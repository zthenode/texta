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
 *   File: cplatform_time.c
 *
 * Author: $author$
 *   Date: 3/19/2011
 **********************************************************************
 */
#include "cplatform_time.h"

#if defined(WINDOWS) 
/* Windows
 */
/**
 **********************************************************************
 * Function: gmtime_r
 *
 *   Author: $author$
 *     Date: 8/26/2011
 **********************************************************************
 */
struct tm* gmtime_r
(const time_t* timep, struct tm* tmp)
{
    return tmp;
}
/**
 **********************************************************************
 * Function: localtime_r
 *
 *   Author: $author$
 *     Date: 8/26/2011
 **********************************************************************
 */
struct tm* localtime_r
(const time_t* timep, struct tm* tmp)
{
    return tmp;
}
#else /* defined(WINDOWS) */
/* Unix
 */
#endif /* defined(WINDOWS) */

#if !defined(TIME_HAS_CLOCK_GETTIME)
/**
 **********************************************************************
 * Function: clock_gettime
 *
 *   Author: $author$
 *     Date: 3/20/2011
 **********************************************************************
 */
int clock_gettime
(clockid_t clockid, struct timespec* timespec)
{
    int err = 1;
    return err;
}
#endif /* !defined(TIME_HAS_CLOCK_GETTIME) */
