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
///   File: string.hpp
///
/// Author: $author$
///   Date: 12/20/2018
///////////////////////////////////////////////////////////////////////
#ifndef _CORAL_NADIR_BASE_STRING_HPP
#define _CORAL_NADIR_BASE_STRING_HPP

#include "coral/nadir/base/types.hpp"
#include "nadir/base/string_base.hpp"
#include "nadir/base/string.hpp"
#include "nadir/base/to_string.hpp"

namespace coral {

typedef ::nadir::string_base string_base;
typedef ::nadir::tstring_base tstring_base;
typedef ::nadir::wstring_base wstring_base;

typedef ::nadir::char_string string;
typedef ::nadir::tchar_string tstring;
typedef ::nadir::wchar_string wstring;

typedef ::nadir::chars_to_string chars_to_string;
typedef ::nadir::chars_to_tstring chars_to_tstring;
typedef ::nadir::chars_to_wstring chars_to_wstring;

} /// namespace coral

#endif /// ndef _CORAL_NADIR_BASE_STRING_HPP
