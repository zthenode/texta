///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2014 $organization$
///
/// This software is provided by the author and contributors ``as is'' 
/// and any express or implied warranties, including, but not limited to, 
/// the implied warranties of merchantability and fitness for a particular 
/// purpose are disclaimed. In no event shall the author or contributors 
/// be liable for any direct, indirect, incidental, special, exemplary, 
/// or consequential damages (including, but not limited to, procurement 
/// of substitute goods or services; loss of use, data, or profits; or 
/// business interruption) however caused and on any theory of liability, 
/// whether in contract, strict liability, or tort (including negligence 
/// or otherwise) arising in any way out of the use of this software, 
/// even if advised of the possibility of such damage.
///
///   File: platform_defines.hpp
///
/// Author: $author$
///   Date: 8/17/2014, 2/20/2021
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_BASE_PLATFORM_DEFINES_HPP
#define _XOS_NADIR_XOS_BASE_PLATFORM_DEFINES_HPP

#include "xos/base/platform_includes.hpp"

#if defined(WINDOWS)
//
// Windows
// ...
#if !defined(__GNUC__)
//
// Visual C++
// ...
// ...
// Visual C++
//
#else // !defined(__GNUC__)
//
// Gcc
// ...
#if defined(CPLATFORM_DEFINED_DEBUG)
#warning Compiler other than Visual C++ (Gcc) being used
#endif // defined(CPLATFORM_DEFINED_DEBUG)
// ...
// Gcc
//
#endif // !defined(__GNUC__)

#if defined(UNICODE)
#define TCHAR_NOT_CHAR
#endif // defined(UNICODE)

#define PLATFORM_EXPORT __declspec(dllexport)
#define PLATFORM_IMPORT __declspec(dllimport)

#define FOREIGN_DIRECTORY_SEPARATOR_CHAR '/'
#define PLATFORM_DIRECTORY_SEPARATOR_CHAR '\\'
#define PLATFORM_VOLUME_SEPARATOR_CHAR ':'

#define NULL_HANDLE_VALUE NULL
#define NULL_ATOM_VALUE 0

#define INVALID_HANDLE INVALID_HANDLE_VALUE
#define NULL_HANDLE NULL_HANDLE_VALUE
#define NULL_ATOM NULL_ATOM_VALUE

#if !defined(DEBUG_BUILD)
#if defined(_DEBUG)
#define DEBUG_BUILD
#endif // defined(_DEBUG)
#endif // !defined(DEBUG_BUILD)
// ...
// Windows
//
#else // defined(WINDOWS)
//
// Unix
// ...
#if defined(__GNUC__)
//
// Gcc
// ...
// ...
// Gcc
//
#else // defined(__GNUC__)
#error Compiler other than Gcc not supported
#endif // defined(__GNUC__)

#define PLATFORM_EXPORT
#define PLATFORM_IMPORT

#define INFINITE -1

#if defined(unix)
#define PLATFORM_unix unix
#undef unix
#endif //

#if defined(MACOSX)
//
// MacOSX
// ...
#if !defined(PLATFORM_HAS_NO_EXECVPE)
#define PLATFORM_HAS_NO_EXECVPE
#endif // !defined(PLATFORM_HAS_NO_EXECVPE)
// ...
// MacOSX
//
#endif // defined(MACOSX)

#define FOREIGN_DIRECTORY_SEPARATOR_CHAR '\\'
#define PLATFORM_DIRECTORY_SEPARATOR_CHAR '/'
#define PLATFORM_VOLUME_SEPARATOR_CHAR 0
// ...
// Unix
//
#endif // defined(WINDOWS)

#if defined(__MSC__)
//
// Visual C++
// ...
#define PACKED_STRUCT
// ...
// Visual C++
//
#else // defined(__MSC__)
#if defined(__GNUC__)
//
// Gcc
// ...
#define PACKED_STRUCT __attribute__ ((packed))
// ...
// Gcc
//
#else // defined(__GNUC__)
#error Compiler not supported
#endif // defined(__GNUC__)
#endif // defined(__MSC__)

//
// Generic
// ...
#if !defined(exported)
#define exported PLATFORM_EXPORT
#endif // !defined(exported)

#define c_EXPORT PLATFORM_EXPORT
#define c_IMPORT PLATFORM_IMPORT

#define UNDEFINED -1

#define NULL_BYTE 0
#define NULL_CHAR 0
#define NULL_TCHAR 0
#define NULL_WCHAR 0

#define _PLATFORM_IMPORT PLATFORM_IMPORT
#define _PLATFORM_EXPORT PLATFORM_EXPORT

#define c_EXPORT_CLASS PLATFORM_EXPORT
#define c_INTERFACE_CLASS PLATFORM_EXPORT
#define c_IMPLEMENT_CLASS PLATFORM_EXPORT
#define c_INSTANCE_CLASS PLATFORM_EXPORT

#define _EXPORT_CLASS PLATFORM_EXPORT
#define _INTERFACE_CLASS PLATFORM_EXPORT
#define _IMPLEMENT_CLASS PLATFORM_EXPORT
#define _INSTANCE_CLASS PLATFORM_EXPORT

#define EXPORT_CLASS PLATFORM_EXPORT
#define INTERFACE_CLASS PLATFORM_EXPORT

#if !defined(NO_IMPLEMENT_CLASS)
#define IMPLEMENT_CLASS PLATFORM_EXPORT
#endif // !defined(NO_IMPLEMENT_CLASS)

#define INSTANCE_CLASS PLATFORM_EXPORT

#define _PACKED_STRUCT PACKED_STRUCT
#define c_PACKED_STRUCT PACKED_STRUCT

#if defined(DELETE)
#define PLATFORM_DELETE DELETE
#undef DELETE
#endif // defined(DELETE)

#define PLATFORM_EXTENSION_SEPARATOR "."
#define FOREIGN_EXTENSION_SEPARATOR PLATFORM_EXTENSION_SEPARATOR

#define PLATFORM_EXTENSION_SEPARATOR_CHAR '.'
#define FOREIGN_EXTENSION_SEPARATOR_CHAR PLATFORM_EXTENSION_SEPARATOR_CHAR
// ...
// Generic
//

namespace xos {
namespace base {

} // namespace base 
} // namespace xos 

#endif // _XOS_NADIR_XOS_BASE_PLATFORM_DEFINES_HPP 
