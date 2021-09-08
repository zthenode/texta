///////////////////////////////////////////////////////////////////////
//   File: evplatform_directory.h
//
// Author: $author$
//   Date: 5/3/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _PLATFORM_DIRECTORY_H
#define _PLATFORM_DIRECTORY_H

#include "evplatform_path.h"
#include "evplatform_stat.h"

#if defined(WIN32) 
// Windows
#include <direct.h>
typedef HANDLE DIRECTORY;
typedef DIRECTORY INVALID_DIRECTORY_T;
#define mkdir(path, mode) _mkdir(path)
#define getcwd(buf, size) _getcwd(buf, size)
#else // defined(WIN32) 
// Unix
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
typedef DIR* DIRECTORY;
typedef unsigned INVALID_DIRECTORY_T;
#endif // defined(WIN32)

#define DIRECTORY_WILDCARD_CHAR '*'
#define CURRENT_DIRECTORY_NAME "."
#define PARENT_DIRECTORY_NAME ".."

#define INVALID_DIRECTORY_VALUE ((INVALID_DIRECTORY_T)0)
#define INVALID_DIRECTORY ((DIRECTORY)INVALID_DIRECTORY_VALUE)

#if defined(__cplusplus)
extern "C" {
#endif

#if defined(__cplusplus)
}
#endif

#endif // _PLATFORM_DIRECTORY_H
