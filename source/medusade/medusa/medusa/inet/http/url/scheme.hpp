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
///   File: scheme.hpp
///
/// Author: $author$
///   Date: 10/27/2018
///////////////////////////////////////////////////////////////////////
#ifndef _MEDUSA_INET_HTTP_URL_SCHEME_HPP
#define _MEDUSA_INET_HTTP_URL_SCHEME_HPP

#include "medusa/inet/http/url/part.hpp"

namespace medusa {
namespace inet {
namespace http {
namespace url {

typedef part::Implements scheme_implements;
typedef part scheme_extends;
///////////////////////////////////////////////////////////////////////
///  Class: scheme
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS scheme: virtual public scheme_implements, public scheme_extends {
public:
    typedef scheme_implements Implements;
    typedef scheme_extends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    scheme(const char_t* copy, size_t length): Extends(copy, length) {}
    scheme(const char_t* copy): Extends(copy) {}
    scheme(const string_t& copy): Extends(copy) {}
    scheme(const scheme& copy): Extends(copy) {}
    scheme() {}
    virtual ~scheme() {}
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
}; /// class _EXPORT_CLASS scheme

} /// namespace url
} /// namespace http
} /// namespace inet
} /// namespace medusa

#endif ///ndef _MEDUSA_INET_HTTP_URL_SCHEME_HPP
