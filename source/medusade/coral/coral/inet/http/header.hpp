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
///   File: header.hpp
///
/// Author: $author$
///   Date: 1/13/2015
///////////////////////////////////////////////////////////////////////
#ifndef _CORAL_INET_HTTP_HEADER_HPP
#define _CORAL_INET_HTTP_HEADER_HPP

#include "medusa/inet/http/message/header.hpp"
#include "coral/base/string.hpp"

#define CORAL_INET_HTTP_MESSAGE_HEADER_NAME_CONTENT_ENCODING \
    MEDUSA_INET_HTTP_MESSAGE_HEADER_NAME_CONTENT_ENCODING

#define CORAL_INET_HTTP_MESSAGE_HEADER_NAME_CONTENT_LENGTH \
    MEDUSA_INET_HTTP_MESSAGE_HEADER_NAME_CONTENT_LENGTH

#define CORAL_INET_HTTP_MESSAGE_HEADER_NAME_CONTENT_TYPE \
    MEDUSA_INET_HTTP_MESSAGE_HEADER_NAME_CONTENT_TYPE

namespace coral {
namespace inet {
namespace http {
namespace message {
namespace header {

///////////////////////////////////////////////////////////////////////
/// Enum: which_t
///////////////////////////////////////////////////////////////////////
typedef medusa::inet::http::message::header::which_t which_t;
enum {
    none = medusa::inet::http::message::header::none,

    content_encoding = medusa::inet::http::message::header::content_encoding,
    content_length = medusa::inet::http::message::header::content_length,
    content_type = medusa::inet::http::message::header::content_type,

    next = medusa::inet::http::message::header::next,
    first = medusa::inet::http::message::header::first,
    last = medusa::inet::http::message::header::last,
};

typedef medusa::inet::http::message::header::name name;
typedef medusa::inet::http::message::header::value value;
typedef medusa::inet::http::message::header::field field;
typedef medusa::inet::http::message::header::fields fields;

} // namespace header
} // namespace message
} // namespace http
} // namespace inet 
} // namespace coral 

#endif // _CORAL_INET_HTTP_HEADER_HPP 
