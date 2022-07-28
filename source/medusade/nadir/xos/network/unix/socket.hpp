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
///   Date: 12/1/2014
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_NETWORK_UNIX_SOCKET_HPP
#define _XOS_NADIR_XOS_NETWORK_UNIX_SOCKET_HPP

#include "xos/network/socket.hpp"
#include "xos/base/opener.hpp"
#include "xos/base/opened.hpp"
#include "xos/base/attached.hpp"
#include "xos/base/attacher.hpp"

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <netdb.h>
#include <errno.h>

#if !defined(XOS_NETWORK_UNIX_SOCKET_BIND_REUSABLE)
#define XOS_NETWORK_UNIX_SOCKET_BIND_REUSABLE true
#endif // !defined(XOS_NETWORK_UNIX_SOCKET_BIND_REUSABLE)

#if !defined(XOS_NETWORK_SOCKET_BACKLOG)
#define XOS_NETWORK_SOCKET_BACKLOG SOMAXCONN
#endif // !defined(XOS_NETWORK_SOCKET_BACKLOG)

namespace xos {
namespace network {
namespace unix {

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
 class TImplements = socket_implements, class TExtends = socket_extends>

class _EXPORT_CLASS sockett: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef socket_linger_seconds_t linger_seconds_t;
    typedef socket_shutdown_how_t shutdown_how_t;
    enum {
        shutdown_none = socket_shutdown_none,
        shutdown_read = socket_shutdown_read,
        shutdown_write = socket_shutdown_write,
        shutdown_both = socket_shutdown_both
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
            base::opener_exception e = base::failed_to_close;
            XOS_LOG_ERROR("...failed on closed()");
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
            if (0 <= (detached = ::socket(domain, type, protocol))) {
                XOS_LOG_DEBUG("...socket(domain = " << domain << ", type = " << type << ", protocol = " << protocol << ")");
                this->attach_opened(detached);
                return true;
            } else {
                XOS_LOG_ERROR("...failed errno = " << errno << " on socket(domain = " << domain << ", type = " << type << ", protocol = " << protocol << ")");
            }
        }
        return false;
    }
    virtual bool close() {
        if ((this->on_close())) {
            attached_t detached = unattached;
            if (unattached  != (detached = this->detach())) {
                int err = 0;
                XOS_LOG_DEBUG("close(" << detached << ")...");
                if (!(err = ::close(detached))) {
                    XOS_LOG_DEBUG("...close(" << detached << ")");
                    return true;
                } else {
                    XOS_LOG_ERROR("...failed errno = " << errno << " on close(" << detached << ")");
                }
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
            XOS_LOG_DEBUG("::shutdown(detached, how)...");
            if (!(err = ::shutdown(detached, how))) {
                return true;
            } else {
                XOS_LOG_ERROR("...failed errno = " << errno << " on ::shutdown(detached, how)");
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
            XOS_LOG_DEBUG("::connect(detached, addr, addrlen)...");
            if (!(err = ::connect(detached, addr, addrlen))) {
                return true;
            } else {
                XOS_LOG_ERROR("...failed errno = " << errno << " on ::connect(detached, addr, addrlen)");
            }
        }
        return false;
    }
    virtual bool bind(const struct sockaddr* addr, socklen_t addrlen) {
        attached_t detached = unattached;
        if (unattached  != (detached = this->attached_to())) {
            int err = 0;
#if defined(XOS_NETWORK_UNIX_SOCKET_BIND_REUSABLE)
            if (!(this->set_reuseaddr_opt(XOS_NETWORK_UNIX_SOCKET_BIND_REUSABLE))) {
                return false;
            }
#endif // defined(XOS_NETWORK_UNIX_SOCKET_BIND_REUSABLE)
            XOS_LOG_DEBUG("::bind(detached, addr, addrlen...");
            if (!(err = ::bind(detached, addr, addrlen))) {
                return true;
            } else {
                XOS_LOG_ERROR("...failed errno = " << errno << " on ::bind(detached, addr, addrlen)");
            }
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    using Implements::listen;
    virtual bool listen() {
        return this->listen(XOS_NETWORK_SOCKET_BACKLOG);
    }
    virtual bool listen(int backlog) {
        attached_t detached = unattached;
        if (unattached  != (detached = this->attached_to())) {
            int err = 0;
            XOS_LOG_DEBUG("::listen(detached, backlog)...");
            if (!(err = ::listen(detached, backlog))) {
                return true;
            } else {
                XOS_LOG_ERROR("...failed errno = " << errno << " on ::listen(detached, backlog)");
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
                if (0 <= (attached = ::accept(detached, addr, addrlen))) {
                    sock.attach_opened(attached);
                    return true;
                } else {
                    XOS_LOG_ERROR("...failed errno = " << errno << " on ::accept(detached, addr, addrlen)");
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
            ssize_t count = 0;
            if (0 <= (count = ::send(detached, buf, len, flags))) {
                return count;
            } else {
                XOS_LOG_ERROR("...failed errno = " << errno << " on ::send(detached, buf, len, flags)");
            }
        }
        return 0;
    }
    virtual ssize_t recv(void* buf, size_t len, int flags) {
        attached_t detached = unattached;
        if ((buf) && (len) && (unattached  != (detached = this->attached_to()))) {
            ssize_t count = 0;
            if (0 <= (count = ::recv(detached, buf, len, flags))) {
                return count;
            } else {
                XOS_LOG_ERROR("...failed errno = " << errno << " on ::recv(detached, buf, len, flags)");
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
            ssize_t count = 0;
            if (0 <= (count = ::sendto(detached, buf, len, flags, addr, addrlen))) {
                return count;
            } else {
                XOS_LOG_ERROR("failed " << errno << " on sendto()");
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
            ssize_t count = 0;
            if (0 <= (count = ::recvfrom(detached, buf, len, flags, addr, addrlen))) {
                return count;
            } else {
                XOS_LOG_ERROR("failed " << errno << " on recvfrom()");
            }
        }
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool get_family(address_family_t &family, struct sockaddr &addr) {
        socklen_t addrlen = sizeof(addr);
        memset(&addr, 0, addrlen);
        if ((get_name(&addr, addrlen))) {
            family = (addr.sa_family);
            return true;
        }
        return false;
    }
    virtual bool get_name(struct sockaddr* addr, socklen_t &addrlen) const {
        attached_t detached = unattached;
        if (unattached  != (detached = this->attached_to())) {
            int err = 0;
            if (!(err = ::getsockname(detached, addr, &addrlen))) {
                return true;
            } else  {
                XOS_LOG_ERROR("failed " << errno << " on getsockname()");
            }
        }
        return false;
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
    virtual bool get_reuseaddr_opt(bool &on) const {
        int value = 0;
        socklen_t length = sizeof(value);
        if ((this->get_opt(SOL_SOCKET, SO_REUSEADDR, &value, length))) {
            on = (value != 0);
            return true;
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool set_delay_opt(bool on = true) {
        int value = (on)?(0):(1);
        return this->set_opt(IPPROTO_TCP, TCP_NODELAY, &value, sizeof(value));
    }
    virtual bool set_nodelay_opt(bool on = true) {
        int value = (on)?(1):(0);
        return this->set_opt(IPPROTO_TCP, TCP_NODELAY, &value, sizeof(value));
    }
    virtual bool get_delay_opt(bool &on) const {
        int value = 0;
        socklen_t length = sizeof(value);
        if ((this->get_opt(IPPROTO_TCP, TCP_NODELAY, &value, length))) {
            on = (value == 0);
            return true;
        }
        return false;
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
    virtual bool get_linger_opt(bool &on, int &linger_seconds) const {
        struct linger value = {0, 0};
        socklen_t length = sizeof(value);
        if ((this->get_opt(SOL_SOCKET, SO_LINGER, &value, length))) {
            on = (value.l_onoff == 0);
            linger_seconds = (value.l_linger);
            return true;
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool set_opt
    (int level, int name, const void* value, socklen_t length) {
        attached_t detached = unattached;
        if (unattached  != (detached = this->attached_to())) {
            int err = 0;
            if (!(err = ::setsockopt(detached, level, name, value, length))) {
                return true;
            } else  {
                XOS_LOG_ERROR("failed " << errno << " on setsockopt()");
            }
        }
        return false;
    }
    virtual bool get_opt
    (int level, int name, void* value, socklen_t &length) const {
        attached_t detached = unattached;
        if (unattached  != (detached = this->attached_to())) {
            int err = 0;
            if (!(err = ::getsockopt(detached, level, name, value, &length))) {
                return true;
            } else  {
                XOS_LOG_ERROR("failed " << errno << " on getsockopt()");
            }
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool on_close() {
        address_family_t family = 0;
        struct sockaddr addr;
        if ((get_family(family, addr))) {
            if (AF_LOCAL == (family)) {
                if (sizeof(struct sockaddr_un) <= sizeof(struct sockaddr)) {
                    struct sockaddr_un &addr_un = *((struct sockaddr_un*)&addr);
                    XOS_LOG_MESSAGE_DEBUG("...on_close() family = AF_LOCAL path = \"" << addr_un.sun_path << "\"");
                }
            }
        }
        return true;
    }
};
typedef sockett<> socket;

} // namespace unix 
} // namespace network 
} // namespace xos 

#endif // _XOS_NADIR_XOS_NETWORK_UNIX_SOCKET_HPP 
