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
///   File: processors.hpp
///
/// Author: $author$
///   Date: 2/20/2016
///////////////////////////////////////////////////////////////////////
#ifndef _MEDUSA_INET_XTTP_SERVER_DAEMON_HELLO_PROCESSORS_HPP
#define _MEDUSA_INET_XTTP_SERVER_DAEMON_HELLO_PROCESSORS_HPP

#include "medusa/inet/xttp/server/daemon/processors.hpp"
#include "xos/app/console/hello/base.hpp"

namespace medusa {
namespace inet {
namespace xttp {
namespace server {
namespace daemon {
namespace hello {

typedef processors::processor::Implements processor_implements;
typedef processors::processor processor_extends;
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
    processor(const char_t* message): Extends(message) {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual status_t operator()
    (signaler_t& restart, signaler_t& stop, response_t& rs, const request_t& rq) {
        status_t status = processing_none;
        request_t::line_t::method_t& method = rq.line().method();
        if (!(protocol_.compare(method.chars()))) {
            MEDUSA_LOG_MESSAGE_DEBUG("message = \"" << protocol_ << "\"...");
            rs.line().set_code(protocol_.chars());
            rs.combine();
            status = process(restart, stop, rs, rq);
            MEDUSA_LOG_MESSAGE_DEBUG("...message = \"" << protocol_ << "\"");
        }
        return status;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

namespace hello {
typedef daemon::hello::processor_implements processor_implements;
typedef daemon::hello::processor processor_extends;
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
    processor(): Extends(XOS_APP_CONSOLE_HELLO_HELLO_MESSAGE) {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual status_t process
    (signaler_t& restart, signaler_t& stop, response_t& rs, const request_t& rq) {
        status_t status = processing_done;
        restart();
        stop();
        return status;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
} // namespace hello

namespace bye {
typedef daemon::hello::processor_implements processor_implements;
typedef daemon::hello::processor processor_extends;
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
    processor(): Extends(XOS_APP_CONSOLE_HELLO_BYE_MESSAGE) {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual status_t process
    (signaler_t& restart, signaler_t& stop, response_t& rs, const request_t& rq) {
        status_t status = processing_done;
        stop();
        return status;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
} // namespace bye

} // namespace hello
} // namespace daemon 
} // namespace server 
} // namespace xttp 
} // namespace inet 
} // namespace medusa 

#endif // _MEDUSA_INET_XTTP_SERVER_DAEMON_HELLO_PROCESSORS_HPP 
