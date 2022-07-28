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
///   File: main_opt.cpp
///
/// Author: $author$
///   Date: 2/7/2015
///////////////////////////////////////////////////////////////////////
#ifndef _MEDUSA_DAEMON_MAIN_HPP
#include "medusa/daemon/main_opt.hpp"

namespace medusa {
namespace daemon {

typedef console::main_implement main_implements;
typedef console::main main_extends;
///////////////////////////////////////////////////////////////////////
///  Class: maint
///////////////////////////////////////////////////////////////////////
template
<class TImplements = main_implements, class TExtends = main_extends>

class _EXPORT_CLASS maint: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    maint() {
    }
    virtual ~maint() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
#endif // _MEDUSA_DAEMON_MAIN_HPP

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int on_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        switch(optval) {
        case MEDUSA_DAEMON_MAIN_RESTART_OPTVAL_C:
            err = on_restart_option
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case MEDUSA_DAEMON_MAIN_START_OPTVAL_C:
            err = on_start_option
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case MEDUSA_DAEMON_MAIN_STOP_OPTVAL_C:
            err = on_stop_option
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
        case MEDUSA_DAEMON_MAIN_RESTART_OPTVAL_C:
            optarg = MEDUSA_DAEMON_MAIN_RESTART_OPTARG;
            chars = MEDUSA_DAEMON_MAIN_RESTART_OPTUSE;
            break;
        case MEDUSA_DAEMON_MAIN_START_OPTVAL_C:
            optarg = MEDUSA_DAEMON_MAIN_START_OPTARG;
            chars = MEDUSA_DAEMON_MAIN_START_OPTUSE;
            break;
        case MEDUSA_DAEMON_MAIN_STOP_OPTVAL_C:
            optarg = MEDUSA_DAEMON_MAIN_STOP_OPTARG;
            chars = MEDUSA_DAEMON_MAIN_STOP_OPTUSE;
            break;
        default:
            chars = Extends::option_usage(optarg, longopt);
        }
        return chars;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* options(const struct option*& longopts) {
        int err = 0;
        static const char_t* chars = MEDUSA_DAEMON_MAIN_OPTIONS_CHARS;
        static struct option optstruct[]= {
            MEDUSA_DAEMON_MAIN_OPTIONS_OPTIONS
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }

#ifndef _MEDUSA_DAEMON_MAIN_HPP
};

} // namespace daemon 
} // namespace medusa 

#endif // _MEDUSA_DAEMON_MAIN_HPP
