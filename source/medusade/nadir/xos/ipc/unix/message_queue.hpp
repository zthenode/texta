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
///   File: message_queue.hpp
///
/// Author: $author$
///   Date: 8/13/2016
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_IPC_UNIX_MESSAGE_QUEUE_HPP
#define _XOS_NADIR_XOS_IPC_UNIX_MESSAGE_QUEUE_HPP

#include "xos/ipc/unix/key.hpp"
#include "xos/ipc/message_queue.hpp"
#include "xos/base/opened.hpp"
#include "xos/base/opener.hpp"
#include "xos/base/attached.hpp"
#include "xos/base/attacher.hpp"
#include <sys/ipc.h>
#include <sys/msg.h>

namespace xos {
namespace ipc {
namespace unix {

typedef ipc::message_queue message_queue_implements;
typedef base::attachedt
<message_queue_attached_t, message_queue_unattached_t, message_queue_unattached,
 message_queue_implements, base::base> message_queue_attached;
typedef base::openedt
<message_queue_attached_t, message_queue_unattached_t, message_queue_unattached,
 message_queue_implements, message_queue_attached> message_queue_extends;
///////////////////////////////////////////////////////////////////////
///  Class: message_queuet
///////////////////////////////////////////////////////////////////////
template
<class TImplements = message_queue_implements,
 class TExtends = message_queue_extends>

class _EXPORT_CLASS message_queuet
: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef typename TImplements::attached_t attached_t;
    typedef typename TImplements::unattached_t unattached_t;
    enum { unattached = TImplements::unattached };

