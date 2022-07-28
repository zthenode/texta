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
///   File: open.hpp
///
/// Author: $author$
///   Date: 1/8/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_BASE_OPEN_HPP
#define _XOS_NADIR_BASE_OPEN_HPP

#include "xos/base/exception.hpp"

namespace xos {
namespace base {

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
enum open_status {
    close_success,
    open_success = close_success,

    open_failed,
    close_failed
};

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
inline const char* open_status_to_chars(open_status status) {
    switch (status) {
    case open_success: return "open_success";
    case open_failed: return "open_failed";
    case close_failed: return "close_failed";
    }
    return "unknown";
}

typedef exceptiont_implements open_exception_implements;
typedef exceptiont<open_status> open_exception_extends;
///////////////////////////////////////////////////////////////////////
///  Class: open_exceptiont
///////////////////////////////////////////////////////////////////////
template
<class TImplements = open_exception_implements,
 class TExtends = open_exception_extends>

class _EXPORT_CLASS open_exceptiont: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    open_exceptiont(open_status status): Extends(status) {}
    virtual ~open_exceptiont() {}
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char* status_to_chars() const {
        return open_status_to_chars(this->status());
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef open_exceptiont<> open_exception;

} // namespace base 
} // namespace xos 

#endif // _XOS_NADIR_BASE_OPEN_HPP 
