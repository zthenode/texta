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
///   Date: 4/8/2015
///////////////////////////////////////////////////////////////////////
#ifndef _CORAL_BASE_STRING_HPP
#define _CORAL_BASE_STRING_HPP

#include "coral/base/types.hpp"
#include "xos/base/string.hpp"
#include "xos/base/string_base.hpp"

namespace coral {

typedef xos::base::string_implements string_implements;
typedef xos::base::string_extends string_extends;
typedef xos::base::tstring_extends tstring_extends;
typedef xos::base::wstring_extends wstring_extends;
///////////////////////////////////////////////////////////////////////
///  Class: stringt
///////////////////////////////////////////////////////////////////////
#if defined(USE_CPP_11)
template
<typename TChar = char, typename TEnd = TChar, TEnd VEnd = 0,
 class TExtends = std::basic_string<TChar>,
 class TImplements = string_implements>

using stringt = typename xos::base::stringt
<TChar, TEnd, VEnd, TExtends, TImplements>;
#else // defined(USE_CPP_11)
#endif // defined(USE_CPP_11)

typedef xos::base::string string_t;
typedef xos::base::tstring tstring_t;
typedef xos::base::wstring wstring_t;

typedef xos::base::string_base_implements string_base_implements;
typedef xos::base::string_base_extends string_base_extends;
///////////////////////////////////////////////////////////////////////
///  Class: string_base
///////////////////////////////////////////////////////////////////////
#if defined(USE_CPP_11)
template
<typename TChar = char, typename TSize = size_t,
 TSize VSize = XOS_BASE_STRING_BASE_DEFAULT_SIZE,
 typename TEnd = TChar, TEnd VEnd = 0,
 class TExtends = string_base_extends,
 class TImplements = string_base_implements>

using string_baset = typename xos::base::string_baset
<TChar, TSize, VSize, TEnd, VEnd, TExtends, TImplements>;
#else // defined(USE_CPP_11)
#endif // defined(USE_CPP_11)

typedef xos::base::string_base string_base_t;
typedef xos::base::tstring_base tstring_base_t;
typedef xos::base::wstring_base wstring_base_t;

} // namespace coral

#endif // _CORAL_BASE_STRING_HPP 
