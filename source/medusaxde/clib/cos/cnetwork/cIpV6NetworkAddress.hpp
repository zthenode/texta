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
//   File: cIpV6NetworkAddress.hpp
//
// Author: $author$
//   Date: 4/5/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CIPV6NETWORKADDRESS_HPP) || defined(CIPV6NETWORKADDRESS_MEMBERS_ONLY)
#if !defined(_CIPV6NETWORKADDRESS_HPP) && !defined(CIPV6NETWORKADDRESS_MEMBERS_ONLY)
#define _CIPV6NETWORKADDRESS_HPP
#endif // !defined(_CIPV6NETWORKADDRESS_HPP) && !defined(CIPV6NETWORKADDRESS_MEMBERS_ONLY) 

#if !defined(CIPV6NETWORKADDRESS_MEMBERS_ONLY)
#include "cIpNetworkAddressInterface.hpp"
#include "cIpNetworkAddress.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cIpV6NetworkAddressExtend
//
//  Author: $author$
//    Date: 4/5/2011
///////////////////////////////////////////////////////////////////////
typedef cIpNetworkAddress
cIpV6NetworkAddressExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cIpV6NetworkAddress
//
// Author: $author$
//   Date: 4/5/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cIpV6NetworkAddress
: virtual public cIpV6NetworkAddressImplement,
  public cIpV6NetworkAddressExtend
{
public:
    typedef cIpV6NetworkAddressImplement cImplements;
    typedef cIpV6NetworkAddressExtend cExtends;
    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cIpV6NetworkAddress
    //
    //       Author: $author$
    //         Date: 4/5/2011
    ///////////////////////////////////////////////////////////////////////
    cIpV6NetworkAddress()
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cIpV6NetworkAddress
    //
    //      Author: $author$
    //        Date: 4/5/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cIpV6NetworkAddress()
    {
    }
#else // !defined(CIPV6NETWORKADDRESS_MEMBERS_ONLY) 
#endif // !defined(CIPV6NETWORKADDRESS_MEMBERS_ONLY) 

#if !defined(CIPV6NETWORKADDRESS_MEMBERS_ONLY)
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CIPV6NETWORKADDRESS_MEMBERS_ONLY) 
#endif // !defined(CIPV6NETWORKADDRESS_MEMBERS_ONLY) 

#endif // !defined(_CIPV6NETWORKADDRESS_HPP) || defined(CIPV6NETWORKADDRESS_MEMBERS_ONLY) 
        

