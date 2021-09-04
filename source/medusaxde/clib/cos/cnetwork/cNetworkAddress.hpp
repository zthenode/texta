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
//   File: cNetworkAddress.hpp
//
// Author: $author$
//   Date: 4/5/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CNETWORKADDRESS_HPP) || defined(CNETWORKADDRESS_MEMBERS_ONLY)
#if !defined(_CNETWORKADDRESS_HPP) && !defined(CNETWORKADDRESS_MEMBERS_ONLY)
#define _CNETWORKADDRESS_HPP
#endif // !defined(_CNETWORKADDRESS_HPP) && !defined(CNETWORKADDRESS_MEMBERS_ONLY) 

#if !defined(CNETWORKADDRESS_MEMBERS_ONLY)
#include "cNetworkAddressInterface.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cNetworkAddressExtend
//
//  Author: $author$
//    Date: 4/5/2011
///////////////////////////////////////////////////////////////////////
typedef cInstanceBase
cNetworkAddressExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cNetworkAddress
//
// Author: $author$
//   Date: 4/5/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cNetworkAddress
: virtual public cNetworkAddressImplement,
  public cNetworkAddressExtend
{
public:
    typedef cNetworkAddressImplement cImplements;
    typedef cNetworkAddressExtend cExtends;
    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cNetworkAddress
    //
    //       Author: $author$
    //         Date: 4/5/2011
    ///////////////////////////////////////////////////////////////////////
    cNetworkAddress()
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cNetworkAddress
    //
    //      Author: $author$
    //        Date: 4/5/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cNetworkAddress()
    {
    }
#else // !defined(CNETWORKADDRESS_MEMBERS_ONLY) 
#endif // !defined(CNETWORKADDRESS_MEMBERS_ONLY) 

#if !defined(CNETWORKADDRESS_MEMBERS_ONLY)
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CNETWORKADDRESS_MEMBERS_ONLY) 
#endif // !defined(CNETWORKADDRESS_MEMBERS_ONLY) 

#endif // !defined(_CNETWORKADDRESS_HPP) || defined(CNETWORKADDRESS_MEMBERS_ONLY) 
        

