///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2019 $organization$
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
///   File: main_opt.hpp
///
/// Author: $author$
///   Date: 1/12/2019
///////////////////////////////////////////////////////////////////////
#ifndef _MEDUSA_APP_CONSOLE_HELLO_MAIN_OPT_HPP
#define _MEDUSA_APP_CONSOLE_HELLO_MAIN_OPT_HPP

#include "medusa/console/main.hpp"

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define MEDUSA_APP_CONSOLE_HELLO_MAIN_CLIENT_OPT "client"
#define MEDUSA_APP_CONSOLE_HELLO_MAIN_CLIENT_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define MEDUSA_APP_CONSOLE_HELLO_MAIN_CLIENT_OPTARG_RESULT 0
#define MEDUSA_APP_CONSOLE_HELLO_MAIN_CLIENT_OPTARG ""
#define MEDUSA_APP_CONSOLE_HELLO_MAIN_CLIENT_OPTUSE "run as client"
#define MEDUSA_APP_CONSOLE_HELLO_MAIN_CLIENT_OPTVAL_S "c"
#define MEDUSA_APP_CONSOLE_HELLO_MAIN_CLIENT_OPTVAL_C 'c'
#define MEDUSA_APP_CONSOLE_HELLO_MAIN_CLIENT_OPTION \
   {MEDUSA_APP_CONSOLE_HELLO_MAIN_CLIENT_OPT, \
    MEDUSA_APP_CONSOLE_HELLO_MAIN_CLIENT_OPTARG_REQUIRED, \
    MEDUSA_APP_CONSOLE_HELLO_MAIN_CLIENT_OPTARG_RESULT, \
    MEDUSA_APP_CONSOLE_HELLO_MAIN_CLIENT_OPTVAL_C}, \

#define MEDUSA_APP_CONSOLE_HELLO_MAIN_SERVER_OPT "server"
#define MEDUSA_APP_CONSOLE_HELLO_MAIN_SERVER_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define MEDUSA_APP_CONSOLE_HELLO_MAIN_SERVER_OPTARG_RESULT 0
#define MEDUSA_APP_CONSOLE_HELLO_MAIN_SERVER_OPTARG ""
#define MEDUSA_APP_CONSOLE_HELLO_MAIN_SERVER_OPTUSE "run as server"
#define MEDUSA_APP_CONSOLE_HELLO_MAIN_SERVER_OPTVAL_S "s"
#define MEDUSA_APP_CONSOLE_HELLO_MAIN_SERVER_OPTVAL_C 's'
#define MEDUSA_APP_CONSOLE_HELLO_MAIN_SERVER_OPTION \
   {MEDUSA_APP_CONSOLE_HELLO_MAIN_SERVER_OPT, \
    MEDUSA_APP_CONSOLE_HELLO_MAIN_SERVER_OPTARG_REQUIRED, \
    MEDUSA_APP_CONSOLE_HELLO_MAIN_SERVER_OPTARG_RESULT, \
    MEDUSA_APP_CONSOLE_HELLO_MAIN_SERVER_OPTVAL_C}, \

#define MEDUSA_APP_CONSOLE_HELLO_MAIN_HOST_OPT "host"
#define MEDUSA_APP_CONSOLE_HELLO_MAIN_HOST_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_REQUIRED
#define MEDUSA_APP_CONSOLE_HELLO_MAIN_HOST_OPTARG_RESULT 0
#define MEDUSA_APP_CONSOLE_HELLO_MAIN_HOST_OPTARG "{ ddd.ddd.ddd.ddd | name }"
#define MEDUSA_APP_CONSOLE_HELLO_MAIN_HOST_OPTUSE "host address"
#define MEDUSA_APP_CONSOLE_HELLO_MAIN_HOST_OPTVAL_S "h:"
#define MEDUSA_APP_CONSOLE_HELLO_MAIN_HOST_OPTVAL_C 'h'
#define MEDUSA_APP_CONSOLE_HELLO_MAIN_HOST_OPTION \
   {MEDUSA_APP_CONSOLE_HELLO_MAIN_HOST_OPT, \
    MEDUSA_APP_CONSOLE_HELLO_MAIN_HOST_OPTARG_REQUIRED, \
    MEDUSA_APP_CONSOLE_HELLO_MAIN_HOST_OPTARG_RESULT, \
    MEDUSA_APP_CONSOLE_HELLO_MAIN_HOST_OPTVAL_C}, \

