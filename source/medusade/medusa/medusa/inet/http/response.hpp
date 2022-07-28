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
///   File: response.hpp
///
/// Author: $author$
///   Date: 2/14/2016
///////////////////////////////////////////////////////////////////////
#ifndef _MEDUSA_INET_HTTP_RESPONSE_HPP
#define _MEDUSA_INET_HTTP_RESPONSE_HPP

#include "medusa/inet/xttp/response/message.hpp"
#include "medusa/inet/xttp/response/status/line.hpp"
#include "medusa/inet/xttp/response/status/code.hpp"
#include "medusa/inet/xttp/response/status/reason.hpp"
#include "medusa/inet/http/version.hpp"

namespace medusa {
namespace inet {
namespace http {
namespace response {

namespace status {

typedef xttp::response::status::code_implements code_implements;
typedef xttp::response::status::code code_extends;
///////////////////////////////////////////////////////////////////////
///  Class: codet
///////////////////////////////////////////////////////////////////////
template
<class TImplements = code_implements,
 class TExtends = code_extends>

class _EXPORT_CLASS codet: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    typedef int which_t;
    enum {
        none = 0,

        Informational = 100,
        Continue = Informational,
        Switching_Protocols = 101,
        Processing = 102,

        Success = 200,
        OK = Success,
        Created = 201,
        Accepted = 202,
        Non_Authoritative_Information = 203,
        No_Content = 204,
        Reset_Content = 205,
        Partial_Content = 206,
        Multi_Status = 207,
        Already_Reported = 208,
        IM_Used = 226,

        Redirection = 300,
        Multiple_Choices = Redirection,
        Moved_Permanently = 301,
        Found = 302,
        See_Other = 303,
        Not_Modified = 304,
        Use_Proxy = 305,
        Switch_Proxy = 306,
        Temporary_Redirect = 307,
        Permanent_Redirect = 308,

        Client_Error = 400,
        Bad_Request = Client_Error,
        Unauthorized = 401,
        Payment_Required = 402,
        Forbidden = 403,
        Not_Found = 404,
        Method_Not_Allowed = 405,
        Not_Acceptable = 406,
        Proxy_Authentication_Required = 407,
        Request_Timeout = 408,
        Conflict = 409,
        Gone = 410,
        Length_Required = 411,
        Precondition_Failed = 412,
        Payload_Too_Large = 413,
        URI_Too_Long = 414,
        Unsupported_Media_Type = 415,
        Range_Not_Satisfiable = 416,
        Expectation_Failed = 417,
        Im_a_teapot = 418,
        Misdirected_Request = 421,
        Unprocessable_Entity = 422,
        Locked = 423,
        Failed_Dependency = 424,
        Upgrade_Required = 426,
        Precondition_Required = 428,
        Too_Many_Requests = 429,
        Request_Header_Fields_Too_Large = 431,
        Unavailable_For_Legal_Reasons = 451,

        Server_Error = 500,
        Internal_Server_Error = Server_Error,
        Not_Implemented = 501,
        Bad_Gateway = 502,
        Service_Unavailable = 503,
        Gateway_Timeout = 504,
        HTTP_Version_Not_Supported = 505,
        Variant_Also_Negotiates = 506,
        Insufficient_Storage = 507,
        Loop_Detected = 508,
        Not_Extended = 510,
        Network_Authentication_Required = 511,

        extension, first = (none + 1), last = (extension - 1),
        count = ((last - first) + 1)
    };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    codet(which_t which): which_(which) {
        string_t name;
        this->assign(name_of(name, which));
    }
    codet(const codet& copy)
    : Extends(copy), which_(copy.which_) {
    }
    codet(): which_(none) {
    }
    virtual ~codet() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    static const char_t* name_of(string_t& name, which_t which) {
        name.assign_unsigned(which);
        return name.chars();
    }
    static which_t of_name(const char_t* name) {
        if ((name)) {
            string_t s(name);
            return s.to_unsigned();
        }
        return none;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    which_t which_;
};
typedef codet<> code;

typedef xttp::response::status::reason_implements reason_implements;
typedef xttp::response::status::reason reason_extends;
///////////////////////////////////////////////////////////////////////
///  Class: reasont
///////////////////////////////////////////////////////////////////////
template
<class TImplements = reason_implements, class TExtends = reason_extends>

class _EXPORT_CLASS reasont: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    reasont(const char_t* chars, size_t length): Extends(chars, length) {
    }
    reasont(const char_t* chars): Extends(chars) {
    }
    reasont(const reasont& copy): Extends(copy) {
    }
    reasont() {
    }
    virtual ~reasont() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef reasont<> reason;

typedef xttp::response::status::line_implements line_implements;
typedef xttp::response::status::line line_extends;
///////////////////////////////////////////////////////////////////////
///  Class: linet
///////////////////////////////////////////////////////////////////////
template
<class TImplements = line_implements, class TExtends = line_extends>

class _EXPORT_CLASS linet: virtual public TImplements,public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef status::code code_t;
    typedef status::reason reason_t;
    typedef http::version version_t;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    linet(const code_t& code, const reason_t& reason)
    : Extends(version_t(), code, reason) {
    }
    linet(const code_t& code)
    : Extends(version_t(), code) {
    }
    linet(const linet& copy)
    : Extends(copy) {
    }
    linet() {
    }
    virtual ~linet() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef linet<> line;

} // namespace status

typedef xttp::response::message_implements message_implements;
typedef xttp::response::message message_extends;
///////////////////////////////////////////////////////////////////////
///  Class: messaget
///////////////////////////////////////////////////////////////////////
template
<class TImplements = message_implements, class TExtends = message_extends>

class _EXPORT_CLASS messaget: virtual public TImplements,public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef status::line line_t;
    typedef xttp::message::header::fields headers_t;
    typedef xttp::message::body::content body_t;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    messaget
    (const line_t& line, const headers_t& headers, const body_t& body)
    : Extends(line, headers, body) {
    }
    messaget
    (const line_t& line, const headers_t& headers)
    : Extends(line, headers) {
    }
    messaget
    (const line_t& line, const body_t& body)
    : Extends(line, body) {
    }
    messaget(const line_t& line): Extends(line) {
    }
    messaget(const messaget& copy): Extends(copy) {
    }
    messaget() {
    }
    virtual ~messaget() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef messaget<> message;

} // namespace response
} // namespace http 
} // namespace inet 
} // namespace medusa 

#endif // _MEDUSA_INET_HTTP_RESPONSE_HPP 
