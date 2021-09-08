///////////////////////////////////////////////////////////////////////
//   File: evplatform_file.h
//
// Author: $author$
//   Date: 5/17/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _EVPLATFORM_FILE_H
#define _EVPLATFORM_FILE_H

#include <stdio.h>
#include "evplatform.h"

#if defined(WIN32) 
// Windows
#include <io.h>
#include <fcntl.h>
typedef FILE* INVALID_FILE_T;
#define INVALID_FILE 0
#else // defined(WIN32) 
// Unix
typedef unsigned INVALID_FILE_T;
#define INVALID_FILE 0
#endif // defined(WIN32)

#define FOPEN_MODE_READ "r"
#define FOPEN_MODE_WRITE "w"

#define FOPEN_MODE_TEXT
#define FOPEN_MODE_READ_TEXT FOPEN_MODE_READ
#define FOPEN_MODE_WRITE_TEXT FOPEN_MODE_WRITE

#if defined(WIN32) 
// Windows
#define FOPEN_MODE_BINARY "b"
#define FOPEN_MODE_READ_BINARY FOPEN_MODE_READ FOPEN_MODE_BINARY
#define FOPEN_MODE_WRITE_BINARY FOPEN_MODE_WRITE FOPEN_MODE_BINARY
#else // defined(WIN32) 
// Unix
#define FOPEN_MODE_BINARY
#define FOPEN_MODE_READ_BINARY FOPEN_MODE_READ
#define FOPEN_MODE_WRITE_BINARY FOPEN_MODE_WRITE
#endif // defined(WIN32)

#if defined(__cplusplus)
extern "C" {
#endif

#if defined(__cplusplus)
}
#endif

#endif // _EVPLATFORM_FILE_H
