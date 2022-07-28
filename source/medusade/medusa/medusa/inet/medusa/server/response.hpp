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
///   File: response.hpp
///
/// Author: $author$
///   Date: 11/24/2014
///////////////////////////////////////////////////////////////////////
#ifndef _MEDUSA_INET_MEDUSA_SERVER_RESPONSE_HPP
#define _MEDUSA_INET_MEDUSA_SERVER_RESPONSE_HPP

#include "medusa/inet/medusa/server/protocol.hpp"
#include "medusa/inet/xttp/response/message.hpp"
#include "medusa/base/base.hpp"

#define MEDUSA_SERVER_RESPONSE_SUCCESS_CODE "100"
#define MEDUSA_SERVER_RESPONSE_SUCCESS_REASON "Success"

#define MEDUSA_SERVER_RESPONSE_FAILED_CODE "200"
#define MEDUSA_SERVER_RESPONSE_FAILED_REASON "Failed"

namespace medusa {
namespace inet {
namespace medusa {
namespace server {

namespace response {
typedef xttp::response::message_implements message_implements;
typedef xttp::response::message message_extends;
///////////////////////////////////////////////////////////////////////
///  Class: message
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS message
: virtual public message_implements, public message_extends {
public:
    typedef message_implements Implements;
    typedef message_extends Extends;

    typedef Extends::line_t line_extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    class _EXPORT_CLASS line_t: public line_extends {
    public:
        line_t(const char_t* code, const char_t* reason)
        : line_extends(protocol::identifier(), code, reason) {
        }
        line_t(const char_t* code)
        : line_extends(protocol::identifier(), code) {
        }
        line_t(const code_t& code, const reason_t& reason)
        : line_extends(protocol::identifier(), code, reason) {
        }
        line_t(const code_t& code)
        : line_extends(protocol::identifier(), code) {
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
} // namespace response 

namespace success {
typedef server::response::message response_extends;
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS response: public response_extends {
public:
    typedef response_extends::line_t line_extends;
    ///////////////////////////////////////////////////////////////////////
    class _EXPORT_CLASS line_t: public line_extends {
    public:
        line_t(const char_t* reason): line_extends
        (MEDUSA_SERVER_RESPONSE_SUCCESS_CODE, reason) {}
        line_t(): line_extends
        (MEDUSA_SERVER_RESPONSE_SUCCESS_CODE,
         MEDUSA_SERVER_RESPONSE_SUCCESS_REASON) {}
    };
    ///////////////////////////////////////////////////////////////////////
    response(const char_t* reason): response_extends(line_t(reason)) {}
    response(): response_extends(line_t()) {}
};
} // namespace success

namespace failed {
typedef server::response::message response_extends;
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS response: public response_extends {
public:
    typedef response_extends::line_t line_extends;
    ///////////////////////////////////////////////////////////////////////
    class _EXPORT_CLASS line_t: public line_extends {
    public:
        line_t(const char_t* reason): line_extends
        (MEDUSA_SERVER_RESPONSE_FAILED_CODE, reason) {}
        line_t(): line_extends
        (MEDUSA_SERVER_RESPONSE_FAILED_CODE,
         MEDUSA_SERVER_RESPONSE_FAILED_REASON) {}
    };
    ///////////////////////////////////////////////////////////////////////
    response(const char_t* reason): response_extends(line_t(reason)) {}
    response(): response_extends(line_t()) {}
};
} // namespace failed

} // namespace server
} // namespace medusa 
} // namespace inet 
} // namespace medusa 

#endif // _MEDUSA_INET_MEDUSA_SERVER_RESPONSE_HPP 
