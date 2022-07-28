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
///   File: processor.hpp
///
/// Author: $author$
///   Date: 2/9/2015
///////////////////////////////////////////////////////////////////////
#ifndef _MEDUSA_NETWORK_SERVER_DAEMON_TCP_PROCESSOR_HPP
#define _MEDUSA_NETWORK_SERVER_DAEMON_TCP_PROCESSOR_HPP

#include "medusa/network/server/daemon/tcp/connections.hpp"
#include "medusa/inet/xttp/processor.hpp"
#include "medusa/inet/xttp/response/message.hpp"
#include "medusa/inet/xttp/request/message.hpp"
#include "medusa/io/socket/writer.hpp"
#include "medusa/io/socket/reader.hpp"
#include "medusa/base/base.hpp"
//#include "xos/app/console/hello/base.hpp"

namespace medusa {
namespace network {
namespace server {
namespace daemon {
namespace tcp {

typedef implement_base processor_implements;
typedef base processor_extends;
///////////////////////////////////////////////////////////////////////
///  Class: processor
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS processor
: virtual public processor_implements, public processor_extends {
public:
    typedef processor_implements Implements;
    typedef processor_extends Extends;

    typedef inet::xttp::processor xttp_processor_t;
    typedef inet::xttp::processor::status status_t;
    enum {
        processing_none = inet::xttp::processor::processing_none,
        processing_done = inet::xttp::processor::processing_done,
        processing_failed = inet::xttp::processor::processing_failed,
        processing_continued = inet::xttp::processor::processing_continued
    };
    typedef inet::xttp::response::message response_t;
    typedef inet::xttp::request::message request_t;
    typedef inet::xttp::request::message::line_t line_t;
    typedef inet::xttp::request::message::line_t::method_t method_t;
    typedef network::socket socket_t;
    typedef io::socket::tcp::writer socket_writer_t;
    typedef mt::signaler signaler_t;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    processor
    (xttp_processor_t& xttp,
     int optind, int argc, const char_t*const* argv, const char_t*const* env)
    : xttp_(xttp),
      optind_(optind), argc_(argc), argv_(argv), env_(env) {
    }
    virtual ~processor() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual status_t operator()
    (signaler_t& restart, signaler_t& stop, socket_t& sk, const request_t& rq) {
        status_t status = processing_none;
        socket_writer_t skw(sk);
        response_t rs;

        if (!(processing_done != (status = xttp_(restart, stop, rs, rq)))) {
            MEDUSA_LOG_MESSAGE_DEBUG("...response = \"" << rs << "\"");
            skw.write(rs.chars(), rs.length());
        } else {
            if (!(processing_none != status)) {
                MEDUSA_LOG_MESSAGE_DEBUG("...failed to process line = \"" << rq.line() << "\"");
                rs.set_line(rq.line().chars());
                MEDUSA_LOG_MESSAGE_DEBUG("...response = \"" << rs << "\"");
                skw.write(rs.chars(), rs.length());
                status = processing_done;
            }
        }
        return status;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    xttp_processor_t& xttp_;
    int optind_, argc_;
    const char_t *const* argv_, *const* env_;
};

} // namespace tcp 
} // namespace daemon 
} // namespace server 
} // namespace network 
} // namespace medusa 

#endif // _MEDUSA_NETWORK_SERVER_DAEMON_TCP_PROCESSOR_HPP 
