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
///   File: parameters.hpp
///
/// Author: $author$
///   Date: 11/23/2014
///////////////////////////////////////////////////////////////////////
#ifndef _MEDUSA_INET_XTTP_REQUEST_PARAMETERS_HPP
#define _MEDUSA_INET_XTTP_REQUEST_PARAMETERS_HPP

#include "medusa/base/base.hpp"

namespace medusa {
namespace inet {
namespace xttp {
namespace request {

typedef string_implements parameters_implements;
typedef string_t parameters_extends;
///////////////////////////////////////////////////////////////////////
///  Class: parameterst
///////////////////////////////////////////////////////////////////////
template
<class TImplements = parameters_implements,
 class TExtends = parameters_extends>

class _EXPORT_CLASS parameterst: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    parameterst(const char_t* chars, size_t length): Extends(chars, length) {
    }
    parameterst(const char_t* chars): Extends(chars) {
    }
    parameterst(const parameterst& copy): Extends(copy) {
    }
    parameterst() {
    }
    virtual ~parameterst() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef parameterst<> parameters;

} // namespace request 
} // namespace xttp 
} // namespace inet 
} // namespace medusa 

#endif // _MEDUSA_INET_XTTP_REQUEST_PARAMETERS_HPP 
