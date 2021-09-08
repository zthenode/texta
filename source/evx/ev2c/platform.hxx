/**
 **********************************************************************
 * Copyright (c) $year$ $author$
 *
 * This software is provided by the author and contributors ``as is'' 
 * and any express or implied warranties, including, but not limited to, 
 * the implied warranties of merchantability and fitness for a particular 
 * purpose are disclaimed. In no event shall the author or contributors 
 * be liable for any direct, indirect, incidental, special, exemplary, 
 * or consequential damages (including, but not limited to, procurement 
 * of substitute goods or services; loss of use, data, or profits; or 
 * business interruption) however caused and on any theory of liability, 
 * whether in contract, strict liability, or tort (including negligence 
 * or otherwise) arising in any way out of the use of this software, 
 * even if advised of the possibility of such damage.
 *
 *   File: platform.hxx
 *
 * Author: $author$
 *   Date: $date$
 **********************************************************************
 */
#ifndef _PLATFORM_HXX
#define _PLATFORM_HXX

#if !defined(WIN32) 
#if defined(_WIN32) 
#define WIN32
#endif /* defined(_WIN32) */
#endif /* !defined(WIN32) */

#if defined(WIN32) 
/* Windows
 */
#include <windows.h>
#include <tchar.h>
#include <wchar.h>

#if defined(UNICODE) 
#define TCHAR_NOT_CHAR
#endif /* defined(UNICODE) */

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

#define PLATFORM_EXPORT __declspec(dllexport)
#define PLATFORM_IMPORT __declspec(dllimport)

#define PLATFORM_CCAST(type) const_cast<type>
#define PLATFORM_DCAST(type) dynamic_cast<type>
#define PLATFORM_SCAST(type) static_cast<type>
#define PLATFORM_RCAST(type) reinterpret_cast<type>

#if defined(WIN32_MSC_VER_6) 
/* Visual C++ 6.0 */
#elif defined(WIN32_MSC_VER_7) 
/* Visual C++ 7.0 */
#elif defined(WIN32_MSC_VER_8) 
/* Visual C++ 8.0 */
#else // defined(WIN32_MSC_VER_6) 
/* Otherwise */
#endif /* defined(WIN32_MSC_VER_6) */

#if defined(WIN32_MSC_VER_6) 
/* Visual C++ 6.0 */
#define NO_STD_STRING_CLEAR
#define __FUNCTION__ __function__
#define DF(name) static const char __function__[]=""#name;
#else /* defined(WIN32_MSC_VER_6) */
/* Otherwise */
#define DF(name)
#pragma warning(disable:4996) /* 'function' was declared deprecated */
#endif /* defined(WIN32_MSC_VER_6) */

#pragma warning(disable:4250) /* derived 'class' inherits 'base::member' via dominance */
#pragma warning(disable:4355) /* 'this' used in base member initializer list */

#else /* defined(WIN32) */
/* Unix
 */
#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#if !defined(UNIX)
#define UNIX
#endif /* !defined(UNIX) */

#define DF(name)
#define NO_TEMPLATE_STATIC_MEMBERS

#define PLATFORM_EXPORT
#define PLATFORM_IMPORT

#define PLATFORM_CCAST(type) const_cast<type>
#define PLATFORM_DCAST(type) dynamic_cast<type>
#define PLATFORM_SCAST(type) static_cast<type>

#if defined(__GNUC__)
#if (__GNUC__ < 4)
#define PLATFORM_RCAST(type) (type)
#else /* (__GNUC__ < 4) */
#define PLATFORM_RCAST(type) reinterpret_cast<type>
#endif /* (__GNUC__ < 4) */
#else /* defined(__GNUC__) */
#define PLATFORM_RCAST(type) reinterpret_cast<type>
#endif /* defined(__GNUC__) */

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

typedef char* PCHAR;
typedef PCHAR LPCHAR;

typedef TCHAR* PTCHAR;
typedef PTCHAR LPTCHAR;

typedef WCHAR* PWCHAR;
typedef PWCHAR LPWCHAR;

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

typedef WCHAR* PWSTR;
typedef PWSTR LPWSTR;

typedef const WCHAR* PCWSTR;
typedef PCWSTR LPCWSTR;

#define INFINITE -1
#define INVALID_HANDLE_VALUE (0)

#endif /* defined(WIN32) */

#define UNDEFINED -1
#define INVALID_HANDLE INVALID_HANDLE_VALUE

typedef INT8 int8;
typedef INT16 int16;
typedef INT32 int32;
typedef INT64 int64;

typedef UINT8 uint8;
typedef UINT16 uint16;
typedef UINT32 uint32;
typedef UINT64 uint64;

#endif /* _PLATFORM_HXX */
