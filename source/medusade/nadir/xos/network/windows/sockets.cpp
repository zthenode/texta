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
///   File: sockets.cpp
///
/// Author: $author$
///   Date: 3/1/2015
///////////////////////////////////////////////////////////////////////
#include "xos/network/windows/sockets.hpp"

#if defined(WINSOCK_2)
#define WINSOCK_VERSION_MAJOR 2
#define WINSOCK_VERSION_MAJOR 2
#else // defined(WINSOCK_2)
#define WINSOCK_VERSION_MAJOR 1
#define WINSOCK_VERSION_MAJOR 1
#endif // defined(WINSOCK_2)

namespace xos {
namespace network {
namespace windows {
namespace sockets {

bool startup() {
    WORD wsaVersion = MAKEWORD(WINSOCK_VERSION_MAJOR, WINSOCK_VERSION_MAJOR);
    WSAData wsaData;
    int err;
    XOS_LOG_DEBUG("WSAStartup(" << wsaVersion << ", ...)...");
    if (!(err = WSAStartup(wsaVersion, &wsaData))) {
        XOS_LOG_DEBUG("...WSAStartup(" << wsaVersion << ", ...)");
        return true;
    } else {
        XOS_LOG_ERROR("failed " << WSAGetLastError() << " on WSAStartup(" << wsaVersion << ", ...)");
    }
    return false;
}
bool cleanup() {
    int err;
    XOS_LOG_DEBUG("WSACleanup()...");
    if (!(err = WSACleanup())) {
        XOS_LOG_DEBUG("...WSACleanup()");
        return true;
    } else {
        XOS_LOG_ERROR("failed " << WSAGetLastError() << " on WSACleanup()");
    }
    return false;
}

} // namespace sockets 
} // namespace windows 
} // namespace network 
} // namespace xos 
