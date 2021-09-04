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
 *   File: cplatform_file.c
 *
 * Author: $author$
 *   Date: 3/5/2008
 **********************************************************************
 */

#include "cplatform_file.h"

#if defined(WIN32) 
/* Windows
 */
#else /* defined(WIN32) */
/* Unix
 */
#endif /* defined(WIN32) */

#if !defined(cplatform_fclose) 
/**
 **********************************************************************
 * Function: cplatform_fclose
 *
 *   Author: $author$
 *     Date: 3/5/2008
 **********************************************************************
 */
int cplatform_fclose(FILE* fp)
{
    int err = fclose(fp);
    return err;
}
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
FILE* cplatform_fopen(const char *path, const char *mode)
{
    FILE* file = NULL;
#if defined(WIN32) && (MSC_VER > MSC_VER_6)
/* fopen deprecated for more secure version (fopen_s)
 */
    errno_t err;
    if ((err = fopen_s(&file, path, mode)))
        file = NULL;
#else /* defined(WIN32) && (MSC_VER > MSC_VER_6) */
    file = fopen(path, mode);
#endif /* defined(WIN32) && (MSC_VER > MSC_VER_6) */
    return file;
}
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
FILE* cplatform_fdopen(int fildes, const char *mode)
{
    FILE* file = NULL;
    return file;
}
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
(const char *path, const char *mode, FILE *stream)
{
    FILE* file = NULL;
    return file;
}
#endif /* !defined(cplatform_freopen) */
