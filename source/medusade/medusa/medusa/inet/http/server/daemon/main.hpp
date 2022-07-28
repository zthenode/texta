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
///   File: main.hpp
///
/// Author: $author$
///   Date: 2/7/2015
///////////////////////////////////////////////////////////////////////
#ifndef _MEDUSA_INET_HTTP_SERVER_DAEMON_MAIN_HPP
#define _MEDUSA_INET_HTTP_SERVER_DAEMON_MAIN_HPP

#include "medusa/daemon/main.hpp"
#include "medusa/inet/http/server/daemon/processor.hpp"
#include "medusa/inet/http/processor.hpp"
#include "medusa/network/server/daemon/tcp/service.hpp"
#include "medusa/network/server/daemon/tcp/connections.hpp"
#include "medusa/network/network.hpp"
#include "medusa/mt/mt.hpp"

#define MEDUSA_INET_HTTP_SERVER_DAEMON_PORTNO 8080
#define MEDUSA_INET_HTTP_SERVER_DAEMON_PORT MEDUSA_2STRING(MEDUSA_INET_HTTP_SERVER_DAEMON_PORTNO)
#define MEDUSA_INET_HTTP_SERVER_DAEMON_HOST "localhost"
#define MEDUSA_INET_HTTP_SERVER_DAEMON_UDP_SIZE 4096

