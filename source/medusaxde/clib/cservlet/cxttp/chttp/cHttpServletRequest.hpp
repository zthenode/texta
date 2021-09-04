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
//   File: cHttpServletRequest.hpp
//
// Author: $author$
//   Date: 10/26/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CHTTPSERVLETREQUEST_HPP) || defined(CHTTPSERVLETREQUEST_MEMBERS_ONLY)
#if !defined(_CHTTPSERVLETREQUEST_HPP) && !defined(CHTTPSERVLETREQUEST_MEMBERS_ONLY)
#define _CHTTPSERVLETREQUEST_HPP
#endif // !defined(_CHTTPSERVLETREQUEST_HPP) && !defined(CHTTPSERVLETREQUEST_MEMBERS_ONLY) 

#if !defined(CHTTPSERVLETREQUEST_MEMBERS_ONLY)
#include "cHttpServletRequestInterface.hpp"
#include "cInstanceBase.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cHttpServletRequestExtend
//
//  Author: $author$
//    Date: 10/26/2011
///////////////////////////////////////////////////////////////////////
typedef cInstanceBase
cHttpServletRequestExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cHttpServletRequest
//
// Author: $author$
//   Date: 10/26/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cHttpServletRequest
: virtual public cHttpServletRequestImplement,
  public cHttpServletRequestExtend
{
public:
    typedef cHttpServletRequestImplement cImplements;
    typedef cHttpServletRequestExtend cExtends;
    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cHttpServletRequest
    //
    //       Author: $author$
    //         Date: 10/26/2011
    ///////////////////////////////////////////////////////////////////////
    cHttpServletRequest()
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cHttpServletRequest
    //
    //      Author: $author$
    //        Date: 10/26/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cHttpServletRequest()
    {
    }
#else // !defined(CHTTPSERVLETREQUEST_MEMBERS_ONLY) 
#endif // !defined(CHTTPSERVLETREQUEST_MEMBERS_ONLY) 

#if !defined(CHTTPSERVLETREQUEST_MEMBERS_ONLY)
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CHTTPSERVLETREQUEST_MEMBERS_ONLY) 
#endif // !defined(CHTTPSERVLETREQUEST_MEMBERS_ONLY) 

#endif // !defined(_CHTTPSERVLETREQUEST_HPP) || defined(CHTTPSERVLETREQUEST_MEMBERS_ONLY) 
        

