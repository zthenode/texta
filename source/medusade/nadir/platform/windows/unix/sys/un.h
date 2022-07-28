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
///   File: un.h
///
/// Author: $author$
///   Date: 9/29/2016
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_WINDOWS_UNIX_SYS_UN_H
#define _XOS_WINDOWS_UNIX_SYS_UN_H

#include "xos/base/platform.hpp"

#define AF_LOCAL AF_UNIX
#define PF_LOCAL PF_UNIX
#define sun_family sa_family

struct sockaddr_un: sockaddr {
    char sun_path[MAX_PATH];
};

namespace xos {
namespace windows {
namespace unix {
namespace sys {

} // namespace sys 
} // namespace unix 
} // namespace windows 
} // namespace xos 

#endif // _XOS_WINDOWS_UNIX_SYS_UN_H 
        

