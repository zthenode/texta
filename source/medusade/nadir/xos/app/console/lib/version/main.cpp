///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2021 $organization$
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
///   File: main.cpp
///
/// Author: $author$
///   Date: 6/14/2021
///////////////////////////////////////////////////////////////////////
#include "xos/app/console/lib/version/main.hpp"

#if !defined(XOS_APP_CONSOLE_LIB_VERSION_MAIN_INSTANCE)
///#define XOS_APP_CONSOLE_LIB_VERSION_MAIN_INSTANCE
#endif /// !defined(XOS_APP_CONSOLE_LIB_VERSION_MAIN_NSTANCE)

namespace xos {
namespace app {
namespace console {
namespace lib {
namespace version {

/// class main
#if defined(XOS_APP_CONSOLE_LIB_VERSION_MAIN_INSTANCE)
static main the_main;
#endif /// defined(XOS_APP_CONSOLE_LIB_VERSION_MAIN_INSTANCE)

} /// namespace version
} /// namespace lib
} /// namespace console
} /// namespace app
} /// namespace xos
