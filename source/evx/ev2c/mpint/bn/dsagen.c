/*
 * dsagen.c
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
#include "rand.h"

#undef GENUINE_DSA

#ifdef GENUINE_DSA
#define HASH    SHA
#define SHA_0
#else
#define HASH    SHA
#define SHA_1
#endif 

#define SHA_CBLOCK	64
#define SHA_LBLOCK	16
#define SHA_BLOCK	16
#define SHA_LAST_BLOCK  56
#define SHA_LENGTH_BLOCK 8
#define SHA_DIGEST_LENGTH 20

typedef struct SHAstate_st
	{
	unsigned long h0,h1,h2,h3,h4;
	unsigned long Nl,Nh;
	unsigned long data[SHA_LBLOCK];
	int num;
	} SHA_CTX;


#ifdef undef
/* one or the other needs to be defined */
#ifndef SHA_1 /* FIPE 180-1 */
#define SHA_0 /* FIPS 180   */
#endif
#endif

#define ULONG	unsigned long
#define UCHAR	unsigned char
#define UINT	unsigned int

#ifdef NOCONST
#define const
#endif

#undef c2nl
#define c2nl(c,l)	(l =(((unsigned long)(*((c)++)))<<24), \
			 l|=(((unsigned long)(*((c)++)))<<16), \
			 l|=(((unsigned long)(*((c)++)))<< 8), \
			 l|=(((unsigned long)(*((c)++)))    ))

#undef p_c2nl
#define p_c2nl(c,l,n)	{ \
			switch (n) { \
			case 0: l =((unsigned long)(*((c)++)))<<24; \
			case 1: l|=((unsigned long)(*((c)++)))<<16; \
			case 2: l|=((unsigned long)(*((c)++)))<< 8; \
			case 3: l|=((unsigned long)(*((c)++))); \
				} \
			}

#undef c2nl_p
/* NOTE the pointer is not incremented at the end of this */
#define c2nl_p(c,l,n)	{ \
			l=0; \
			(c)+=n; \
			switch (n) { \
			case 3: l =((unsigned long)(*(--(c))))<< 8; \
			case 2: l|=((unsigned long)(*(--(c))))<<16; \
			case 1: l|=((unsigned long)(*(--(c))))<<24; \
				} \
			}

#undef p_c2nl_p
#define p_c2nl_p(c,l,sc,len) { \
			switch (sc) \
				{ \
			case 0: l =((unsigned long)(*((c)++)))<<24; \
				if (--len == 0) break; \
			case 1: l|=((unsigned long)(*((c)++)))<<16; \
				if (--len == 0) break; \
			case 2: l|=((unsigned long)(*((c)++)))<< 8; \
				} \
			}

#undef nl2c
#define nl2c(l,c)	(*((c)++)=(unsigned char)(((l)>>24)&0xff), \
			 *((c)++)=(unsigned char)(((l)>>16)&0xff), \
			 *((c)++)=(unsigned char)(((l)>> 8)&0xff), \
			 *((c)++)=(unsigned char)(((l)    )&0xff))

#undef c2l
#define c2l(c,l)	(l =(((unsigned long)(*((c)++)))    ), \
			 l|=(((unsigned long)(*((c)++)))<< 8), \
			 l|=(((unsigned long)(*((c)++)))<<16), \
			 l|=(((unsigned long)(*((c)++)))<<24))

#undef p_c2l
#define p_c2l(c,l,n)	{ \
			switch (n) { \
			case 0: l =((unsigned long)(*((c)++))); \
			case 1: l|=((unsigned long)(*((c)++)))<< 8; \
			case 2: l|=((unsigned long)(*((c)++)))<<16; \
			case 3: l|=((unsigned long)(*((c)++)))<<24; \
				} \
			}

#undef c2l_p
/* NOTE the pointer is not incremented at the end of this */
#define c2l_p(c,l,n)	{ \
			l=0; \
			(c)+=n; \
			switch (n) { \
			case 3: l =((unsigned long)(*(--(c))))<<16; \
			case 2: l|=((unsigned long)(*(--(c))))<< 8; \
			case 1: l|=((unsigned long)(*(--(c)))); \
				} \
			}

