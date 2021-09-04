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
//   File: cHttpServletResponseInterface.hpp
//
// Author: $author$
//   Date: 10/26/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CHTTPSERVLETRESPONSEINTERFACE_HPP) || defined(CHTTPSERVLETRESPONSEINTERFACE_MEMBERS_ONLY)
#if !defined(_CHTTPSERVLETRESPONSEINTERFACE_HPP) && !defined(CHTTPSERVLETRESPONSEINTERFACE_MEMBERS_ONLY)
#define _CHTTPSERVLETRESPONSEINTERFACE_HPP
#endif // !defined(_CHTTPSERVLETRESPONSEINTERFACE_HPP) && !defined(CHTTPSERVLETRESPONSEINTERFACE_MEMBERS_ONLY) 

#if !defined(CHTTPSERVLETRESPONSEINTERFACE_MEMBERS_ONLY)
#include "cInterfaceBase.hpp"
#include "cHttpContentInterface.hpp"
#include "cWriterInterface.hpp"
#include "cString.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cHttpServletResponseInterfaceImplements
//
//  Author: $author$
//    Date: 10/26/2011
///////////////////////////////////////////////////////////////////////
typedef cInterfaceBase
cHttpServletResponseInterfaceImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cHttpServletResponseInterface
//
// Author: $author$
//   Date: 10/26/2011
///////////////////////////////////////////////////////////////////////
class c_INTERFACE_CLASS cHttpServletResponseInterface
: virtual public cHttpServletResponseInterfaceImplements
{
public:
    typedef cHttpServletResponseInterfaceImplements cImplements;
#else // !defined(CHTTPSERVLETRESPONSEINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CHTTPSERVLETRESPONSEINTERFACE_MEMBERS_ONLY) 

#if !defined(CHTTPSERVLETRESPONSEINTERFACE_MEMBERS_ONLY)
// include cHttpServletResponse member functions interface
//
#define CHTTPSERVLETRESPONSE_MEMBERS_ONLY
#define CHTTPSERVLETRESPONSE_MEMBER_FUNCS_INTERFACE
#include "cHttpServletResponse.hpp"
#undef CHTTPSERVLETRESPONSE_MEMBER_FUNCS_INTERFACE
#undef CHTTPSERVLETRESPONSE_MEMBERS_ONLY
};

#if !defined(CHTTPSERVLETRESPONSEIMPLEMENT_MEMBERS_ONLY)
///////////////////////////////////////////////////////////////////////
//  Class: cHttpServletResponseImplement
//
// Author: $author$
//   Date: 10/26/2011
///////////////////////////////////////////////////////////////////////
class c_IMPLEMENT_CLASS cHttpServletResponseImplement
: virtual public cHttpServletResponseInterface
{
public:
    typedef cHttpServletResponseInterface cImplements;
#else // !defined(CHTTPSERVLETRESPONSEIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CHTTPSERVLETRESPONSEIMPLEMENT_MEMBERS_ONLY) 

#if !defined(CHTTPSERVLETRESPONSEIMPLEMENT_MEMBERS_ONLY)
// include cHttpServletResponse member functions implement
//
#define CHTTPSERVLETRESPONSE_MEMBERS_ONLY
#define CHTTPSERVLETRESPONSE_MEMBER_FUNCS_IMPLEMENT
#include "cHttpServletResponse.hpp"
#undef CHTTPSERVLETRESPONSE_MEMBER_FUNCS_IMPLEMENT
#undef CHTTPSERVLETRESPONSE_MEMBERS_ONLY
};
#else // !defined(CHTTPSERVLETRESPONSEIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CHTTPSERVLETRESPONSEIMPLEMENT_MEMBERS_ONLY) 

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CHTTPSERVLETRESPONSEINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CHTTPSERVLETRESPONSEINTERFACE_MEMBERS_ONLY) 

#endif // !defined(_CHTTPSERVLETRESPONSEINTERFACE_HPP) || defined(CHTTPSERVLETRESPONSEINTERFACE_MEMBERS_ONLY) 
        

