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
 *   File: cplatform_time.h
 *
 * Author: $author$
 *   Date: 3/19/2011
 **********************************************************************
 */
#ifndef _CPLATFORM_TIME_H
#define _CPLATFORM_TIME_H

#include "cplatform.h"

#if defined(WINDOWS) 
/* Windows
 */
#include <time.h>

typedef time_t useconds_t;
typedef struct timespec
{
    time_t tv_sec;
    time_t tv_nsec;
} timespec_t;
#else /* defined(WINDOWS) */
/* Unix
 */
#include <time.h>

#if defined(_POSIX_TIMERS) && (_POSIX_TIMERS >= 0)
#define TIME_HAS_CLOCK_GETTIME
#endif /* defined(_POSIX_TIMERS) && (_POSIX_TIMERS >= 0) */

#endif /* defined(WINDOWS) */

#if !defined(TIME_HAS_CLOCK_GETTIME)
typedef int clockid_t;
enum
{
    CLOCK_REALTIME,
    CLOCK_MONOTONIC
};
#endif /* !defined(TIME_HAS_CLOCK_GETTIME) */

typedef useconds_t mseconds_t;

#if defined(__cplusplus)
extern "C" {
#endif /* defined(__cplusplus) */

#if defined(WINDOWS) 
/* Windows
 */
struct tm* gmtime_r
(const time_t* timep, struct tm* tmp);

struct tm* localtime_r
(const time_t* timep, struct tm* tmp);
#else /* defined(WINDOWS) */
/* Unix
 */
#endif /* defined(WINDOWS) */

#if !defined(TIME_HAS_CLOCK_GETTIME)
int clock_gettime
(clockid_t clockid, struct timespec* timespec);
#endif /* !defined(TIME_HAS_CLOCK_GETTIME) */

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /* _CPLATFORM_TIME_H */
