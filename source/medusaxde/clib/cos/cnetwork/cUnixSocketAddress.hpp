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
//   File: cUnixSocketAddress.hpp
//
// Author: $author$
//   Date: 4/6/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CUNIXSOCKETADDRESS_HPP) || defined(CUNIXSOCKETADDRESS_MEMBERS_ONLY)
#if !defined(_CUNIXSOCKETADDRESS_HPP) && !defined(CUNIXSOCKETADDRESS_MEMBERS_ONLY)
#define _CUNIXSOCKETADDRESS_HPP
#endif // !defined(_CUNIXSOCKETADDRESS_HPP) && !defined(CUNIXSOCKETADDRESS_MEMBERS_ONLY) 

#if !defined(CUNIXSOCKETADDRESS_MEMBERS_ONLY)
#include "cUnixSocketAddressInterface.hpp"
#include "cSocketAddress.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cUnixSocketAddressExtend
//
//  Author: $author$
//    Date: 4/6/2011
///////////////////////////////////////////////////////////////////////
typedef cSocketAddress
cUnixSocketAddressExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cUnixSocketAddress
//
// Author: $author$
//   Date: 4/6/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cUnixSocketAddress
: virtual public cUnixSocketAddressImplement,
  public cUnixSocketAddressExtend
{
public:
    typedef cUnixSocketAddressImplement cImplements;
    typedef cUnixSocketAddressExtend cExtends;
    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cUnixSocketAddress
    //
    //       Author: $author$
    //         Date: 4/6/2011
    ///////////////////////////////////////////////////////////////////////
    cUnixSocketAddress()
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cUnixSocketAddress
    //
    //      Author: $author$
    //        Date: 4/6/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cUnixSocketAddress()
    {
    }
#else // !defined(CUNIXSOCKETADDRESS_MEMBERS_ONLY) 
#endif // !defined(CUNIXSOCKETADDRESS_MEMBERS_ONLY) 

#if !defined(CUNIXSOCKETADDRESS_MEMBERS_ONLY)
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CUNIXSOCKETADDRESS_MEMBERS_ONLY) 
#endif // !defined(CUNIXSOCKETADDRESS_MEMBERS_ONLY) 

#endif // !defined(_CUNIXSOCKETADDRESS_HPP) || defined(CUNIXSOCKETADDRESS_MEMBERS_ONLY) 
        

