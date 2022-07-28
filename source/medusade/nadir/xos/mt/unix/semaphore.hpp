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
///   File: semaphore.hpp
///
/// Author: $author$
///   Date: 12/11/2014
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_MT_UNIX_SEMAPHORE_HPP
#define _XOS_NADIR_XOS_MT_UNIX_SEMAPHORE_HPP

#include "xos/mt/semaphore.hpp"
#include "xos/mt/acquirer.hpp"
#include "xos/mt/waiter.hpp"
#include "xos/base/created.hpp"
#include "xos/base/creator.hpp"
#include "xos/base/attached.hpp"
#include "xos/base/attacher.hpp"
#include "xos/io/logger.hpp"

#include <semaphore.h>
#include <errno.h>

#if defined(_POSIX_TIMEOUTS) && (_POSIX_TIMEOUTS >=0 )
#define SEM_HAS_TIMEDWAIT
#endif // defined(_POSIX_TIMEOUTS) && (_POSIX_TIMEOUTS >=0 )

#define SEMAPHORE_PROCESS_PRIVATE 0
#define SEMAPHORE_PROCESS_SHARED  1

namespace xos {
namespace mt {
namespace unix {

typedef sem_t semaphore_t;
typedef semaphore_t* semaphore_attached_t;

typedef base::attachert<semaphore_attached_t, int, 0, mt::semaphore> semaphore_attacher;
typedef base::attachedt<semaphore_attached_t, int, 0, semaphore_attacher, base::base> semaphore_attached;
typedef base::createdt<semaphore_attached_t, int, 0, semaphore_attacher, semaphore_attached> semaphore_created;
typedef semaphore_attacher semaphore_implements;
typedef mt::semaphore_extendt
<semaphore_attached_t, int, 0,
 semaphore_implements, semaphore_created> semaphore_extends;
///////////////////////////////////////////////////////////////////////
///  Class: semaphoret
///////////////////////////////////////////////////////////////////////
template
<class TImplements = semaphore_implements, class TExtends = semaphore_extends>

class _EXPORT_CLASS semaphoret: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    semaphoret() {
        if ((this->initially_created())) {
            if (!(this->create())) {
                base::creator_exception e = base::failed_to_create;
                XOS_LOG_ERROR("...throwing exception failed_to_create");
                throw (e);
            }
        }
    }
    virtual ~semaphoret() {
        if (!(this->destroyed())) {
            base::creator_exception e = base::failed_to_destroy;
            XOS_LOG_ERROR("...throwing exception failed_to_destroy");
            throw (e);
        }
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    using Extends::create;
    virtual bool create(size_t initial_count) {
        if ((this->destroyed())) {
            int pshared = SEMAPHORE_PROCESS_PRIVATE;
            semaphore_t* sem = 0;
            int err = 0;
            if ((!(err = sem_init(&sem_, pshared, initial_count)))) {
                this->attach_created(&sem_);
                return true;
            } else {
                XOS_LOG_ERROR("failed " << errno << " on sem_init()");
            }
        }
        return false;
    }
    virtual bool destroy() {
        semaphore_t* sem = 0;
        if ((sem = this->detach())) {
            int err = 0;
            if (!(err = sem_destroy(sem))) {
                return true;
            } else {
                XOS_LOG_ERROR("failed " << errno << " on sem_destroy()");
            }
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool acquire() {
        semaphore_t* sem = 0;
        if ((sem = this->attached_to())) {
            int err = 0;
            XOS_LOG_TRACE("wait on sem_wait()...");
            if (!(err = sem_wait(sem))) {
                XOS_LOG_TRACE("...waited on sem_wait()");
                return true;
            } else {
                XOS_LOG_ERROR("...failed " << errno << " on sem_wait()");
            }
        }
        return false;
    }
    virtual wait_status try_acquire() {
        semaphore_t* sem = 0;
        if ((sem = this->attached_to())) {
            int err = 0;
            XOS_LOG_TRACE("wait on sem_trywait()...");
            if (!(err = sem_trywait(sem))) {
                XOS_LOG_TRACE("...waited on sem_trywait()");
                return wait_success;
            } else {
                if (EAGAIN == (errno)) {
                    XOS_LOG_TRACE("...EAGAIN on sem_trywait()");
                    return wait_busy;
                } else {
                    if (EINTR == (errno)) {
                        XOS_LOG_ERROR("...EINTR on sem_trywait()");
                        return wait_interrupted;
                    } else {
                        XOS_LOG_ERROR("...failed " << errno << " on sem_trywait()");
                    }
                }
            }
        }
        return wait_failed;
    }
    virtual wait_status timed_acquire(mseconds_t milliseconds) {
        semaphore_t* sem = 0;
        if ((sem = this->attached_to())) {
            int err = 0;
            if (0 < (milliseconds)) {
#if defined(SEM_HAS_TIMEDWAIT)
                struct timespec until_time;
                clock_gettime(CLOCK_REALTIME, &until_time);
                until_time.tv_sec += milliseconds/1000;
                until_time.tv_nsec += (milliseconds%1000)*1000;
                XOS_LOG_TRACE("wait on sem_timedwait()...");
                if (!(err = sem_timedwait(sem, &until_time))) {
                    XOS_LOG_TRACE("...waited on sem_timedwait()");
                    return wait_success;
                } else {
                    if (ETIMEDOUT == (errno)) {
                        XOS_LOG_TRACE("...ETIMEDOUT on sem_timedwait()");
                        return wait_busy;
                    } else {
                        if (EINTR == (errno)) {
                            XOS_LOG_TRACE("...EINTR on sem_timedwait()");
                            return wait_interrupted;
                        } else {
                            XOS_LOG_TRACE("...failed " << errno << " on sem_timedwait()");
                        }
                    }
                }
#else // defined(SEM_HAS_TIMEDWAIT)
                return wait_invalid;
#endif // defined(SEM_HAS_TIMEDWAIT)
            } else {
                if (0 > (milliseconds)) {
                    XOS_LOG_TRACE("wait on sem_wait()...");
                    if (!(err = sem_wait(sem))) {
                        XOS_LOG_TRACE("...waited on sem_wait()");
                        return wait_success;
                    } else {
                        if (EINTR == (errno)) {
                            XOS_LOG_ERROR("...EINTR on sem_wait()");
                            return wait_interrupted;
                        } else {
                            XOS_LOG_ERROR("...failed " << errno << " on sem_trywait()");
                        }
                    }
                } else {
                    XOS_LOG_TRACE("wait on sem_trywait()...");
                    if (!(err = sem_trywait(sem))) {
                        XOS_LOG_TRACE("...waited on sem_trywait()");
                        return wait_success;
                    } else {
                        if (EAGAIN == (errno)) {
                            XOS_LOG_TRACE("...EAGAIN on sem_trywait()");
                            return wait_busy;
                        } else {
                            if (EINTR == (errno)) {
                                XOS_LOG_ERROR("...EINTR on sem_trywait()");
                                return wait_interrupted;
                            } else {
                                XOS_LOG_ERROR("...failed " << errno << " on sem_trywait()");
                            }
                        }
                    }
                }
            }
        }
        return wait_failed;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool release() {
        semaphore_t* sem = 0;
        if ((sem = this->attached_to())) {
            int err = 0;
            if (!(err = sem_post(sem))) {
                return true;
            } else {
                XOS_LOG_ERROR("failed " << errno << " on sem_post()");
            }
        }
        return false;
    }
    virtual ssize_t release(size_t amount) {
        return -1;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    semaphore_t sem_;
};
typedef semaphoret<> semaphore;

} // namespace unix 
} // namespace mt 
} // namespace xos 

#endif // _XOS_NADIR_XOS_MT_UNIX_SEMAPHORE_HPP 
