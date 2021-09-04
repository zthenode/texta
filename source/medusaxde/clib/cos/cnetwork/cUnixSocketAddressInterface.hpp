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
//   File: cUnixSocketAddressInterface.hpp
//
// Author: $author$
//   Date: 4/5/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CUNIXSOCKETADDRESSINTERFACE_HPP) || defined(CUNIXSOCKETADDRESSINTERFACE_MEMBERS_ONLY)
#if !defined(_CUNIXSOCKETADDRESSINTERFACE_HPP) && !defined(CUNIXSOCKETADDRESSINTERFACE_MEMBERS_ONLY)
#define _CUNIXSOCKETADDRESSINTERFACE_HPP
#endif // !defined(_CUNIXSOCKETADDRESSINTERFACE_HPP) && !defined(CUNIXSOCKETADDRESSINTERFACE_MEMBERS_ONLY) 

#if !defined(CUNIXSOCKETADDRESSINTERFACE_MEMBERS_ONLY)
#include "cSocketAddressInterface.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cUnixSocketAddressInterfaceImplements
//
//  Author: $author$
//    Date: 4/5/2011
///////////////////////////////////////////////////////////////////////
typedef cSocketAddressInterface
cUnixSocketAddressInterfaceImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cUnixSocketAddressInterface
//
// Author: $author$
//   Date: 4/5/2011
///////////////////////////////////////////////////////////////////////
class c_INTERFACE_CLASS cUnixSocketAddressInterface
: virtual public cUnixSocketAddressInterfaceImplements
{
public:
    typedef cUnixSocketAddressInterfaceImplements cImplements;
#else // !defined(CUNIXSOCKETADDRESSINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CUNIXSOCKETADDRESSINTERFACE_MEMBERS_ONLY) 

#if !defined(CUNIXSOCKETADDRESSINTERFACE_MEMBERS_ONLY)
// include cUnixSocketAddress member functions interface
 
#define CUNIXSOCKETADDRESS_MEMBERS_ONLY
#define CUNIXSOCKETADDRESS_MEMBER_FUNCS_INTERFACE
#include "cUnixSocketAddress.hpp"
#undef CUNIXSOCKETADDRESS_MEMBER_FUNCS_INTERFACE
#undef CUNIXSOCKETADDRESS_MEMBERS_ONLY

};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CUNIXSOCKETADDRESSINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CUNIXSOCKETADDRESSINTERFACE_MEMBERS_ONLY) 

#endif // !defined(_CUNIXSOCKETADDRESSINTERFACE_HPP) || defined(CUNIXSOCKETADDRESSINTERFACE_MEMBERS_ONLY) �
�
8
�
��
        

