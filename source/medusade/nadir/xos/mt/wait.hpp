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
///   File: wait.hpp
///
/// Author: $author$
///   Date: 8/16/2014
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_MT_WAIT_HPP
#define _XOS_NADIR_XOS_MT_WAIT_HPP

#include "xos/mt/waiter.hpp"

namespace xos {
namespace mt {

typedef base::implement_base wait_implement;
typedef base::base wait_extend;
///////////////////////////////////////////////////////////////////////
///  Class: waitt
///////////////////////////////////////////////////////////////////////
template
<class TWaiter = waiter,
 class TExtends = wait_extend,
 class TImplements = wait_implement>

class _EXPORT_CLASS waitt: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    waitt(TWaiter& waiter): waiter_(waiter) {
        if (!(waiter_.wait())) {
            wait_status e = wait_failed;
            throw (e);
        }
    }
    virtual ~waitt() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    TWaiter& waiter_;
};
typedef waitt<> wait;

} // namespace mt 
} // namespace xos 

#endif // _XOS_NADIR_XOS_MT_WAIT_HPP 
