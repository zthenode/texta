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
///   File: os.hpp
///
/// Author: $author$
///   Date: 2/3/2015
///////////////////////////////////////////////////////////////////////
#ifndef _CORAL_MT_OS_OS_HPP
#define _CORAL_MT_OS_OS_HPP

#include "coral/base/base.hpp"

namespace coral {
namespace mt {
namespace windows {}
namespace unix {}
namespace macosx {}
namespace os {

#if defined(WINDOWS)
// Windows
namespace os = windows;
#else // defined(WINDOWS)
// Unix
#if defined(MACOSX)
// MacOSX
namespace os = macosx;
#else // defined(MACOSX)
// Otherwise
namespace os = unix;
#endif // defined(MACOSX)
#endif // defined(WINDOWS)

} // namespace os
} // namespace mt 
} // namespace coral 

#endif // _CORAL_MT_OS_OS_HPP 
