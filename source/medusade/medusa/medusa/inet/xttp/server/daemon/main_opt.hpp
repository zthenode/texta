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
#ifndef _MEDUSA_INET_XTTP_SERVER_DAEMON_MAIN_OPT_HPP
#define _MEDUSA_INET_XTTP_SERVER_DAEMON_MAIN_OPT_HPP

#include "medusa/daemon/main.hpp"

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define MEDUSA_INET_XTTP_SERVER_DAEMON_MAIN_HOST_OPT "host"
#define MEDUSA_INET_XTTP_SERVER_DAEMON_MAIN_HOST_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_REQUIRED
#define MEDUSA_INET_XTTP_SERVER_DAEMON_MAIN_HOST_OPTARG_RESULT 0
#define MEDUSA_INET_XTTP_SERVER_DAEMON_MAIN_HOST_OPTARG "{ ddd.ddd.ddd.ddd | name }"
#define MEDUSA_INET_XTTP_SERVER_DAEMON_MAIN_HOST_OPTUSE "host name or address"
#define MEDUSA_INET_XTTP_SERVER_DAEMON_MAIN_HOST_OPTVAL_S "h:"
#define MEDUSA_INET_XTTP_SERVER_DAEMON_MAIN_HOST_OPTVAL_C 'h'
#define MEDUSA_INET_XTTP_SERVER_DAEMON_MAIN_HOST_OPTION \
   {MEDUSA_INET_XTTP_SERVER_DAEMON_MAIN_HOST_OPT, \
    MEDUSA_INET_XTTP_SERVER_DAEMON_MAIN_HOST_OPTARG_REQUIRED, \
    MEDUSA_INET_XTTP_SERVER_DAEMON_MAIN_HOST_OPTARG_RESULT, \
    MEDUSA_INET_XTTP_SERVER_DAEMON_MAIN_HOST_OPTVAL_C}, \

#define MEDUSA_INET_XTTP_SERVER_DAEMON_MAIN_PORT_OPT "port"
#define MEDUSA_INET_XTTP_SERVER_DAEMON_MAIN_PORT_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_REQUIRED
#define MEDUSA_INET_XTTP_SERVER_DAEMON_MAIN_PORT_OPTARG_RESULT 0
#define MEDUSA_INET_XTTP_SERVER_DAEMON_MAIN_PORT_OPTARG "{0..2^16-1}"
#define MEDUSA_INET_XTTP_SERVER_DAEMON_MAIN_PORT_OPTUSE "host port number"
#define MEDUSA_INET_XTTP_SERVER_DAEMON_MAIN_PORT_OPTVAL_S "p:"
#define MEDUSA_INET_XTTP_SERVER_DAEMON_MAIN_PORT_OPTVAL_C 'p'
#define MEDUSA_INET_XTTP_SERVER_DAEMON_MAIN_PORT_OPTION \
   {MEDUSA_INET_XTTP_SERVER_DAEMON_MAIN_PORT_OPT, \
    MEDUSA_INET_XTTP_SERVER_DAEMON_MAIN_PORT_OPTARG_REQUIRED, \
    MEDUSA_INET_XTTP_SERVER_DAEMON_MAIN_PORT_OPTARG_RESULT, \
    MEDUSA_INET_XTTP_SERVER_DAEMON_MAIN_PORT_OPTVAL_C}, \

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define MEDUSA_INET_XTTP_SERVER_DAEMON_MAIN_OPTIONS_CHARS \
   MEDUSA_INET_XTTP_SERVER_DAEMON_MAIN_HOST_OPTVAL_S \
   MEDUSA_INET_XTTP_SERVER_DAEMON_MAIN_PORT_OPTVAL_S \
   MEDUSA_DAEMON_MAIN_OPTIONS_CHARS

#define MEDUSA_INET_XTTP_SERVER_DAEMON_MAIN_OPTIONS_OPTIONS \
   MEDUSA_INET_XTTP_SERVER_DAEMON_MAIN_HOST_OPTION \
   MEDUSA_INET_XTTP_SERVER_DAEMON_MAIN_PORT_OPTION \
   MEDUSA_DAEMON_MAIN_OPTIONS_OPTIONS

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define MEDUSA_INET_XTTP_SERVER_DAEMON_MAIN_ARGS 0
#define MEDUSA_INET_XTTP_SERVER_DAEMON_MAIN_ARGV

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

namespace medusa {
namespace inet {
namespace xttp {
namespace server {
namespace daemon {

typedef ::medusa::daemon::main::Implements main_opt_implements;
typedef ::medusa::daemon::main main_opt_extends;
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
    ///////////////////////////////////////////////////////////////////////
    virtual int on_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        switch(optval) {
        case MEDUSA_INET_XTTP_SERVER_DAEMON_MAIN_HOST_OPTVAL_C:
            err = on_host_option
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case MEDUSA_INET_XTTP_SERVER_DAEMON_MAIN_PORT_OPTVAL_C:
            err = on_port_option
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
        case MEDUSA_INET_XTTP_SERVER_DAEMON_MAIN_HOST_OPTVAL_C:
            optarg = MEDUSA_INET_XTTP_SERVER_DAEMON_MAIN_HOST_OPTARG;
            chars = MEDUSA_INET_XTTP_SERVER_DAEMON_MAIN_HOST_OPTUSE;
            break;
        case MEDUSA_INET_XTTP_SERVER_DAEMON_MAIN_PORT_OPTVAL_C:
            optarg = MEDUSA_INET_XTTP_SERVER_DAEMON_MAIN_PORT_OPTARG;
            chars = MEDUSA_INET_XTTP_SERVER_DAEMON_MAIN_PORT_OPTUSE;
            break;
        default:
            chars = Extends::option_usage(optarg, longopt);
        }
        return chars;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* options(const struct option*& longopts) {
        int err = 0;
        static const char_t* chars = MEDUSA_INET_XTTP_SERVER_DAEMON_MAIN_OPTIONS_CHARS;
        static struct option optstruct[]= {
            MEDUSA_INET_XTTP_SERVER_DAEMON_MAIN_OPTIONS_OPTIONS
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }
    
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* arguments(const char_t**& argv) {
        static const char_t* _args = MEDUSA_INET_XTTP_SERVER_DAEMON_MAIN_ARGS;
        static const char_t* _argv[] = {
            MEDUSA_INET_XTTP_SERVER_DAEMON_MAIN_ARGV
            0};
        argv = _argv;
        return _args;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
}; /// class _EXPORT_CLASS main_opt

} /// namespace daemon
} /// namespace server
} /// namespace xttp
} /// namespace inet
} /// namespace medusa

#endif ///ndef _MEDUSA_INET_XTTP_SERVER_DAEMON_MAIN_OPT_HPP
