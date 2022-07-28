///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2018 $organization$
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
///   Date: 12/21/2018
///////////////////////////////////////////////////////////////////////
#ifndef _CORAL_NADIR_CONSOLE_MAIN_HPP
#define _CORAL_NADIR_CONSOLE_MAIN_HPP

#include "coral/nadir/console/main_opt.hpp"
#include "nadir/console/getopt/main.hpp"

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define CORAL_CONSOLE_MAIN_LOGGING_LEVELS_OPT "logging"
#define CORAL_CONSOLE_MAIN_LOGGING_LEVELS_OPTARG_REQUIRED CORAL_MAIN_OPT_ARGUMENT_REQUIRED
#define CORAL_CONSOLE_MAIN_LOGGING_LEVELS_OPTARG_RESULT 0
#define CORAL_CONSOLE_MAIN_LOGGING_LEVELS_OPTARG CORAL_MAIN_LOGGING_OPTARG
#define CORAL_CONSOLE_MAIN_LOGGING_LEVELS_OPTUSE CORAL_MAIN_LOGGING_OPTUSE
#define CORAL_CONSOLE_MAIN_LOGGING_LEVELS_OPTVAL_S "l:"
#define CORAL_CONSOLE_MAIN_LOGGING_LEVELS_OPTVAL_C 'l'
#define CORAL_CONSOLE_MAIN_LOGGING_LEVELS_OPTION \
   {CORAL_CONSOLE_MAIN_LOGGING_LEVELS_OPT, \
    CORAL_CONSOLE_MAIN_LOGGING_LEVELS_OPTARG_REQUIRED, \
    CORAL_CONSOLE_MAIN_LOGGING_LEVELS_OPTARG_RESULT, \
    CORAL_CONSOLE_MAIN_LOGGING_LEVELS_OPTVAL_C}, \

#define CORAL_CONSOLE_MAIN_HELP_OPT "help"
#define CORAL_CONSOLE_MAIN_HELP_OPTARG_REQUIRED CORAL_MAIN_OPT_ARGUMENT_NONE
#define CORAL_CONSOLE_MAIN_HELP_OPTARG_RESULT 0
#define CORAL_CONSOLE_MAIN_HELP_OPTARG CORAL_MAIN_HELP_OPTARG
#define CORAL_CONSOLE_MAIN_HELP_OPTUSE CORAL_MAIN_HELP_OPTUSE
#define CORAL_CONSOLE_MAIN_HELP_OPTVAL_S "?"
#define CORAL_CONSOLE_MAIN_HELP_OPTVAL_C '?'
#define CORAL_CONSOLE_MAIN_HELP_OPTION \
   {CORAL_CONSOLE_MAIN_HELP_OPT, \
    CORAL_CONSOLE_MAIN_HELP_OPTARG_REQUIRED, \
    CORAL_CONSOLE_MAIN_HELP_OPTARG_RESULT, \
    CORAL_CONSOLE_MAIN_HELP_OPTVAL_C}, \

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define CORAL_CONSOLE_MAIN_OPTIONS_CHARS \
    CORAL_CONSOLE_MAIN_LOGGING_LEVELS_OPTVAL_S \
    CORAL_CONSOLE_MAIN_HELP_OPTVAL_S \

#define CORAL_CONSOLE_MAIN_OPTIONS_OPTIONS \
    CORAL_CONSOLE_MAIN_LOGGING_LEVELS_OPTION \
    CORAL_CONSOLE_MAIN_HELP_OPTION \
    
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

namespace coral {

namespace console {
typedef nadir::console::getopt::maint_implements main_implements;
typedef nadir::console::getopt::main main_extends;
///////////////////////////////////////////////////////////////////////
///  Class: main
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS main: virtual public main_implements, public main_extends {
public:
    typedef main_implements Implements;
    typedef main_extends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    main() {
    }
    virtual ~main() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int on_logging_levels_option
    (int optval, const char* optarg,
     const char* optname, int optind,
     int argc, char**argv, char**env) {
        int err = Extends::on_logging_option
        (CORAL_MAIN_LOGGING_OPTVAL_C, optarg, optname, optind, argc, argv, env);
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int on_help_option
    (int optval, const char* optarg,
     const char* optname, int optind,
     int argc, char**argv, char**env) {
        int err = Extends::on_usage_option
        (optval, optarg, optname, optind, argc, argv, env);
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
        case CORAL_CONSOLE_MAIN_LOGGING_LEVELS_OPTVAL_C:
            err = on_logging_levels_option
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case CORAL_CONSOLE_MAIN_HELP_OPTVAL_C:
            err = on_help_option
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
    virtual const char* option_usage
    (const char*& optarg, const struct option* longopt) {
        const char* chars = "";
        switch(longopt->val) {
        case CORAL_CONSOLE_MAIN_LOGGING_LEVELS_OPTVAL_C:
            optarg = CORAL_CONSOLE_MAIN_LOGGING_LEVELS_OPTARG;
            chars = CORAL_CONSOLE_MAIN_LOGGING_LEVELS_OPTUSE;
            break;
        case CORAL_CONSOLE_MAIN_HELP_OPTVAL_C:
            optarg = CORAL_CONSOLE_MAIN_HELP_OPTARG;
            chars = CORAL_CONSOLE_MAIN_HELP_OPTUSE;
            break;
        default:
            chars = Extends::option_usage(optarg, longopt);
        }
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char* options(const struct option*& longopts) {
        int err = 0;
        static const char* chars = CORAL_CONSOLE_MAIN_OPTIONS_CHARS;
        static struct option optstruct[]= {
            CORAL_CONSOLE_MAIN_OPTIONS_OPTIONS
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
} /// namespace console

} /// namespace coral

#endif /// ndef _CORAL_NADIR_CONSOLE_MAIN_HPP
