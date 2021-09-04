/**
 **********************************************************************
 * Copyright (c) 1988-2008 $organization$
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
 *   File: cplatform_windows.h
 *
 * Author: $author$
 *   Date: 4/23/2008
 **********************************************************************
 */
#ifndef _CPLATFORM_WINDOWS_H
#define _CPLATFORM_WINDOWS_H

#include "cplatform.h"

#if defined(WIN32) 
/* Windows
 */
#else /* defined(WIN32) */
/* Unix
 */
typedef HANDLE HGDIOBJ;
#endif /* defined(WIN32) */

#define NULL_HGDIOBJ NULL_HANDLE_VALUE

#if defined(_WIN32_WCE) 
typedef LPWSTR LPCMDLINE;
#else /* defined(_WIN32_WCE) */
typedef LPSTR LPCMDLINE;
#endif /* defined(_WIN32_WCE) */

#if defined(__cplusplus)
extern "C" {
#endif /* defined(__cplusplus) */

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /* _CPLATFORM_WINDOWS_H */
