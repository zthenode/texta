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
///   File: content.hpp
///
/// Author: $author$
///   Date: 1/7/2015
///////////////////////////////////////////////////////////////////////
#ifndef _CORAL_INET_HTTP_CONTENT_HPP
#define _CORAL_INET_HTTP_CONTENT_HPP

#include "medusa/inet/http/content/type/name.hpp"
#include "medusa/inet/http/content/type/which.hpp"
#include "medusa/inet/http/content/reader.hpp"
#include "medusa/inet/http/url/encoded/reader.hpp"
#include "medusa/inet/http/form/reader.hpp"
#include "medusa/inet/http/form/fields.hpp"
#include "medusa/inet/http/form/field.hpp"
#include "coral/base/base.hpp"

namespace coral {
namespace inet {
namespace http {

namespace content {
namespace type {

///////////////////////////////////////////////////////////////////////
/// which
///////////////////////////////////////////////////////////////////////
typedef medusa::inet::http::content::type::which_t which_t;
enum {
    none = medusa::inet::http::content::type::none,

    text = medusa::inet::http::content::type::text,
    html = medusa::inet::http::content::type::html,
    xml = medusa::inet::http::content::type::xml,
    octet_stream = medusa::inet::http::content::type::octet_stream,
    urlencoded_form_data = medusa::inet::http::content::type::urlencoded_form_data,
    multipart_form_data = medusa::inet::http::content::type::multipart_form_data,
    json = medusa::inet::http::content::type::json,
    javascript = medusa::inet::http::content::type::javascript,

    next = medusa::inet::http::content::type::next,
    first = medusa::inet::http::content::type::first,
    last = medusa::inet::http::content::type::last,
};

///////////////////////////////////////////////////////////////////////
///  Class: name
///////////////////////////////////////////////////////////////////////
#if defined(USE_CPP_11)
template
<typename TChar = char_t, typename TWhich = which_t,
 class TExtends = xos::base::stringt<TChar>,
 class TImplements = medusa::inet::http::content::type::name_implements>

using namet = typename medusa::inet::http::content::type::namet
<TChar, TWhich, TExtends, TImplements>;
#else // defined(USE_CPP_11)
#endif // defined(USE_CPP_11)
typedef medusa::inet::http::content::type::name name;

} // namespace type
} // namespace content

namespace content {
namespace read {
///////////////////////////////////////////////////////////////////////
///  Class: observer
///////////////////////////////////////////////////////////////////////
typedef medusa::inet::http::content::read::observer observer;
} // namespace read
typedef medusa::inet::http::content::reader_extends reader_extends;
///////////////////////////////////////////////////////////////////////
///  Class: reader
///////////////////////////////////////////////////////////////////////
#if defined(USE_CPP_11)
template
<typename TWhat = void, typename TSized = char_t,
 typename TEnd = int, TEnd VEnd = 0,
 class TReader = io::readert<TWhat, TSized, TEnd, VEnd>,
 class TImplements = TReader, class TExtends = reader_extends>

using readert = typename medusa::inet::http::content::readert
<TWhat, TSized, TEnd, VEnd, TReader, TImplements, TExtends>;
#else // defined(USE_CPP_11)
#endif // defined(USE_CPP_11)
typedef medusa::inet::http::content::reader reader;
} // namespace content

namespace url {
namespace encoded {

typedef medusa::inet::http::url::encoded::reader_extends reader_extends;
///////////////////////////////////////////////////////////////////////
///  Class: reader
///////////////////////////////////////////////////////////////////////
#if defined(USE_CPP_11)
template
<typename TWhat = void, typename TSized = char_t,
 typename TEnd = int, TEnd VEnd = 0,
 class TReader = io::readert<TWhat, TSized, TEnd, VEnd>,
 class TImplements = TReader, class TExtends = reader_extends>

using readert = typename medusa::inet::http::url::encoded::readert
<TWhat, TSized, TEnd, VEnd, TReader, TImplements, TExtends>;
#else // defined(USE_CPP_11)
#endif // defined(USE_CPP_11)
typedef medusa::inet::http::url::encoded::reader reader;

} // namespace encoded
} // namespace url

namespace form {

typedef implement_base field_implements;
typedef base field_extends;
///////////////////////////////////////////////////////////////////////
///  Class: field
///////////////////////////////////////////////////////////////////////
#if defined(USE_CPP_11)
template
<typename TChar = char_t, typename TEnd = int, TEnd VEnd = 0,
 class TString = stringt<TChar, TEnd, VEnd>,
 class TImplements = field_implements, class TExtends = field_extends>

using fieldt = typename medusa::inet::http::form::fieldt
<TChar, TEnd, VEnd, TString, TImplements, TExtends>;
#else // defined(USE_CPP_11)
#endif // defined(USE_CPP_11)
typedef medusa::inet::http::form::field field;

typedef implement_base fields_implements;
///////////////////////////////////////////////////////////////////////
///  Class: fields
///////////////////////////////////////////////////////////////////////
#if defined(USE_CPP_11)
template
<class TField = field, class TFields = std::list<TField>,
 class TExtends = TFields, class TImplements = fields_implements>

using fieldst = typename medusa::inet::http::form::fieldst
<TField, TFields, TExtends, TImplements>;
#else // defined(USE_CPP_11)
#endif // defined(USE_CPP_11)
typedef medusa::inet::http::form::fields fields;

typedef implement_base reader_implements;
typedef base reader_extends;
///////////////////////////////////////////////////////////////////////
///  Class: reader
///////////////////////////////////////////////////////////////////////
#if defined(USE_CPP_11)
template
<typename TWhat = void, typename TSized = char_t,
 typename TEnd = int, TEnd VEnd = 0,
 class TReader = io::readert<TWhat, TSized, TEnd, VEnd>,
 class TField = fieldt<TSized, TEnd, VEnd>, class TFields = fieldst<TField>,
 class TImplements = reader_implements, class TExtends = reader_extends>

using readert = typename medusa::inet::http::form::readert
<TWhat, TSized, TEnd, VEnd, TReader, TField, TFields, TImplements, TExtends>;
#else // defined(USE_CPP_11)
#endif // defined(USE_CPP_11)
typedef medusa::inet::http::form::reader reader;

} // namespace form

} // namespace http
} // namespace inet 
} // namespace coral 

#endif // _CORAL_INET_HTTP_CONTENT_HPP 
