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
#ifndef _XOS_NADIR_XOS_IPC_MESSAGE_QUEUE_HPP
#define _XOS_NADIR_XOS_IPC_MESSAGE_QUEUE_HPP

#include "xos/base/opener.hpp"
#include "xos/base/attacher.hpp"
#include "xos/io/logger.hpp"

namespace xos {
namespace ipc {

typedef int mode_t;
enum {
    mode_create    = (1 << 0),
    mode_exclusive = (1 << 1),
    mode_nowait    = (1 << 2)
};

typedef int message_queue_t;
typedef message_queue_t message_queue_attached_t;
typedef int message_queue_unattached_t;
enum { message_queue_unattached = -1 };

typedef base::opener message_queue_implements;
///////////////////////////////////////////////////////////////////////
///  Class: message_queuet
///////////////////////////////////////////////////////////////////////
template
<typename TAttached = message_queue_attached_t,
 typename TUnattached = message_queue_unattached_t,
 TUnattached VUnattached = message_queue_unattached,
 typename TMode = mode_t,
 TMode VModeCreate = mode_create,
 TMode VModeExclusive = mode_exclusive,
 TMode VModeNoWait = mode_nowait,
 class TImplements = message_queue_implements>

class _EXPORT_CLASS message_queuet: virtual public TImplements {
public:
    typedef TImplements Implements;

    typedef TAttached attached_t;
    typedef TUnattached unattached_t;
    enum { unattached = VUnattached };

    typedef TMode mode_t;
    enum {
        mode_create    = VModeCreate,
        mode_exclusive = VModeExclusive,
        mode_nowait    = VModeNoWait
    };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool open(const char *name) { return false; }
    virtual bool open(const char *name, mode_t mode) { return false; }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t send(const void* buffer, size_t length) { return 0; }
    virtual ssize_t receive(void* buffer, size_t length) { return 0; }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef message_queuet<> message_queue;

} // namespace ipc 
} // namespace xos 

#endif // _XOS_NADIR_XOS_IPC_MESSAGE_QUEUE_HPP 
        

