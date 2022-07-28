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
///   File: logger.hpp
///
/// Author: $author$
///   Date: 10/29/2014
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_IO_MAIN_LOGGER_HPP
#define _XOS_NADIR_XOS_IO_MAIN_LOGGER_HPP

#include "xos/io/logger.hpp"
#include "xos/mt/lock.hpp"
#include "xos/base/main.hpp"

namespace xos {
namespace io {
namespace main {

typedef io::logger logger_implements;
typedef base::base logger_extends;
///////////////////////////////////////////////////////////////////////
///  Class: loggert
///////////////////////////////////////////////////////////////////////
template
<typename TChar = char,
 typename TEnd = TChar, TEnd VEnd = 0,
 class TMain = base::maint<TChar, TEnd, VEnd>,
 class TImplements = logger_implements, class TExtends = logger_extends>

class _EXPORT_CLASS loggert: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef io::logger::level level;
    typedef io::logger::location location;
    typedef io::logger::message message;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    loggert(TMain& main)
    : main_(main),
      logger_(Implements::get_default()),
      enabled_for_(XOS_DEFAULT_LOGGING_LEVELS) {
        Implements::set_default(this);
    }
    virtual ~loggert() {
        if (this == (Implements::get_default())) {
            Implements::set_default(logger_);
        }
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void log
    (const level& _level, const location& _location, const message& _message) {
        mt::lock lk(main_);
        if ((this->is_enabled_for(_level))) {
            this->log(_location);
            main_.log(_message.c_str());
            main_.logln();
        }
    }
    virtual void logf
    (const level& _level, const location& _location, const char* format, ...) {
        mt::lock lk(main_);
        if ((this->is_enabled_for(_level))) {
            this->log(_location);
            if ((format)) {
                va_list va;
                va_start(va, format);
                main_.logfv(format, va);
                va_end(va);
            }
            main_.logln();
        }
    }
    virtual void logfv
    (const level& _level, const location& _location, const char* format, va_list va) {
        mt::lock lk(main_);
        if ((this->is_enabled_for(_level))) {
            this->log(_location);
            if ((format)) {
                main_.logfv(format, va);
            }
            main_.logln();
        }
    }
    virtual void logfv
    (const level& _level, const location& _location,
     const message& _message, const char* format, va_list va) {
        mt::lock lk(main_);
        if ((this->is_enabled_for(_level))) {
            this->log(_location);
            main_.log(_message.c_str());
            if ((format)) {
                main_.logfv(format, va);
            }
            main_.logln();
        }
    }
    ///////////////////////////////////////////////////////////////////////
    virtual void log
    (const level& _level, const message& _message) {
        mt::lock lk(main_);
        if ((this->is_enabled_for(_level))) {
            main_.log(_message.c_str());
            main_.logln();
        }
    }
    virtual void logf
    (const level& _level, const char* format, ...) {
        mt::lock lk(main_);
        if ((this->is_enabled_for(_level))) {
            if ((format)) {
                va_list va;
                va_start(va, format);
                main_.logfv(format, va);
                va_end(va);
            }
            main_.logln();
        }
    }
    virtual void logfv
    (const level& _level, const char* format, va_list va) {
        mt::lock lk(main_);
        if ((this->is_enabled_for(_level))) {
            if ((format)) {
                main_.logfv(format, va);
            }
            main_.logln();
        }
    }
    virtual void logfv
    (const level& _level, const message& _message, const char* format, va_list va) {
        mt::lock lk(main_);
        if ((this->is_enabled_for(_level))) {
            main_.log(_message.c_str());
            if ((format)) {
                main_.logfv(format, va);
            }
            main_.logln();
        }
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void enable_for(const level& _level) {
        enabled_for_ = _level;
    }
    virtual level enabled_for() const {
        return enabled_for_;
    }
    virtual bool is_enabled_for(const level& _level) const {
        level::enable enabled_for = enabled_for_;
        level::enable enabled = _level;
        return ((enabled_for & enabled) == enabled);
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t log(const location& _location) {
        ssize_t count = 0;
        main_.log(_location.get_file_name().c_str());
        main_.log("[");
        main_.log(_location.get_line_number().c_str());
        main_.log("]");
        main_.log(" ");
        main_.log(_location.get_function_name().c_str());
        main_.log(" ");
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    TMain& main_;
    Implements* logger_;
    level enabled_for_;
};
typedef loggert<> logger;

} // namespace main 
} // namespace io 
} // namespace xos 

#endif // _XOS_NADIR_XOS_IO_MAIN_LOGGER_HPP 
