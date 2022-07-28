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
///   File: base.hpp
///
/// Author: $author$
///   Date: 12/12/2014
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_APP_CONSOLE_HELLO_BASE_HPP
#define _XOS_NADIR_XOS_APP_CONSOLE_HELLO_BASE_HPP

#include "xos/base/getopt/main.hpp"
#include "xos/io/logger.hpp"
#include "xos/base/types.hpp"

#define XOS_APP_CONSOLE_HELLO_PORTNO 8080
#define XOS_APP_CONSOLE_HELLO_PORT XOS_BASE_2STRING(XOS_APP_CONSOLE_HELLO_PORTNO)
#define XOS_APP_CONSOLE_HELLO_HOST "localhost"
#define XOS_APP_CONSOLE_HELLO_BYE_MESSAGE "Bye"
#define XOS_APP_CONSOLE_HELLO_HELLO_MESSAGE "Hello"
#define XOS_APP_CONSOLE_HELLO_MESSAGE_LINE_SEPARATOR "\r\n"
#define XOS_APP_CONSOLE_HELLO_MESSAGE_BODY_SEPARATOR "\r\n\r\n"

namespace xos {
namespace app {
namespace console {
namespace hello {

typedef xos::base::chars_t chars_t;
typedef xos::base::getopt::main::char_t char_t;
typedef xos::base::getopt::main::string_t string_t;

} // namespace hello
} // namespace console 
} // namespace app 
} // namespace xos 

#endif // _XOS_NADIR_XOS_APP_CONSOLE_HELLO_BASE_HPP 
