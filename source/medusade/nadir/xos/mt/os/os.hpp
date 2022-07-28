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
///   File: os.hpp
///
/// Author: $author$
///   Date: 10/30/2014
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_MT_OS_OS_HPP
#define _XOS_NADIR_XOS_MT_OS_OS_HPP

#include "xos/base/base.hpp"

namespace xos {
namespace mt {
namespace apple { namespace mach {} namespace osx {} namespace ios {} }
namespace microsoft { namespace windows { namespace crt {} } }
namespace posix { }
namespace macosx { namespace crt {} }
namespace windows { namespace crt {} }
namespace unix { namespace crt {} }
namespace os {

#if defined(WINDOWS)
// Windows
namespace os = windows;
#elif defined(MACOSX)
// MacOSX
namespace os = macosx;
#else // defined(WINDOWS)
// Unix
namespace os = unix;
#endif // defined(WINDOWS)

} // namespace os
} // namespace mt 
} // namespace xos 

#endif // _XOS_NADIR_XOS_MT_OS_OS_HPP 
