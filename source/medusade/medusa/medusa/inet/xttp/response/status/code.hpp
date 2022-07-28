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
///   File: code.hpp
///
/// Author: $author$
///   Date: 11/23/2014
///////////////////////////////////////////////////////////////////////
#ifndef _MEDUSA_INET_XTTP_RESPONSE_STATUS_CODE_HPP
#define _MEDUSA_INET_XTTP_RESPONSE_STATUS_CODE_HPP

#include "medusa/base/string.hpp"

namespace medusa {
namespace inet {
namespace xttp {
namespace response {
namespace status {

typedef medusa::string_t_implements code_implements;
typedef medusa::string_t code_extends;
///////////////////////////////////////////////////////////////////////
///  Class: codet
///////////////////////////////////////////////////////////////////////
template
<class TImplements = code_implements,
 class TExtends = code_extends>

class _EXPORT_CLASS codet: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    codet(const char_t* chars, size_t length): Extends(chars, length) {
    }
    codet(const char_t* chars): Extends(chars) {
    }
    codet(const codet& copy): Extends(copy) {
    }
    codet() {
    }
    virtual ~codet() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef codet<> code;

} // namespace status 
} // namespace response 
} // namespace xttp 
} // namespace inet 
} // namespace medusa 

#endif // _MEDUSA_INET_XTTP_RESPONSE_STATUS_CODE_HPP 
