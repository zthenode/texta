///////////////////////////////////////////////////////////////////////
//   File: evplatform_exec.h
//
// Author: $author$
//   Date: 7/20/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _EVPLATFORM_EXEC_H
#define _EVPLATFORM_EXEC_H


#include "evplatform.h"

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
// Function: execvp
//
//   Author: $author$
//     Date: 7/20/2007
///////////////////////////////////////////////////////////////////////
int execvp
(const char* file,
 char*const argv[]);
#else // defined(WIN32) 
// Unix
#endif // defined(WIN32)

#if defined(__cplusplus)
}
#endif

#endif // _EVPLATFORM_EXEC_H
