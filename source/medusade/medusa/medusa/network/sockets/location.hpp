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
#ifndef _MEDUSA_NETWORK_SOCKETS_LOCATION_HPP
#define _MEDUSA_NETWORK_SOCKETS_LOCATION_HPP

#include "medusa/network/location.hpp"
#include "xos/network/ip/v4/endpoint.hpp"
#include "xos/network/ip/v6/endpoint.hpp"
#include "xos/network/ip/endpoint.hpp"

namespace medusa {
namespace network {
namespace sockets {

class _EXPORT_CLASS location;
///////////////////////////////////////////////////////////////////////
///  Class: locationt
///////////////////////////////////////////////////////////////////////
template
<class TImplement = network::locationt
 <addr_attached_t, addr_unattached_t, addr_unattached, 
  address_t, location, network::location>,
 class TImplements = TImplement>

class _EXPORT_CLASS locationt: virtual public TImplements {
public:
    typedef TImplements Implements;
    
    typedef typename Implements::sockets_location_t sockets_location_t;
    typedef typename Implements::sockets_address_t sockets_address_t;
    typedef typename Implements::attached_t attached_t;
    typedef typename Implements::unattached_t unattached_t;
    enum { unattached = Implements::unattached };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* host() const {
        return 0;
    }
    virtual addrindex_t index() const {
        return 0;
    }
    virtual sockport_t port() const {
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef locationt<> location_implements;
///////////////////////////////////////////////////////////////////////
///  Class: location
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS location: virtual public location_implements {
public:
    typedef location_implements Implements;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual sockets_address_t* sockets_address() const {
        return (sockets_address_t*)this;
    }
    virtual sockets_location_t* sockets_location() const {
        return (sockets_location_t*)this;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

namespace ip {

///////////////////////////////////////////////////////////////////////
///  Class: locationt
///////////////////////////////////////////////////////////////////////
template
<class TImplements = sockets::location>

class _EXPORT_CLASS locationt: virtual public TImplements {
public:
    typedef TImplements Implements;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef locationt<> location;

namespace v4 {

///////////////////////////////////////////////////////////////////////
///  Class: locationt
///////////////////////////////////////////////////////////////////////
template
<class TImplement = ip::location,
 class TExtendBase = ::xos::base::attachedt
 <addr_attached_t, addr_unattached_t, addr_unattached, 
  TImplement, ::xos::network::ip::v4::address>,
 class TExtend = ::xos::network::ip::v4::endpointt<TImplement, TExtendBase>,
 class TImplements = TImplement, class TExtends = TExtend>

class _EXPORT_CLASS locationt: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    locationt
    (const char_t* host, addrindex_t index, sockport_t port)
    : Extends(host, index, port), host_(host), index_(index), port_(port) {
    }
    locationt(const char_t* host, sockport_t port)
    : Extends(host, port), host_(host), index_(0), port_(port) {
    }
    locationt(sockport_t port): Extends(port), index_(0), port_(port) {
    }
    locationt(const locationt& copy)
    : Extends(copy), host_(copy.host_), index_(copy.index_), port_(copy.port_) {
    }
    locationt(): index_(0), port_(0) {
    }
    virtual ~locationt() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* host() const {
        return host_.has_chars();
    }
    virtual addrindex_t index() const {
        return index_;
    }
    virtual sockport_t port() const {
        return port_;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    string_t host_;
    addrindex_t index_;
    sockport_t port_;
};
typedef locationt<> location;

} // namespace v4 

namespace v6 {

///////////////////////////////////////////////////////////////////////
///  Class: locationt
///////////////////////////////////////////////////////////////////////
template
<class TImplement = ip::location,
 class TExtendBase = ::xos::base::attachedt
 <addr_attached_t, addr_unattached_t, addr_unattached, 
  TImplement, ::xos::network::ip::v6::address>,
 class TExtend = ::xos::network::ip::v6::endpointt<TImplement, TExtendBase>,
 class TImplements = TImplement, class TExtends = TExtend>

class _EXPORT_CLASS locationt: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    locationt
    (const char_t* host, addrindex_t index, sockport_t port)
    : Extends(host, index, port), host_(host), index_(index), port_(port) {
    }
    locationt(const char_t* host, sockport_t port)
    : Extends(host, port), host_(host), index_(0), port_(port) {
    }
    locationt(sockport_t port): Extends(port), index_(0), port_(port) {
    }
    locationt(const locationt& copy)
    : Extends(copy), host_(copy.host_), index_(copy.index_), port_(copy.port_) {
    }
    locationt(): index_(0), port_(0) {
    }
    virtual ~locationt() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* host() const {
        return host_.has_chars();
    }
    virtual addrindex_t index() const {
        return index_;
    }
    virtual sockport_t port() const {
        return port_;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    string_t host_;
    addrindex_t index_;
    sockport_t port_;
};
typedef locationt<> location;

} // namespace v6 

} // namespace ip 

} // namespace sockets 
} // namespace network 
} // namespace medusa 

#endif // _MEDUSA_NETWORK_SOCKETS_LOCATION_HPP 
