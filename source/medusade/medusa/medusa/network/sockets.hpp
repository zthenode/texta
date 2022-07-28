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
///   File: sockets.hpp
///
/// Author: $author$
///   Date: 12/27/2017
///////////////////////////////////////////////////////////////////////
#ifndef _MEDUSA_NETWORK_SOCKETS_HPP
#define _MEDUSA_NETWORK_SOCKETS_HPP

#include "medusa/network/sockets/connection.hpp"
#include "medusa/network/sockets/endpoint.hpp"
#include "medusa/network/sockets/location.hpp"
#include "medusa/network/socket.hpp"
#include "medusa/io/logger.hpp"

namespace medusa {
namespace network {

///////////////////////////////////////////////////////////////////////
/// ip
///////////////////////////////////////////////////////////////////////
namespace ip {

typedef network::sockets::ip::location::Implements location_implements;
typedef network::sockets::ip::location location;

typedef sockets::ip::endpoint::Implements endpoint_implements;
typedef sockets::ip::endpoint endpoint;

///////////////////////////////////////////////////////////////////////
/// v4
///////////////////////////////////////////////////////////////////////
namespace v4 {

typedef network::sockets::ip::v4::location::Implements location_implements;
typedef network::sockets::ip::v4::location location;

typedef sockets::ip::v4::endpoint::Implements endpoint_implements;
typedef sockets::ip::v4::endpoint endpoint;

} // namespace v4

///////////////////////////////////////////////////////////////////////
/// v6
///////////////////////////////////////////////////////////////////////
namespace v6 {

typedef network::sockets::ip::v6::location::Implements location_implements;
typedef network::sockets::ip::v6::location location;

typedef sockets::ip::v6::endpoint::Implements endpoint_implements;
typedef sockets::ip::v6::endpoint endpoint;

} // namespace v6

} // namespace ip

///////////////////////////////////////////////////////////////////////
/// sockets
///////////////////////////////////////////////////////////////////////
namespace sockets {

inline bool startup() { return ::xos::network::os::sockets::startup(); }
inline bool cleanup() { return ::xos::network::os::sockets::cleanup(); }

} // namespace sockets

} // namespace network 
} // namespace medusa 

#endif // _MEDUSA_NETWORK_SOCKETS_HPP 
