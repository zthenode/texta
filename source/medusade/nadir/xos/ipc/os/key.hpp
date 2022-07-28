///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2016 $organization$
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
///   File: key.hpp
///
/// Author: $author$
///   Date: 8/15/2016
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_IPC_OS_KEY_HPP
#define _XOS_NADIR_XOS_IPC_OS_KEY_HPP

#include "xos/ipc/os/os.hpp"

#if defined(WINDOWS)
// Windows
#include "xos/ipc/windows/key.hpp"
#elif defined(MACOSX)
// MacOSX
#include "xos/ipc/macosx/key.hpp"
#else // defined(WINDOWS)
// Unix
#include "xos/ipc/unix/key.hpp"
#endif // defined(WINDOWS)

namespace xos {
namespace ipc {
namespace os {

typedef os::key key;

} // namespace os
} // namespace ipc 
} // namespace xos 

#endif // _XOS_NADIR_XOS_IPC_OS_KEY_HPP 