#undef p_c2l_p
#define p_c2l_p(c,l,sc,len) { \
			switch (sc) \
				{ \
			case 0: l =((unsigned long)(*((c)++))); \
				if (--len == 0) break; \
			case 1: l|=((unsigned long)(*((c)++)))<< 8; \
				if (--len == 0) break; \
			case 2: l|=((unsigned long)(*((c)++)))<<16; \
				} \
			}

#undef l2c
#define l2c(l,c)	(*((c)++)=(unsigned char)(((l)    )&0xff), \
			 *((c)++)=(unsigned char)(((l)>> 8)&0xff), \
			 *((c)++)=(unsigned char)(((l)>>16)&0xff), \
			 *((c)++)=(unsigned char)(((l)>>24)&0xff))

#undef ROTATE
#if defined(WIN32)
#define ROTATE(a,n)     _lrotl(a,n)
#else
#define ROTATE(a,n)     (((a)<<(n))|(((a)&0xffffffff)>>(32-(n))))
#endif

/* A nice byte order reversal from Wei Dai <weidai@eskimo.com> */
#if defined(WIN32)
/* 5 instructions with rotate instruction, else 9 */
#define Endian_Reverse32(a) \
	{ \
	unsigned long l=(a); \
	(a)=((ROTATE(l,8)&0x00FF00FF)|(ROTATE(l,24)&0xFF00FF00)); \
	}
#else
/* 6 instructions with rotate instruction, else 8 */
#define Endian_Reverse32(a) \
	{ \
	unsigned long l=(a); \
	l=(((l&0xFF00FF00)>>8L)|((l&0x00FF00FF)<<8L)); \
	(a)=ROTATE(l,16L); \
	}
#endif

/* As  pointed out by Wei Dai <weidai@eskimo.com>, F() below can be
 * simplified to the code in F_00_19.  Wei attributes these optimisations
 * to Peter Gutmann's SHS code, and he attributes it to Rich Schroeppel.
 * #define F(x,y,z) (((x) & (y))  |  ((~(x)) & (z)))
 * I've just become aware of another tweak to be made, again from Wei Dai,
 * in F_40_59, (x&a)|(y&a) -> (x|y)&a
 */
#define	F_00_19(b,c,d)	((((c) ^ (d)) & (b)) ^ (d)) 
#define	F_20_39(b,c,d)	((b) ^ (c) ^ (d))
#define F_40_59(b,c,d)	(((b) & (c)) | (((b)|(c)) & (d))) 
#define	F_60_79(b,c,d)	F_20_39(b,c,d)

#ifdef SHA_0
#undef Xupdate
#define Xupdate(a,i,ia,ib,ic,id) X[(i)&0x0f]=(a)=\
	(ia[(i)&0x0f]^ib[((i)+2)&0x0f]^ic[((i)+8)&0x0f]^id[((i)+13)&0x0f]);
#endif
#ifdef SHA_1
#undef Xupdate
#define Xupdate(a,i,ia,ib,ic,id) (a)=\
	(ia[(i)&0x0f]^ib[((i)+2)&0x0f]^ic[((i)+8)&0x0f]^id[((i)+13)&0x0f]);\
	X[(i)&0x0f]=(a)=ROTATE((a),1);
#endif

#define BODY_00_15(i,a,b,c,d,e,f,xa) \
	(f)=xa[i]+(e)+K_00_19+ROTATE((a),5)+F_00_19((b),(c),(d)); \
	(b)=ROTATE((b),30);

#define BODY_16_19(i,a,b,c,d,e,f,xa,xb,xc,xd) \
	Xupdate(f,i,xa,xb,xc,xd); \
	(f)+=(e)+K_00_19+ROTATE((a),5)+F_00_19((b),(c),(d)); \
	(b)=ROTATE((b),30);

#define BODY_20_31(i,a,b,c,d,e,f,xa,xb,xc,xd) \
	Xupdate(f,i,xa,xb,xc,xd); \
	(f)+=(e)+K_20_39+ROTATE((a),5)+F_20_39((b),(c),(d)); \
	(b)=ROTATE((b),30);

#define BODY_32_39(i,a,b,c,d,e,f,xa) \
	Xupdate(f,i,xa,xa,xa,xa); \
	(f)+=(e)+K_20_39+ROTATE((a),5)+F_20_39((b),(c),(d)); \
	(b)=ROTATE((b),30);

