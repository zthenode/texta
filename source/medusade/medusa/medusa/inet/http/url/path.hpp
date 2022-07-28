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
///   File: path.hpp
///
/// Author: $author$
///   Date: 10/27/2018
///////////////////////////////////////////////////////////////////////
#ifndef _MEDUSA_INET_HTTP_URL_PATH_HPP
#define _MEDUSA_INET_HTTP_URL_PATH_HPP

#include "medusa/inet/http/url/part.hpp"

namespace medusa {
namespace inet {
namespace http {
namespace url {

typedef part::Implements path_implements;
typedef part path_extends;
///////////////////////////////////////////////////////////////////////
///  Class: path
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS path: virtual public path_implements, public path_extends {
public:
    typedef path_implements Implements;
    typedef path_extends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    path(const char_t* copy, size_t length): Extends(copy, length) {}
    path(const char_t* copy): Extends(copy) {}
    path(const string_t& copy): Extends(copy) {}
    path(const path& copy): Extends(copy) {}
    path() {}
    virtual ~path() {}
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
}; /// class _EXPORT_CLASS path

} /// namespace url
} /// namespace http
} /// namespace inet
} /// namespace medusa

#endif ///ndef _MEDUSA_INET_HTTP_URL_PATH_HPP
