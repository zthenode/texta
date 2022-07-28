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
///   File: address.hpp
///
/// Author: $author$
///   Date: 11/27/2014
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_NETWORK_ADDRESS_HPP
#define _XOS_NADIR_XOS_NETWORK_ADDRESS_HPP

#include "xos/base/base.hpp"

#include <sys/socket.h>
#include <netdb.h>

#define XOS_NETWORK_ADDRESS_FAMILY_UNSPEC AF_UNSPEC
#define XOS_NETWORK_ADDRESS_VERSION_UNSPEC 0

namespace xos {
namespace network {

typedef int address_family_t;
typedef int address_version_t;
typedef base::implement_base address_implements;
///////////////////////////////////////////////////////////////////////
///  Class: addresst
///////////////////////////////////////////////////////////////////////
template
<typename TFamily = address_family_t,
 typename TVersion = address_version_t,
 class TImplements = address_implements>

class _EXPORT_CLASS addresst: virtual public TImplements {
public:
    typedef TImplements Implements;
    typedef TFamily family_t;
    enum { family = XOS_NETWORK_ADDRESS_FAMILY_UNSPEC };
    enum { version = XOS_NETWORK_ADDRESS_VERSION_UNSPEC };
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
};
typedef addresst<> address;

} // namespace network 
} // namespace xos 

#endif // _XOS_NADIR_XOS_NETWORK_ADDRESS_HPP 