#define BODY_40_59(i,a,b,c,d,e,f,xa) \
	Xupdate(f,i,xa,xa,xa,xa); \
	(f)+=(e)+K_40_59+ROTATE((a),5)+F_40_59((b),(c),(d)); \
	(b)=ROTATE((b),30);

#define BODY_60_79(i,a,b,c,d,e,f,xa) \
	Xupdate(f,i,xa,xa,xa,xa); \
	(f)=X[(i)&0x0f]+(e)+K_60_79+ROTATE((a),5)+F_60_79((b),(c),(d)); \
	(b)=ROTATE((b),30);

/* Implemented from SHA-0 document - The Secure Hash Algorithm
 */

#define INIT_DATA_h0 (unsigned long)0x67452301L
#define INIT_DATA_h1 (unsigned long)0xefcdab89L
#define INIT_DATA_h2 (unsigned long)0x98badcfeL
#define INIT_DATA_h3 (unsigned long)0x10325476L
#define INIT_DATA_h4 (unsigned long)0xc3d2e1f0L

#define K_00_19	0x5a827999L
#define K_20_39 0x6ed9eba1L
#define K_40_59 0x8f1bbcdcL
#define K_60_79 0xca62c1d6L

#ifndef NOPROTO
   void sha_block(SHA_CTX *c, register unsigned long *p, int num);
#else
   void sha_block();
#endif

#define	M_c2nl 		c2nl
#define	M_p_c2nl	p_c2nl
#define	M_c2nl_p	c2nl_p
#define	M_p_c2nl_p	p_c2nl_p
#define	M_nl2c		nl2c

void SHA_Init(c)
SHA_CTX *c;
	{
	c->h0=INIT_DATA_h0;
	c->h1=INIT_DATA_h1;
	c->h2=INIT_DATA_h2;
	c->h3=INIT_DATA_h3;
	c->h4=INIT_DATA_h4;
	c->Nl=0;
	c->Nh=0;
	c->num=0;
	}

void SHA_Update(c, data, len)
SHA_CTX *c;
register unsigned char *data;
unsigned long len;
	{
	register ULONG *p;
	int ew,ec,sw,sc;
	ULONG l;

	if (len == 0) return;

	l=(c->Nl+(len<<3))&0xffffffffL;
	if (l < c->Nl) /* overflow */
		c->Nh++;
	c->Nh+=(len>>29);
	c->Nl=l;

	if (c->num != 0)
		{
		p=c->data;
		sw=c->num>>2;
		sc=c->num&0x03;

		if ((c->num+len) >= SHA_CBLOCK)
			{
			l= p[sw];
			M_p_c2nl(data,l,sc);
			p[sw++]=l;
			for (; sw<SHA_LBLOCK; sw++)
				{
				M_c2nl(data,l);
				p[sw]=l;
				}
			len-=(SHA_CBLOCK-c->num);

			sha_block(c,p,64);
			c->num=0;
			/* drop through and do the rest */
			}
		else
			{
			c->num+=(int)len;
			if ((sc+len) < 4) /* ugly, add char's to a word */
				{
				l= p[sw];
				M_p_c2nl_p(data,l,sc,len);
				p[sw]=l;
				}
			else
				{
				ew=(c->num>>2);
				ec=(c->num&0x03);
				l= p[sw];
				M_p_c2nl(data,l,sc);
				p[sw++]=l;
				for (; sw < ew; sw++)
					{ M_c2nl(data,l); p[sw]=l; }
				if (ec)
					{
					M_c2nl_p(data,l,ec);
					p[sw]=l;
					}
				}
			return;
			}
		}
	/* We can only do the following code for assember, the reason
	 * being that the sha_block 'C' version changes the values
	 * in the 'data' array.  The assember code avoids this and
	 * copies it to a local array.  I should be able to do this for
	 * the C version as well....
	 */
#if 1
#if defined(B_ENDIAN) || defined(SHA_ASM)
	if ((((unsigned int)data)%sizeof(ULONG)) == 0)
		{
		sw=len/SHA_CBLOCK;
		if (sw)
			{
			sw*=SHA_CBLOCK;
			sha_block(c,(ULONG *)data,sw);
			data+=sw;
			len-=sw;
			}
		}
#endif
#endif
	/* we now can process the input data in blocks of SHA_CBLOCK
	 * chars and save the leftovers to c->data. */
	p=c->data;
	while (len >= SHA_CBLOCK)
		{
#if defined(B_ENDIAN) || defined(L_ENDIAN)
		if (p != (unsigned long *)data)
			memcpy(p,data,SHA_CBLOCK);
		data+=SHA_CBLOCK;
#  ifdef L_ENDIAN
#    ifndef SHA_ASM /* Will not happen */
		for (sw=(SHA_LBLOCK/4); sw; sw--)
			{
			Endian_Reverse32(p[0]);
			Endian_Reverse32(p[1]);
			Endian_Reverse32(p[2]);
			Endian_Reverse32(p[3]);
			p+=4;
			}
		p=c->data;
#    endif
#  endif
#else
		for (sw=(SHA_BLOCK/4); sw; sw--)
			{
			M_c2nl(data,l); *(p++)=l;
			M_c2nl(data,l); *(p++)=l;
			M_c2nl(data,l); *(p++)=l;
			M_c2nl(data,l); *(p++)=l;
			}
		p=c->data;
#endif
		sha_block(c,p,64);
		len-=SHA_CBLOCK;
		}
	ec=(int)len;
	c->num=ec;
	ew=(ec>>2);
	ec&=0x03;

	for (sw=0; sw < ew; sw++)
		{ M_c2nl(data,l); p[sw]=l; }
	M_c2nl_p(data,l,ec);
	p[sw]=l;
	}

