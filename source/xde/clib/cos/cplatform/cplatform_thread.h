/**
 **********************************************************************
 * Copyright (c) 1988-2008 $organization$
 *
 * This software is provided by the author and contributors ``as is'' 
 * and any express or implied warranties, including, but not limited to, 
 * the implied warranties of merchantability and fitness for a particular 
 * purpose are disclaimed. In no event shall the author or contributors 
 * be liable for any direct, indirect, incidental, special, exemplary, 
 * or consequential damages (including, but not limited to, procurement 
 * of substitute goods or services; loss of use, data, or profits; or 
 * business interruption) however caused and on any theory of liability, 
 * whether in contract, strict liability, or tort (including negligence 
 * or otherwise) arising in any way out of the use of this software, 
 * even if advised of the possibility of such damage.
 *
 *   File: cplatform_thread.h
 *
 * Author: $author$
 *   Date: 2/14/2008
 **********************************************************************
 */
#ifndef _CPLATFORM_THREAD_H
#define _CPLATFORM_THREAD_H

#include "cplatform.h"

#if defined(WINDOWS) 
/* Windows
 */
#if !defined(CTHREAD_WINDOWS_API) 
#if !defined(CTHREAD_UNIX_API) 
/* use Windows API
 */
#define CTHREAD_WINDOWS_API
#endif /* !defined(CTHREAD_UNIX_API) */
#endif /* !defined(CTHREAD_WINDOWS_API) */

typedef int
pthread_t;

typedef struct pthread_attr {
    int attr;
} pthread_attr_t;

#else /* defined(WINDOWS) */
/* Unix
 */
#include <pthread.h>
#if !defined(CTHREAD_UNIX_API) 
#if !defined(CTHREAD_WINDOWS_API) 
/* use Unix API
 */
#define CTHREAD_UNIX_API
#endif /* !defined(CTHREAD_WINDOWS_API) */
#endif /* !defined(CTHREAD_UNIX_API) */

typedef DWORD WINAPI 
(*LPTHREAD_START_ROUTINE)(LPVOID lpParameter);
#endif /* defined(WINDOWS) */

#if defined(CTHREAD_WINDOWS_API) 
/* use Windows API
 */
#define INVALID_THREAD NULL
typedef HANDLE THREAD;
typedef SECURITY_ATTRIBUTES THREAD_ATTR;
#define THREAD_EXIT(result)
#if defined(CTHREAD_WINDOWS_API_USE_CREATETHREAD) 
/* Use CreateThread
 */
#define THREAD_FUNC WINAPI
typedef DWORD THREAD_RESULT;
typedef LPVOID THREAD_PARAM;
#else /* defined(CTHREAD_WINDOWS_API_USE_CREATETHREAD) */
/* Use beginthread
 */
#define THREAD_FUNC __stdcall
typedef unsigned THREAD_RESULT;
typedef void* THREAD_PARAM;
#endif /* defined(CTHREAD_WINDOWS_API_USE_CREATETHREAD) */
#else /* defined(CTHREAD_WINDOWS_API) */
/* use Unix API
 */
#if defined(MACOSX)
#define INVALID_THREAD 0
#else /* defined(MACOSX) */
#define INVALID_THREAD -1
#endif /* defined(MACOSX) */
#define THREAD_FUNC
#define THREAD_EXIT(result) pthread_exit(result)
typedef pthread_t THREAD;
typedef pthread_attr_t THREAD_ATTR;
typedef void* THREAD_RESULT;
typedef void* THREAD_PARAM;
#endif /* defined(CTHREAD_WINDOWS_API) */

#if defined(__cplusplus)
extern "C" {
#endif /* defined(__cplusplus) */

#if defined(WINDOWS) 
/* Windows
 */
int pthread_create
(pthread_t *restrict thread,
 const pthread_attr_t *restrict attr,
 void *(*start_routine)(void*), void *restrict arg);

int pthread_join(pthread_t thread, void **value_ptr);
void pthread_exit(void *value_ptr);

int pthread_attr_init(pthread_attr_t *attr);
int pthread_attr_destroy(pthread_attr_t *attr);
#else /* defined(WINDOWS) */
/* Unix
 */
DWORD WINAPI ThreadProc(LPVOID lpParameter);
HANDLE CreateThread(
  LPSECURITY_ATTRIBUTES lpThreadAttributes,
  SIZE_T dwStackSize,
  LPTHREAD_START_ROUTINE lpStartAddress,
  LPVOID lpParameter,
  DWORD dwCreationFlags,
  LPDWORD lpThreadId
);
uintptr_t _beginthread( 
   void( *start_address )( void * ),
   unsigned stack_size,
   void *arglist 
);
uintptr_t _beginthreadex( 
   void *security,
   unsigned stack_size,
   unsigned ( *start_address )( void * ),
   void *arglist,
   unsigned initflag,
   unsigned *thrdaddr 
);
#endif /* defined(WINDOWS) */

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /* _CPLATFORM_THREAD_H */
