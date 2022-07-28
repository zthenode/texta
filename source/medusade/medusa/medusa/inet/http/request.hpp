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
///   Date: 11/25/2014
///////////////////////////////////////////////////////////////////////
#ifndef _MEDUSA_INET_HTTP_REQUEST_HPP
#define _MEDUSA_INET_HTTP_REQUEST_HPP

#include "medusa/inet/http/version.hpp"
#include "medusa/inet/xttp/request/message.hpp"
#include "medusa/inet/xttp/request/line.hpp"

#define MEDUSA_INET_HTTP_REQUEST_METHOD_NAME_GET "GET"
#define MEDUSA_INET_HTTP_REQUEST_METHOD_NAME_POST "POST"
#define MEDUSA_INET_HTTP_REQUEST_METHOD_NAME_PUT "PUT"
#define MEDUSA_INET_HTTP_REQUEST_METHOD_NAME_DELETE "DELETE"
#define MEDUSA_INET_HTTP_REQUEST_METHOD_NAME_TRACE "TRACE"
#define MEDUSA_INET_HTTP_REQUEST_METHOD_NAME_CONNECT "CONNECT"
#define MEDUSA_INET_HTTP_REQUEST_METHOD_NAME_OPTIONS "OPTIONS"
#define MEDUSA_INET_HTTP_REQUEST_METHOD_NAME_HEAD "HEAD"
#define MEDUSA_INET_HTTP_REQUEST_METHOD_NAME_PATCH "PATCH"

#define MEDUSA_INET_HTTP_REQUEST_METHOD_NAMES \
    MEDUSA_INET_HTTP_REQUEST_METHOD_NAME_GET, \
    MEDUSA_INET_HTTP_REQUEST_METHOD_NAME_POST, \
    MEDUSA_INET_HTTP_REQUEST_METHOD_NAME_PUT, \
    MEDUSA_INET_HTTP_REQUEST_METHOD_NAME_DELETE, \
    MEDUSA_INET_HTTP_REQUEST_METHOD_NAME_TRACE, \
    MEDUSA_INET_HTTP_REQUEST_METHOD_NAME_CONNECT, \
    MEDUSA_INET_HTTP_REQUEST_METHOD_NAME_OPTIONS, \
    MEDUSA_INET_HTTP_REQUEST_METHOD_NAME_HEAD, \
    MEDUSA_INET_HTTP_REQUEST_METHOD_NAME_PATCH

namespace medusa {
namespace inet {
namespace http {

namespace request {
typedef xttp::request::method_implements method_implements;
typedef xttp::request::method method_extends;
///////////////////////////////////////////////////////////////////////
///  Class: method
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS method: virtual public method_implements, public method_extends {
public:
    typedef method_implements Implements;
    typedef method_extends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    typedef int which_t;
    enum {
        none = 0,
        GET, POST, PUT, DELETE, TRACE, CONNECT, OPTIONS, HEAD, PATCH,
        extension, first = (none + 1), last = (extension - 1),
        count = ((last - first) + 1)
    };
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    method(const char_t* name, size_t length)
    : Extends(name, length), which_(of_name(this->chars())) {
    }
    method(const char_t* name)
    : Extends(name), which_(of_name(this->chars())) {
    }
    method(which_t which)
    : Extends(name_of(which)), which_(which) {
    }
    method(const method& copy)
    : Extends(copy), which_(copy.which_) {
    }
    method() {
    }
    virtual ~method() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual which_t to_which() const {
        return of_name(this->chars());
    }
    virtual which_t which() const {
        return which_;
    }
    virtual operator which_t() const {
        return which_;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    static const char_t* name_of(which_t which) {
        static const char_t* of[count] = {
            MEDUSA_INET_HTTP_REQUEST_METHOD_NAMES
        };
        if ((which >= first) && (which <= last))
            return of[which - first];
        return 0;
    }
    static which_t of_name(const char_t* name) {
        if ((name)) {
            const char_t* to_name;
            for (which_t which = first; which <= last; ++which) {
                if ((to_name = name_of(which))) {
                    if (!(chars_t::compare(name, to_name)))
                        return which;
                }
            }
            return extension;
        }
        return none;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    which_t which_;
};
typedef xttp::request::parameters_implements uri_implements;
typedef xttp::request::parameters uri_extends;
///////////////////////////////////////////////////////////////////////
///  Class: uri
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS uri: virtual public uri_implements, public uri_extends {
public:
    typedef uri_implements Implements;
    typedef uri_extends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    uri(const char_t* chars): Extends(chars) {
    }
    uri(const uri& copy): Extends(copy) {
    }
    uri() {
    }
    virtual ~uri() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef xttp::request::line_implements line_implements;
typedef xttp::request::linet<method> line_extends;
///////////////////////////////////////////////////////////////////////
///  Class: line
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS line: virtual public line_implements, public line_extends {
public:
    typedef line_implements Implements;
    typedef line_extends Extends;
    typedef http::version version_t;
    typedef http::request::uri uri_t;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    line(const char_t* method, const char_t* uri)
    : Extends(method, uri, version_t()) {
    }
    line(const method_t& method, const uri_t& uri)
    : Extends(method, uri, version_t()) {
    }
    line(const line& copy): Extends(copy) {
    }
    line() {
    }
    virtual ~line() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef xttp::request::message_implements message_implements;
typedef xttp::request::messaget<line> message_extends;
///////////////////////////////////////////////////////////////////////
///  Class: message
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS message
: virtual protected message_implements, public message_extends {
public:
    typedef message_implements Implements;
    typedef message_extends Extends;
    typedef request::line line_t;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    message(const line_t& line): Extends(line) {
    }
    message() {
    }
    virtual ~message() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
} // namespace request

} // namespace http
} // namespace inet 
} // namespace medusa 

#endif // _MEDUSA_INET_HTTP_REQUEST_HPP 