void SHA_Transform(c,b)
SHA_CTX *c;
unsigned char *b;
	{
	ULONG p[16];
#if !defined(B_ENDIAN)
	ULONG *q;
	int i;
#endif

#if defined(B_ENDIAN) || defined(L_ENDIAN)
	memcpy(p,b,64);
#ifdef L_ENDIAN
	q=p;
	for (i=(SHA_LBLOCK/4); i; i--)
		{
		Endian_Reverse32(q[0]);
		Endian_Reverse32(q[1]);
		Endian_Reverse32(q[2]);
		Endian_Reverse32(q[3]);
		q+=4;
		}
#endif
#else
	q=p;
	for (i=(SHA_LBLOCK/4); i; i--)
		{
		ULONG l;
		c2nl(b,l); *(q++)=l;
		c2nl(b,l); *(q++)=l;
		c2nl(b,l); *(q++)=l;
		c2nl(b,l); *(q++)=l; 
		} 
#endif
	sha_block(c,p,64);
	}

void sha_block(c, W, num)
SHA_CTX *c;
register unsigned long *W;
int num;
	{
	register ULONG A,B,C,D,E,T;
	ULONG X[16];

	A=c->h0;
	B=c->h1;
	C=c->h2;
	D=c->h3;
	E=c->h4;

	for (;;)
		{
	BODY_00_15( 0,A,B,C,D,E,T,W);
	BODY_00_15( 1,T,A,B,C,D,E,W);
	BODY_00_15( 2,E,T,A,B,C,D,W);
	BODY_00_15( 3,D,E,T,A,B,C,W);
	BODY_00_15( 4,C,D,E,T,A,B,W);
	BODY_00_15( 5,B,C,D,E,T,A,W);
	BODY_00_15( 6,A,B,C,D,E,T,W);
	BODY_00_15( 7,T,A,B,C,D,E,W);
	BODY_00_15( 8,E,T,A,B,C,D,W);
	BODY_00_15( 9,D,E,T,A,B,C,W);
	BODY_00_15(10,C,D,E,T,A,B,W);
	BODY_00_15(11,B,C,D,E,T,A,W);
	BODY_00_15(12,A,B,C,D,E,T,W);
	BODY_00_15(13,T,A,B,C,D,E,W);
	BODY_00_15(14,E,T,A,B,C,D,W);
	BODY_00_15(15,D,E,T,A,B,C,W);
	BODY_16_19(16,C,D,E,T,A,B,W,W,W,W);
	BODY_16_19(17,B,C,D,E,T,A,W,W,W,W);
	BODY_16_19(18,A,B,C,D,E,T,W,W,W,W);
	BODY_16_19(19,T,A,B,C,D,E,W,W,W,X);

	BODY_20_31(20,E,T,A,B,C,D,W,W,W,X);
	BODY_20_31(21,D,E,T,A,B,C,W,W,W,X);
	BODY_20_31(22,C,D,E,T,A,B,W,W,W,X);
	BODY_20_31(23,B,C,D,E,T,A,W,W,W,X);
	BODY_20_31(24,A,B,C,D,E,T,W,W,X,X);
	BODY_20_31(25,T,A,B,C,D,E,W,W,X,X);
	BODY_20_31(26,E,T,A,B,C,D,W,W,X,X);
	BODY_20_31(27,D,E,T,A,B,C,W,W,X,X);
	BODY_20_31(28,C,D,E,T,A,B,W,W,X,X);
	BODY_20_31(29,B,C,D,E,T,A,W,W,X,X);
	BODY_20_31(30,A,B,C,D,E,T,W,X,X,X);
	BODY_20_31(31,T,A,B,C,D,E,W,X,X,X);
	BODY_32_39(32,E,T,A,B,C,D,X);
	BODY_32_39(33,D,E,T,A,B,C,X);
	BODY_32_39(34,C,D,E,T,A,B,X);
	BODY_32_39(35,B,C,D,E,T,A,X);
	BODY_32_39(36,A,B,C,D,E,T,X);
	BODY_32_39(37,T,A,B,C,D,E,X);
	BODY_32_39(38,E,T,A,B,C,D,X);
	BODY_32_39(39,D,E,T,A,B,C,X);

	BODY_40_59(40,C,D,E,T,A,B,X);
	BODY_40_59(41,B,C,D,E,T,A,X);
	BODY_40_59(42,A,B,C,D,E,T,X);
	BODY_40_59(43,T,A,B,C,D,E,X);
	BODY_40_59(44,E,T,A,B,C,D,X);
	BODY_40_59(45,D,E,T,A,B,C,X);
	BODY_40_59(46,C,D,E,T,A,B,X);
	BODY_40_59(47,B,C,D,E,T,A,X);
	BODY_40_59(48,A,B,C,D,E,T,X);
	BODY_40_59(49,T,A,B,C,D,E,X);
	BODY_40_59(50,E,T,A,B,C,D,X);
	BODY_40_59(51,D,E,T,A,B,C,X);
	BODY_40_59(52,C,D,E,T,A,B,X);
	BODY_40_59(53,B,C,D,E,T,A,X);
	BODY_40_59(54,A,B,C,D,E,T,X);
	BODY_40_59(55,T,A,B,C,D,E,X);
	BODY_40_59(56,E,T,A,B,C,D,X);
	BODY_40_59(57,D,E,T,A,B,C,X);
	BODY_40_59(58,C,D,E,T,A,B,X);
	BODY_40_59(59,B,C,D,E,T,A,X);

	BODY_60_79(60,A,B,C,D,E,T,X);
	BODY_60_79(61,T,A,B,C,D,E,X);
	BODY_60_79(62,E,T,A,B,C,D,X);
	BODY_60_79(63,D,E,T,A,B,C,X);
	BODY_60_79(64,C,D,E,T,A,B,X);
	BODY_60_79(65,B,C,D,E,T,A,X);
	BODY_60_79(66,A,B,C,D,E,T,X);
	BODY_60_79(67,T,A,B,C,D,E,X);
	BODY_60_79(68,E,T,A,B,C,D,X);
	BODY_60_79(69,D,E,T,A,B,C,X);
	BODY_60_79(70,C,D,E,T,A,B,X);
	BODY_60_79(71,B,C,D,E,T,A,X);
	BODY_60_79(72,A,B,C,D,E,T,X);
	BODY_60_79(73,T,A,B,C,D,E,X);
	BODY_60_79(74,E,T,A,B,C,D,X);
	BODY_60_79(75,D,E,T,A,B,C,X);
	BODY_60_79(76,C,D,E,T,A,B,X);
	BODY_60_79(77,B,C,D,E,T,A,X);
	BODY_60_79(78,A,B,C,D,E,T,X);
	BODY_60_79(79,T,A,B,C,D,E,X);
	
	c->h0=(c->h0+E)&0xffffffffL; 
	c->h1=(c->h1+T)&0xffffffffL;
	c->h2=(c->h2+A)&0xffffffffL;
	c->h3=(c->h3+B)&0xffffffffL;
	c->h4=(c->h4+C)&0xffffffffL;

	num-=64;
	if (num <= 0) break;

	A=c->h0;
	B=c->h1;
	C=c->h2;
	D=c->h3;
	E=c->h4;

	W+=16;
		}
	}

