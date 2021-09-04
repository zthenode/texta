/**
 **********************************************************************
 * Copyright (c) 1988-2009 $organization$
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
 *   File: cplatform_string.h
 *
 * Author: $author$
 *   Date: 2/2/2009
 **********************************************************************
 */
#ifndef _CPLATFORM_STRING_H
#define _CPLATFORM_STRING_H

#include <string.h>

#if !defined(CPLATFORM_STRING_WINDOWS_API) 
#define CPLATFORM_STRING_WINDOWS_API CPLATFORM_WINDOWS_API
#endif /* !defined(CPLATFORM_STRING_WINDOWS_API) */

#if defined(CPLATFORM_STRING_WINDOWS_API) 
/* Windows API
 */
#else /* defined(CPLATFORM_STRING_WINDOWS_API) */
/* Unix API
 */
#endif /* defined(CPLATFORM_STRING_WINDOWS_API) */

#if defined(__cplusplus)
extern "C" {
#endif /* defined(__cplusplus) */

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /* _CPLATFORM_STRING_H */
