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
///   File: main_opt.hpp
///
/// Author: $author$
///   Date: 2/2/2015
///////////////////////////////////////////////////////////////////////
#ifndef _CORAL_APP_CGI_THROWER_MAIN_OPT_HPP
#define _CORAL_APP_CGI_THROWER_MAIN_OPT_HPP

#include "coral/inet/cgi/main.hpp"

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define CORAL_APP_CGI_THROWER_MAIN_PATH_TRANSLATED_OPT "path-translated"
#define CORAL_APP_CGI_THROWER_MAIN_PATH_TRANSLATED_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_REQUIRED
#define CORAL_APP_CGI_THROWER_MAIN_PATH_TRANSLATED_OPTARG_RESULT 0
#define CORAL_APP_CGI_THROWER_MAIN_PATH_TRANSLATED_OPTARG ""
#define CORAL_APP_CGI_THROWER_MAIN_PATH_TRANSLATED_OPTUSE ""
#define CORAL_APP_CGI_THROWER_MAIN_PATH_TRANSLATED_OPTVAL_S "p:"
#define CORAL_APP_CGI_THROWER_MAIN_PATH_TRANSLATED_OPTVAL_C 'p'
#define CORAL_APP_CGI_THROWER_MAIN_PATH_TRANSLATED_OPTION \
   {CORAL_APP_CGI_THROWER_MAIN_PATH_TRANSLATED_OPT, \
    CORAL_APP_CGI_THROWER_MAIN_PATH_TRANSLATED_OPTARG_REQUIRED, \
    CORAL_APP_CGI_THROWER_MAIN_PATH_TRANSLATED_OPTARG_RESULT, \
    CORAL_APP_CGI_THROWER_MAIN_PATH_TRANSLATED_OPTVAL_C}, \

#define CORAL_APP_CGI_THROWER_MAIN_SCRIPT_NAME_OPT "script-name"
#define CORAL_APP_CGI_THROWER_MAIN_SCRIPT_NAME_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_REQUIRED
#define CORAL_APP_CGI_THROWER_MAIN_SCRIPT_NAME_OPTARG_RESULT 0
#define CORAL_APP_CGI_THROWER_MAIN_SCRIPT_NAME_OPTARG ""
#define CORAL_APP_CGI_THROWER_MAIN_SCRIPT_NAME_OPTUSE ""
#define CORAL_APP_CGI_THROWER_MAIN_SCRIPT_NAME_OPTVAL_S "s:"
#define CORAL_APP_CGI_THROWER_MAIN_SCRIPT_NAME_OPTVAL_C 's'
#define CORAL_APP_CGI_THROWER_MAIN_SCRIPT_NAME_OPTION \
   {CORAL_APP_CGI_THROWER_MAIN_SCRIPT_NAME_OPT, \
    CORAL_APP_CGI_THROWER_MAIN_SCRIPT_NAME_OPTARG_REQUIRED, \
    CORAL_APP_CGI_THROWER_MAIN_SCRIPT_NAME_OPTARG_RESULT, \
    CORAL_APP_CGI_THROWER_MAIN_SCRIPT_NAME_OPTVAL_C}, \

#define CORAL_APP_CGI_THROWER_MAIN_EXEC_NAME_OPT "exec-name"
#define CORAL_APP_CGI_THROWER_MAIN_EXEC_NAME_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_REQUIRED
#define CORAL_APP_CGI_THROWER_MAIN_EXEC_NAME_OPTARG_RESULT 0
#define CORAL_APP_CGI_THROWER_MAIN_EXEC_NAME_OPTARG ""
#define CORAL_APP_CGI_THROWER_MAIN_EXEC_NAME_OPTUSE ""
#define CORAL_APP_CGI_THROWER_MAIN_EXEC_NAME_OPTVAL_S "x:"
#define CORAL_APP_CGI_THROWER_MAIN_EXEC_NAME_OPTVAL_C 'x'
#define CORAL_APP_CGI_THROWER_MAIN_EXEC_NAME_OPTION \
   {CORAL_APP_CGI_THROWER_MAIN_EXEC_NAME_OPT, \
    CORAL_APP_CGI_THROWER_MAIN_EXEC_NAME_OPTARG_REQUIRED, \
    CORAL_APP_CGI_THROWER_MAIN_EXEC_NAME_OPTARG_RESULT, \
    CORAL_APP_CGI_THROWER_MAIN_EXEC_NAME_OPTVAL_C}, \

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define CORAL_APP_CGI_THROWER_MAIN_OPTIONS_CHARS \
   CORAL_APP_CGI_THROWER_MAIN_PATH_TRANSLATED_OPTVAL_S \
   CORAL_APP_CGI_THROWER_MAIN_SCRIPT_NAME_OPTVAL_S \
   CORAL_APP_CGI_THROWER_MAIN_EXEC_NAME_OPTVAL_S \
   CORAL_INET_CGI_MAIN_OPTIONS_CHARS

#define CORAL_APP_CGI_THROWER_MAIN_OPTIONS_OPTIONS \
   CORAL_APP_CGI_THROWER_MAIN_PATH_TRANSLATED_OPTION \
   CORAL_APP_CGI_THROWER_MAIN_SCRIPT_NAME_OPTION \
   CORAL_APP_CGI_THROWER_MAIN_EXEC_NAME_OPTION \
   CORAL_INET_CGI_MAIN_OPTIONS_OPTIONS

namespace coral {
namespace app {
namespace cgi {
namespace thrower {

} // namespace thrower 
} // namespace cgi 
} // namespace app 
} // namespace coral 

#endif // _CORAL_APP_CGI_THROWER_MAIN_OPT_HPP 
