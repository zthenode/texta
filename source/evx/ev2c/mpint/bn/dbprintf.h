/*
 * dbprintf.h
 *
 * $author$
 *
 * 6/17/98
 */
#ifndef DBPRINTF_H
#define DBPRINTF_H

#ifndef dbprintf
#ifndef DBPRINTF
#define dbif(cond)
#define dbprintf(args)
#define dbdump(buff,bytes)
#else
#include <stdio.h>
#define dbif(cond) if (cond)
#define dbprintf(args) printf args
extern void dbdump(const void *buff,unsigned long bytes);
#endif
#endif

#endif
