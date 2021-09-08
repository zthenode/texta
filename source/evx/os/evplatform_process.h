///////////////////////////////////////////////////////////////////////
//   File: evplatform_process.h
//
// Author: $author$
//   Date: 5/2/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _EVPLATFORM_PROCESS_H
#define _EVPLATFORM_PROCESS_H

#include "evplatform.h"

#if defined(WIN32) 
// Windows
typedef HANDLE PROCESS;
typedef PROCESS INVALID_PROCESS_T;
#define INVALID_PROCESS 0
#else // defined(WIN32) 
// Unix
#include <sys/wait.h>
#include <errno.h>
typedef pid_t PROCESS;
typedef PROCESS INVALID_PROCESS_T;
#define INVALID_PROCESS -1
#endif // defined(WIN32)

#if defined(__cplusplus)
extern "C" {
#endif

#if defined(__cplusplus)
}
#endif

#endif // _EVPLATFORM_PROCESS_H
