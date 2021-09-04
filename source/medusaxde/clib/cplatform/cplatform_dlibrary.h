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
 *   File: cplatform_dlibrary.h
 *
 * Author: $author$
 *   Date: 10/13/2011
 **********************************************************************
 */
#ifndef _CPLATFORM_DLIBRARY_H
#define _CPLATFORM_DLIBRARY_H

#include "cplatform.h"

#if defined(WINDOWS) 
/* Windows
 */
typedef HMODULE DLIBRARY;
#define NULL_DLIBRARY 0
#define PLATFORM_DLIBRARY_EXTENSION "dll"
#else /* defined(WINDOWS) */
/* Unix
 */
#include <dlfcn.h>
#if defined(MACOSX) 
/* Mac OSX
 */
#define PLATFORM_DLIBRARY_EXTENSION "dylib"
#else /* defined(MACOSX) */
/* Unix
 */
#define PLATFORM_DLIBRARY_EXTENSION "so"
#endif /* defined(MACOSX) */
typedef void* DLIBRARY;
#define NULL_DLIBRARY 0
#endif /* defined(WINDOWS) */

#define DLIBRARY_SYMBOLX(identifier) "" #identifier ""
#define DLIBRARY_SYMBOL(identifier) DLIBRARY_SYMBOLX(identifier)

#if defined(__cplusplus)
extern "C" {
#endif /* defined(__cplusplus) */

#if defined(WINDOWS) 
/* Windows
 */
void* dlopen(const char* path, int flag);
int dlclose(void* handle);
void* dlsym(void* handle, const char* symbol);
char* dlerror(void);
void _init(void);
void _fini(void);
#else /* defined(WINDOWS) */
/* Unix
 */
HMODULE LoadLibrary(LPCTSTR lpFileName);
BOOL FreeLibrary(HMODULE hModule);
FARPROC GetProcAddress(HMODULE hModule, LPCSTR lpProcName);
BOOL WINAPI DllMain(HINSTANCE hinstDll, DWORD dwReason, LPVOID lpvReserved);
#endif /* defined(WINDOWS) */

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /* _CPLATFORM_DLIBRARY_H */
