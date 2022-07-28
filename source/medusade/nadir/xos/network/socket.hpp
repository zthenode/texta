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
///   File: socket.hpp
///
/// Author: $author$
///   Date: 11/30/2014
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_NETWORK_SOCKET_HPP
#define _XOS_NADIR_XOS_NETWORK_SOCKET_HPP

#include "xos/network/transport.hpp"
#include "xos/network/endpoint.hpp"
#include "xos/network/address.hpp"
#include "xos/base/opener.hpp"
#include "xos/base/attacher.hpp"

#include <sys/socket.h>

#define XOS_NETWORK_SOCKET_LINGER_SECONDS 10

namespace xos {
namespace network {

typedef int socket_linger_seconds_t;
enum {
    socket_linger_seconds_default = -1,
    socket_linger_seconds_none = 0
};

typedef int socket_shutdown_how_t;
enum {
    socket_shutdown_none = 0,
    socket_shutdown_read = 1,
    socket_shutdown_write = 2,
    socket_shutdown_both = (socket_shutdown_read | socket_shutdown_write)
};

typedef int socket_t;
typedef socket_t socket_attached_t;
typedef int socket_unattached_t;
enum { socket_unattached = 0 };

typedef address_family_t socket_domain_t;
typedef transport_type_t socket_type_t;
typedef transport_protocol_t socket_protocol_t;

typedef transport socket_transport;
typedef endpoint socket_endpoint;

typedef base::opener socket_implements;
///////////////////////////////////////////////////////////////////////
///  Class: sockett
///////////////////////////////////////////////////////////////////////
template
<typename TAttached = socket_attached_t,
 typename TUnattached = socket_unattached_t,
 TUnattached VUnattached = socket_unattached,
 typename TDomain = socket_domain_t,
 typename TType = socket_type_t,
 typename TProtocol = socket_protocol_t,
 class TTransport = socket_transport,
 class TEndpoint = socket_endpoint,
 class TImplements = base::attachert
 <TAttached, TUnattached, VUnattached, socket_implements> >

class _EXPORT_CLASS sockett: virtual public TImplements {
public:
    typedef TImplements Implements;

    typedef socket_linger_seconds_t linger_seconds_t;
    typedef socket_shutdown_how_t shutdown_how_t;
    typedef TTransport transport_t;
    typedef TEndpoint endpoint_t;
    typedef TAttached attached_t;
    typedef TUnattached unattached_t;
    enum { unattached = VUnattached };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool open(const transport_t& transport) {
        socket_domain_t domain = transport.get_domain();
        socket_type_t type = transport.get_type();
        socket_protocol_t protocol = transport.get_protocol();
        if ((this->open(domain, type, protocol))) {
            return true;
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool connect(const endpoint_t& ep) {
        struct sockaddr* addr = 0;
        socklen_t addrlen = 0;
        if ((addr = ep.socket_address(addrlen))) {
            if ((this->connect(addr, addrlen))) {
                return true;
            }
        }
        return false;
    }
    virtual bool bind(const endpoint_t& ep) {
        struct sockaddr* addr = 0;
        socklen_t addrlen = 0;
        if ((addr = ep.socket_address(addrlen))) {
            if ((this->bind(addr, addrlen))) {
                return true;
            }
        }
        return false;
    }
    virtual bool listen(const endpoint_t& ep) {
        struct sockaddr* addr = 0;
        socklen_t addrlen = 0;
        if ((addr = ep.socket_address(addrlen))) {
            if ((this->bind(addr, addrlen))) {
                if ((this->listen())) {
                    return true;
                }
            }
        }
        return false;
    }
    virtual bool accept(sockett& sock, const endpoint_t& ep) {
        struct sockaddr* addr = 0;
        socklen_t addrlen = 0;
        if ((addr = ep.socket_address(addrlen))) {
            if ((this->accept(sock, addr, &addrlen))) {
                return true;
            }
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t sendto
    (const void* buf, size_t len, int flags, const endpoint_t& ep) {
        const struct sockaddr* addr = 0;
        socklen_t addrlen = 0;
        if ((addr = ep.socket_address(addrlen))) {
            ssize_t count = this->sendto(buf, len, flags, addr, addrlen);
            return count;
        }
        return 0;
    }
    virtual ssize_t recvfrom
    (void* buf, size_t len, int flags, const endpoint_t& ep) {
        struct sockaddr* addr = 0;
        socklen_t addrlen = 0;
        if ((addr = ep.socket_address(addrlen))) {
            ssize_t count = this->recvfrom(buf, len, flags, addr, &addrlen);
            return count;
        }
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    //virtual bool closed() { return false; }
    virtual attached_t attach_opened
    (attached_t detached, bool opened = true) { return unattached; }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool open
    (socket_domain_t domain, socket_type_t type, socket_protocol_t protocol) { return false; }
    virtual bool close() { return false; }
    virtual bool shutdown() { return false; }
    virtual bool shutdown(shutdown_how_t how) { return false; }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool connect(const struct sockaddr* addr, socklen_t addrlen) { return false; }
    virtual bool bind(const struct sockaddr* addr, socklen_t addrlen) { return false; }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool listen() { return false; }
    virtual bool listen(int backlog) { return false; }
    virtual bool accept(sockett& sock, struct sockaddr* addr, socklen_t* addrlen) { return false; }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t send(const void* buf, size_t len, int flags) { return 0; }
    virtual ssize_t recv(void* buf, size_t len, int flags) { return 0; }

    virtual ssize_t sendto
    (const void* buf, size_t len, int flags,
     const struct sockaddr* addr, socklen_t addrlen) { return 0; }
    virtual ssize_t recvfrom
    (void* buf, size_t len, int flags,
     struct sockaddr* addr, socklen_t* addrlen) { return 0; }

    virtual ssize_t sendmsg(const struct msghdr* msg, int flags) { return 0; }
    virtual ssize_t recvmsg(struct msghdr* msg, int flags) { return 0; }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool get_family
    (address_family_t &family, struct sockaddr &addr) { return false; }
    virtual bool get_name
    (struct sockaddr* addr, socklen_t &addrlen) const { return false; }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool set_reuseaddr_opt(bool on = true) { return false; }
    virtual bool set_noreuseaddr_opt(bool on = true) { return false; }
    virtual bool get_reuseaddr_opt(bool &on) const { return false; }

    virtual bool set_delay_opt(bool on = true) { return false; }
    virtual bool set_nodelay_opt(bool on = true) { return false; }
    virtual bool get_delay_opt(bool &on) const { return false; }

    virtual bool set_linger_opt
    (bool on = true, int linger_seconds = socket_linger_seconds_default) { return false; }
    virtual bool set_dontlinger_opt
    (bool on = true, int linger_seconds = socket_linger_seconds_none) { return false; }
    virtual bool get_linger_opt(bool &on, int &linger_seconds) const { return false; }

    virtual bool set_opt
    (int level, int name, const void* value, socklen_t length) { return false; }
    virtual bool get_opt
    (int level, int name, void* value, socklen_t &length) const { return false; }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool on_close() { return true; }
};
typedef sockett<> socket;

} // namespace network 
} // namespace xos 

#endif // _XOS_NADIR_XOS_NETWORK_SOCKET_HPP 
