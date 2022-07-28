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
///   File: main_opt.hpp
///
/// Author: $author$
///   Date: 12/21/2018
///////////////////////////////////////////////////////////////////////
#ifndef _CORAL_NADIR_CONSOLE_MAIN_OPT_HPP
#define _CORAL_NADIR_CONSOLE_MAIN_OPT_HPP

#include "coral/nadir/io/logger.hpp"
#include "nadir/console/getopt/main_opt.hpp"

#define CORAL_MAIN_LOGGING_OPTVAL_C NADIR_CONSOLE_GETOPT_MAIN_LOGGING_OPTVAL_C
#define CORAL_MAIN_LOGGING_OPTARG NADIR_CONSOLE_GETOPT_MAIN_LOGGING_OPTARG
#define CORAL_MAIN_LOGGING_OPTUSE NADIR_CONSOLE_GETOPT_MAIN_LOGGING_OPTUSE

#define CORAL_MAIN_HELP_OPTVAL_C NADIR_CONSOLE_GETOPT_MAIN_HELP_OPTVAL_C
#define CORAL_MAIN_HELP_OPTARG NADIR_CONSOLE_GETOPT_MAIN_HELP_OPTARG
#define CORAL_MAIN_HELP_OPTUSE NADIR_CONSOLE_GETOPT_MAIN_HELP_OPTUSE

enum {
    CORAL_MAIN_OPT_ARGUMENT_NONE     = NADIR_CONSOLE_GETOPT_MAIN_OPT_ARGUMENT_NONE,
    CORAL_MAIN_OPT_ARGUMENT_REQUIRED = NADIR_CONSOLE_GETOPT_MAIN_OPT_ARGUMENT_REQUIRED,
    CORAL_MAIN_OPT_ARGUMENT_OPTIONAL = NADIR_CONSOLE_GETOPT_MAIN_OPT_ARGUMENT_OPTIONAL
};

namespace coral {

namespace console {
typedef int main_opt_argument_t;
enum {
    MAIN_OPT_ARGUMENT_NONE     = CORAL_MAIN_OPT_ARGUMENT_NONE,
    MAIN_OPT_ARGUMENT_REQUIRED = CORAL_MAIN_OPT_ARGUMENT_REQUIRED,
    MAIN_OPT_ARGUMENT_OPTIONAL = CORAL_MAIN_OPT_ARGUMENT_OPTIONAL
};
typedef nadir::console::getopt::main_opt main_opt;
} /// namespace console

namespace daemon {
typedef coral::console::main_opt_argument_t main_opt_argument_t;
enum {
    MAIN_OPT_ARGUMENT_NONE     = coral::console::MAIN_OPT_ARGUMENT_NONE,
    MAIN_OPT_ARGUMENT_REQUIRED = coral::console::MAIN_OPT_ARGUMENT_REQUIRED,
    MAIN_OPT_ARGUMENT_OPTIONAL = coral::console::MAIN_OPT_ARGUMENT_OPTIONAL
};
} /// namespace daemon

namespace app {
namespace console {
typedef coral::console::main_opt_argument_t main_opt_argument_t;
enum {
    MAIN_OPT_ARGUMENT_NONE     = coral::console::MAIN_OPT_ARGUMENT_NONE,
    MAIN_OPT_ARGUMENT_REQUIRED = coral::console::MAIN_OPT_ARGUMENT_REQUIRED,
    MAIN_OPT_ARGUMENT_OPTIONAL = coral::console::MAIN_OPT_ARGUMENT_OPTIONAL
};
} /// namespace console

namespace daemon {
typedef coral::console::main_opt_argument_t main_opt_argument_t;
enum {
    MAIN_OPT_ARGUMENT_NONE     = coral::console::MAIN_OPT_ARGUMENT_NONE,
    MAIN_OPT_ARGUMENT_REQUIRED = coral::console::MAIN_OPT_ARGUMENT_REQUIRED,
    MAIN_OPT_ARGUMENT_OPTIONAL = coral::console::MAIN_OPT_ARGUMENT_OPTIONAL
};
} /// namespace daemon
} /// namespace app

} /// namespace coral

#endif /// ndef _CORAL_NADIR_CONSOLE_MAIN_OPT_HPP
