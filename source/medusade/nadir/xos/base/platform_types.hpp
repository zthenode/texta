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
///   File: platform_types.hpp
///
/// Author: $author$
///   Date: 8/17/2014
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_BASE_PLATFORM_TYPES_HPP
#define _XOS_NADIR_XOS_BASE_PLATFORM_TYPES_HPP

#include "xos/base/platform_defines.hpp"

#if defined(WINDOWS)
//
// Windows
// ...
#if !defined(__GNUC__)
//
// Visual C++
// ...

//
// Visual C++ version specific definitions
//
#if defined(WINDOWS_MSC_VER_6)
//
// Visual C++ 6.0
//
typedef char INT8;
typedef short INT16;
typedef unsigned char UINT8;
typedef unsigned short UINT16;
#else // defined(WINDOWS_MSC_VER_6)
//
// Visual C++ 7.0 or greater
//
#endif // defined(WINDOWS_MSC_VER_6)

typedef BYTE byte_t;
typedef WORD word_t;

typedef TCHAR tchar_t;

typedef INT8 int8_t;
typedef INT16 int16_t;
typedef INT32 int32_t;
typedef INT64 int64_t;

typedef UINT8 uint8_t;
typedef UINT16 uint16_t;
typedef UINT32 uint32_t;
typedef UINT64 uint64_t;

typedef int MODE_T;
typedef MODE_T mode_t;

typedef SSIZE_T ssize_t;

typedef time_t useconds_t;

typedef UINT uint;
typedef USHORT ushort;
typedef ULONG ulong;
// ...
// Visual C++
//
#else // !defined(__GNUC__)
//
// Gcc
// ...
#if defined(CPLATFORM_DEFINED_DEBUG)
#warning Compiler other than Visual C++ (Gcc) being used
#endif // defined(CPLATFORM_DEFINED_DEBUG)

#if !defined(__MINGW32__)
// MinGWin
// ...
typedef char INT8;
typedef short INT16;
typedef unsigned char UINT8;
typedef unsigned short UINT16;
// ...
// MinGWin
#else // !defined(__MINGW32__)
#define PCCHAR PCCHAR_T
typedef int MODE_T;
#endif // !defined(__MINGW32__)

typedef TCHAR tchar_t;
// ...
// Gcc
//
#endif // !defined(__GNUC__)

typedef ULONGLONG QWORD;

typedef DWORD MODE;

typedef HANDLE INVALID_HANDLE_T;
typedef HANDLE NULL_HANDLE_T;

typedef ATOM INVALID_ATOM_T;
typedef ATOM NULL_ATOM_T;
// ...
// Windows
//
#else // defined(WINDOWS)
//
// Unix
// ...
#define TRUE 1
#define FALSE 0

#if defined(MACOSX)
typedef unsigned char uint8_t;
#if !defined(OBJC_BOOL_DEFINED)
typedef int BOOL;
#endif // !defined(OBJC_BOOL_DEFINED)
#else // defined(MACOSX)
typedef int BOOL;
#endif // defined(MACOSX)

typedef uint8_t byte_t;
typedef uint16_t word_t;

typedef char tchar_t;

typedef char CHAR;
typedef tchar_t TCHAR;
typedef wchar_t WCHAR;

typedef unsigned char BYTE;
typedef unsigned short WORD;
typedef uint32_t DWORD;
typedef uint64_t QWORD;

typedef int INT;
typedef int32_t LONG;
typedef int64_t LONGLONG;

typedef unsigned int UINT;
typedef uint32_t ULONG;
typedef uint64_t ULONGLONG;

typedef short SHORT;
typedef unsigned short USHORT;

typedef int8_t INT8;
typedef int16_t INT16;
typedef int32_t INT32;
typedef int64_t INT64;

typedef uint8_t UINT8;
typedef uint16_t UINT16;
typedef uint32_t UINT32;
typedef uint64_t UINT64;

typedef void* PVOID;
typedef PVOID LPVOID;
typedef PVOID HMODULE;
typedef PVOID HINSTANCE;

typedef PVOID HANDLE;
typedef INT INVALID_HANDLE_T;
typedef INT NULL_HANDLE_T;
#define INVALID_HANDLE_VALUE ((HANDLE)-1)
#define NULL_HANDLE_VALUE ((HANDLE)0)
#define INVALID_HANDLE INVALID_HANDLE_VALUE
#define NULL_HANDLE NULL_HANDLE_VALUE

