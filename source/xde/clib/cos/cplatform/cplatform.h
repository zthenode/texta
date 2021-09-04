/**
 **********************************************************************
 * Copyright (c) 1988-2007 $organization$
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
 *   File: cplatform.h
 *
 * Author: $author$
 *   Date: 10/12/2007
 *
 **********************************************************************
 */
#ifndef _CPLATFORM_H
#define _CPLATFORM_H
#define _PLATFORM_H

#include "cplatform_build.h"
#include "cplatform_include.h"
#include "cplatform_define.h"
#include "cplatform_type.h"
#include "cplatform_api.h"

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
}
#endif /* defined(__cplusplus) */

#include "cplatform_api.h"

#endif /* _CPLATFORM_H */
