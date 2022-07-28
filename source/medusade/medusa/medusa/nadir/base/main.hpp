///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2017 $organization$
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
///   Date: 6/13/2017
///////////////////////////////////////////////////////////////////////
#ifndef _MEDUSA_NADIR_BASE_MAIN_HPP
#define _MEDUSA_NADIR_BASE_MAIN_HPP

#include "medusa/base/base.hpp"
#include "nadir/console/getopt/main.hpp"
#include "nadir/console/getopt/main_opt.hpp"

#define MEDUSA_MAIN_LOGGING_OPTVAL_C NADIR_CONSOLE_GETOPT_MAIN_LOGGING_OPTVAL_C
#define MEDUSA_MAIN_LOGGING_OPTARG NADIR_CONSOLE_GETOPT_MAIN_LOGGING_OPTARG
#define MEDUSA_MAIN_LOGGING_OPTUSE NADIR_CONSOLE_GETOPT_MAIN_LOGGING_OPTUSE

#define MEDUSA_MAIN_HELP_OPTVAL_C NADIR_CONSOLE_GETOPT_MAIN_HELP_OPTVAL_C
#define MEDUSA_MAIN_HELP_OPTARG NADIR_CONSOLE_GETOPT_MAIN_HELP_OPTARG
#define MEDUSA_MAIN_HELP_OPTUSE NADIR_CONSOLE_GETOPT_MAIN_HELP_OPTUSE

enum {
    MEDUSA_MAIN_OPT_ARGUMENT_NONE     = NADIR_CONSOLE_GETOPT_MAIN_OPT_ARGUMENT_NONE,
    MEDUSA_MAIN_OPT_ARGUMENT_REQUIRED = NADIR_CONSOLE_GETOPT_MAIN_OPT_ARGUMENT_REQUIRED,
    MEDUSA_MAIN_OPT_ARGUMENT_OPTIONAL = NADIR_CONSOLE_GETOPT_MAIN_OPT_ARGUMENT_OPTIONAL
};

namespace medusa {
namespace console {

typedef nadir::console::getopt::maint_implements main_implements;
typedef nadir::console::getopt::main main_extends;

} // namespace console
} // namespace medusa 

#endif // _MEDUSA_NADIR_BASE_MAIN_HPP 
