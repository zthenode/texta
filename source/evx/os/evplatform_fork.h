///////////////////////////////////////////////////////////////////////
//   File: evplatform_fork.h
//
// Author: $author$
//   Date: 7/20/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _EVPLATFORM_FORK_H
#define _EVPLATFORM_FORK_H

#include "evplatform_pid.h"

#if defined(WIN32) 
// Windows
#else // defined(WIN32) 
// Unix
#endif // defined(WIN32)

#if defined(__cplusplus)
extern "C" {
#endif

#if defined(WIN32) 
// Windows
///////////////////////////////////////////////////////////////////////
// Function: fork
//
//   Author: $author$
//     Date: 7/20/2007
///////////////////////////////////////////////////////////////////////
pid_t fork(void);
#else // defined(WIN32) 
// Unix
#endif // defined(WIN32)

#if defined(__cplusplus)
}
#endif

#endif // _EVPLATFORM_FORK_H
