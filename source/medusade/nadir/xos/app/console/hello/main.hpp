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
///   File: main.hpp
///
/// Author: $author$
///   Date: 9/7/2014
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_APP_CONSOLE_HELLO_MAIN_HPP
#define _XOS_NADIR_XOS_APP_CONSOLE_HELLO_MAIN_HPP

#include "xos/base/getopt/main.hpp"
#include "xos/base/getopt/main_opt.hpp"
#include "xos/app/console/hello/tcp_service.hpp"
#include "xos/app/console/hello/tcp_processor.hpp"
#include "xos/app/console/hello/tcp_connections.hpp"
#include "xos/app/console/hello/processor.hpp"
#include "xos/app/console/hello/response.hpp"
#include "xos/app/console/hello/request.hpp"
#include "xos/app/console/hello/message.hpp"
#include "xos/network/os/sockets.hpp"
#include "xos/network/os/socket.hpp"
#include "xos/network/ip/v6/udp/transport.hpp"
#include "xos/network/ip/v6/tcp/transport.hpp"
#include "xos/network/ip/v6/endpoint.hpp"
#include "xos/network/ip/v4/udp/transport.hpp"
#include "xos/network/ip/v4/tcp/transport.hpp"
#include "xos/network/ip/v4/endpoint.hpp"
#include "xos/network/local/stream/transport.hpp"
#include "xos/network/local/dgram/transport.hpp"
#include "xos/network/local/endpoint.hpp"
#include "xos/mt/os/semaphore.hpp"
#include "xos/mt/os/mutex.hpp"
#include "xos/mt/lock.hpp"
#include "xos/io/file/opened.hpp"
#include "xos/io/write/file.hpp"
#include "xos/io/read/file.hpp"
#include "xos/base/types.hpp"
#include "xos/base/string.hpp"

#include <sstream>
#include <deque>
#include <queue>
#include <list>

#include "xos/app/console/hello/main_opt.hpp"

