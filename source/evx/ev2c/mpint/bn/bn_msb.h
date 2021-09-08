/*
 * bn_msb.c
 *
 * $author$
 * 2/3/1999
 */

#ifndef BN_MSB_H
#define BN_MSB_H

#include "bn.h"

#ifdef __cplusplus
extern "C" {
#endif

void BN_set_msb(BIGNUM *n,const unsigned char *buff,unsigned bytes);
void BN_get_msb(const BIGNUM *n,unsigned char *buff,unsigned bytes);

#ifdef __cplusplus
}
#endif

#endif
