///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2018 $organization$
///
/// This software is provided by the author and contributors ``as is'' 
/// and any express or implied warranties, including, but not limited to, 
/// the implied warranties of merchantability and fitness for a particular 
/// purpose are disclaimed. In no event shall the author or contributors 
/// be liable for any direct, indirect, incidental, special, exemplary, 
/// or consequential damages (including, but not limited to, procurement 
/// of substitute goods or services; loss of use, data, or profits; or 
/// business interruption) however caused and on any theory of liability, 
/// whether in contract, strict liability, or tort (including negligence 
/// or otherwise) arising in any way out of the use of this software, 
/// even if advised of the possibility of such damage.
///
///   File: mutex.hpp
///
/// Author: $author$
///   Date: 5/9/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_MT_POSIX_MUTEX_HPP
#define _XOS_NADIR_XOS_MT_POSIX_MUTEX_HPP

#include "xos/mt/mutex.hpp"
#include "xos/base/created.hpp"
#include "xos/base/creator.hpp"
#include "xos/base/attached.hpp"
#include "xos/base/attacher.hpp"
#include "xos/base/logged.hpp"
#include "xos/io/logger.hpp"

#include <pthread.h>
#include <time.h>
#include <errno.h>

#if defined(_POSIX_TIMEOUTS) && (_POSIX_TIMEOUTS >=0 )
#define PTHREAD_MUTEX_HAS_TIMEDLOCK
#else // defined(_POSIX_TIMEOUTS) && (_POSIX_TIMEOUTS >=0 )
#define PTHREAD_MUTEX_HAS_TIMEDLOCK
#define pthread_mutex_timedlock(m, t) EINVAL
#define clock_gettime(f, t) memset(t, 0, sizeof(t))
#endif // defined(_POSIX_TIMEOUTS) && (_POSIX_TIMEOUTS >=0 )

