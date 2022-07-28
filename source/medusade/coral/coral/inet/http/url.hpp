///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2018 $organization$
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
///   File: url.hpp
///
/// Author: $author$
///   Date: 10/29/2018
///////////////////////////////////////////////////////////////////////
#ifndef _CORAL_INET_HTTP_URL_HPP
#define _CORAL_INET_HTTP_URL_HPP

#include "medusa/inet/http/url/part.hpp"
#include "medusa/inet/http/url/scheme.hpp"
#include "medusa/inet/http/url/authority.hpp"
#include "medusa/inet/http/url/path.hpp"
#include "medusa/inet/http/url/query.hpp"
#include "medusa/inet/http/url/fragment.hpp"
#include "medusa/inet/http/url/location.hpp"
#include "medusa/inet/http/url/encoded/string.hpp"
#include "medusa/inet/http/url/encoded/form/fields.hpp"

namespace coral {
namespace inet {
namespace http {
namespace url {

typedef ::medusa::inet::http::url::scheme scheme;
typedef ::medusa::inet::http::url::authority authority;
typedef ::medusa::inet::http::url::path path;
typedef ::medusa::inet::http::url::query query;
typedef ::medusa::inet::http::url::fragment fragment;
typedef ::medusa::inet::http::url::location location;

namespace encoded {

typedef ::medusa::inet::http::url::encoded::string string;

namespace form {

typedef ::medusa::inet::http::url::encoded::form::fields fields;

} /// namespace form

} /// namespace encoded

} /// namespace url
} /// namespace http
} /// namespace inet
} /// namespace coral

#endif ///ndef _CORAL_INET_HTTP_URL_HPP
