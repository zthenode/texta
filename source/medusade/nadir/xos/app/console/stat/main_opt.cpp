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
///   File: main_opt.cpp
///
/// Author: $author$
///   Date: 3/28/2015
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_APP_CONSOLE_STAT_MAIN_OPT_CPP
#define _XOS_NADIR_XOS_APP_CONSOLE_STAT_MAIN_OPT_CPP

#ifndef _XOS_NADIR_XOS_APP_CONSOLE_STAT_MAIN_HPP
#include "xos/base/getopt/main.hpp"

namespace xos {
namespace app {
namespace console {
namespace stat {

typedef base::getopt::main_implement main_implement;
typedef base::getopt::main main_extend;
///////////////////////////////////////////////////////////////////////
///  Class: main
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS main: virtual public main_implement, public main_extend {
public:
#endif // _XOS_NADIR_XOS_APP_CONSOLE_STAT_MAIN_HPP

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char* arguments(const char**& args) {
        static const char* argv[] = {
            XOS_APP_CONSOLE_STAT_MAIN_ARGV
            0};
        args = argv;
        return XOS_APP_CONSOLE_STAT_MAIN_ARGS;
    }

#ifndef _XOS_NADIR_XOS_APP_CONSOLE_STAT_MAIN_HPP
};

} // namespace stat
} // namespace console 
} // namespace app 
} // namespace xos 
#endif // _XOS_NADIR_XOS_APP_CONSOLE_STAT_MAIN_HPP

#endif // _XOS_NADIR_XOS_APP_CONSOLE_STAT_MAIN_OPT_CPP 
