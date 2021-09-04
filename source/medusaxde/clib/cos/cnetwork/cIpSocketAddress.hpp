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
//   File: cIpSocketAddress.hpp
//
// Author: $author$
//   Date: 4/6/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CIPSOCKETADDRESS_HPP) || defined(CIPSOCKETADDRESS_MEMBERS_ONLY)
#if !defined(_CIPSOCKETADDRESS_HPP) && !defined(CIPSOCKETADDRESS_MEMBERS_ONLY)
#define _CIPSOCKETADDRESS_HPP
#endif // !defined(_CIPSOCKETADDRESS_HPP) && !defined(CIPSOCKETADDRESS_MEMBERS_ONLY) 

#if !defined(CIPSOCKETADDRESS_MEMBERS_ONLY)
#include "cIpSocketAddressInterface.hpp"
#include "cIpNetworkAddress.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cIpSocketAddressExtend
//
//  Author: $author$
//    Date: 4/6/2011
///////////////////////////////////////////////////////////////////////
typedef cSocketAddress
cIpSocketAddressExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cIpSocketAddress
//
// Author: $author$
//   Date: 4/6/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cIpSocketAddress
: virtual public cIpSocketAddressImplement,
  public cIpSocketAddressExtend
{
public:
    typedef cIpSocketAddressImplement cImplements;
    typedef cIpSocketAddressExtend cExtends;
    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cIpSocketAddress
    //
    //       Author: $author$
    //         Date: 4/6/2011
    ///////////////////////////////////////////////////////////////////////
    cIpSocketAddress()
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cIpSocketAddress
    //
    //      Author: $author$
    //        Date: 4/6/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cIpSocketAddress()
    {
    }
#else // !defined(CIPSOCKETADDRESS_MEMBERS_ONLY) 
#endif // !defined(CIPSOCKETADDRESS_MEMBERS_ONLY) 

#if !defined(CIPSOCKETADDRESS_MEMBERS_ONLY)
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CIPSOCKETADDRESS_MEMBERS_ONLY) 
#endif // !defined(CIPSOCKETADDRESS_MEMBERS_ONLY) 

#endif // !defined(_CIPSOCKETADDRESS_HPP) || defined(CIPSOCKETADDRESS_MEMBERS_ONLY) 
        

