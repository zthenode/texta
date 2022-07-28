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
///   File: logged.hpp
///
/// Author: $author$
///   Date: 5/11/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_BASE_LOGGED_HPP
#define _XOS_NADIR_XOS_BASE_LOGGED_HPP

#include "xos/base/base.hpp"

namespace xos {
namespace base {

typedef implement_base logged_implementt_implements;
///////////////////////////////////////////////////////////////////////
///  Class: logged_implementt
///////////////////////////////////////////////////////////////////////
template <class TImplements = logged_implementt_implements>
class _EXPORT_CLASS logged_implementt: virtual public TImplements {
public:
    typedef TImplements Implements;
};
typedef logged_implementt<> logged_implement;

typedef logged_implement loggedt_implements;
typedef base loggedt_extends;
///////////////////////////////////////////////////////////////////////
///  Class: loggedt
///////////////////////////////////////////////////////////////////////
template <class TImplements = loggedt_implements, class TExtends = loggedt_extends>
class _EXPORT_CLASS loggedt: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef loggedt Derives;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    loggedt(bool  is_logging): is_logging_(is_logging) {
    }
    loggedt(const loggedt &copy): is_logging_(copy.is_logging()) {
    }
    loggedt(): is_logging_(true) {
    }
    virtual ~loggedt() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool set_is_logging(bool to = true) {
        is_logging_ = to;
        return is_logging_;
    }
    virtual bool is_logging() const {
        return is_logging_;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    bool is_logging_;
};
typedef loggedt<> logged;

} // namespace base
} // namespace xos

#endif // _XOS_NADIR_XOS_BASE_LOGGED_HPP 
