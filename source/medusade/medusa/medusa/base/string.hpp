///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2015 $organization$
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
///   File: string.hpp
///
/// Author: $author$
///   Date: 4/9/2015
///////////////////////////////////////////////////////////////////////
#ifndef _MEDUSA_BASE_STRING_HPP
#define _MEDUSA_BASE_STRING_HPP

#include "medusa/base/array.hpp"
#include "xos/base/to_string.hpp"
#include "xos/base/string.hpp"

namespace medusa {

typedef xos::base::string_implements string_implements;
typedef xos::base::string string_extends;
///////////////////////////////////////////////////////////////////////
///  Class: stringt
///////////////////////////////////////////////////////////////////////
#if defined(USE_CPP_11)
template
<typename TChar = char, 
 typename TEnd = TChar, TEnd VEnd = 0,
 class TExtends = std::basic_string<TChar>, 
 class TImplements = string_implements>

using stringt = typename xos::base::stringt
<TChar, TEnd, VEnd, TExtends, TImplements>;
#else // defined(USE_CPP_11)
template
<typename TChar = char, 
 typename TEnd = TChar, TEnd VEnd = 0,
 class TExtend = std::basic_string<TChar>, class TImplements = string_implements,
 class TExtends = xos::base::stringt<TChar, TEnd, VEnd, TExtend, TImplements> >

class _EXPORT_CLASS stringt: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    
    typedef TChar char_t;
    typedef TEnd end_char_t;
    enum { end_char = VEnd };
    
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    stringt(const char_t* chars, size_t length): Extends(chars, length) {
    }
    stringt(const char_t* chars): Extends(chars) {
    }
    stringt(const stringt& copy): Extends(copy) {
    }
    stringt() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
#endif // defined(USE_CPP_11)

typedef string_implements string_t_implements;
typedef string_implements wstring_t_implements;
typedef string_implements tstring_t_implements;
typedef string_implements bstring_t_implements;

typedef xos::base::string string_t;
typedef xos::base::tstring tstring_t;
typedef xos::base::wstring wstring_t;
typedef xos::base::bstring bstring_t;

typedef xos::base::pointer_to_string pointer_to_string;

} // namespace medusa

#endif // _MEDUSA_BASE_STRING_HPP 
