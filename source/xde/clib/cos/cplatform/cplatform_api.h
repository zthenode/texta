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
 *   File: cplatform_api.h
 *
 * Author: $author$
 *   Date: 12/8/2017
 **********************************************************************
 */
#ifndef _CPLATFORM_API_H
#define _CPLATFORM_API_H

#include "cplatform_type.h"

/* Select which API is to be used (Windows/Unix)
 */
#if defined(WIN32) 
/* Windows host
 */
#if !defined(WIN32_API) 
#if !defined(UNIX_API) 
#define WIN32_API
#if !defined(WINDOWS_API) 
#define WINDOWS_API 
#endif /* !defined(WINDOWS_API) */
#if defined(WIN32_WCE) 
/* Windows CE host
 */
#if !defined(WIN32_WCE_API) 
#define WIN32_WCE_API
#endif /* !defined(WIN32_WCE_API) */
#endif /* defined(WIN32_WCE) */
#endif /* !defined(UNIX_API) */
#else /* !defined(WIN32_API) */
#undef UNIX_API
#undef WIN64_API
#endif /* !defined(WIN32_API) */
#else /* defined(WIN32) */
/* Unix host
 */
#if !defined(UNIX_API) 
#if !defined(WIN32_API) 
#define UNIX_API
#else /* !defined(WIN32_API) */
#endif /* !defined(WIN32_API) */
#else /* !defined(UNIX_API) */
#undef WINDOWS_API
#undef WIN64_API
#undef WIN32_API
#undef WIN32_CE_API
#endif /* !defined(UNIX_API) */
#endif /* defined(WIN32) */

#if defined(WIN32) 
/** 
 * Windows 
 */
/*
 * Windows
 **/
#else /* defined(WIN32) */
/**
 * Unix
 */
#if !defined(UNIX_API) 
#if !defined(WIN32_API) 
#define UNIX_API
#endif /* !defined(WIN32_API) */
#else /* !defined(UNIX_API) */
#undef WIN32_API
#endif /* !defined(UNIX_API) */
/*
 * Unix
 **/
#endif /* defined(WIN32) */

#if defined(__cplusplus)
extern "C" {
#endif /* defined(__cplusplus) */

#if defined(WIN32) 
/** 
 * Windows 
 */
/*
 * Windows
 **/
#else /* defined(WIN32) */
/**
 * Unix
 */
BOOL CloseHandle(HANDLE hObject);
/*
 * Unix
 **/
#endif /* defined(WIN32) */

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /* _CPLATFORM_API_H */
