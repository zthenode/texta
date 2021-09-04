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
//   File: cIpV4SocketAddress.hpp
//
// Author: $author$
//   Date: 4/6/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CIPV4SOCKETADDRESS_HPP) || defined(CIPV4SOCKETADDRESS_MEMBERS_ONLY)
#if !defined(_CIPV4SOCKETADDRESS_HPP) && !defined(CIPV4SOCKETADDRESS_MEMBERS_ONLY)
#define _CIPV4SOCKETADDRESS_HPP
#endif // !defined(_CIPV4SOCKETADDRESS_HPP) && !defined(CIPV4SOCKETADDRESS_MEMBERS_ONLY) 

#if !defined(CIPV4SOCKETADDRESS_MEMBERS_ONLY)
#include "cIpV4SocketAddressInterface.hpp"
#include "cIpSocketAddress.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cIpV4SocketAddressExtend
//
//  Author: $author$
//    Date: 4/6/2011
///////////////////////////////////////////////////////////////////////
typedef cIpSocketAddress
cIpV4SocketAddressExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cIpV4SocketAddress
//
// Author: $author$
//   Date: 4/6/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cIpV4SocketAddress
: virtual public cIpV4SocketAddressImplement,
  public cIpV4SocketAddressExtend
{
public:
    typedef cIpV4SocketAddressImplement cImplements;
    typedef cIpV4SocketAddressExtend cExtends;
    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cIpV4SocketAddress
    //
    //       Author: $author$
    //         Date: 4/6/2011
    ///////////////////////////////////////////////////////////////////////
    cIpV4SocketAddress()
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cIpV4SocketAddress
    //
    //      Author: $author$
    //        Date: 4/6/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cIpV4SocketAddress()
    {
    }
#else // !defined(CIPV4SOCKETADDRESS_MEMBERS_ONLY) 
#endif // !defined(CIPV4SOCKETADDRESS_MEMBERS_ONLY) 

#if !defined(CIPV4SOCKETADDRESS_MEMBERS_ONLY)
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CIPV4SOCKETADDRESS_MEMBERS_ONLY) 
#endif // !defined(CIPV4SOCKETADDRESS_MEMBERS_ONLY) 

#endif // !defined(_CIPV4SOCKETADDRESS_HPP) || defined(CIPV4SOCKETADDRESS_MEMBERS_ONLY) 
        

