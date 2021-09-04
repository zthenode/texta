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
//   File: cHttpContentInterface.hpp
//
// Author: $author$
//   Date: 11/1/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CHTTPCONTENTINTERFACE_HPP) || defined(CHTTPCONTENTINTERFACE_MEMBERS_ONLY)
#if !defined(_CHTTPCONTENTINTERFACE_HPP) && !defined(CHTTPCONTENTINTERFACE_MEMBERS_ONLY)
#define _CHTTPCONTENTINTERFACE_HPP
#endif // !defined(_CHTTPCONTENTINTERFACE_HPP) && !defined(CHTTPCONTENTINTERFACE_MEMBERS_ONLY) 

#if !defined(CHTTPCONTENTINTERFACE_MEMBERS_ONLY)
#include "cInterfaceBase.hpp"
#include "cString.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cHttpContentInterfaceImplements
//
//  Author: $author$
//    Date: 11/1/2011
///////////////////////////////////////////////////////////////////////
typedef cInterfaceBase
cHttpContentInterfaceImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cHttpContentInterface
//
// Author: $author$
//   Date: 11/1/2011
///////////////////////////////////////////////////////////////////////
class c_INTERFACE_CLASS cHttpContentInterface
: virtual public cHttpContentInterfaceImplements
{
public:
    typedef cHttpContentInterfaceImplements cImplements;
#else // !defined(CHTTPCONTENTINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CHTTPCONTENTINTERFACE_MEMBERS_ONLY) 

#if !defined(CHTTPCONTENTINTERFACE_MEMBERS_ONLY)
// include cHttpContent member functions interface
//
#define CHTTPCONTENT_MEMBERS_ONLY
#define CHTTPCONTENT_MEMBER_FUNCS_INTERFACE
#include "cHttpContent.hpp"
#undef CHTTPCONTENT_MEMBER_FUNCS_INTERFACE
#undef CHTTPCONTENT_MEMBERS_ONLY
};

#if !defined(CHTTPCONTENTIMPLEMENT_MEMBERS_ONLY)
///////////////////////////////////////////////////////////////////////
//  Class: cHttpContentImplement
//
// Author: $author$
//   Date: 11/1/2011
///////////////////////////////////////////////////////////////////////
class c_IMPLEMENT_CLASS cHttpContentImplement
: virtual public cHttpContentInterface
{
public:
    typedef cHttpContentInterface cImplements;
#else // !defined(CHTTPCONTENTIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CHTTPCONTENTIMPLEMENT_MEMBERS_ONLY) 

#if !defined(CHTTPCONTENTIMPLEMENT_MEMBERS_ONLY)
// include cHttpContent member functions implement
//
#define CHTTPCONTENT_MEMBERS_ONLY
#define CHTTPCONTENT_MEMBER_FUNCS_IMPLEMENT
#include "cHttpContent.hpp"
#undef CHTTPCONTENT_MEMBER_FUNCS_IMPLEMENT
#undef CHTTPCONTENT_MEMBERS_ONLY
};
#else // !defined(CHTTPCONTENTIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CHTTPCONTENTIMPLEMENT_MEMBERS_ONLY) 

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CHTTPCONTENTINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CHTTPCONTENTINTERFACE_MEMBERS_ONLY) 

#endif // !defined(_CHTTPCONTENTINTERFACE_HPP) || defined(CHTTPCONTENTINTERFACE_MEMBERS_ONLY) 
        

