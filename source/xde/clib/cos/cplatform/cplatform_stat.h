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
 *   File: cplatform_stat.h
 *
 * Author: $author$
 *   Date: 9/11/2008
 **********************************************************************
 */
#ifndef _CPLATFORM_STAT_H
#define _CPLATFORM_STAT_H

#include "cplatform.h"

#if defined(WIN32) 
/* Windows
 */
#include <sys/types.h>
#include <sys/stat.h>

#if defined(CPLATFORM_STAT) 
struct _stat {
        _dev_t     st_dev;
        _ino_t     st_ino;
        unsigned short st_mode;
        short      st_nlink;
        short      st_uid;
        short      st_gid;
        _dev_t     st_rdev;
        _off_t     st_size;
        time_t st_atime;
        time_t st_mtime;
        time_t st_ctime;
        };
#endif /* defined(CPLATFORM_STAT) */
#else /* defined(WIN32) */
/* Unix
 */
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#if defined(CPLATFORM_STAT) 
struct stat {
    dev_t    st_dev;        /* ID of device containing file */
    ino_t    st_ino;        /* inode number */
    mode_t    st_mode;    /* protection */
    nlink_t    st_nlink;   /* number of hard links */
    uid_t    st_uid;        /* user ID of owner */
    gid_t    st_gid;        /* group ID of owner */
    dev_t    st_rdev;    /* device ID (if special file) */
    off_t    st_size;    /* total size, in bytes */
    blksize_t st_blksize; /* blocksize for filesystem I/O */
    blkcnt_t    st_blocks;  /* number of blocks allocated */
    time_t    st_atime;   /* time of last access */
    time_t    st_mtime;   /* time of last modification */
    time_t    st_ctime;   /* time of last status change */
};
#endif /* defined(CPLATFORM_STAT) */
#endif /* defined(WIN32) */

#if defined(__cplusplus)
extern "C" {
#endif /* defined(__cplusplus) */

#if defined(WIN32) 
/* Windows
 */
#if defined(CPLATFORM_STAT) 
int _stat(const char *path, struct _stat *buffer);
int _fstat(int fd, struct _stat *buffer);
int _wstat(const wchar_t *path, struct _stat *buffer);
#endif /* defined(CPLATFORM_STAT) */
#else /* defined(WIN32) */
/* Unix
 */
#if defined(CPLATFORM_STAT) 
int stat(const char *path, struct stat *buf);
int fstat(int filedes, struct stat *buf);
int lstat(const char *path, struct stat *buf);
#endif /* defined(CPLATFORM_STAT) */
#endif /* defined(WIN32) */

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /* _CPLATFORM_STAT_H */
