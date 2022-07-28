///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2015 $organization$
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
///   File: file.hpp
///
/// Author: $author$
///   Date: 4/16/2015
///////////////////////////////////////////////////////////////////////
#ifndef _CORAL_IO_OS_FILE_HPP
#define _CORAL_IO_OS_FILE_HPP

#include "coral/io/os/os.hpp"

#if defined(WINDOWS)
// Windows
#include "xos/io/windows/file.hpp"
#else // defined(WINDOWS)
// Unix
#if defined(MACOSX)
// MacOSX
#include "xos/io/unix/file.hpp"
#else // defined(MACOSX)
// Otherwise
#include "xos/io/unix/file.hpp"
#endif // defined(MACOSX)
#endif // defined(WINDOWS)

namespace coral {
namespace io {
namespace os {

#if defined(WINDOWS)
// Windows
typedef xos::io::windows::fd_t fd_t;
#else // defined(WINDOWS)
// Unix
#if defined(MACOSX)
// MacOSX
typedef xos::io::unix::fd_t fd_t;
#else // defined(MACOSX)
// Otherwise
typedef xos::io::unix::fd_t fd_t;
#endif // defined(MACOSX)
#endif // defined(WINDOWS)

} // namespace os
} // namespace io
} // namespace coral 

#endif // _CORAL_IO_OS_FILE_HPP
