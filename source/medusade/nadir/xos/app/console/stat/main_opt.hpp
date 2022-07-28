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
///   Date: 3/28/2015
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_APP_CONSOLE_STAT_MAIN_OPT_HPP
#define _XOS_NADIR_XOS_APP_CONSOLE_STAT_MAIN_OPT_HPP

#include "xos/base/getopt/main.hpp"

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_STAT_MAIN_PATH_ARG "[path]"
#define XOS_APP_CONSOLE_STAT_MAIN_PATH_ARG_USE "File path"
#define XOS_APP_CONSOLE_STAT_MAIN_PATH_ARGV \
    XOS_APP_CONSOLE_STAT_MAIN_PATH_ARG " - " \
    XOS_APP_CONSOLE_STAT_MAIN_PATH_ARG_USE \

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_STAT_MAIN_ARGV \
    XOS_APP_CONSOLE_STAT_MAIN_PATH_ARGV , \

#define XOS_APP_CONSOLE_STAT_MAIN_ARGS \
    XOS_APP_CONSOLE_STAT_MAIN_PATH_ARG " " \

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

namespace xos {
namespace app {
namespace console {
namespace stat {

} // namespace stat 
} // namespace console 
} // namespace app 
} // namespace xos 

#endif // _XOS_NADIR_XOS_APP_CONSOLE_STAT_MAIN_OPT_HPP 
