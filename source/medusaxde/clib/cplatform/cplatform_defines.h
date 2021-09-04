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
 *   File: cplatform_defines.h
 *
 * Author: $author$
 *   Date: 3/13/2011
 **********************************************************************
 */
#ifndef _CPLATFORM_DEFINES_H
#define _CPLATFORM_DEFINES_H

/*
 **********************************************************************
 *
 * Defines
 *
 **********************************************************************
 */
#if defined(WINDOWS) 
/* Windows
 * ...
 */
 
#if !defined(__GNUC__) 
/* Visual C++
 * ...
 */
/* ...
 * Visual C++
 */
#else /* !defined(__GNUC__) */
/*
 * Gcc
 * ...
 */
#if defined(CPLATFORM_DEFINED_DEBUG) 
#warning Compiler other than Visual C++ (Gcc) being used
#endif /* defined(CPLATFORM_DEFINED_DEBUG) */
/*
 * ...
 * Gcc
 */
#endif /* !defined(__GNUC__) */
 
#if defined(UNICODE) 
#define TCHAR_NOT_CHAR
#endif /* defined(UNICODE) */

#define PLATFORM_EXPORT __declspec(dllexport)
#define PLATFORM_IMPORT __declspec(dllimport)

/* ...
 * Windows
 */
#else /* defined(WINDOWS) */
/* Unix
 * ...
 */
 
#if defined(__GNUC__) 
/* Gcc
 * ...
 */
/* ...
 * Gcc
 */
#else /* defined(__GNUC__) */
#error Compiler other than Gcc not supported
#endif /* defined(__GNUC__) */

#define PLATFORM_EXPORT
#define PLATFORM_IMPORT

/* ...
 * Unix
 */
#endif /* defined(WINDOWS) */

/* Generic
 * ...
 */
#define c_EXPORT PLATFORM_EXPORT
#define c_IMPORT PLATFORM_IMPORT

#define UNDEFINED -1

#define INVALID_HANDLE INVALID_HANDLE_VALUE
#define NULL_HANDLE NULL_HANDLE_VALUE
#define NULL_ATOM NULL_ATOM_VALUE

#define NULL_BYTE 0
#define NULL_CHAR 0
#define NULL_TCHAR 0
#define NULL_WCHAR 0

#if defined(NO_TEMPLATE_PARAMETER_CAST) 
/* Can't cast template parameters
 */
#define V_INVALID_HANDLE 0
#define V_NULL_HANDLE 0
#define V_NULL_ATOM 0
#else /* defined(NO_TEMPLATE_PARAMETER_CAST) */
#define V_INVALID_HANDLE INVALID_HANDLE
#define V_NULL_HANDLE NULL_HANDLE
#define V_NULL_ATOM NULL_ATOM
#endif /* defined(NO_TEMPLATE_PARAMETER_CAST) */
/* ...
 * Generic
 */

#if defined(__cplusplus)
extern "C" {
#endif /* defined(__cplusplus) */

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /* _CPLATFORM_DEFINES_H */
