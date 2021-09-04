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
//   File: cIpNetworkAddressInterface.hpp
//
// Author: $author$
//   Date: 4/5/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CIPNETWORKADDRESSINTERFACE_HPP) || defined(CIPNETWORKADDRESSINTERFACE_MEMBERS_ONLY)
#if !defined(_CIPNETWORKADDRESSINTERFACE_HPP) && !defined(CIPNETWORKADDRESSINTERFACE_MEMBERS_ONLY)
#define _CIPNETWORKADDRESSINTERFACE_HPP
#endif // !defined(_CIPNETWORKADDRESSINTERFACE_HPP) && !defined(CIPNETWORKADDRESSINTERFACE_MEMBERS_ONLY) 

#if !defined(CIPNETWORKADDRESSINTERFACE_MEMBERS_ONLY)
#include "cNetworkAddressInterface.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cIpNetworkAddressInterfaceImplements
//
//  Author: $author$
//    Date: 4/5/2011
///////////////////////////////////////////////////////////////////////
typedef cNetworkAddressInterface
cIpNetworkAddressInterfaceImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cIpNetworkAddressInterface
//
// Author: $author$
//   Date: 4/5/2011
///////////////////////////////////////////////////////////////////////
class c_INTERFACE_CLASS cIpNetworkAddressInterface
: virtual public cIpNetworkAddressInterfaceImplements
{
public:
    typedef cIpNetworkAddressInterfaceImplements cImplements;
#else // !defined(CIPNETWORKADDRESSINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CIPNETWORKADDRESSINTERFACE_MEMBERS_ONLY) 

#if !defined(CIPNETWORKADDRESSINTERFACE_MEMBERS_ONLY)
// include cIpNetworkAddress member functions interface
 
#define CIPNETWORKADDRESS_MEMBERS_ONLY
#define CIPNETWORKADDRESS_MEMBER_FUNCS_INTERFACE
#include "cIpNetworkAddress.hpp"
#undef CIPNETWORKADDRESS_MEMBER_FUNCS_INTERFACE
#undef CIPNETWORKADDRESS_MEMBERS_ONLY

};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CIPNETWORKADDRESSINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CIPNETWORKADDRESSINTERFACE_MEMBERS_ONLY) 

#endif // !defined(_CIPNETWORKADDRESSINTERFACE_HPP) || defined(CIPNETWORKADDRESSINTERFACE_MEMBERS_ONLY) 
        

