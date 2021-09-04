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
//   File: cIpV6NetworkAddressInterface.hpp
//
// Author: $author$
//   Date: 4/5/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CIPV6NETWORKADDRESSINTERFACE_HPP) || defined(CIPV6NETWORKADDRESSINTERFACE_MEMBERS_ONLY)
#if !defined(_CIPV6NETWORKADDRESSINTERFACE_HPP) && !defined(CIPV6NETWORKADDRESSINTERFACE_MEMBERS_ONLY)
#define _CIPV6NETWORKADDRESSINTERFACE_HPP
#endif // !defined(_CIPV6NETWORKADDRESSINTERFACE_HPP) && !defined(CIPV6NETWORKADDRESSINTERFACE_MEMBERS_ONLY) 

#if !defined(CIPV6NETWORKADDRESSINTERFACE_MEMBERS_ONLY)
#include "cIpNetworkAddressInterface.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cIpV6NetworkAddressInterfaceImplements
//
//  Author: $author$
//    Date: 4/5/2011
///////////////////////////////////////////////////////////////////////
typedef cIpNetworkAddressInterface
cIpV6NetworkAddressInterfaceImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cIpV6NetworkAddressInterface
//
// Author: $author$
//   Date: 4/5/2011
///////////////////////////////////////////////////////////////////////
class c_INTERFACE_CLASS cIpV6NetworkAddressInterface
: virtual public cIpV6NetworkAddressInterfaceImplements
{
public:
    typedef cIpV6NetworkAddressInterfaceImplements cImplements;
#else // !defined(CIPV6NETWORKADDRESSINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CIPV6NETWORKADDRESSINTERFACE_MEMBERS_ONLY) 

#if !defined(CIPV6NETWORKADDRESSINTERFACE_MEMBERS_ONLY)
// include cIpV6NetworkAddress member functions interface
 
#define CIPV6NETWORKADDRESS_MEMBERS_ONLY
#define CIPV6NETWORKADDRESS_MEMBER_FUNCS_INTERFACE
#include "cIpV6NetworkAddress.hpp"
#undef CIPV6NETWORKADDRESS_MEMBER_FUNCS_INTERFACE
#undef CIPV6NETWORKADDRESS_MEMBERS_ONLY

};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CIPV6NETWORKADDRESSINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CIPV6NETWORKADDRESSINTERFACE_MEMBERS_ONLY) 

#endif // !defined(_CIPV6NETWORKADDRESSINTERFACE_HPP) || defined(CIPV6NETWORKADDRESSINTERFACE_MEMBERS_ONLY) 
        

