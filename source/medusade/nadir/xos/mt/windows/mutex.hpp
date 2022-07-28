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
///   File: mutex.hpp
///
/// Author: $author$
///   Date: 2/22/2015
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_MT_WINDOWS_MUTEX_HPP
#define _XOS_NADIR_XOS_MT_WINDOWS_MUTEX_HPP

#include "xos/mt/mutex.hpp"
#include "xos/base/created.hpp"
#include "xos/base/creator.hpp"
#include "xos/base/attached.hpp"
#include "xos/base/attacher.hpp"
#include "xos/io/logger.hpp"

namespace xos {
namespace mt {
namespace windows {

typedef HANDLE mutex_attached_t;

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
            xos::base::creator_exception e = xos::base::failed_to_create;
            throw (e);
        }
    }
    mutext(mutext& copy)
    : Extends(copy.attached_to()), is_logging_(copy.is_logging()) {
    }
    virtual ~mutext() {
        if (!(this->destroyed())) {
            xos::base::creator_exception e = xos::base::failed_to_destroy;
            throw (e);
        }
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool create() {
        if ((this->destroyed())) {
            LPSECURITY_ATTRIBUTES lpMutexAttributes = NULL;
            BOOL bInitialOwner = FALSE;
            LPCTSTR lpName = NULL;
            mutex_attached_t detached = 0;
            if ((detached = CreateMutex(lpMutexAttributes, bInitialOwner, lpName))) {
                this->attach_created(detached);
                return true;
            } else {
                if ((this->is_logging())) {
                    XOS_LOG_ERROR("failed " << GetLastError() << " on CreateMutex()");
                }
            }
        }
        return false;
    }
    virtual bool destroy() {
        mutex_attached_t detached = 0;
        if ((detached = this->detach())) {
            if ((CloseHandle(detached))) {
                return true;
            } else {
                if ((this->is_logging())) {
                    XOS_LOG_ERROR("failed " << GetLastError() << " on CloseHandle()");
                }
            }
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool unlock() {
        mutex_attached_t detached = 0;
        if ((detached = this->attached_to())) {
            if ((ReleaseMutex(detached))) {
                return true;
            } else {
                if ((this->is_logging())) {
                    XOS_LOG_ERROR("failed " << GetLastError() << " on ReleaseMutex()");
                }
            }
        }
        return false;
    }
    virtual bool lock() {
        mutex_attached_t detached = 0;
        if ((detached = this->attached_to())) {
            DWORD dwMilliseconds = INFINITE;
            DWORD dwResult = 0;
            if (!(WAIT_OBJECT_0 != (dwResult = WaitForSingleObject(detached, dwMilliseconds)))) {
                return true;
            } else {
                if ((this->is_logging())) {
                    XOS_LOG_ERROR("failed " << GetLastError() << " on WaitForSingleObject()");
                }
            }
        }
        return false;
    }
    virtual wait_status try_lock() {
        return timed_lock(0);
    }
    virtual wait_status timed_lock(mseconds_t milliseconds) {
        mutex_attached_t detached = 0;
        if ((detached = this->attached_to())) {
            DWORD dwMilliseconds = (DWORD)(milliseconds);
            DWORD dwResult = 0;

            if ((this->is_logging())) {
                XOS_LOG_TRACE("WaitForSingleObject(..., " << milliseconds << ")...");
            }
            if (!(WAIT_OBJECT_0 != (dwResult = WaitForSingleObject(detached, dwMilliseconds)))) {
                if ((this->is_logging())) {
                    XOS_LOG_TRACE("..." << GetLastError() << "(WAIT_OBJECT_0 on WaitForSingleObject(..., " << milliseconds << ")");
                }
                return wait_success;
            } else {
                switch (dwResult) {
                case WAIT_TIMEOUT:
                    if ((this->is_logging())) {
                        XOS_LOG_TRACE("failed " << GetLastError() << "(WAIT_TIMEOUT) on WaitForSingleObject(..., " << milliseconds << ")");
                    }
                    return wait_busy;

                case WAIT_ABANDONED:
                    if ((this->is_logging())) {
                        XOS_LOG_ERROR("failed " << GetLastError() << "(WAIT_ABANDONED) on WaitForSingleObject(..., " << milliseconds << ")");
                    }
                    return wait_interrupted;

                default:
                    if ((this->is_logging())) {
                        XOS_LOG_ERROR("failed " << GetLastError() << " on WaitForSingleObject(..., " << milliseconds << ")");
                    }
                }
            }
        }
        return wait_failed;
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
};
typedef mutext<> mutex;

} // namespace windows 
} // namespace mt 
} // namespace xos 

#endif // _XOS_NADIR_XOS_MT_WINDOWS_MUTEX_HPP 
