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
//   File: cHttpServletInterface.hpp
//
// Author: $author$
//   Date: 10/15/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CHTTPSERVLETINTERFACE_HPP) || defined(CHTTPSERVLETINTERFACE_MEMBERS_ONLY)
#if !defined(_CHTTPSERVLETINTERFACE_HPP) && !defined(CHTTPSERVLETINTERFACE_MEMBERS_ONLY)
#define _CHTTPSERVLETINTERFACE_HPP
#endif // !defined(_CHTTPSERVLETINTERFACE_HPP) && !defined(CHTTPSERVLETINTERFACE_MEMBERS_ONLY) 

#if !defined(CHTTPSERVLETINTERFACE_MEMBERS_ONLY)
#include "cXttpServletInterface.hpp"
#include "cHttpServletRequestInterface.hpp"
#include "cHttpServletResponseInterface.hpp"
#include "cHttpRequestMethod.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cHttpServletInterfaceImplements
//
//  Author: $author$
//    Date: 10/15/2011
///////////////////////////////////////////////////////////////////////
typedef cXttpServletInterface
cHttpServletInterfaceImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cHttpServletInterface
//
// Author: $author$
//   Date: 10/15/2011
///////////////////////////////////////////////////////////////////////
class c_INTERFACE_CLASS cHttpServletInterface
: virtual public cHttpServletInterfaceImplements
{
public:
    typedef cHttpServletInterfaceImplements cImplements;
#else // !defined(CHTTPSERVLETINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CHTTPSERVLETINTERFACE_MEMBERS_ONLY) 

#if !defined(CHTTPSERVLETINTERFACE_MEMBERS_ONLY)
// include cHttpServlet member functions interface
//
#define CHTTPSERVLET_MEMBERS_ONLY
#define CHTTPSERVLET_MEMBER_FUNCS_INTERFACE
#include "cHttpServlet.hpp"
#undef CHTTPSERVLET_MEMBER_FUNCS_INTERFACE
#undef CHTTPSERVLET_MEMBERS_ONLY
};

#if !defined(CHTTPSERVLETIMPLEMENT_MEMBERS_ONLY)
///////////////////////////////////////////////////////////////////////
//  Class: cHttpServletImplement
//
// Author: $author$
//   Date: 10/15/2011
///////////////////////////////////////////////////////////////////////
class c_IMPLEMENT_CLASS cHttpServletImplement
: virtual public cHttpServletInterface,
  virtual public cXttpServletImplement
{
public:
    typedef cHttpServletInterface cImplements;
    //typedef cXttpServletImplement cImplements;
#else // !defined(CHTTPSERVLETIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CHTTPSERVLETIMPLEMENT_MEMBERS_ONLY) 

#if !defined(CHTTPSERVLETIMPLEMENT_MEMBERS_ONLY)
// include cHttpServlet member functions implement
//
#define CHTTPSERVLET_MEMBERS_ONLY
#define CHTTPSERVLET_MEMBER_FUNCS_IMPLEMENT
#include "cHttpServlet.hpp"
#undef CHTTPSERVLET_MEMBER_FUNCS_IMPLEMENT
#undef CHTTPSERVLET_MEMBERS_ONLY
};
#else // !defined(CHTTPSERVLETIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CHTTPSERVLETIMPLEMENT_MEMBERS_ONLY) 

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CHTTPSERVLETINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CHTTPSERVLETINTERFACE_MEMBERS_ONLY) 

#endif // !defined(_CHTTPSERVLETINTERFACE_HPP) || defined(CHTTPSERVLETINTERFACE_MEMBERS_ONLY) 
        

