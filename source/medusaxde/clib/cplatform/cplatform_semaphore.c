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
 *   File: cplatform_semaphore.c
 *
 * Author: $author$
 *   Date: 6/12/2011
 **********************************************************************
 */
#include "cplatform_semaphore.h"
#include "cplatform_errno.h"

#if defined(WINDOWS) 
/* Windows
 */

/**
 **********************************************************************
 * Function: sem_init
 *
 *   Author: $author$
 *     Date: 6/12/2011
 **********************************************************************
 */
int sem_init
(sem_t* sem, int pshared, unsigned int value)
{
    int err = EINVAL;
    return err;
}
/**
 **********************************************************************
 * Function: sem_destroy
 *
 *   Author: $author$
 *     Date: 6/12/2011
 **********************************************************************
 */
int sem_destroy
(sem_t* sem)
{
    int err = EINVAL;
    return err;
}

/**
 **********************************************************************
 * Function: sem_post
 *
 *   Author: $author$
 *     Date: 6/12/2011
 **********************************************************************
 */
int sem_post
(sem_t* sem)
{
    int err = EINVAL;
    return err;
}
/**
 **********************************************************************
 * Function: sem_getvalue
 *
 *   Author: $author$
 *     Date: 6/12/2011
 **********************************************************************
 */
int sem_getvalue
(sem_t* sem, int *sval)
{
    int err = EINVAL;
    return err;
}
/**
 **********************************************************************
 * Function: sem_trywait
 *
 *   Author: $author$
 *     Date: 6/12/2011
 **********************************************************************
 */
int sem_trywait
(sem_t* sem)
{
    int err = EINVAL;
    return err;
}
/**
 **********************************************************************
 * Function: sem_wait
 *
 *   Author: $author$
 *     Date: 6/12/2011
 **********************************************************************
 */
int sem_wait
(sem_t* sem)
{
    int err = EINVAL;
    return err;
}

/**
 **********************************************************************
 * Function: sem_open
 *
 *   Author: $author$
 *     Date: 6/12/2011
 **********************************************************************
 */
sem_t* sem_open
(const char* name, int oflag, ...)
{
    sem_t* sem = 0;
    return sem;
}
/**
 **********************************************************************
 * Function: sem_close
 *
 *   Author: $author$
 *     Date: 6/12/2011
 **********************************************************************
 */
int sem_close
(sem_t* sem)
{
    int err = EINVAL;
    return err;
}
/**
 **********************************************************************
 * Function: sem_unlink
 *
 *   Author: $author$
 *     Date: 6/12/2011
 **********************************************************************
 */
int sem_unlink
(const char* name)
{
    int err = EINVAL;
    return err;
}

#else /* defined(WINDOWS) */
/* Unix
 */
#endif /* defined(WINDOWS) */

#if !defined(SEM_HAS_TIMEDWAIT)
/**
 **********************************************************************
 * Function: sem_timedwait
 *
 *   Author: $author$
 *     Date: 6/12/2011
 **********************************************************************
 */
int sem_timedwait
(sem_t* sem, const struct timespec *abs_timeout)
{
    int err = EINVAL;
    return err;
}
#endif /* !defined(SEM_HAS_TIMEDWAIT) */
