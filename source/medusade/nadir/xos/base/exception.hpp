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
///   File: exception.hpp
///
/// Author: $author$
///   Date: 1/8/2018, 6/14/2021
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_BASE_EXCEPTION_HPP
#define _XOS_BASE_EXCEPTION_HPP

#include "xos/base/string.hpp"

namespace xos {

namespace base {
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
enum exception_status {
    exception_success,
    exception_failed,
    exception_unexpected
};

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
inline const char* exception_status_to_chars(exception_status status) {
    switch (status) {
    case exception_success: return "exception_success";
    case exception_failed: return "exception_failed";
    case exception_unexpected: return "exception_unexpected";
    }
    return "unknown";
}

typedef implement_base exceptiont_implements;
typedef base exceptiont_extends;
///////////////////////////////////////////////////////////////////////
///  Class: exceptiont
///////////////////////////////////////////////////////////////////////
template
<typename TStatus = exception_status,
 typename TChar = char, class TString = stringt<char>,
 class TImplements = exceptiont_implements, class TExtends = exceptiont_extends>

class _EXPORT_CLASS exceptiont: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef TStatus status_t;
    typedef TString string_t;
    typedef TChar char_t;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    exceptiont(status_t status): status_(status) {}
    virtual ~exceptiont() {}
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual status_t status() const { return status_; }
    virtual string_t status_to_string() const {
        string_t to(this->status_to_chars());
        return to;
    }
    virtual const char_t* status_to_chars() const {
        return exception_status_to_chars(((exception_status)this->status()));
    }
    virtual operator const char_t*() const {
        return this->status_to_chars();
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    status_t status_;
};
typedef exceptiont<> exception;
} // namespace base 

/// enum exception_status
typedef int exception_status;
enum {
    exception_success = base::exception_success,
    exception_failed  = base::exception_failed,
    exception_unexpected = base::exception_unexpected
}; /// enum exception_status

/// class exceptiont
template <class TExtends = base::exception, class TImplements = typename TExtends::Implements>
class exported exceptiont: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef exceptiont derives; 
    
    typedef typename extends::char_t char_t;
    typedef typename extends::string_t string_t;
    typedef typename extends::status_t status_t;
    typedef exception_status exception_status_t;
    
    /// constructors / destructor
    exceptiont(const exceptiont& copy): extends(copy.status_) {
    }
    exceptiont(exception_status_t status): extends((status_t)status) {
    }
    virtual ~exceptiont() {
    }
}; /// class exceptiont
typedef exceptiont<> exception;

} // namespace xos 

#endif // _XOS_BASE_EXCEPTION_HPP 
