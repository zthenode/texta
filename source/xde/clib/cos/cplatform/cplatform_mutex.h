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
 *   File: cplatform_mutex.h
 *
 * Author: $author$
 *   Date: 2/3/2008
 **********************************************************************
 */
#ifndef _CPLATFORM_MUTEX_H
#define _CPLATFORM_MUTEX_H

#include "cplatform.h"

#if defined(WIN32) 
/* Windows
 */
#define INVALID_MUTEX NULL
typedef HANDLE MUTEX;
typedef SECURITY_ATTRIBUTES MUTEX_ATTR;

typedef struct pthread_mutex 
pthread_mutex_t;

typedef struct pthread_mutexattr 
pthread_mutexattr_t;

#else /* defined(WIN32) */
/* Unix
 */
#include <pthread.h>
typedef pthread_mutex_t MUTEX;
typedef pthread_mutexattr_t MUTEX_ATTR;
#endif /* defined(WIN32) */

#if defined(__cplusplus)
extern "C" {
#endif /* defined(__cplusplus) */

/**
 **********************************************************************
 * Function: InitMutexAttributes
 *
 *   Author: $author$
 *     Date: 2/2/2009
 **********************************************************************
 */
BOOL InitMutexAttributes
(LPSECURITY_ATTRIBUTES lpSecurityAttributes);

#if defined(WIN32) 
/* Windows
 */
int pthread_mutex_init
(pthread_mutex_t *mutex,
 const pthread_mutexattr_t *attr);

int pthread_mutex_destroy
(pthread_mutex_t *mutex);

int pthread_mutex_lock(pthread_mutex_t *mutex);
int pthread_mutex_trylock(pthread_mutex_t *mutex);
int pthread_mutex_unlock(pthread_mutex_t *mutex);

int pthread_mutexattr_settype
(pthread_mutexattr_t *attr, int type);

int pthread_mutexattr_gettype
(const pthread_mutexattr_t *attr, int *type);

int pthread_mutexattr_init(pthread_mutexattr_t *attr);
int pthread_mutexattr_destroy(pthread_mutexattr_t *attr);

#else /* defined(WIN32) */
/* Unix
 */
HANDLE CreateMutex
(LPSECURITY_ATTRIBUTES lpMutexAttributes,
 BOOL bInitialOwner,
 LPCTSTR lpName);

HANDLE OpenMutex
(DWORD dwDesiredAccess,
 BOOL bInheritHandle,
 LPCTSTR lpName);

BOOL ReleaseMutex
(HANDLE hMutex);

#endif /* defined(WIN32) */

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /* _CPLATFORM_MUTEX_H */
