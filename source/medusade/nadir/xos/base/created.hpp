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
///   File: created.hpp
///
/// Author: $author$
///   Date: 9/20/2014
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_BASE_CREATED_HPP
#define _XOS_NADIR_XOS_BASE_CREATED_HPP

#include "xos/base/creator.hpp"
#include "xos/base/attached.hpp"

namespace xos {
namespace base {

typedef creator created_base_implements;
typedef base created_base_extends;
///////////////////////////////////////////////////////////////////////
///  Class: created_baset
///////////////////////////////////////////////////////////////////////
template
<class TImplements = created_base_implements, 
 class TExtends = created_base_extends>

class _EXPORT_CLASS created_baset: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    created_baset(bool is_created): is_created_(is_created) {
    }
    created_baset(): is_created_(false) {
    }
    virtual ~created_baset() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool set_is_created(bool to = true) {
        is_created_ = to;
        return is_created_;
    }
    virtual bool is_created() const {
        return is_created_;
    }
    virtual bool is_destroyed() const {
        return !is_created_;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    bool is_created_;
};

typedef creator created_implements;
typedef base created_extends;
///////////////////////////////////////////////////////////////////////
///  Class: createdt
///////////////////////////////////////////////////////////////////////
template
<typename TAttached = void*,
 typename TUnattached = int,
 TUnattached VUnattached = 0,
 class TImplements = attachert
 <TAttached, TUnattached, VUnattached, created_implements>,
 class TExtends = attachedt
 <TAttached, TUnattached, VUnattached, TImplements, created_extends> >

class _EXPORT_CLASS createdt: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef TAttached attached_t;
    typedef TUnattached unattached_t;
    enum { unattached = VUnattached };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    createdt
    (attached_t detached = (attached_t)(unattached), bool is_created = false)
    : Extends(detached), is_created_(is_created) {
    }
    virtual ~createdt() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool create() {
        attached_t detached = (attached_t)(unattached);
        if (((attached_t)(unattached) != (detached = this->create_attached()))) {
            this->set_is_created();
            return true;
        }
        return false;
    }
    virtual bool destroy() {
        attached_t detached = (attached_t)(unattached);
        this->set_is_created(false);
        if (((attached_t)(unattached) != (detached = this->detach()))) {
            if ((this->destroy_detached(detached))) {
                return true;
            }
        } else {
            return true;
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual attached_t create_attached() {
        attached_t detached = (attached_t)(unattached);
        if ((this->destroyed())) {
            if (((attached_t)(unattached) != (detached = create_detached()))) {
                this->attach(detached);
            }
        }
        return detached;
    }
    virtual attached_t create_detached() const {
        attached_t detached = (attached_t)(unattached);
        return detached;
    }
    virtual bool destroy_detached(attached_t detached) const {
        if ((attached_t)(unattached) != (detached)) {
            return true;
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool set_is_created(bool to = true) {
        is_created_ = to;
        return is_created_;
    }
    virtual bool is_created() const {
        return is_created_;
    }
    virtual bool is_destroyed() const {
        return !is_created_;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual attached_t attach_created(attached_t detached, bool is_created = true) {
        attached_t attached = this->attach(detached);
        this->set_is_created(is_created);
        return attached;
    }
    virtual attached_t detach_created(bool& is_created) {
        attached_t detached = Extends::detach();
        is_created = this->is_created();
        this->set_is_created(false);
        return detached;
    }
    virtual attached_t detach() {
        attached_t detached = Extends::detach();
        this->set_is_created(false);
        return detached;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    bool is_created_;
};
typedef createdt<> created;

} // namespace base 
} // namespace xos 

#endif // _XOS_NADIR_XOS_BASE_CREATED_HPP 
