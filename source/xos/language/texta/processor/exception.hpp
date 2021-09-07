///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2020 $organization$
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
///   Date: 4/14/2020
///////////////////////////////////////////////////////////////////////
#ifndef XOS_LANGUAGE_TEXTA_PROCESSOR_EXCEPTION_HPP
#define XOS_LANGUAGE_TEXTA_PROCESSOR_EXCEPTION_HPP

#include "xos/base/exception.hpp"

namespace xos {
namespace language {
namespace texta {
namespace processor {

/// enum exception_status
typedef xos::exception_status exception_status_t;
enum {
    exception_none = xos::exception_success,
    exception_failed = xos::exception_failed,
    exception_exit
}; /// enum exception_status

/// function exception_status_to_chars
inline const char* exception_status_to_chars(exception_status_t status) {
    switch(status) {
    case exception_none: return "exception_none";
    case exception_failed: return "exception_failed";
    case exception_exit: return "exception_exit";
    }
    return "unknown";
}

/// class exceptiont
template <class TExtends = xos::exceptiont<exception_status_t>, class TImplements = typename TExtends::implements>
class exported exceptiont: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef exceptiont derives;

    typedef typename extends::status_t status_t;

    /// constructor / destructor
    exceptiont(const exceptiont& copy): extends(copy) {
    }
    exceptiont(status_t status): extends(status) {
    }
    virtual ~exceptiont() {
    }

    /// ...status...
    virtual const char* status_to_chars() const {
        return exception_status_to_chars(this->status());
    }
}; /// class exceptiont
typedef exceptiont<> exception;

} /// namespace processor
} /// namespace texta
} /// namespace language
} /// namespace xos

#endif /// ndef XOS_LANGUAGE_TEXTA_PROCESSOR_EXCEPTION_HPP 
