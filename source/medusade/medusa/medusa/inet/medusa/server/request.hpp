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
///   File: request.hpp
///
/// Author: $author$
///   Date: 11/24/2014
///////////////////////////////////////////////////////////////////////
#ifndef _MEDUSA_INET_MEDUSA_SERVER_REQUEST_HPP
#define _MEDUSA_INET_MEDUSA_SERVER_REQUEST_HPP

#include "medusa/inet/medusa/server/protocol.hpp"
#include "medusa/inet/xttp/request/message.hpp"
#include "medusa/base/base.hpp"

#define MEDUSA_SERVER_REQUEST_METHOD_RESTART "RESTART"
#define MEDUSA_SERVER_REQUEST_METHOD_START "START"
#define MEDUSA_SERVER_REQUEST_METHOD_STOP "STOP"

namespace medusa {
namespace inet {
namespace medusa {
namespace server {

namespace request {
typedef xttp::request::message_implements message_implements;
typedef xttp::request::message message_extends;
///////////////////////////////////////////////////////////////////////
///  Class: message
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS message
: virtual protected message_implements, public message_extends {
public:
    typedef message_implements Implements;
    typedef message_extends Extends;

    typedef Extends::line_t line_extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    class _EXPORT_CLASS line_t: public line_extends {
    public:
        line_t(const char_t* method, const char_t* parameters)
        : line_extends(method, parameters, protocol::identifier()) {
        }
        line_t(const char_t* method)
        : line_extends(method, protocol::identifier()) {
        }
        line_t(const method_t& method, const parameters_t& parameters)
        : line_extends(method, parameters, protocol::identifier()) {
        }
        line_t(const method_t& method)
        : line_extends(method, protocol::identifier()) {
        }
        line_t(const line_t& copy)
        : line_extends(copy) {
        }
    };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    message(const line_t& line): Extends(line) {
    }
    virtual ~message() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
} // namespace request

namespace restart {
typedef server::request::message request_extends;
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS request: public request_extends {
public:
    typedef request_extends::line_t line_extends;
    ///////////////////////////////////////////////////////////////////////
    class _EXPORT_CLASS line_t: public line_extends {
    public:
        line_t(): line_extends
        (MEDUSA_SERVER_REQUEST_METHOD_RESTART) {}
    };
    ///////////////////////////////////////////////////////////////////////
    request(): request_extends(line_t()) {}
};
} // namespace restart

namespace start {
typedef server::request::message request_extends;
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS request: public request_extends {
public:
    typedef request_extends::line_t line_extends;
    ///////////////////////////////////////////////////////////////////////
    class _EXPORT_CLASS line_t: public line_extends {
    public:
        line_t(): line_extends
        (MEDUSA_SERVER_REQUEST_METHOD_START) {}
    };
    ///////////////////////////////////////////////////////////////////////
    request(): request_extends(line_t()) {}
};
} // namespace start

namespace stop {
typedef server::request::message request_extends;
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS request: public request_extends {
public:
    typedef request_extends::line_t line_extends;
    ///////////////////////////////////////////////////////////////////////
    class _EXPORT_CLASS line_t: public line_extends {
    public:
        line_t(): line_extends
        (MEDUSA_SERVER_REQUEST_METHOD_STOP) {}
    };
    ///////////////////////////////////////////////////////////////////////
    request(): request_extends(line_t()) {}
};
} // namespace stop

} // namespace server
} // namespace medusa 
} // namespace inet 
} // namespace medusa 

#endif // _MEDUSA_INET_MEDUSA_SERVER_REQUEST_HPP 
