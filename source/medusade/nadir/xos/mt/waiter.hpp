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
///   File: waiter.hpp
///
/// Author: $author$
///   Date: 8/14/2014
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_MT_WAITER_HPP
#define _XOS_NADIR_XOS_MT_WAITER_HPP

#include "xos/base/base.hpp"

namespace xos {
namespace mt {

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
enum wait_status {
    wait_success,
    wait_failed,
    wait_busy,
    wait_interrupted,
    wait_invalid
};

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
enum wait_time {
    wait_forever = -1,
    wait_none = 0
};

typedef base::implement_base wait_implement;
///////////////////////////////////////////////////////////////////////
///  Class: waitert
///////////////////////////////////////////////////////////////////////
template <class TImplements = wait_implement>

class _EXPORT_CLASS waitert: virtual public TImplements {
public:
    typedef TImplements Implements;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool wait() { return false; }
    virtual wait_status try_wait() { return wait_failed; }
    virtual wait_status timed_wait(mseconds_t milliseconds) { return wait_failed; }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef waitert<> waiter;

} // namespace mt 
} // namespace xos 

#endif // _XOS_NADIR_XOS_MT_WAITER_HPP
