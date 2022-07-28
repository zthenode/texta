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
///   Date: 12/15/2014, 6/23/2022
/// 
///////////////////////////////////////////////////////////////////////
#ifndef _CORAL_CONSOLE_MAIN_HPP
#define _CORAL_CONSOLE_MAIN_HPP

#if !defined(NO_USE_NADIR_BASE)
#include "coral/nadir/console/main.hpp"
#else /// !defined(NO_USE_NADIR_BASE)
#include "coral/base/base.hpp"
#include "xos/base/main.hpp"
#include "xos/base/getopt/main.hpp"
#include "xos/base/getopt/main_opt.hpp"
#include "xos/io/main/argv/writer.hpp"
#include "xos/io/main/in/reader.hpp"
#include "xos/io/main/out/writer.hpp"
#include "xos/io/main/err/writer.hpp"

#define CORAL_MAIN_LOGGING_OPTVAL_C XOS_MAIN_LOGGING_OPTVAL_C
#define CORAL_MAIN_LOGGING_OPTARG XOS_MAIN_LOGGING_OPTARG
#define CORAL_MAIN_LOGGING_OPTUSE XOS_MAIN_LOGGING_OPTUSE

#define CORAL_MAIN_HELP_OPTVAL_C XOS_MAIN_HELP_OPTVAL_C
#define CORAL_MAIN_HELP_OPTARG XOS_MAIN_HELP_OPTARG
#define CORAL_MAIN_HELP_OPTUSE XOS_MAIN_HELP_OPTUSE

enum {
    CORAL_MAIN_OPT_ARGUMENT_NONE     = XOS_MAIN_OPT_ARGUMENT_NONE,
    CORAL_MAIN_OPT_ARGUMENT_REQUIRED = XOS_MAIN_OPT_ARGUMENT_REQUIRED,
    CORAL_MAIN_OPT_ARGUMENT_OPTIONAL = XOS_MAIN_OPT_ARGUMENT_OPTIONAL
};

namespace coral {
namespace console {

typedef int main_opt_argument_t;
enum {
    MAIN_OPT_ARGUMENT_NONE     = CORAL_MAIN_OPT_ARGUMENT_NONE,
    MAIN_OPT_ARGUMENT_REQUIRED = CORAL_MAIN_OPT_ARGUMENT_REQUIRED,
    MAIN_OPT_ARGUMENT_OPTIONAL = CORAL_MAIN_OPT_ARGUMENT_OPTIONAL
};

} // namespace console

namespace app {
namespace console {

typedef coral::console::main_opt_argument_t main_opt_argument_t;
enum {
    MAIN_OPT_ARGUMENT_NONE     = coral::console::MAIN_OPT_ARGUMENT_NONE,
    MAIN_OPT_ARGUMENT_REQUIRED = coral::console::MAIN_OPT_ARGUMENT_REQUIRED,
    MAIN_OPT_ARGUMENT_OPTIONAL = coral::console::MAIN_OPT_ARGUMENT_OPTIONAL
};

} // namespace console
} // namespace app

namespace inet {
namespace cgi {

typedef coral::console::main_opt_argument_t main_opt_argument_t;
enum {
    MAIN_OPT_ARGUMENT_NONE     = coral::console::MAIN_OPT_ARGUMENT_NONE,
    MAIN_OPT_ARGUMENT_REQUIRED = coral::console::MAIN_OPT_ARGUMENT_REQUIRED,
    MAIN_OPT_ARGUMENT_OPTIONAL = coral::console::MAIN_OPT_ARGUMENT_OPTIONAL
};

} // namespace cgi
} // namespace inet

namespace app {
namespace cgi {

typedef coral::console::main_opt_argument_t main_opt_argument_t;
enum {
    MAIN_OPT_ARGUMENT_NONE     = coral::console::MAIN_OPT_ARGUMENT_NONE,
    MAIN_OPT_ARGUMENT_REQUIRED = coral::console::MAIN_OPT_ARGUMENT_REQUIRED,
    MAIN_OPT_ARGUMENT_OPTIONAL = coral::console::MAIN_OPT_ARGUMENT_OPTIONAL
};

} // namespace cgi
} // namespace app

} // namespace coral

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

