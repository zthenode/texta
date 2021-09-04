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
 *   File: cplatform_build.h
 *
 * Author: $author$
 *   Date: 12/8/2017
 **********************************************************************
 */
#ifndef _CPLATFORM_BUILD_H
#define _CPLATFORM_BUILD_H

/* Define WIN64 if any of the Win64
 * variants are selected
 */
#if !defined(WIN64)
#if defined(_WIN64) || defined(__WIN64__) || defined(__Win64__) || defined(__win64__)
#define WIN64
#else /*  defined(_WIN64) || defined(__WIN64__) || defined(__Win64__) || defined(__win64__) */
#endif /*  defined(_WIN64) || defined(__WIN64__) || defined(__Win64__) || defined(__win64__) */
#else /*  !defined(WIN64) */
#endif /*  !defined(WIN64) */

/* Define WIN32 if any of the Win32
 * variants are selected
 */
#if !defined(WIN32)
#if defined(_WIN32) || defined(__WIN32__) || defined(__Win32__) || defined(__win32__)
#define WIN32
#else /*  defined(_WIN32) || defined(__WIN32__) || defined(__Win32__) || defined(__win32__) */
#endif /*  defined(_WIN32) || defined(__WIN32__) || defined(__Win32__) || defined(__win32__) */
#else /*  !defined(WIN32) */
#endif /*  !defined(WIN32) */

/* Define LINUX if any of the Linux
 * variants are selected
 */
#if !defined(LINUX)
#if defined(__LINUX__) || defined(__Linux__) || defined(__linux__)
#define LINUX
#else /*  defined(__LINUX__) || defined(__Linux__) || defined(__linux__) */
#endif /*  defined(__LINUX__) || defined(__Linux__) || defined(__linux__) */
#else /*  !defined(LINUX) */
#endif /*  !defined(LINUX) */

/* Define MACOSX if any of the Mac OSX
 * variants are selected
 */
#if !defined(MACOSX)
#if defined(__APPLE__) || defined(__MACOS__) || defined(__MACOSX__) || defined(__MacOSX__) || defined(__macosx__)
#define MACOSX
#else /*  defined(__MACOS__) || defined(__MacOSX__) || defined(__macosx__) */
#endif /*  defined(__MACOS__) || defined(__MacOSX__) || defined(__macosx__) */
#else /*  !defined(MACOSX) */
#endif /*  !defined(MACOSX) */

/* Define WIN64_WCE if any of the Windows CE 64bit 
 * variants are selected
 */
#if !defined(WIN64_WCE) 
#if defined(_WIN64_WCE)
#define WIN64_WCE
#if !defined(WIN64) 
#define WIN64
#endif /* !defined(WIN64) */
#endif /* defined(_WIN64_WCE)*/
#endif /* !defined(WIN64_WCE) */

/* Define WIN32_WCE if any of the Windows CE 32bit 
 * variants are selected
 */
#if !defined(WIN32_WCE) 
#if defined(_WIN32_WCE)
#define WIN32_WCE
#if !defined(WIN32) 
#define WIN32
#endif /* !defined(WIN32) */
#endif /* defined(_WIN32_WCE)*/
#endif /* !defined(WIN32_WCE) */

/* Define WINDOWS if any of the Windows
 * variants are selected
 */
#if !defined(WINDOWS) 
#if defined(WIN64) || defined(WIN32) 
#define WINDOWS 
#else /* defined(WIN64) || defined(WIN32) */
#endif /* defined(WIN64) || defined(WIN32) */
#else /* !defined(WINDOWS) */
#endif /* !defined(WINDOWS) */

/* Define BSD if any of the BSD variants are defined
 */
#if !defined(BSD)
#if defined(MACOSX)
#define BSD
#endif /*/ defined(MACOSX) /*/
#endif /*/ !defined(BSD) /*/

/* Define SYSTEMV if any of the SYSTEMV variants are defined
 */
#if !defined(SYSTEMV)
#if defined(LINUX)
#define SYSTEMV
#endif /*/ defined(LINUX) /*/
#endif /*/ !defined(SYSTEMV) /*/

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
/*
 * Unix
 **/
#endif /* defined(WIN32) */

#if defined(__cplusplus)
extern "C" {
#endif /* defined(__cplusplus) */

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /* _CPLATFORM_BUILD_H */

        

