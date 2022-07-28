///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2015 $organization$
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
///   File: connections.hpp
///
/// Author: $author$
///   Date: 2/8/2015
///////////////////////////////////////////////////////////////////////
#ifndef _MEDUSA_NETWORK_SERVER_DAEMON_TCP_CONNECTIONS_HPP
#define _MEDUSA_NETWORK_SERVER_DAEMON_TCP_CONNECTIONS_HPP

#include "medusa/base/base.hpp"
#include "medusa/network/network.hpp"
#include "medusa/mt/mt.hpp"

#include <queue>

namespace medusa {
namespace network {
namespace server {
namespace daemon {
namespace tcp {

typedef implement_base connections_implements;
typedef base connections_extends;
///////////////////////////////////////////////////////////////////////
///  Class: connections
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS connections
: virtual public connections_implements, public connections_extends {
public:
    typedef connections_implements Implements;
    typedef connections_extends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    connections(): cleared_(false) {
    }
    virtual ~connections() {
        clear();
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void clear() {
        mt::lock l(lock_);
        while (0 < (queue_.size())) {
            network::os::socket s = queue_.front();
            s.closed();
            queue_.pop();
        }
        cleared_ = true;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool queue(network::os::socket& s) {
        mt::lock l(lock_);
        queue_.push(s);
        if (0 < (queue_.size())) {
            network::os::socket& qed = queue_.back();
            MEDUSA_LOG_MESSAGE_DEBUG("queued socket...");
            qed.set_is_open(s.is_open());
            s.set_is_open(false);
            signal_.release();
            return true;
        } else {
            MEDUSA_LOG_MESSAGE_ERROR("...queue empty");
        }
        return false;
    }
    virtual bool dequeue(network::os::socket& s) {
        MEDUSA_LOG_MESSAGE_DEBUG("wait signal...");
        if ((signal_.wait())) {
            mt::lock l(lock_);
            if (0 < (queue_.size())) {
                s = queue_.front();
                s.set_is_open(queue_.front().is_open());
                queue_.front().set_is_open(false);
                queue_.pop();
                MEDUSA_LOG_MESSAGE_DEBUG("...dequeued socket");
                return true;
            } else {
                MEDUSA_LOG_MESSAGE_DEBUG("...queue empty");
                if ((cleared_)) {
                    signal_.release();
                }
            }
        } else {
            MEDUSA_LOG_MESSAGE_ERROR("...failed on wait signal");
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    bool cleared_;
    mt::os::mutex lock_;
    mt::os::semaphore signal_;
    std::queue<network::os::socket> queue_;
};

} // namespace tcp 
} // namespace daemon 
} // namespace server 
} // namespace network 
} // namespace medusa 

#endif // _MEDUSA_NETWORK_SERVER_DAEMON_TCP_CONNECTIONS_HPP 
