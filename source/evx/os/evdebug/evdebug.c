///////////////////////////////////////////////////////////////////////
//   File: evdebug.c
//
// Author: $author$
//   Date: 11/29/2019
//
//    $Id$
///////////////////////////////////////////////////////////////////////
#define EV_DEBUG_EXPORT
#include "evdebug.h"
#undef EV_DEBUG_EXPORT

EvDebugLevels g_evDebugLevels = DEFAULT_EV_DEBUG_LEVELS_VALUE;

int EvDebugPrintFormatted(const char* format, ...) {
    int count = 0;
    va_list va;
    va_start(va, format);
    count = EvDebugPrintFormattedV(format, va);
    va_end(va);
    return count;
}

int EvDebugPrintFormattedV(const char* format, va_list va) {
    int count = 0;
    if ((format)) {
        if (0 < (count = vfprintf(stderr, format, va))) {
            fflush(stderr);
        }
    }
    return count;
}
