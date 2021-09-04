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
//   File: cUnixNetworkAddress.hpp
//
// Author: $author$
//   Date: 4/5/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CUNIXNETWORKADDRESS_HPP) || defined(CUNIXNETWORKADDRESS_MEMBERS_ONLY)
#if !defined(_CUNIXNETWORKADDRESS_HPP) && !defined(CUNIXNETWORKADDRESS_MEMBERS_ONLY)
#define _CUNIXNETWORKADDRESS_HPP
#endif // !defined(_CUNIXNETWORKADDRESS_HPP) && !defined(CUNIXNETWORKADDRESS_MEMBERS_ONLY) 

#if !defined(CUNIXNETWORKADDRESS_MEMBERS_ONLY)
#include "cUnixNetworkAddressInterface.hpp"
#include "cNetworkAddress.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cUnixNetworkAddressExtend
//
//  Author: $author$
//    Date: 4/5/2011
///////////////////////////////////////////////////////////////////////
typedef cNetworkAddress
cUnixNetworkAddressExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cUnixNetworkAddress
//
// Author: $author$
//   Date: 4/5/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cUnixNetworkAddress
: virtual public cUnixNetworkAddressImplement,
  public cUnixNetworkAddressExtend
{
public:
    typedef cUnixNetworkAddressImplement cImplements;
    typedef cUnixNetworkAddressExtend cExtends;
    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cUnixNetworkAddress
    //
    //       Author: $author$
    //         Date: 4/5/2011
    ///////////////////////////////////////////////////////////////////////
    cUnixNetworkAddress()
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cUnixNetworkAddress
    //
    //      Author: $author$
    //        Date: 4/5/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cUnixNetworkAddress()
    {
    }
#else // !defined(CUNIXNETWORKADDRESS_MEMBERS_ONLY) 
#endif // !defined(CUNIXNETWORKADDRESS_MEMBERS_ONLY) 

#if !defined(CUNIXNETWORKADDRESS_MEMBERS_ONLY)
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CUNIXNETWORKADDRESS_MEMBERS_ONLY) 
#endif // !defined(CUNIXNETWORKADDRESS_MEMBERS_ONLY) 

#endif // !defined(_CUNIXNETWORKADDRESS_HPP) || defined(CUNIXNETWORKADDRESS_MEMBERS_ONLY) 
        

