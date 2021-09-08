///////////////////////////////////////////////////////////////////////
//   File: evplatform_wait.h
//
// Author: $author$
//   Date: 7/23/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _EVPLATFORM_WAIT_H
#define _EVPLATFORM_WAIT_H

#include "evplatform_pid.h"

#if defined(WIN32) 
// Windows
#else // defined(WIN32) 
// Unix
#include <sys/types.h>
#include <sys/wait.h>
#endif // defined(WIN32)

#if defined(__cplusplus)
extern "C" {
#endif

#if defined(WIN32) 
// Windows
///////////////////////////////////////////////////////////////////////
// Function: wait
//
//   Author: $author$
//     Date: 7/23/2007
///////////////////////////////////////////////////////////////////////
pid_t wait
(int* status);
///////////////////////////////////////////////////////////////////////
// Function: waitpid
//
//   Author: $author$
//     Date: 7/23/2007
///////////////////////////////////////////////////////////////////////
pid_t waitpid
(pid_t pid,
 int* status,
 int options);
#else // defined(WIN32) 
// Unix
#endif // defined(WIN32)

#if defined(__cplusplus)
}
#endif

#endif // _EVPLATFORM_WAIT_H
