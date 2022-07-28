///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2016 $organization$
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
///   Date: 1/6/2016
///////////////////////////////////////////////////////////////////////
#ifndef _CORAL_CONSOLE_DAEMON_MAIN_HPP
#define _CORAL_CONSOLE_DAEMON_MAIN_HPP

#include "coral/console/main.hpp"

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define CORAL_CONSOLE_DAEMON_MAIN_OPTIONS_CHARS \
    CORAL_CONSOLE_MAIN_OPTIONS_CHARS

#define CORAL_CONSOLE_DAEMON_MAIN_OPTIONS_OPTIONS \
    CORAL_CONSOLE_MAIN_OPTIONS_OPTIONS

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

namespace coral {
namespace console {
namespace daemon {

typedef console::main_implements main_implements;
typedef console::main main_extends;
///////////////////////////////////////////////////////////////////////
///  Class: main
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS main
: virtual public main_implements, public main_extends {
public:
    typedef main_implements Implements;
    typedef main_extends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    main() {
    }
    virtual ~main() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace daemon 
} // namespace console 
} // namespace coral 

#endif // _CORAL_CONSOLE_DAEMON_MAIN_HPP 
