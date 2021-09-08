///////////////////////////////////////////////////////////////////////
//   File: evplatform_thread.h
//
// Author: $author$
//   Date: 4/7/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _EVPLATFORM_THREAD_H
#define _EVPLATFORM_THREAD_H

#include "evplatform.h"

#if defined(WIN32) 
// Windows
#define INVALID_THREAD NULL
#define THREAD_FUNC WINAPI
#define THREAD_EXIT(result)
typedef HANDLE THREAD;
typedef DWORD THREAD_RESULT;
typedef LPVOID THREAD_PARAM;
#else // defined(WIN32) 
// Unix
#include <pthread.h>
#define INVALID_THREAD -1
#define THREAD_FUNC
#define THREAD_EXIT(result) pthread_exit(result)
typedef pthread_t THREAD;
typedef void* THREAD_RESULT;
typedef void* THREAD_PARAM;
#endif // defined(WIN32)

#if defined(__cplusplus)
extern "C" {
#endif

#if defined(__cplusplus)
}
#endif

#endif // _EVPLATFORM_THREAD_H
