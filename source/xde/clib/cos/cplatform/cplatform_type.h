/**
 **********************************************************************
 * Copyright (c) 1988-2017 $organization$
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
 *   File: cplatform_type.h
 *
 * Author: $author$
 *   Date: 12/8/2017, 1/2/2021
 **********************************************************************
 */
#ifndef _CPLATFORM_TYPE_H
#define _CPLATFORM_TYPE_H

#include "cplatform_define.h"

#if defined(WIN32) 
/** 
 * Windows 
 */
#if defined(WIN32_MSC_VER_6) 
/* Visual C++ 6.0 */
typedef char INT8;
typedef short INT16;
typedef unsigned char UINT8;
typedef unsigned short UINT16;
#else /* defined(WIN32_MSC_VER_6) */
#endif /* defined(WIN32_MSC_VER_6) */

typedef ULONGLONG QWORD;
typedef DWORD MODE;
typedef int MODE_T;

typedef HANDLE INVALID_HANDLE_T;
typedef HANDLE NULL_HANDLE_T;
#define NULL_HANDLE_VALUE NULL

typedef ATOM INVALID_ATOM_T;
typedef ATOM NULL_ATOM_T;
#define NULL_ATOM_VALUE 0

typedef SSIZE_T ssize_t;
typedef MODE_T mode_t;

typedef INT8 int8_t;
typedef INT16 int16_t;
typedef INT32 int32_t;
typedef INT64 int64_t;

typedef UINT8 uint8_t;
typedef UINT16 uint16_t;
typedef UINT32 uint32_t;
typedef UINT64 uint64_t;

typedef BYTE byte_t;
typedef WORD word_t;
typedef UINT uint;
typedef USHORT ushort;
typedef ULONG ulong;
/*
 * Windows
 **/
#else /* defined(WIN32) */
/**
 * Unix
 */
typedef int BOOL;

typedef char CHAR;
typedef char TCHAR;
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
#define INVALID_HANDLE_VALUE -1
#define NULL_HANDLE_VALUE 0

typedef INT ATOM;
typedef INT INVALID_ATOM_T;
typedef INT NULL_ATOM_T;
#define INVALID_ATOM_VALUE -1
#define NULL_ATOM_VALUE 0

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

typedef DWORD* PDWORD;
typedef PDWORD LPDWORD;

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

typedef struct _SECURITY_ATTRIBUTES 
{
    DWORD nLength;
    LPVOID lpSecurityDescriptor;
    BOOL bInheritHandle;
} SECURITY_ATTRIBUTES, 
  *PSECURITY_ATTRIBUTES, 
  *LPSECURITY_ATTRIBUTES;

typedef BYTE byte_t;
typedef WORD word_t;
typedef unsigned int uint;
typedef unsigned short ushort;

#if defined(MACOSX)
#define pointer_t platform_pointer_t
#endif /* defined(MACOSX) */
/*
 * Unix
 **/
#endif /* defined(WIN32) */

typedef CHAR char_t;
typedef TCHAR tchar_t;

#if !defined(CPLATFORM_NO_int) 
typedef INT8 int8;
typedef INT16 int16;
typedef INT32 int32;
typedef INT64 int64;
#endif /* !defined(CPLATFORM_NO_int) */

#if !defined(CPLATFORM_NO_uint) 
typedef UINT8 uint8;
typedef UINT16 uint16;
typedef UINT32 uint32;
typedef UINT64 uint64;
#endif /* !defined(CPLATFORM_NO_uint) */

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

typedef ULONG TUNSIGNED;
typedef LONG TSIGNED;
typedef ULONG TSIZE;
typedef LONG TLENGTH;
#define UNDEFINED_LENGTH ((TLENGTH)(-1))

typedef MODE_T MODET;
typedef SIZE_T SIZET;
typedef SSIZE_T SSIZET;

#define NULL_BYTE 0
#define NULL_CHAR 0
#define NULL_TCHAR 0
#define NULL_WCHAR 0

#define NULL_POINTER_VALUE 0
#define NULL_POINTER ((PVOID)(NULL_POINTER_VALUE))

#if defined(NO_TEMPLATE_PARAMETER_CAST) 
/* Can't cast template parameters
 */
#define V_UNDEFINED -1
#define V_INVALID_HANDLE 0
#define V_NULL_HANDLE 0
#define V_NULL_ATOM 0
#else /* defined(NO_TEMPLATE_PARAMETER_CAST) */
#define V_UNDEFINED UNDEFINED
#define V_INVALID_HANDLE INVALID_HANDLE
#define V_NULL_HANDLE NULL_HANDLE
#define V_NULL_ATOM NULL_ATOM
#endif /* defined(NO_TEMPLATE_PARAMETER_CAST) */

typedef FILE* file_t;
typedef void* pointer_t;
typedef const void* const_pointer_t;
#define null ((pointer_t)0)
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

#if defined(__cplusplus)
extern "C" {
#endif /* defined(__cplusplus) */

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /* _CPLATFORM_TYPE_H */
