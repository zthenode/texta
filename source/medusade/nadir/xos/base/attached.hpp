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
///   File: attached.hpp
///
/// Author: $author$
///   Date: 9/17/2014
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_BASE_ATTACHED_HPP
#define _XOS_NADIR_XOS_BASE_ATTACHED_HPP

#include "xos/base/attacher.hpp"

namespace xos {
namespace base {

typedef base attached_extends;
///////////////////////////////////////////////////////////////////////
///  Class: attachedt
///////////////////////////////////////////////////////////////////////
template
<typename TAttached = void*,
 typename TUnattached = int,
 TUnattached VUnattached = 0,
 class TImplements = attachert
 <TAttached, TUnattached, VUnattached, attacher_implements>,
 class TExtends = attached_extends>

class _EXPORT_CLASS attachedt: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef TAttached attached_t;
    typedef TUnattached unattached_t;
    enum { unattached = VUnattached };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    attachedt
    (attached_t detached = (attached_t)(unattached))
    : attached_to_(detached) {
    }
    virtual ~attachedt() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual attached_t attach(attached_t detached) {
        attached_to_ = detached;
        return attached_to_;
    }
    virtual attached_t detach() {
        attached_t detached = attached_to_;
        attached_to_ = (attached_t)(unattached);
        return detached;
    }
    virtual attached_t attached_to() const {
        return attached_to_;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    attached_t attached_to_;
};

typedef attachedt<> attached;

} // namespace base 
} // namespace xos 

#endif // _XOS_NADIR_XOS_BASE_ATTACHED_HPP 
