///////////////////////////////////////////////////////////////////////
//   File: evdebug.h
//
// Author: $author$
//   Date: 11/29/2019
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _EVDEBUG_H
#define _EVDEBUG_H

#include "evplatform.h"
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

#if defined(WIN32) 
//
// Windows
//
#define DB_FUNCTION __FUNCTION__
#define CDB_FUNCTION (strrchr(__FUNCTION__,':')?(strrchr(__FUNCTION__,':')+1):(__FUNCTION__))
#else // defined(WIN32) 
//
// Unix
//
#if defined(DB_USE_PRETTY_FUNCTION)
#define DB_FUNCTION __PRETTY_FUNCTION__
#else
#define DB_FUNCTION __FUNCTION__
#endif // defined(DB_USE_PRETTY_FUNCTION)
#define CDB_FUNCTION __FUNCTION__
#endif // defined(WIN32)

enum
{
    EV_DEBUG_LEVELS_NONE  = 0,

    EV_DEBUG_LEVELS_ERROR, 
    EV_DEBUG_LEVELS_WARN, 
    EV_DEBUG_LEVELS_INFO, 
    EV_DEBUG_LEVELS_FUNC,
    EV_DEBUG_LEVELS_TRACE,

	EV_DEBUG_LEVELS_NEXT,
	EV_DEBUG_LEVELS  = (EV_DEBUG_LEVELS_NEXT - 1)
};

enum
{
    EV_DEBUG_LEVEL_NONE  = 0, 

    EV_DEBUG_LEVEL_ERROR = (1 << (EV_DEBUG_LEVELS_ERROR-1)), 
    EV_DEBUG_LEVEL_WARN  = (1 << (EV_DEBUG_LEVELS_WARN-1)), 
    EV_DEBUG_LEVEL_INFO  = (1 << (EV_DEBUG_LEVELS_INFO-1)), 
    EV_DEBUG_LEVEL_FUNC  = (1 << (EV_DEBUG_LEVELS_FUNC-1)),
    EV_DEBUG_LEVEL_TRACE = (1 << (EV_DEBUG_LEVELS_TRACE-1)),

	EV_NEXT_DEBUG_LEVEL  = (1 << (EV_DEBUG_LEVELS_NEXT-1)),
	EV_ALL_DEBUG_LEVELS  = (EV_NEXT_DEBUG_LEVEL - 1)
};

#if !defined(DEFAULT_EV_DEBUG_LEVELS_VALUE)
#if defined(DEFAULT_EV_DEBUG_LEVEL_ERROR)
#define DEFAULT_EV_DEBUG_LEVELS_VALUE EV_DEBUG_LEVEL_ERROR
#endif // defined(DEFAULT_EV_DEBUG_LEVEL_ERROR)
#endif // !defined(DEFAULT_EV_DEBUG_LEVELS_VALUE)

#if !defined(DEFAULT_EV_DEBUG_LEVELS_VALUE)
#define DEFAULT_EV_DEBUG_LEVELS_VALUE EV_ALL_DEBUG_LEVELS
#endif // !defined(DEFAULT_EV_DEBUG_LEVELS_VALUE)

#define DEFAULT_EV_DEBUG_LEVELS EV_DEBUG_LEVELS

#define EV_DEBUG_LEVEL_ERROR_NAME "error: "
#define EV_DEBUG_LEVEL_WARN_NAME "warning: "
#define EV_DEBUG_LEVEL_INFO_NAME ""
#define EV_DEBUG_LEVEL_FUNC_NAME ""
#define EV_DEBUG_LEVEL_TRACE_NAME ""

#define GET_EV_DEBUG_LEVELS() g_evDebugLevels
#define SET_EV_DEBUG_LEVELS(n) g_evDebugLevels = ((1 << n) - 1)
#define IS_EV_DEBUGL(level) (g_evDebugLevels & level)
#define EV_DEBUGL(level,type) ((g_evDebugLevels & level) && EvDebugPrintFormatted("%s:%d: %s", __FILE__, __LINE__, type))

