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
///   File: base.hpp
///
/// Author: $author$
///   Date: 3/4/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_FRAMEWORK_BASE_BASE_HPP
#define _XOS_NADIR_XOS_FRAMEWORK_BASE_BASE_HPP

#include "xos/base/base.hpp"
#include "xos/base/attached.hpp"
#include "xos/base/created.hpp"
#include "xos/base/opened.hpp"
#include "xos/base/array.hpp"
#include "xos/base/string.hpp"
#include "xos/base/to_string.hpp"

#if defined(_NAMESPACE)
namespace _NAMESPACE {
#endif // defined(_NAMESPACE) 

typedef ::xos::base::implement_base implement_base;
typedef ::xos::base::base base;

typedef ::xos::base::attacher_exception attacher_exception;
static const attacher_exception failed_to_attach = ::xos::base::failed_to_attach;
static const attacher_exception failed_to_detach = ::xos::base::failed_to_detach;

typedef ::xos::base::creator_exception creator_exception;
static const creator_exception failed_to_create = ::xos::base::failed_to_create;
static const creator_exception failed_to_destroy = ::xos::base::failed_to_destroy;

typedef ::xos::base::opener_exception opener_exception;
static const opener_exception failed_to_open = ::xos::base::failed_to_open;
static const opener_exception failed_to_close = ::xos::base::failed_to_close;

///////////////////////////////////////////////////////////////////////
///  Class: arrayt
///////////////////////////////////////////////////////////////////////
#if defined(USE_CPP_11)
template
<typename TWhat = char, 
 typename TSize = size_t, TSize VSize = XOS_ARRAY_DEFAULT_SIZE,
 class TExtends = ::xos::base::array_extends, 
 class TImplements = ::xos::base::array_implements>

using arrayt = typename ::xos::base::arrayt
<TWhat, TSize, VSize, TExtends, TImplements>;
#else // defined(USE_CPP_11)
template
<typename TWhat = char, 
 typename TSize = size_t, TSize VSize = XOS_ARRAY_DEFAULT_SIZE,
 class TExtend = ::xos::base::arrayt
 <TWhat, TSize, VSize, ::xos::base::array_implements>, 
 class TImplements = ::xos::base::array_implementt
 <TWhat, TSize, VSize, ::xos::base::array_implements>,
 class TExtends = ::xos::base::arrayt<TWhat, TSize, VSize, TExtend, TImplements> >

class _EXPORT_CLASS arrayt: virtual public TImplements,public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef TWhat what_t;
    typedef TSize size_t;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    arrayt(ssize_t length): Extends(length) {}
    arrayt(const arrayt& copy): Extends(copy) {}
    arrayt() {}
    virtual ~arrayt() {
        this->clear();
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
#endif // defined(USE_CPP_11)
typedef ::xos::base::byte_array byte_array;
typedef ::xos::base::char_array char_array;
typedef ::xos::base::wchar_array wchar_array;
typedef ::xos::base::tchar_array tchar_array;

///////////////////////////////////////////////////////////////////////
///  Class: stringt
///////////////////////////////////////////////////////////////////////
#if defined(USE_CPP_11)
template
<typename TChar = char, 
 typename TEnd = TChar, TEnd VEnd = 0,
 class TExtends = ::std::basic_string<TChar>, 
 class TImplements = ::xos::base::string_implementt<TChar, TEnd, VEnd> >

using stringt = typename ::xos::base::stringt
<TChar, TEnd, VEnd, TExtends, TImplements>;
#else // defined(USE_CPP_11)
template
<typename TChar = char, 
 typename TEnd = TChar, TEnd VEnd = 0,
 class TExtend = ::std::basic_string<TChar>, 
 class TImplements = ::xos::base::string_implementt<TChar, TEnd, VEnd>,
 class TExtends = ::xos::base::stringt<TChar, TEnd, VEnd, TExtend, TImplements> >

class _EXPORT_CLASS stringt: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef TChar char_t;
    typedef TEnd end_char_t;
    enum { end_char = VEnd };
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    stringt(const char_t* chars, size_t length): Extends(chars, length) {}
    stringt(const char_t* chars): Extends(chars) {}
    stringt(const stringt& copy): Extends(copy) {}
    stringt() {}
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
#endif // defined(USE_CPP_11)
typedef ::xos::base::string string_t, char_string_t;
typedef ::xos::base::tstring tstring_t, tchar_string_t;
typedef ::xos::base::wstring wstring_t, wchar_string_t;

typedef ::xos::base::unsigned_to_string unsigned_to_string;
typedef ::xos::base::signed_to_string signed_to_string;
typedef ::xos::base::pointer_to_string pointer_to_string;
typedef ::xos::base::bool_to_string bool_to_string;
typedef ::xos::base::char_to_string char_to_string;
typedef ::xos::base::x_to_string x_to_string;

#if defined(_NAMESPACE)
}
#endif // defined(_NAMESPACE) 

#endif // _XOS_NADIR_XOS_FRAMEWORK_BASE_BASE_HPP 
