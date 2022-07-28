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
///   File: address_string.hpp
///
/// Author: $author$
///   Date: 11/27/2014
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_NETWORK_IP_V4_ADDRESS_STRING_HPP
#define _XOS_NADIR_XOS_NETWORK_IP_V4_ADDRESS_STRING_HPP

#include "xos/network/ip/address.hpp"
#include "xos/base/string.hpp"
#include "xos/base/base.hpp"

#define XOS_NETWORK_IP_V4_ADDRESS_STRING_OCTET_SEPARATOR '.'
#define XOS_NETWORK_IP_V4_ADDRESS_STRING_OCTET_DIGIT_MIN '0'
#define XOS_NETWORK_IP_V4_ADDRESS_STRING_OCTET_DIGIT_MAX '9'

namespace xos {
namespace network {
namespace ip {
namespace v4 {

///////////////////////////////////////////////////////////////////////
///  Class: address_stringt
///////////////////////////////////////////////////////////////////////
template
<typename TChar = char_t, typename TEnd = TChar, TEnd VEnd = 0,
 class TExtends = base::stringt<TChar, TEnd, VEnd>,
 class TImplements = base::string_implements>

class _EXPORT_CLASS address_stringt
: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef TChar char_t;
    typedef TEnd end_t;
    enum { end = VEnd };
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    address_stringt(const char_t* chars, size_t length)
    : Extends(chars, length),
      octect_separator_(XOS_NETWORK_IP_V4_ADDRESS_STRING_OCTET_SEPARATOR),
      octet_digit_min_(XOS_NETWORK_IP_V4_ADDRESS_STRING_OCTET_DIGIT_MIN),
      octet_digit_max_(XOS_NETWORK_IP_V4_ADDRESS_STRING_OCTET_DIGIT_MAX) {
    }
    address_stringt(const char_t* chars)
    : Extends(chars),
      octect_separator_(XOS_NETWORK_IP_V4_ADDRESS_STRING_OCTET_SEPARATOR),
      octet_digit_min_(XOS_NETWORK_IP_V4_ADDRESS_STRING_OCTET_DIGIT_MIN),
      octet_digit_max_(XOS_NETWORK_IP_V4_ADDRESS_STRING_OCTET_DIGIT_MAX) {
    }
    address_stringt(const address_stringt& copy)
    : Extends(copy),
      octect_separator_(XOS_NETWORK_IP_V4_ADDRESS_STRING_OCTET_SEPARATOR),
      octet_digit_min_(XOS_NETWORK_IP_V4_ADDRESS_STRING_OCTET_DIGIT_MIN),
      octet_digit_max_(XOS_NETWORK_IP_V4_ADDRESS_STRING_OCTET_DIGIT_MAX) {
    }
    address_stringt()
    : octect_separator_(XOS_NETWORK_IP_V4_ADDRESS_STRING_OCTET_SEPARATOR),
      octet_digit_min_(XOS_NETWORK_IP_V4_ADDRESS_STRING_OCTET_DIGIT_MIN),
      octet_digit_max_(XOS_NETWORK_IP_V4_ADDRESS_STRING_OCTET_DIGIT_MAX) {
    }
    virtual ~address_stringt() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual uint32_t to_uint32() const {
        uint32_t addr = 0;
        uint8_t octet;
        size_t octetLen;
        const char_t* chars;
        size_t len;
        char_t c;

        if ((chars = this->has_chars(len))) {
            for (octet = 0, octetLen = 0; len; ++chars, --len) {
                if (octect_separator_ != (c = *chars)) {
                    if ((c < octet_digit_min_) || (c > octet_digit_max_)) {
                        ::char_t cc = (::char_t)(c);
                        base::string cs(&cc, 1);
                        return 0;
                    }
                    octet = ((octet * 10) + (c - octet_digit_min_));
                    ++octetLen;
                } else {
                    addr = ((addr << 8) | octet);
                    octet = 0;
                    octetLen = 0;
                }
            }
            if ((octetLen))
                addr = ((addr << 8) | octet);
        }
        return addr;
    }
    virtual operator uint32_t() const {
        uint32_t addr = to_uint32();
        return addr;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    const char_t octect_separator_,
                 octet_digit_min_,
                 octet_digit_max_;
};
typedef address_stringt<> address_string;

} // namespace v4 
} // namespace ip 
} // namespace network 
} // namespace xos 

#endif // _XOS_NADIR_XOS_NETWORK_IP_V4_ADDRESS_STRING_HPP 