#define MEDUSA_APP_CONSOLE_HELLO_MAIN_PORT_OPT "port"
#define MEDUSA_APP_CONSOLE_HELLO_MAIN_PORT_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_REQUIRED
#define MEDUSA_APP_CONSOLE_HELLO_MAIN_PORT_OPTARG_RESULT 0
#define MEDUSA_APP_CONSOLE_HELLO_MAIN_PORT_OPTARG "{0..2^16-1}"
#define MEDUSA_APP_CONSOLE_HELLO_MAIN_PORT_OPTUSE "port number"
#define MEDUSA_APP_CONSOLE_HELLO_MAIN_PORT_OPTVAL_S "p:"
#define MEDUSA_APP_CONSOLE_HELLO_MAIN_PORT_OPTVAL_C 'p'
#define MEDUSA_APP_CONSOLE_HELLO_MAIN_PORT_OPTION \
   {MEDUSA_APP_CONSOLE_HELLO_MAIN_PORT_OPT, \
    MEDUSA_APP_CONSOLE_HELLO_MAIN_PORT_OPTARG_REQUIRED, \
    MEDUSA_APP_CONSOLE_HELLO_MAIN_PORT_OPTARG_RESULT, \
    MEDUSA_APP_CONSOLE_HELLO_MAIN_PORT_OPTVAL_C}, \

#define MEDUSA_APP_CONSOLE_HELLO_MAIN_FAMILY_OPT "family"
#define MEDUSA_APP_CONSOLE_HELLO_MAIN_FAMILY_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_REQUIRED
#define MEDUSA_APP_CONSOLE_HELLO_MAIN_FAMILY_OPTARG_RESULT 0
#define MEDUSA_APP_CONSOLE_HELLO_MAIN_FAMILY_OPTARG "{ (4)ipv4 | (6)ipv6 | (l)local }"
#define MEDUSA_APP_CONSOLE_HELLO_MAIN_FAMILY_OPTUSE "address family"
#define MEDUSA_APP_CONSOLE_HELLO_MAIN_FAMILY_OPTVAL_S "f:"
#define MEDUSA_APP_CONSOLE_HELLO_MAIN_FAMILY_OPTVAL_C 'f'
#define MEDUSA_APP_CONSOLE_HELLO_MAIN_FAMILY_OPTION \
   {MEDUSA_APP_CONSOLE_HELLO_MAIN_FAMILY_OPT, \
    MEDUSA_APP_CONSOLE_HELLO_MAIN_FAMILY_OPTARG_REQUIRED, \
    MEDUSA_APP_CONSOLE_HELLO_MAIN_FAMILY_OPTARG_RESULT, \
    MEDUSA_APP_CONSOLE_HELLO_MAIN_FAMILY_OPTVAL_C}, \

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define MEDUSA_APP_CONSOLE_HELLO_MAIN_OPTIONS_CHARS \
   MEDUSA_APP_CONSOLE_HELLO_MAIN_CLIENT_OPTVAL_S \
   MEDUSA_APP_CONSOLE_HELLO_MAIN_SERVER_OPTVAL_S \
   MEDUSA_APP_CONSOLE_HELLO_MAIN_HOST_OPTVAL_S \
   MEDUSA_APP_CONSOLE_HELLO_MAIN_PORT_OPTVAL_S \
   MEDUSA_APP_CONSOLE_HELLO_MAIN_FAMILY_OPTVAL_S \
   MEDUSA_CONSOLE_MAIN_OPTIONS_CHARS

#define MEDUSA_APP_CONSOLE_HELLO_MAIN_OPTIONS_OPTIONS \
   MEDUSA_APP_CONSOLE_HELLO_MAIN_CLIENT_OPTION \
   MEDUSA_APP_CONSOLE_HELLO_MAIN_SERVER_OPTION \
   MEDUSA_APP_CONSOLE_HELLO_MAIN_HOST_OPTION \
   MEDUSA_APP_CONSOLE_HELLO_MAIN_PORT_OPTION \
   MEDUSA_APP_CONSOLE_HELLO_MAIN_FAMILY_OPTION \
   MEDUSA_CONSOLE_MAIN_OPTIONS_OPTIONS

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define MEDUSA_APP_CONSOLE_HELLO_MAIN_ARGS 0
#define MEDUSA_APP_CONSOLE_HELLO_MAIN_ARGV

