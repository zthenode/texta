///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2017 $organization$
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
///   Date: 12/27/2017, 6/24/2022
/// 
///////////////////////////////////////////////////////////////////////
#ifndef _MEDUSA_APP_CONSOLE_HELLO_MAIN_HPP
#define _MEDUSA_APP_CONSOLE_HELLO_MAIN_HPP

#include "medusa/app/console/hello/main_opt.hpp"
#include "medusa/network/sockets.hpp"
#include "medusa/network/endpoint.hpp"
#include "medusa/network/location.hpp"
#include "medusa/network/transport.hpp"

namespace medusa {
namespace app {
namespace console {
namespace hello {

typedef main_opt_implements main_implements;
typedef main_opt main_extends;
///////////////////////////////////////////////////////////////////////
///  Class: main
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS main: virtual public main_implements, public main_extends {
public:
    typedef main_implements Implements;
    typedef main_extends Extends;
    typedef main Derives;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    main()
    : run_(0), 
      run_network_(0), 
      run_network_client_(0),
      run_stream_network_client_(0),
      get_client_network_connection_(0),
      get_client_network_location_(0),
      get_client_ip_network_location_(0),
      run_network_server_(0), 
      run_stream_network_server_(0),
      get_server_network_connection_(0),
      get_server_network_location_(0),
      get_server_network_endpoint_(0),
      get_server_ip_network_endpoint_(0),
      get_stream_network_transport_(0),
      bye_request_("GET /bye/ HTTP/1.0\r\n\r\n"),
      bye_response_("HTTP/1.0 200 Ok\r\n\r\nBye\r\n"),
      hello_request_("GET /hello/ HTTP/1.0\r\n\r\n"),
      hello_response_("HTTP/1.0 200 Ok\r\n\r\nHello\r\n"),
      host_("localhost"), port_("80"), server_port_("8080"), 
      portno_(80), server_portno_(8080) {
    }
    virtual ~main() {
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    int (Derives::*run_)(int argc, char_t** argv, char_t** env);
    virtual int run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if ((run_)) {
            err = (this->*run_)(argc, argv, env);
        } else {
            err = this->usage(argc, argv, env);
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    int (Derives::*run_network_)(int argc, char_t** argv, char_t** env);
    virtual int run_network(int argc, char_t** argv, char_t** env) {
        int err = 1;
        if ((network::sockets::startup())) {
            if ((run_network_)) {
                err = (this->*run_network_)(argc, argv, env);
            } else {
                err = run_network_client(argc, argv, env);
            }
            network::sockets::cleanup();
        }
        return err;
    }

    ///
    /// client 
    /// 
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    int (Derives::*run_network_client_)(int argc, char_t** argv, char_t** env);
    virtual int run_network_client(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if ((run_network_client_)) {
            err = (this->*run_network_client_)(argc, argv, env);
        } else {
            err = run_stream_network_client(argc, argv, env);
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    int (Derives::*run_stream_network_client_)(int argc, char_t** argv, char_t** env);
    virtual int run_stream_network_client(int argc, char_t** argv, char_t** env) {
        int err = 0;
        network::transport* tp = 0;

        if ((tp = get_stream_network_transport())) {
            network::location* lc = 0;

            if ((lc = get_client_network_location())) {
                network::connection* cn = 0;
                
                if ((cn = get_client_network_connection(*tp))) {
                    
                    if ((cn->connect(*lc))) {
                        size_t length = 0;
                        
                        if (length <= (send(*cn, hello_request_))) {

                            recv(response_, *cn);
                        }
                        cn->disconnect();
                    }
                    release(cn);
                }
                release(lc);
            }
            release(tp);
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    network::connection* 
    (Derives::*get_client_network_connection_)(const network::transport& tp);
    virtual network::connection* get_client_network_connection(const network::transport& tp) {
        network::connection* cn = 0;
        if ((get_client_network_connection_)) {
            cn = (this->*get_client_network_connection_)(tp);
        } else {
            cn = get_socket_network_connection(tp);
        }
        return cn;
    }
    virtual network::connection* 
    get_socket_network_connection(const network::transport& tp) {
        network::connection* cn = 0;
        MEDUSA_LOG_DEBUG("try {...");
        try {
            MEDUSA_LOG_DEBUG("new network::socket::connection(network::transport& tp)...");
            cn = new network::sockets::connection(tp);
            MEDUSA_LOG_DEBUG("..." << pointer_to_string(cn) << " = new network::ip::v4::connection(network::transport& tp);");
        } catch (...) {
            MEDUSA_LOG_ERROR("...catch (...)");
        }
        return cn;
    }
    virtual void release(network::connection* cn) {
        if ((cn)) {
            MEDUSA_LOG_DEBUG("try {...");
            try {
                MEDUSA_LOG_DEBUG("delete cn = " << pointer_to_string(cn) << "...");
                delete cn;
            } catch (...) {
                MEDUSA_LOG_ERROR("...catch (...)");
            }
        }
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    network::location* (Derives::*get_client_network_location_)();
    virtual network::location* get_client_network_location() {
        network::location* lc = 0;
        if ((get_client_network_location_)) {
            lc = (this->*get_client_network_location_)();
        } else {
            lc = get_client_ip_network_location();
        }
        return lc;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    network::location* 
    (Derives::*get_client_ip_network_location_)(const char_t* host, ushort port);
    virtual network::location* get_client_ip_network_location() {
        network::location* lc = 0;
        const char_t* host = 0;
        ushort port = 0;
        if ((host = host_.has_chars()) && (port = portno_)) {
            if ((get_client_ip_network_location_)) {
                lc = (this->*get_client_ip_network_location_)(host, port);
            } else {
                lc = get_client_ip_v4_network_location(host, port);
            }
        }
        return lc;
    }
    virtual network::location* 
    get_client_ip_v4_network_location(const char_t* host, ushort port) {
        network::location* lc = 0;
        MEDUSA_LOG_DEBUG("try {...");
        try {
            MEDUSA_LOG_DEBUG("new network::ip::v4::location(host = \"" << host << "\", port = " << port << ")...");
            lc = new network::ip::v4::location(host, port);
            MEDUSA_LOG_DEBUG("..." << pointer_to_string(lc) << " = new network::ip::v4::location(host = \"" << host << "\", port = " << port << ");");
        } catch (...) {
            MEDUSA_LOG_ERROR("...catch (...)");
        }
        return lc;
    }
    virtual void release(network::location* lc) {
        if ((lc)) {
            MEDUSA_LOG_DEBUG("try {...");
            try {
                MEDUSA_LOG_DEBUG("delete lc = " << pointer_to_string(lc) << "...");
                delete lc;
            } catch (...) {
                MEDUSA_LOG_ERROR("...catch (...)");
            }
        }
    }
    
    ///
    /// server 
    /// 
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    int (Derives::*run_network_server_)(int argc, char_t** argv, char_t** env);
    virtual int run_network_server(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if ((run_network_server_)) {
            err = (this->*run_network_server_)(argc, argv, env);
        } else {
            err = run_stream_network_server(argc, argv, env);
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    int (Derives::*run_stream_network_server_)(int argc, char_t** argv, char_t** env);
    virtual int run_stream_network_server(int argc, char_t** argv, char_t** env) {
        int err = 0;
        network::transport* tp = 0;

        if ((tp = get_stream_network_transport())) {
            network::location* lc = 0;

            if ((lc = get_server_network_location())) {
                network::endpoint* ep = 0;
    
                if ((ep = get_server_network_endpoint())) {
                    network::connection* cn = 0;
        
                    if ((cn = get_server_network_connection())) {
                        network::location* clc = 0;
            
                        if ((clc = get_server_network_location())) {

                            if ((ep->listen(*tp, *lc))) {
                                bool done = true;
                                ssize_t count = 0;
    
                                do {
                                    if ((ep->accept(*cn, *clc))) {
                                        
                                        if (0 < (count = recv(request_, *cn))) {
                                            
                                            count = send(*cn, hello_response_);
                                        }
                                        cn->close();
                                    }
                                } while (!done);
                            }
                        }
                        release(cn);
                    }                    
                    release(ep);
                }                
                release(lc);
            }
            release(tp);
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    network::connection* (Derives::*get_server_network_connection_)();
    virtual network::connection* get_server_network_connection() {
        network::connection* cn = 0;
        if ((get_server_network_connection_)) {
            cn = (this->*get_server_network_connection_)();
        } else {
            cn = get_socket_network_connection();
        }
        return cn;
    }
    virtual network::connection* 
    get_socket_network_connection() {
        network::connection* cn = 0;
        MEDUSA_LOG_DEBUG("try {...");
        try {
            MEDUSA_LOG_DEBUG("new network::socket::connection()...");
            cn = new network::sockets::connection();
            MEDUSA_LOG_DEBUG("..." << pointer_to_string(cn) << " = new network::ip::v4::connection();");
        } catch (...) {
            MEDUSA_LOG_ERROR("...catch (...)");
        }
        return cn;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    network::location* (Derives::*get_server_network_location_)();
    virtual network::location* get_server_network_location() {
        network::location* lc = 0;
        if ((get_server_network_location_)) {
            lc = (this->*get_server_network_location_)();
        } else {
            lc = get_server_ip_network_location();
        }
        return lc;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    network::location* 
    (Derives::*get_server_ip_network_location_)(ushort port);
    virtual network::location* get_server_ip_network_location() {
        network::location* lc = 0;
        ushort port = 0;
        if ((port = server_portno_)) {
            if ((get_server_ip_network_location_)) {
                lc = (this->*get_server_ip_network_location_)(port);
            } else {
                lc = get_server_ip_v4_network_location(port);
            }
        }
        return lc;
    }
    virtual network::location* 
    get_server_ip_v4_network_location(ushort port) {
        network::location* lc = 0;
        MEDUSA_LOG_DEBUG("try {...");
        try {
            MEDUSA_LOG_DEBUG("new network::ip::v4::location(port = " << port << ")...");
            lc = new network::ip::v4::location(port);
            MEDUSA_LOG_DEBUG("..." << pointer_to_string(lc) << " = new network::ip::v4::location(port = " << port << ");");
        } catch (...) {
            MEDUSA_LOG_ERROR("...catch (...)");
        }
        return lc;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    network::endpoint* (Derives::*get_server_network_endpoint_)();
    virtual network::endpoint* get_server_network_endpoint() {
        network::endpoint* ep = 0;
        if ((get_server_network_endpoint_)) {
            ep = (this->*get_server_network_endpoint_)();
        } else {
            ep = get_server_ip_network_endpoint();
        }
        return ep;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    network::endpoint* (Derives::*get_server_ip_network_endpoint_)();
    virtual network::endpoint* get_server_ip_network_endpoint() {
        network::endpoint* ep = 0;
        ushort port = 0;
        if ((port = server_portno_)) {
            if ((get_server_ip_network_endpoint_)) {
                ep = (this->*get_server_ip_network_endpoint_)();
            } else {
                ep = get_server_ip_v4_network_endpoint();
            }
        }
        return ep;
    }
    virtual network::endpoint* 
    get_server_ip_v4_network_endpoint() {
        network::endpoint* ep = 0;
        MEDUSA_LOG_DEBUG("try {...");
        try {
            MEDUSA_LOG_DEBUG("new network::ip::v4::endpoint()...");
            ep = new network::ip::v4::endpoint();
            MEDUSA_LOG_DEBUG("..." << pointer_to_string(ep) << " = new network::ip::v4::endpoint();");
        } catch (...) {
            MEDUSA_LOG_ERROR("...catch (...)");
        }
        return ep;
    }
    virtual void release(network::endpoint* ep) {
        if ((ep)) {
            MEDUSA_LOG_DEBUG("try {...");
            try {
                MEDUSA_LOG_DEBUG("delete ep = " << pointer_to_string(ep) << "...");
                delete ep;
            } catch (...) {
                MEDUSA_LOG_ERROR("...catch (...)");
            }
        }
    }
    
    ///
    /// send/recv 
    /// 
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t send(network::connection& cn, const string_t& msg) {
        ssize_t count = 0;
        size_t length = 0;
        const char_t* chars = 0;
        if ((chars = msg.has_chars(length))) {
            MEDUSA_LOG_DEBUG("cn.send(chars = \"" << chars << "\", length = " << length << ")...");
            count = cn.send(chars, length);
        }
        return count;
    }
    virtual ssize_t recv(string_t& msg, network::connection& cn) {
        enum state {
            line, line_cr, 
            header, header_cr 
        };
        ssize_t count = 0, amount = 0;
        size_t length = 0;
        char_t c = 0;
        for (state s = line; 0 < (amount = cn.recv(&c, 1)); count += amount) {
            count += amount;
            this->out(&c, 1);
            switch (c) {
            case '\r':
                MEDUSA_LOG_DEBUG("...case '\\r'");
                switch(s) {
                case line:
                    s = line_cr;
                    break;
                case header:
                    s = header_cr;
                    break;
                case line_cr:
                case header_cr:
                    MEDUSA_LOG_DEBUG("...case '\\r''\\r'");
                default:
                    length += amount;
                    msg.append(&c, 1);
                    break;
                }
                break;
            case '\n':
                MEDUSA_LOG_DEBUG("...case '\\n'");
                switch(s) {
                case line:
                case line_cr:
                    MEDUSA_LOG_DEBUG("...line = \"" << msg << "\"")
                    msg.clear();
                    s = header;
                    length = 0;
                    break;
                case header:
                case header_cr:
                    if (length) {
                        MEDUSA_LOG_DEBUG("...header = \"" << msg << "\"")
                        msg.clear();
                        length = 0;
                        s = header;
                    } else {
                        return count;
                    }
                    break;
                default:
                    length += amount;
                    msg.append(&c, 1);
                    break;
                }
                break;
            default:
                length += amount;
                msg.append(&c, 1);
                break;
            }
        }
        return count;
    }

    ///
    /// transport
    /// 
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    network::transport* (Derives::*get_stream_network_transport_)();
    virtual network::transport* get_stream_network_transport() {
        network::transport* tp = 0;
        if ((get_stream_network_transport_)) {
            tp = (this->*get_stream_network_transport_)();
        } else {
            tp = get_ip_tcp_network_transport();
        }
        return tp;
    }
    virtual network::transport* get_ip_tcp_network_transport() {
        network::transport* tp = 0;
        MEDUSA_LOG_DEBUG("try {...");
        try {
            MEDUSA_LOG_DEBUG("new network::ip::tcp::transport()...");
            tp = new network::ip::tcp::transport();
            MEDUSA_LOG_DEBUG("..." << pointer_to_string(tp) << " = new network::ip::tcp::transport()...");
        } catch (...) {
            MEDUSA_LOG_ERROR("...catch (...)");
        }
        return tp;
    }
    virtual void release(network::transport* tp) {
        if ((tp)) {
            MEDUSA_LOG_DEBUG("try {...");
            try {
                MEDUSA_LOG_DEBUG("delete tp = " << pointer_to_string(tp) << "...");
                delete tp;
            } catch (...) {
                MEDUSA_LOG_ERROR("...catch (...)");
            }
        }
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int on_client_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        run_network_ = &Derives::run_network_client;
        run_ = &Derives::run_network;
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int on_server_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        run_network_ = &Derives::run_network_server;
        run_ = &Derives::run_network;
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int on_port_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            unsigned portno = chars_t::to_unsigned(optarg);
            if (0 < (portno)) {
                portno_ = (server_portno_ = portno);
                port_.assign(server_port_.assign(optarg));
            }
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    string_t request_, response_, 
             bye_request_, bye_response_,
             hello_request_, hello_response_, 
             host_, port_, server_port_;
    ushort portno_, server_portno_;
};

} // namespace hello 
} // namespace console 
} // namespace app 
} // namespace medusa 

#endif // _MEDUSA_APP_CONSOLE_HELLO_MAIN_HPP 