void SHA_Final(md, c)
unsigned char *md;
SHA_CTX *c;
	{
	register int i,j;
	register ULONG l;
	register ULONG *p;
	static unsigned char end[4]={0x80,0x00,0x00,0x00};
	unsigned char *cp=end;

	/* c->num should definitly have room for at least one more byte. */
	p=c->data;
	j=c->num;
	i=j>>2;
#ifdef PURIFY
	if ((j&0x03) == 0) p[i]=0;
#endif
	l=p[i];
	M_p_c2nl(cp,l,j&0x03);
	p[i]=l;
	i++;
	/* i is the next 'undefined word' */
	if (c->num >= SHA_LAST_BLOCK)
		{
		for (; i<SHA_LBLOCK; i++)
			p[i]=0;
		sha_block(c,p,64);
		i=0;
		}
	for (; i<(SHA_LBLOCK-2); i++)
		p[i]=0;
	p[SHA_LBLOCK-2]=c->Nh;
	p[SHA_LBLOCK-1]=c->Nl;
	sha_block(c,p,64);
	cp=md;
	l=c->h0; nl2c(l,cp);
	l=c->h1; nl2c(l,cp);
	l=c->h2; nl2c(l,cp);
	l=c->h3; nl2c(l,cp);
	l=c->h4; nl2c(l,cp);

	/* clear stuff, sha_block may be leaving some stuff on the stack
	 * but I'm not worried :-) */
	c->num=0;
/*	memset((char *)&c,0,sizeof(c));*/
	}