namespace medusa {
namespace app {
namespace console {
namespace hello {

typedef ::medusa::console::main::Implements main_opt_implements;
typedef ::medusa::console::main main_opt_extends;
///////////////////////////////////////////////////////////////////////
///  Class: main_opt
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS main_opt: virtual public main_opt_implements, public main_opt_extends {
public:
    typedef main_opt_implements Implements;
    typedef main_opt_extends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    main_opt() {}
    virtual ~main_opt() {}
private:
    main_opt(const main_opt& copy) {}

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int on_client_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int on_server_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int on_host_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
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
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int on_family_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int on_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        switch(optval) {
        case MEDUSA_APP_CONSOLE_HELLO_MAIN_CLIENT_OPTVAL_C:
            err = on_client_option
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case MEDUSA_APP_CONSOLE_HELLO_MAIN_SERVER_OPTVAL_C:
            err = on_server_option
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case MEDUSA_APP_CONSOLE_HELLO_MAIN_HOST_OPTVAL_C:
            err = on_host_option
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case MEDUSA_APP_CONSOLE_HELLO_MAIN_PORT_OPTVAL_C:
            err = on_port_option
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case MEDUSA_APP_CONSOLE_HELLO_MAIN_FAMILY_OPTVAL_C:
            err = on_family_option
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        default:
            err = Extends::on_option
            (optval, optarg, optname, optind, argc, argv, env);
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* option_usage
    (const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = "";
        switch(longopt->val) {
        case MEDUSA_APP_CONSOLE_HELLO_MAIN_CLIENT_OPTVAL_C:
            optarg = MEDUSA_APP_CONSOLE_HELLO_MAIN_CLIENT_OPTARG;
            chars = MEDUSA_APP_CONSOLE_HELLO_MAIN_CLIENT_OPTUSE;
            break;
        case MEDUSA_APP_CONSOLE_HELLO_MAIN_SERVER_OPTVAL_C:
            optarg = MEDUSA_APP_CONSOLE_HELLO_MAIN_SERVER_OPTARG;
            chars = MEDUSA_APP_CONSOLE_HELLO_MAIN_SERVER_OPTUSE;
            break;
        case MEDUSA_APP_CONSOLE_HELLO_MAIN_HOST_OPTVAL_C:
            optarg = MEDUSA_APP_CONSOLE_HELLO_MAIN_HOST_OPTARG;
            chars = MEDUSA_APP_CONSOLE_HELLO_MAIN_HOST_OPTUSE;
            break;
        case MEDUSA_APP_CONSOLE_HELLO_MAIN_PORT_OPTVAL_C:
            optarg = MEDUSA_APP_CONSOLE_HELLO_MAIN_PORT_OPTARG;
            chars = MEDUSA_APP_CONSOLE_HELLO_MAIN_PORT_OPTUSE;
            break;
        case MEDUSA_APP_CONSOLE_HELLO_MAIN_FAMILY_OPTVAL_C:
            optarg = MEDUSA_APP_CONSOLE_HELLO_MAIN_FAMILY_OPTARG;
            chars = MEDUSA_APP_CONSOLE_HELLO_MAIN_FAMILY_OPTUSE;
            break;
        default:
            chars = Extends::option_usage(optarg, longopt);
        }
        return chars;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* options(const struct option*& longopts) {
        int err = 0;
        static const char_t* chars = MEDUSA_APP_CONSOLE_HELLO_MAIN_OPTIONS_CHARS;
        static struct option optstruct[]= {
            MEDUSA_APP_CONSOLE_HELLO_MAIN_OPTIONS_OPTIONS
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* arguments(const char_t**& argv) {
        static const char_t* _args = MEDUSA_APP_CONSOLE_HELLO_MAIN_ARGS;
        static const char_t* _argv[] = {
            MEDUSA_APP_CONSOLE_HELLO_MAIN_ARGV
            0};
        argv = _argv;
        return _args;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
}; /// class _EXPORT_CLASS main_opt

} /// namespace hello
} /// namespace console
} /// namespace app
} /// namespace medusa

#endif ///ndef _MEDUSA_APP_CONSOLE_HELLO_MAIN_OPT_HPP
