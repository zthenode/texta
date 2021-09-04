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
//   File: cIpSocketAddressInterface.hpp
//
// Author: $author$
//   Date: 4/5/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CIPSOCKETADDRESSINTERFACE_HPP) || defined(CIPSOCKETADDRESSINTERFACE_MEMBERS_ONLY)
#if !defined(_CIPSOCKETADDRESSINTERFACE_HPP) && !defined(CIPSOCKETADDRESSINTERFACE_MEMBERS_ONLY)
#define _CIPSOCKETADDRESSINTERFACE_HPP
#endif // !defined(_CIPSOCKETADDRESSINTERFACE_HPP) && !defined(CIPSOCKETADDRESSINTERFACE_MEMBERS_ONLY) 

#if !defined(CIPSOCKETADDRESSINTERFACE_MEMBERS_ONLY)
#include "cSocketAddressInterface.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cIpSocketAddressInterfaceImplements
//
//  Author: $author$
//    Date: 4/5/2011
///////////////////////////////////////////////////////////////////////
typedef cSocketAddressInterface
cIpSocketAddressInterfaceImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cIpSocketAddressInterface
//
// Author: $author$
//   Date: 4/5/2011
///////////////////////////////////////////////////////////////////////
class c_INTERFACE_CLASS cIpSocketAddressInterface
: virtual public cIpSocketAddressInterfaceImplements
{
public:
    typedef cIpSocketAddressInterfaceImplements cImplements;
#else // !defined(CIPSOCKETADDRESSINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CIPSOCKETADDRESSINTERFACE_MEMBERS_ONLY) 

#if !defined(CIPSOCKETADDRESSINTERFACE_MEMBERS_ONLY)
// include cIpSocketAddress member functions interface
 
#define CIPSOCKETADDRESS_MEMBERS_ONLY
#define CIPSOCKETADDRESS_MEMBER_FUNCS_INTERFACE
#include "cIpSocketAddress.hpp"
#undef CIPSOCKETADDRESS_MEMBER_FUNCS_INTERFACE
#undef CIPSOCKETADDRESS_MEMBERS_ONLY

};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CIPSOCKETADDRESSINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CIPSOCKETADDRESSINTERFACE_MEMBERS_ONLY) 

#endif // !defined(_CIPSOCKETADDRESSINTERFACE_HPP) || defined(CIPSOCKETADDRESSINTERFACE_MEMBERS_ONLY) 
        

