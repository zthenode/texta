///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2017 $organization$
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
///   File: network.hpp
///
/// Author: $author$
///   Date: 6/4/2017
///////////////////////////////////////////////////////////////////////
#ifndef _MEDUSA_XOS_BASE_NETWORK_HPP
#define _MEDUSA_XOS_BASE_NETWORK_HPP

#include "medusa/xos/base/base.hpp"
#include "xos/network/os/sockets.hpp"
#include "xos/network/os/socket.hpp"
#include "xos/network/ip/v6/tcp/transport.hpp"
#include "xos/network/ip/v6/udp/transport.hpp"
#include "xos/network/ip/v6/endpoint.hpp"
#include "xos/network/ip/v4/tcp/transport.hpp"
#include "xos/network/ip/v4/udp/transport.hpp"
#include "xos/network/ip/v4/endpoint.hpp"

namespace medusa {
namespace network {

typedef xos::network::address address;
typedef xos::network::endpoint endpoint;
typedef xos::network::transport transport;

///////////////////////////////////////////////////////////////////////
/// ip
///////////////////////////////////////////////////////////////////////
namespace ip {

typedef xos::network::ip::address address;
typedef xos::network::ip::endpoint endpoint;
typedef xos::network::ip::transport transport;

///////////////////////////////////////////////////////////////////////
/// v4
///////////////////////////////////////////////////////////////////////
namespace v4 {

typedef xos::network::ip::v4::address address;
typedef xos::network::ip::v4::endpoint endpoint;

namespace tcp {

typedef xos::network::ip::v4::tcp::transport transport;

} // namespace tcp

namespace udp {

typedef xos::network::ip::v4::udp::transport transport;

} // namespace udp
} // namespace v4

///////////////////////////////////////////////////////////////////////
/// v6
///////////////////////////////////////////////////////////////////////
namespace v6 {

typedef xos::network::ip::v6::address address;
typedef xos::network::ip::v6::endpoint endpoint;

namespace tcp {

typedef xos::network::ip::v6::tcp::transport transport;

} // namespace tcp

namespace udp {

typedef xos::network::ip::v6::udp::transport transport;

} // namespace udp
} // namespace v6

} // namespace ip

///////////////////////////////////////////////////////////////////////
/// socket
///////////////////////////////////////////////////////////////////////
typedef xos::network::socket socket;

namespace os {

///////////////////////////////////////////////////////////////////////
/// socket
///////////////////////////////////////////////////////////////////////
typedef xos::network::os::socket socket;

} // namespace os

namespace sockets {

bool startup();
bool cleanup();

} // namespace sockets

} // namespace network
} // namespace medusa 

#endif // _MEDUSA_XOS_BASE_NETWORK_HPP 
