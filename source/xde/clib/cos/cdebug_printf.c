/**
 **********************************************************************
 * Copyright (c) 1988-2015 $organization$
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
 *   File: cdebug_printf.c
 *
 * Author: $author$
 *   Date: 1/22/2015
 **********************************************************************
 */
#include "cdebug_printf.h"

#if defined(CDEBUG_PRINTF)
#include <stdarg.h>
#if !defined(CDEBUG_VPRINTF)
#define CDEBUG_VPRINTF vprintf
#else /* !defined(CDEBUG_VPRINTF) */
#if !defined(CDEBUG_VFPRINTF)
#define CDEBUG_VFPRINTF vfprintf
#endif /* !defined(CDEBUG_VFPRINTF) */
int CDEBUG_VPRINTF(const char* format, va_list va) {
    int count = CDEBUG_VFPRINTF(stderr, format, va);
    return count;
}
#endif /* !defined(CDEBUG_VPRINTF) */
int CDEBUG_PRINTF(const char* format, ...) {
    int count = 0;
#if !defined(RELEASE_BUILD)
    va_list va;
    va_start(va, format);
    count = CDEBUG_VPRINTF(format, va);
    va_end(va);
#endif /* !defined(RELEASE_BUILD) */
    return count;
}
#else /* defined(CDEBUG_PRINTF) */
#endif /* defined(CDEBUG_PRINTF) */
