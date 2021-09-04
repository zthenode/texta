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
//   File: cNetworkAddressInterface.hpp
//
// Author: $author$
//   Date: 4/5/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CNETWORKADDRESSINTERFACE_HPP) || defined(CNETWORKADDRESSINTERFACE_MEMBERS_ONLY)
#if !defined(_CNETWORKADDRESSINTERFACE_HPP) && !defined(CNETWORKADDRESSINTERFACE_MEMBERS_ONLY)
#define _CNETWORKADDRESSINTERFACE_HPP
#endif // !defined(_CNETWORKADDRESSINTERFACE_HPP) && !defined(CNETWORKADDRESSINTERFACE_MEMBERS_ONLY) 

#if !defined(CNETWORKADDRESSINTERFACE_MEMBERS_ONLY)
#include "cInterfaceBase.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cNetworkInterfaceImplements
//
//  Author: $author$
//    Date: 4/5/2011
///////////////////////////////////////////////////////////////////////
typedef cInterfaceBase
cNetworkInterfaceImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cNetworkAddressInterface
//
// Author: $author$
//   Date: 4/5/2011
///////////////////////////////////////////////////////////////////////
class c_INTERFACE_CLASS cNetworkAddressInterface
: virtual public cNetworkInterfaceImplements
{
public:
    typedef cNetworkInterfaceImplements cImplements;
#else // !defined(CNETWORKADDRESSINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CNETWORKADDRESSINTERFACE_MEMBERS_ONLY) 

#if !defined(CNETWORKADDRESSINTERFACE_MEMBERS_ONLY)
// include cNetworkAddress member functions interface
 
#define CNETWORKADDRESS_MEMBERS_ONLY
#define CNETWORKADDRESS_MEMBER_FUNCS_INTERFACE
#include "cNetworkAddress.hpp"
#undef CNETWORKADDRESS_MEMBER_FUNCS_INTERFACE
#undef CNETWORKADDRESS_MEMBERS_ONLY
};

#if !defined(CNETWORKADDRESSIMPLEMENT_MEMBERS_ONLY)
///////////////////////////////////////////////////////////////////////
//  Class: cNetworkAddressImplement
//
// Author: $author$
//   Date: 4/5/2011
///////////////////////////////////////////////////////////////////////
class c_IMPLEMENT_CLASS cNetworkAddressImplement
: virtual public cNetworkAddressInterface
{
public:
    typedef cNetworkAddressInterface cImplements;
#else // !defined(CNETWORKADDRESSIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CNETWORKADDRESSIMPLEMENT_MEMBERS_ONLY) 

#if !defined(CNETWORKADDRESSIMPLEMENT_MEMBERS_ONLY)
// include cNetworkAddress interface member definitions

#define CNETWORKADDRESSINTERFACE_MEMBERS_ONLY
#include "cNetworkAddressInterface.hpp"
#undef CNETWORKADDRESSINTERFACE_MEMBERS_ONLY

// include cNetworkAddress member functions implement

#define CNETWORKADDRESS_MEMBERS_ONLY
#define CNETWORKADDRESS_MEMBER_FUNCS_IMPLEMENT
#include "cNetworkAddress.hpp"
#undef CNETWORKADDRESS_MEMBER_FUNCS_IMPLEMENT
#undef CNETWORKADDRESS_MEMBERS_ONLY
};
#else // !defined(CNETWORKADDRESSIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CNETWORKADDRESSIMPLEMENT_MEMBERS_ONLY) 

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CNETWORKADDRESSINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CNETWORKADDRESSINTERFACE_MEMBERS_ONLY) 

#endif // !defined(_CNETWORKADDRESSINTERFACE_HPP) || defined(CNETWORKADDRESSINTERFACE_MEMBERS_ONLY) 
        

