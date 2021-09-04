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
 *   File: cplatform_define.h
 *
 * Author: $author$
 *   Date: 12/8/2017
 **********************************************************************
 */
#ifndef _CPLATFORM_DEFINE_H
#define _CPLATFORM_DEFINE_H

#include "cplatform_include.h"

#if defined(WIN32) 
/** 
 * Windows 
 */
#define PACKED_STRUCT
#define CTHIS
#define restrict

#if defined(UNICODE) 
#define TCHAR_NOT_CHAR
#endif /* defined(UNICODE) */

#define MSC_VER_6 1200
#define MSC_VER_7 1300
#define MSC_VER_8 1400

#if !defined(MSC_VER)
#define MSC_VER _MSC_VER
#endif /* !defined(MSC_VER) */

#if (_MSC_VER >= MSC_VER_8) 
#define WIN32_MSC_VER_8
#elif (_MSC_VER >= MSC_VER_7) 
#define WIN32_MSC_VER_7
#else /* (_MSC_VER >= MSC_VER_8) */
#define WIN32_MSC_VER_6
#endif /* (_MSC_VER >= MSC_VER_8) */

#if defined(WIN32_MSC_VER_6) 
/* Visual C++ 6.0 */
#pragma warning(disable:4786) /* identifier was truncated to '255'
                                 characters in the debug information */
#define NO_TEMPLATE_PARAMETER_CAST
#define NO_STD_STRING_CLEAR
#define __FUNCTION__ __function__
#define DF(name) static const char __function__[]=""#name;
#else /* defined(WIN32_MSC_VER_6) */
/* Otherwise */
#define DF(name)
#pragma warning(disable:4503) /* decorated name length exceeded, name was truncated */
#pragma warning(disable:4996) /* 'function' was declared deprecated */
#endif /* defined(WIN32_MSC_VER_6) */

#pragma warning(disable:4250) // derived 'class' inherits 'base::member' via dominance
#pragma warning(disable:4355) // 'this' used in base member initializer list
/*
 * Windows
 **/
#else /* defined(WIN32) */
/**
 * Unix
 */
#if !defined(UNIX)
#define UNIX
#endif /* !defined(UNIX) */

#define DF(name)
#define NO_TEMPLATE_STATIC_MEMBERS
#define NO_TEMPLATE_PARAMETER_CAST

#define PLATFORM_EXPORT
#define PLATFORM_IMPORT

#define PLATFORM_CCAST(type) const_cast<type>
#define PLATFORM_DCAST(type) dynamic_cast<type>
#define PLATFORM_SCAST(type) static_cast<type>

#if defined(__GNUC__)
/* Gcc
 */
#define CTHIS (*this).
#define PACKED_STRUCT __attribute__ ((packed))
#if (__GNUC__ < 4)
#define PLATFORM_RCAST(type) (type)
#else /* (__GNUC__ < 4) */
#define PLATFORM_RCAST(type) reinterpret_cast<type>
#endif /* (__GNUC__ < 4) */
#else /* defined(__GNUC__) */
#define PLATFORM_RCAST(type) reinterpret_cast<type>
#endif /* defined(__GNUC__) */

#if !defined(TRUE) 
#define TRUE 1
#else /* !defined(TRUE) */
#endif /* !defined(TRUE) */

#if !defined(FALSE) 
#define FALSE 0
#else /* !defined(FALSE) */
#endif /* !defined(FALSE) */

#define WINAPI
#define INFINITE -1
/*
 * Unix
 **/
#endif /* defined(WIN32) */

#define UNDEFINED -1
#define c_PACKED_STRUCT PACKED_STRUCT
#define packed PACKED_STRUCT

#if defined(__cplusplus)
extern "C" {
#endif /* defined(__cplusplus) */

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /* _CPLATFORM_DEFINE_H */
