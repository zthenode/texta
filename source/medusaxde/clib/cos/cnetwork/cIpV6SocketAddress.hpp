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
//   File: cIpV6SocketAddress.hpp
//
// Author: $author$
//   Date: 4/6/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CIPV6SOCKETADDRESS_HPP) || defined(CIPV6SOCKETADDRESS_MEMBERS_ONLY)
#if !defined(_CIPV6SOCKETADDRESS_HPP) && !defined(CIPV6SOCKETADDRESS_MEMBERS_ONLY)
#define _CIPV6SOCKETADDRESS_HPP
#endif // !defined(_CIPV6SOCKETADDRESS_HPP) && !defined(CIPV6SOCKETADDRESS_MEMBERS_ONLY) 

#if !defined(CIPV6SOCKETADDRESS_MEMBERS_ONLY)
#include "cIpV6SocketAddressInterface.hpp"
#include "cIpSocketAddress.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cIpV6SocketAddressExtend
//
//  Author: $author$
//    Date: 4/6/2011
///////////////////////////////////////////////////////////////////////
typedef cIpSocketAddress
cIpV6SocketAddressExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cIpV6SocketAddress
//
// Author: $author$
//   Date: 4/6/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cIpV6SocketAddress
: virtual public cIpV6SocketAddressImplement,
  public cIpV6SocketAddressExtend
{
public:
    typedef cIpV6SocketAddressImplement cImplements;
    typedef cIpV6SocketAddressExtend cExtends;
    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cIpV6SocketAddress
    //
    //       Author: $author$
    //         Date: 4/6/2011
    ///////////////////////////////////////////////////////////////////////
    cIpV6SocketAddress()
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cIpV6SocketAddress
    //
    //      Author: $author$
    //        Date: 4/6/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cIpV6SocketAddress()
    {
    }
#else // !defined(CIPV6SOCKETADDRESS_MEMBERS_ONLY) 
#endif // !defined(CIPV6SOCKETADDRESS_MEMBERS_ONLY) 

#if !defined(CIPV6SOCKETADDRESS_MEMBERS_ONLY)
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CIPV6SOCKETADDRESS_MEMBERS_ONLY) 
#endif // !defined(CIPV6SOCKETADDRESS_MEMBERS_ONLY) 

#endif // !defined(_CIPV6SOCKETADDRESS_HPP) || defined(CIPV6SOCKETADDRESS_MEMBERS_ONLY) 
        

