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
///   File: control.hpp
///
/// Author: $author$
///   Date: 3/2/2015
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_MT_WINDOWS_SERVICE_CONTROL_HPP
#define _XOS_NADIR_XOS_MT_WINDOWS_SERVICE_CONTROL_HPP

#include "xos/mt/windows/service/handle.hpp"

namespace xos {
namespace mt {
namespace windows {
namespace service {

typedef handle_implements control_implements;
typedef handle control_extends;
///////////////////////////////////////////////////////////////////////
///  Class: controlt
///////////////////////////////////////////////////////////////////////
template
<class TImplements=control_implements, class TExtends=control_extends>

class _EXPORT_CLASS controlt: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef handle_attached_t attached_t;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    controlt(attached_t attached = 0, bool is_open = false)
    : Extends(attached, is_open) {
    }
    controlt(const controlt& copy): Extends(copy.attached_to()) {
    }
    virtual ~controlt() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef controlt<> control;

} // namespace service 
} // namespace windows 
} // namespace mt 
} // namespace xos 

#endif // _XOS_NADIR_XOS_MT_WINDOWS_SERVICE_CONTROL_HPP 
