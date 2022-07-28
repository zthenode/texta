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
///   File: acquirer.hpp
///
/// Author: $author$
///   Date: 8/16/2014
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_MT_ACQUIRER_HPP
#define _XOS_NADIR_XOS_MT_ACQUIRER_HPP

#include "xos/mt/releaser.hpp"
#include "xos/mt/waiter.hpp"

namespace xos {
namespace mt {

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
enum acquirer_exception {
    acquire_failed,
    release_failed
};

typedef releaser acquirer_implement;
///////////////////////////////////////////////////////////////////////
///  Class: acquirert
///////////////////////////////////////////////////////////////////////
template <class TImplements = acquirer_implement>

class _EXPORT_CLASS acquirert: virtual public TImplements {
public:
    typedef TImplements Implements;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool acquire() { return false; }
    virtual wait_status try_acquire() { return wait_failed; }
    virtual wait_status timed_acquire(mseconds_t milliseconds) { return wait_failed; }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef acquirert<> acquirer;

} // namespace mt 
} // namespace xos 

#endif // _XOS_NADIR_XOS_MT_ACQUIRER_HPP 
