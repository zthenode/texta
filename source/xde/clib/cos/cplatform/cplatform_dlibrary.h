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
 *   File: cplatform_dlibrary.h
 *
 * Author: $author$
 *   Date: 5/24/2008
 **********************************************************************
 */
#ifndef _CPLATFORM_DLIBRARY_H
#define _CPLATFORM_DLIBRARY_H

#include "cplatform.h"

#if defined(WIN32) 
/* Windows
 */
typedef HMODULE DLIBRARY;
#define INVALID_DLIBRARY 0
#else /* defined(WIN32) */
/* Unix
 */
#include <dlfcn.h>
typedef void* DLIBRARY;
#define INVALID_DLIBRARY 0
#endif /* defined(WIN32) */

#if defined(__cplusplus)
extern "C" {
#endif /* defined(__cplusplus) */

#if defined(WIN32) 
/* Windows
 */
void* dlopen(const char* path, int flag);
int dlclose(void* handle);
void* dlsym(void* handle, const char* symbol);
char* dlerror(void);
#else /* defined(WIN32) */
/* Unix
 */
HINSTANCE LoadLibrary(LPCTSTR lpLibFileName);
BOOL FreeLibrary(HMODULE hLibModule);
#endif /* defined(WIN32) */

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /* _CPLATFORM_DLIBRARY_H */
