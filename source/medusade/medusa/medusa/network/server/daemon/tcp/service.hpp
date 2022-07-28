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
///   File: service.hpp
///
/// Author: $author$
///   Date: 2/14/2016
///////////////////////////////////////////////////////////////////////
#ifndef _MEDUSA_NETWORK_SERVER_DAEMON_TCP_SERVICE_HPP
#define _MEDUSA_NETWORK_SERVER_DAEMON_TCP_SERVICE_HPP

#include "medusa/network/server/daemon/tcp/connections.hpp"
#include "medusa/network/server/daemon/tcp/processor.hpp"
#include "medusa/inet/xttp/request/reader.hpp"
#include "medusa/inet/http/processor.hpp"
#include "medusa/io/socket/reader.hpp"

namespace medusa {
namespace network {
namespace server {
namespace daemon {
namespace tcp {

typedef implement_base service_implements;
typedef base service_extends;
///////////////////////////////////////////////////////////////////////
///  Class: servicet
///////////////////////////////////////////////////////////////////////
template
<class TImplements = service_implements, class TExtends = service_extends>

class _EXPORT_CLASS servicet: virtual public TImplements,public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    servicet
    (inet::xttp::processor& xttp,
     const network::socket& s, const network::endpoint& ep,
     int optind, int argc, const char_t*const* argv, const char_t*const* env)
    : xttp_(xttp), s_(s), ep_(ep),
      optind_(optind), argc_(argc), argv_(argv), env_(env) {
    }
    virtual ~servicet() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void operator()
    (mt::signaler& restart, mt::signaler& stop,
     tcp::connections& cn, bool repeated = true) {
        processor p(xttp_, optind_, argc_, argv_, env_);
        processor::status_t ps;
        network::os::socket sk;
        io::socket::tcp::reader skr(sk);
        inet::xttp::request::message rq;
        inet::xttp::request::readert<inet::xttp::request::message> rqr(rq);
        do {
            XOS_LOG_MESSAGE_DEBUG("dequeue socket...");
            if ((cn.dequeue(sk))) {
                bool continued = false;
                XOS_LOG_MESSAGE_DEBUG("...dequeued socket");
                do {
                    continued = false;
                    if ((rqr.read(skr))) {
                        switch(ps = (p(restart, stop, sk, rq))) {
                        case processor::processing_done:
                            break;
                        case processor::processing_continued:
                            continued = true;
                            break;
                        default:
                            XOS_LOG_MESSAGE_ERROR("...failed to process request line = \"" << rq.line() << "\"");
                            stop();
                        }
                    }
                } while (continued);
            }
        } while (repeated);
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    inet::xttp::processor& xttp_;
    const network::socket& s_;
    const network::endpoint& ep_;
    int optind_, argc_;
    const char_t *const* argv_, *const* env_;
};
typedef servicet<> service;

} // namespace tcp 
} // namespace daemon 
} // namespace server 
} // namespace network 
} // namespace medusa 

#endif // _MEDUSA_NETWORK_SERVER_DAEMON_TCP_SERVICE_HPP 
