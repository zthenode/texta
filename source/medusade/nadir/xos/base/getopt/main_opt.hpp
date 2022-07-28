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
///   File: main_opt.hpp
///
/// Author: $author$
///   Date: 9/13/2014
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_BASE_GETOPT_MAIN_OPT_HPP
#define _XOS_NADIR_XOS_BASE_GETOPT_MAIN_OPT_HPP

#include "xos/base/base.hpp"
#include <getopt.h>

#define XOS_MAIN_2STRING_(id) "" #id ""
#define XOS_MAIN_2STRING(id) XOS_MAIN_2STRING_(id)

#define XOS_MAIN_LOGGING_OPT "logging-level"
#define XOS_MAIN_LOGGING_OPTARG_REQUIRED XOS_MAIN_OPT_ARGUMENT_REQUIRED
#define XOS_MAIN_LOGGING_OPTARG "{(a)all | (n)none | (f)fatal | (e)error | (w)waring | (i)info | (d)debug | (t)trace}"
#define XOS_MAIN_LOGGING_OPTUSE ""
#define XOS_MAIN_LOGGING_OPTVAL_S "l:"
#define XOS_MAIN_LOGGING_OPTVAL_C 'l'

#define XOS_MAIN_LOGGING_OPTIONS_OPTION \
   {XOS_MAIN_LOGGING_OPT, \
    XOS_MAIN_LOGGING_OPTARG_REQUIRED, 0, \
    XOS_MAIN_LOGGING_OPTVAL_C},

#define XOS_MAIN_HELP_OPT "help"
#define XOS_MAIN_HELP_OPTARG_REQUIRED XOS_MAIN_OPT_ARGUMENT_NONE
#define XOS_MAIN_HELP_OPTARG ""
#define XOS_MAIN_HELP_OPTUSE "Usage options"
#define XOS_MAIN_HELP_OPTVAL_S "h"
#define XOS_MAIN_HELP_OPTVAL_C 'h'

#define XOS_MAIN_HELP_OPTIONS_OPTION \
   {XOS_MAIN_HELP_OPT, \
    XOS_MAIN_HELP_OPTARG_REQUIRED, 0, \
    XOS_MAIN_HELP_OPTVAL_C},

#define XOS_MAIN_OPTIONS_CHARS \
    XOS_MAIN_LOGGING_OPTVAL_S \
    XOS_MAIN_HELP_OPTVAL_S

#define XOS_MAIN_OPTIONS_OPTIONS \
    XOS_MAIN_LOGGING_OPTIONS_OPTION \
    XOS_MAIN_HELP_OPTIONS_OPTION

enum {
    XOS_MAIN_OPT_ARGUMENT_NONE     = 0,
    XOS_MAIN_OPT_ARGUMENT_REQUIRED = 1,
    XOS_MAIN_OPT_ARGUMENT_OPTIONAL = 2
};

namespace xos {
namespace base {
namespace getopt {

typedef int main_opt_argument_t;
enum {
    MAIN_OPT_ARGUMENT_NONE     = XOS_MAIN_OPT_ARGUMENT_NONE,
    MAIN_OPT_ARGUMENT_REQUIRED = XOS_MAIN_OPT_ARGUMENT_REQUIRED,
    MAIN_OPT_ARGUMENT_OPTIONAL = XOS_MAIN_OPT_ARGUMENT_OPTIONAL
};

typedef int opt_argument_t;
enum {
    OPT_ARGUMENT_NONE     = XOS_MAIN_OPT_ARGUMENT_NONE,
    OPT_ARGUMENT_REQUIRED = XOS_MAIN_OPT_ARGUMENT_REQUIRED,
    OPT_ARGUMENT_OPTIONAL = XOS_MAIN_OPT_ARGUMENT_OPTIONAL
};

int on_logging_level(const char* optarg);

int on_logging_option
(int optval, const char* optarg,
 const char* optname, int optind,
 int argc, char**argv, char**env);

} // namespace getopt
} // namespace base 
} // namespace xos 

namespace xos {
namespace app {
namespace console {

typedef int main_opt_argument_t;
enum {
    MAIN_OPT_ARGUMENT_NONE     = XOS_MAIN_OPT_ARGUMENT_NONE,
    MAIN_OPT_ARGUMENT_REQUIRED = XOS_MAIN_OPT_ARGUMENT_REQUIRED,
    MAIN_OPT_ARGUMENT_OPTIONAL = XOS_MAIN_OPT_ARGUMENT_OPTIONAL
};

} // namespace console
} // namespace app
} // namespace xos

#endif // _XOS_NADIR_XOS_BASE_GETOPT_MAIN_OPT_HPP
