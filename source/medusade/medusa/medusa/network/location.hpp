///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2018 $organization$
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
///   File: location.hpp
///
/// Author: $author$
///   Date: 1/27/2018
///////////////////////////////////////////////////////////////////////
#ifndef _MEDUSA_NETWORK_LOCATION_HPP
#define _MEDUSA_NETWORK_LOCATION_HPP

#include "medusa/network/address.hpp"
#include "xos/network/endpoint.hpp"
#include "xos/base/attacher.hpp"

namespace medusa {
namespace network {

namespace sockets {

typedef ::xos::network::sockport_t sockport_t;

typedef ::xos::network::addrindex_t addrindex_t;
enum {
    first_addrindex = ::xos::network::first_addrindex,
    last_addrindex = ::xos::network::last_addrindex
};

typedef struct sockaddr* addr_attached_t;
typedef int addr_unattached_t;
enum { addr_unattached = 0 };

typedef ::xos::network::endpoint address_t;

class _EXPORT_CLASS location;

} // namespace sockets

typedef ::xos::network::endpoint_exception_t location_exception_t;
enum {
    failed_to_attach_location = ::xos::network::failed_to_attach_endpoint,
    failed_to_detach_location = ::xos::network::failed_to_detach_endpoint
};

typedef sockets::addr_attached_t sockets_addr_attached_t;
typedef sockets::addr_unattached_t sockets_addr_unattached_t;
enum { sockets_addr_unattached = sockets::addr_unattached };
typedef sockets::address_t sockets_address_t;
typedef sockets::location sockets_location;

///////////////////////////////////////////////////////////////////////
///  Class: locationt
///////////////////////////////////////////////////////////////////////
template
<typename TAttached = sockets_addr_attached_t,
 typename TUnattached = sockets_addr_unattached_t,
 TUnattached VUnattached = sockets_addr_unattached,
 class TSocketsAddress = sockets_address_t,
 class TSocketsLocation = sockets_location,
 class TImplements = TSocketsAddress>

class _EXPORT_CLASS locationt: virtual public TImplements {
public:
    typedef TImplements Implements;

    typedef TSocketsLocation sockets_location_t;
    typedef TSocketsAddress sockets_address_t;
    typedef TAttached attached_t;
    typedef TUnattached unattached_t;
    enum { unattached = VUnattached };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual sockets_address_t* sockets_address() const {
        return 0;
    }
    virtual sockets_location_t* sockets_location() const {
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef locationt<> location;

} // namespace network 
} // namespace medusa 

#endif // _MEDUSA_NETWORK_LOCATION_HPP 
