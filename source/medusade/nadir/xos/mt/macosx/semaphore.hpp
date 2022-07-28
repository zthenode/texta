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
#ifndef _XOS_NADIR_XOS_MT_MACOSX_SEMAPHORE_HPP
#define _XOS_NADIR_XOS_MT_MACOSX_SEMAPHORE_HPP

#include "xos/mt/semaphore.hpp"
#include "xos/mt/acquirer.hpp"
#include "xos/mt/waiter.hpp"
#include "xos/base/created.hpp"
#include "xos/base/creator.hpp"
#include "xos/base/attached.hpp"
#include "xos/base/attacher.hpp"
#include "xos/io/logger.hpp"

#include <mach/task.h>
#include <mach/mach.h>
#include <mach/semaphore.h>

namespace xos {
namespace mt {
namespace macosx {

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
    using Implements::create;
    virtual bool create(size_t initial_count) {
        if ((this->destroyed())) {
            task_t task = mach_task_self();
            sync_policy_t sync_policy = SYNC_POLICY_FIFO;
            int err = 0;
            if ((KERN_SUCCESS == (err = semaphore_create(task, &sem_, sync_policy, initial_count)))) {
                this->attach_created(&sem_);
                return true;
            } else {
                XOS_LOG_ERROR("failed " << err << " on semaphore_create()");
            }
        }
        return false;
    }
    virtual bool destroy() {
        semaphore_t* sem = 0;
        if ((sem = this->detach())) {
            task_t task = mach_task_self();
            int err = 0;
            if (KERN_SUCCESS == (err = semaphore_destroy(task, *sem))) {
                return true;
            } else {
                XOS_LOG_ERROR("failed " << err << " on semaphore_destroy()");
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
            XOS_LOG_TRACE("wait on semaphore_wait()...");
            if (KERN_SUCCESS == (err = semaphore_wait(*sem))) {
                XOS_LOG_TRACE("...waited on semaphore_wait()");
                return true;
            } else {
                XOS_LOG_ERROR("...failed " << err << " on semaphore_wait()");
            }
        }
        return false;
    }
    virtual wait_status try_acquire() {
        return this->timed_acquire(0);
    }
    virtual wait_status timed_acquire(mseconds_t milliseconds) {
        semaphore_t* sem = 0;
        if ((sem = this->attached_to())) {
            int err = 0;
            if (0 <= (milliseconds)) {
                mach_timespec_t wait_time;
                wait_time.tv_sec = milliseconds/1000;
                wait_time.tv_nsec = (milliseconds%1000)*1000;
                XOS_LOG_TRACE("wait on semaphore_timedwait()...");
                if (KERN_SUCCESS == (err = semaphore_timedwait(*sem, wait_time))) {
                    XOS_LOG_TRACE("...waited on semaphore_timedwait()");
                    return wait_success;
                } else {
                    if (KERN_OPERATION_TIMED_OUT == (err)) {
                        XOS_LOG_TRACE("...KERN_OPERATION_TIMED_OUT on semaphore_timedwait()");
                        return wait_busy;
                    } else {
                        if (KERN_ABORTED == (err)) {
                            XOS_LOG_TRACE("...KERN_ABORTED on semaphore_timedwait()");
                            return wait_interrupted;
                        } else {
                            XOS_LOG_TRACE("...failed " << err << " on semaphore_timedwait()");
                        }
                    }
                }
            } else {
                XOS_LOG_TRACE("wait on semaphore_wait()...");
                if (KERN_SUCCESS == (err = semaphore_wait(*sem))) {
                    XOS_LOG_TRACE("...waited on semaphore_wait()");
                    return wait_success;
                } else {
                    XOS_LOG_ERROR("...failed " << err << " on semaphore_wait()");
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
            if (KERN_SUCCESS == (err = semaphore_signal(*sem))) {
                return true;
            } else {
                XOS_LOG_ERROR("failed " << err << " on semaphore_signal()");
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

} // namespace macosx 
} // namespace mt 
} // namespace xos 

#endif // _XOS_NADIR_XOS_MT_MACOSX_SEMAPHORE_HPP 
