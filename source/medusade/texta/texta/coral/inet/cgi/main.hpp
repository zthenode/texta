///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2017 $organization$
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
///   File: main.hpp
///
/// Author: $author$
///   Date: 5/29/2017
///////////////////////////////////////////////////////////////////////
#ifndef _TEXTA_CORAL_INET_CGI_MAIN_HPP
#define _TEXTA_CORAL_INET_CGI_MAIN_HPP

#include "coral/inet/cgi/main.hpp"

namespace texta {
namespace inet {
namespace http {

namespace content {
namespace type {

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
typedef ::coral::inet::http::content::type::which_t which_t;
enum {
    none = ::coral::inet::http::content::type::none,

    text = ::coral::inet::http::content::type::text,
    html = ::coral::inet::http::content::type::html,
    xml = ::coral::inet::http::content::type::xml,
    octet_stream = ::coral::inet::http::content::type::octet_stream,
    urlencoded_form_data = ::coral::inet::http::content::type::urlencoded_form_data,
    multipart_form_data = ::coral::inet::http::content::type::multipart_form_data,

    next = ::coral::inet::http::content::type::next,
    first = ::coral::inet::http::content::type::first,
    last = ::coral::inet::http::content::type::last,
};
typedef ::coral::inet::http::content::type::name name;

} // namespace type
} // namespace content

namespace form {

typedef ::coral::inet::http::form::field field;
typedef ::coral::inet::http::form::fields fields;

} // namespace form
} // namespace http

namespace cgi {
namespace environment {
namespace variable {

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
typedef ::coral::inet::cgi::environment::variable::which_t which_t;
enum {
    none = ::coral::inet::cgi::environment::variable::none,

    PATH_INFO = ::coral::inet::cgi::environment::variable::PATH_INFO,
    PATH_TRANSLATED = ::coral::inet::cgi::environment::variable::PATH_TRANSLATED,

    firat = ::coral::inet::cgi::environment::variable::first,
    last = ::coral::inet::cgi::environment::variable::last,
    count = ::coral::inet::cgi::environment::variable::count
};
typedef ::coral::inet::cgi::environment::variable::name name;
typedef ::coral::inet::cgi::environment::variable::value value;

} // namespace variable

namespace variables {

typedef ::coral::inet::cgi::environment::variables::values values;

} // namespace variables
} // namespace environment

typedef ::coral::inet::cgi::main_implements main_implements;
typedef ::coral::inet::cgi::main main_extends;

} // namespace cgi

} // namespace inet 
} // namespace texta 

#endif // _TEXTA_CORAL_INET_CGI_MAIN_HPP 
