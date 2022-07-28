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
///   File: fs.hpp
///
/// Author: $author$
///   Date: 3/19/2015
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_OS_FS_HPP
#define _XOS_NADIR_XOS_OS_FS_HPP

#include "xos/os/os.hpp"

namespace xos {
namespace os {

namespace windows { namespace fs {} }
namespace macosx { namespace fs {} }
namespace unix { namespace fs {} }

namespace fs = os::fs;

} // namespace os 
} // namespace xos 

#endif // _XOS_NADIR_XOS_OS_FS_HPP 
