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
//   File: cXttpServletInterface.hpp
//
// Author: $author$
//   Date: 10/15/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CXTTPSERVLETINTERFACE_HPP) || defined(CXTTPSERVLETINTERFACE_MEMBERS_ONLY)
#if !defined(_CXTTPSERVLETINTERFACE_HPP) && !defined(CXTTPSERVLETINTERFACE_MEMBERS_ONLY)
#define _CXTTPSERVLETINTERFACE_HPP
#endif // !defined(_CXTTPSERVLETINTERFACE_HPP) && !defined(CXTTPSERVLETINTERFACE_MEMBERS_ONLY) 

#if !defined(CXTTPSERVLETINTERFACE_MEMBERS_ONLY)
#include "cGenericServletInterface.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cXttpServletInterfaceImplements
//
//  Author: $author$
//    Date: 10/15/2011
///////////////////////////////////////////////////////////////////////
typedef cGenericServletInterface
cXttpServletInterfaceImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cXttpServletInterface
//
// Author: $author$
//   Date: 10/15/2011
///////////////////////////////////////////////////////////////////////
class c_INTERFACE_CLASS cXttpServletInterface
: virtual public cXttpServletInterfaceImplements
{
public:
    typedef cXttpServletInterfaceImplements cImplements;
#else // !defined(CXTTPSERVLETINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CXTTPSERVLETINTERFACE_MEMBERS_ONLY) 

#if !defined(CXTTPSERVLETINTERFACE_MEMBERS_ONLY)
// include cXttpServlet member functions interface
//
#define CXTTPSERVLET_MEMBERS_ONLY
#define CXTTPSERVLET_MEMBER_FUNCS_INTERFACE
#include "cXttpServlet.hpp"
#undef CXTTPSERVLET_MEMBER_FUNCS_INTERFACE
#undef CXTTPSERVLET_MEMBERS_ONLY
};

#if !defined(CXTTPSERVLETIMPLEMENT_MEMBERS_ONLY)
///////////////////////////////////////////////////////////////////////
//  Class: cXttpServletImplement
//
// Author: $author$
//   Date: 10/15/2011
///////////////////////////////////////////////////////////////////////
class c_IMPLEMENT_CLASS cXttpServletImplement
: virtual public cXttpServletInterface,
  virtual public cGenericServletImplement
{
public:
    typedef cXttpServletInterface cImplements;
    //typedef cGenericServletImplement cImplements;
#else // !defined(CXTTPSERVLETIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CXTTPSERVLETIMPLEMENT_MEMBERS_ONLY) 

#if !defined(CXTTPSERVLETIMPLEMENT_MEMBERS_ONLY)
// include cXttpServlet member functions implement
//
#define CXTTPSERVLET_MEMBERS_ONLY
#define CXTTPSERVLET_MEMBER_FUNCS_IMPLEMENT
#include "cXttpServlet.hpp"
#undef CXTTPSERVLET_MEMBER_FUNCS_IMPLEMENT
#undef CXTTPSERVLET_MEMBERS_ONLY
};
#else // !defined(CXTTPSERVLETIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CXTTPSERVLETIMPLEMENT_MEMBERS_ONLY) 


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CXTTPSERVLETINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CXTTPSERVLETINTERFACE_MEMBERS_ONLY) 

#endif // !defined(_CXTTPSERVLETINTERFACE_HPP) || defined(CXTTPSERVLETINTERFACE_MEMBERS_ONLY) 
        

