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
///   File: io.hpp
///
/// Author: $author$
///   Date: 1/1/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_IO_CONSOLE_IO_HPP
#define _XOS_NADIR_XOS_IO_CONSOLE_IO_HPP

#include "xos/console/io.hpp"

namespace xos {
namespace io {
namespace console {

///////////////////////////////////////////////////////////////////////
///  Class: iot
///////////////////////////////////////////////////////////////////////
template
<class TImplements = xos::console::char_io, class TExtends = base::base>

class _EXPORT_CLASS iot: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef mt::wait_status wait_status_t;
    typedef mt::locked locked_t;
    typedef mt::locked default_locked_t;
    
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    iot(locked_t& locked): locked_(locked) {
    }
    iot(): locked_(default_locked_) {
    }
    virtual ~iot() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool unlock() { 
        return locked_.unlock(); 
    }
    virtual bool lock() { 
        return locked_.lock(); 
    }
    virtual wait_status_t try_lock() { 
        return locked_.try_lock(); 
    }
    virtual wait_status_t timed_lock(mseconds_t milliseconds) { 
        return locked_.timed_lock(milliseconds); 
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    default_locked_t default_locked_;
    locked_t& locked_;
};
typedef iot<> char_io;

} // namespace console 
} // namespace io 
} // namespace xos 

#endif // _XOS_NADIR_XOS_IO_CONSOLE_IO_HPP 

        

