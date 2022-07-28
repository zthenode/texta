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
///   Date: 8/24/2014, 6/29/2022
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_IO_LOGGER_HPP
#define _XOS_NADIR_XOS_IO_LOGGER_HPP

#include "xos/mt/locker.hpp"
#include "xos/base/string.hpp"
#include <sstream>

#if defined(XOS_USE_LOG4CXX)
// Use log4cxx logging
//
#include "log4cxx/logger.h"
#else // defined(XOS_USE_LOG4CXX)
#if !defined(NO_USE_XOS_LOGGER_INTERFACE)
#include "xos/logger/interface.hpp"
#else // !defined(NO_USE_XOS_LOGGER_INTERFACE)
#if !defined(NO_USE_XOS_LOGGER_OUTPUT)
#include "xos/logger/output.hpp"
#endif // !defined(NO_USE_XOS_LOGGER_OUTPUT)
#endif // !defined(NO_USE_XOS_LOGGER_INTERFACE)
#endif // defined(XOS_USE_LOG4CXX)

namespace xos {
namespace io {

#if !defined(_XOS_NADIR_LOGGER_INTERFACE_HPP)
typedef mt::locker logger_implement;
#else // !defined(_XOS_NADIR_LOGGER_INTERFACE_HPP)
typedef xos::logger::interface logger_implement;
#endif // !defined(_XOS_NADIR_LOGGER_INTERFACE_HPP)
///////////////////////////////////////////////////////////////////////
///  Class: logger
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS logger: virtual public logger_implement {
public:
    typedef logger_implement Implements;

#if defined(_XOS_NADIR_LOGGER_LEVEL_HPP)
    typedef xos::logger::level level;
    typedef xos::logger::levels levels;
#else // defined(_XOS_NADIR_LOGGER_LEVEL_HPP)
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    class _EXPORT_CLASS level {
    public:
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        typedef unsigned enable;
        enum {
            fatal_shift = 0,
            error_shift,
            warn_shift,
            info_shift,
            debug_shift,
            trace_shift,

            next_shift
        };
        enum {
            none  = 0,

            fatal = (1 << fatal_shift),
            error = (1 << error_shift),
            warn  = (1 << warn_shift),
            info  = (1 << info_shift),
            debug = (1 << debug_shift),
            trace = (1 << trace_shift),

            next  = (1 << next_shift),
            all   = (next - 1)
        };
        enum {
            none_message  = 0,

            fatal_message = (fatal << next_shift),
            error_message = (error << next_shift),
            warn_message  = (warn << next_shift),
            info_message  = (info << next_shift),
            debug_message = (debug << next_shift),
            trace_message = (trace << next_shift),

            next_message  = (next << next_shift),
            all_message   = (all << next_shift)
        };
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        level(enable _enable = none): enable_(_enable){}
        level(const level& copy): enable_(copy.enable_){}
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        inline level& operator = (enable _enable){
            enable_ = _enable;
            return *this;
        }
        inline operator enable() const {
            return enable_;
        }
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
    protected:
        enable enable_;
    };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    class _EXPORT_CLASS levels {
    public:
        enum {
            fatal_shift = 1,
            error_shift,
            warn_shift,
            info_shift,
            debug_shift,
            trace_shift,

            next_shift
        };
        enum {
            none  = 0,

            fatal = ((1 << fatal_shift) - 1),
            error = ((1 << error_shift) - 1),
            warn  = ((1 << warn_shift) - 1),
            info  = ((1 << info_shift) - 1),
            debug = ((1 << debug_shift) - 1),
            trace = ((1 << trace_shift) - 1),

            next  = ((1 << next_shift) - 1),
            all   = (next >> 1)
        };
        enum {
            none_message  = 0,

            fatal_message = (fatal << (next_shift - 1)),
            error_message = (error << (next_shift - 1)),
            warn_message  = (warn << (next_shift - 1)),
            info_message  = (info << (next_shift - 1)),
            debug_message = (debug << (next_shift - 1)),
            trace_message = (trace << (next_shift - 1)),

            next_message  = (next << (next_shift - 1)),
            all_message   = (all << (next_shift - 1))
        };
    };
#endif // defined(_XOS_NADIR_LOGGER_LEVEL_HPP)

#if defined(_XOS_NADIR_LOGGER_MESSAGE_HPP)
    typedef xos::logger::location location;
    typedef xos::logger::message message;
#else // defined(_XOS_NADIR_LOGGER_MESSAGE_HPP)
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    class _EXPORT_CLASS location {
    public:
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        location
        (const char* function_name, const char* file_name, size_t line_number)
        : function_name_(function_name),
          file_name_(file_name),
          line_number_(line_number) {
        }
        location
        (const location& copy)
        : function_name_(copy.function_name_),
          file_name_(copy.file_name_),
          line_number_(copy.line_number_) {
        }
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        inline base::string get_function_name() const { return function_name_; }
        inline base::string get_file_name() const { return file_name_; }
        inline base::string get_line_number() const {
            std::stringstream ss;
            ss << line_number_;
            return ss.str();
        }
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
    protected:
        base::string function_name_;
        base::string file_name_;
        size_t line_number_;
    };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    class _EXPORT_CLASS message: public base::string {
    public:
        message& operator << (const Extends& str){ append(str); return *this; }
        message& operator << (const char* chars){ append(chars); return *this; }
        message& operator << (const wchar_t* chars){ append(chars); return *this; }
        message& operator << (int i){
            std::stringstream ss;
            ss << i;
            append(ss.str());
            return *this;
        }
    };
#endif // defined(_XOS_NADIR_LOGGER_MESSAGE_HPP)

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    class _EXPORT_CLASS class_name: public base::string {
    public:
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        class_name(const base::string& fully_qualified_function_name) {
            assign(class_name_of(fully_qualified_function_name));
        }
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        virtual base::string class_name_of
        (const base::string& fully_qualified_function_name) {
            base::string class_name;
            base::string name;
            const char* chars;
            size_t length;
            if ((chars = fully_qualified_function_name.c_str())
                && (length = fully_qualified_function_name.length())) {
                for (int state = 0, i = 0; i < length; ++i) {
                    char c=chars[i];
                    switch(state) {
                    case 1:
                        switch(c) {
                        case '(':
                            return class_name;
                        case ' ':
                            name.clear();
                            break;
                        case ':':
                            class_name.append(name);
                            name.assign("::");
                            state = 0;
                            break;
                        default:
                            state = 0;
                            name.append(":");
                            name.append(&c,1);
                        }
                        break;
                    default:
                        switch(c) {
                        case '(':
                            return class_name;
                        case ' ':
                            name.clear();
                            break;
                        case ':':
                            state = 1;
                            break;
                        default:
                            name.append(&c,1);
                        }
                    }
                }
            }
            return class_name;
        }
    };

#if !defined(_XOS_NADIR_LOGGER_INTERFACE_HPP)
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool init() { return true; }
    virtual bool fini() { return true; }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void log
    (const level& _level, const location& _location, const message& _message) {}
    virtual void logf
    (const level& _level, const location& _location, const char* format, ...) {}
    virtual void logfv
    (const level& _level, const location& _location, const char* format, va_list va) {}
    virtual void logfv
    (const level& _level, const location& _location,
     const message& _message, const char* format, va_list va) {}
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void log
    (const level& _level, const message& _message) {}
    virtual void logf
    (const level& _level, const char* format, ...) {}
    virtual void logfv
    (const level& _level, const char* format, va_list va) {}
    virtual void logfv
    (const level& _level, const message& _message, const char* format, va_list va) {}

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void enable_for(const level& _level) {}
    virtual level enabled_for() const { return level(level::none); }
    virtual bool is_enabled_for(const level& _level) const { return false; }
#endif // !defined(_XOS_NADIR_LOGGER_INTERFACE_HPP)

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    static logger* get_default();
    static void set_default(logger* _logger);
};

} // namespace io 
} // namespace xos 

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#if !defined(XOS_LOGGER_LOCATION)
#if defined(_MSC_VER)
#if (_MSC_VER >= 1300)
#define __XOS_LOGGER_FUNC__ __FUNCSIG__
#endif // (_MSC_VER >= 1300)
#else // defined(_MSC_VER)
#if defined(__GNUC__)
#if defined(USE__PRETTY_FUNCTION__)
#define __XOS_LOGGER_FUNC__ __PRETTY_FUNCTION__
#else // defined(USE__PRETTY_FUNCTION__)
#define __XOS_LOGGER_FUNC__ __FUNCTION__
#endif // defined(USE__PRETTY_FUNCTION__)
#endif // defined(__GNUC__)
#endif // defined(_MSC_VER)
#if !defined(__XOS_LOGGER_FUNC__)
#define __XOS_LOGGER_FUNC__ ""
#define __XOS_LOGGER_CLASS__ ""
#else // !defined(__XOS_LOGGER_FUNC__)
#define __XOS_LOGGER_CLASS__ ::xos::io::logger::class_name(__XOS_LOGGER_FUNC__)
#endif // !defined(__XOS_LOGGER_FUNC__)
#define XOS_LOGGER_LOCATION ::xos::io::logger::location(__XOS_LOGGER_FUNC__, __FILE__, __LINE__)
#endif // !defined(XOS_LOGGER_LOCATION)

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#if !defined(XOS_INIT_LOGGER)
#define XOS_INIT_LOGGER(logger_) { \
::xos::io::logger* logger = logger_; \
if ((logger)) { logger->init(); } }

