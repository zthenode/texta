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
#ifndef _CORAL_INET_CGI_MAIN_OPT_HPP
#define _CORAL_INET_CGI_MAIN_OPT_HPP

#include "coral/console/main.hpp"

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define CORAL_INET_CGI_MAIN_ARGV_FILE_NAME_OPT "argv-file"
#define CORAL_INET_CGI_MAIN_ARGV_FILE_NAME_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_REQUIRED
#define CORAL_INET_CGI_MAIN_ARGV_FILE_NAME_OPTARG_RESULT 0
#define CORAL_INET_CGI_MAIN_ARGV_FILE_NAME_OPTARG ""
#define CORAL_INET_CGI_MAIN_ARGV_FILE_NAME_OPTUSE ""
#define CORAL_INET_CGI_MAIN_ARGV_FILE_NAME_OPTVAL_S "a:"
#define CORAL_INET_CGI_MAIN_ARGV_FILE_NAME_OPTVAL_C 'a'
#define CORAL_INET_CGI_MAIN_ARGV_FILE_NAME_OPTION \
   {CORAL_INET_CGI_MAIN_ARGV_FILE_NAME_OPT, \
    CORAL_INET_CGI_MAIN_ARGV_FILE_NAME_OPTARG_REQUIRED, \
    CORAL_INET_CGI_MAIN_ARGV_FILE_NAME_OPTARG_RESULT, \
    CORAL_INET_CGI_MAIN_ARGV_FILE_NAME_OPTVAL_C}, \

#define CORAL_INET_CGI_MAIN_ENV_FILE_NAME_OPT "env-file"
#define CORAL_INET_CGI_MAIN_ENV_FILE_NAME_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_REQUIRED
#define CORAL_INET_CGI_MAIN_ENV_FILE_NAME_OPTARG_RESULT 0
#define CORAL_INET_CGI_MAIN_ENV_FILE_NAME_OPTARG ""
#define CORAL_INET_CGI_MAIN_ENV_FILE_NAME_OPTUSE ""
#define CORAL_INET_CGI_MAIN_ENV_FILE_NAME_OPTVAL_S "e:"
#define CORAL_INET_CGI_MAIN_ENV_FILE_NAME_OPTVAL_C 'e'
#define CORAL_INET_CGI_MAIN_ENV_FILE_NAME_OPTION \
   {CORAL_INET_CGI_MAIN_ENV_FILE_NAME_OPT, \
    CORAL_INET_CGI_MAIN_ENV_FILE_NAME_OPTARG_REQUIRED, \
    CORAL_INET_CGI_MAIN_ENV_FILE_NAME_OPTARG_RESULT, \
    CORAL_INET_CGI_MAIN_ENV_FILE_NAME_OPTVAL_C}, \

#define CORAL_INET_CGI_MAIN_STDIN_FILE_NAME_OPT "stdin-file"
#define CORAL_INET_CGI_MAIN_STDIN_FILE_NAME_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_REQUIRED
#define CORAL_INET_CGI_MAIN_STDIN_FILE_NAME_OPTARG_RESULT 0
#define CORAL_INET_CGI_MAIN_STDIN_FILE_NAME_OPTARG ""
#define CORAL_INET_CGI_MAIN_STDIN_FILE_NAME_OPTUSE ""
#define CORAL_INET_CGI_MAIN_STDIN_FILE_NAME_OPTVAL_S "i:"
#define CORAL_INET_CGI_MAIN_STDIN_FILE_NAME_OPTVAL_C 'i'
#define CORAL_INET_CGI_MAIN_STDIN_FILE_NAME_OPTION \
   {CORAL_INET_CGI_MAIN_STDIN_FILE_NAME_OPT, \
    CORAL_INET_CGI_MAIN_STDIN_FILE_NAME_OPTARG_REQUIRED, \
    CORAL_INET_CGI_MAIN_STDIN_FILE_NAME_OPTARG_RESULT, \
    CORAL_INET_CGI_MAIN_STDIN_FILE_NAME_OPTVAL_C}, \

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define CORAL_INET_CGI_MAIN_OPTIONS_CHARS \
   CORAL_INET_CGI_MAIN_ARGV_FILE_NAME_OPTVAL_S \
   CORAL_INET_CGI_MAIN_ENV_FILE_NAME_OPTVAL_S \
   CORAL_INET_CGI_MAIN_STDIN_FILE_NAME_OPTVAL_S \
   CORAL_CONSOLE_MAIN_OPTIONS_CHARS

#define CORAL_INET_CGI_MAIN_OPTIONS_OPTIONS \
   CORAL_INET_CGI_MAIN_ARGV_FILE_NAME_OPTION \
   CORAL_INET_CGI_MAIN_ENV_FILE_NAME_OPTION \
   CORAL_INET_CGI_MAIN_STDIN_FILE_NAME_OPTION \
   CORAL_CONSOLE_MAIN_OPTIONS_OPTIONS

namespace coral {
namespace inet {
namespace cgi {

} // namespace cgi 
} // namespace inet
} // namespace coral 

#endif // _CORAL_INET_CGI_MAIN_OPT_HPP 
