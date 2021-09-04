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
 *   File: cplatform_fcntl.h
 *
 * Author: $author$
 *   Date: 9/15/2011
 **********************************************************************
 */
#ifndef _CPLATFORM_FCNTL_H
#define _CPLATFORM_FCNTL_H

#include "cplatform.h"
#include <fcntl.h>

#if defined(WINDOWS) 
/* Windows
 */
#include <io.h>
#define PLATFORM_O_BINARY _O_BINARY
#else /* defined(WINDOWS) */
/* Unix
 */
#define PLATFORM_O_BINARY 0
#endif /* defined(WINDOWS) */

#if defined(__cplusplus)
extern "C" {
#endif /* defined(__cplusplus) */

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /* _CPLATFORM_FCNTL_H */
        

