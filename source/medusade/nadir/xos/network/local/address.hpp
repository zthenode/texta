///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2016 $organization$
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
///   File: address.hpp
///
/// Author: $author$
///   Date: 8/10/2016
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_NETWORK_LOCAL_ADDRESS_HPP
#define _XOS_NADIR_XOS_NETWORK_LOCAL_ADDRESS_HPP

#include "xos/network/address.hpp"
#include <sys/un.h>

#define XOS_NETWORK_LOCAL_ADDRESS_FAMILY AF_LOCAL
#define XOS_NETWORK_LOCAL_ADDRESS_VERSION 0

namespace xos {
namespace network {
namespace local {

typedef network::address address_implements;
typedef base::base address_extends;
///////////////////////////////////////////////////////////////////////
///  Class: addresst
///////////////////////////////////////////////////////////////////////
template
<typename TFamily = address_family_t, typename TVersion = address_version_t,
 class TImplements = address_implements, class TExtends = address_extends>

class _EXPORT_CLASS addresst: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef TFamily family_t;
    typedef TVersion version_t;

    enum { family = XOS_NETWORK_LOCAL_ADDRESS_FAMILY };
    enum { version = XOS_NETWORK_LOCAL_ADDRESS_VERSION };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    addresst() {
    }
    virtual ~addresst() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int get_family() const {
        return family;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int get_version() const {
        return version;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef addresst<> address;

} // namespace local 
} // namespace network 
} // namespace xos 

#endif // _XOS_NADIR_XOS_NETWORK_LOCAL_ADDRESS_HPP 
