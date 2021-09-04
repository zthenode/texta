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
 *   File: cplatform.h
 *
 * Author: $author$
 *   Date: 3/12/2011
 **********************************************************************
 */
#ifndef _CPLATFORM_H
#define _CPLATFORM_H

/*
 **********************************************************************
 *
 * Build Environment
 *
 **********************************************************************
 */
#include "cplatform_build.h"

/*
 **********************************************************************
 *
 * Compiler
 *
 **********************************************************************
 */
#include "cplatform_compiler.h"

/*
 **********************************************************************
 *
 * Includes
 *
 **********************************************************************
 */
#include "cplatform_includes.h"

/*
 **********************************************************************
 *
 * Defines
 *
 **********************************************************************
 */
#include "cplatform_defines.h"

/*
 **********************************************************************
 *
 * Types
 *
 **********************************************************************
 */
#include "cplatform_types.h"

#if defined(WINDOWS) 
/* Windows
 */
/* Windows
 */
#else /* defined(WINDOWS) */
/* Unix
 */
/* Unix
 */
#endif /* defined(WINDOWS) */

#if defined(__cplusplus)
extern "C" {
#endif /* defined(__cplusplus) */

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /* _CPLATFORM_H */
