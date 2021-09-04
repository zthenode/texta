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
//   File: cHttpServletAcquirerInterface.hpp
//
// Author: $author$
//   Date: 10/15/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CHTTPSERVLETACQUIRERINTERFACE_HPP) || defined(CHTTPSERVLETACQUIRERINTERFACE_MEMBERS_ONLY)
#if !defined(_CHTTPSERVLETACQUIRERINTERFACE_HPP) && !defined(CHTTPSERVLETACQUIRERINTERFACE_MEMBERS_ONLY)
#define _CHTTPSERVLETACQUIRERINTERFACE_HPP
#endif // !defined(_CHTTPSERVLETACQUIRERINTERFACE_HPP) && !defined(CHTTPSERVLETACQUIRERINTERFACE_MEMBERS_ONLY) 

#if !defined(CHTTPSERVLETACQUIRERINTERFACE_MEMBERS_ONLY)
#include "cHttpServletInterface.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cHttpServletAcquirerInterfaceImplements
//
//  Author: $author$
//    Date: 10/15/2011
///////////////////////////////////////////////////////////////////////
typedef cInterfaceBase
cHttpServletAcquirerInterfaceImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cHttpServletAcquirerInterface
//
// Author: $author$
//   Date: 10/15/2011
///////////////////////////////////////////////////////////////////////
class c_INTERFACE_CLASS cHttpServletAcquirerInterface
: virtual public cHttpServletAcquirerInterfaceImplements
{
public:
    typedef cHttpServletAcquirerInterfaceImplements cImplements;
#else // !defined(CHTTPSERVLETACQUIRERINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CHTTPSERVLETACQUIRERINTERFACE_MEMBERS_ONLY) 

#if !defined(CHTTPSERVLETACQUIRERINTERFACE_MEMBERS_ONLY)
// include cHttpServletAcquirer member functions interface
//
#define CHTTPSERVLETACQUIRER_MEMBERS_ONLY
#define CHTTPSERVLETACQUIRER_MEMBER_FUNCS_INTERFACE
#include "cHttpServletAcquirer.hpp"
#undef CHTTPSERVLETACQUIRER_MEMBER_FUNCS_INTERFACE
#undef CHTTPSERVLETACQUIRER_MEMBERS_ONLY
};

#if !defined(CHTTPSERVLETACQUIRERIMPLEMENT_MEMBERS_ONLY)
///////////////////////////////////////////////////////////////////////
//  Class: cHttpServletAcquirerImplement
//
// Author: $author$
//   Date: 10/15/2011
///////////////////////////////////////////////////////////////////////
class c_IMPLEMENT_CLASS cHttpServletAcquirerImplement
: virtual public cHttpServletAcquirerInterface
{
public:
    typedef cHttpServletAcquirerInterface cImplements;
#else // !defined(CHTTPSERVLETACQUIRERIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CHTTPSERVLETACQUIRERIMPLEMENT_MEMBERS_ONLY) 

#if !defined(CHTTPSERVLETACQUIRERIMPLEMENT_MEMBERS_ONLY)
// include cHttpServletAcquirer member functions implement
//
#define CHTTPSERVLETACQUIRER_MEMBERS_ONLY
#define CHTTPSERVLETACQUIRER_MEMBER_FUNCS_IMPLEMENT
#include "cHttpServletAcquirer.hpp"
#undef CHTTPSERVLETACQUIRER_MEMBER_FUNCS_IMPLEMENT
#undef CHTTPSERVLETACQUIRER_MEMBERS_ONLY
};
#else // !defined(CHTTPSERVLETACQUIRERIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CHTTPSERVLETACQUIRERIMPLEMENT_MEMBERS_ONLY) 

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CHTTPSERVLETACQUIRERINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CHTTPSERVLETACQUIRERINTERFACE_MEMBERS_ONLY) 

#endif // !defined(_CHTTPSERVLETACQUIRERINTERFACE_HPP) || defined(CHTTPSERVLETACQUIRERINTERFACE_MEMBERS_ONLY) 
        

