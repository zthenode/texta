///////////////////////////////////////////////////////////////////////
//   File: evplatform_pid.h
//
// Author: $author$
//   Date: 7/18/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _EVPLATFORM_PID_H
#define _EVPLATFORM_PID_H

#include "evplatform.h"

#if defined(WIN32) 
// Windows
typedef int PID;
typedef PID pid_t;
#else // defined(WIN32) 
// Unix
#include <sys/types.h>
#include <unistd.h>
typedef pid_t PID;
#endif // defined(WIN32)

#define INVALID_PID ((PID)-1)

#if defined(__cplusplus)
extern "C" {
#endif

#if defined(WIN32) 
// Windows
///////////////////////////////////////////////////////////////////////
// Function: getpid
//
//   Author: $author$
//     Date: 7/23/2007
///////////////////////////////////////////////////////////////////////
pid_t getpid
(void);
///////////////////////////////////////////////////////////////////////
// Function: getppid
//
//   Author: $author$
//     Date: 7/23/2007
///////////////////////////////////////////////////////////////////////
pid_t getppid
(void);
#else // defined(WIN32) 
// Unix
#endif // defined(WIN32)

#if defined(__cplusplus)
}
#endif

#endif // _EVPLATFORM_PID_H
