/*
 * bn_msb.c
 *
 * $author$
 * 2/3/1999
 */

#include <stdio.h>
#include "bn_msb.h"

void BN_set_msb(BIGNUM *n,const unsigned char *buff,unsigned bytes)
{
    unsigned i;

    BN_set_word(n,0);
    for (i=0; i<bytes; i++)
    {
        BN_lshift(n,n,8);
        BN_add_word(n,buff[i]);
    }
}

void BN_get_msb(const BIGNUM *n,unsigned char *buff,unsigned bytes)
{
    BIGNUM *t;
    unsigned i;

    if ((t=BN_new())!=NULL)
    {
        BN_copy(t,(BIGNUM*)(n));
        for (i=bytes; i>0; i--)
        {
            buff[i-1]=(unsigned char)BN_mod_word(t,256);
            BN_rshift(t,t,8);
        }
        BN_free(t);
    }
}

