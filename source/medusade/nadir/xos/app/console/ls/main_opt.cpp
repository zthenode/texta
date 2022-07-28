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
///   Date: 4/1/2015
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_APP_CONSOLE_LS_MAIN_OPT_CPP
#define _XOS_NADIR_XOS_APP_CONSOLE_LS_MAIN_OPT_CPP

#ifndef _XOS_NADIR_XOS_APP_CONSOLE_LS_MAIN_HPP
#include "xos/base/getopt/main.hpp"

namespace xos {
namespace app {
namespace console {
namespace ls {

typedef base::getopt::main_implement main_implement;
typedef base::getopt::main main_extend;
///////////////////////////////////////////////////////////////////////
///  Class: main
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS main: virtual public main_implement, public main_extend {
public:
    typedef main_implement Implements;
    typedef main_extend Extends;
#endif // _XOS_NADIR_XOS_APP_CONSOLE_LS_MAIN_HPP

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* set_recursive(const char_t* to) {
        this->is_recursive_ = true;
        return to;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* set_reflective(const char_t* to) {
        this->is_reflective_ = true;
        return to;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int on_recursive_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        set_recursive(optarg);
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int on_reflective_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        set_reflective(optarg);
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
        case XOS_APP_CONSOLE_LS_MAIN_RECURSIVE_OPTVAL_C:
            err = on_recursive_option
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_LS_MAIN_REFLECTIVE_OPTVAL_C:
            err = on_reflective_option
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
        case XOS_APP_CONSOLE_LS_MAIN_RECURSIVE_OPTVAL_C:
            optarg = XOS_APP_CONSOLE_LS_MAIN_RECURSIVE_OPTARG;
            chars = XOS_APP_CONSOLE_LS_MAIN_RECURSIVE_OPTUSE;
            break;
        case XOS_APP_CONSOLE_LS_MAIN_REFLECTIVE_OPTVAL_C:
            optarg = XOS_APP_CONSOLE_LS_MAIN_REFLECTIVE_OPTARG;
            chars = XOS_APP_CONSOLE_LS_MAIN_REFLECTIVE_OPTUSE;
            break;
        default:
            chars = Extends::option_usage(optarg, longopt);
        }
        return chars;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* options(const struct option*& longopts) {
        int err = 0;
        static const char_t* chars = XOS_APP_CONSOLE_LS_MAIN_OPTIONS_CHARS;
        static struct option optstruct[]= {
            XOS_APP_CONSOLE_LS_MAIN_OPTIONS_OPTIONS
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char* arguments(const char**& args) {
        static const char* argv[] = {
            XOS_APP_CONSOLE_LS_MAIN_ARGV
            0};
        args = argv;
        return XOS_APP_CONSOLE_LS_MAIN_ARGS;
    }

#ifndef _XOS_NADIR_XOS_APP_CONSOLE_LS_MAIN_HPP
};

} // namespace ls 
} // namespace console 
} // namespace app 
} // namespace xos 
#endif // _XOS_NADIR_XOS_APP_CONSOLE_LS_MAIN_HPP

#endif // _XOS_NADIR_XOS_APP_CONSOLE_LS_MAIN_OPT_CPP 