unsigned char *SHA(d, n, md)
unsigned char *d;
unsigned long n;
unsigned char *md;
	{
	SHA_CTX c;
	static unsigned char m[SHA_DIGEST_LENGTH];

	if (md == NULL) md=m;
	SHA_Init(&c);
	SHA_Update(&c,d,n);
	SHA_Final(md,&c);
	memset(&c,0,sizeof(c));
	return(md);
	}

#define DSAerr(func,error)

typedef struct dsa_st
	{
	/* This first variable is used to pick up errors where
	 * a DSA is passed instead of of a EVP_PKEY */
	int pad;
	int version;
	int write_params;
	BIGNUM *p;
	BIGNUM *q;	/* == 20 */
	BIGNUM *g;

	BIGNUM *pub_key;  /* y public key */
	BIGNUM *priv_key; /* x private key */

	BIGNUM *kinv;	/* Signing pre-calc */
	BIGNUM *r;	/* Signing pre-calc */

	int references;
	} DSA;

DSA *DSA_new()
	{
	DSA *ret;

	ret=(DSA *)Malloc(sizeof(DSA));
	if (ret == NULL)
		{
		DSAerr(DSA_F_DSA_NEW,ERR_R_MALLOC_FAILURE);
		return(NULL);
		}
	ret->pad=0;
	ret->version=0;
	ret->write_params=1;
	ret->p=NULL;
	ret->q=NULL;
	ret->g=NULL;

	ret->pub_key=NULL;
	ret->priv_key=NULL;

	ret->kinv=NULL;
	ret->r=NULL;

	ret->references=1;
	return(ret);
	}

void DSA_free(r)
DSA *r;
	{
	int i;

	if (r == NULL) return;
/*
	i=CRYPTO_add(&r->references,-1,CRYPTO_LOCK_DSA);
*/
#ifdef REF_PRINT
	REF_PRINT("DSA",r);
#endif
	if (i > 0) return;
#ifdef REF_CHECK
	if (i < 0)
		{
		fprintf(stderr,"DSA_free, bad reference count\n");
		abort();
		}
#endif

	if (r->p != NULL) BN_clear_free(r->p);
	if (r->q != NULL) BN_clear_free(r->q);
	if (r->g != NULL) BN_clear_free(r->g);
	if (r->pub_key != NULL) BN_clear_free(r->pub_key);
	if (r->priv_key != NULL) BN_clear_free(r->priv_key);
	if (r->kinv != NULL) BN_clear_free(r->kinv);
	if (r->r != NULL) BN_clear_free(r->r);
	Free(r);
	}

