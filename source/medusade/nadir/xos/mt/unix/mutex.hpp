///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2014 $organization$
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
///   Date: 10/30/2014
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_MT_UNIX_MUTEX_HPP
#define _XOS_NADIR_XOS_MT_UNIX_MUTEX_HPP

#include "xos/mt/mutex.hpp"
#include "xos/base/created.hpp"
#include "xos/base/creator.hpp"
#include "xos/base/attached.hpp"
#include "xos/base/attacher.hpp"
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
namespace unix {

typedef pthread_mutexattr_t mutexattr_t;
typedef pthread_mutex_t mutex_t;
typedef mutex_t* mutex_attached_t;

typedef base::creatort<mt::mutex> mutex_creator;
typedef base::attachert<mutex_attached_t, int, 0, mutex_creator> mutex_attacher;
typedef base::attachedt<mutex_attached_t, int, 0, mutex_attacher, base::base> mutex_attached;
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
    mutext
    (mutex_attached_t attached, bool is_created = false, bool is_logging = true)
    : Extends(attached, is_created), is_logging_(is_logging) {
    }
    mutext(bool is_logging = true): is_logging_(is_logging) {
        if (!(this->create())) {
            base::creator_exception e = base::failed_to_create;
            throw (e);
        }
    }
    virtual ~mutext() {
        if (!(this->destroyed())) {
            base::creator_exception e = base::failed_to_destroy;
            throw (e);
        }
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool create() {
        if ((this->destroyed())) {
            int err = 0;
            if (!(err = pthread_mutexattr_init(&mutexattr_))) {
                if (!(err = pthread_mutex_init(&mutex_, &mutexattr_))) {
                    this->attach_created(&mutex_);
                    pthread_mutexattr_destroy(&mutexattr_);
                    return true;
                } else {
                    if ((this->is_logging())) {
                        XOS_LOG_ERROR("failed " << err << " on pthread_mutex_init()");
                    }
                    pthread_mutexattr_destroy(&mutexattr_);
                }
            } else {
                if ((this->is_logging())) {
                    XOS_LOG_ERROR("failed " << err << " on pthread_mutexattr_init()");
                }
            }
        }
        return false;
    }
    virtual bool destroy() {
        mutex_attached_t detached = 0;
        if ((detached = this->detach())) {
            int err = 0;
            if (!(err = pthread_mutex_destroy(detached))) {
                return true;
            } else {
                if ((this->is_logging())) {
                    XOS_LOG_ERROR("failed " << err << " on pthread_mutex_destroy()");
                }
            }
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool unlock() {
        mutex_attached_t attached = 0;
        if ((attached = this->attached_to())) {
            int err = 0;
            if (!(err =  pthread_mutex_unlock(attached))) {
                return true;
            } else {
                if ((this->is_logging())) {
                    XOS_LOG_ERROR("failed " << err << " on pthread_mutex_unlock()");
                }
            }
        }
        return false;
    }
    virtual bool lock() {
        mutex_attached_t attached = 0;
        if ((attached = this->attached_to())) {
            int err = 0;
            if (!(err =  pthread_mutex_lock(attached))) {
                return true;
            } else {
                if ((this->is_logging())) {
                    XOS_LOG_ERROR("...failed " << err << " on pthread_mutex_lock()");
                }
            }
        }
        return false;
    }
    virtual wait_status try_lock() {
        mutex_attached_t attached = 0;
        if ((attached = this->attached_to())) {
            int err = 0;
            if (!(err =  pthread_mutex_trylock(attached))) {
                return wait_success;
            } else {
                if ((this->is_logging())) {
                    if (ETIMEDOUT != (err)) {
                        XOS_LOG_ERROR("...failed " << err << " on pthread_mutex_trylock()");
                    } else {
                        XOS_LOG_TRACE("...failed " << err << " on pthread_mutex_trylock()");
                    }
                }
            }
        }
        return wait_failed;
    }
    virtual wait_status timed_lock(mseconds_t milliseconds) {
#if defined(PTHREAD_MUTEX_HAS_TIMEDLOCK)
        mutex_attached_t attached = 0;
        if ((attached = this->attached_to())) {
            int err = 0;
            if (0 < milliseconds) {
                struct timespec until_time;
                clock_gettime(CLOCK_REALTIME, &until_time);
                until_time.tv_sec +=  milliseconds/1000;
                until_time.tv_nsec +=  (milliseconds%1000)*1000;
                if (!(err = pthread_mutex_timedlock(attached, &until_time))) {
                    return wait_success;
                } else {
                    if ((this->is_logging())) {
                        if (ETIMEDOUT != (err)) {
                            XOS_LOG_ERROR("...failed " << err << " on pthread_mutex_timedlock()");
                        } else {
                            XOS_LOG_TRACE("...failed " << err << " on pthread_mutex_timedlock()");
                        }
                    }
                }
            } else {
                if (!milliseconds) {
                    if (!(err =  pthread_mutex_trylock(attached))) {
                        return wait_success;
                    } else {
                        if ((this->is_logging())) {
                            if (ETIMEDOUT != (err)) {
                                XOS_LOG_ERROR("...failed " << err << " on pthread_mutex_trylock()");
                            } else {
                                XOS_LOG_TRACE("...failed " << err << " on pthread_mutex_trylock()");
                            }
                        }
                    }
                } else {
                    if (!(err =  pthread_mutex_lock(attached))) {
                        return wait_success;
                    } else {
                        if ((this->is_logging())) {
                            XOS_LOG_ERROR("...failed " << err << " on pthread_mutex_lock()");
                        }
                    }
                }
            }
            switch(err) {
            case ETIMEDOUT:
                return wait_busy;
            case EINTR:
                return wait_interrupted;
            }
        }
        return wait_failed;
#else // defined(PTHREAD_MUTEX_HAS_TIMEDLOCK)
        if ((this->is_logging())) {
            XOS_LOG_ERROR("wait_invalid");
        }
        return wait_invalid;
#endif // defined(PTHREAD_MUTEX_HAS_TIMEDLOCK)
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool is_logging() const {
        return is_logging_;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    bool is_logging_;
    mutexattr_t mutexattr_;
    mutex_t mutex_;
};
typedef mutext<> mutex;

} // namespace unix 
} // namespace mt 
} // namespace xos 

#endif // _XOS_NADIR_XOS_MT_UNIX_MUTEX_HPP 
