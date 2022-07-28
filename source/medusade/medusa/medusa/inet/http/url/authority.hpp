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
///   File: authority.hpp
///
/// Author: $author$
///   Date: 10/27/2018
///////////////////////////////////////////////////////////////////////
#ifndef _MEDUSA_INET_HTTP_URL_AUTHORITY_HPP
#define _MEDUSA_INET_HTTP_URL_AUTHORITY_HPP

#include "medusa/inet/http/url/part.hpp"

namespace medusa {
namespace inet {
namespace http {
namespace url {

typedef part::Implements authority_implements;
typedef part authority_extends;
///////////////////////////////////////////////////////////////////////
///  Class: authority
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS authority: virtual public authority_implements, public authority_extends {
public:
    typedef authority_implements Implements;
    typedef authority_extends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    authority(const char_t* copy, size_t length): Extends(copy, length) {}
    authority(const char_t* copy): Extends(copy) {}
    authority(const string_t& copy): Extends(copy) {}
    authority(const authority& copy): Extends(copy) {}
    authority() {}
    virtual ~authority() {}
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
}; /// class _EXPORT_CLASS authority

} /// namespace url
} /// namespace http
} /// namespace inet
} /// namespace medusa

#endif ///ndef _MEDUSA_INET_HTTP_URL_AUTHORITY_HPP
