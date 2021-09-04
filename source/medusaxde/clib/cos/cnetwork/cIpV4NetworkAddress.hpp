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
//   File: cIpV4NetworkAddress.hpp
//
// Author: $author$
//   Date: 4/5/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CIPV4NETWORKADDRESS_HPP) || defined(CIPV4NETWORKADDRESS_MEMBERS_ONLY)
#if !defined(_CIPV4NETWORKADDRESS_HPP) && !defined(CIPV4NETWORKADDRESS_MEMBERS_ONLY)
#define _CIPV4NETWORKADDRESS_HPP
#endif // !defined(_CIPV4NETWORKADDRESS_HPP) && !defined(CIPV4NETWORKADDRESS_MEMBERS_ONLY) 

#if !defined(CIPV4NETWORKADDRESS_MEMBERS_ONLY)
#include "cIpNetworkAddressInterface.hpp"
#include "cIpNetworkAddress.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cIpV4NetworkAddressExtend
//
//  Author: $author$
//    Date: 4/5/2011
///////////////////////////////////////////////////////////////////////
typedef cIpNetworkAddress
cIpV4NetworkAddressExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cIpV4NetworkAddress
//
// Author: $author$
//   Date: 4/5/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cIpV4NetworkAddress
: virtual public cIpV4NetworkAddressImplement,
  public cIpV4NetworkAddressExtend
{
public:
    typedef cIpV4NetworkAddressImplement cImplements;
    typedef cIpV4NetworkAddressExtend cExtends;
    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cIpV4NetworkAddress
    //
    //       Author: $author$
    //         Date: 4/5/2011
    ///////////////////////////////////////////////////////////////////////
    cIpV4NetworkAddress()
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cIpV4NetworkAddress
    //
    //      Author: $author$
    //        Date: 4/5/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cIpV4NetworkAddress()
    {
    }
#else // !defined(CIPV4NETWORKADDRESS_MEMBERS_ONLY) 
#endif // !defined(CIPV4NETWORKADDRESS_MEMBERS_ONLY) 

#if !defined(CIPV4NETWORKADDRESS_MEMBERS_ONLY)
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CIPV4NETWORKADDRESS_MEMBERS_ONLY) 
#endif // !defined(CIPV4NETWORKADDRESS_MEMBERS_ONLY) 

#endif // !defined(_CIPV4NETWORKADDRESS_HPP) || defined(CIPV4NETWORKADDRESS_MEMBERS_ONLY) 
        

