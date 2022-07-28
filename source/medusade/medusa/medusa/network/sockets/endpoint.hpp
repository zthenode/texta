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
///   File: endpoint.hpp
///
/// Author: $author$
///   Date: 1/28/2018
///////////////////////////////////////////////////////////////////////
#ifndef _MEDUSA_NETWORK_SOCKETS_ENDPOINT_HPP
#define _MEDUSA_NETWORK_SOCKETS_ENDPOINT_HPP

#include "medusa/network/sockets/connection.hpp"
#include "medusa/network/sockets/location.hpp"
#include "medusa/network/endpoint.hpp"
#include "medusa/network/socket.hpp"

namespace medusa {
namespace network {
namespace sockets {

class _EXPORT_CLASS endpoint;
///////////////////////////////////////////////////////////////////////
///  Class: endpointt
///////////////////////////////////////////////////////////////////////
template
<class TImplement = network::endpointt
 <addr_attached_t, addr_unattached_t, addr_unattached, 
  address_t, endpoint, network::endpoint>,
 class TImplements = TImplement>

class _EXPORT_CLASS endpointt: virtual public TImplements {
public:
    typedef TImplements Implements;
    
    typedef typename Implements::sockets_endpoint_t sockets_endpoint_t;
    typedef typename Implements::sockets_address_t sockets_address_t;
    typedef typename Implements::attached_t attached_t;
    typedef typename Implements::unattached_t unattached_t;
    enum { unattached = Implements::unattached };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef endpointt<> endpoint_implements;
///////////////////////////////////////////////////////////////////////
///  Class: endpoint
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS endpoint: virtual public endpoint_implements {
public:
    typedef endpoint_implements Implements;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

///////////////////////////////////////////////////////////////////////
/// ip
///////////////////////////////////////////////////////////////////////
namespace ip {

///////////////////////////////////////////////////////////////////////
///  Class: endpointt
///////////////////////////////////////////////////////////////////////
template
<class TImplements = sockets::endpoint>

class _EXPORT_CLASS endpointt: virtual public TImplements {
public:
    typedef TImplements Implements;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef endpointt<> endpoint;
typedef endpoint::Implements endpoint_implements;

///////////////////////////////////////////////////////////////////////
/// v4
///////////////////////////////////////////////////////////////////////
namespace v4 {

///////////////////////////////////////////////////////////////////////
///  Class: endpointt
///////////////////////////////////////////////////////////////////////
template
<class TImplement = ip::endpoint,
 class TExtendBase = ::xos::base::attachedt
 <addr_attached_t, addr_unattached_t, addr_unattached, 
  TImplement, ::xos::network::ip::v4::address>,
 class TExtend = ::xos::network::ip::v4::endpointt<TImplement, TExtendBase>,
 class TImplements = TImplement, class TExtends = TExtend>

class _EXPORT_CLASS endpointt: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
	endpointt(const char_t* host, sockport_t port): Extends(host, port) {
    }
	endpointt(sockport_t port): Extends(port) {
    }
	endpointt(const endpointt& copy): Extends(copy) {
    }
    endpointt() {
    }
    virtual ~endpointt() {
        if (!(sk_.closed())) {
            const opener_exception e = failed_to_close;
            throw (e);
        }
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool bind
    (const network::transport& tp, const network::location& lc) {
        return false;
    }
    virtual bool listen
    (const network::transport& tp, const network::location& lc) {
        const network::sockets::location* slc = 0;

        if ((slc = lc.sockets_location())) {

            if ((this->attach(slc->port()))) {
                
                if ((sk_.open(tp))) {
                    
                    if ((sk_.listen(*this))) {
                        return true;
                    }
                    sk_.close();
                }
                this->detach();
            }
        }
        return false;
    }
    virtual bool accept(network::connection& cn, network::location& lc) {
        network::sockets::connection* scn = 0;
        network::sockets::location* slc = 0;
        
        if ((scn = cn.sockets_connection()) && (slc = lc.sockets_location())) {
            
            if ((sk_.accept(*scn, *slc))) {
                return true;
            }
        }
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
protected:
    ::xos::network::os::socket sk_;
};
typedef endpointt<> endpoint;
typedef endpoint::Implements endpoint_implements;

} // namespace v4

///////////////////////////////////////////////////////////////////////
/// v6
///////////////////////////////////////////////////////////////////////
namespace v6 {

///////////////////////////////////////////////////////////////////////
///  Class: endpointt
///////////////////////////////////////////////////////////////////////
template
<class TImplement = ip::endpoint,
 class TExtendBase = ::xos::base::attachedt
 <addr_attached_t, addr_unattached_t, addr_unattached, 
  TImplement, ::xos::network::ip::v6::address>,
 class TExtend = ::xos::network::ip::v6::endpointt<TImplement, TExtendBase>,
 class TImplements = TImplement, class TExtends = TExtend>

class _EXPORT_CLASS endpointt: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
	endpointt(const char_t* host, sockport_t port): Extends(host, port) {
    }
	endpointt(sockport_t port): Extends(port) {
    }
	endpointt(const endpointt& copy): Extends(copy) {
    }
    endpointt() {
    }
    virtual ~endpointt() {
        if (!(sk_.closed())) {
            const opener_exception e = failed_to_close;
            throw (e);
        }
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool bind
    (const network::transport& tp, const network::location& lc) {
        return false;
    }
    virtual bool listen
    (const network::transport& tp, const network::location& lc) {
        const network::sockets::location* slc = 0;

        if ((slc = lc.sockets_location())) {

            if ((this->attach(slc->port()))) {
                
                if ((sk_.open(tp))) {
                    
                    if ((sk_.listen(*this))) {
                        return true;
                    }
                    sk_.close();
                }
                this->detach();
            }
        }
        return false;
    }
    virtual bool accept(network::connection& cn, network::location& lc) {
        network::sockets::connection* scn = 0;
        network::sockets::location* slc = 0;
        
        if ((scn = cn.sockets_connection()) && (slc = lc.sockets_location())) {
            
            if ((sk_.accept(*scn, *slc))) {
                return true;
            }
        }
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
protected:
    ::xos::network::os::socket sk_;
};
typedef endpointt<> endpoint;
typedef endpoint::Implements endpoint_implements;

} // namespace v6

} // namespace ip

} // namespace sockets
} // namespace network 
} // namespace medusa 

#endif // _MEDUSA_NETWORK_SOCKETS_ENDPOINT_HPP 
