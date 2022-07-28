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
///   File: logger_base.hpp
///
/// Author: $author$
///   Date: 2/27/2016
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_IO_LOGGER_BASE_HPP
#define _XOS_NADIR_XOS_IO_LOGGER_BASE_HPP

#include "xos/io/logger.hpp"
#include "xos/mt/os/mutex.hpp"
#include "xos/mt/lock.hpp"

namespace xos {
namespace io {

typedef xos::mt::os::mutex logger_base_locked_t;
typedef xos::mt::locker logger_base_locker_t;
typedef xos::mt::lock logger_base_lock_t;

typedef io::logger logger_base_implements;
typedef base::base logger_base_extends;
///////////////////////////////////////////////////////////////////////
///  Class: logger_baset
///////////////////////////////////////////////////////////////////////
template
<typename TLocked = logger_base_locked_t, typename TDefaultLocked = TLocked,
 typename TLocker = logger_base_locker_t, typename TLock = logger_base_lock_t,
 typename TChar = char_t, typename TEnd = TChar, TEnd VEnd = 0,
 class TImplements = logger_base_implements, class TExtends = logger_base_extends>

class _EXPORT_CLASS logger_baset: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef io::logger::level level;
    typedef io::logger::location location;
    typedef io::logger::message message;

    typedef TDefaultLocked default_locked_t;
    typedef TLocked locked_t;
    typedef TLocker locker_t;
    typedef TLock lock_t;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    logger_baset
    (locked_t& locked, level enabled_for = XOS_DEFAULT_LOGGING_LEVELS,
     Implements* default_logger = Implements::get_default(),
     bool set_default_logger = true)
    : locked_(locked), default_logger_(default_logger), enabled_for_(enabled_for) {
        if ((set_default_logger)) {
            Implements::set_default(this);
        }
    }
    logger_baset
    (level enabled_for = XOS_DEFAULT_LOGGING_LEVELS,
     Implements* default_logger = Implements::get_default(),
     bool set_default_logger = true)
    : locked_(default_locked_), default_logger_(default_logger), enabled_for_(enabled_for) {
        if ((set_default_logger)) {
            Implements::set_default(this);
        }
    }
    virtual ~logger_baset() {
        if (this == (Implements::get_default())) {
            Implements::set_default(default_logger_);
        }
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void log
    (const level& _level, const location& _location, const message& _message) {
        lock_t lk(locked_);
        if ((this->is_enabled_for(_level))) {
            this->log(_location);
            log(_message.c_str());
            logln();
        }
    }
    virtual void logf
    (const level& _level, const location& _location, const char_t* format, ...) {
        lock_t lk(locked_);
        if ((this->is_enabled_for(_level))) {
            this->log(_location);
            if ((format)) {
                va_list va;
                va_start(va, format);
                logfv(format, va);
                va_end(va);
            }
            logln();
        }
    }
    virtual void log
    (const level& _level, const message& _message) {
        lock_t lk(locked_);
        if ((this->is_enabled_for(_level))) {
            log(_message.c_str());
            logln();
        }
    }
    virtual void logf
    (const level& _level, const char_t* format, ...) {
        lock_t lk(locked_);
        if ((this->is_enabled_for(_level))) {
            if ((format)) {
                va_list va;
                va_start(va, format);
                logfv(format, va);
                va_end(va);
            }
            logln();
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
        ssize_t count = logl
        (_location.get_file_name().c_str(),
         "[", _location.get_line_number().c_str(), "]",
         " ", _location.get_function_name().c_str(), " ", NULL);
        return count;
    }
    virtual ssize_t logl(const char_t* chars, ...) {
        ssize_t count = 0;
        va_list va;
        va_start(va, chars);
        if ((chars)) {
            count = logv(chars, va);
        }
        va_end(va);
        return count;
    }
    virtual ssize_t logv(const char_t* chars, va_list va) {
        ssize_t count = 0;
        ssize_t amount = 0;
        for (count = 0; chars; count += amount) {
            if (0 > (amount = log(chars)))
                return amount;
            chars = va_arg(va, const char_t*);
        }
        return count;
    }
    virtual ssize_t logfv(const char_t* format, va_list va) {
        ssize_t count = 0;
        return count;
    }
    virtual ssize_t log(const char_t* chars) {
        ssize_t count = 0;
        return count;
    }
    virtual ssize_t logln() {
        ssize_t count = log("\n");
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    default_locked_t default_locked_;
    locked_t& locked_;
    Implements* default_logger_;
    level enabled_for_;
};
typedef logger_baset<> logger_base;

} // namespace io 
} // namespace xos 

#endif // _XOS_NADIR_XOS_IO_LOGGER_BASE_HPP 
