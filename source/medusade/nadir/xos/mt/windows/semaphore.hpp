///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2015 $organization$
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
///   Date: 3/1/2015
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_MT_WINDOWS_SEMAPHORE_HPP
#define _XOS_NADIR_XOS_MT_WINDOWS_SEMAPHORE_HPP

#include "xos/mt/semaphore.hpp"
#include "xos/mt/acquirer.hpp"
#include "xos/mt/waiter.hpp"
#include "xos/base/created.hpp"
#include "xos/base/creator.hpp"
#include "xos/base/attached.hpp"
#include "xos/base/attacher.hpp"
#include "xos/io/logger.hpp"

namespace xos {
namespace mt {
namespace windows {

typedef HANDLE semaphore_attached_t;

typedef base::creatort<mt::semaphore> semaphore_creator;
typedef base::attachert<semaphore_attached_t, int, 0, semaphore_creator> semaphore_attacher;
typedef base::attachedt<semaphore_attached_t, int, 0, semaphore_attacher, base::base> semaphore_attached;
typedef base::createdt<semaphore_attached_t, int, 0, semaphore_attacher, semaphore_attached> semaphore_created;
typedef semaphore_attacher semaphore_implements;
typedef semaphore_created semaphore_extends;
///////////////////////////////////////////////////////////////////////
///  Class: semaphoret
///////////////////////////////////////////////////////////////////////
template
<class TImplements=semaphore_implements, class TExtends=semaphore_extends>

class _EXPORT_CLASS semaphoret: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef semaphore_attached_t attached_t;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    semaphoret(attached_t attached, bool is_created = false)
    : Extends(attached, is_created) {
    }
    semaphoret() {
        if ((this->initially_created())) {
            if (!(this->create())) {
                xos::base::creator_exception e = xos::base::failed_to_create;
                XOS_LOG_ERROR("...throwing exception failed_to_create");
                throw (e);
            }
        }
    }
    semaphoret(semaphoret& copy): Extends(copy.attached_to()) {
    }
    virtual ~semaphoret() {
        if (!(this->destroyed())) {
            xos::base::creator_exception e = xos::base::failed_to_destroy;
            XOS_LOG_ERROR("...throwing exception failed_to_destroy");
            throw (e);
        }
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool create() {
        return this->create(0, -1);
    }
    virtual bool create(size_t initial_count) {
        return this->create(initial_count, -1);
    }
    virtual bool create(size_t initial_count, ssize_t maximum_count) {
        if ((this->destroyed())) {
            LONG lInitialCount = (LONG)(initial_count);
            LONG lMaximumCount =(LONG)((0 > maximum_count)?(((ULONG)(-1))>>1):(maximum_count));
            LPSECURITY_ATTRIBUTES lpSecurityAttributes = 0;
            LPCTSTR lpName = 0;
            attached_t detached = 0;

            XOS_LOG_DEBUG("CreateSemaphore()...");
            if ((detached = CreateSemaphore
                (lpSecurityAttributes, lInitialCount, lMaximumCount, lpName))) {
                XOS_LOG_DEBUG("...CreateSemaphore()");
                this->attach_created(detached);
                return true;
            } else {
                XOS_LOG_ERROR("failed " << GetLastError() << " on CreateSemaphore()");
            }
        }
        return false;
    }
    virtual bool destroy() {
        attached_t detached = 0;
        if ((detached = this->detach())) {
            XOS_LOG_DEBUG("CloseHandle()...");
            if ((CloseHandle(detached))) {
                XOS_LOG_DEBUG("...CloseHandle()");
                return true;
            } else {
                XOS_LOG_ERROR("failed " << GetLastError() << " on CloseHandle()");
            }
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool acquire() {
        if (wait_success == (timed_acquire(-1))) {
            return true;
        }
        return false;
    }
    virtual wait_status try_acquire() {
        return timed_acquire(0);
    }
    virtual wait_status timed_acquire(mseconds_t milliseconds) {
        attached_t detached = 0;
        if ((detached = this->attached_to())) {
            DWORD dwMilliSeconds = (DWORD)((0 > milliseconds)?(INFINITE):(milliseconds));
            DWORD dwResult = 0;

            XOS_LOG_TRACE("WaitForSingleObject(..., " << milliseconds << ")...");
            if (WAIT_OBJECT_0 == (dwResult = WaitForSingleObject(detached, dwMilliSeconds))) {
                XOS_LOG_TRACE("..." << GetLastError() << "(WAIT_OBJECT_0) on WaitForSingleObject(..., " << milliseconds << ")");
                return wait_success;
            } else {
                switch(dwResult) {
                case WAIT_TIMEOUT:
                    XOS_LOG_TRACE("failed " << GetLastError() << "(WAIT_TIMEOUT) on WaitForSingleObject(..., " << milliseconds << ")");
                    return wait_busy;
                    break;

                case WAIT_ABANDONED:
                    XOS_LOG_ERROR("failed " << GetLastError() << "(WAIT_ABANDONED) on WaitForSingleObject(..., " << milliseconds << ")");
                    return wait_interrupted;
                    break;

                default:
                    XOS_LOG_ERROR("failed " << GetLastError() << " on WaitForSingleObject(..., " << milliseconds << ")");
                    break;
                }
            }
        }
        return wait_failed;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool release() {
        return release(1);
    }
    virtual ssize_t release(size_t amount) {
        attached_t detached = 0;
        if ((detached = this->attached_to())) {
            LONG lReleaseCount = (LONG)(amount);
            LONG lPreviousCount = 0;

            XOS_LOG_DEBUG("ReleaseSemaphore(" << lReleaseCount << ", ...)...");
            if ((ReleaseSemaphore(detached, lReleaseCount, &lPreviousCount))) {
                XOS_LOG_DEBUG("...ReleaseSemaphore(" << lReleaseCount << ", ...)");
                return (ssize_t)(lPreviousCount - lReleaseCount);
            } else {
                XOS_LOG_ERROR("failed " << GetLastError() << " on ReleaseSemaphore(" << lReleaseCount << ", ...)");
            }
        }
        return -1;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef semaphoret<> semaphore;

} // namespace windows 
} // namespace mt 
} // namespace xos 

#endif // _XOS_NADIR_XOS_MT_WINDOWS_SEMAPHORE_HPP 
