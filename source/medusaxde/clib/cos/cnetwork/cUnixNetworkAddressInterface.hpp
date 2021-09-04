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
//   File: cUnixNetworkAddressInterface.hpp
//
// Author: $author$
//   Date: 4/5/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CUNIXNETWORKADDRESSINTERFACE_HPP) || defined(CUNIXNETWORKADDRESSINTERFACE_MEMBERS_ONLY)
#if !defined(_CUNIXNETWORKADDRESSINTERFACE_HPP) && !defined(CUNIXNETWORKADDRESSINTERFACE_MEMBERS_ONLY)
#define _CUNIXNETWORKADDRESSINTERFACE_HPP
#endif // !defined(_CUNIXNETWORKADDRESSINTERFACE_HPP) && !defined(CUNIXNETWORKADDRESSINTERFACE_MEMBERS_ONLY) 

#if !defined(CUNIXNETWORKADDRESSINTERFACE_MEMBERS_ONLY)
#include "cNetworkAddressInterface.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cUnixNetworkAddressInterfaceImplements
//
//  Author: $author$
//    Date: 4/5/2011
///////////////////////////////////////////////////////////////////////
typedef cNetworkAddressInterface
cUnixNetworkAddressInterfaceImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cUnixNetworkAddressInterface
//
// Author: $author$
//   Date: 4/5/2011
///////////////////////////////////////////////////////////////////////
class c_INTERFACE_CLASS cUnixNetworkAddressInterface
: virtual public cUnixNetworkAddressInterfaceImplements
{
public:
    typedef cUnixNetworkAddressInterfaceImplements cImplements;
#else // !defined(CUNIXNETWORKADDRESSINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CUNIXNETWORKADDRESSINTERFACE_MEMBERS_ONLY) 

#if !defined(CUNIXNETWORKADDRESSINTERFACE_MEMBERS_ONLY)
// include cUnixNetworkAddress member functions interface
 
#define CUNIXNETWORKADDRESS_MEMBERS_ONLY
#define CUNIXNETWORKADDRESS_MEMBER_FUNCS_INTERFACE
#include "cUnixNetworkAddress.hpp"
#undef CUNIXNETWORKADDRESS_MEMBER_FUNCS_INTERFACE
#undef CUNIXNETWORKADDRESS_MEMBERS_ONLY

};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CUNIXNETWORKADDRESSINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CUNIXNETWORKADDRESSINTERFACE_MEMBERS_ONLY) 

#endif // !defined(_CUNIXNETWORKADDRESSINTERFACE_HPP) || defined(CUNIXNETWORKADDRESSINTERFACE_MEMBERS_ONLY) 
        