#define XOS_FINI_LOGGER(logger_) { \
::xos::io::logger* logger = logger_; \
if ((logger)) { logger->fini(); } }
#endif // !defined(XOS_INIT_LOGGER)

#if !defined(XOS_SET_LOGGER_LEVEL)
#define XOS_SET_LOGGER_LEVEL(logger_, level_) { \
::xos::io::logger* logger = logger_; \
if ((logger)) { logger->enable_for(level_); } }

#define XOS_GET_LOGGER_LEVEL(logger_) \
((logger_)?(logger_->enabled_for()):(::xos::io::logger::level\
(::xos::io::logger::levels::none)))
#endif // !defined(XOS_SET_LOGGER_LEVEL)

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#if !defined(XOS_LOG_ANY_LEVEL)
#define XOS_LOG_ANY_LEVEL(logger_, message_) { \
::xos::io::logger* logger = logger_; \
if ((logger)) {\
   ::xos::io::logger::level level_; \
   ::xos::io::logger::message message; \
   logger->log(level_, XOS_LOGGER_LOCATION, message << message_); } }

#define XOS_LOG_ANY_LEVELF(logger_, format_, ...) { \
::xos::io::logger* logger = logger_; \
if ((logger)) {\
   ::xos::io::logger::level level_; \
   logger->logf(level_, XOS_LOGGER_LOCATION, format_, ##__VA_ARGS__); } }
#endif // !defined(XOS_LOG_ANY_LEVEL)

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#if !defined(XOS_LOG)
#define XOS_LOG(logger_, level_, message_) { \
::xos::io::logger* logger = logger_; \
if ((logger)?(logger->is_enabled_for(level_)):(false)) {\
   ::xos::io::logger::message message; \
   logger->log(level_, XOS_LOGGER_LOCATION, message << message_); } }

#define XOS_LOGF(logger_, level_, format_, ...) { \
::xos::io::logger* logger = logger_; \
if ((logger)?(logger->is_enabled_for(level_)):(false)) {\
   logger->logf(level_, XOS_LOGGER_LOCATION, format_, ##__VA_ARGS__); } }
#endif // !defined(XOS_LOG)

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#if !defined(XOS_LOG_MESSAGE_ANY_LEVEL)
#define XOS_LOG_MESSAGE_ANY_LEVEL(logger_, message_) { \
::xos::io::logger* logger = logger_; \
if ((logger)) {\
   ::xos::io::logger::level level_; \
   ::xos::io::logger::message message; \
   logger->log(level_, message << message_); } }

#define XOS_LOG_MESSAGE_ANY_LEVELF(logger_, format_, ...) { \
::xos::io::logger* logger = logger_; \
if ((logger)) {\
   ::xos::io::logger::level level_; \
   logger->logf(level_, format_, ##__VA_ARGS__); } }

#define XOS_LOG_MESSAGE_ANY_LEVELFV(logger_, format_, va_) { \
::xos::io::logger* logger = logger_; \
if ((logger)) {\
   ::xos::io::logger::level level_; \
   logger->logfv(level_, format_, va_); } }

#define XOS_LOG_MESSAGE_ANY_LEVELMFV(logger_, message_, format_, va_) { \
::xos::io::logger* logger = logger_; \
if ((logger)) {\
   ::xos::io::logger::level level_; \
   ::xos::io::logger::message message; \
   logger->logfv(level_, message << message_, format_, va_); } }
#endif // !defined(XOS_LOG_MESSAGE_ANY_LEVEL)

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#if !defined(XOS_LOG_MESSAGE)
#define XOS_LOG_MESSAGE(logger_, level_, message_) { \
::xos::io::logger* logger = logger_; \
if ((logger)?(logger->is_enabled_for(level_)):(false)) {\
   ::xos::io::logger::message message; \
   logger->log(level_, message << message_); } }

#define XOS_LOG_MESSAGEF(logger_, level_, format_, ...) { \
::xos::io::logger* logger = logger_; \
if ((logger)?(logger->is_enabled_for(level_)):(false)) {\
   logger->logf(level_, format_, ##__VA_ARGS__); } }

#define XOS_LOG_MESSAGEFV(logger_, level_, format_, va_) { \
::xos::io::logger* logger = logger_; \
if ((logger)?(logger->is_enabled_for(level_)):(false)) {\
   logger->logfv(level_, format_, va_); } }

#define XOS_LOG_MESSAGEMFV(logger_, level_, message_, format_, va_) { \
::xos::io::logger* logger = logger_; \
::xos::io::logger::message message; \
if ((logger)?(logger->is_enabled_for(level_)):(false)) {\
   logger->logfv(level_, message << message_, format_, va_); } }
#endif // !defined(XOS_LOG_MESSAGE)

#if !defined(XOS_USE_LOG4CXX)
// Use xos logging
//
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#if !defined(XOS_DEFAULT_LOGGER)
#if !defined(XOS_USE_LOGGER)
#define XOS_DEFAULT_LOGGER ::xos::io::logger::get_default()
#else // !defined(XOS_USE_LOGGER)
#define XOS_DEFAULT_LOGGER ::xos::io::logger::get_default()
#endif // !defined(XOS_USE_LOGGER)

#define XOS_LOGGER_INIT() XOS_INIT_LOGGER(XOS_DEFAULT_LOGGER)
#define XOS_LOGGER_FINI() XOS_FINI_LOGGER(XOS_DEFAULT_LOGGER)

#define XOS_SET_LOGGING_LEVEL(level)  XOS_SET_LOGGER_LEVEL(XOS_DEFAULT_LOGGER, level)
#define XOS_GET_LOGGING_LEVEL(level)  (level = XOS_GET_LOGGER_LEVEL(XOS_DEFAULT_LOGGER))
#endif // !defined(XOS_DEFAULT_LOGGER)

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#if !defined(XOS_LOGGING_LEVELS)
#define XOS_LOGGING_LEVELS ::xos::io::logger::level::enable

#define XOS_LOGGING_LEVELS_ALL ::xos::io::logger::levels::all
#define XOS_LOGGING_LEVELS_NONE ::xos::io::logger::levels::none
#define XOS_LOGGING_LEVELS_FATAL ::xos::io::logger::levels::fatal
#define XOS_LOGGING_LEVELS_ERROR ::xos::io::logger::levels::error
#define XOS_LOGGING_LEVELS_WARN ::xos::io::logger::levels::warn
#define XOS_LOGGING_LEVELS_INFO ::xos::io::logger::levels::info
#define XOS_LOGGING_LEVELS_DEBUG ::xos::io::logger::levels::debug
#define XOS_LOGGING_LEVELS_TRACE ::xos::io::logger::levels::trace

#define XOS_LOGGING_LEVELS_ALL_MESSAGE ::xos::io::logger::levels::all_message
#define XOS_LOGGING_LEVELS_NONE_MESSAGE ::xos::io::logger::levels::none_message
#define XOS_LOGGING_LEVELS_FATAL_MESSAGE ::xos::io::logger::levels::fatal_message
#define XOS_LOGGING_LEVELS_ERROR_MESSAGE ::xos::io::logger::levels::error_message
#define XOS_LOGGING_LEVELS_WARN_MESSAGE ::xos::io::logger::levels::warn_message
#define XOS_LOGGING_LEVELS_INFO_MESSAGE ::xos::io::logger::levels::info_message
#define XOS_LOGGING_LEVELS_DEBUG_MESSAGE ::xos::io::logger::levels::debug_message
#define XOS_LOGGING_LEVELS_TRACE_MESSAGE ::xos::io::logger::levels::trace_message
#endif // !defined(XOS_LOGGING_LEVELS)

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#if !defined(XOS_LOG_ANY)
#define XOS_LOG_ANY(message) XOS_LOG_ANY_LEVEL(XOS_DEFAULT_LOGGER, message)
#define XOS_LOG_FATAL(message) XOS_LOG(XOS_DEFAULT_LOGGER, ::xos::io::logger::level::fatal, message)
#define XOS_LOG_ERROR(message) XOS_LOG(XOS_DEFAULT_LOGGER, ::xos::io::logger::level::error, message)
#define XOS_LOG_WARN(message) XOS_LOG(XOS_DEFAULT_LOGGER, ::xos::io::logger::level::warn, message)
#define XOS_LOG_INFO(message) XOS_LOG(XOS_DEFAULT_LOGGER, ::xos::io::logger::level::info, message)
#define XOS_LOG_DEBUG(message) XOS_LOG(XOS_DEFAULT_LOGGER, ::xos::io::logger::level::debug, message)
#define XOS_LOG_TRACE(message) XOS_LOG(XOS_DEFAULT_LOGGER, ::xos::io::logger::level::trace, message)
#endif // !defined(XOS_LOG_ANY)

#if !defined(XOS_LOG_ANYF)
#define XOS_LOG_ANYF(message, ...) XOS_LOG_ANY_LEVELF(XOS_DEFAULT_LOGGER, message, ##__VA_ARGS__)
#define XOS_LOG_FATALF(message, ...) XOS_LOGF(XOS_DEFAULT_LOGGER, ::xos::io::logger::level::fatal, message, ##__VA_ARGS__)
#define XOS_LOG_ERRORF(message, ...) XOS_LOGF(XOS_DEFAULT_LOGGER, ::xos::io::logger::level::error, message, ##__VA_ARGS__)
#define XOS_LOG_WARNF(message, ...) XOS_LOGF(XOS_DEFAULT_LOGGER, ::xos::io::logger::level::warn, message, ##__VA_ARGS__)
#define XOS_LOG_INFOF(message, ...) XOS_LOGF(XOS_DEFAULT_LOGGER, ::xos::io::logger::level::info, message, ##__VA_ARGS__)
#define XOS_LOG_DEBUGF(message, ...) XOS_LOGF(XOS_DEFAULT_LOGGER, ::xos::io::logger::level::debug, message, ##__VA_ARGS__)
#define XOS_LOG_TRACEF(message, ...) XOS_LOGF(XOS_DEFAULT_LOGGER, ::xos::io::logger::level::trace, message, ##__VA_ARGS__)
#endif // !defined(XOS_LOG_ANYF)

#if !defined(XOS_LOG_MESSAGE_ANY)
#define XOS_LOG_MESSAGE_ANY(message) XOS_LOG_MESSAGE_ANY_LEVEL(XOS_DEFAULT_LOGGER, message)
#define XOS_LOG_MESSAGE_FATAL(message) XOS_LOG_MESSAGE(XOS_DEFAULT_LOGGER, ::xos::io::logger::level::fatal_message, message)
#define XOS_LOG_MESSAGE_ERROR(message) XOS_LOG_MESSAGE(XOS_DEFAULT_LOGGER, ::xos::io::logger::level::error_message, message)
#define XOS_LOG_MESSAGE_WARN(message) XOS_LOG_MESSAGE(XOS_DEFAULT_LOGGER, ::xos::io::logger::level::warn_message, message)
#define XOS_LOG_MESSAGE_INFO(message) XOS_LOG_MESSAGE(XOS_DEFAULT_LOGGER, ::xos::io::logger::level::info_message, message)
#define XOS_LOG_MESSAGE_DEBUG(message) XOS_LOG_MESSAGE(XOS_DEFAULT_LOGGER, ::xos::io::logger::level::debug_message, message)
#define XOS_LOG_MESSAGE_TRACE(message) XOS_LOG_MESSAGE(XOS_DEFAULT_LOGGER, ::xos::io::logger::level::trace_message, message)
#endif // !defined(XOS_LOG_MESSAGE_ANY)

#if !defined(XOS_LOG_MESSAGE_ANYF)
#define XOS_LOG_MESSAGE_ANYF(message, ...) XOS_LOG_MESSAGE_ANY_LEVELF(XOS_DEFAULT_LOGGER, message, ##__VA_ARGS__)
#define XOS_LOG_MESSAGE_FATALF(message, ...) XOS_LOG_MESSAGEF(XOS_DEFAULT_LOGGER, ::xos::io::logger::level::fatal_message, message, ##__VA_ARGS__)
#define XOS_LOG_MESSAGE_ERRORF(message, ...) XOS_LOG_MESSAGEF(XOS_DEFAULT_LOGGER, ::xos::io::logger::level::error_message, message, ##__VA_ARGS__)
#define XOS_LOG_MESSAGE_WARNF(message, ...) XOS_LOG_MESSAGEF(XOS_DEFAULT_LOGGER, ::xos::io::logger::level::warn_message, message, ##__VA_ARGS__)
#define XOS_LOG_MESSAGE_INFOF(message, ...) XOS_LOG_MESSAGEF(XOS_DEFAULT_LOGGER, ::xos::io::logger::level::info_message, message, ##__VA_ARGS__)
#define XOS_LOG_MESSAGE_DEBUGF(message, ...) XOS_LOG_MESSAGEF(XOS_DEFAULT_LOGGER, ::xos::io::logger::level::debug_message, message, ##__VA_ARGS__)
#define XOS_LOG_MESSAGE_TRACEF(message, ...) XOS_LOG_MESSAGEF(XOS_DEFAULT_LOGGER, ::xos::io::logger::level::trace_message, message, ##__VA_ARGS__)
#endif // !defined(XOS_LOG_MESSAGE_ANYF)

#if !defined(XOS_LOG_MESSAGE_ANYFV)
#define XOS_LOG_MESSAGE_ANYFV(message, va) XOS_LOG_MESSAGE_ANY_LEVELFV(XOS_DEFAULT_LOGGER, message, va)
#define XOS_LOG_MESSAGE_FATALFV(message, va) XOS_LOG_MESSAGEFV(XOS_DEFAULT_LOGGER, ::xos::io::logger::level::fatal_message, message, va)
#define XOS_LOG_MESSAGE_ERRORFV(message, va) XOS_LOG_MESSAGEFV(XOS_DEFAULT_LOGGER, ::xos::io::logger::level::error_message, message, va)
#define XOS_LOG_MESSAGE_WARNFV(message, va) XOS_LOG_MESSAGEFV(XOS_DEFAULT_LOGGER, ::xos::io::logger::level::warn_message, message, va)
#define XOS_LOG_MESSAGE_INFOFV(message, va) XOS_LOG_MESSAGEFV(XOS_DEFAULT_LOGGER, ::xos::io::logger::level::info_message, message, va)
#define XOS_LOG_MESSAGE_DEBUGFV(message, va) XOS_LOG_MESSAGEFV(XOS_DEFAULT_LOGGER, ::xos::io::logger::level::debug_message, message, va)
#define XOS_LOG_MESSAGE_TRACEFV(message, va) XOS_LOG_MESSAGEFV(XOS_DEFAULT_LOGGER, ::xos::io::logger::level::trace_message, message, va)
#endif // !defined(XOS_LOG_MESSAGE_ANYFV)

#if !defined(XOS_LOG_MESSAGE_ANYMFV)
#define XOS_LOG_MESSAGE_ANYMFV(message, format, va) XOS_LOG_MESSAGE_ANY_LEVELMFV(XOS_DEFAULT_LOGGER, message, format, va)
#define XOS_LOG_MESSAGE_FATALMFV(message, format, va) XOS_LOG_MESSAGEMFV(XOS_DEFAULT_LOGGER, ::xos::io::logger::level::fatal_message, message, format, va)
#define XOS_LOG_MESSAGE_ERRORMFV(message, format, va) XOS_LOG_MESSAGEMFV(XOS_DEFAULT_LOGGER, ::xos::io::logger::level::error_message, message, format, va)
#define XOS_LOG_MESSAGE_WARNMFV(message, format, va) XOS_LOG_MESSAGEMFV(XOS_DEFAULT_LOGGER, ::xos::io::logger::level::warn_message, message, format, va)
#define XOS_LOG_MESSAGE_INFOMFV(message, format, va) XOS_LOG_MESSAGEMFV(XOS_DEFAULT_LOGGER, ::xos::io::logger::level::info_message, message, format, va)
#define XOS_LOG_MESSAGE_DEBUGMFV(message, format, va) XOS_LOG_MESSAGEMFV(XOS_DEFAULT_LOGGER, ::xos::io::logger::level::debug_message, message, format, va)
#define XOS_LOG_MESSAGE_TRACEMFV(message, format, va) XOS_LOG_MESSAGEMFV(XOS_DEFAULT_LOGGER, ::xos::io::logger::level::trace_message, message, format, va)
#endif // !defined(XOS_LOG_MESSAGE_ANYMFV)

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#if !defined(XOS_LOGGING_LEVELS_DEFAULT)
#if defined(XOS_DEFAULT_LOG_ERROR)
#define XOS_LOGGING_LEVELS_DEFAULT XOS_LOGGING_LEVELS_ERROR
#elif defined(XOS_DEFAULT_LOG_DEBUG)
#define XOS_LOGGING_LEVELS_DEFAULT XOS_LOGGING_LEVELS_DEBUG
#elif defined(XOS_DEFAULT_LOG_TRACE)
#define XOS_LOGGING_LEVELS_DEFAULT XOS_LOGGING_LEVELS_TRACE
#endif // defined(XOS_DEFAULT_LOG_ERROR)
#endif // !defined(XOS_LOGGING_LEVELS_DEFAULT)

#if !defined(XOS_LOGGING_LEVELS_DEFAULT)
#if defined(TRACE_BUILD)
#define XOS_LOGGING_LEVELS_DEFAULT XOS_LOGGING_LEVELS_TRACE
#else // defined(TRACE_BUILD)
#if defined(DEBUG_BUILD)
#define XOS_LOGGING_LEVELS_DEFAULT XOS_LOGGING_LEVELS_DEBUG
#else // defined(DEBUG_BUILD)
#define XOS_LOGGING_LEVELS_DEFAULT XOS_LOGGING_LEVELS_ERROR
#endif // defined(DEBUG_BUILD)
#endif // defined(TRACE_BUILD)
#endif // !defined(XOS_LOGGING_LEVELS_DEFAULT)

// default logging levels
//
#if !defined(XOS_DEFAULT_LOGGING_LEVELS)
#define XOS_DEFAULT_LOGGING_LEVELS XOS_LOGGING_LEVELS_DEFAULT
#endif // !defined(XOS_DEFAULT_LOGGING_LEVELS)
#endif // !defined(XOS_USE_LOG4CXX)

#if !defined(XOS_ERR_LOG)
#define NDEF_XOS_ERR_LOG
#define XOS_ERR_LOG(message_)
#define XOS_ERR_LOG_FATAL(message_) XOS_ERR_LOG(message_)
#define XOS_ERR_LOG_ERROR(message_) XOS_ERR_LOG(message_)
#define XOS_ERR_LOG_WARN(message_) XOS_ERR_LOG(message_)
#define XOS_ERR_LOG_INFO(message_) XOS_ERR_LOG(message_)
#define XOS_ERR_LOG_DEBUG(message_) XOS_ERR_LOG(message_)
#define XOS_ERR_LOG_TRACE(message_) XOS_ERR_LOG(message_)
#endif // !defined(XOS_ERR_LOG)

#if !defined(XOS_IS_ERR_LOGGING)
#define XOS_IS_ERR_LOGGING_FATAL(message_) { if (this->is_logging()) XOS_LOG_FATAL(message_) else XOS_ERR_LOG_FATAL(message_) }
#define XOS_IS_ERR_LOGGING_ERROR(message_) { if (this->is_logging()) XOS_LOG_ERROR(message_) else XOS_ERR_LOG_ERROR(message_) }
#define XOS_IS_ERR_LOGGING_WARN(message_) { if (this->is_logging()) XOS_LOG_WARN(message_) else XOS_ERR_LOG_WARN(message_) }
#define XOS_IS_ERR_LOGGING_INFO(message_) { if (this->is_logging()) XOS_LOG_INFO(message_) else XOS_ERR_LOG_INFO(message_) }
#define XOS_IS_ERR_LOGGING_DEBUG(message_) { if (this->is_logging()) XOS_LOG_DEBUG(message_) else XOS_ERR_LOG_DEBUG(message_) }
#define XOS_IS_ERR_LOGGING_TRACE(message_) { if (this->is_logging()) XOS_LOG_TRACE(message_) else XOS_ERR_LOG_TRACE(message_) }
#endif // !defined(XOS_ERR_LOG)

#if !defined(XOS_IS_LOGGING)
#define XOS_IS_LOGGING_FATAL(message_) { if (this->is_logging()) XOS_LOG_FATAL(message_) }
#define XOS_IS_LOGGING_ERROR(message_) { if (this->is_logging()) XOS_LOG_ERROR(message_) }
#define XOS_IS_LOGGING_WARN(message_) { if (this->is_logging()) XOS_LOG_WARN(message_) }
#define XOS_IS_LOGGING_INFO(message_) { if (this->is_logging()) XOS_LOG_INFO(message_) }
#define XOS_IS_LOGGING_DEBUG(message_) { if (this->is_logging()) XOS_LOG_DEBUG(message_) }
#define XOS_IS_LOGGING_TRACE(message_) { if (this->is_logging()) XOS_LOG_TRACE(message_) }
#endif // !defined(XOS_ERR_LOG)

#if !defined(NO_LOG_DEFINES)
// LOG_DEFINES
// ...
#if !defined(LOG_ANY)
#define LOG_ANY XOS_LOG_ANY
#define LOG_FATAL XOS_LOG_FATAL
#define LOG_ERROR XOS_LOG_ERROR
#define LOG_WARN XOS_LOG_WARN
#define LOG_INFO XOS_LOG_INFO
#define LOG_DEBUG XOS_LOG_DEBUG
#define LOG_TRACE XOS_LOG_TRACE
#endif // !defined(LOG_ANY)

#if !defined(LOG_ANYF)
#define LOG_ANYF XOS_LOG_ANYF
#define LOG_FATALF XOS_LOG_FATALF
#define LOG_ERRORF XOS_LOG_ERRORF
#define LOG_WARNF XOS_LOG_WARNF
#define LOG_INFOF XOS_LOG_INFOF
#define LOG_DEBUGF XOS_LOG_DEBUGF
#define LOG_TRACEF XOS_LOG_TRACEF
#endif // !defined(LOG_ANYF)

#if !defined(LOG_MESSAGE_ANY)
#define LOG_MESSAGE_ANY XOS_LOG_MESSAGE_ANY
#define LOG_MESSAGE_FATAL XOS_LOG_MESSAGE_FATAL
#define LOG_MESSAGE_ERROR XOS_LOG_MESSAGE_ERROR
#define LOG_MESSAGE_WARN XOS_LOG_MESSAGE_WARN
#define LOG_MESSAGE_INFO XOS_LOG_MESSAGE_INFO
#define LOG_MESSAGE_DEBUG XOS_LOG_MESSAGE_DEBUG
#define LOG_MESSAGE_TRACE XOS_LOG_MESSAGE_TRACE
#endif // !defined(LOG_MESSAGE_ANY)

#if !defined(LOG_MESSAGE_ANYF)
#define LOG_MESSAGE_ANYF XOS_LOG_MESSAGE_ANYF
#define LOG_MESSAGE_FATALF XOS_LOG_MESSAGE_FATALF
#define LOG_MESSAGE_ERRORF XOS_LOG_MESSAGE_ERRORF
#define LOG_MESSAGE_WARNF XOS_LOG_MESSAGE_WARNF
#define LOG_MESSAGE_INFOF XOS_LOG_MESSAGE_INFOF
#define LOG_MESSAGE_DEBUGF XOS_LOG_MESSAGE_DEBUGF
#define LOG_MESSAGE_TRACEF XOS_LOG_MESSAGE_TRACEF
#endif // !defined(LOG_MESSAGE_ANYF)

#if !defined(ERR_LOG)
#define ERR_LOG_ANY XOS_ERR_LOG_ANY
#define ERR_LOG_FATAL XOS_ERR_LOG_FATAL
#define ERR_LOG_ERROR XOS_ERR_LOG_ERROR
#define ERR_LOG_WARN XOS_ERR_LOG_WARN
#define ERR_LOG_INFO XOS_ERR_LOG_INFO
#define ERR_LOG_DEBUG XOS_ERR_LOG_DEBUG
#define ERR_LOG_TRACE XOS_ERR_LOG_TRACE
#endif // !defined(ERR_LOG)

#if !defined(IS_ERR_LOGGING)
#define IS_ERR_LOGGING_ANY XOS_IS_ERR_LOGGING_ANY
#define IS_ERR_LOGGING_FATAL XOS_IS_ERR_LOGGING_FATAL
#define IS_ERR_LOGGING_ERROR XOS_IS_ERR_LOGGING_ERROR
#define IS_ERR_LOGGING_WARN XOS_IS_ERR_LOGGING_WARN
#define IS_ERR_LOGGING_INFO XOS_IS_ERR_LOGGING_INFO
#define IS_ERR_LOGGING_DEBUG XOS_IS_ERR_LOGGING_DEBUG
#define IS_ERR_LOGGING_TRACE XOS_IS_ERR_LOGGING_TRACE
#endif // !defined(ERR_LOG)

#if !defined(IS_LOGGING)
#define IS_LOGGING_ANY XOS_IS_LOGGING_ANY
#define IS_LOGGING_FATAL XOS_IS_LOGGING_FATAL
#define IS_LOGGING_ERROR XOS_IS_LOGGING_ERROR
#define IS_LOGGING_WARN XOS_IS_LOGGING_WARN
#define IS_LOGGING_INFO XOS_IS_LOGGING_INFO
#define IS_LOGGING_DEBUG XOS_IS_LOGGING_DEBUG
#define IS_LOGGING_TRACE XOS_IS_LOGGING_TRACE
#endif // !defined(ERR_LOG)

#if !defined(LOGGER_LOG_ANY)
#define LOGGER_LOG_ANY XOS_LOG_ANY
#define LOGGER_LOG_FATAL XOS_LOG_FATAL
#define LOGGER_LOG_ERROR XOS_LOG_ERROR
#define LOGGER_LOG_WARN XOS_LOG_WARN
#define LOGGER_LOG_INFO XOS_LOG_INFO
#define LOGGER_LOG_DEBUG XOS_LOG_DEBUG
#define LOGGER_LOG_TRACE XOS_LOG_TRACE
#endif // !defined(LOGGER_LOG_ANY)

#if !defined(LOGGER_IS_LOGGED_ANY)
#define LOGGER_IS_LOGGED_ANY XOS_IS_LOGGING_ANY
#define LOGGER_IS_LOGGED_FATAL XOS_IS_LOGGING_FATAL
#define LOGGER_IS_LOGGED_ERROR XOS_IS_LOGGING_ERROR
#define LOGGER_IS_LOGGED_WARN XOS_IS_LOGGING_WARN
#define LOGGER_IS_LOGGED_INFO XOS_IS_LOGGING_INFO
#define LOGGER_IS_LOGGED_DEBUG XOS_IS_LOGGING_DEBUG
#define LOGGER_IS_LOGGED_TRACE XOS_IS_LOGGING_TRACE
#endif // !defined(ERR_LOG)
// ...
// LOG_DEFINES
#endif // !defined(NO_LOG_DEFINES)

#endif // _XOS_NADIR_XOS_IO_LOGGER_HPP
