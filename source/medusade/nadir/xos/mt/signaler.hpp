///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2016 $organization$
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
///   File: signaler.hpp
///
/// Author: $author$
///   Date: 2/14/2016
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_MT_SIGNALER_HPP
#define _XOS_NADIR_XOS_MT_SIGNALER_HPP

#include "xos/mt/os/mutex.hpp"
#include "xos/mt/lock.hpp"

namespace xos {
namespace mt {

typedef base::implement_base signaler_implements;
typedef base::base signaler_extends;
///////////////////////////////////////////////////////////////////////
///  Class: signalert
///////////////////////////////////////////////////////////////////////
template
<typename TRaised = bool, TRaised VRaised = true, TRaised VLowered = false,
 class TImplements = signaler_implements, class TExtends = signaler_extends>

class _EXPORT_CLASS signalert: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    signalert(TRaised& raised): raise_(VLowered), raised_(raised) {
    }
    signalert(): raise_(VLowered), raised_(raise_) {
    }
    virtual ~signalert() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void operator()(bool raise = true) {
        xos::mt::lock locked(lock_);
        if ((raise)) {
            raised_ = VRaised;
        } else {
            raised_ = VLowered;
        }
    }
    virtual operator TRaised() {
        xos::mt::lock locked(lock_);
        bool raised = raised_;
        return raised;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    TRaised raise_;
    TRaised& raised_;
    xos::mt::os::mutex lock_;
};
typedef signalert<> signaler;

} // namespace mt 
} // namespace xos 

#endif // _XOS_NADIR_XOS_MT_SIGNALER_HPP 
