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
 *   File: cplatform_stdio.h
 *
 * Author: $author$
 *   Date: 9/15/2011
 **********************************************************************
 */
#ifndef _CPLATFORM_STDIO_H
#define _CPLATFORM_STDIO_H

#include "cplatform.h"
#include <stdio.h>

#if !defined(CPLATFORM_STDIO_EXPORT) 
#define CPLATFORM_STDIO_EXPORT PLATFORM_IMPORT
#else /* !defined(CPLATFORM_STDIO_EXPORT) */
#endif /* !defined(CPLATFORM_STDIO_EXPORT) */

#if defined(WINDOWS) 
/* Windows
 */
#define CPLATFORM_FILE_MODE_BINARY "b"
#else /* defined(WINDOWS) */
/* Unix
 */
#define CPLATFORM_FILE_MODE_BINARY
#endif /* defined(WINDOWS) */

#define CPLATFORM_FILE_MODE_READ "r"
#define CPLATFORM_FILE_MODE_WRITE "w"

#define CPLATFORM_FILE_MODE_READ_BINARY \
        CPLATFORM_FILE_MODE_READ \
        CPLATFORM_FILE_MODE_BINARY
        
#define CPLATFORM_FILE_MODE_WRITE_BINARY \
        CPLATFORM_FILE_MODE_WRITE \
        CPLATFORM_FILE_MODE_BINARY
        
/**
 **********************************************************************
 *   Enum: eSeek
 *
 * Author: $author$
 *   Date: 3/13/2009
 **********************************************************************
 */
typedef int eSeek;
enum
{
    e_FIRST_SEEK = 0,

    e_SEEK_SET = e_FIRST_SEEK,
    e_SEEK_CUR,
    e_SEEK_END,

    e_NEXT_SEEK,
    e_LAST_SEEK = e_NEXT_SEEK-1,
    e_COUNT_SEEK = e_LAST_SEEK-e_FIRST_SEEK+1
};

#define e_SEEK_NAME_SET "SET"
#define e_SEEK_NAME_CUR "CUR"
#define e_SEEK_NAME_END "END"

#if defined(__cplusplus)
extern "C" {
#endif /* defined(__cplusplus) */

extern CPLATFORM_STDIO_EXPORT int g_e_seek_value[e_COUNT_SEEK];
extern CPLATFORM_STDIO_EXPORT const char* g_e_seek_name[e_COUNT_SEEK];

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

#endif /* _CPLATFORM_STDIO_H */
        

