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
///   File: message.hpp
///
/// Author: $author$
///   Date: 10/20/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_LOGGER_MESSAGE_HPP
#define _XOS_NADIR_LOGGER_MESSAGE_HPP

#include "xos/base/string.hpp"
#include <sstream>

namespace xos {
namespace logger {

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS function: public base::string {
public:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS location: public base::string {
public:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    location
    (const char* function_name, const char* file_name, size_t line_number)
    : function_name_(function_name),
      file_name_(file_name),
      line_number_(line_number) {
    }
    location(const location& copy)
    : function_name_(copy.function_name_),
      file_name_(copy.file_name_),
      line_number_(copy.line_number_) {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual base::string get_function_name() const { 
        return function_name_; 
    }
    virtual base::string get_file_name() const { 
        return file_name_; 
    }
    virtual base::string get_line_number() const {
        std::stringstream ss;
        ss << line_number_;
        return ss.str();
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual base::string function_name() const { 
        return get_function_name(); 
    }
    virtual base::string file_name() const { 
        return get_file_name(); 
    }
    virtual base::string line_number() const {
        return get_line_number();
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
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual message& operator << (const Extends& str) { 
        append(str); 
        return *this; 
    }
    virtual message& operator << (const char* chars) { 
        append(chars); 
        return *this; 
    }
    virtual message& operator << (const wchar_t* chars) { 
        append(chars); 
        return *this; 
    }
    virtual message& operator << (int i) {
        std::stringstream ss;
        ss << i;
        append(ss.str());
        return *this;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace logger 
} // namespace xos 

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#if !defined(__XOS_LOGGER_FUNC__)
#define __XOS_LOGGER_FUNC__ __FUNCTION__
#endif // !defined(__XOS_LOGGER_FUNCTION__)

#if !defined(XOS_LOGGER_FUNCTION)
#define XOS_LOGGER_FUNCTION \
    ::xos::logger::function(__XOS_LOGGER_FUNC__)
#endif // !defined(XOS_LOGGER_LOCATION)

#if !defined(XOS_LOGGER_LOCATION)
#define XOS_LOGGER_LOCATION \
    ::xos::logger::location(__XOS_LOGGER_FUNC__, __FILE__, __LINE__)
#endif // !defined(XOS_LOGGER_LOCATION)

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#endif // _XOS_NADIR_LOGGER_MESSAGE_HPP 
