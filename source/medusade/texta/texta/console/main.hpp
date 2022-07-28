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
///   Date: 6/2/2016
///////////////////////////////////////////////////////////////////////
#ifndef _TEXTA_CONSOLE_MAIN_HPP
#define _TEXTA_CONSOLE_MAIN_HPP

#include "texta/console/main_opt.hpp"
#include "texta/base/base.hpp"

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define TEXTA_CONSOLE_MAIN_LOGGING_LEVELS_OPT "logging"
#define TEXTA_CONSOLE_MAIN_LOGGING_LEVELS_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_REQUIRED
#define TEXTA_CONSOLE_MAIN_LOGGING_LEVELS_OPTARG_RESULT 0
#define TEXTA_CONSOLE_MAIN_LOGGING_LEVELS_OPTARG TEXTA_MAIN_LOGGING_OPTARG
#define TEXTA_CONSOLE_MAIN_LOGGING_LEVELS_OPTUSE TEXTA_MAIN_LOGGING_OPTUSE
#define TEXTA_CONSOLE_MAIN_LOGGING_LEVELS_OPTVAL_S "l:"
#define TEXTA_CONSOLE_MAIN_LOGGING_LEVELS_OPTVAL_C 'l'
#define TEXTA_CONSOLE_MAIN_LOGGING_LEVELS_OPTION \
   {TEXTA_CONSOLE_MAIN_LOGGING_LEVELS_OPT, \
    TEXTA_CONSOLE_MAIN_LOGGING_LEVELS_OPTARG_REQUIRED, \
    TEXTA_CONSOLE_MAIN_LOGGING_LEVELS_OPTARG_RESULT, \
    TEXTA_CONSOLE_MAIN_LOGGING_LEVELS_OPTVAL_C}, \

#define TEXTA_CONSOLE_MAIN_HELP_OPT "help"
#define TEXTA_CONSOLE_MAIN_HELP_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define TEXTA_CONSOLE_MAIN_HELP_OPTARG_RESULT 0
#define TEXTA_CONSOLE_MAIN_HELP_OPTARG TEXTA_MAIN_HELP_OPTARG
#define TEXTA_CONSOLE_MAIN_HELP_OPTUSE TEXTA_MAIN_HELP_OPTUSE
#define TEXTA_CONSOLE_MAIN_HELP_OPTVAL_S "?"
#define TEXTA_CONSOLE_MAIN_HELP_OPTVAL_C '?'
#define TEXTA_CONSOLE_MAIN_HELP_OPTION \
   {TEXTA_CONSOLE_MAIN_HELP_OPT, \
    TEXTA_CONSOLE_MAIN_HELP_OPTARG_REQUIRED, \
    TEXTA_CONSOLE_MAIN_HELP_OPTARG_RESULT, \
    TEXTA_CONSOLE_MAIN_HELP_OPTVAL_C}, \

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define TEXTA_CONSOLE_MAIN_OPTIONS_CHARS \
    TEXTA_CONSOLE_MAIN_LOGGING_LEVELS_OPTVAL_S \
    TEXTA_CONSOLE_MAIN_HELP_OPTVAL_S \

#define TEXTA_CONSOLE_MAIN_OPTIONS_OPTIONS \
    TEXTA_CONSOLE_MAIN_LOGGING_LEVELS_OPTION \
    TEXTA_CONSOLE_MAIN_HELP_OPTION \

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

namespace texta {
namespace console {

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

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int on_logging_levels_option
    (int optval, const char* optarg,
     const char* optname, int optind,
     int argc, char**argv, char**env) {
        int err = this->on_logging_option
        (TEXTA_MAIN_LOGGING_OPTVAL_C,
         optarg, optname, optind, argc, argv, env);
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int on_help_option
    (int optval, const char* optarg,
     const char* optname, int optind,
     int argc, char**argv, char**env) {
        int err = this->usage(argc, argv, env);
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
        case TEXTA_CONSOLE_MAIN_LOGGING_LEVELS_OPTVAL_C:
            err = on_logging_levels_option
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case TEXTA_CONSOLE_MAIN_HELP_OPTVAL_C:
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
        case TEXTA_CONSOLE_MAIN_LOGGING_LEVELS_OPTVAL_C:
            optarg = TEXTA_CONSOLE_MAIN_LOGGING_LEVELS_OPTARG;
            chars = TEXTA_CONSOLE_MAIN_LOGGING_LEVELS_OPTUSE;
            break;
        case TEXTA_CONSOLE_MAIN_HELP_OPTVAL_C:
            optarg = TEXTA_CONSOLE_MAIN_HELP_OPTARG;
            chars = TEXTA_CONSOLE_MAIN_HELP_OPTUSE;
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
        static const char* chars = TEXTA_CONSOLE_MAIN_OPTIONS_CHARS;
        static struct option optstruct[]= {
            TEXTA_CONSOLE_MAIN_OPTIONS_OPTIONS
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
};
typedef maint<> main;

} // namespace console
} // namespace texta 

#endif // _TEXTA_CONSOLE_MAIN_HPP 
