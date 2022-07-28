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
///   File: socket.hpp
///
/// Author: $author$
///   Date: 2/23/2015
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_NETWORK_WINDOWS_SOCKET_HPP
#define _XOS_NADIR_XOS_NETWORK_WINDOWS_SOCKET_HPP

#include "xos/network/socket.hpp"
#include "xos/base/opener.hpp"
#include "xos/base/opened.hpp"
#include "xos/base/attached.hpp"
#include "xos/base/attacher.hpp"

#if !defined(XOS_NETWORK_WINDOWS_SOCKET_BIND_REUSABLE)
#define XOS_NETWORK_WINDOWS_SOCKET_BIND_REUSABLE true
#endif // !defined(XOS_NETWORK_WINDOWS_SOCKET_BIND_REUSABLE)

#if !defined(XOS_NETWORK_WINDOWS_SOCKET_BACKLOG)
#define XOS_NETWORK_WINDOWS_SOCKET_BACKLOG SOMAXCONN
#endif // !defined(XOS_NETWORK_WINDOWS_SOCKET_BACKLOG)

namespace xos {
namespace network {
namespace windows {

typedef network::socket implements_socket;
typedef implements_socket socket_implements;
typedef base::attachedt
<socket_attached_t, socket_unattached_t, socket_unattached,
 socket_implements, base::base> socket_attached;
typedef base::openedt
<socket_attached_t, socket_unattached_t, socket_unattached,
 socket_implements, socket_attached> socket_extends;
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
 class TSocket = implements_socket,
 class TImplements=socket_implements, class TExtends=socket_extends>

class _EXPORT_CLASS sockett: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef socket_linger_seconds_t linger_seconds_t;
    typedef socket_shutdown_how_t shutdown_how_t;
    enum {
        shutdown_read = SD_RECEIVE,
        shutdown_write = SD_SEND,
        shutdown_both = SD_BOTH
    };
    typedef TSocket socket_t;
    typedef TTransport transport_t;
    typedef TEndpoint endpoint_t;
    typedef TAttached attached_t;
    typedef TUnattached unattached_t;
    enum { unattached = VUnattached };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    sockett(const sockett& copy): Extends(copy.attached_to()) {
    }
    sockett() {
    }
    virtual ~sockett() {
        if (!(this->closed())) {
            xos::base::opener_exception e = xos::base::failed_to_close;
            XOS_LOG_ERROR("...failed on closed() throwing base::failed_to_close...");
            throw (e);
        }
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    using Implements::open;
    virtual bool open
    (socket_domain_t domain, socket_type_t type, socket_protocol_t protocol) {
        if ((this->closed())) {
            attached_t detached = unattached;
            XOS_LOG_DEBUG("socket(domain = " << domain << ", type = " << type << ", protocol = " << protocol << ")...");
            if (INVALID_SOCKET != (detached = ::socket(domain, type, protocol))) {
                XOS_LOG_DEBUG("...socket(domain = " << domain << ", type = " << type << ", protocol = " << protocol << ")");
                this->attach_opened(detached);
                return true;
            } else {
                XOS_LOG_ERROR("failed " << WSAGetLastError() << " on socket(domain = " << domain << ", type = " << type << ", protocol = " << protocol << ")");
            }
        }
        return false;
    }
    virtual bool close() {
        attached_t detached = unattached;
        if (unattached  != (detached = this->detach())) {
            int err = 0;
            XOS_LOG_DEBUG("close(" << detached << ")...");
            if (SOCKET_ERROR != (err = ::closesocket(detached))) {
                XOS_LOG_DEBUG("...close(" << detached << ")");
                return true;
            } else {
                XOS_LOG_ERROR("failed " << WSAGetLastError() << " on close(" << detached << ")");
            }
        }
        return false;
    }
    virtual bool shutdown() {
        return this->shutdown(shutdown_both);
    }
    virtual bool shutdown(shutdown_how_t how) {
        attached_t detached = unattached;
        if (unattached  != (detached = this->attached_to())) {
            int err = 0;
            if (SOCKET_ERROR != (err = ::shutdown(detached, how))) {
                return true;
            } else {
                XOS_LOG_ERROR("failed " << WSAGetLastError() << " on shutdown()");
            }
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    using Implements::connect;
    virtual bool connect(const struct sockaddr* addr, socklen_t addrlen) {
        attached_t detached = unattached;
        if (unattached  != (detached = this->attached_to())) {
            int err = 0;
            if (SOCKET_ERROR != (err = ::connect(detached, addr, addrlen))) {
                return true;
            } else {
                XOS_LOG_ERROR("failed " << WSAGetLastError() << " on connect()");
            }
        }
        return false;
    }
    virtual bool bind(const struct sockaddr* addr, socklen_t addrlen) {
        attached_t detached = unattached;
        if (unattached  != (detached = this->attached_to())) {
            int err = 0;
#if defined(XOS_NETWORK_WINDOWS_SOCKET_BIND_REUSABLE)
            if (!(this->set_reuseaddr_opt(XOS_NETWORK_WINDOWS_SOCKET_BIND_REUSABLE))) {
                return false;
            }
#endif // defined(XOS_NETWORK_WINDOWS_SOCKET_BIND_REUSABLE)
            if (SOCKET_ERROR != (err = ::bind(detached, addr, addrlen))) {
                return true;
            } else {
                XOS_LOG_ERROR("failed " << WSAGetLastError() << " on bind()");
            }
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    using Implements::listen;
    virtual bool listen() {
        return this->listen(XOS_NETWORK_WINDOWS_SOCKET_BACKLOG);
    }
    virtual bool listen(int backlog) {
        attached_t detached = unattached;
        if (unattached  != (detached = this->attached_to())) {
            int err = 0;
            if (SOCKET_ERROR != (err = ::listen(detached, backlog))) {
                return true;
            } else {
                XOS_LOG_ERROR("failed " << WSAGetLastError() << " on listen()");
            }
        }
        return false;
    }
    using Implements::accept;
    virtual bool accept(socket_t& sock, struct sockaddr* addr, socklen_t* addrlen) {
        if ((sock.closed())) {
            attached_t detached = unattached;
            if (unattached  != (detached = this->attached_to())) {
                attached_t attached = unattached;
                if (INVALID_SOCKET != (attached = ::accept(detached, addr, addrlen))) {
                    sock.attach_opened(attached);
                    return true;
                } else {
                    XOS_LOG_ERROR("failed " << WSAGetLastError() << " on accept()");
                }
            }
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t send(const void* buf, size_t len, int flags) {
        attached_t detached = unattached;
        if ((buf) && (len) && (unattached  != (detached = this->attached_to()))) {
            int count = 0;
            if (SOCKET_ERROR != (count = ::send
                (detached, (const char*)(buf), len, flags))) {
                return count;
            } else {
                XOS_LOG_ERROR("failed " << WSAGetLastError() << " on send()");
            }
        }
        return 0;
    }
    virtual ssize_t recv(void* buf, size_t len, int flags) {
        attached_t detached = unattached;
        if ((buf) && (len) && (unattached  != (detached = this->attached_to()))) {
            int count = 0;
            if (SOCKET_ERROR != (count = ::recv
                (detached, (char*)(buf), len, flags))) {
                return count;
            } else {
                XOS_LOG_ERROR("failed " << WSAGetLastError() << " on recv()");
            }
        }
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t sendto
    (const void* buf, size_t len, int flags,
     const struct sockaddr* addr, socklen_t addrlen) {
        attached_t detached = unattached;
        if ((buf) && (len) && (addr) && (addrlen)
            && (unattached  != (detached = this->attached_to()))) {
            int count = 0;
            if (SOCKET_ERROR != (count = ::sendto
                (detached, (const char*)(buf), len, flags, addr, addrlen))) {
                return count;
            } else {
                XOS_LOG_ERROR("failed " << WSAGetLastError() << " on sendto()");
            }
        }
        return 0;
    }
    virtual ssize_t recvfrom
    (void* buf, size_t len, int flags,
     struct sockaddr* addr, socklen_t* addrlen) {
        attached_t detached = unattached;
        if ((buf) && (len) && (addr) && (addrlen)
            && (unattached  != (detached = this->attached_to()))) {
            int count = 0;
            if (SOCKET_ERROR != (count = ::recvfrom
                (detached, (char*)(buf), len, flags, addr, addrlen))) {
                return count;
            } else {
                XOS_LOG_ERROR("failed " << WSAGetLastError() << " on recvfrom()");
            }
        }
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool set_reuseaddr_opt(bool on = true) {
        int value = (on)?(1):(0);
        return this->set_opt(SOL_SOCKET, SO_REUSEADDR, &value, sizeof(value));
    }
    virtual bool set_noreuseaddr_opt(bool on = true) {
        int value = (on)?(0):(1);
        return this->set_opt(SOL_SOCKET, SO_REUSEADDR, &value, sizeof(value));
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool set_delay_opt(bool on = true) {
        int value = (on)?(1):(0); // Note opposite of unix
        return this->set_opt(IPPROTO_TCP, TCP_NODELAY, &value, sizeof(value));
    }
    virtual bool set_nodelay_opt(bool on = true) {
        int value = (on)?(0):(1); // Note opposite of unix
        return this->set_opt(IPPROTO_TCP, TCP_NODELAY, &value, sizeof(value));
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool set_linger_opt
    (bool on = true, int linger_seconds = socket_linger_seconds_default) {
        struct linger value;
        value.l_onoff = (on)?(1):(0);
        value.l_linger = (0>linger_seconds)?(XOS_NETWORK_SOCKET_LINGER_SECONDS):(linger_seconds);
        return this->set_opt(SOL_SOCKET, SO_LINGER, &value, sizeof(value));
    }
    virtual bool set_dontlinger_opt
    (bool on = true, int linger_seconds = socket_linger_seconds_none) {
        struct linger value;
        value.l_onoff = (on)?(0):(1);
        value.l_linger = (0>linger_seconds)?(XOS_NETWORK_SOCKET_LINGER_SECONDS):(linger_seconds);
        return this->set_opt(SOL_SOCKET, SO_LINGER, &value, sizeof(value));
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool set_opt
    (int level, int name, const void* value, socklen_t length) {
        attached_t detached = unattached;
        if (unattached  != (detached = this->attached_to())) {
            int err = 0;
            if (SOCKET_ERROR != (err = ::setsockopt
                (detached, level, name, (const char*)(value), length))) {
                return true;
            } else  {
                XOS_LOG_ERROR("failed " << WSAGetLastError() << " on setsockopt()");
            }
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef sockett<> socket;

} // namespace windows 
} // namespace network 
} // namespace xos 

#endif // _XOS_NADIR_XOS_NETWORK_WINDOWS_SOCKET_HPP 
