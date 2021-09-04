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
 *   File: cplatform_includes.h
 *
 * Author: $author$
 *   Date: 3/13/2011
 **********************************************************************
 */
#ifndef _CPLATFORM_INCLUDES_H
#define _CPLATFORM_INCLUDES_H

/*
 **********************************************************************
 *
 * Includes
 *
 **********************************************************************
 */
#if defined(WINDOWS) 
/* Windows
 */

#if !defined(_WINDOWS_) 
#define _INC_WINDOWS
#include <windows.h>
#if !defined(_WIN32_WINNT) 
#if (WINVER >= 0x0500)
#define _WIN32_WINNT WINVER
#endif /* (WINVER >= 0x500) */
#endif /* !defined(_WIN32_WINNT) */
#undef _INC_WINDOWS
#undef _WINDOWS_
#else /* !defined(_WINDOWS_) */
#endif /* !defined(_WINDOWS_) */

#include <windows.h>
#include <windowsx.h>
#include <tchar.h>
#include <wchar.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#else /* defined(WINDOWS) */
/* Unix
 */
#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#endif /* defined(WINDOWS) */

#if defined(__cplusplus)
extern "C" {
#endif /* defined(__cplusplus) */

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /* _CPLATFORM_INCLUDES_H */