#define IS_DBE IS_EV_DEBUGL(EV_DEBUG_LEVEL_ERROR)
#define IS_DBW IS_EV_DEBUGL(EV_DEBUG_LEVEL_WARN)
#define IS_DBI IS_EV_DEBUGL(EV_DEBUG_LEVEL_INFO)
#define IS_DBF IS_EV_DEBUGL(EV_DEBUG_LEVEL_FUNC)
#define IS_DBT IS_EV_DEBUGL(EV_DEBUG_LEVEL_TRACE)

#define DBE EV_DEBUGL(EV_DEBUG_LEVEL_ERROR, EV_DEBUG_LEVEL_ERROR_NAME) && (EvDebugPrintFormatted("%s", DB_FUNCTION)||1) && EvDebugPrintFormatted
#define DBW EV_DEBUGL(EV_DEBUG_LEVEL_WARN, EV_DEBUG_LEVEL_WARN_NAME) && (EvDebugPrintFormatted("%s", DB_FUNCTION)||1) && EvDebugPrintFormatted
#define DBI EV_DEBUGL(EV_DEBUG_LEVEL_INFO, EV_DEBUG_LEVEL_INFO_NAME) && (EvDebugPrintFormatted("%s", DB_FUNCTION)||1) && EvDebugPrintFormatted
#define DBF EV_DEBUGL(EV_DEBUG_LEVEL_FUNC, EV_DEBUG_LEVEL_FUNC_NAME) && (EvDebugPrintFormatted("%s", DB_FUNCTION)||1) && EvDebugPrintFormatted
#define DBT EV_DEBUGL(EV_DEBUG_LEVEL_TRACE, EV_DEBUG_LEVEL_TRACE_NAME) && (EvDebugPrintFormatted("%s", DB_FUNCTION)||1) && EvDebugPrintFormatted

#define CDBE EV_DEBUGL(EV_DEBUG_LEVEL_ERROR, EV_DEBUG_LEVEL_ERROR_NAME) && (EvDebugPrintFormatted(" %s::%s", CDB_CLASS, CDB_FUNCTION)||1) && EvDebugPrintFormatted
#define CDBW EV_DEBUGL(EV_DEBUG_LEVEL_WARN, EV_DEBUG_LEVEL_WARN_NAME) && (EvDebugPrintFormatted(" %s::%s", CDB_CLASS, CDB_FUNCTION)||1) && EvDebugPrintFormatted
#define CDBI EV_DEBUGL(EV_DEBUG_LEVEL_INFO, EV_DEBUG_LEVEL_INFO_NAME) && (EvDebugPrintFormatted(" %s::%s", CDB_CLASS, CDB_FUNCTION)||1) && EvDebugPrintFormatted
#define CDBF EV_DEBUGL(EV_DEBUG_LEVEL_FUNC, EV_DEBUG_LEVEL_FUNC_NAME) && (EvDebugPrintFormatted(" %s::%s", CDB_CLASS, CDB_FUNCTION)||1) && EvDebugPrintFormatted
#define CDBT EV_DEBUGL(EV_DEBUG_LEVEL_TRACE, EV_DEBUG_LEVEL_TRACE_NAME) && (EvDebugPrintFormatted(" %s::%s", CDB_CLASS, CDB_FUNCTION)||1) && EvDebugPrintFormatted

typedef int EvDebugLevels;

#if defined(__cplusplus)
extern "C" {
#endif

#if defined(EV_DEBUG_EXPORT) 
EV_PLATFORM_EXPORT extern
#else // defined(EV_DEBUG_EXPORT) 
EV_PLATFORM_IMPORT extern
#endif // defined(EV_DEBUG_EXPORT)
EvDebugLevels g_evDebugLevels;

#if defined(EV_DEBUG_EXPORT) 
EV_PLATFORM_EXPORT extern
#else // defined(EV_DEBUG_EXPORT) 
EV_PLATFORM_IMPORT extern
#endif // defined(EV_DEBUG_EXPORT)
int EvDebugPrintFormatted(const char* format, ...);

#if defined(EV_DEBUG_EXPORT) 
EV_PLATFORM_EXPORT extern
#else // defined(EV_DEBUG_EXPORT) 
EV_PLATFORM_IMPORT extern
#endif // defined(EV_DEBUG_EXPORT)
int EvDebugPrintFormattedV(const char* format, va_list va);

#if defined(__cplusplus)
}
#endif

#endif // _EVDEBUG_H
