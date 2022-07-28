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
///   File: attacher.hpp
///
/// Author: $author$
///   Date: 9/7/2014
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_BASE_ATTACHER_HPP
#define _XOS_NADIR_XOS_BASE_ATTACHER_HPP

#include "xos/base/attach.hpp"

namespace xos {
namespace base {

///////////////////////////////////////////////////////////////////////
///  Enum: attacher_exception
///////////////////////////////////////////////////////////////////////
enum attacher_exception {
    failed_to_attach,
    failed_to_detach
};

typedef base::implement_base attacher_implements;
///////////////////////////////////////////////////////////////////////
///  Class: attachert
///////////////////////////////////////////////////////////////////////
template
<typename TAttached = void*,
 typename TUnattached = int,
 TUnattached VUnattached = 0,
 class TImplements = attacher_implements>

class _EXPORT_CLASS attachert: virtual public TImplements {
public:
    typedef TImplements Implements;

    typedef TAttached attached_t;
    typedef TUnattached unattached_t;
    enum { unattached = VUnattached };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual attached_t attach(attached_t detached) {
        return (attached_t)(unattached);
    }
    virtual attached_t detach() {
        return (attached_t)(unattached);
    }
    virtual attached_t attached_to() const {
        return (attached_t)(unattached);
    }
};

typedef attachert<> attacher;

} // namespace base 
} // namespace xos 

#endif // _XOS_NADIR_XOS_BASE_ATTACHER_HPP 
