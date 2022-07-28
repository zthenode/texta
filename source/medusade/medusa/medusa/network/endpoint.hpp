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
///   File: endpoint.hpp
///
/// Author: $author$
///   Date: 12/27/2017
///////////////////////////////////////////////////////////////////////
#ifndef _MEDUSA_NETWORK_ENDPOINT_HPP
#define _MEDUSA_NETWORK_ENDPOINT_HPP

#include "medusa/network/connection.hpp"
#include "medusa/network/location.hpp"
#include "medusa/network/transport.hpp"
#include "xos/network/ip/v6/endpoint.hpp"
#include "xos/network/ip/v4/endpoint.hpp"
#include "xos/network/ip/endpoint.hpp"
#include "xos/network/endpoint.hpp"

namespace medusa {
namespace network {

namespace sockets {

class _EXPORT_CLASS endpoint;

} // namespace sockets

typedef sockets::endpoint sockets_endpoint;

///////////////////////////////////////////////////////////////////////
///  Class: endpointt
///////////////////////////////////////////////////////////////////////
template
<typename TAttached = sockets_addr_attached_t,
 typename TUnattached = sockets_addr_unattached_t,
 TUnattached VUnattached = sockets_addr_unattached,
 class TSocketsAddress = sockets_address_t,
 class TSocketsEndpoint = sockets_endpoint,
 class TImplements = TSocketsAddress>

class _EXPORT_CLASS endpointt: virtual public TImplements {
public:
    typedef TImplements Implements;

    typedef TSocketsEndpoint sockets_endpoint_t;
    typedef TSocketsAddress sockets_address_t;
    typedef TAttached attached_t;
    typedef TUnattached unattached_t;
    enum { unattached = VUnattached };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool bind
    (const network::transport& tp, const network::location& lc) {
        return false;
    }
    virtual bool listen
    (const network::transport& tp, const network::location& lc) {
        return false;
    }
    virtual bool accept(network::connection& cn, network::location& lc) {
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t sendto
    (const void* buf, size_t len, const network::location& lc) {
        return 0;
    }
    virtual ssize_t recvfrom
    (void* buf, size_t len, network::location& lc) {
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual sockets_address_t* sockets_address() const {
        return 0;
    }
    virtual sockets_endpoint_t* sockets_endpoint() const {
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef endpointt<> endpoint;
typedef endpoint::Implements endpoint_implements;

} // namespace network 
} // namespace medusa 

#endif // _MEDUSA_NETWORK_ENDPOINT_HPP 
