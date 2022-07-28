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
///   File: semaphore.hpp
///
/// Author: $author$
///   Date: 12/11/2014
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_MT_SEMAPHORE_HPP
#define _XOS_NADIR_XOS_MT_SEMAPHORE_HPP

#include "xos/mt/acquirer.hpp"
#include "xos/mt/waiter.hpp"
#include "xos/base/created.hpp"
#include "xos/base/creator.hpp"
#include "xos/base/attached.hpp"
#include "xos/base/attacher.hpp"

namespace xos {
namespace mt {

///////////////////////////////////////////////////////////////////////
///  Class: semaphore_implements
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS semaphore_implements
: virtual public waiter, virtual public acquirer, virtual public base::creator {
public:
};
///////////////////////////////////////////////////////////////////////
///  Class: semaphoret
///////////////////////////////////////////////////////////////////////
template <class TImplements = semaphore_implements>

class _EXPORT_CLASS semaphoret: virtual public TImplements {
public:
    typedef TImplements Implements;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool create() {
        return this->create(0);
    }
    virtual bool create(size_t initial_count) {
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool wait() {
        return this->acquire();
    }
    virtual wait_status try_wait() {
        return this->try_acquire();
    }
    virtual wait_status timed_wait(mseconds_t milliseconds) {
        return this->timed_acquire(milliseconds);
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool initially_created() const {
        return true;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef semaphoret<> semaphore;

///////////////////////////////////////////////////////////////////////
///  Class: semaphore_attachedt
///////////////////////////////////////////////////////////////////////
template
<typename TAttached,
 typename TUnattached = int, TUnattached VUnattached = 0,
 class TImplements = base::attachert
 <TAttached, TUnattached, VUnattached, semaphore>,
 class TExtends = base::attachedt
 <TAttached, TUnattached, VUnattached, TImplements, base::base> >

class _EXPORT_CLASS semaphore_attachedt: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef TAttached attached_t;
    typedef TUnattached unattached_t;
    enum { unattached = VUnattached };
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    semaphore_attachedt
    (attached_t detached = (attached_t)(unattached)): Extends(detached) {
    }
    virtual ~semaphore_attachedt() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

///////////////////////////////////////////////////////////////////////
///  Class: semaphore_createdt
///////////////////////////////////////////////////////////////////////
template
<typename TAttached,
 typename TUnattached = int, TUnattached VUnattached = 0,
 class TImplements = base::attachert
 <TAttached, TUnattached, VUnattached, semaphore>,
 class TExtends = base::createdt
 <TAttached, TUnattached, VUnattached, TImplements,
  semaphore_attachedt<TAttached, TUnattached, VUnattached, TImplements> > >
class _EXPORT_CLASS semaphore_createdt: virtual public TImplements,public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef TAttached attached_t;
    typedef TUnattached unattached_t;
    enum { unattached = VUnattached };
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    semaphore_createdt
    (attached_t detached = (attached_t)(unattached),
     bool is_created = false): Extends(detached, is_created) {
    }
    virtual ~semaphore_createdt() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

///////////////////////////////////////////////////////////////////////
///  Class: semaphore_extendt
///////////////////////////////////////////////////////////////////////
template
<typename TAttached, typename TUnattached = int, TUnattached VUnattached = 0,
 class TImplements = base::attachert
 <TAttached, TUnattached, VUnattached, semaphore>,
 class TExtends = semaphore_createdt
 <TAttached, TUnattached, VUnattached, TImplements,
  base::createdt
  <TAttached, TUnattached, VUnattached, TImplements,
   semaphore_attachedt<TAttached, TUnattached, VUnattached, TImplements> > > >

class _EXPORT_CLASS semaphore_extendt
: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef TAttached attached_t;
    typedef TUnattached unattached_t;
    enum { unattached = VUnattached };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    semaphore_extendt
    (attached_t detached = (attached_t)(unattached),
     bool is_created = false): Extends(detached, is_created) {
    }
    virtual ~semaphore_extendt() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool create() {
        return this->create(0);
    }
    virtual bool create(size_t initial_count) {
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace mt
} // namespace xos 

#endif // _XOS_NADIR_XOS_MT_SEMAPHORE_HPP 
