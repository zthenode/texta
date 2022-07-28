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
///   File: lock.hpp
///
/// Author: $author$
///   Date: 8/16/2014
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_MT_LOCK_HPP
#define _XOS_NADIR_XOS_MT_LOCK_HPP

#include "xos/mt/locker.hpp"

namespace xos {
namespace mt {

typedef base::implement_base lock_implement;
typedef base::base lock_extend;
///////////////////////////////////////////////////////////////////////
///  Class: lockt
///////////////////////////////////////////////////////////////////////
template
<class TLocker = locker,
 class TExtends = lock_extend,
 class TImplements = lock_implement>

class _EXPORT_CLASS lockt: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    lockt(TLocker& locker): locker_(locker) {
        if (!(locker_.lock())) {
            locker_exception e = lock_failed;
            throw (e);
        }
    }
    virtual ~lockt() {
        if (!(locker_.unlock())) {
            locker_exception e = unlock_failed;
            throw (e);
        }
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    TLocker& locker_;
};
typedef lockt<> lock;

} // namespace mt 
} // namespace xos 

#endif // _XOS_NADIR_XOS_MT_LOCK_HPP 