namespace medusa {
namespace inet {
namespace http {
namespace server {
namespace daemon {

typedef ::medusa::daemon::main_implements main_implements;
typedef ::medusa::daemon::main main_extends;
///////////////////////////////////////////////////////////////////////
///  Class: maint
///////////////////////////////////////////////////////////////////////
template
<class TImplements = main_implements, class TExtends = main_extends>

class _EXPORT_CLASS maint: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef maint Derives;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    maint(processor& xttp)
    : xttp_(xttp),
      http_listen_(&Derives::http_tcp_listen),
      http_tp_(&Derives::ip_v4_tcp_tp),
      http_ep_(&Derives::ip_v4_ep),
      http_portno_(MEDUSA_INET_HTTP_SERVER_DAEMON_PORTNO),
      http_port_(MEDUSA_INET_HTTP_SERVER_DAEMON_PORT),
      http_host_(MEDUSA_INET_HTTP_SERVER_DAEMON_HOST),
      udp_size_(MEDUSA_INET_HTTP_SERVER_DAEMON_UDP_SIZE) {
    }
    virtual ~maint() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    typedef int (Derives::*listen_t)
    (mt::signaler& restart,
     network::socket& s, network::endpoint& ep,
     int argc, char_t** argv, char_t** env);
    typedef network::transport* (Derives::*transport_t)();
    typedef network::endpoint* (Derives::*endpoint_t)
    (bool listen, const char_t* host, ushort port);

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int run_start(int argc, char_t**argv, char_t**env) {
        int err = 0;
        listen_t listen = 0;
        mt::signaler restart;

        do {
            restart(false);

            if ((listen = http_listen_)) {
                network::transport* tp = 0;

                if ((http_tp_) && (tp = (this->*http_tp_)())) {
                    network::endpoint* ep = 0;

                    if ((http_ep_) && (ep = ((this->*http_ep_)
                        (this->run_is_start(), http_host_.chars(), http_portno_)))) {
                        network::os::socket s;

                        MEDUSA_LOG_MESSAGE_DEBUG("s.open(*tp)...");
                        if ((s.open(*tp))) {
                            MEDUSA_LOG_MESSAGE_DEBUG("...s.open(*tp)");

                            (this->*listen)(restart, s, *ep, argc, argv, env);

                            MEDUSA_LOG_MESSAGE_DEBUG("s.close()...");
                            if ((s.close())) {
                                MEDUSA_LOG_MESSAGE_DEBUG("...s.close()");
                            } else {
                                MEDUSA_LOG_MESSAGE_DEBUG("...failed on s.close()");
                            }
                        } else {
                            MEDUSA_LOG_MESSAGE_DEBUG("...failed on s.open(*tp)");
                        }
                        MEDUSA_LOG_MESSAGE_DEBUG("delete ep...")
                        delete ep;
                    }
                    MEDUSA_LOG_MESSAGE_DEBUG("delete tp...")
                    delete tp;
                }
            }
        } while (restart);
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int http_tcp_listen
    (mt::signaler& restart,
     network::socket& s, network::endpoint& ep,
     int argc, char_t** argv, char_t** env) {
        int err = 0;

        MEDUSA_LOG_MESSAGE_DEBUG("s.listen(ep)...");
        if ((s.listen(ep))) {
            network::server::daemon::tcp::service sv(xttp_, s, ep, optind, argc, argv, env);
            network::server::daemon::tcp::connections cn;
            network::os::socket sk;

            MEDUSA_LOG_MESSAGE_DEBUG("...s.listen(ep)");
            for (bool done = false; !done; ) {
                mt::signaler stop(done);
                if (!(done = !(sk.closed()))) {

                    MEDUSA_LOG_MESSAGE_DEBUG("s.accept()...");
                    if (!(done = !(s.accept(sk, ep)))) {

                        MEDUSA_LOG_MESSAGE_DEBUG("...s.accept()");
                        if ((cn.queue(sk))) {
                            sv(restart, stop, cn, false);
                        }
                    } else {
                        XOS_LOG_MESSAGE_ERROR("...failed on s.accept()");
                    }
                }
            }
        } else {
            MEDUSA_LOG_MESSAGE_DEBUG("...failed on s.listen(ep)");
        }
        return err;
    }
    virtual int http_udp_listen
    (mt::signaler& restart,
     network::socket& s, network::endpoint& ep,
     int argc, char_t** argv, char_t** env) {
        int err = 0;
        size_t size = 0;

        if (udp_size_ <= (udp_.set_size(size = udp_size_))) {
            byte_t* bytes = 0;

            if ((bytes = udp_.elements())) {
                if ((s.bind(ep))) {
                    ssize_t count = 0;
                    mt::signaler done;

                    do {
                        MEDUSA_LOG_MESSAGE_DEBUG("recv[" << size << "] from ep...");
                        if (0 < (count = s.recvfrom(bytes, size, 0, ep))) {
                            MEDUSA_LOG_MESSAGE_DEBUG("...recv[" << count << "] from ep");
                        } else {
                            MEDUSA_LOG_MESSAGE_DEBUG("...failed with recv[" << count << "] from ep");
                        }
                    } while (0 < count);
                }
            }
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual network::transport* ip_v4_tcp_tp() {
        network::transport* tp = new network::ip::v4::tcp::transport();
        return tp;
    }
    virtual network::transport* ip_v6_tcp_tp() {
        network::transport* tp = new network::ip::v6::tcp::transport();
        return tp;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual network::transport* ip_v4_udp_tp() {
        network::transport* tp = new network::ip::v4::udp::transport();
        return tp;
    }
    virtual network::transport* ip_v6_udp_tp() {
        network::transport* tp = new network::ip::v6::udp::transport();
        return tp;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual network::endpoint* ip_v4_ep
    (bool listen, const char_t* host, ushort port) {
        if (!(listen)) {
            if ((host) && (0 < (port))) {
                network::endpoint* ep = new network::ip::v4::endpoint(host, port);
                return ep;
            }
        } else {
            if ((0 < (port))) {
                network::endpoint* ep = new network::ip::v4::endpoint(port);
                return ep;
            }
        }
        return 0;
    }
    virtual network::endpoint* ip_v6_ep
    (bool listen, const char_t* host, ushort port) {
        if (!(listen)) {
            if ((host) && (0 < (port))) {
                network::endpoint* ep = new network::ip::v6::endpoint(host, port);
                return ep;
            }
        } else {
            if ((0 < (port))) {
                network::endpoint* ep = new network::ip::v6::endpoint(port);
                return ep;
            }
        }
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    processor& xttp_;
    listen_t http_listen_;
    transport_t http_tp_;
    endpoint_t http_ep_;
    ushort http_portno_;
    string_t http_port_, http_host_;
    size_t udp_size_;
    byte_array udp_;
};
typedef maint<> main;

} // namespace daemon 
} // namespace server
} // namespace http
} // namespace inet 
} // namespace medusa 

#endif // _MEDUSA_INET_HTTP_SERVER_DAEMON_MAIN_HPP
