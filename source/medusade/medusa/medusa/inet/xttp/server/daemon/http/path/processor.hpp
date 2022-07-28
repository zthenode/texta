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
///   File: processor.hpp
///
/// Author: $author$
///   Date: 2/22/2016
///////////////////////////////////////////////////////////////////////
#ifndef _MEDUSA_INET_XTTP_SERVER_DAEMON_HTTP_PATH_PROCESSOR_HPP
#define _MEDUSA_INET_XTTP_SERVER_DAEMON_HTTP_PATH_PROCESSOR_HPP

#include "medusa/inet/xttp/server/daemon/processor.hpp"
#include "medusa/inet/http/response.hpp"
#include "medusa/inet/http/request.hpp"

namespace medusa {
namespace inet {
namespace xttp {
namespace server {
namespace daemon {
namespace http {
namespace path {

class _EXPORT_CLASS processor;
typedef daemon::named::processor_implements processor_implements;
typedef daemon::named::processort<processor> processor_extends;
///////////////////////////////////////////////////////////////////////
///  Class: processor
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS processor
: virtual public processor_implements, public processor_extends {
public:
    typedef processor_implements Implements;
    typedef processor_extends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    processor(const wchar_t* name): Extends(name) {
        add(this);
    }
    processor(const char_t* name): Extends(name) {
        add(this);
    }
    virtual ~processor() {
        remove(this);
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual status_t operator()
    (signaler_t& restart, signaler_t& stop, response_t& rs, const request_t& rq) {
        status_t status = processing_none;
        request_t::line_t::parameters_t& name = rq.line().parameters();
        if (!(name_.compare(name.chars()))) {
            MEDUSA_LOG_MESSAGE_DEBUG("path = \"" << name_ << "\"...");
            status = process(restart, stop, rs, rq);
            MEDUSA_LOG_MESSAGE_DEBUG("...path = \"" << name_ << "\"");
        }
        return status;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

#define MEDUSA_INET_XTTP_SERVER_DAEMON_HTTP_SERVLET_PATH "/servlet/"

namespace servlet {
typedef path::processor processor_extends;
///////////////////////////////////////////////////////////////////////
///  Class: processor
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS processor: public processor_extends {
public:
    typedef processor_extends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    processor(): Extends(MEDUSA_INET_XTTP_SERVER_DAEMON_HTTP_SERVLET_PATH) {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual status_t process
    (signaler_t& restart, signaler_t& stop, response_t& rs, const request_t& rq) {
        status_t status = processing_none;
        if (!(status != processing_none)) {
            inet::http::response::status::code::which_t code
            = inet::http::response::status::code::Bad_Request;
            rs.line().set_code(string_t().assign_unsigned(code).chars());
            rs.combine();
            status = processing_done;
        }
        return status;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
} // namespace servlet

} // namespace path
} // namespace http 
} // namespace daemon 
} // namespace server 
} // namespace xttp 
} // namespace inet 
} // namespace medusa 

#endif // _MEDUSA_INET_XTTP_SERVER_DAEMON_HTTP_PATH_PROCESSOR_HPP 
