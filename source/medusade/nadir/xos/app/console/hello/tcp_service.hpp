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
///   File: tcp_service.hpp
///
/// Author: $author$
///   Date: 12/12/2014
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_APP_CONSOLE_HELLO_TCP_SERVICE_HPP
#define _XOS_NADIR_XOS_APP_CONSOLE_HELLO_TCP_SERVICE_HPP

#include "xos/app/console/hello/tcp_processor.hpp"
#include "xos/app/console/hello/tcp_connections.hpp"
#include "xos/app/console/hello/signaler.hpp"
#include "xos/app/console/hello/response.hpp"
#include "xos/app/console/hello/request.hpp"
#include "xos/app/console/hello/message.hpp"
#include "xos/app/console/hello/base.hpp"

namespace xos {
namespace app {
namespace console {
namespace hello {

///////////////////////////////////////////////////////////////////////
///  Class: tcp_service
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS tcp_service {
public:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    tcp_service
    (const network::socket& s, const network::endpoint& ep,
     const string_t& bye_message, const string_t& hello_message,
     int optind, int argc, const char_t*const* argv, const char_t*const* env)
    : s_(s), ep_(ep), bye_message_(bye_message), hello_message_(hello_message),
      optind_(optind), argc_(argc), argv_(argv), env_(env) {
    }
    virtual ~tcp_service() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void operator()(signaler& bye, tcp_connections& cn, bool is_repeated = true) {
        //XOS_LOG_MESSAGE_DEBUG("hello message = \"" << hello_message_ << "\"...");
        tcp_processor p(bye_message_, hello_message_, optind_, argc_, argv_, env_);
        tcp_processor::status ps;
        network::os::socket s;
        request rq;
        char chars[4096];
        //XOS_LOG_MESSAGE_DEBUG("hello message = \"" << hello_message_ << "\"...");
        do {
            XOS_LOG_MESSAGE_DEBUG("dequeue socket...");
            if ((cn.dequeue(s))) {
                bool continued = false;
                ssize_t count = 0;
                XOS_LOG_MESSAGE_DEBUG("...dequeued socket");
                do {
                    if ((rq.on_read_start())) {
                        do {
                            XOS_LOG_MESSAGE_DEBUG("recv[" << sizeof(chars) << "]...");
                            if (0 < (count = s.recv(chars, sizeof(chars), 0))) {
                                XOS_LOG_MESSAGE_DEBUG("...recv[" << count << "]");
                                if (!(rq.on_read_finish(chars, count))) {
                                    continue;
                                } else {
                                    XOS_LOG_MESSAGE_DEBUG("...read \"" << rq << "\"");
                                    switch (ps = p(s, rq)) {
                                    case tcp_processor::processing_done:
                                        if (!(bye_message_ != rq.line())) {
                                            XOS_LOG_MESSAGE_DEBUG("...Bye \"" << rq.line() << "\"");
                                            bye();
                                        }
                                        break;
                                    case tcp_processor::processing_continued:
                                        continued = true;
                                        break;
                                    }
                                }
                            } else {
                                XOS_LOG_MESSAGE_DEBUG("...failed with recv[" << count << "]");
                            }
                            break;
                        } while (0 < count);
                    }
                } while (continued);
            } else {
                XOS_LOG_MESSAGE_ERROR("...failed to dequeue socket");
            }
        } while (is_repeated);
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    const network::socket& s_;
    const network::endpoint& ep_;
    const string_t& bye_message_, & hello_message_;
    int optind_, argc_;
    const char_t *const* argv_, *const* env_;
};

} // namespace hello
} // namespace console 
} // namespace app 
} // namespace xos 

#endif // _XOS_NADIR_XOS_APP_CONSOLE_HELLO_TCP_SERVICE_HPP 