typedef INT ATOM;
typedef INT INVALID_ATOM_T;
typedef INT NULL_ATOM_T;
#define INVALID_ATOM_VALUE ((ATOM)-1)
#define NULL_ATOM_VALUE ((ATOM)0)
#define NULL_ATOM NULL_ATOM_VALUE

typedef char* PCHAR;
typedef PCHAR LPCHAR;

typedef TCHAR* PTCHAR;
typedef PTCHAR LPTCHAR;

typedef WCHAR* PWCHAR;
typedef PWCHAR LPWCHAR;

typedef BYTE* PBYTE;
typedef PBYTE LPBYTE;

typedef WORD* PWORD;
typedef PWORD LPWORD;

typedef SHORT* PSHORT;
typedef PSHORT LPSHORT;

typedef LONG* PLONG;
typedef PLONG LPLONG;

typedef USHORT* PUSHORT;
typedef PUSHORT LPUSHORT;

typedef ULONG* PULONG;
typedef PULONG LPULONG;

typedef char* PSTR;
typedef PSTR LPSTR;
typedef const char* PCSTR;
typedef PCSTR LPCSTR;

typedef TCHAR* PTSTR;
typedef PTSTR LPTSTR;
typedef const TCHAR* PCTSTR;
typedef PCTSTR LPCTSTR;

typedef WCHAR* PWSTR;
typedef PWSTR LPWSTR;
typedef const WCHAR* PCWSTR;
typedef PCWSTR LPCWSTR;

typedef int MODE;
typedef mode_t MODE_T;
typedef size_t SIZE_T;
typedef ssize_t SSIZE_T;
// ...
// Unix
//
#endif // defined(WINDOWS)

//
// Generic
// ...
typedef ULONG TUNSIGNED;
typedef LONG TSIGNED;
typedef ULONG TSIZE;
typedef LONG TCOUNT;
typedef LONG TOFFSET;
typedef LONG TLENGTH;
#define UNDEFINED_LENGTH ((TLENGTH)(-1))

typedef MODE_T MODET;
typedef SIZE_T SIZET;
typedef SSIZE_T SSIZET;

typedef const CHAR* PCCHAR;
typedef const PCCHAR* PCPCCHAR;
typedef PCCHAR* PPCCHAR;
typedef PCHAR* PPCHAR;

typedef const TCHAR* PCTCHAR;
typedef const PCTCHAR* PCPCTCHAR;
typedef PCTCHAR* PPCTCHAR;
typedef PTCHAR* PPTCHAR;

typedef const WCHAR* PCWCHAR;
typedef const PCWCHAR* PCPCWCHAR;
typedef PCWCHAR* PPCWCHAR;
typedef PWCHAR* PPWCHAR;

typedef const BYTE* PCBYTE;
typedef const PCBYTE* PCPCBYTE;
typedef PCBYTE* PPCBYTE;
typedef PBYTE* PPBYTE;

typedef useconds_t nseconds_t;
typedef useconds_t mseconds_t;
typedef mseconds_t seconds_t;
typedef seconds_t minutes_t;
typedef seconds_t hours_t;
typedef unsigned days_t;
typedef unsigned months_t;
typedef unsigned years_t;
typedef days_t day_t;
typedef months_t month_t;
typedef years_t year_t;

typedef char char_t;
// ...
// Generic
//

#if defined(NO_TEMPLATE_PARAMETER_CAST)
//
// Can't cast template parameters
//
#define V_INVALID_HANDLE 0
#define V_NULL_HANDLE 0
#define V_NULL_ATOM 0
#else // defined(NO_TEMPLATE_PARAMETER_CAST)
#define V_INVALID_HANDLE INVALID_HANDLE
#define V_NULL_HANDLE NULL_HANDLE
#define V_NULL_ATOM NULL_ATOM
#endif // defined(NO_TEMPLATE_PARAMETER_CAST)

#define NULL_POINTER_VALUE ((PVOID)0)
#define NULL_POINTER NULL_POINTER_VALUE

#define CHARS_NULL ((char*)0)
#define WCHARS_NULL ((wchar_t*)0)
#define TCHARS_NULL ((tchar_t*)0)

#define CCHARS_NULL ((const char*)0)
#define CWCHARS_NULL ((const wchar_t*)0)
#define CTCHARS_NULL ((const tchar_t*)0)

namespace xos {
namespace base {

} // namespace base 
} // namespace xos 

#endif // _XOS_NADIR_XOS_BASE_PLATFORM_TYPES_HPP 
