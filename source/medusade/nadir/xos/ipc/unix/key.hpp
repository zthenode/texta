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
///   File: key.hpp
///
/// Author: $author$
///   Date: 8/15/2016
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_IPC_UNIX_KEY_HPP
#define _XOS_NADIR_XOS_IPC_UNIX_KEY_HPP

#include "xos/ipc/key.hpp"
#include "xos/io/logger.hpp"
#include "xos/base/to_string.hpp"
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/sem.h>
#include <sys/shm.h>

namespace xos {
namespace ipc {
namespace unix {

typedef ipc::key implements_key;
typedef implements_key key_implements;
typedef base::attachedt
<key_attached_t, key_unattached_t, key_unattached,
 key_implements, base::base> key_attached;
typedef base::createdt
<key_attached_t, key_unattached_t, key_unattached,
 key_implements, key_attached> key_extends;
///////////////////////////////////////////////////////////////////////
///  Class: keyt
///////////////////////////////////////////////////////////////////////
template
<class TImplements = key_implements, class TExtends = key_extends>

class _EXPORT_CLASS keyt: virtual public TImplements,public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef typename TImplements::attached_t attached_t;
    typedef typename TImplements::unattached_t unattached_t;
    enum { unattached = TImplements::unattached };

    typedef typename TImplements::index_t index_t;
    enum {
        index_first = TImplements::index_first,
        index_last  = TImplements::index_last
    };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    keyt
    (attached_t detached = unattached, bool is_created = false)
    : Extends(detached, is_created) {
    }
    keyt(const keyt& copy): Extends(copy.attached_to()) {
    }
    virtual ~keyt() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool create
    (const char* name, index_t index = index_first) {
        attached_t detached = unattached;
        if (unattached != (detached = create_attached(name, index))) {
            this->set_is_created();
            return true;
        }
        return false;
    }
    virtual bool destroy() {
        attached_t detached = unattached;
        if (unattached != (detached = this->detach())) {
            return destroy_detached(detached);
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual attached_t create_attached
    (const char* name, index_t index = index_first) {
        attached_t detached = unattached;
        if (unattached != (detached = create_detached(name, index))) {
            this->attach(detached);
            return detached;
        }
        return unattached;
    }
    virtual attached_t create_detached
    (const char* name, index_t index = index_first) const {
        attached_t detached = unattached;
        if ((name) && (name[0]) && (index)) {
            XOS_LOG_MESSAGE_DEBUG("ftok(name = \"" << name << "\", index = " << index << ")...");
            if (unattached != (detached = (attached_t)ftok(name, index))) {
                XOS_LOG_MESSAGE_DEBUG("..." << detached << " = ftok(name = \"" << name << "\", index = " << index << ")");
                return detached;
            } else {
                XOS_LOG_ERROR("...failed " << detached << " = ftok(name = \"" << name << "\", index = " << index << ")");
            }
        }
        return unattached;
    }
    virtual bool destroy_detached(attached_t detached) {
        if (unattached != (detached)) {
            int id = 0, err = 0;
            XOS_LOG_MESSAGE_DEBUG("msgget(detached = " << detached << ", 0)...");
            if (0 <= (id = msgget(detached, 0))) {
                XOS_LOG_MESSAGE_DEBUG("..." << id << " = msgget(detached = " << detached << ", 0)");
                if (!(err = msgctl(id, IPC_RMID, NULL))) {
                    return true;
                }
            } else {
                XOS_LOG_MESSAGE_DEBUG("..." << id << " = msgget(detached = " << detached << ", 0)");
                XOS_LOG_MESSAGE_DEBUG("semget(detached = " << detached << ", 0, 0)...");
                if (0 <= (id = semget(detached, 0, 0))) {
                    if (!(err = semctl(id, 0, IPC_RMID, NULL))) {
                        return true;
                    }
                } else {
                    XOS_LOG_MESSAGE_DEBUG("..." << id << " = semget(detached = " << detached << ", 0, 0)");
                    XOS_LOG_MESSAGE_DEBUG("shmget(detached = " << detached << ", 0, 0)...");
                    if (0 <= (id = shmget(detached, 0, 0))) {
                        if (!(err = shmctl(id, IPC_RMID, NULL))) {
                            return true;
                        }
                    } else {
                        XOS_LOG_MESSAGE_DEBUG("..." << id << " = shmget(detached = " << detached << ", 0, 0)");
                    }
                }
            }
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef keyt<> key;

} // namespace unix 
} // namespace ipc 
} // namespace xos 

#endif // _XOS_NADIR_XOS_IPC_UNIX_KEY_HPP 
