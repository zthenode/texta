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
///   File: tcp_connections.hpp
///
/// Author: $author$
///   Date: 12/12/2014
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_APP_CONSOLE_HELLO_TCP_CONNECTIONS_HPP
#define _XOS_NADIR_XOS_APP_CONSOLE_HELLO_TCP_CONNECTIONS_HPP

#include "xos/app/console/hello/base.hpp"
#include "xos/network/os/socket.hpp"
#include "xos/network/ip/v6/tcp/transport.hpp"
#include "xos/network/ip/v6/endpoint.hpp"
#include "xos/network/ip/v4/tcp/transport.hpp"
#include "xos/network/ip/v4/endpoint.hpp"
#include "xos/mt/os/semaphore.hpp"
#include "xos/mt/os/mutex.hpp"
#include "xos/mt/lock.hpp"

#include <queue>

namespace xos {
namespace app {
namespace console {
namespace hello {

///////////////////////////////////////////////////////////////////////
///  Class: tcp_connections
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS tcp_connections {
public:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    tcp_connections(): cleared_(false) {
    }
    virtual ~tcp_connections() {
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
            XOS_LOG_MESSAGE_DEBUG("queued socket...");
            qed.set_is_open(s.is_open());
            s.set_is_open(false);
            signal_.release();
            return true;
        } else {
            XOS_LOG_MESSAGE_ERROR("...queue empty");
        }
        return false;
    }
    virtual bool dequeue(network::os::socket& s) {
        XOS_LOG_MESSAGE_DEBUG("wait signal...");
        if ((signal_.wait())) {
            mt::lock l(lock_);
            if (0 < (queue_.size())) {
                s = queue_.front();
                s.set_is_open(queue_.front().is_open());
                queue_.front().set_is_open(false);
                queue_.pop();
                XOS_LOG_MESSAGE_DEBUG("...dequeued socket");
                return true;
            } else {
                XOS_LOG_MESSAGE_DEBUG("...queue empty");
                if ((cleared_)) {
                    signal_.release();
                }
            }
        } else {
            XOS_LOG_MESSAGE_ERROR("...failed on wait signal");
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

} // namespace hello
} // namespace console 
} // namespace app 
} // namespace xos 

#endif // _XOS_NADIR_XOS_APP_CONSOLE_HELLO_TCP_CONNECTIONS_HPP 
