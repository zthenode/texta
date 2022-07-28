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
///   File: content.hpp
///
/// Author: $author$
///   Date: 11/24/2014
///////////////////////////////////////////////////////////////////////
#ifndef _MEDUSA_INET_XTTP_MESSAGE_BODY_CONTENT_HPP
#define _MEDUSA_INET_XTTP_MESSAGE_BODY_CONTENT_HPP

#include "medusa/base/string.hpp"

namespace medusa {
namespace inet {
namespace xttp {
namespace message {
namespace body {

typedef string_implements content_implements;
typedef string_t content_extends;
///////////////////////////////////////////////////////////////////////
///  Class: contentt
///////////////////////////////////////////////////////////////////////
template
<class TImplements = content_implements,
 class TExtends = content_extends>

class _EXPORT_CLASS contentt
: virtual public content_implements, public content_extends {
public:
    typedef content_implements Implements;
    typedef content_extends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    contentt() {
    }
    virtual ~contentt() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef contentt<> content;

} // namespace body 
} // namespace message 
} // namespace xttp 
} // namespace inet 
} // namespace medusa 

#endif // _MEDUSA_INET_XTTP_MESSAGE_BODY_CONTENT_HPP 
