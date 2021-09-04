/**
 **********************************************************************
 * Copyright (c) 1988-2011 $organization$
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
 *   File: cplatform_compiler.h
 *
 * Author: $author$
 *   Date: 3/12/2011
 **********************************************************************
 */
#ifndef _CPLATFORM_COMPILER_H
#define _CPLATFORM_COMPILER_H

/*
 **********************************************************************
 *
 * Compiler
 *
 **********************************************************************
 */
/*
 * Visual C++
 */
#if defined(__MSC__) || defined(_MSC_VER) || defined(MSC_VER)
/*
 * Visual C++
 * ...
 */
#if defined(CPLATFORM_DEFINED_DEBUG) 
#warning defined MSC
#endif /* defined(CPLATFORM_DEFINED_DEBUG) */

#if !defined(MSC_VER)
#if !defined(_MSC_VER)
#define MSC_VER __MSC__
#else /* !defined(_MSC_VER) */
#define MSC_VER _MSC_VER
#endif /* !defined(_MSC_VER) */
#endif /* !defined(MSC_VER) */

#if !defined(__MSC__)
#define __MSC__ MSC_VER
#endif /* !defined(__MSC__) */

#define MSC_VER_6 1200
#define MSC_VER_7 1300
#define MSC_VER_8 1400
#define MSC_VER_9 1500

#if (_MSC_VER >= MSC_VER_9) 
#define WINDOWS_MSC_VER_9
#elif (_MSC_VER >= MSC_VER_8) 
#define WINDOWS_MSC_VER_8
#elif (_MSC_VER >= MSC_VER_7) 
#define WINDOWS_MSC_VER_7
#else /* (_MSC_VER >= MSC_VER_8) */
#define WINDOWS_MSC_VER_6
#endif /* (_MSC_VER >= MSC_VER_8) */

/* Visual C++ version specific definitions
 */
#if defined(WINDOWS_MSC_VER_6) 
/* Visual C++ 6.0 
 */
#pragma warning(disable:4786) /* identifier was truncated to '255'
                                 characters in the debug information */
#define NO_TEMPLATE_PARAMETER_CAST
#define NO_STD_STRING_CLEAR
#else /* defined(WINDOWS_MSC_VER_6) */
/* Visual C++ 7.0 or greater 
 */
#pragma warning(disable:4503) /* decorated name length exceeded, name was truncated */
#pragma warning(disable:4996) /* 'function' was declared deprecated */
#endif /* defined(WINDOWS_MSC_VER_6) */

#pragma warning(disable:4250) /* derived 'class' inherits 'base::member' via dominance */
#pragma warning(disable:4355) /* 'this' used in base member initializer list */
#pragma warning(disable:4065) /* switch statement contains 'default' but no 'case' labels */

#define PLATFORM_CCAST(type) const_cast<type>
#define PLATFORM_DCAST(type) dynamic_cast<type>
#define PLATFORM_SCAST(type) static_cast<type>
#define PLATFORM_RCAST(type) reinterpret_cast<type>

#define CTHIS
#define restrict
#define NO_ARRAY_CONSTRUCTION
#define NO_STATIC_MEMBER_EXPORT

/*
 * ...
 * Visual C++
 */
#endif /* defined(__MSC__) || defined(_MSC_VER) || defined(MSC_VER)*/

/*
 * Gcc
 */
#if defined(__GNUC__)
/*
 * Gcc
 * ...
 */
 
/* Gcc version specific definitions
 */
#if (__GNUC__ < 4)
#define PLATFORM_RCAST(type) (type)
#else /* (__GNUC__ < 4) */
#define PLATFORM_RCAST(type) reinterpret_cast<type>
#if (__GNUC_MINOR__ < 3)
#define NO_ARRAY_CONSTRUCTION
#else /* (__GNUC_MINOR__ < 3) */
#endif /*(__GNUC_MINOR__ < 3) */
#endif /* (__GNUC__ < 4) */

#define PLATFORM_CCAST(type) const_cast<type>
#define PLATFORM_DCAST(type) dynamic_cast<type>
#define PLATFORM_SCAST(type) static_cast<type>

#define NO_ARRAY_CONSTRUCTION
#define NO_TEMPLATE_STATIC_MEMBERS

#define CTHIS (*this).

#define _T(string) string

#if defined(CPLATFORM_DEFINED_DEBUG) 
#warning defined GNUC
#endif /* defined(CPLATFORM_DEFINED_DEBUG) */
/*
 * ...
 * Gcc
 */
#endif /* defined(__GNUC__) */

#if defined(__cplusplus)
extern "C" {
#endif /* defined(__cplusplus) */

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /* _CPLATFORM_COMPILER_H */
