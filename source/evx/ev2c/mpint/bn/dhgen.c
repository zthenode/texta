/*
 * dhgen.c
 *
 * $author$
 * 2/3/1999
 */

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <dump.h>
#include "cryptlib.h"
#include "bn_msb.h"

typedef struct dh_st
	{
	/* This first argument is used to pick up errors when
	 * a DH is passed instead of a EVP_PKEY */
	int pad;
	int version;
	BIGNUM *p;
	BIGNUM *g;
	int length; /* optional */
	BIGNUM *pub_key;	/* y */
	BIGNUM *priv_key;	/* x */
	} DH;

#define DH_GENERATOR_2		2
/* #define DH_GENERATOR_3	3 */
#define DH_GENERATOR_5		5

/* DH_check error codes */
#define DH_CHECK_P_NOT_PRIME		0x01
#define DH_CHECK_P_NOT_STRONG_PRIME	0x02
#define DH_UNABLE_TO_CHECK_GENERATOR	0x04
#define DH_NOT_SUITABLE_GENERATOR	0x08

/* Function codes. */
#define DH_F_DHPARAMS_PRINT				 100
#define DH_F_DHPARAMS_PRINT_FP				 101
#define DH_F_DH_COMPUTE_KEY				 102
#define DH_F_DH_GENERATE_KEY				 103
#define DH_F_DH_GENERATE_PARAMETERS			 104
#define DH_F_DH_NEW					 105

/* Reason codes. */
#define DH_R_NO_PRIVATE_VALUE				 100
 
#define DHparams_dup(x) (DH *)ASN1_dup((int (*)())i2d_DHparams, \
		(char *(*)())d2i_DHparams,(char *)(x))
#define d2i_DHparams_fp(fp,x) (DH *)ASN1_d2i_fp((char *(*)())DH_new, \
		(char *(*)())d2i_DHparams,(fp),(unsigned char **)(x))
#define i2d_DHparams_fp(fp,x) ASN1_i2d_fp(i2d_DHparams,(fp), \
		(unsigned char *)(x))
#define d2i_DHparams_bio(bp,x) (DH *)ASN1_d2i_bio((char *(*)())DH_new, \
		(char *(*)())d2i_DHparams,(bp),(unsigned char **)(x))
#define i2d_DHparams_bio(bp,x) ASN1_i2d_bio(i2d_DHparams,(bp), \
		(unsigned char *)(x))

#define DHerr(func,error)

DH *DH_new()
	{
	DH *ret;

	ret=(DH *)Malloc(sizeof(DH));
	if (ret == NULL)
		{
		DHerr(DH_F_DH_NEW,ERR_R_MALLOC_FAILURE);
		return(NULL);
		}
	ret->pad=0;
	ret->version=0;
	ret->p=NULL;
	ret->g=NULL;
	ret->length=0;
	ret->pub_key=NULL;
	ret->priv_key=NULL;
	return(ret);
	}

void DH_free(r)
DH *r;
	{
	if (r->p != NULL) BN_clear_free(r->p);
	if (r->g != NULL) BN_clear_free(r->g);
	if (r->pub_key != NULL) BN_clear_free(r->pub_key);
	if (r->priv_key != NULL) BN_clear_free(r->priv_key);
	Free(r);
	}

int DH_size(dh)
DH *dh;
	{
	return(BN_num_bytes(dh->p));
	}

DH *DH_generate_parameters(prime_len,generator,callback,cb_arg)
int prime_len;
int generator;
void (*callback)(P_I_I_P);
char *cb_arg;
	{
	BIGNUM *p=NULL,*t1,*t2;
	DH *ret=NULL;
	int g,ok= -1;
	BN_CTX *ctx=NULL;

	ret=DH_new();
	ctx=BN_CTX_new();
	if (ctx == NULL) goto err;
	t1=ctx->bn[0];
	t2=ctx->bn[1];
	ctx->tos=2;
	
	if (generator == DH_GENERATOR_2)
		{
		BN_set_word(t1,24);
		BN_set_word(t2,11);
		g=2;
		}
#ifdef undef  /* does not work for strong primes */
	else if (generator == DH_GENERATOR_3)
		{
		BN_set_word(t1,12);
		BN_set_word(t2,5);
		g=3;
		}
#endif
	else if (generator == DH_GENERATOR_5)
		{
		BN_set_word(t1,10);
		BN_set_word(t2,3);
		/* BN_set_word(t3,7); just have to miss
		 * out on these ones :-( */
		g=5;
		}
	else
		g=generator;
	
	p=BN_generate_prime(prime_len,1,t1,t2,callback,cb_arg);
	if (p == NULL) goto err;
	if (callback != NULL) callback(3,0,cb_arg);
	ret->p=p;
	ret->g=BN_new();
	if (!BN_set_word(ret->g,g)) goto err;
	ok=1;
err:
	if (ok == -1)
		{
		DHerr(DH_F_DH_GENERATE_PARAMETERS,ERR_R_BN_LIB);
		ok=0;
		}

	if (ctx != NULL) BN_CTX_free(ctx);
	if (!ok && (ret != NULL))
		{
		DH_free(ret);
		ret=NULL;
		}
	return(ret);
	}

int rand_bytes(char *ptr,int len)
{
    static unsigned randnum=0;
    static unsigned avail=0;
    int i;

    for (i=0; i<len;)
    {
        if (avail<1)
        {
            randnum=(unsigned)rand();
            avail=sizeof(randnum);
//            printf(" [%x] ",randnum);
        }
        if ((ptr[i]=(char)(randnum&255))!=0)
        {
//            printf("%2.2x",(unsigned char)ptr[i]);
            i++;
        }
        if ((randnum>>=8)<1)
            avail=0;
        else avail--;
    }
//    printf(".");
    return 0;
}

void usage()
{
    printf("usage: dhgen [-bN] [-gN]\n\n");
    printf("       -bN number of bits\n");
    printf("       -gN generator\n");
    exit(0);
}

void main(int argc,char **argv)
{
    time_t tm;
    int i,bytes,bits,generator;
    DH *dh;
    unsigned char buff[1024];

    bits=1024;
    generator=DH_GENERATOR_5;
    for (i=1; i<argc; i++)
    {
        switch(argv[i][0])
        {
        case '-':
            switch(tolower(argv[i][1]))
            {
            case 'b':
                if (argv[i][2])
                {
                    bits=atoi(&argv[i][2]);
                    break;
                }
                usage();

            case 'g':
                if (argv[i][2])
                {
                    generator=atoi(&argv[i][2]);
                    break;
                }
                usage();

            default:
                usage();
            }
            break;

        default:
            usage();
        }
    }
    bytes=(bits+7)/8;
    srand(time(&tm));
    dh=DH_generate_parameters(bits,generator,NULL,NULL);
    if (dh!=NULL)
    {
        printf("g=%d\n\n",generator);
        BN_get_msb(dh->p,buff,bytes);
        printf("n=");
        dump0x(buff,bytes);
    }
}
