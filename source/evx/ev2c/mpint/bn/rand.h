/*
 * rand.h
 *
 * $author$
 * 2/2/1999
 */

#ifndef RAND_H
#define RAND_H

#define RAND_bytes(ptr,size) rand_bytes(ptr,size)

#ifdef  __cplusplus
extern "C" {
#endif

#ifndef NOPROTO
int rand_bytes( unsigned char *buf,int num);
#else
int rand_bytes();
#endif

#ifdef  __cplusplus
}
#endif

#endif
