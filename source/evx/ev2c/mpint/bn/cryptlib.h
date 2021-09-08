/*
 * cryptlib.h
 *
 * $author$
 * 2/2/1999
 */

#ifndef CRYPTLIB_H
#define CRYPTLIB_H

#include <stdlib.h>
#include <string.h>

#define MS_STATIC static
#define BNerr(func,error)
#define Malloc(size) malloc(size)
#define Realloc(ptr,size) realloc(ptr,size)
#define Free(ptr) free(ptr)

#ifdef  __cplusplus
extern "C" {
#endif

#ifndef NOPROTO
#define P_CC_CC	const void *,const void *
#define P_I_I		int,int 
#define P_I_I_P		int,int,char *
#define P_I_I_P_I	int,int,char *,int
#define P_IP_I_I_P_I	int *,int,int,char *,int
#define P_V		void 
#else
#define P_CC_CC
#define P_I_I
#define P_I_I_P
#define P_IP_I_I_P_I
#define P_I_I_P_I
#define P_V
#endif

#ifdef  __cplusplus
}
#endif

#endif
