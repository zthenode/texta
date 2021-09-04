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
 *   File: cplatform_pthread.c
 *
 * Author: $author$
 *   Date: 3/19/2011
 **********************************************************************
 */
#include "cplatform_pthread.h"

#if defined(WINDOWS) 
/* Windows
 */

/*
 * mutex
 */
/**
 **********************************************************************
 * Function: pthread_mutexattr_init
 *
 *   Author: $author$
 *     Date: 3/19/2011
 **********************************************************************
 */
int pthread_mutexattr_init
(pthread_mutexattr_t* mutexattr)
{
    int err = 1;
    return err;
}
/**
 **********************************************************************
 * Function: pthread_mutexattr_destroy
 *
 *   Author: $author$
 *     Date: 3/19/2011
 **********************************************************************
 */
int pthread_mutexattr_destroy
(pthread_mutexattr_t* mutexattr)
{
    int err = 1;
    return err;
}
/**
 **********************************************************************
 * Function: pthread_mutexattr_settype
 *
 *   Author: $author$
 *     Date: 6/12/2011
 **********************************************************************
 */
int pthread_mutexattr_settype
(pthread_mutexattr_t* mutexattr, int type)
{
    int err = EINVAL;
    return err;
}
/**
 **********************************************************************
 * Function: pthread_mutexattr_gettype
 *
 *   Author: $author$
 *     Date: 6/12/2011
 **********************************************************************
 */
int pthread_mutexattr_gettype
(const pthread_mutexattr_t* mutexattr, int* type)
{
    int err = EINVAL;
    return err;
}
/**
 **********************************************************************
 * Function: pthread_mutexattr_setpshared
 *
 *   Author: $author$
 *     Date: 6/12/2011
 **********************************************************************
 */
int pthread_mutexattr_setpshared
(pthread_mutexattr_t* mutexattr, int type)
{
    int err = EINVAL;
    return err;
}
/**
 **********************************************************************
 * Function: pthread_mutexattr_getpshared
 *
 *   Author: $author$
 *     Date: 6/12/2011
 **********************************************************************
 */
int pthread_mutexattr_getpshared
(const pthread_mutexattr_t* mutexattr, int* type)
{
    int err = EINVAL;
    return err;
}

/**
 **********************************************************************
 * Function: pthread_mutex_init
 *
 *   Author: $author$
 *     Date: 3/19/2011
 **********************************************************************
 */
int pthread_mutex_init
(pthread_mutex_t* mutex, 
 const pthread_mutexattr_t* mutexattr)
{
    int err = 1;
    return err;
}
/**
 **********************************************************************
 * Function: pthread_mutex_destroy
 *
 *   Author: $author$
 *     Date: 3/19/2011
 **********************************************************************
 */
int pthread_mutex_destroy
(pthread_mutex_t* mutex)
{
    int err = 1;
    return err;
}

/**
 **********************************************************************
 * Function: pthread_mutex_lock
 *
 *   Author: $author$
 *     Date: 3/19/2011
 **********************************************************************
 */
int pthread_mutex_lock
(pthread_mutex_t* mutex)
{
    int err = 1;
    return err;
}
/**
 **********************************************************************
 * Function: pthread_mutex_trylock
 *
 *   Author: $author$
 *     Date: 3/19/2011
 **********************************************************************
 */
int pthread_mutex_trylock
(pthread_mutex_t* mutex)
{
    int err = 1;
    return err;
}
/**
 **********************************************************************
 * Function: pthread_mutex_unlock
 *
 *   Author: $author$
 *     Date: 3/19/2011
 **********************************************************************
 */
int pthread_mutex_unlock
(pthread_mutex_t* mutex)
{
    int err = 1;
    return err;
}

/*
 * cond
 */
/**
 **********************************************************************
 * Function: pthread_condattr_init
 *
 *   Author: $author$
 *     Date: 6/12/2011
 **********************************************************************
 */
int pthread_condattr_init
(pthread_condattr_t* condattr)
{
    int err = EINVAL;
    return err;
}
/**
 **********************************************************************
 * Function: pthread_condattr_destroy
 *
 *   Author: $author$
 *     Date: 6/12/2011
 **********************************************************************
 */
int pthread_condattr_destroy
(pthread_condattr_t* condattr)
{
    int err = EINVAL;
    return err;
}

/**
 **********************************************************************
 * Function: pthread_condattr_setpshared
 *
 *   Author: $author$
 *     Date: 6/12/2011
 **********************************************************************
 */
int pthread_condattr_setpshared
(pthread_condattr_t* condattr, int pshared)
{
    int err = EINVAL;
    return err;
}
/**
 **********************************************************************
 * Function: pthread_condattr_getpshared
 *
 *   Author: $author$
 *     Date: 6/12/2011
 **********************************************************************
 */
int pthread_condattr_getpshared
(const pthread_condattr_t* condattr, int* pshared)
{
    int err = EINVAL;
    return err;
}

/**
 **********************************************************************
 * Function: pthread_cond_init
 *
 *   Author: $author$
 *     Date: 6/12/2011
 **********************************************************************
 */