    typedef typename TImplements::mode_t mode_t;
    enum {
        mode_create    = TImplements::mode_create,
        mode_exclusive = TImplements::mode_exclusive,
        mode_nowait    = TImplements::mode_nowait
    };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    message_queuet
    (attached_t detached = unattached, bool is_open = false)
    : Extends(detached, is_open),
      mode_(0) {
    }
    virtual ~message_queuet() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool open(const char *name) {
        if ((this->open(name, 0))) {
            return true;
        }
        return false;
    }
    virtual bool open(const char *name, mode_t mode) {
        attached_t detached = unattached;
        if (unattached != (detached = open_attached(name, mode))) {
            this->set_is_open();
            return true;
        }
        return false;
    }
    virtual bool close() {
        attached_t detached = unattached;
        if (unattached != (detached = this->detach())) {
            mode_t mode = mode_;
            mode_ = 0;
            if ((close_detached(detached, mode))) {
                return true;
            }
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual attached_t open_attached(const char *name, mode_t mode) {
        attached_t detached = unattached;
        if (unattached != (detached = open_detached(name, mode))) {
            this->attach(detached);
            mode_ = mode;
            return detached;
        }
        return unattached;
    }
    virtual attached_t open_detached(const char *name, mode_t mode) {
        if ((name) && (name[0])) {
            key_t msgkey = ipc::unix::key::unattached;
            if ((msgkey = ipc::unix::key().create_detached(name))) {
                attached_t detached = unattached;
                int msgflg
                    = ((mode & mode_create)?(IPC_CREAT):(0))
                    | ((mode & mode_exclusive)?(IPC_EXCL):(0))
                    | ((mode & mode_nowait)?(IPC_NOWAIT):(0))
                    | S_IRWXU | S_IRWXG | S_IRWXO;

                XOS_LOG_MESSAGE_DEBUG("msgget(msgkey = " << msgkey << ", msgflg = " << msgflg << ")...");
                if (unattached != (detached = msgget(msgkey, msgflg))) {
                    XOS_LOG_MESSAGE_DEBUG("..." << detached << " = msgget(msgkey = " << msgkey << ", msgflg = " << msgflg << ")");
                    return detached;
                } else {
                    XOS_LOG_MESSAGE_ERROR("...failed " << detached << " = msgget(msgkey = " << msgkey << ", msgflg = " << msgflg << "");
                }
                ipc::unix::key().destroy_detached(msgkey);
            }
        }
        return unattached;
    }
    virtual bool close_detached(attached_t detached, mode_t mode = 0) const {
        attached_t attached = unattached;
        if (attached != (detached)) {
            int err = 0;
            struct msqid_ds ds;

            XOS_LOG_MESSAGE_DEBUG("msgctl(detached = " << detached << ", IPC_STAT, &ds = " << base::pointer_to_string(&ds) << ")...");
            if (!(err = msgctl(detached, IPC_STAT, &ds))) {
                XOS_LOG_MESSAGE_DEBUG("...mode = " << mode << " on msgctl(detached = " << detached << ", IPC_STAT, &ds = " << base::pointer_to_string(&ds) << ")");

                if ((mode & mode_create)) {
                    XOS_LOG_MESSAGE_DEBUG("msgctl(detached = " << detached << ", IPC_RMID, NULL)...");
                    if (!(err = msgctl(detached, IPC_RMID, NULL))) {
                        XOS_LOG_MESSAGE_DEBUG("...msgctl(detached = " << detached << ", IPC_RMID, NULL)");
                        return true;
                    } else {
                        XOS_LOG_MESSAGE_ERROR("...failed on " << err << " = msgctl(detached = " << detached << ", IPC_RMID, NULL)");
                    }
                } else {
                    return true;
                }
            } else {
                XOS_LOG_MESSAGE_ERROR("...failed on " << err << " = msgctl(detached = " << detached << ", IPC_STAT, &ds = " << base::pointer_to_string(&ds) << ")");
            }
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t send(const void* buffer, size_t length) {
        attached_t detached = unattached;
        if ((buffer) && (length)
            && (unattached != (detached = this->attached_to()))) {
            int err = 0, flags = 0;

            XOS_LOG_MESSAGE_DEBUG("msgsnd(detached = " << detached << ", buffer = " << base::pointer_to_string(buffer) << ", length = " << length << ", flags = " << flags << ")...");
            if (!(err = msgsnd(detached, buffer, length, flags))) {
                XOS_LOG_MESSAGE_DEBUG("...msgsnd(detached = " << detached << ", buffer = " << base::pointer_to_string(buffer) << ", length = " << length << ", flags = " << flags << ")");
                return length;
            } else {
                XOS_LOG_MESSAGE_ERROR("...failed " << err << " on msgsnd(detached = " << detached << ", buffer = " << base::pointer_to_string(buffer) << ", length = " << length << ", flags = " << flags << ")");
            }
        }
        return 0;
    }
    virtual ssize_t receive(void* buffer, size_t length) {
        attached_t detached = unattached;
        if ((buffer) && (length)
            && (unattached != (detached = this->attached_to()))) {
            int count = 0, flags = 0;
            long type = 0;

            XOS_LOG_MESSAGE_DEBUG("msgrcv(detached = " << detached << ", buffer = " << base::pointer_to_string(buffer) << ", length = " << length << ", type = " << type << ", flags = " << flags << ")...");
            if (0 < (count = msgrcv(detached, buffer, length, type, flags))) {
                XOS_LOG_MESSAGE_DEBUG("..." << count << " = msgrcv(detached = " << detached << ", buffer = " << base::pointer_to_string(buffer) << ", length = " << length << ", type = " << type << ", flags = " << flags << ")");
                return length;
            } else {
                XOS_LOG_MESSAGE_ERROR("...failed on " << count << " = msgrcv(detached = " << detached << ", buffer = " << base::pointer_to_string(buffer) << ", type = " << type << ", length = " << length << ", flags = " << flags << ")");
            }
        }
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    mode_t mode_;
};
typedef message_queuet<> message_queue;

} // namespace unix 
} // namespace ipc 
} // namespace xos 

#endif // _XOS_NADIR_XOS_IPC_UNIX_MESSAGE_QUEUE_HPP 
