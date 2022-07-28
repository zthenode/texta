///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2014 $organization$
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
///   Date: 11/28/2014
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_NETWORK_IP_V4_ENDPOINT_HPP
#define _XOS_NADIR_XOS_NETWORK_IP_V4_ENDPOINT_HPP

#include "xos/network/ip/endpoint.hpp"
#include "xos/network/ip/v4/address.hpp"
#include "xos/base/attached.hpp"

namespace xos {
namespace network {
namespace ip {
namespace v4 {

typedef ip::endpoint_implements endpoint_implements;
typedef base::attachedt
<endpoint_attached_t, endpoint_unattached_t, endpoint_unattached,
 endpoint_implements, address> endpoint_extends;
///////////////////////////////////////////////////////////////////////
///  Class: endpointt
///////////////////////////////////////////////////////////////////////
template
<class TImplements = endpoint_implements, class TExtends = endpoint_extends>

class _EXPORT_CLASS endpointt: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    endpointt(const char_t* host, addrindex_t index, sockport_t port)
    : socket_address_port_(0), socket_address_len_(0) {
        memset(&socket_address_, 0, sizeof(socket_address_));
        if (!(this->attach(host, index, port))) {
            endpoint_exception_t e = failed_to_attach_endpoint;
            XOS_LOG_ERROR("throwing failed_to_attach_endpoint...");
            throw (e);
        }
    }
    endpointt(const char_t* host, sockport_t port)
    : socket_address_port_(0), socket_address_len_(0) {
        memset(&socket_address_, 0, sizeof(socket_address_));
        if (!(this->attach_first(host, port))) {
            endpoint_exception_t e = failed_to_attach_endpoint;
            XOS_LOG_ERROR("throwing failed_to_attach_endpoint...");
            throw (e);
        }
    }
    endpointt(sockport_t port)
    : socket_address_port_(0), socket_address_len_(0) {
        memset(&socket_address_, 0, sizeof(socket_address_));
        if (!(this->attach(port))) {
            endpoint_exception_t e = failed_to_attach_endpoint;
            XOS_LOG_ERROR("throwing failed_to_attach_endpoint...");
            throw (e);
        }
    }
    endpointt
    (const struct sockaddr* socket_address,
     socklen_t socket_address_len, sockport_t port)
    : socket_address_port_(0), socket_address_len_(0) {
        memset(&socket_address_, 0, sizeof(socket_address_));
        if (!(this->attach(socket_address, socket_address_len, port))) {
            endpoint_exception_t e = failed_to_attach_endpoint;
            XOS_LOG_ERROR("throwing failed_to_attach_endpoint...");
            throw (e);
        }
    }
    endpointt(const endpointt& copy)
    : socket_address_port_(0), socket_address_len_(0) {
        memset(&socket_address_, 0, sizeof(socket_address_));
        if (!(this->attach
            (copy.socket_address_, copy.socket_address_len_, copy.socket_address_port_))) {
            endpoint_exception_t e = failed_to_attach_endpoint;
            XOS_LOG_ERROR("throwing failed_to_attach_endpoint...");
            throw (e);
        }
    }
    endpointt()
    : socket_address_port_(0), socket_address_len_(0) {
        memset(&socket_address_, 0, sizeof(socket_address_));
    }
    virtual ~endpointt() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    using Implements::attach;
    virtual struct sockaddr* attach
    (const struct sockaddr* socket_address,
     socklen_t socket_address_len, sockport_t port) {
        if ((socket_address) && (socket_address_len == (this->socket_address_len()))) {
            if (this->get_family() == (socket_address->sa_family)) {
                struct sockaddr* attached = 0;
                if ((attached = this->attach(port))) {
                    const struct sockaddr_in& socket_address_in = (const struct sockaddr_in&)(*socket_address);
                    socket_address_.sin_addr.s_addr = socket_address_in.sin_addr.s_addr;
                }
                return attached;
            }
        }
        return 0;
    }
    virtual struct sockaddr* attach(sockport_t port) {
        memset(&socket_address_, 0, socket_address_len_ = (sizeof(socket_address_)));
        socket_address_.sin_family = this->get_family();
        socket_address_.sin_addr.s_addr = INADDR_ANY;
        socket_address_.sin_port = htons(port);
        return Extends::attach((sockaddr*)(&socket_address_));
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual socklen_t socket_address_len() const {
        return (socklen_t)(sizeof(socket_address_));
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    sockport_t socket_address_port_;
    socklen_t socket_address_len_;
    struct sockaddr_in socket_address_;
};
typedef endpointt<> endpoint;

} // namespace v4 
} // namespace ip 
} // namespace network 
} // namespace xos 

#endif // _XOS_NADIR_XOS_NETWORK_IP_V4_ENDPOINT_HPP 
