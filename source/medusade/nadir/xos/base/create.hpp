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
///   File: create.hpp
///
/// Author: $author$
///   Date: 1/8/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_BASE_CREATE_HPP
#define _XOS_NADIR_BASE_CREATE_HPP

#include "xos/base/exception.hpp"

namespace xos {
namespace base {

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
enum create_status {
    destroy_success,
    create_success = destroy_success,

    create_failed,
    destroy_failed
};

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
inline const char* create_status_to_chars(create_status status) {
    switch (status) {
    case create_success: return "create_success";
    case create_failed: return "create_failed";
    case destroy_failed: return "destroy_failed";
    }
    return "unknown";
}

typedef exceptiont_implements create_exception_implements;
typedef exceptiont<create_status> create_exception_extends;
///////////////////////////////////////////////////////////////////////
///  Class: create_exceptiont
///////////////////////////////////////////////////////////////////////
template
<class TImplements = create_exception_implements,
 class TExtends = create_exception_extends>

class _EXPORT_CLASS create_exceptiont: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    create_exceptiont(create_status status): Extends(status) {}
    virtual ~create_exceptiont() {}
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char* status_to_chars() const {
        return create_status_to_chars(this->status());
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef create_exceptiont<> create_exception;

} // namespace base 
} // namespace xos 

#endif // _XOS_NADIR_BASE_CREATE_HPP 
