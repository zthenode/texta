/**
 **********************************************************************
 * Copyright (c) 1988-2011 $organization$
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
 *   File: cplatform_pthread.h
 *
 * Author: $author$
 *   Date: 3/19/2011
 **********************************************************************
 */
#ifndef _CPLATFORM_PTHREAD_H
#define _CPLATFORM_PTHREAD_H

#include "cplatform_errno.h"
#include "cplatform_time.h"

#if defined(WINDOWS) 
/* Windows
 */
#define PTHREAD_PROCESS_PRIVATE 0
#define PTHREAD_PROCESS_SHARED  1
#define PTHREAD_SCOPE_PROCESS   PTHREAD_PROCESS_PRIVATE
#define PTHREAD_SCOPE_SYSTEM    PTHREAD_PROCESS_SHARED

/*
 * mutex
 */
typedef HANDLE
pthread_mutex_t;

typedef SECURITY_ATTRIBUTES
pthread_mutexattr_t;

#define PTHREAD_MUTEX_NORMAL     0
#define PTHREAD_MUTEX_ERRORCHECK 1
#define PTHREAD_MUTEX_RECURSIVE  2
#define PTHREAD_MUTEX_DEFAULT    3

/*
 * cond
 */
typedef HANDLE
pthread_cond_t;

typedef SECURITY_ATTRIBUTES
pthread_condattr_t;

/*
 * thread
 */
typedef HANDLE
pthread_t;

typedef SECURITY_ATTRIBUTES
pthread_attr_t;

#else /* defined(WINDOWS) */
/* Unix
 */
#include <pthread.h>
#endif /* defined(WINDOWS) */

#if defined(_POSIX_TIMEOUTS) && (_POSIX_TIMEOUTS >=0 )
#define PTHREAD_MUTEX_HAS_TIMEDLOCK
#define PTHREAD_COND_HAS_TIMEDWAIT
#define PTHREAD_HAS_TIMEDJOIN
#define PTHREAD_HAS_TRYJOIN
#endif /* defined(_POSIX_TIMEOUTS) && (_POSIX_TIMEOUTS >=0 ) */

#if defined(__cplusplus)
extern "C" {
#endif /* defined(__cplusplus) */

#if defined(WINDOWS) 
/* Windows
 */

/*
 * mutex
 */
int pthread_mutexattr_init(pthread_mutexattr_t* mutexattr);
int pthread_mutexattr_destroy(pthread_mutexattr_t* mutexattr);

int pthread_mutexattr_setpshared(pthread_mutexattr_t* mutexattr, int pshared);
int pthread_mutexattr_getpshared(const pthread_mutexattr_t* attr, int* pshared);

int pthread_mutexattr_settype(pthread_mutexattr_t* mutexattr, int type);
int pthread_mutexattr_gettype(const pthread_mutexattr_t* mutexattr, int* type);

int pthread_mutex_init
(pthread_mutex_t* mutex, const pthread_mutexattr_t* mutexattr);
int pthread_mutex_destroy(pthread_mutex_t* mutex);

int pthread_mutex_lock(pthread_mutex_t* mutex);
int pthread_mutex_trylock(pthread_mutex_t* mutex);
int pthread_mutex_timedlock
(pthread_mutex_t* mutex, const struct timespec* timespec);
int pthread_mutex_unlock(pthread_mutex_t* mutex);

/*
 * cond
 */
int pthread_condattr_init(pthread_condattr_t* condattr);
int pthread_condattr_destroy(pthread_condattr_t* condattr);

int pthread_condattr_setpshared(pthread_condattr_t* condattr, int pshared);
int pthread_condattr_getpshared(const pthread_condattr_t* condattr, int* pshared);

int pthread_cond_init
(pthread_cond_t* cond, const pthread_condattr_t* condattr);
int pthread_cond_destroy(pthread_cond_t* cond);

int pthread_cond_broadcast(pthread_cond_t* cond);
int pthread_cond_signal(pthread_cond_t* cond);

int pthread_cond_wait
(pthread_cond_t* cond, pthread_mutex_t* mutex);

int pthread_cond_timedwait
(pthread_cond_t* cond, pthread_mutex_t* mutex, 
 const struct timespec* abstime);

/*
 * thread
 */

int pthread_attr_init(pthread_attr_t *attr);
int pthread_attr_destroy(pthread_attr_t *attr);

int pthread_create
(pthread_t *thread, const pthread_attr_t *attr,
 void *(*start_routine)(void*), void *arg);

int pthread_join(pthread_t thread, void **value_ptr);
int pthread_tryjoin_np(pthread_t thread, void **value_ptr);
int pthread_timedjoin_np
(pthread_t thread, void **value_ptr, const struct timespec* timespec);
int pthread_detach(pthread_t thread);
void pthread_exit(void *value_ptr);

#else /* defined(WINDOWS) */
/* Unix
 */

/*
 * mutex
 */
#if !defined(PTHREAD_MUTEX_HAS_TIMEDLOCK)
int pthread_mutex_timedlock
(pthread_mutex_t* mutex, const struct timespec* timespec);
#endif /* !defined(PTHREAD_MUTEX_HAS_TIMEDLOCK) */

/*
 * cond
 */
#if !defined(PTHREAD_COND_HAS_TIMEDWAIT)
int pthread_cond_timedwait
(pthread_cond_t* cond, pthread_mutex_t* mutex, 
 const struct timespec* abstime);
#endif /* !defined(PTHREAD_COND_HAS_TIMEDWAIT) */

/*
 * thread
 */
#if !defined(PTHREAD_HAS_TIMEDJOIN)
int pthread_timedjoin_np
(pthread_t thread, void **value_ptr, const struct timespec* timespec);
#endif /* !defined(PTHREAD_HAS_TIMEDJOIN) */

#if !defined(PTHREAD_HAS_TRYJOIN)
int pthread_tryjoin_np
(pthread_t thread, void **value_ptr);
#endif /* !defined(PTHREAD_HAS_TRYJOIN) */

#endif /* defined(WINDOWS) */

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /* _CPLATFORM_PTHREAD_H */
