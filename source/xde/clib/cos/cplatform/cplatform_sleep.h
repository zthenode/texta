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
 *   File: cplatform_sleep.h
 *
 * Author: $author$
 *   Date: 2/7/2009
 **********************************************************************
 */
#ifndef _CPLATFORM_SLEEP_H
#define _CPLATFORM_SLEEP_H

#include "cplatform.h"

#if defined(WINDOWS) 
/* Windows
 */
#define cplatform_sleep(ms) Sleep(ms)
#else /* defined(WINDOWS) */
/* Unix
 */
#define cplatform_sleep(ms) usleep(ms*1000)
#endif /* defined(WINDOWS) */

#if defined(__cplusplus)
extern "C" {
#endif /* defined(__cplusplus) */

#if defined(WINDOWS) 
/* Windows
 */
#else /* defined(WINDOWS) */
/* Unix
 */
#endif /* defined(WINDOWS) */

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /* _CPLATFORM_SLEEP_H */
