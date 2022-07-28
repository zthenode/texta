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
///   File: main.hpp
///
/// Author: $author$
///   Date: 12/15/2014
///////////////////////////////////////////////////////////////////////
#ifndef _CORAL_APP_CONSOLE_CORAL_MAIN_HPP
#define _CORAL_APP_CONSOLE_CORAL_MAIN_HPP

#include "coral/app/console/coral/main_opt.hpp"
#include "coral/console/main.hpp"
#include "coral/lib/coral/version.hpp"
#include "coral/io/logger.hpp"

namespace coral {
namespace app {
namespace console {
namespace coral {

typedef ::coral::console::main_implements main_implements;
typedef ::coral::console::main main_extends;
///////////////////////////////////////////////////////////////////////
///  Class: main
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS main: virtual public main_implements, public main_extends {
public:
    typedef main_implements Implements;
    typedef main_extends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    main() {
    }
    virtual ~main() {
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const lib::version& version = lib::coral::version::which();
        this->outl(version.name(), " version = ", version.to_string().chars(), NULL);
        this->outln();
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* set_argv(const char_t* to) {
        if ((to) && (to[0])) {
            CORAL_LOG_MESSAGE_DEBUG("set argv = \"" << to << "\"...");
        }
        return to;
    }
    virtual const char_t* set_env(const char_t* to) {
        if ((to) && (to[0])) {
            CORAL_LOG_MESSAGE_DEBUG("set env = \"" << to << "\"...");
        }
        return to;
    }
    virtual const char_t* set_input(const char_t* to) {
        if ((to) && (to[0])) {
            CORAL_LOG_MESSAGE_DEBUG("set input = \"" << to << "\"...");
        }
        return to;
    }
    virtual const char_t* set_output(const char_t* to) {
        if ((to) && (to[0])) {
            CORAL_LOG_MESSAGE_DEBUG("set output = \"" << to << "\"...");
        }
        return to;
    }
    virtual const char_t* set_stdin(const char_t* to) {
        if ((to) && (to[0])) {
            CORAL_LOG_MESSAGE_DEBUG("set stdin = \"" << to << "\"...");
        }
        return to;
    }
    virtual const char_t* set_stdout(const char_t* to) {
        if ((to) && (to[0])) {
            CORAL_LOG_MESSAGE_DEBUG("set stdout = \"" << to << "\"...");
        }
        return to;
    }
    virtual const char_t* set_stderr(const char_t* to) {
        if ((to) && (to[0])) {
            CORAL_LOG_MESSAGE_DEBUG("set stderr = \"" << to << "\"...");
        }
        return to;
    }

#include "coral/app/console/coral/main_opt.cpp"
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
};

} // namespace coral 
} // namespace console 
} // namespace app 
} // namespace coral 

#endif // _CORAL_APP_CONSOLE_CORAL_MAIN_HPP 
