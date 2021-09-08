///////////////////////////////////////////////////////////////////////
//   File: evplatform_path.h
//
// Author: $author$
//   Date: 5/18/2008
///////////////////////////////////////////////////////////////////////
#ifndef _EVPLATFORM_PATH_H
#define _EVPLATFORM_PATH_H

#if defined(WIN32) 
// Windows 
#define FOREIGN_DIRECTORY_SEPARATOR_CHAR '/'
#define NATIVE_DIRECTORY_SEPARATOR_CHAR '\\'
#define NORMAL_DIRECTORY_SEPARATOR_CHAR FOREIGN_DIRECTORY_SEPARATOR_CHAR
#define DIRECTORY_SEPARATOR_CHAR NATIVE_DIRECTORY_SEPARATOR_CHAR
#define VOLUME_SEPARATOR_CHAR ':'
#else // defined(WIN32) 
// Unix 
#define FOREIGN_DIRECTORY_SEPARATOR_CHAR '\\'
#define NATIVE_DIRECTORY_SEPARATOR_CHAR '/'
#define NORMAL_DIRECTORY_SEPARATOR_CHAR NATIVE_DIRECTORY_SEPARATOR_CHAR
#define DIRECTORY_SEPARATOR_CHAR NATIVE_DIRECTORY_SEPARATOR_CHAR
#define VOLUME_SEPARATOR_CHAR DIRECTORY_SEPARATOR_CHAR
#endif // defined(WIN32) 

#define EXTENSION_SEPARATOR_CHAR '.'

#if defined(__cplusplus)
extern "C" {
#endif

#if defined(__cplusplus)
}
#endif

#endif // _EVPLATFORM_PATH_H 
