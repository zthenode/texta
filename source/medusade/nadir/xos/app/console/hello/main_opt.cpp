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
///   File: main_opt.cpp
///
/// Author: $author$
///   Date: 12/3/2014
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_APP_CONSOLE_HELLO_MAIN_OPT_CPP
#define _XOS_NADIR_XOS_APP_CONSOLE_HELLO_MAIN_OPT_CPP

#ifndef _XOS_NADIR_XOS_APP_CONSOLE_HELLO_MAIN_HPP
#include "xos/base/getopt/main.hpp"

namespace xos {
namespace app {
namespace console {
namespace hello {

typedef xos::base::getopt::main main_extends;
///////////////////////////////////////////////////////////////////////
///  Class: main
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS main: public main_extends {
public:
    typedef main_extends Extends;
#endif // ndef _XOS_NADIR_XOS_APP_CONSOLE_HELLO_MAIN_HPP

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int on_message_option
    (int optval, const char* optarg,
     const char* optname, int optind,
     int argc, char**argv, char**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            set_message(optarg);
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int on_message_file_option
    (int optval, const char* optarg,
     const char* optname, int optind,
     int argc, char**argv, char**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            set_message_file(optarg);
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int on_input_option
    (int optval, const char* optarg,
     const char* optname, int optind,
     int argc, char**argv, char**env) {
        int err = 0;
        set_input();
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int on_client_option
    (int optval, const char* optarg,
     const char* optname, int optind,
     int argc, char**argv, char**env) {
        int err = 0;
        set_client();
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int on_server_option
    (int optval, const char* optarg,
     const char* optname, int optind,
     int argc, char**argv, char**env) {
        int err = 0;
        set_server();
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int on_host_option
    (int optval, const char* optarg,
     const char* optname, int optind,
     int argc, char**argv, char**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            set_host(optarg);
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int on_port_option
    (int optval, const char* optarg,
     const char* optname, int optind,
     int argc, char**argv, char**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            set_port(optarg);
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int on_family_option
    (int optval, const char* optarg,
     const char* optname, int optind,
     int argc, char**argv, char**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            set_family(optarg);
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int on_transport_option
    (int optval, const char* optarg,
     const char* optname, int optind,
     int argc, char**argv, char**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            set_transport(optarg);
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int on_logging_option
    (int optval, const char* optarg,
     const char* optname, int optind,
     int argc, char**argv, char**env) {
        int err = Extends::on_logging_option
        (XOS_MAIN_LOGGING_OPTVAL_C, optarg, optname, optind, argc, argv, env);
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int on_usage_option
    (int optval, const char* optarg,
     const char* optname, int optind,
     int argc, char**argv, char**env) {
        int err = Extends::on_usage_option
        (XOS_MAIN_HELP_OPTVAL_C, optarg, optname, optind, argc, argv, env);
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int on_option
    (int optval, const char* optarg,
     const char* optname, int optind,
     int argc, char**argv, char**env) {
        int err = 0;
        switch(optval) {
        case XOS_APP_CONSOLE_HELLO_MAIN_MESSAGE_OPTVAL_C:
            err = on_message_option
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_HELLO_MAIN_MESSAGE_FILE_OPTVAL_C:
            err = on_message_file_option
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_HELLO_MAIN_INPUT_OPTVAL_C:
            err = on_input_option
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_HELLO_MAIN_CLIENT_OPTVAL_C:
            err = on_client_option
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_HELLO_MAIN_SERVER_OPTVAL_C:
            err = on_server_option
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_HELLO_MAIN_HOST_OPTVAL_C:
            err = on_host_option
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_HELLO_MAIN_PORT_OPTVAL_C:
            err = on_port_option
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_HELLO_MAIN_FAMILY_OPTVAL_C:
            err = on_family_option
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_HELLO_MAIN_TRANSPORT_OPTVAL_C:
            err = on_transport_option
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_HELLO_MAIN_LOGGING_OPTVAL_C:
            err = on_logging_option
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_HELLO_MAIN_USAGE_OPTVAL_C:
            err = on_usage_option
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        default:
            err = Extends::on_option
            (optval, optarg, optname, optind, argc, argv, env);
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual const char* option_usage
    (const char*& optarg, const struct option* longopt) {
        const char* chars = "";
        switch(longopt->val) {
        case XOS_APP_CONSOLE_HELLO_MAIN_MESSAGE_OPTVAL_C:
            optarg = XOS_APP_CONSOLE_HELLO_MAIN_MESSAGE_OPTARG;
            chars = XOS_APP_CONSOLE_HELLO_MAIN_MESSAGE_OPTUSE;
            break;
        case XOS_APP_CONSOLE_HELLO_MAIN_MESSAGE_FILE_OPTVAL_C:
            optarg = XOS_APP_CONSOLE_HELLO_MAIN_MESSAGE_FILE_OPTARG;
            chars = XOS_APP_CONSOLE_HELLO_MAIN_MESSAGE_FILE_OPTUSE;
            break;
        case XOS_APP_CONSOLE_HELLO_MAIN_INPUT_OPTVAL_C:
            optarg = XOS_APP_CONSOLE_HELLO_MAIN_INPUT_OPTARG;
            chars = XOS_APP_CONSOLE_HELLO_MAIN_INPUT_OPTUSE;
            break;
        case XOS_APP_CONSOLE_HELLO_MAIN_CLIENT_OPTVAL_C:
            optarg = XOS_APP_CONSOLE_HELLO_MAIN_CLIENT_OPTARG;
            chars = XOS_APP_CONSOLE_HELLO_MAIN_CLIENT_OPTUSE;
            break;
        case XOS_APP_CONSOLE_HELLO_MAIN_SERVER_OPTVAL_C:
            optarg = XOS_APP_CONSOLE_HELLO_MAIN_SERVER_OPTARG;
            chars = XOS_APP_CONSOLE_HELLO_MAIN_SERVER_OPTUSE;
            break;
        case XOS_APP_CONSOLE_HELLO_MAIN_HOST_OPTVAL_C:
            optarg = XOS_APP_CONSOLE_HELLO_MAIN_HOST_OPTARG;
            chars = XOS_APP_CONSOLE_HELLO_MAIN_HOST_OPTUSE;
            break;
        case XOS_APP_CONSOLE_HELLO_MAIN_PORT_OPTVAL_C:
            optarg = XOS_APP_CONSOLE_HELLO_MAIN_PORT_OPTARG;
            chars = XOS_APP_CONSOLE_HELLO_MAIN_PORT_OPTUSE;
            break;
        case XOS_APP_CONSOLE_HELLO_MAIN_FAMILY_OPTVAL_C:
            optarg = XOS_APP_CONSOLE_HELLO_MAIN_FAMILY_OPTARG;
            chars = XOS_APP_CONSOLE_HELLO_MAIN_FAMILY_OPTUSE;
            break;
        case XOS_APP_CONSOLE_HELLO_MAIN_TRANSPORT_OPTVAL_C:
            optarg = XOS_APP_CONSOLE_HELLO_MAIN_TRANSPORT_OPTARG;
            chars = XOS_APP_CONSOLE_HELLO_MAIN_TRANSPORT_OPTUSE;
            break;
        case XOS_APP_CONSOLE_HELLO_MAIN_LOGGING_OPTVAL_C:
            optarg = XOS_APP_CONSOLE_HELLO_MAIN_LOGGING_OPTARG;
            chars = XOS_APP_CONSOLE_HELLO_MAIN_LOGGING_OPTUSE;
            break;
        case XOS_APP_CONSOLE_HELLO_MAIN_USAGE_OPTVAL_C:
            optarg = XOS_APP_CONSOLE_HELLO_MAIN_USAGE_OPTARG;
            chars = XOS_APP_CONSOLE_HELLO_MAIN_USAGE_OPTUSE;
            break;
        default:
            chars = Extends::option_usage(optarg, longopt);
        }
        return chars;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual const char* options(const struct option*& longopts) {
        int err = 0;
        static const char* chars = XOS_APP_CONSOLE_HELLO_MAIN_OPTIONS_CHARS;
        static struct option optstruct[]= {
            XOS_APP_CONSOLE_HELLO_MAIN_OPTIONS_OPTIONS
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }

#ifndef _XOS_NADIR_XOS_APP_CONSOLE_HELLO_MAIN_HPP
};

} // namespace hello 
} // namespace console 
} // namespace app 
} // namespace xos 
#endif // ndef _XOS_NADIR_XOS_APP_CONSOLE_HELLO_MAIN_HPP

#endif // _XOS_NADIR_XOS_APP_CONSOLE_HELLO_MAIN_OPT_CPP 
