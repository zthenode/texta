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
//   File: cGenericServlet.hpp
//
// Author: $author$
//   Date: 10/15/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CGENERICSERVLET_HPP) || defined(CGENERICSERVLET_MEMBERS_ONLY)
#if !defined(_CGENERICSERVLET_HPP) && !defined(CGENERICSERVLET_MEMBERS_ONLY)
#define _CGENERICSERVLET_HPP
#endif // !defined(_CGENERICSERVLET_HPP) && !defined(CGENERICSERVLET_MEMBERS_ONLY) 

#if !defined(CGENERICSERVLET_MEMBERS_ONLY)
#include "cGenericServletInterface.hpp"
#include "cInstanceBase.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cGenericServletExtend
//
//  Author: $author$
//    Date: 10/15/2011
///////////////////////////////////////////////////////////////////////
typedef cInstanceBase
cGenericServletExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cGenericServlet
//
// Author: $author$
//   Date: 10/15/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cGenericServlet
: virtual public cGenericServletImplement,
  public cGenericServletExtend
{
public:
    typedef cGenericServletImplement cImplements;
    typedef cGenericServletExtend cExtends;
    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cGenericServlet
    //
    //       Author: $author$
    //         Date: 10/15/2011
    ///////////////////////////////////////////////////////////////////////
    cGenericServlet()
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cGenericServlet
    //
    //      Author: $author$
    //        Date: 10/15/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cGenericServlet()
    {
    }
#else // !defined(CGENERICSERVLET_MEMBERS_ONLY) 
#endif // !defined(CGENERICSERVLET_MEMBERS_ONLY) 

#if !defined(CGENERICSERVLET_MEMBERS_ONLY)
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CGENERICSERVLET_MEMBERS_ONLY) 
#endif // !defined(CGENERICSERVLET_MEMBERS_ONLY) 

#endif // !defined(_CGENERICSERVLET_HPP) || defined(CGENERICSERVLET_MEMBERS_ONLY) 
        

