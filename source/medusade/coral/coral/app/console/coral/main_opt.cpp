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
///   Date: 12/17/2014
///////////////////////////////////////////////////////////////////////
#ifndef _CORAL_APP_CONSOLE_CORAL_MAIN_OPT_CPP
#define _CORAL_APP_CONSOLE_CORAL_MAIN_OPT_CPP

#if !defined(_CORAL_APP_CONSOLE_CORAL_MAIN_HPP)
#include "coral/console/main.hpp"

namespace coral {
namespace app {
namespace console {
namespace coral {

typedef ::coral::console::main_implements main_implements;
typedef ::coral::console::main main_extends;
///////////////////////////////////////////////////////////////////////
///  Class: main
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS main: virtual public main_implements, public main_extends {
public:
    typedef main_implements Implements;
    typedef main_extends Extends;
#endif // !defined(_CORAL_APP_CONSOLE_CORAL_MAIN_HPP)

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int on_argv_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            CORAL_LOG_DEBUG("optarg = \"" << optarg << "\"...");
            if (!(set_argv(optarg))) {
                CORAL_LOG_ERROR("...failed on set_argv(\"" << optarg << "\")");
            }
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int on_env_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            CORAL_LOG_DEBUG("optarg = \"" << optarg << "\"...");
            if (!(set_env(optarg))) {
                CORAL_LOG_ERROR("...failed on set_env(\"" << optarg << "\")");
            }
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int on_input_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            CORAL_LOG_DEBUG("optarg = \"" << optarg << "\"...");
            if (!(set_input(optarg))) {
                CORAL_LOG_ERROR("...failed on set_input(\"" << optarg << "\")");
            }
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int on_output_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            CORAL_LOG_DEBUG("optarg = \"" << optarg << "\"...");
            if (!(set_output(optarg))) {
                CORAL_LOG_ERROR("...failed on set_output(\"" << optarg << "\")");
            }
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int on_stdin_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            CORAL_LOG_DEBUG("optarg = \"" << optarg << "\"...");
            if (!(set_stdin(optarg))) {
                CORAL_LOG_ERROR("...failed on set_stdin(\"" << optarg << "\")");
            }
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int on_stdout_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            CORAL_LOG_DEBUG("optarg = \"" << optarg << "\"...");
            if (!(set_stdout(optarg))) {
                CORAL_LOG_ERROR("...failed on set_stdout(\"" << optarg << "\")");
            }
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int on_stderr_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            CORAL_LOG_DEBUG("optarg = \"" << optarg << "\"...");
            if (!(set_stderr(optarg))) {
                CORAL_LOG_ERROR("...failed on set_stderr(\"" << optarg << "\")");
            }
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
        case CORAL_APP_CONSOLE_CORAL_MAIN_ARGV_OPTVAL_C:
            err = on_argv_option
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case CORAL_APP_CONSOLE_CORAL_MAIN_ENV_OPTVAL_C:
            err = on_env_option
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case CORAL_APP_CONSOLE_CORAL_MAIN_INPUT_OPTVAL_C:
            err = on_input_option
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case CORAL_APP_CONSOLE_CORAL_MAIN_OUTPUT_OPTVAL_C:
            err = on_output_option
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case CORAL_APP_CONSOLE_CORAL_MAIN_STDIN_OPTVAL_C:
            err = on_stdin_option
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case CORAL_APP_CONSOLE_CORAL_MAIN_STDOUT_OPTVAL_C:
            err = on_stdout_option
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case CORAL_APP_CONSOLE_CORAL_MAIN_STDERR_OPTVAL_C:
            err = on_stderr_option
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        default:
            err = Extends::on_option
            (optval, optarg, optname, optind, argc, argv, env);
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* option_usage
    (const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = "";
        switch(longopt->val) {
        case CORAL_APP_CONSOLE_CORAL_MAIN_ARGV_OPTVAL_C:
            optarg = CORAL_APP_CONSOLE_CORAL_MAIN_ARGV_OPTARG;
            chars = CORAL_APP_CONSOLE_CORAL_MAIN_ARGV_OPTUSE;
            break;
        case CORAL_APP_CONSOLE_CORAL_MAIN_ENV_OPTVAL_C:
            optarg = CORAL_APP_CONSOLE_CORAL_MAIN_ENV_OPTARG;
            chars = CORAL_APP_CONSOLE_CORAL_MAIN_ENV_OPTUSE;
            break;
        case CORAL_APP_CONSOLE_CORAL_MAIN_INPUT_OPTVAL_C:
            optarg = CORAL_APP_CONSOLE_CORAL_MAIN_INPUT_OPTARG;
            chars = CORAL_APP_CONSOLE_CORAL_MAIN_INPUT_OPTUSE;
            break;
        case CORAL_APP_CONSOLE_CORAL_MAIN_OUTPUT_OPTVAL_C:
            optarg = CORAL_APP_CONSOLE_CORAL_MAIN_OUTPUT_OPTARG;
            chars = CORAL_APP_CONSOLE_CORAL_MAIN_OUTPUT_OPTUSE;
            break;
        case CORAL_APP_CONSOLE_CORAL_MAIN_STDIN_OPTVAL_C:
            optarg = CORAL_APP_CONSOLE_CORAL_MAIN_STDIN_OPTARG;
            chars = CORAL_APP_CONSOLE_CORAL_MAIN_STDIN_OPTUSE;
            break;
        case CORAL_APP_CONSOLE_CORAL_MAIN_STDOUT_OPTVAL_C:
            optarg = CORAL_APP_CONSOLE_CORAL_MAIN_STDOUT_OPTARG;
            chars = CORAL_APP_CONSOLE_CORAL_MAIN_STDOUT_OPTUSE;
            break;
        case CORAL_APP_CONSOLE_CORAL_MAIN_STDERR_OPTVAL_C:
            optarg = CORAL_APP_CONSOLE_CORAL_MAIN_STDERR_OPTARG;
            chars = CORAL_APP_CONSOLE_CORAL_MAIN_STDERR_OPTUSE;
            break;
        default:
            chars = Extends::option_usage(optarg, longopt);
        }
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* options(const struct option*& longopts) {
        int err = 0;
        static const char_t* chars = CORAL_APP_CONSOLE_CORAL_MAIN_OPTIONS_CHARS;
        static struct option optstruct[]= {
            CORAL_APP_CONSOLE_CORAL_MAIN_OPTIONS_OPTIONS
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }

#if !defined(_CORAL_APP_CONSOLE_CORAL_MAIN_HPP)
};

} // namespace coral 
} // namespace console 
} // namespace app 
} // namespace coral 
#endif // !defined(_CORAL_APP_CONSOLE_CORAL_MAIN_HPP)

#endif // _CORAL_APP_CONSOLE_CORAL_MAIN_OPT_CPP 
        

