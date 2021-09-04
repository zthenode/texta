///////////////////////////////////////////////////////////////////////
// Copyright (c) 1988-2011 $organization$
//
// This software is provided by the author and contributors ``as is'' 
// and any express or implied warranties, including, but not limited to, 
// the implied warranties of merchantability and fitness for a particular 
// purpose are disclaimed. In no event shall the author or contributors 
// be liable for any direct, indirect, incidental, special, exemplary, 
// or consequential damages (including, but not limited to, procurement 
// of substitute goods or services; loss of use, data, or profits; or 
// business interruption) however caused and on any theory of liability, 
// whether in contract, strict liability, or tort (including negligence 
// or otherwise) arising in any way out of the use of this software, 
// even if advised of the possibility of such damage.
//
//   File: cIpV6SocketAddressInterface.hpp
//
// Author: $author$
//   Date: 4/5/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CIPV6SOCKETADDRESSINTERFACE_HPP) || defined(CIPV6SOCKETADDRESSINTERFACE_MEMBERS_ONLY)
#if !defined(_CIPV6SOCKETADDRESSINTERFACE_HPP) && !defined(CIPV6SOCKETADDRESSINTERFACE_MEMBERS_ONLY)
#define _CIPV6SOCKETADDRESSINTERFACE_HPP
#endif // !defined(_CIPV6SOCKETADDRESSINTERFACE_HPP) && !defined(CIPV6SOCKETADDRESSINTERFACE_MEMBERS_ONLY) 

#if !defined(CIPV6SOCKETADDRESSINTERFACE_MEMBERS_ONLY)
#include "cIpSocketAddressInterface.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cIpV6SocketAddressInterfaceImplements
//
//  Author: $author$
//    Date: 4/5/2011
///////////////////////////////////////////////////////////////////////
typedef cIpSocketAddressInterface
cIpV6SocketAddressInterfaceImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cIpV6SocketAddressInterface
//
// Author: $author$
//   Date: 4/5/2011
///////////////////////////////////////////////////////////////////////
class c_INTERFACE_CLASS cIpV6SocketAddressInterface
: virtual public cIpV6SocketAddressInterfaceImplements
{
public:
    typedef cIpV6SocketAddressInterfaceImplements cImplements;
#else // !defined(CIPV6SOCKETADDRESSINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CIPV6SOCKETADDRESSINTERFACE_MEMBERS_ONLY) 

#if !defined(CIPV6SOCKETADDRESSINTERFACE_MEMBERS_ONLY)
// include cIpV6SocketAddress member functions interface
 
#define CIPV6SOCKETADDRESS_MEMBERS_ONLY
#define CIPV6SOCKETADDRESS_MEMBER_FUNCS_INTERFACE
#include "cIpV6SocketAddress.hpp"
#undef CIPV6SOCKETADDRESS_MEMBER_FUNCS_INTERFACE
#undef CIPV6SOCKETADDRESS_MEMBERS_ONLY

};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CIPV6SOCKETADDRESSINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CIPV6SOCKETADDRESSINTERFACE_MEMBERS_ONLY) 

#endif // !defined(_CIPV6SOCKETADDRESSINTERFACE_HPP) || defined(CIPV6SOCKETADDRESSINTERFACE_MEMBERS_ONLY) �
�
8
�
��
        

