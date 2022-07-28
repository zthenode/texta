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
///   File: reason.hpp
///
/// Author: $author$
///   Date: 11/23/2014
///////////////////////////////////////////////////////////////////////
#ifndef _MEDUSA_INET_XTTP_RESPONSE_STATUS_REASON_HPP
#define _MEDUSA_INET_XTTP_RESPONSE_STATUS_REASON_HPP

#include "medusa/base/base.hpp"

namespace medusa {
namespace inet {
namespace xttp {
namespace response {
namespace status {

typedef string_implements reason_implements;
typedef string_t reason_extends;
///////////////////////////////////////////////////////////////////////
///  Class: reasont
///////////////////////////////////////////////////////////////////////
template
<class TImplements = reason_implements,
 class TExtends = reason_extends>

class _EXPORT_CLASS reasont: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    reasont(const char_t* chars, size_t length): Extends(chars, length) {
    }
    reasont(const char_t* chars): Extends(chars) {
    }
    reasont(const reasont& copy): Extends(copy) {
    }
    reasont() {
    }
    virtual ~reasont() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef reasont<> reason;

} // namespace status 
} // namespace response 
} // namespace xttp 
} // namespace inet 
} // namespace medusa 

#endif // _MEDUSA_INET_XTTP_RESPONSE_STATUS_REASON_HPP 
