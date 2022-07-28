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
///   Date: 2/7/2015
///////////////////////////////////////////////////////////////////////
#ifndef _MEDUSA_DAEMON_MAIN_OPT_HPP
#define _MEDUSA_DAEMON_MAIN_OPT_HPP

#include "medusa/console/main.hpp"
#include "medusa/console/main_opt.hpp"

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define MEDUSA_DAEMON_MAIN_RESTART_OPT "restart"
#define MEDUSA_DAEMON_MAIN_RESTART_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define MEDUSA_DAEMON_MAIN_RESTART_OPTARG_RESULT 0
#define MEDUSA_DAEMON_MAIN_RESTART_OPTARG ""
#define MEDUSA_DAEMON_MAIN_RESTART_OPTUSE ""
#define MEDUSA_DAEMON_MAIN_RESTART_OPTVAL_S "r"
#define MEDUSA_DAEMON_MAIN_RESTART_OPTVAL_C 'r'
#define MEDUSA_DAEMON_MAIN_RESTART_OPTION \
   {MEDUSA_DAEMON_MAIN_RESTART_OPT, \
    MEDUSA_DAEMON_MAIN_RESTART_OPTARG_REQUIRED, \
    MEDUSA_DAEMON_MAIN_RESTART_OPTARG_RESULT, \
    MEDUSA_DAEMON_MAIN_RESTART_OPTVAL_C}, \

#define MEDUSA_DAEMON_MAIN_START_OPT "start"
#define MEDUSA_DAEMON_MAIN_START_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define MEDUSA_DAEMON_MAIN_START_OPTARG_RESULT 0
#define MEDUSA_DAEMON_MAIN_START_OPTARG ""
#define MEDUSA_DAEMON_MAIN_START_OPTUSE ""
#define MEDUSA_DAEMON_MAIN_START_OPTVAL_S "s"
#define MEDUSA_DAEMON_MAIN_START_OPTVAL_C 's'
#define MEDUSA_DAEMON_MAIN_START_OPTION \
   {MEDUSA_DAEMON_MAIN_START_OPT, \
    MEDUSA_DAEMON_MAIN_START_OPTARG_REQUIRED, \
    MEDUSA_DAEMON_MAIN_START_OPTARG_RESULT, \
    MEDUSA_DAEMON_MAIN_START_OPTVAL_C}, \

#define MEDUSA_DAEMON_MAIN_STOP_OPT "stop"
#define MEDUSA_DAEMON_MAIN_STOP_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define MEDUSA_DAEMON_MAIN_STOP_OPTARG_RESULT 0
#define MEDUSA_DAEMON_MAIN_STOP_OPTARG ""
#define MEDUSA_DAEMON_MAIN_STOP_OPTUSE ""
#define MEDUSA_DAEMON_MAIN_STOP_OPTVAL_S "t"
#define MEDUSA_DAEMON_MAIN_STOP_OPTVAL_C 't'
#define MEDUSA_DAEMON_MAIN_STOP_OPTION \
   {MEDUSA_DAEMON_MAIN_STOP_OPT, \
    MEDUSA_DAEMON_MAIN_STOP_OPTARG_REQUIRED, \
    MEDUSA_DAEMON_MAIN_STOP_OPTARG_RESULT, \
    MEDUSA_DAEMON_MAIN_STOP_OPTVAL_C}, \

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define MEDUSA_DAEMON_MAIN_OPTIONS_CHARS \
   MEDUSA_DAEMON_MAIN_RESTART_OPTVAL_S \
   MEDUSA_DAEMON_MAIN_START_OPTVAL_S \
   MEDUSA_DAEMON_MAIN_STOP_OPTVAL_S \
   MEDUSA_CONSOLE_MAIN_OPTIONS_CHARS

#define MEDUSA_DAEMON_MAIN_OPTIONS_OPTIONS \
   MEDUSA_DAEMON_MAIN_RESTART_OPTION \
   MEDUSA_DAEMON_MAIN_START_OPTION \
   MEDUSA_DAEMON_MAIN_STOP_OPTION \
   MEDUSA_CONSOLE_MAIN_OPTIONS_OPTIONS

namespace medusa {
namespace daemon {

} // namespace daemon 
} // namespace medusa 


#endif // _MEDUSA_DAEMON_MAIN_OPT_HPP 
