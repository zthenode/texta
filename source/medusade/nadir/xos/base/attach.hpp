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
///   File: attach.hpp
///
/// Author: $author$
///   Date: 1/8/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_BASE_ATTACH_HPP
#define _XOS_BASE_ATTACH_HPP

#include "xos/base/exception.hpp"

namespace xos {
namespace base {

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
enum attach_status {
    detach_success,
    attach_success = detach_success,

    attach_failed,
    detach_failed
};

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
inline const char* attach_status_to_chars(attach_status status) {
    switch (status) {
    case attach_success: return "attach_success";
    case attach_failed: return "attach_failed";
    case detach_failed: return "detach_failed";
    }
    return "unknown";
}

typedef exceptiont_implements attach_exception_implements;
typedef exceptiont<attach_status> attach_exception_extends;
///////////////////////////////////////////////////////////////////////
///  Class: attach_exceptiont
///////////////////////////////////////////////////////////////////////
template
<class TImplements = attach_exception_implements,
 class TExtends = attach_exception_extends>

class _EXPORT_CLASS attach_exceptiont: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    attach_exceptiont(attach_status status): Extends(status) {}
    virtual ~attach_exceptiont() {}
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char* status_to_chars() const {
        return attach_status_to_chars(this->status());
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef attach_exceptiont<> attach_exception;

} // namespace base 
} // namespace xos 

#endif // _XOS_BASE_ATTACH_HPP 

        

