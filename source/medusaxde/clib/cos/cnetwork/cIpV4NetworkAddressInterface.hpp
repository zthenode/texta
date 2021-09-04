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
//   File: cIpV4NetworkAddressInterface.hpp
//
// Author: $author$
//   Date: 4/5/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CIPV4NETWORKADDRESSINTERFACE_HPP) || defined(CIPV4NETWORKADDRESSINTERFACE_MEMBERS_ONLY)
#if !defined(_CIPV4NETWORKADDRESSINTERFACE_HPP) && !defined(CIPV4NETWORKADDRESSINTERFACE_MEMBERS_ONLY)
#define _CIPV4NETWORKADDRESSINTERFACE_HPP
#endif // !defined(_CIPV4NETWORKADDRESSINTERFACE_HPP) && !defined(CIPV4NETWORKADDRESSINTERFACE_MEMBERS_ONLY) 

#if !defined(CIPV4NETWORKADDRESSINTERFACE_MEMBERS_ONLY)
#include "cIpNetworkAddressInterface.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cIpV4NetworkAddressInterfaceImplements
//
//  Author: $author$
//    Date: 4/5/2011
///////////////////////////////////////////////////////////////////////
typedef cIpNetworkAddressInterface
cIpV4NetworkAddressInterfaceImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cIpV4NetworkAddressInterface
//
// Author: $author$
//   Date: 4/5/2011
///////////////////////////////////////////////////////////////////////
class c_INTERFACE_CLASS cIpV4NetworkAddressInterface
: virtual public cIpV4NetworkAddressInterfaceImplements
{
public:
    typedef cIpV4NetworkAddressInterfaceImplements cImplements;
#else // !defined(CIPV4NETWORKADDRESSINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CIPV4NETWORKADDRESSINTERFACE_MEMBERS_ONLY) 

#if !defined(CIPV4NETWORKADDRESSINTERFACE_MEMBERS_ONLY)
// include cIpV4NetworkAddress member functions interface
 
#define CIPV4NETWORKADDRESS_MEMBERS_ONLY
#define CIPV4NETWORKADDRESS_MEMBER_FUNCS_INTERFACE
#include "cIpV4NetworkAddress.hpp"
#undef CIPV4NETWORKADDRESS_MEMBER_FUNCS_INTERFACE
#undef CIPV4NETWORKADDRESS_MEMBERS_ONLY

};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CIPV4NETWORKADDRESSINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CIPV4NETWORKADDRESSINTERFACE_MEMBERS_ONLY) 

#endif // !defined(_CIPV4NETWORKADDRESSINTERFACE_HPP) || defined(CIPV4NETWORKADDRESSINTERFACE_MEMBERS_ONLY) 
        

