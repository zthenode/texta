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
///   File: handle.hpp
///
/// Author: $author$
///   Date: 3/2/2015
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_MT_WINDOWS_SERVICE_HANDLE_HPP
#define _XOS_NADIR_XOS_MT_WINDOWS_SERVICE_HANDLE_HPP

#include "xos/base/base.hpp"
#include "xos/base/opened.hpp"
#include "xos/base/opener.hpp"
#include "xos/base/attached.hpp"
#include "xos/base/attacher.hpp"
#include "xos/io/logger.hpp"

namespace xos {
namespace mt {
namespace windows {
namespace service {

typedef SC_HANDLE handle_attached_t;

typedef base::attachert<handle_attached_t, int, 0, xos::base::opener> handle_attacher;
typedef base::attachedt<handle_attached_t, int, 0, handle_attacher, base::base> handle_attached;
typedef base::openedt<handle_attached_t, int, 0, handle_attacher, handle_attached> handle_opened;
typedef handle_attacher handle_implements;
typedef handle_opened handle_extends;
///////////////////////////////////////////////////////////////////////
///  Class: handlet
///////////////////////////////////////////////////////////////////////
template
<class TImplements = handle_implements, class TExtends = handle_extends>

class _EXPORT_CLASS handlet: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef handle_attached_t attached_t;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    handlet(attached_t attached = 0, bool is_open = false)
    : Extends(attached, is_open) {
    }
    handlet(const handlet& copy): Extends(copy.attached_to()) {
    }
    virtual ~handlet() {
        if (!(this->closed())) {
            xos::base::opener_exception e = xos::base::failed_to_close;
            XOS_LOG_ERROR("...throwing exception failed_to_close");
            throw (e);
        }
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool close() {
        attached_t detached = 0;
        if ((detached = this->detach())) {
            XOS_LOG_DEBUG("CloseServiceHandle()...");
            if ((CloseServiceHandle(detached))) {
                XOS_LOG_DEBUG("...CloseServiceHandle()");
                return true;
            } else {
                XOS_LOG_ERROR("failed " << GetLastError() << " on CloseServiceHandle()");
            }
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef handlet<> handle;

} // namespace service 
} // namespace windows 
} // namespace mt 
} // namespace xos 

#endif // _XOS_NADIR_XOS_MT_WINDOWS_SERVICE_HANDLE_HPP 
