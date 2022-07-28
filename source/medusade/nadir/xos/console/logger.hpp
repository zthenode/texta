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
///   File: logger.hpp
///
/// Author: $author$
///   Date: 11/6/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_CONSOLE_LOGGER_HPP
#define _XOS_NADIR_CONSOLE_LOGGER_HPP

#include "xos/logger/interface.hpp"
#include "xos/console/io.hpp"

namespace xos {
namespace console {

typedef xos::console::char_io logger_io_implements;
typedef xos::logger::instance_implements logger_implements;
typedef xos::logger::instance logger_extends;
///////////////////////////////////////////////////////////////////////
///  Class: logger
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS logger
: virtual public logger_io_implements, 
  virtual public logger_implements, public logger_extends {
public:
    typedef logger_io_implements IoImplements;
    typedef logger_implements Implements;
    typedef logger_extends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    logger() {
    }
    virtual ~logger() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t logfv(const char_t* format, va_list va) {
        ssize_t count = 0;
        count = this->errfv(format, va);
        return count;
    }
    virtual ssize_t log(const char_t* chars) {
        ssize_t count = 0;
        count = this->err(chars);
        return count;
    }
    virtual ssize_t logflush() {
        ssize_t count = 0;
        count = this->err_flush();
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace console 
} // namespace xos 

#endif // _XOS_NADIR_CONSOLE_LOGGER_HPP 
