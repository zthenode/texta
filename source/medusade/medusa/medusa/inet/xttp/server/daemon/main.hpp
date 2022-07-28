///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2016 $organization$
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
///   Date: 2/19/2016
///////////////////////////////////////////////////////////////////////
#ifndef _MEDUSA_INET_XTTP_SERVER_DAEMON_MAIN_HPP
#define _MEDUSA_INET_XTTP_SERVER_DAEMON_MAIN_HPP

#include "medusa/inet/xttp/server/daemon/main_opt.hpp"
#include "medusa/inet/xttp/server/daemon/processor.hpp"
#include "medusa/inet/xttp/processor.hpp"
#include "medusa/network/server/daemon/tcp/service.hpp"
#include "medusa/network/server/daemon/tcp/connections.hpp"
#include "medusa/network/network.hpp"
#include "medusa/mt/mt.hpp"

#define MEDUSA_INET_XTTP_SERVER_DAEMON_PORTNO 8080
#define MEDUSA_INET_XTTP_SERVER_DAEMON_PORT MEDUSA_2STRING(MEDUSA_INET_XTTP_SERVER_DAEMON_PORTNO)
#define MEDUSA_INET_XTTP_SERVER_DAEMON_HOST "localhost"
#define MEDUSA_INET_XTTP_SERVER_DAEMON_UDP_SIZE 4096

namespace medusa {
namespace inet {
namespace xttp {
namespace server {
namespace daemon {

typedef ::medusa::inet::xttp::server::daemon::main_opt::Implements main_implements;
typedef ::medusa::inet::xttp::server::daemon::main_opt main_extends;
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
    maint(processor& p)
    : p_(p),
      listen_(&Derives::tcp_listen),
      tp_(&Derives::ip_v4_tcp_tp),
      ep_(&Derives::ip_v4_ep),
      portno_(MEDUSA_INET_XTTP_SERVER_DAEMON_PORTNO),
      port_(MEDUSA_INET_XTTP_SERVER_DAEMON_PORT),
      host_(MEDUSA_INET_XTTP_SERVER_DAEMON_HOST),
      udp_size_(MEDUSA_INET_XTTP_SERVER_DAEMON_UDP_SIZE) {
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
    virtual int before_run_start(int argc, char_t**argv, char_t**env) {
        int err = 0;
		network::sockets::startup();
        return err;
    }
    virtual int after_run_start(int argc, char_t**argv, char_t**env) {
        int err = 0;
		network::sockets::cleanup();
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int run_start(int argc, char_t**argv, char_t**env) {
        int err = 0, err2 = 0;
        listen_t listen = 0;
        mt::signaler restart;

        do {
            restart(false);

            if ((listen = listen_)) {
                network::transport* tp = 0;

                if ((tp_) && (tp = (this->*tp_)())) {
                    network::endpoint* ep = 0;

                    if ((ep_) && (ep = ((this->*ep_)
                        (this->run_is_start(), host_.chars(), portno_)))) {
                        network::os::socket s;

                        MEDUSA_LOG_MESSAGE_DEBUG("s.open(*tp)...");
                        if ((s.open(*tp))) {
                            MEDUSA_LOG_MESSAGE_DEBUG("...s.open(*tp)");

                            MEDUSA_LOG_MESSAGE_DEBUG("p_.init()...");
                            if (!(err = p_.init(optind, argc, argv, env))) {
                                MEDUSA_LOG_MESSAGE_DEBUG("...p_.init()");

                                err2 = (this->*listen)(restart, s, *ep, argc, argv, env);

                                MEDUSA_LOG_MESSAGE_DEBUG("p_.fini()...");
                                if (!(err2 = p_.fini(optind, argc, argv, env))) {
                                    MEDUSA_LOG_MESSAGE_DEBUG("...p_.fini()");
                                } else {
                                    MEDUSA_LOG_MESSAGE_DEBUG("...failed " << err2 << " on p_.fini()");
                                }
                            } else {
                                MEDUSA_LOG_MESSAGE_DEBUG("...failed " << err << " on p_.init()");
                            }

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
    virtual int tcp_listen
    (mt::signaler& restart,
     network::socket& s, network::endpoint& ep,
     int argc, char_t** argv, char_t** env) {
        int err = 0;

        MEDUSA_LOG_MESSAGE_DEBUG("s.listen(ep)...");
        if ((s.listen(ep))) {
            network::server::daemon::tcp::service sv(p_, s, ep, optind, argc, argv, env);
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
    virtual int udp_listen
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
    virtual int on_host_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            host_.assign(optarg);
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int on_port_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            unsigned portno  = chars_t::to_unsigned(optarg);
            if (0 <  (portno)) {
                portno_ = portno;
                port_.assign(optarg);
            }
        }
        return err;
    }
    
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    processor& p_;
    listen_t listen_;
    transport_t tp_;
    endpoint_t ep_;
    ushort portno_;
    string_t port_, host_;
    size_t udp_size_;
    byte_array udp_;
};
typedef maint<> main;

} // namespace daemon 
} // namespace server 
} // namespace xttp 
} // namespace inet 
} // namespace medusa 

#endif // _MEDUSA_INET_XTTP_SERVER_DAEMON_MAIN_HPP 
