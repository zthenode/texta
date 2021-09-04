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
 *   File: cplatform_io.h
 *
 * Author: $author$
 *   Date: 1/4/2008
 **********************************************************************
 */
#ifndef _CPLATFORM_IO_H
#define _CPLATFORM_IO_H

#include "cplatform.h"
#include "cerror.h"

#if defined(WIN32) 
/* Windows
 */
#if !defined(WIN32_WCE) 
#include <sys/stat.h>
#include <fcntl.h>
#include <io.h>
#endif /* !defined(WIN32_WCE) */

/* Windows oflags
 */
#if defined(WIN32_WCE) 
/* WindowsCE
 */
#define IO_O_APPEND     0    
#define IO_O_BINARY     0    
#define IO_O_CREAT      0     
#define IO_O_EXCL       0      
#define IO_O_NONBLOCK   0  
#define IO_O_RANDOM     0    
#define IO_O_RDONLY     0    
#define IO_O_RDWR       0      
#define IO_O_SEQUENTIAL 0
#define IO_O_SYNC       0      
#define IO_O_TEMPORARY  0 
#define IO_O_TEXT       0      
#define IO_O_TRUNC      0     
#define IO_O_WRONLY     0    
#else /* defined(WIN32_WCE) */
/* Windows
 */
#define IO_O_APPEND     _O_APPEND    
#define IO_O_BINARY     _O_BINARY    
#define IO_O_CREAT      _O_CREAT     
#define IO_O_EXCL       _O_EXCL      
#define IO_O_NONBLOCK   0  
#define IO_O_RANDOM     _O_RANDOM    
#define IO_O_RDONLY     _O_RDONLY    
#define IO_O_RDWR       _O_RDWR      
#define IO_O_SEQUENTIAL _O_SEQUENTIAL
#define IO_O_SYNC       0      
#define IO_O_TEMPORARY  _O_TEMPORARY 
#define IO_O_TEXT       _O_TEXT      
#define IO_O_TRUNC      _O_TRUNC     
#define IO_O_WRONLY     _O_WRONLY    
#endif /* defined(WIN32_WCE) */

#define HAS_IO_O_APPEND     1    
#define HAS_IO_O_BINARY     1   
#define HAS_IO_O_CREAT      1    
#define HAS_IO_O_EXCL       1     
#define HAS_IO_O_NONBLOCK   0  
#define HAS_IO_O_RANDOM     1   
#define HAS_IO_O_RDONLY     1    
#define HAS_IO_O_RDWR       1     
#define HAS_IO_O_SEQUENTIAL 1
#define HAS_IO_O_SYNC       0      
#define HAS_IO_O_TEMPORARY  1
#define HAS_IO_O_TEXT       1      
#define HAS_IO_O_TRUNC      1  
#define HAS_IO_O_WRONLY     1   

/* Windows omodes
 */
#if defined(WIN32_WCE) 
/* WindowsCE
 */
#define IO_S_IREAD  0 
#define IO_S_IWRITE 0
#define IO_S_IEXEC  0
#define IO_S_IRUSR  0 
#define IO_S_IWUSR  0
#else /* defined(WIN32_WCE) */
/* Windows
 */
#define IO_S_IREAD  _S_IREAD 
#define IO_S_IWRITE _S_IWRITE
#define IO_S_IEXEC  0
#define IO_S_IRUSR  _S_IREAD 
#define IO_S_IWUSR  _S_IWRITE
#endif /* defined(WIN32_WCE) */

#define IO_S_IXUSR  0
#define IO_S_IRGRP  0
#define IO_S_IWGRP  0
#define IO_S_IXGRP  0
#define IO_S_IROTH  0
#define IO_S_IWOTH  0
#define IO_S_IXOTH  0
#define IO_S_IRWXU  0
#define IO_S_IRWXG  0
#define IO_S_IRWXO  0

#define HAS_IO_S_IREAD  1
#define HAS_IO_S_IWRITE 1
#define HAS_IO_S_IEXEC  1
#define HAS_IO_S_IRUSR  1
#define HAS_IO_S_IWUSR  1
#define HAS_IO_S_IXUSR  1
#define HAS_IO_S_IRGRP  0
#define HAS_IO_S_IWGRP  0
#define HAS_IO_S_IXGRP  0
#define HAS_IO_S_IROTH  0
#define HAS_IO_S_IWOTH  0
#define HAS_IO_S_IXOTH  0
#define HAS_IO_S_IRWXU  0
#define HAS_IO_S_IRWXG  0
#define HAS_IO_S_IRWXO  0

#else /* defined(WIN32) */
/* Unix
 */
#include <sys/stat.h>
#include <fcntl.h>
/* Unix oflags
 */
#define IO_O_APPEND     O_APPEND    
#define IO_O_BINARY     0    
#define IO_O_CREAT      O_CREAT     
#define IO_O_EXCL       O_EXCL      
#define IO_O_NONBLOCK   O_NONBLOCK  
#define IO_O_RANDOM     0    
#define IO_O_RDONLY     O_RDONLY    
#define IO_O_RDWR       O_RDWR      
#define IO_O_SEQUENTIAL 0
#define IO_O_SYNC       O_SYNC      
#define IO_O_TEMPORARY  0
#define IO_O_TEXT       0      
#define IO_O_TRUNC      O_TRUNC     
#define IO_O_WRONLY     O_WRONLY    

