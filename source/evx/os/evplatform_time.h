///////////////////////////////////////////////////////////////////////
//   File: evplatform_time.h
//
// Author: $author$
//   Date: 8/7/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _EVPLATFORM_TIME_H
#define _EVPLATFORM_TIME_H

#include "evplatform.h"

#if defined(WIN32) 
// Windows
#if defined(DEFINE_STRUCT_TM) 
struct tm 
{
    int tm_sec;   // seconds after the minute (0..59)
    int tm_min;   // minutes after the hour (0..59)
    int tm_hour;  // hours past midnight (0..23)
    int tm_mday;  // day of the month (1..31)
    int tm_mon;   // months since January (0..11)
    int tm_year;  // years since 1900 (0..)
    int tm_wday;  // days since Sunday (0..6)
    int tm_yday;  // days since January 1 (0..365)
	int tm_isdst; // daylight saving time (0:no,1:yes,-1:unknown)
};
#endif // defined(DEFINE_STRUCT_TM)
#else // defined(WIN32) 
// Unix
#include <time.h>
#endif // defined(WIN32)

#define INVALID_TIME ((time_t)-1)

#if defined(__cplusplus)
extern "C" {
#endif

#if defined(WIN32) 
// Windows
char *asctime(const struct tm *tm);
char *asctime_r(const struct tm *tm, char *buf);

char *ctime(const time_t *timep);
char *ctime_r(const time_t *timep, char *buf);

struct tm *gmtime(const time_t *timep);
struct tm *gmtime_r(const time_t *timep, struct tm *result);

struct tm *localtime(const time_t *timep);
struct tm *localtime_r(const time_t *timep, struct tm *result);

time_t mktime(struct tm *tm);
time_t time(time_t *t);

#else // defined(WIN32) 
// Unix
#endif // defined(WIN32)

#if defined(__cplusplus)
}
#endif

#endif // _EVPLATFORM_TIME_H
