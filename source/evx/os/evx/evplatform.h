///////////////////////////////////////////////////////////////////////
//   File: evplatform.h
//
// Author: $author$
//   Date: 4/3/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _EVPLATFORM_H
#define _EVPLATFORM_H

//
// Define MACOSX if any of the Mac OSX variants are selected
//
#if defined(APPLE) || defined(__APPLE__) || defined(__MACOS__) || defined(__MACOSX__) || defined(__MacOSX__) || defined(__macosx__)
#if defined(CPLATFORM_DEFINED_DEBUG) 
#warning defined MACOSX
#endif // defined(CPLATFORM_DEFINED_DEBUG)
#if !defined(MACOSX)
#define MACOSX
#endif // !defined(MACOSX)
#endif // defined(APPLE) || defined(__APPLE__) || defined(__MACOS__) || defined(__MACOSX__) || defined(__MacOSX__) || defined(__macosx__)

#if !defined(WIN32) 
#if defined(_WIN32)
#define WIN32
#endif // defined(_WIN32)
#endif // !defined(WIN32)

#if !defined(WIN64) 
#if defined(_WIN64)
#define WIN64
#endif // defined(_WIN64)
#endif // !defined(WIN64)

#if !defined(WINDOWS) 
#if defined(WIN32) || defined(WIN64) 
#define WINDOWS
#endif // defined(WIN32) || defined(WIN64)
#endif // !defined(WINDOWS)

#if defined(WIN32) 
//
// Windows
//

#if !defined(WIN32_API) 
#if !defined(UNIX_API) 
#define WIN32_API
#endif // !defined(UNIX_API)
#else // !defined(WIN32_API)
#undef UNIX_API
#endif // !defined(WIN32_API)

#if defined(EV_WINSOCK_2) 
// Use Windows Sockets 2 API
#include <winsock2.h>
#elif defined(EV_WINSOCK_1) 
// Use Windows Sockets 1 API
#include <winsock.h>
#else // defined(EV_WINSOCK_2) 
// Use Default Windows Sockets API
#endif // defined(EV_WINSOCK_2)

#include <windows.h>
#include <tchar.h>
#include <wchar.h>

#if defined(UNICODE) 
#define TCHAR_NOT_CHAR
#endif // defined(UNICODE)

#define MSC_VER_6 1200
#define MSC_VER_7 1300
#define MSC_VER_8 1400

#if (_MSC_VER >= MSC_VER_8) 
#define WIN32_MSC_VER_8
#elif (_MSC_VER >= MSC_VER_7) 
#define WIN32_MSC_VER_7
#else /* (_MSC_VER >= MSC_VER_8) */
#define WIN32_MSC_VER_6
#endif /* (_MSC_VER >= MSC_VER_8) */

#define EV_PLATFORM_EXPORT __declspec(dllexport)
#define EV_PLATFORM_IMPORT __declspec(dllimport)

#define EV_PLATFORM_CCAST(type) const_cast<type>
#define EV_PLATFORM_DCAST(type) dynamic_cast<type>
#define EV_PLATFORM_SCAST(type) static_cast<type>
#define EV_PLATFORM_RCAST(type) reinterpret_cast<type>

#if defined(WIN32_MSC_VER_6) 
// Visual C++ 6.0
#elif defined(WIN32_MSC_VER_7) 
// Visual C++ 7.0
#elif defined(WIN32_MSC_VER_8) 
// Visual C++ 8.0
#else // defined(WIN32_MSC_VER_6) 
// Otherwise
#endif // defined(WIN32_MSC_VER_6)

#if defined(WIN32_MSC_VER_6) 
// Visual C++ 6.0
#define EV_NO_STD_STRING_CLEAR
#define __FUNCTION__ __function__
#define DF(name) static const char __function__[]=""#name;
#else // defined(WIN32_MSC_VER_6) 
// Otherwise
#define DF(name)
#endif // defined(WIN32_MSC_VER_6)

typedef HANDLE INVALID_HANDLE_T;

#pragma warning(disable:4250) // derived 'class' inherits 'base::member' via dominance
#pragma warning(disable:4355) // 'this' used in base member initializer list
//#pragma warning(disable:4996) // 'function' was declared deprecated
#else // defined(WIN32) 
//
// Unix
//
#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#if !defined(UNIX)
#define UNIX
#endif // !defined(UNIX)

#if !defined(UNIX_API) 
#if !defined(WIN32_API) 
#define UNIX_API
#endif // !defined(WIN32_API)
#else // !defined(UNIX_API)
#undef WIN32_API
#endif // !defined(UNIX_API)

#define DF(name)
#define EV_NO_TEMPLATE_STATIC_MEMBERS

#define EV_PLATFORM_EXPORT
#define EV_PLATFORM_IMPORT

#define EV_PLATFORM_CCAST(type) const_cast<type>
#define EV_PLATFORM_DCAST(type) dynamic_cast<type>
#define EV_PLATFORM_SCAST(type) static_cast<type>

#if defined(__GNUC__)
#if (__GNUC__ < 4)
#define EV_PLATFORM_RCAST(type) (type)
#else // (__GNUC__ < 4)
#define EV_PLATFORM_RCAST(type) reinterpret_cast<type>
#endif // (__GNUC__ < 4)
#else // defined(__GNUC__)
#define EV_PLATFORM_RCAST(type) reinterpret_cast<type>
#endif // defined(__GNUC__)

typedef int BOOL;

typedef char CHAR;
typedef char TCHAR;
typedef short WCHAR;

typedef unsigned char BYTE;
typedef unsigned short WORD;
typedef uint32_t DWORD;

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
typedef PVOID HANDLE;
typedef PVOID HMODULE;
typedef PVOID HINSTANCE;

typedef INT INVALID_HANDLE_T;

typedef char* PCHAR;
typedef PCHAR LPCHAR;

typedef BYTE* PBYTE;
typedef PBYTE LPBYTE;

typedef char* PSTR;
typedef PSTR LPSTR;

typedef const char* PCSTR;
typedef PCSTR LPCSTR;

typedef TCHAR* PTSTR;
typedef PTSTR LPTSTR;

typedef const TCHAR* PCTSTR;
typedef PCTSTR LPCTSTR;

#define INFINITE -1
#define INVALID_HANDLE_VALUE (0)

#endif // defined(WIN32)

#define UNDEFINED -1
#undef INVALID_HANDLE
#define INVALID_HANDLE INVALID_HANDLE_VALUE

typedef const CHAR* PCCHAR;
typedef const PCCHAR* PCPCCHAR;
typedef PCCHAR* PPCCHAR;

#if defined(__cplusplus)
extern "C" {
#endif

#if defined(__cplusplus)
}
#endif

#endif // _EVPLATFORM_H