namespace xos {
namespace mt {
namespace posix {

typedef pthread_mutexattr_t mutexattr_t;
typedef pthread_mutex_t mutex_t;
typedef mutex_t* mutex_attached_t;

typedef base::creatort<mt::mutex> mutex_creator;
typedef base::attachert<mutex_attached_t, int, 0, mutex_creator> mutex_attacher;
typedef base::loggedt<mutex_attacher, base::base> mutex_logged;
typedef base::attachedt<mutex_attached_t, int, 0, mutex_attacher, mutex_logged> mutex_attached;
typedef base::createdt<mutex_attached_t, int, 0, mutex_attacher, mutex_attached> mutex_created;

typedef mutex_attacher mutex_implements;
typedef mutex_created mutex_extends;
///////////////////////////////////////////////////////////////////////
///  Class: mutext
///////////////////////////////////////////////////////////////////////
template
<class TImplements = mutex_implements, class TExtends = mutex_extends>

class _EXPORT_CLASS mutext: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    mutext(mutex_attached_t attached, bool is_created, bool is_logging)
    : Extends(attached, is_created) {
        this->set_is_logging(is_logging);
    }
    mutext(mutex_attached_t attached, bool is_created)
    : Extends(attached, is_created) {
        this->set_is_logging(false);
    }
    mutext(mutex_attached_t attached)
    : Extends(attached) {
        this->set_is_logging(false);
    }
    mutext(bool is_logging) {
        this->set_is_logging(is_logging);
        construct();
    }
    mutext() {
        this->set_is_logging(true);
        construct();
    }
    virtual ~mutext() {
        destruct();
    }

private:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void construct() {
        if (!(this->create())) {
            base::creator_exception e = base::failed_to_create;
            XOS_IS_ERR_LOGGING_ERROR("...failed on this->create() throw (base::creator_exception e = base::failed_to_create)...");
            throw (e);
        }
    }
    virtual void destruct() {
        if (!(this->destroyed())) {
            base::creator_exception e = base::failed_to_destroy;
            XOS_IS_ERR_LOGGING_ERROR("...failed on this->destroyed() throw (base::creator_exception e = base::failed_to_destroy)...");
            throw (e);
        }
    }

public:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool unlock() {
        mutex_attached_t attached = 0;
        if ((attached = this->attached_to())) {
            int err = 0;
            if (!(err = ::pthread_mutex_unlock(attached))) {
                return true;
            } else {
                XOS_IS_LOGGING_ERROR("failed " << err << " on ::pthread_mutex_unlock()");
            }
        }
        return false;
    }
    virtual bool lock() {
        mutex_attached_t attached = 0;
        if ((attached = this->attached_to())) {
            int err = 0;
            if (!(err = ::pthread_mutex_lock(attached))) {
                return true;
            } else {
                XOS_IS_LOGGING_ERROR("...failed " << err << " on ::pthread_mutex_lock()");
            }
        }
        return false;
    }
    virtual wait_status try_lock() {
        mutex_attached_t attached = 0;
        if ((attached = this->attached_to())) {
            int err = 0;
            if (!(err =  ::pthread_mutex_trylock(attached))) {
                return wait_success;
            } else {
                switch (err) {
                case ETIMEDOUT:
                    XOS_IS_LOGGING_TRACE("...ETIMEDOUT err = " << err << " on ::pthread_mutex_trylock()");
                    return wait_busy;
                case EINTR:
                    XOS_IS_LOGGING_ERROR("...EINTR err = " << err << " on ::pthread_mutex_trylock()");
                    return wait_interrupted;
                default:
                    XOS_IS_LOGGING_ERROR("...failed err = " << err << " on ::pthread_mutex_trylock()");
                    return wait_failed;
                }
            }
        }
        return wait_failed;
    }
    virtual wait_status untimed_lock() {
        mutex_attached_t attached = 0;
        if ((attached = this->attached_to())) {
            int err = 0;
            if (!(err =  ::pthread_mutex_lock(attached))) {
                return wait_success;
            } else {
                switch (err) {
                case ETIMEDOUT:
                    XOS_IS_LOGGING_ERROR("...ETIMEDOUT err = " << err << " on ::pthread_mutex_lock()");
                    return wait_busy;
                case EINTR:
                    XOS_IS_LOGGING_ERROR("...EINTR err = " << err << " on ::pthread_mutex_lock()");
                    return wait_interrupted;
                default:
                    XOS_IS_LOGGING_ERROR("...failed err = " << err << " on ::pthread_mutex_lock()");
                    return wait_failed;
                }
            }
        }
        return wait_failed;
    }
    virtual wait_status timed_lock(mseconds_t milliseconds) {
        if (0 < milliseconds) {
#if defined(PTHREAD_MUTEX_HAS_TIMEDLOCK)
            mutex_attached_t attached = 0;
            if ((attached = this->attached_to())) {
                int err = 0;
                struct timespec until_time;
                ::clock_gettime(CLOCK_REALTIME, &until_time);
                until_time.tv_sec +=  mseconds_seconds(milliseconds);
                until_time.tv_nsec +=  mseconds_nseconds(milliseconds);
                if (!(err = pthread_mutex_timedlock(attached, &until_time))) {
                    return wait_success;
                } else {
                    switch(err) {
                    case ETIMEDOUT:
                        XOS_IS_LOGGING_TRACE("...ETIMEDOUT err = " << err << " on ::pthread_mutex_timedlock()");
                        return wait_busy;
                    case EINTR:
                        XOS_IS_LOGGING_ERROR("...EINTR err = " << err << " on ::pthread_mutex_timedlock()");
                        return wait_interrupted;
                    default:
                        XOS_IS_LOGGING_ERROR("...failed err = " << err << " on ::pthread_mutex_timedlock()");
                        break;
                    }
                }
                return wait_failed;
            }
#else // defined(PTHREAD_MUTEX_HAS_TIMEDLOCK)
            XOS_IS_LOGGING_ERROR("...invalid on ::pthread_mutex_timedlock()");
            return wait_invalid;
#endif // defined(PTHREAD_MUTEX_HAS_TIMEDLOCK)
        } else {
            if (0 == milliseconds) {
                return try_lock();
            } else {
                return untimed_lock();
            }
        }
        return wait_failed;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual mutex_attached_t create_attached() {
        mutex_attached_t detached = 0;
        if ((this->destroyed())) {
            if ((detached = create_detached(mutex_))) {
                this->attach(detached);
            }
        }
        return detached;
    }
    virtual mutex_attached_t create_detached(mutex_t &mutex_) const {
        mutex_attached_t detached = 0;
        int err = 0;
        mutexattr_t mutexattr_;
        if (!(err = ::pthread_mutexattr_init(&mutexattr_))) {
            if (!(err = ::pthread_mutex_init(&mutex_, &mutexattr_))) {
                detached = &mutex_;
            } else {
                XOS_IS_ERR_LOGGING_ERROR("...failed " << err << " on ::pthread_mutex_init()");
            }
            if ((err = ::pthread_mutexattr_destroy(&mutexattr_))) {
                XOS_IS_ERR_LOGGING_ERROR("...failed " << err << " on ::pthread_mutexattr_destroy()");
            }
        } else {
            XOS_IS_ERR_LOGGING_ERROR("...failed " << err << " on ::pthread_mutexattr_init()");
        }
        return detached;
    }
    virtual bool destroy_detached(mutex_attached_t detached) const {
        if ((detached)) {
            int err = 0;
            if (!(err = ::pthread_mutex_destroy(detached))) {
                return true;
            } else {
                XOS_IS_ERR_LOGGING_ERROR("...failed " << err << " on ::pthread_mutex_destroy()");
            }
        }
        return false;
    }
    
protected:
    mutex_t mutex_;
};
typedef mutext<> mutex;

} // namespace posix
} // namespace mt
} // namespace xos

#endif // _XOS_NADIR_XOS_MT_POSIX_MUTEX_HPP 
