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
 *   File: cplatform_event.h
 *
 * Author: $author$
 *   Date: 2/3/2008
 **********************************************************************
 */
#ifndef _CPLATFORM_EVENT_H
#define _CPLATFORM_EVENT_H

#include "cplatform_mutex.h"

#if defined(WIN32) 
/* Windows
 */
typedef struct pthread_cond
pthread_cond_t;

typedef struct pthread_condattr
pthread_condattr_t;

#else /* defined(WIN32) */
/* Unix
 */
#include <pthread.h>
#endif /* defined(WIN32) */

#if defined(__cplusplus)
extern "C" {
#endif /* defined(__cplusplus) */

#if defined(WIN32) 
/* Windows
 */
int pthread_cond_init
(pthread_cond_t *cond, const pthread_condattr_t *attr);

int pthread_cond_destroy(pthread_cond_t *cond);

int pthread_cond_wait
(pthread_cond_t *cond,
 pthread_mutex_t *mutex);

int pthread_cond_timedwait
(pthread_cond_t *cond, 
 pthread_mutex_t *mutex,
 const struct timespec *abstime);

int pthread_condattr_init(pthread_condattr_t *attr);
int pthread_condattr_destroy(pthread_condattr_t *attr);

int pthread_condattr_setpshared
(pthread_condattr_t *attr, int pshared);

int  pthread_condattr_getpshared
(const pthread_condattr_t *attr, int *pshared);

#else /* defined(WIN32) */
/* Unix
 */
#endif /* defined(WIN32) */

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /* _CPLATFORM_EVENT_H */