namespace coral {
namespace console {

typedef xos::base::getopt::main_implement main_implements;
typedef xos::base::getopt::main main_extends;
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

} // namespace console

namespace io {
namespace main {

namespace argv {

///////////////////////////////////////////////////////////////////////
/// writert
///////////////////////////////////////////////////////////////////////
#if defined(USE_CPP_11)
template
<typename TChar = char_t, typename TWhat = void,
 class TWriter = xos::io::writert<TWhat, TChar>,
 class TImplements = TWriter,
 class TExtends = xos::io::main::argv::writer_extends>

using writert = typename xos::io::main::argv::writert
<TChar, TWhat, TImplements, TExtends>;
#else // defined(USE_CPP_11)
#endif // defined(USE_CPP_11)
typedef xos::io::main::argv::writert<> writer;

} // namespace argv

namespace in {

///////////////////////////////////////////////////////////////////////
/// readert
///////////////////////////////////////////////////////////////////////
#if defined(USE_CPP_11)
template
<typename TWhat = void, typename TSized = char_t,
 typename TEnd = int, TEnd VEnd = 0,
 class TMain = xos::base::maint<TSized, TEnd, VEnd>,
 class TImplements = xos::io::readert<TWhat, TSized, TEnd, VEnd>,
 class TExtends = xos::io::main::in::reader_extends>

using readert = typename xos::io::main::in::readert
<TWhat, TSized, TEnd, VEnd, TMain, TImplements, TExtends>;
#else // defined(USE_CPP_11)
#endif // defined(USE_CPP_11)
typedef xos::io::main::in::readert<> reader;

} // namespace in

namespace out {

///////////////////////////////////////////////////////////////////////
/// writert
///////////////////////////////////////////////////////////////////////
#if defined(USE_CPP_11)
template
<typename TWhat = void, typename TSized = char_t,
 typename TEnd = int, TEnd VEnd = 0,
 class TMain = xos::base::maint<TSized, TEnd, VEnd>,
 class TImplements = xos::io::writert<TWhat, TSized, TEnd, VEnd>,
 class TExtends = xos::io::main::out::writer_extends>

using writert = typename xos::io::main::out::writert
<TWhat, TSized, TEnd, VEnd, TImplements, TExtends>;
#else // defined(USE_CPP_11)
#endif // defined(USE_CPP_11)
typedef xos::io::main::out::writert<> writer;

} // namespace out

namespace err {

///////////////////////////////////////////////////////////////////////
/// writert
///////////////////////////////////////////////////////////////////////
#if defined(USE_CPP_11)
template
<typename TWhat = void, typename TSized = char_t,
 typename TEnd = int, TEnd VEnd = 0,
 class TMain = xos::base::maint<TSized, TEnd, VEnd>,
 class TImplements = xos::io::writert<TWhat, TSized, TEnd, VEnd>,
 class TExtends = xos::io::main::err::writer_extends>

using writert = typename xos::io::main::err::writert
<TWhat, TSized, TEnd, VEnd, TImplements, TExtends>;
#else // defined(USE_CPP_11)
#endif // defined(USE_CPP_11)
typedef xos::io::main::err::writert<> writer;

} // namespace err
} // namespace main
} // namespace io

} // namespace coral

#endif /// !defined(NO_USE_NADIR_BASE)

#ifndef CORAL_CONSOLE_MAIN_MAIN
#ifdef XOS_CONSOLE_MAIN_MAIN
#define CORAL_CONSOLE_MAIN_MAIN
#endif /// def XOS_CONSOLE_MAIN_MAIN
#endif /// ndef CORAL_CONSOLE_MAIN_MAIN

#endif // _CORAL_CONSOLE_MAIN_HPP