int DSA_is_prime(w, callback,cb_arg)
BIGNUM *w;
void (*callback)();
char *cb_arg;
	{
	int ok= -1,j,i,n;
	BN_CTX *ctx=NULL,*ctx2=NULL;
	BIGNUM *w_1,*b,*m,*z;
	int a;

	if (!BN_is_bit_set(w,0)) return(0);

	ctx=BN_CTX_new();
	if (ctx == NULL) goto err;
	ctx2=BN_CTX_new();
	if (ctx2 == NULL) goto err;

	m=  ctx2->bn[2];
	b=  ctx2->bn[3];
	z=  ctx2->bn[4];
	w_1=ctx2->bn[5];

	/* step 1 */
	n=50;

	/* step 2 */
	if (!BN_sub(w_1,w,BN_value_one())) goto err;
	for (a=1; !BN_is_bit_set(w_1,a); a++)
		;
	if (!BN_rshift(m,w_1,a)) goto err;

	for (i=1; i < n; i++)
		{
		/* step 3 */
		BN_rand(b,BN_num_bits(w)-2/*-1*/,0,0);
		BN_set_word(b,0x10001L);

		/* step 4 */
		j=0;
		if (!BN_mod_exp(z,b,m,w,ctx)) goto err;

		/* step 5 */
		for (;;)
			{
			if (((j == 0) && BN_is_one(z)) || (BN_cmp(z,w_1) == 0))
				break;

			/* step 6 */
			if ((j > 0) && BN_is_one(z))
				{
				ok=0;
				goto err;
				}

			j++;
			if (j >= a)
				{
				ok=0;
				goto err;
				}

			if (!BN_mod_mul(z,z,z,w,ctx)) goto err;
			if (callback != NULL) callback(1,j,cb_arg);
			}
		}

	ok=1;
err:
	if (ok == -1) DSAerr(DSA_F_DSA_IS_PRIME,ERR_R_BN_LIB);
	BN_CTX_free(ctx);
	BN_CTX_free(ctx2);
	
	return(ok);
	}

DSA *DSA_generate_parameters(bits,seed_in,seed_len,counter_ret,h_ret,callback,
	cb_arg)