int pthread_cond_init
(pthread_cond_t* cond, const pthread_condattr_t* condattr)
{
    int err = EINVAL;
    return err;
}
/**
 **********************************************************************
 * Function: pthread_cond_destroy
 *
 *   Author: $author$
 *     Date: 6/12/2011
 **********************************************************************
 */
int pthread_cond_destroy(pthread_cond_t* cond)
{
    int err = EINVAL;
    return err;
}

/**
 **********************************************************************
 * Function: pthread_cond_broadcast
 *
 *   Author: $author$
 *     Date: 6/12/2011
 **********************************************************************
 */
int pthread_cond_broadcast(pthread_cond_t* cond)
{
    int err = EINVAL;
    return err;
}
/**
 **********************************************************************
 * Function: pthread_cond_signal
 *
 *   Author: $author$
 *     Date: 6/12/2011
 **********************************************************************
 */
int pthread_cond_signal(pthread_cond_t* cond)
{
    int err = EINVAL;
    return err;
}

/**
 **********************************************************************
 * Function: pthread_cond_wait
 *
 *   Author: $author$
 *     Date: 6/12/2011
 **********************************************************************
 */
int pthread_cond_wait
(pthread_cond_t* cond, pthread_mutex_t* mutex)
{
    int err = EINVAL;
    return err;
}

/*
 * thread
 */

/**
 **********************************************************************
 * Function: pthread_attr_init
 *
 *   Author: $author$
 *     Date: 6/16/2011
 **********************************************************************
 */
int pthread_attr_init
(pthread_attr_t *attr)
{
    int err = EINVAL;
    return err;
}
/**
 **********************************************************************
 * Function: pthread_attr_destroy
 *
 *   Author: $author$
 *     Date: 6/16/2011
 **********************************************************************
 */
int pthread_attr_destroy
(pthread_attr_t *attr)
{
    int err = EINVAL;
    return err;
}

/**
 **********************************************************************
 * Function: pthread_create
 *
 *   Author: $author$
 *     Date: 6/16/2011
 **********************************************************************
 */
int pthread_create
(pthread_t *thread, const pthread_attr_t *attr,
 void *(*start_routine)(void*), void *arg)
{
    int err = EINVAL;
    return err;
}
/**
 **********************************************************************
 * Function: pthread_join
 *
 *   Author: $author$
 *     Date: 6/16/2011
 **********************************************************************
 */
int pthread_join
(pthread_t thread, void **value_ptr)
{
    int err = EINVAL;
    return err;
}
/**
 **********************************************************************
 * Function: pthread_detach
 *
 *   Author: $author$
 *     Date: 6/16/2011
 **********************************************************************
 */
int pthread_detach
(pthread_t thread)
{
    int err = EINVAL;
    return err;
}
/**
 **********************************************************************
 * Function: pthread_exit
 *
 *   Author: $author$
 *     Date: 6/16/2011
 **********************************************************************
 */
void pthread_exit
(void *value_ptr)
{
}

#else /* defined(WINDOWS) */
/* Unix
 */
#endif /* defined(WINDOWS) */

#if !defined(PTHREAD_MUTEX_HAS_TIMEDLOCK)
/**
 **********************************************************************
 * Function: pthread_mutex_timedlock
 *
 *   Author: $author$
 *     Date: 3/19/2011
 **********************************************************************
 */
int pthread_mutex_timedlock
(pthread_mutex_t* mutex, const struct timespec* timespec)
{
    int err = 1;
    return err;
}
#endif /* !defined(PTHREAD_MUTEX_HAS_TIMEDLOCK) */

#if !defined(PTHREAD_COND_HAS_TIMEDWAIT)
/**
 **********************************************************************
 * Function: pthread_cond_timedwait
 *
 *   Author: $author$
 *     Date: 6/12/2011
 **********************************************************************
 */
int pthread_cond_timedwait
(pthread_cond_t* cond, pthread_mutex_t* mutex, 
 const struct timespec* abstime)
{
    int err = EINVAL;
    return err;
}
#endif /* !defined(PTHREAD_COND_HAS_TIMEDWAIT) */

#if !defined(PTHREAD_HAS_TIMEDJOIN)
/**
 **********************************************************************
 * Function: pthread_timedjoin_np
 *
 *   Author: $author$
 *     Date: 6/16/2011
 **********************************************************************
 */
int pthread_timedjoin_np
(pthread_t thread, void **value_ptr, const struct timespec* timespec)
{
    int err = EINVAL;
    return err;
}
#endif /* !defined(PTHREAD_HAS_TIMEDJOIN) */

#if !defined(PTHREAD_HAS_TRYJOIN)
/**
 **********************************************************************
 * Function: pthread_tryjoin_np
 *
 *   Author: $author$
 *     Date: 6/16/2011
 **********************************************************************
 */
int pthread_tryjoin_np
(pthread_t thread, void **value_ptr)
{
    int err = EINVAL;
    return err;
}
#endif /* !defined(PTHREAD_HAS_TRYJOIN) */