namespace xos {
namespace app {
namespace console {
namespace hello {

typedef base::getopt::main_implement main_implement;
typedef base::getopt::main main_extend;
///////////////////////////////////////////////////////////////////////
///  Class: main
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS main: virtual public main_implement, public main_extend {
public:
    typedef main_implement Implements;
    typedef main_extend Extends;
    typedef main Derives;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    main()
    : run_(0),
      send_(&Derives::client_tcp_send),
      listen_(&Derives::server_tcp_listen),
      ep_(&Derives::ip_v4_ep),
      tp_(&Derives::ip_v4_tcp_tp),
      portno_(XOS_APP_CONSOLE_HELLO_PORTNO),
      port_(XOS_APP_CONSOLE_HELLO_PORT),
      host_(XOS_APP_CONSOLE_HELLO_HOST),
      bye_message_(XOS_APP_CONSOLE_HELLO_BYE_MESSAGE),
      hello_message_(XOS_APP_CONSOLE_HELLO_HELLO_MESSAGE),
      message_line_separator_(XOS_APP_CONSOLE_HELLO_MESSAGE_LINE_SEPARATOR),
      message_body_separator_(XOS_APP_CONSOLE_HELLO_MESSAGE_BODY_SEPARATOR) {
    }
    virtual ~main() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    typedef int (Derives::*run_t)(int argc, char_t** argv, char_t** env);
    typedef int (Derives::*send_t)
    (network::socket& s, network::endpoint& ep,
     const char_t* chars, size_t length, int argc, char_t** argv, char_t** env);
    typedef int (Derives::*listen_t)
    (network::socket& s, network::endpoint& ep, int argc, char_t** argv, char_t** env);
    typedef network::endpoint* (Derives::*endpoint_t)();
    typedef network::transport* (Derives::*transport_t)();

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if ((network::os::sockets::startup())) {
            if ((run_)) {
                err = (this->*run_)(argc, argv, env);
            } else {
                const char_t* chars = 0;
                if ((chars = hello_message_.has_chars())) {
                    out(chars);
                    if ((optind<argc)) {
                        for (int arg = optind; arg < argc; ++arg) {
                            if ((chars = argv[arg]) && (chars[0])) {
                                out(message_line_separator_.chars());
                                out(chars);
                            }
                        }
                        out(message_body_separator_.chars());
                    } else {
                        out(message_line_separator_.chars());
                    }
                }
            }
            network::os::sockets::cleanup();
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int input_run(int argc, char_t** argv, char_t** env) {
        io::write::file out(std_out());
        const char_t* chars = 0;
        if ((chars = message_file_name_.has_chars())) {
            io::file::opened file;
            XOS_LOG_MESSAGE_DEBUG("open \"" << chars << "\"...");
            if ((file.open(chars, file.mode_read_binary()))) {
                XOS_LOG_MESSAGE_DEBUG("...opened \"" << chars << "\"");
                io::read::file in(file.attached_to());
                int err = rw_run(out, in, argc, argv, env);
                XOS_LOG_MESSAGE_DEBUG("close \"" << chars << "\"...");
                if ((file.close())) {
                    XOS_LOG_MESSAGE_DEBUG("...closed \"" << chars << "\"");
                } else {
                    XOS_LOG_MESSAGE_ERROR("...failed to close \"" << chars << "\"");
                }
                return err;
            } else {
                XOS_LOG_MESSAGE_ERROR("...failed to open \"" << chars << "\"");
            }
        } else {
            io::read::file in(std_in());
            return rw_run(out, in, argc, argv, env);
        }
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int rw_run
    (io::writer& writer, io::reader& reader, int argc, char_t** argv, char_t** env) {
        processor p(bye_message_, hello_message_, optind, argc, argv, env);
        bool continued = false;
        ssize_t count = 0;
        request rq;
        signaler bye;
        char chars[4096];
        do {
            if ((rq.on_read_start())) {
                do {
                    XOS_LOG_MESSAGE_DEBUG("read[" << sizeof(chars) << "]...");
                    if (0 < (count = reader.read(chars, sizeof(chars)))) {
                        XOS_LOG_MESSAGE_DEBUG("...read[" << count << "]");
                        if (!(rq.on_read_finish(chars, count))) {
                            continue;
                        } else {
                            processor::status ps;
                            XOS_LOG_MESSAGE_DEBUG("...read \"" << rq << "\"");
                            switch (ps = p(bye, writer, rq)) {
                            case processor::processing_done:
                                if ((bye)) {
                                    XOS_LOG_MESSAGE_DEBUG("...Bye \"" << rq.line() << "\"");
                                }
                                break;
                            case processor::processing_continued:
                                continued = true;
                                break;
                            }
                        }
                    } else {
                        XOS_LOG_MESSAGE_DEBUG("...failed with read[" << count << "]");
                    }
                    break;
                } while (0 < count);
            }
        } while (continued);
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int client_run(int argc, char_t** argv, char_t** env) {
        send_t send = 0;

        if ((send = (this->send_))) {
            //string_t message("GET /source/ HTTP/1.1\r\nHost: localhost\r\n\r\n");
            const char* chars = 0;
            size_t length = 0;
            request rq;
            //if ((chars = client_message(length, message, argc, argv, env))) {
            if ((chars = client_message(length, rq, argc, argv, env))) {
                network::endpoint* ep = 0;

                if ((ep_) && (ep = ((this->*ep_)()))) {
                    network::transport* tp = 0;

                    if ((tp_) && (tp = (this->*tp_)())) {
                        network::os::socket s;

                        if ((s.open(*tp))) {
                            (this->*send)(s, *ep, chars, length, argc, argv, env);
                            s.close();
                        }
                        delete tp;
                    }
                    delete ep;
                }
            }
        }
        return 0;
    }
    virtual int client_tcp_send
    (network::socket& s, network::endpoint& ep,
     const char_t* chars, size_t length, int argc, char_t** argv, char_t** env) {

        XOS_LOG_MESSAGE_DEBUG("s.connect()...");
        if ((s.connect(ep))) {
            ssize_t count;

            XOS_LOG_MESSAGE_DEBUG("sending \"" << chars << "\"...");
            if (0 < (count = s.send(chars, length, 0))) {

                XOS_LOG_MESSAGE_DEBUG("...sent \"" << chars << "\"");
                do {

                    XOS_LOG_MESSAGE_DEBUG("recv[" << sizeof(chars_) << "]...");
                    if (0 < (count = s.recv(chars_, sizeof(chars_), 0))) {

                        XOS_LOG_MESSAGE_DEBUG("...recv[" << count << "]");
                        out(chars_, count);
                        continue;
                    } else {
                        XOS_LOG_MESSAGE_DEBUG("...failed with recv[" << count << "]");
                    }
                    break;
                } while (0 < count);
            } else {
                XOS_LOG_MESSAGE_ERROR("... failed to send \"" << chars << "\"");
            }
        } else {
            XOS_LOG_MESSAGE_DEBUG("...failed on s.connect()");
        }
        return 0;
    }
    virtual int client_udp_send
    (network::socket& s, network::endpoint& ep,
     const char_t* chars, size_t length,  int argc, char_t** argv, char_t** env) {
        ssize_t count;

        XOS_LOG_MESSAGE_DEBUG("sending \"" << chars << "\"...");
        if (0 < (count = s.sendto(chars, length, 0, ep))) {

            XOS_LOG_MESSAGE_DEBUG("...sent \"" << chars << "\"");
        } else {
            XOS_LOG_MESSAGE_ERROR("... failed to send \"" << chars << "\"");
        }
        return 0;
    }
    virtual const char_t* client_message
    (size_t& length, request& rq, int argc, char_t** argv, char_t** env) {
        if ((rq.on_write_start())) {
            const char* chars = 0;
            if ((chars = hello_message_.has_chars(length))) {
                XOS_LOG_MESSAGE_DEBUG("line \"" << chars << "\"...");
                if ((rq.on_write_line(chars, length))) {
                    XOS_LOG_MESSAGE_DEBUG("...line \"" << chars << "\"");
                    for (int arg = optind; arg < argc; ++arg) {
                        if ((chars = (argv[arg])) && (0 < (length = chars_t::count(chars)))) {
                            XOS_LOG_MESSAGE_DEBUG("header \"" << chars << "\"...");
                            if (!(rq.on_write_header(chars, length))) {
                                return 0;
                            } else {
                                XOS_LOG_MESSAGE_DEBUG("...header \"" << chars << "\"");
                            }
                        }
                    }
                    if ((rq.on_write_finish())) {
                        if ((chars = rq.has_chars(length))) {
                            XOS_LOG_MESSAGE_DEBUG("message \"" << chars << "\"");
                            return chars;
                        }
                    }
                }
            }
        }
        return 0;
    }
    virtual const char_t* client_message
    (size_t& length, string_t& message, int argc, char_t** argv, char_t** env) {
        if ((hello_message_.has_chars())) {
            message.assign(hello_message_);
            for (int arg = optind; arg < argc; ++arg) {
                const char_t* chars;
                if (((chars = argv[arg])[0])) {
                    message.append(message_line_separator_);
                    message.append(chars);
                }
            }
            message.append(message_body_separator_);
        }
        return message.has_chars(length);
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int server_run(int argc, char_t** argv, char_t** env) {
        listen_t listen = 0;

        if ((listen = (this->listen_))) {
            network::endpoint* ep = 0;

            if ((ep_) && (ep = ((this->*ep_)()))) {
                network::transport* tp = 0;

                if ((tp_) && (tp = (this->*tp_)())) {
                    network::os::socket s;

                    if ((s.open(*tp))) {
                        (this->*listen)(s, *ep, argc, argv, env);
                        s.close();
                    }
                    delete tp;
                }
                delete ep;
            }
        }
        return 0;
    }
    virtual int server_tcp_listen
    (network::socket& s, network::endpoint& ep, int argc, char_t** argv, char_t** env) {
        XOS_LOG_MESSAGE_DEBUG("hello message = \"" << hello_message_ << "\"...");
        if ((s.listen(ep))) {
            tcp_service sv(s, ep, bye_message_, hello_message_, optind, argc, argv, env);
            network::os::socket sk;
            tcp_connections cn;

            for (bool done = false; !done; ) {
                signaler bye(done);
                if (!(done = !(sk.closed()))) {

                    XOS_LOG_MESSAGE_DEBUG("s.accept()...");
                    if (!(done = !(s.accept(sk, ep)))) {

                        XOS_LOG_MESSAGE_DEBUG("...s.accept()");
                        if ((cn.queue(sk))) {
                            sv(bye, cn, false);
                        }
                    } else {
                        XOS_LOG_MESSAGE_ERROR("...failed on s.accept()");
                    }
                }
            }
        }
        return 1;
    }
    virtual int server_udp_listen
    (network::socket& s, network::endpoint& ep, int argc, char_t** argv, char_t** env) {
        XOS_LOG_MESSAGE_DEBUG("hello message = \"" << hello_message_ << "\"...");
        if ((s.bind(ep))) {
            processor p(bye_message_, hello_message_, optind, argc, argv, env);
            io::write::file writer(std_out());
            size_t count = 0;
            request rq;
            signaler bye;
            do {
                XOS_LOG_MESSAGE_DEBUG("recv[" << sizeof(chars_) << "] from ep...");
                if (0 < (count = s.recvfrom(chars_, sizeof(chars_), 0, ep))) {
                    XOS_LOG_MESSAGE_DEBUG("...recv[" << count << "] from ep");
                    if ((rq.on_read(chars_, count))) {
                        processor::status ps;
                        XOS_LOG_MESSAGE_DEBUG("...read \"" << rq << "\"");
                        switch (ps = p(bye, writer, rq)) {
                        case processor::processing_done:
                            if ((bye)) {
                                XOS_LOG_MESSAGE_DEBUG("...Bye \"" << rq.line() << "\"");
                                return 0;
                            }
                            break;
                        case processor::processing_continued:
                            break;
                        default:
                            return 1;
                        }
                    }
                } else {
                    XOS_LOG_MESSAGE_DEBUG("...failed with recv[" << count << "] from ep");
                }
            } while (0 < count);
        }
        return 1;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual network::transport* ip_v4_tcp_tp() {
        network::transport* tp = new network::ip::v4::tcp::transport();
        return tp;
    }
    virtual network::transport* ip_v4_udp_tp() {
        network::transport* tp = new network::ip::v4::udp::transport();
        return tp;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual network::transport* ip_v6_tcp_tp() {
        network::transport* tp = new network::ip::v6::tcp::transport();
        return tp;
    }
    virtual network::transport* ip_v6_udp_tp() {
        network::transport* tp = new network::ip::v6::udp::transport();
        return tp;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual network::transport* local_stream_tp() {
        network::transport* tp = new network::local::stream::transport();
        return tp;
    }
    virtual network::transport* local_dgram_tp() {
        network::transport* tp = new network::local::dgram::transport();
        return tp;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual network::endpoint* ip_v4_ep() {
        const char_t* host;
        ushort port;
        if ((run_ != &Derives::server_run)) {
            if ((host = host_.has_chars()) && (0 < (port = portno_))) {
                network::endpoint* ep = new network::ip::v4::endpoint(host, port);
                return ep;
            }
        } else {
            if ((0 < (port = portno_))) {
                network::endpoint* ep = new network::ip::v4::endpoint(port);
                return ep;
            }
        }
        return 0;
    }
    virtual network::endpoint* ip_v6_ep() {
        const char_t* host;
        ushort port;
        if ((run_ != &Derives::server_run)) {
            if ((host = host_.has_chars()) && (0 < (port = portno_))) {
                network::endpoint* ep = new network::ip::v6::endpoint(host, port);
                return ep;
            }
        } else {
            if ((0 < (port = portno_))) {
                network::endpoint* ep = new network::ip::v6::endpoint(port);
                return ep;
            }
        }
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual network::endpoint* local_ep() {
        const char_t* host;
        if ((host = host_.has_chars())) {
            network::endpoint* ep = new network::local::endpoint(host);
            return ep;
        }
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void set_input() {
        run_ = &Derives::input_run;
    }
    virtual void set_client() {
        run_ = &Derives::client_run;
    }
    virtual void set_server() {
        run_ = &Derives::server_run;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void set_message(const char_t* to) {
        hello_message_.assign(to);
    }
    virtual void set_message_file(const char_t* to) {
        message_file_name_.assign(to);
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void set_host(const char_t* to) {
        host_.assign(to);
    }
    virtual void set_port(const char_t* to) {
        std::stringstream ss(to);
        int no;
		ss >> no;
        if (0 < (no)) {
            portno_ = no;
            port_.assign(to);
        }
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void set_family(const char_t* to) {
        if ((to) && (to[0])) {
            if (!((to[1]) || (XOS_APP_CONSOLE_HELLO_MAIN_FAMILY_OPTARG_IPV4[1] != to[0]))
                || !(xos::base::chars_t::compare
                     (XOS_APP_CONSOLE_HELLO_MAIN_FAMILY_OPTARG_IPV4+3, to))) {
                set_family_ip_v4();
            } else {
                if (!((to[1]) || (XOS_APP_CONSOLE_HELLO_MAIN_FAMILY_OPTARG_IPV6[1] != to[0]))
                    || !(xos::base::chars_t::compare
                         (XOS_APP_CONSOLE_HELLO_MAIN_FAMILY_OPTARG_IPV6+3, to))) {
                    set_family_ip_v6();
                } else {
                    if (!((to[1]) || (XOS_APP_CONSOLE_HELLO_MAIN_FAMILY_OPTARG_LOCAL[1] != to[0]))
                        || !(xos::base::chars_t::compare
                             (XOS_APP_CONSOLE_HELLO_MAIN_FAMILY_OPTARG_LOCAL+3, to))) {
                        set_family_local();
                    } else {
                    }
                }
            }
        }
    }
    virtual void set_transport(const char_t* to) {
        if (!((to[1]) || (XOS_APP_CONSOLE_HELLO_MAIN_TRANSPORT_OPTARG_TCP[1] != to[0]))
            || !(xos::base::chars_t::compare
                 (XOS_APP_CONSOLE_HELLO_MAIN_TRANSPORT_OPTARG_TCP+3, to))) {
            set_transport_tcp();
        } else {
            if (!((to[1]) || (XOS_APP_CONSOLE_HELLO_MAIN_TRANSPORT_OPTARG_UDP[1] != to[0]))
                || !(xos::base::chars_t::compare
                     (XOS_APP_CONSOLE_HELLO_MAIN_TRANSPORT_OPTARG_UDP+3, to))) {
                set_transport_udp();
            } else {
            }
        }
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void set_transport_tcp() {
        send_ = &Derives::client_tcp_send;
        listen_ = &Derives::server_tcp_listen;
        if ((&Derives::ip_v4_ep == ep_)) {
            tp_ = &Derives::ip_v4_tcp_tp;
        } else {
            if ((&Derives::ip_v6_ep == ep_)) {
                tp_ = &Derives::ip_v6_tcp_tp;
            } else {
            }
        }
    }
    virtual void set_transport_udp() {
        send_ = &Derives::client_udp_send;
        listen_ = &Derives::server_udp_listen;
        if ((&Derives::ip_v4_ep == ep_)) {
            tp_ = &Derives::ip_v4_udp_tp;
        } else {
            if ((&Derives::ip_v6_ep == ep_)) {
                tp_ = &Derives::ip_v6_udp_tp;
            } else {
            }
        }
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void set_family_ip_v4() {
        ep_ = &Derives::ip_v4_ep;
        if ((is_stream_tp())) {
            tp_ = &Derives::ip_v4_tcp_tp;
        } else {
            if ((is_dgram_tp())) {
                tp_ = &Derives::ip_v4_udp_tp;
            } else {
            }
        }
    }
    virtual void set_family_ip_v6() {
        ep_ = &Derives::ip_v6_ep;
        if ((is_stream_tp())) {
            tp_ = &Derives::ip_v6_tcp_tp;
        } else {
            if ((is_dgram_tp())) {
                tp_ = &Derives::ip_v6_udp_tp;
            } else {
            }
        }
    }
    virtual void set_family_local() {
        ep_ = &Derives::local_ep;
        if ((is_stream_tp())) {
            tp_ = &Derives::local_stream_tp;
        } else {
            if ((is_dgram_tp())) {
                tp_ = &Derives::local_dgram_tp;
            } else {
            }
        }
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool is_stream_tp() const {
        if ((&Derives::ip_v4_tcp_tp == tp_)
            || (&Derives::ip_v6_tcp_tp == tp_)
            || (&Derives::local_stream_tp == tp_)) {
            return true;
        }
        return false;
    }
    virtual bool is_dgram_tp() const {
        if ((&Derives::ip_v4_udp_tp == tp_)
            || (&Derives::ip_v6_udp_tp == tp_)
            || (&Derives::local_dgram_tp == tp_)) {
            return true;
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
#include "xos/app/console/hello/main_opt.cpp"

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    run_t run_;
    send_t send_;
    listen_t listen_;
    endpoint_t ep_;
    transport_t tp_;
    ushort portno_;
    string_t port_, host_,
             bye_message_, hello_message_, message_line_separator_,
             message_body_separator_, message_file_name_;
    char_t chars_[4096];
};

} // namespace hello 
} // namespace console 
} // namespace app 
} // namespace xos 

#endif // _XOS_NADIR_XOS_APP_CONSOLE_HELLO_MAIN_HPP 
