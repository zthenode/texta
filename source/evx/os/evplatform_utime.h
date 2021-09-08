///////////////////////////////////////////////////////////////////////
//   File: evplatform_utime.h
//
// Author: $author$
//   Date: 8/10/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _EVPLATFORM_UTIME_H
#define _EVPLATFORM_UTIME_H

#include "evplatform_time.h"

#if defined(WIN32) 
// Windows
#if !defined(_WINSOCKAPI_) 
///////////////////////////////////////////////////////////////////////
//   Struct: timeval
//
//   Author: $author$
//     Date: 8/10/2007
///////////////////////////////////////////////////////////////////////
struct timeval 
{
    long tv_sec;  /* seconds */
    long tv_usec; /* microseconds */
};
#endif // !defined(_WINSOCKAPI_)
///////////////////////////////////////////////////////////////////////
//   Struct: utimbuf
//
//   Author: $author$
//     Date: 8/10/2007
///////////////////////////////////////////////////////////////////////
struct utimbuf 
{
    time_t actime;  /* access time */
    time_t modtime; /* modification time */
};
#else // defined(WIN32) 
// Unix
#include <sys/types.h>
#include <sys/time.h>
#include <utime.h>
#endif // defined(WIN32)

#if defined(__cplusplus)
extern "C" {
#endif

#if defined(WIN32) 
// Windows
///////////////////////////////////////////////////////////////////////
// Function: utime
//
//   Author: $author$
//     Date: 8/10/2007
///////////////////////////////////////////////////////////////////////
int utime(const char *filename, struct utimbuf *buf);
///////////////////////////////////////////////////////////////////////
// Function: utimes
//
//   Author: $author$
//     Date: 8/10/2007
///////////////////////////////////////////////////////////////////////
int utimes(char *filename, struct timeval *tvp);
#else // defined(WIN32) 
// Unix
#endif // defined(WIN32)

#if defined(__cplusplus)
}
#endif

#endif // _EVPLATFORM_UTIME_H
