///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2014 $organization$
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
///   File: wrapped.hpp
///
/// Author: $author$
///   Date: 12/23/2014
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_BASE_WRAPPED_HPP
#define _XOS_NADIR_XOS_BASE_WRAPPED_HPP

#include "xos/base/base.hpp"

namespace xos {
namespace base {

typedef int wrapped_initalized_t;
enum { wrapped_initalized = 0 };
typedef base wrapped_extends;
typedef implement_base wrapped_implements;
///////////////////////////////////////////////////////////////////////
///  Class: wrappedt
///////////////////////////////////////////////////////////////////////
template
<typename TWrapped,
 typename TInitialized = wrapped_initalized_t,
 TInitialized VInitialized = wrapped_initalized,
 class TExtends = wrapped_extends, class TImplements = wrapped_implements>

class _EXPORT_CLASS wrappedt: virtual public TImplements,public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef TWrapped wrapped_t;
    typedef TInitialized initialized_t;
    enum { initialized = VInitialized };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    wrappedt(initialized_t initialized) {
        memset(&wrapped_, initialized, sizeof(wrapped_t));
    }
    wrappedt(const wrapped_t& copy) {
        memcpy(&wrapped_, &copy, sizeof(wrapped_t));
    }
    wrappedt(const wrappedt& copy) {
        memcpy(&wrapped_, &copy.wrapped_, sizeof(wrapped_t));
    }
    wrappedt() {
        memset(&wrapped_, initialized, sizeof(wrapped_t));
    }
    virtual ~wrappedt() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual wrappedt& copy(const wrappedt& copy) {
        memcpy(&wrapped_, &copy.wrapped_, sizeof(wrapped_t));
        return *this;
    }
    virtual wrappedt& copy(const wrapped_t& copy) {
        memcpy(&wrapped_, &copy, sizeof(wrapped_t));
        return *this;
    }
    virtual wrappedt& set(initialized_t initialized) {
        memset(&wrapped_, initialized, sizeof(wrapped_t));
        return *this;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual wrappedt& operator = (const wrappedt& copy) {
        memcpy(&wrapped_, &copy.wrapped_, sizeof(wrapped_t));
        return *this;
    }
    virtual wrappedt& wrapper() const {
        return (wrappedt&)(*this);
    }
    virtual wrapped_t& wrapped() const {
        return (wrapped_t&)(wrapped_);
    }
    virtual operator wrapped_t& () const {
        return (wrapped_t&)(wrapped_);
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    wrapped_t wrapped_;
};

typedef base wrapper_extends;
typedef implement_base wrapper_implements;
///////////////////////////////////////////////////////////////////////
///  Class: wrappert
///////////////////////////////////////////////////////////////////////
template
<typename TWrapped,
 class TExtends = wrapper_extends, class TImplements = wrapper_implements>

class _EXPORT_CLASS wrappert: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef TWrapped wrapped_t;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    wrappert(const wrappert& copy): wrapped_(copy.wrapped_) {
    }
    wrappert() {
    }
    virtual ~wrappert() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual wrappert& copy(const wrappert& copy) {
        wrapped_.copy(copy.wrapped_);
        return *this;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual wrappert& operator = (const wrappert& copy) {
        wrapped_.copy(copy.wrapped_);
        return *this;
    }
    virtual wrappert& wrapper() const {
        return (wrappert&)(*this);
    }
    virtual wrapped_t& wrapped() const {
        return (wrapped_t&)(wrapped_);
    }
    virtual operator wrapped_t& () const {
        return (wrapped_t&)(wrapped_);
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    wrapped_t wrapped_;
};

} // namespace base
} // namespace xos 

#endif // _XOS_NADIR_XOS_BASE_WRAPPED_HPP 
