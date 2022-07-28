///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2018 $organization$
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
///   Date: 1/1/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_IO_CONSOLE_LOGGER_HPP
#define _XOS_NADIR_XOS_IO_CONSOLE_LOGGER_HPP

#include "xos/io/logger_base.hpp"
#include "xos/io/logger_stdio.hpp"
#include "xos/console/io.hpp"

namespace xos {
namespace io {
namespace console {

///////////////////////////////////////////////////////////////////////
///  Class: loggert
///////////////////////////////////////////////////////////////////////
template
<class TIo = xos::console::char_io, 
 class TLogger = io::logger_baset<mt::locked>,
 class TImplements = typename TLogger::Implements, class TExtends = TLogger>

class _EXPORT_CLASS loggert: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef typename TIo::char_t char_t;
    
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    loggert(TIo &io): Extends(io), io_(io) {
    }
    virtual ~loggert() {
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t logfv(const char_t* format, va_list va) {
        ssize_t count = 0;
        count = io_.errfv(format, va);
        return count;
    }
    virtual ssize_t log(const char_t* chars) {
        ssize_t count = 0;
        count = io_.err(chars);
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    TIo &io_;
};
typedef loggert<> logger;

} // namespace console 
} // namespace io 
} // namespace xos 

#endif // _XOS_NADIR_XOS_IO_CONSOLE_LOGGER_HPP 