#define HAS_IO_O_APPEND     1    
#define HAS_IO_O_BINARY     0   
#define HAS_IO_O_CREAT      1    
#define HAS_IO_O_EXCL       1     
#define HAS_IO_O_NONBLOCK   1  
#define HAS_IO_O_RANDOM     0   
#define HAS_IO_O_RDONLY     1    
#define HAS_IO_O_RDWR       1     
#define HAS_IO_O_SEQUENTIAL 0
#define HAS_IO_O_SYNC       1      
#define HAS_IO_O_TEMPORARY  0
#define HAS_IO_O_TEXT       0      
#define HAS_IO_O_TRUNC      1  
#define HAS_IO_O_WRONLY     1   

/* Unix omodes
 */
#define IO_S_IREAD  S_IREAD 
#define IO_S_IWRITE S_IWRITE
#define IO_S_IEXEC  S_IEXEC 
#define IO_S_IRUSR  S_IRUSR 
#define IO_S_IWUSR  S_IWUSR 
#define IO_S_IXUSR  S_IXUSR 
#define IO_S_IRGRP  S_IRGRP 
#define IO_S_IWGRP  S_IWGRP 
#define IO_S_IXGRP  S_IXGRP 
#define IO_S_IROTH  S_IROTH 
#define IO_S_IWOTH  S_IWOTH 
#define IO_S_IXOTH  S_IXOTH 
#define IO_S_IRWXU  S_IRWXU 
#define IO_S_IRWXG  S_IRWXG 
#define IO_S_IRWXO  S_IRWXO 

#define HAS_IO_S_IREAD  1
#define HAS_IO_S_IWRITE 1
#define HAS_IO_S_IEXEC  1
#define HAS_IO_S_IRUSR  1
#define HAS_IO_S_IWUSR  1
#define HAS_IO_S_IXUSR  1
#define HAS_IO_S_IRGRP  1
#define HAS_IO_S_IWGRP  1
#define HAS_IO_S_IXGRP  1
#define HAS_IO_S_IROTH  1
#define HAS_IO_S_IWOTH  1
#define HAS_IO_S_IXOTH  1
#define HAS_IO_S_IRWXU  1
#define HAS_IO_S_IRWXG  1
#define HAS_IO_S_IRWXO  1

#endif /* defined(WIN32) */

#define IO_SEEK_SET SEEK_SET 
#define IO_SEEK_CUR SEEK_CUR 
#define IO_SEEK_END SEEK_END 

/**
 **********************************************************************
 * Typedef: eOMode
 *
 *  Author: $author$
 *    Date: 1/5/2008
 **********************************************************************
 */
typedef int
eOMode;

/**
 **********************************************************************
 * Enum: 
 *
 * Author: $author$
 * Date:   7/1/2003
 **********************************************************************
 */
enum
{
    e_O_APPEND      = 0x0001,
    e_O_BINARY      = 0x0002,
    e_O_CREAT       = 0x0004,
    e_O_EXCL        = 0x0008,
    e_O_NONBLOCK    = 0x0010,
    e_O_RANDOM      = 0x0020,
    e_O_RDONLY      = 0x0040,
    e_O_RDWR        = 0x0080,
    e_O_SEQUENTIAL  = 0x0100,
    e_O_SYNC        = 0x0200,
    e_O_TEMPORARY   = 0x0400,
    e_O_TEXT        = 0x0800,
    e_O_TRUNC       = 0x1000,
    e_O_WRONLY      = 0x2000,

    e_FIRST_O       = e_O_APPEND,
    e_LAST_O        = e_O_WRONLY 
};

/**
 **********************************************************************
 * Typedef: eSMode
 *
 *  Author: $author$
 *    Date: 1/5/2008
 **********************************************************************
 */
typedef int
eSMode;

/**
 **********************************************************************
 * Enum: 
 *
 * Author: $author$
 * Date:   7/1/2003
 **********************************************************************
 */
enum
{
    e_S_IREAD  = 00400,
    e_S_IWRITE = 00200,
    e_S_IEXEC  = 00100,
    e_S_IRUSR  = 00400,
    e_S_IWUSR  = 00200,
    e_S_IXUSR  = 00100,
    e_S_IRGRP  = 00040,
    e_S_IWGRP  = 00020,
    e_S_IXGRP  = 00010,
    e_S_IROTH  = 00004,
    e_S_IWOTH  = 00002,
    e_S_IXOTH  = 00001,
    e_S_IRWXU  = 00700,
    e_S_IRWXG  = 00070,
    e_S_IRWXO  = 00007,

    e_FIRST_S  = e_S_IXOTH,
    e_LAST_S   = e_S_IRUSR
};

/**
 **********************************************************************
 * Typedef: eIoMode
 *
 *  Author: $author$
 *    Date: 1/5/2008
 **********************************************************************
 */
typedef int
eIoMode;

#if defined(__cplusplus)
extern "C" {
#endif /* defined(__cplusplus) */

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /* _CPLATFORM_IO_H */
