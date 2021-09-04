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
 *   File: cplatform_semaphore.h
 *
 * Author: $author$
 *   Date: 6/12/2011
 **********************************************************************
 */
#ifndef _CPLATFORM_SEMAPHORE_H
#define _CPLATFORM_SEMAPHORE_H

#include "cplatform_time.h"
#include "cplatform_errno.h"

#if defined(WINDOWS) 
/* Windows
 */
typedef HANDLE 
sem_t;

#else /* defined(WINDOWS) */
/* Unix
 */
#include <semaphore.h>
#endif /* defined(WINDOWS) */

#define SEMAPHORE_PROCESS_PRIVATE 0
#define SEMAPHORE_PROCESS_SHARED  1

#if defined(__cplusplus)
extern "C" {
#endif /* defined(__cplusplus) */

#if defined(WINDOWS) 
/* Windows
 */
int sem_init(sem_t *sem, int pshared, unsigned int value);
int sem_destroy(sem_t *sem);
int sem_post(sem_t *sem);
int sem_getvalue(sem_t *sem, int *sval);
int sem_trywait(sem_t *sem);
int sem_wait(sem_t *sem);

sem_t *sem_open(const char *name, int oflag, ...);
int    sem_close(sem_t *);
int    sem_unlink(const char *);
#else /* defined(WINDOWS) */
/* Unix
 */

#if defined(_POSIX_TIMEOUTS) && (_POSIX_TIMEOUTS >=0 )
#define SEM_HAS_TIMEDWAIT
#endif /* defined(_POSIX_TIMEOUTS) && (_POSIX_TIMEOUTS >=0 ) */

#endif /* defined(WINDOWS) */

#if !defined(SEM_HAS_TIMEDWAIT)
int sem_timedwait
(sem_t *sem, const struct timespec *abs_timeout);
#endif /* !defined(SEM_HAS_TIMEDWAIT) */

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /* _CPLATFORM_SEMAPHORE_H */
