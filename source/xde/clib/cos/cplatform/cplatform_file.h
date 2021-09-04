/**
 **********************************************************************
 * Copyright (c) 1988-2008 $organization$
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
 *   File: cplatform_file.h
 *
 * Author: $author$
 *   Date: 3/5/2008
 **********************************************************************
 */
#ifndef _CPLATFORM_FILE_H
#define _CPLATFORM_FILE_H

#include "cplatform.h"
#include <stdio.h>

#define FILE_MODE_READ "r"
#define FILE_MODE_WRITE "w"

#define INVALID_FILEP NULL
typedef FILE* FILEP;

#if defined(WIN32) 
/* Windows
 */
#else /* defined(WIN32) */
/* Unix
 */
#endif /* defined(WIN32) */

#if defined(__cplusplus)
extern "C" {
#endif /* defined(__cplusplus) */

#if defined(WIN32) 
/* Windows
 */
#if defined(WIN32_MSC_VER_6) 
/* Visual C++ 6.0 
 */
#define cplatform_fopen fopen
#endif /* defined(WIN32_MSC_VER_6) */
#else /* defined(WIN32) */
/* Unix
 */
#define cplatform_fopen fopen
#endif /* defined(WIN32) */

#define cplatform_fclose fclose
#define cplatform_fread fread
#define cplatform_fwrite fwrite

#if !defined(cplatform_fread) 
/**
 **********************************************************************
 * Function: cplatform_fread
 *
 *   Author: $author$
 *     Date: 3/5/2008
 **********************************************************************
 */
size_t cplatform_fread
(void *ptr, size_t size, size_t count, FILE *stream);
#endif /* !defined(cplatform_fread) */

#if !defined(cplatform_fwrite) 
/**
 **********************************************************************
 * Function: cplatform_fwrite
 *
 *   Author: $author$
 *     Date: 3/5/2008
 **********************************************************************
 */
size_t cplatform_fwrite
(const void *ptr, size_t size, size_t count, FILE *stream);
#endif /* !defined(cplatform_fwrite) */

#if !defined(cplatform_fclose) 
/**
 **********************************************************************
 * Function: cplatform_fclose
 *
 *   Author: $author$
 *     Date: 3/5/2008
 **********************************************************************
 */
int cplatform_fclose(FILE* fp);
#endif /* !defined(cplatform_fclose) */

#if !defined(cplatform_fopen) 
/**
 **********************************************************************
 * Function: cplatform_fopen
 *
 *   Author: $author$
 *     Date: 3/5/2008
 **********************************************************************
 */
FILE* cplatform_fopen(const char *path, const char *mode);
#endif /* !defined(cplatform_fopen) */

#if !defined(cplatform_fdopen) 
/**
 **********************************************************************
 * Function: cplatform_fdopen
 *
 *   Author: $author$
 *     Date: 3/5/2008
 **********************************************************************
 */
FILE* cplatform_fdopen(int fildes, const char *mode);
#endif /* !defined(cplatform_fdopen) */

#if !defined(cplatform_freopen) 
/**
 **********************************************************************
 * Function: cplatform_freopen
 *
 *   Author: $author$
 *     Date: 3/5/2008
 **********************************************************************
 */
FILE* cplatform_freopen
(const char *path, const char *mode, FILE *stream);
#endif /* !defined(cplatform_freopen) */

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /* _CPLATFORM_FILE_H */
