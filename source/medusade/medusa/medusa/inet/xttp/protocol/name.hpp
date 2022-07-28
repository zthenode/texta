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
///   File: name.hpp
///
/// Author: $author$
///   Date: 11/23/2014
///////////////////////////////////////////////////////////////////////
#ifndef _MEDUSA_INET_XTTP_PROTOCOL_NAME_HPP
#define _MEDUSA_INET_XTTP_PROTOCOL_NAME_HPP

#include "medusa/base/string.hpp"

namespace medusa {
namespace inet {
namespace xttp {
namespace protocol {

typedef string_implements name_implements;
typedef string_t name_extends;
///////////////////////////////////////////////////////////////////////
///  Class: namet
///////////////////////////////////////////////////////////////////////
template
<class TImplements = name_implements, class TExtends = name_extends>

class _EXPORT_CLASS namet: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    namet(const char_t* chars, size_t length): Extends(chars, length) {
    }
    namet(const char_t* chars): Extends(chars) {
    }
    namet(const namet& copy): Extends(copy) {
    }
    namet() {
    }
    virtual ~namet() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef namet<> name;

} // namespace protocol 
} // namespace xttp 
} // namespace inet 
} // namespace medusa 

#endif // _MEDUSA_INET_XTTP_PROTOCOL_NAME_HPP 
