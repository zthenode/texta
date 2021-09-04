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
//   File: cXttpServlet.hpp
//
// Author: $author$
//   Date: 10/15/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CXTTPSERVLET_HPP) || defined(CXTTPSERVLET_MEMBERS_ONLY)
#if !defined(_CXTTPSERVLET_HPP) && !defined(CXTTPSERVLET_MEMBERS_ONLY)
#define _CXTTPSERVLET_HPP
#endif // !defined(_CXTTPSERVLET_HPP) && !defined(CXTTPSERVLET_MEMBERS_ONLY) 

#if !defined(CXTTPSERVLET_MEMBERS_ONLY)
#include "cXttpServletInterface.hpp"
#include "cGenericServlet.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cXttpServletExtend
//
//  Author: $author$
//    Date: 10/15/2011
///////////////////////////////////////////////////////////////////////
typedef cGenericServlet
cXttpServletExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cXttpServlet
//
// Author: $author$
//   Date: 10/15/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cXttpServlet
: virtual public cXttpServletImplement,
  public cXttpServletExtend
{
public:
    typedef cXttpServletImplement cImplements;
    typedef cXttpServletExtend cExtends;
    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cXttpServlet
    //
    //       Author: $author$
    //         Date: 10/15/2011
    ///////////////////////////////////////////////////////////////////////
    cXttpServlet()
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cXttpServlet
    //
    //      Author: $author$
    //        Date: 10/15/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cXttpServlet()
    {
    }
#else // !defined(CXTTPSERVLET_MEMBERS_ONLY) 
#endif // !defined(CXTTPSERVLET_MEMBERS_ONLY) 

#if !defined(CXTTPSERVLET_MEMBERS_ONLY)
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CXTTPSERVLET_MEMBERS_ONLY) 
#endif // !defined(CXTTPSERVLET_MEMBERS_ONLY) 

#endif // !defined(_CXTTPSERVLET_HPP) || defined(CXTTPSERVLET_MEMBERS_ONLY) 
        

