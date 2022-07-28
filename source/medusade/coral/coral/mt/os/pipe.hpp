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
///   File: pipe.hpp
///
/// Author: $author$
///   Date: 2/3/2015
///////////////////////////////////////////////////////////////////////
#ifndef _CORAL_MT_OS_PIPE_HPP
#define _CORAL_MT_OS_PIPE_HPP

#include "coral/mt/os/os.hpp"

#if defined(WINDOWS)
// Windows
#include "xos/mt/windows/pipe.hpp"
#else // defined(WINDOWS)
// Unix
#if defined(MACOSX)
// MacOSX
#include "xos/mt/unix/pipe.hpp"
#else // defined(MACOSX)
// Otherwise
#include "xos/mt/unix/pipe.hpp"
#endif // defined(MACOSX)
#endif // defined(WINDOWS)

namespace coral {
namespace mt {
namespace os {

#if defined(WINDOWS)
// Windows
typedef xos::mt::windows::pipe pipe;
#else // defined(WINDOWS)
// Unix
#if defined(MACOSX)
// MacOSX
typedef xos::mt::unix::pipe pipe;
#else // defined(MACOSX)
// Otherwise
typedef xos::mt::unix::pipe pipe;
#endif // defined(MACOSX)
#endif // defined(WINDOWS)

} // namespace os
} // namespace mt 
} // namespace coral 

#endif // _CORAL_MT_OS_PIPE_HPP 
