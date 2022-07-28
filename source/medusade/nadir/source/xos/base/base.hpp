///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2021 $organization$
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
///   Date: 1/12/2021
///////////////////////////////////////////////////////////////////////
#ifndef XOS_BASE_BASE_HPP
#define XOS_BASE_BASE_HPP

#define _XOS_BASE_BASE_HPP
#define _XOS_NADIR_XOS_BASE_BASE_HPP

#include "xos/platform/configure.hpp"

#define XOS_BASE_2STRINGX(value) "" #value ""
#define XOS_BASE_2STRING(value) XOS_BASE_2STRINGX(value)

namespace xos {
namespace base {

///////////////////////////////////////////////////////////////////////
/// class implement_base
///////////////////////////////////////////////////////////////////////
class EXPORT_CLASS implement_base {
public:
    typedef implement_base Derives;

    ///////////////////////////////////////////////////////////////////////
    /// constructor / destructor
    ///////////////////////////////////////////////////////////////////////
    virtual ~implement_base() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
}; /// class implement_base

///////////////////////////////////////////////////////////////////////
/// class base
///////////////////////////////////////////////////////////////////////
class EXPORT_CLASS base: virtual public implement_base {
public:
    typedef implement_base Implements;
    typedef base Derives;

    ///////////////////////////////////////////////////////////////////////
    /// constructor / destructor
    ///////////////////////////////////////////////////////////////////////
    base(const base& copy) {
    }
    base() {
    }
    virtual ~base() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
}; /// class base

} /// namespace base

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

} /// namespace xos

#endif /// ndef XOS_BASE_BASE_HPP 