int bits;
unsigned char *seed_in;
int seed_len;
int *counter_ret;
unsigned long *h_ret;
void (*callback)();
char *cb_arg;
	{
	int ok=0;
	unsigned char seed[SHA_DIGEST_LENGTH];
	unsigned char md[SHA_DIGEST_LENGTH];
	unsigned char buf[SHA_DIGEST_LENGTH],buf2[SHA_DIGEST_LENGTH];
	BIGNUM *r0,*W,*X,*c,*test;
	BIGNUM *g=NULL,*q=NULL,*p=NULL;
	int k,n=0,i,b,m=0;
	int counter=0;
	BN_CTX *ctx=NULL,*ctx2=NULL;
	unsigned int h=2;
	DSA *ret=NULL;

	if (bits < 512) bits=512;
	bits=(bits+63)/64*64;

	if ((seed_in != NULL) && (seed_len == 20))
		memcpy(seed,seed_in,seed_len);

	ctx=BN_CTX_new();
	if (ctx == NULL) goto err;
	ctx2=BN_CTX_new();
	if (ctx2 == NULL) goto err;
	ret=DSA_new();
	if (ret == NULL) goto err;
	r0=ctx2->bn[0];
	g=ctx2->bn[1];
	W=ctx2->bn[2];
	q=ctx2->bn[3];
	X=ctx2->bn[4];
	c=ctx2->bn[5];
	p=ctx2->bn[6];
	test=ctx2->bn[7];

	BN_lshift(test,BN_value_one(),bits-1);

	for (;;)
		{
		for (;;)
			{
			/* step 1 */
			if (callback != NULL) callback(0,m++,cb_arg);

			if (!seed_len)
				RAND_bytes(seed,SHA_DIGEST_LENGTH);
			else
				seed_len=0;

			memcpy(buf,seed,SHA_DIGEST_LENGTH);
			memcpy(buf2,seed,SHA_DIGEST_LENGTH);
			for (i=SHA_DIGEST_LENGTH-1; i >= 0; i--)
				{
				buf[i]++;
				if (buf[i] != 0) break;
				}

			/* step 2 */
			HASH(seed,SHA_DIGEST_LENGTH,md);
			HASH(buf,SHA_DIGEST_LENGTH,buf2);
			for (i=0; i<SHA_DIGEST_LENGTH; i++)
				md[i]^=buf2[i];

			/* step 3 */
			md[0]|=0x80;
			md[SHA_DIGEST_LENGTH-1]|=0x01;
			if (!BN_bin2bn(md,SHA_DIGEST_LENGTH,q)) abort();

			/* step 4 */
			if (DSA_is_prime(q,callback,cb_arg) > 0) break;
			/* do a callback call */
			/* step 5 */
			}

		if (callback != NULL) callback(2,0,cb_arg);
		if (callback != NULL) callback(3,0,cb_arg);

		/* step 6 */
		counter=0;

		n=(bits-1)/160;
		b=(bits-1)-n*160;

		for (;;)
			{
			/* step 7 */
			BN_zero(W);
			for (k=0; k<=n; k++)
				{
				for (i=SHA_DIGEST_LENGTH-1; i >= 0; i--)
					{
					buf[i]++;
					if (buf[i] != 0) break;
					}

				HASH(buf,SHA_DIGEST_LENGTH,md);

				/* step 8 */
				if (!BN_bin2bn(md,SHA_DIGEST_LENGTH,r0)) abort();
				BN_lshift(r0,r0,160*k);
				BN_add(W,W,r0);
				}

			/* more of step 8 */
			BN_mask_bits(W,bits-1);
			BN_copy(X,W); /* this should be ok */
			BN_add(X,X,test); /* this should be ok */

			/* step 9 */
			BN_lshift1(r0,q);
			BN_mod(c,X,r0,ctx);
			BN_sub(r0,c,BN_value_one());
			BN_sub(p,X,r0);

			/* step 10 */
			if (BN_cmp(p,test) >= 0)
				{
				/* step 11 */
				if (DSA_is_prime(p,callback,cb_arg) > 0)
					goto end;
				}

			/* step 13 */
			counter++;

			/* step 14 */
			if (counter >= 4096) break;

			if (callback != NULL) callback(0,counter,cb_arg);
			}
		}
end:
	if (callback != NULL) callback(2,1,cb_arg);

	/* We now need to gernerate g */
	/* Set r0=(p-1)/q */
        BN_sub(test,p,BN_value_one());
        BN_div(r0,NULL,test,q,ctx);

	BN_set_word(test,h);
	for (;;)
		{
		/* g=test^r0%p */
		BN_mod_exp(g,test,r0,p,ctx);
		if (!BN_is_one(g)) break;
		BN_add(test,test,BN_value_one());
		h++;
		}

	if (callback != NULL) callback(3,1,cb_arg);

	ok=1;
err:
	if (!ok)
		{
		if (ret != NULL) DSA_free(ret);
		}
	else
		{
		ret->p=BN_dup(p);
		ret->q=BN_dup(q);
		ret->g=BN_dup(g);
		if ((m > 1) && (seed_in != NULL)) memcpy(seed_in,seed,20);
		if (counter_ret != NULL) *counter_ret=counter;
		if (h_ret != NULL) *h_ret=h;
		}
	BN_CTX_free(ctx);
	BN_CTX_free(ctx2);
	return(ok?ret:NULL);
	}

int rand_bytes(unsigned char *ptr,int len)
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

#ifdef GENUINE_DSA
#define LAST_VALUE 0xbd
#else
#define LAST_VALUE 0xd3
#endif

unsigned char seed[20]={
	0xd5,0x01,0x4e,0x4b,
	0x60,0xef,0x2b,0xa8,
	0xb6,0x21,0x1b,0x40,
	0x62,0xba,0x32,0x24,
	0xe0,0x42,0x7d,LAST_VALUE};

void usage()
{
    printf("usage: dsagen [-bN]\n\n");
    printf("       -bN number of bits\n");
    exit(0);
}

void main(int argc,char **argv)
{
    time_t tm;
    int i,bytes,bits,seedlen;
    DSA *dsa;
    unsigned char buff[1024];

    bits=512;
    seedlen=sizeof(seed);
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
    dsa=DSA_generate_parameters(bits,seed,seedlen,NULL,NULL,NULL,NULL);
    if (dsa!=NULL)
    {
        BN_get_msb(dsa->p,buff,bytes);
        printf("p=");
        dump0x(buff,bytes);
        printf("\n\n");
        BN_get_msb(dsa->q,buff,bytes);
        printf("q=");
        dump0x(buff,bytes);
        printf("\n\n");
        BN_get_msb(dsa->g,buff,bytes);
        printf("g=");
        dump0x(buff,bytes);
        printf("\n\n");
    }
}
