///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2017 $organization$
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
///   File: interface.hpp
///
/// Author: $author$
///   Date: 10/21/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_LOGGER_INTERFACE_HPP
#define _XOS_NADIR_LOGGER_INTERFACE_HPP

#include "xos/logger/output.hpp"
#include "xos/logger/level.hpp"
#include "xos/mt/locked.hpp"
#include "xos/mt/lock.hpp"

#if defined(XOS_USE_LOG4CXX)
// Use log4cxx logging
#include "log4cxx/logger.h"
#endif // defined(XOS_USE_LOG4CXX)

namespace xos {
namespace logger {

typedef mt::locked interface_implements;
///////////////////////////////////////////////////////////////////////
///  Class: interface
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS interface: virtual public interface_implements {
public:
    typedef interface_implements Implements;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool init() { 
        return true; 
    }
    virtual bool fini() { 
        return true; 
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void log
    (const level& _level, const location& _location, const message& _message) {
        mt::lock lock(*this);
        if ((this->is_enabled_for(_level))) {
            this->log(_location);
            this->log(_message.c_str());
            this->logln();
        }
    }
    virtual void logf
    (const level& _level, const location& _location, const char* format, ...) {
        mt::lock lock(*this);
        if ((this->is_enabled_for(_level))) {
            this->log(_location);
            if ((format)) {
                va_list va;
                va_start(va, format);
                this->logfv(format, va);
                va_end(va);
            }
            this->logln();
        }
    }
    virtual void logfv
    (const level& _level, const location& _location, const char* format, va_list va) {
        mt::lock lock(*this);
        if ((this->is_enabled_for(_level))) {
            this->log(_location);
            if ((format)) {
                this->logfv(format, va);
            }
            this->logln();
        }
    }
    virtual void logfv
    (const level& _level, const location& _location,
     const message& _message, const char* format, va_list va) {
        mt::lock lock(*this);
        if ((this->is_enabled_for(_level))) {
            this->log(_location);
            this->log(_message.c_str());
            if ((format)) {
                this->logfv(format, va);
            }
            this->logln();
        }
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void log
    (const level& _level, const message& _message) {
        mt::lock lock(*this);
        if ((this->is_enabled_for(_level))) {
            this->log(_message.c_str());
            this->logln();
        }
    }
    virtual void logf
    (const level& _level, const char* format, ...) {
        mt::lock lock(*this);
        if ((this->is_enabled_for(_level))) {
            if ((format)) {
                va_list va;
                va_start(va, format);
                this->logfv(format, va);
                va_end(va);
            }
            this->logln();
        }
    }
    virtual void logfv
    (const level& _level, const char* format, va_list va) {
        mt::lock lock(*this);
        if ((this->is_enabled_for(_level))) {
            if ((format)) {
                this->logfv(format, va);
            }
            this->logln();
        }
    }
    virtual void logfv
    (const level& _level, const message& _message, const char* format, va_list va) {
        mt::lock lock(*this);
        if ((this->is_enabled_for(_level))) {
            this->log(_message.c_str());
            if ((format)) {
                this->logfv(format, va);
            }
            this->logln();
        }
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void enable_for(const level& _level) {
    }
    virtual level enabled_for() const { 
        return enabled_for_default(); 
    }
    virtual bool is_enabled_for(const level& _level) const { 
        level::enable enabled = _level, enabled_for = this->enabled_for();
        bool is_enabled_for = ((enabled_for & enabled) == enabled);
        return is_enabled_for;
    }
    virtual level enabled_for_default() const { 
        return level(XOS_LOGGING_LEVELS_DEFAULT); 
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    static interface* set_default(interface* to) {
        interface* old_logger = the_default();
        the_default() = to;
        return old_logger;
    }
    static interface* get_default() {
        return the_default();
    }
protected:
    static interface*& the_default() {
        static interface* the_default = 0;
        return the_default;
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
    virtual ssize_t logflush() {
        ssize_t count = 0;
        return count;
    }
    virtual ssize_t logln() {
        ssize_t count = log("\n");
        logflush();
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

typedef interface instance_implements;
typedef base::base instance_extends;
///////////////////////////////////////////////////////////////////////
///  Class: instance
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS instance
: virtual public instance_implements, public instance_extends {
public:
    typedef instance_implements Implements;
    typedef instance_extends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    instance(): old_default_(the_default()) {
        the_default() = this;
        enabled_for_ = enabled_for_default();
    }
    virtual ~instance() {
        if (this == the_default()) {
            the_default() = old_default_;
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

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    interface* old_default_;
    level enabled_for_;
};

} // namespace logger 
} // namespace xos 

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define XOS_INIT_LOGGER(logger_) { \
::xos::logger::interface* logger = logger_; \
if ((logger)) { logger->init(); } }

#define XOS_FINI_LOGGER(logger_) { \
::xos::logger::interface* logger = logger_; \
if ((logger)) { logger->fini(); } }

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define XOS_SET_LOGGER_LEVEL(logger_, level_) { \
::xos::logger::interface* logger = logger_; \
if ((logger)) { logger->enable_for(level_); } }

#define XOS_GET_LOGGER_LEVEL(logger_) \
((logger_)?(logger_->enabled_for()) \
 :(::xos::logger::level(::xos::logger::level::none)))

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define XOS_LOG_PLAIN(logger_, level_, message_) { \
::xos::logger::interface* logger = logger_; \
if ((logger)?(logger->is_enabled_for(level_)):(false)) {\
   ::xos::logger::message message; \
   logger->log(level_, message << message_); } }

#define XOS_LOG_PLAINF(logger_, level_, format_, ...) { \
::xos::logger::interface* logger = logger_; \
if ((logger)?(logger->is_enabled_for(level_)):(false)) {\
   logger->logf(level_, format_, ##__VA_ARGS__); } }

///////////////////////////////////////////////////////////////////////
#define XOS_LOG_FUNCTION(logger_, level_, message_) { \
::xos::logger::interface* logger = logger_; \
if ((logger)?(logger->is_enabled_for(level_)):(false)) {\
   ::xos::logger::message message; \
   logger->log(level_, XOS_LOGGER_FUNCTION, message << message_); } }

#define XOS_LOG_FUNCTIONF(logger_, level_, format_, ...) { \
::xos::logger::interface* logger = logger_; \
if ((logger)?(logger->is_enabled_for(level_)):(false)) {\
   logger->logf(level_, XOS_LOGGER_FUNCTION, format_, ##__VA_ARGS__); } }

///////////////////////////////////////////////////////////////////////
#define XOS_LOG_LOCATION(logger_, level_, message_) { \
::xos::logger::interface* logger = logger_; \
if ((logger)?(logger->is_enabled_for(level_)):(false)) {\
   ::xos::logger::message message; \
   logger->log(level_, XOS_LOGGER_LOCATION, message << message_); } }

#define XOS_LOGF_LOCATION(logger_, level_, format_, ...) { \
::xos::logger::interface* logger = logger_; \
if ((logger)?(logger->is_enabled_for(level_)):(false)) {\
   logger->logf(level_, XOS_LOGGER_LOCATION, format_, ##__VA_ARGS__); } }

///////////////////////////////////////////////////////////////////////
#if defined(XOS_PLAIN_LOGGING)
#define XOS_LOG XOS_LOG_PLAIN
#define XOS_LOGF XOS_LOG_PLAINF
#else // defined(XOS_PLAIN_LOGGING)
#if defined(XOS_FUNCTION_LOGGING)
#define XOS_LOG XOS_LOG_PLAIN
#define XOS_LOGF XOS_LOG_PLAINF
#else // defined(XOS_FUNCTION_LOGGING)
#define XOS_LOG XOS_LOG_PLAIN
#define XOS_LOGF XOS_LOG_PLAINF
#endif // defined(XOS_FUNCTION_LOGGING)
#endif // defined(XOS_PLAIN_LOGGING)

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define XOS_LOG_ANY_LEVEL(logger_, message_) { \
::xos::logger::interface* logger = logger_; \
if ((logger)) {\
   ::xos::logger::level level_; \
   ::xos::logger::message message; \
   logger->log(level_, XOS_LOGGER_LOCATION, message << message_); } }

#define XOS_LOG_ANY_LEVELF(logger_, format_, ...) { \
::xos::logger::interface* logger = logger_; \
if ((logger)) {\
   ::xos::logger::level level_; \
   logger->logf(level_, XOS_LOGGER_LOCATION, format_, ##__VA_ARGS__); } }

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define XOS_LOG_MESSAGE(logger_, level_, message_) { \
::xos::logger::interface* logger = logger_; \
if ((logger)?(logger->is_enabled_for(level_)):(false)) {\
   ::xos::logger::message message; \
   logger->log(level_, message << message_); } }

#define XOS_LOG_MESSAGEF(logger_, level_, format_, ...) { \
::xos::logger::interface* logger = logger_; \
if ((logger)?(logger->is_enabled_for(level_)):(false)) {\
   logger->logf(level_, format_, ##__VA_ARGS__); } }

#define XOS_LOG_MESSAGEFV(logger_, level_, format_, va_) { \
::xos::logger::interface* logger = logger_; \
if ((logger)?(logger->is_enabled_for(level_)):(false)) {\
   logger->logfv(level_, format_, va_); } }

#define XOS_LOG_MESSAGEMFV(logger_, level_, message_, format_, va_) { \
::xos::logger::interface* logger = logger_; \
::xos::logger::message message; \
if ((logger)?(logger->is_enabled_for(level_)):(false)) {\
   logger->logfv(level_, message << message_, format_, va_); } }

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define XOS_LOG_MESSAGE_ANY_LEVEL(logger_, message_) { \
::xos::logger::interface* logger = logger_; \
if ((logger)) {\
   ::xos::logger::level level_; \
   ::xos::logger::message message; \
   logger->log(level_, message << message_); } }

#define XOS_LOG_MESSAGE_ANY_LEVELF(logger_, format_, ...) { \
::xos::logger::interface* logger = logger_; \
if ((logger)) {\
   ::xos::logger::level level_; \
   logger->logf(level_, format_, ##__VA_ARGS__); } }

#define XOS_LOG_MESSAGE_ANY_LEVELFV(logger_, format_, va_) { \
::xos::logger::interface* logger = logger_; \
if ((logger)) {\
   ::xos::logger::level level_; \
   logger->logfv(level_, format_, va_); } }

#define XOS_LOG_MESSAGE_ANY_LEVELMFV(logger_, message_, format_, va_) { \
::xos::logger::interface* logger = logger_; \
if ((logger)) {\
   ::xos::logger::level level_; \
   ::xos::logger::message message; \
   logger->logfv(level_, message << message_, format_, va_); } }

#if !defined(XOS_USE_LOG4CXX)
// Use this logging
// ...
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define XOS_DEFAULT_LOGGER ::xos::logger::interface::get_default()

#define XOS_LOGGER_INIT() XOS_INIT_LOGGER(XOS_DEFAULT_LOGGER)
#define XOS_LOGGER_FINI() XOS_FINI_LOGGER(XOS_DEFAULT_LOGGER)

#define XOS_SET_LOGGING_LEVEL(level)  XOS_SET_LOGGER_LEVEL(XOS_DEFAULT_LOGGER, level)
#define XOS_GET_LOGGING_LEVEL(level)  (level = XOS_GET_LOGGER_LEVEL(XOS_DEFAULT_LOGGER))

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define XOS_LOG_ANY(message) XOS_LOG_ANY_LEVEL(XOS_DEFAULT_LOGGER, message)
#define XOS_LOG_FATAL(message) XOS_LOG(XOS_DEFAULT_LOGGER, ::xos::logger::level::fatal, message)
#define XOS_LOG_ERROR(message) XOS_LOG(XOS_DEFAULT_LOGGER, ::xos::logger::level::error, message)
#define XOS_LOG_WARN(message) XOS_LOG(XOS_DEFAULT_LOGGER, ::xos::logger::level::warn, message)
#define XOS_LOG_INFO(message) XOS_LOG(XOS_DEFAULT_LOGGER, ::xos::logger::level::info, message)
#define XOS_LOG_DEBUG(message) XOS_LOG(XOS_DEFAULT_LOGGER, ::xos::logger::level::debug, message)
#define XOS_LOG_TRACE(message) XOS_LOG(XOS_DEFAULT_LOGGER, ::xos::logger::level::trace, message)

#define XOS_LOG_ANYF(message, ...) XOS_LOG_ANY_LEVELF(XOS_DEFAULT_LOGGER, message, ##__VA_ARGS__)
#define XOS_LOG_FATALF(message, ...) XOS_LOGF(XOS_DEFAULT_LOGGER, ::xos::logger::level::fatal, message, ##__VA_ARGS__)
#define XOS_LOG_ERRORF(message, ...) XOS_LOGF(XOS_DEFAULT_LOGGER, ::xos::logger::level::error, message, ##__VA_ARGS__)
#define XOS_LOG_WARNF(message, ...) XOS_LOGF(XOS_DEFAULT_LOGGER, ::xos::logger::level::warn, message, ##__VA_ARGS__)
#define XOS_LOG_INFOF(message, ...) XOS_LOGF(XOS_DEFAULT_LOGGER, ::xos::logger::level::info, message, ##__VA_ARGS__)
#define XOS_LOG_DEBUGF(message, ...) XOS_LOGF(XOS_DEFAULT_LOGGER, ::xos::logger::level::debug, message, ##__VA_ARGS__)
#define XOS_LOG_TRACEF(message, ...) XOS_LOGF(XOS_DEFAULT_LOGGER, ::xos::logger::level::trace, message, ##__VA_ARGS__)

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define XOS_LOG_MESSAGE_ANY(message) XOS_LOG_MESSAGE_ANY_LEVEL(XOS_DEFAULT_LOGGER, message)
#define XOS_LOG_MESSAGE_FATAL(message) XOS_LOG_MESSAGE(XOS_DEFAULT_LOGGER, ::xos::logger::level::fatal_message, message)
#define XOS_LOG_MESSAGE_ERROR(message) XOS_LOG_MESSAGE(XOS_DEFAULT_LOGGER, ::xos::logger::level::error_message, message)
#define XOS_LOG_MESSAGE_WARN(message) XOS_LOG_MESSAGE(XOS_DEFAULT_LOGGER, ::xos::logger::level::warn_message, message)
#define XOS_LOG_MESSAGE_INFO(message) XOS_LOG_MESSAGE(XOS_DEFAULT_LOGGER, ::xos::logger::level::info_message, message)
#define XOS_LOG_MESSAGE_DEBUG(message) XOS_LOG_MESSAGE(XOS_DEFAULT_LOGGER, ::xos::logger::level::debug_message, message)
#define XOS_LOG_MESSAGE_TRACE(message) XOS_LOG_MESSAGE(XOS_DEFAULT_LOGGER, ::xos::logger::level::trace_message, message)

#define XOS_LOG_MESSAGE_ANYF(message, ...) XOS_LOG_MESSAGE_ANY_LEVELF(XOS_DEFAULT_LOGGER, message, ##__VA_ARGS__)
#define XOS_LOG_MESSAGE_FATALF(message, ...) XOS_LOG_MESSAGEF(XOS_DEFAULT_LOGGER, ::xos::logger::level::fatal_message, message, ##__VA_ARGS__)
#define XOS_LOG_MESSAGE_ERRORF(message, ...) XOS_LOG_MESSAGEF(XOS_DEFAULT_LOGGER, ::xos::logger::level::error_message, message, ##__VA_ARGS__)
#define XOS_LOG_MESSAGE_WARNF(message, ...) XOS_LOG_MESSAGEF(XOS_DEFAULT_LOGGER, ::xos::logger::level::warn_message, message, ##__VA_ARGS__)
#define XOS_LOG_MESSAGE_INFOF(message, ...) XOS_LOG_MESSAGEF(XOS_DEFAULT_LOGGER, ::xos::logger::level::info_message, message, ##__VA_ARGS__)
#define XOS_LOG_MESSAGE_DEBUGF(message, ...) XOS_LOG_MESSAGEF(XOS_DEFAULT_LOGGER, ::xos::logger::level::debug_message, message, ##__VA_ARGS__)
#define XOS_LOG_MESSAGE_TRACEF(message, ...) XOS_LOG_MESSAGEF(XOS_DEFAULT_LOGGER, ::xos::logger::level::trace_message, message, ##__VA_ARGS__)
// ...
// Use this logging
#else // !defined(XOS_USE_LOG4CXX)
// Use log4cxx logging
#endif // !defined(XOS_USE_LOG4CXX)

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#endif // _XOS_NADIR_LOGGER_INTERFACE_HPP 
