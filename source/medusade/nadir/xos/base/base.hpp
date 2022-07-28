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
///   File: base.hpp
///
/// Author: $author$
///   Date: 8/12/2014, 2/20/2021
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_BASE_BASE_HPP
#define _XOS_NADIR_XOS_BASE_BASE_HPP

#include "xos/base/platform.hpp"

#define XOS_BASE_2STRINGX(value) "" #value ""
#define XOS_BASE_2STRING(value) XOS_BASE_2STRINGX(value)

namespace xos {
namespace base {

///////////////////////////////////////////////////////////////////////
///  Class: implement_base
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS implement_base {
public:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ~implement_base() {}
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

///////////////////////////////////////////////////////////////////////
///  Class: base
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS base: virtual public implement_base {
public:
    typedef implement_base Implements;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    base() {}
    virtual ~base() {}
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace base 

///////////////////////////////////////////////////////////////////////
/// class implementt
///////////////////////////////////////////////////////////////////////
template <class TImplements = base::implement_base>
class exported implementt: virtual public TImplements {
public:
    typedef TImplements implements;
    typedef implementt derives; 
    
    /// constructors / destructor
    virtual ~implementt() {
    }
}; /// class implementt
typedef implementt<> implement;

///////////////////////////////////////////////////////////////////////
/// class extendt
///////////////////////////////////////////////////////////////////////
template <class TExtends = base::base, class TImplements = implement>
class exported extendt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef extendt derives; 
    
    /// constructors / destructor
    extendt(const extendt& copy) {
    }
    extendt() {
    }
    virtual ~extendt() {
    }
}; /// class extendt
typedef extendt<> extend;

///
/// mseconds_ seconds / mseconds / useconds / nseconds
/// 
inline seconds_t mseconds_seconds
(mseconds_t mseconds) { return mseconds / 1000; }

inline mseconds_t mseconds_mseconds
(mseconds_t mseconds) { return mseconds % 1000; }

inline useconds_t mseconds_useconds
(mseconds_t mseconds) { return mseconds_mseconds(mseconds) * 1000; }

inline nseconds_t mseconds_nseconds
(mseconds_t mseconds) { return mseconds_useconds(mseconds) * 1000; }

} // namespace xos 

#endif // _XOS_NADIR_XOS_BASE_BASE_HPP
