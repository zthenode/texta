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
///   Date: 12/20/2018
///////////////////////////////////////////////////////////////////////
#ifndef _CORAL_NADIR_BASE_BASE_HPP
#define _CORAL_NADIR_BASE_BASE_HPP

#include "nadir/base/base.hpp"

#if defined(CPP_11)
#if !defined(NO_USE_CPP_11)
#if !defined(USE_CPP_11)
#define USE_CPP_11
#endif // !defined(USE_CPP_11)
#endif // !defined(NO_USE_CPP_11)
#endif // defined(CPP_11)

namespace coral {

typedef ::nadir::implement_base implement_base;
typedef ::nadir::base base;

typedef ::nadir::pointer_t pointer_t;
typedef ::nadir::unsigned_t unsigned_t;
typedef ::nadir::signed_t signed_t;

inline const pointer_t& to_pointer(const pointer_t& v) { return v; }
inline const unsigned_t& to_unsigned(const unsigned_t& v) { return v; }
inline const signed_t& to_signed(const signed_t& v) { return v; }
inline const wchar_t& to_wchar(const wchar_t& v) { return v; }
inline const tchar_t& to_tchar(const tchar_t& v) { return v; }
inline const char& to_char(const char& v) { return v; }
inline const bool& to_bool(const bool& v) { return v; }

} /// namespace coral

#endif /// ndef _CORAL_NADIR_BASE_BASE_HPP
