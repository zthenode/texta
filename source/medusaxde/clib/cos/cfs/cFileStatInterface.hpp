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
//   File: cFileStatInterface.hpp
//
// Author: $author$
//   Date: 8/24/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CFILESTATINTERFACE_HPP) || defined(CFILESTATINTERFACE_MEMBERS_ONLY)
#if !defined(_CFILESTATINTERFACE_HPP) && !defined(CFILESTATINTERFACE_MEMBERS_ONLY)
#define _CFILESTATINTERFACE_HPP
#endif // !defined(_CFILESTATINTERFACE_HPP) && !defined(CFILESTATINTERFACE_MEMBERS_ONLY) 

#if !defined(CFILESTATINTERFACE_MEMBERS_ONLY)
#include "cplatform_stat.h"
#include "cInterfaceBase.hpp"
#include "cImplementBase.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cFileStatInterfaceImplements
//
//  Author: $author$
//    Date: 8/24/2011
///////////////////////////////////////////////////////////////////////
typedef cInterfaceBase
cFileStatInterfaceImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cFileStatInterface
//
// Author: $author$
//   Date: 8/24/2011
///////////////////////////////////////////////////////////////////////
class c_INTERFACE_CLASS cFileStatInterface
: virtual public cFileStatInterfaceImplements
{
public:
    typedef cFileStatInterfaceImplements cImplements;
#else // !defined(CFILESTATINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CFILESTATINTERFACE_MEMBERS_ONLY) 

#if !defined(CFILESTATINTERFACE_MEMBERS_ONLY)
// include cFileStatBase member functions interface
//
#define CFILESTATBASE_MEMBERS_ONLY
#define CFILESTATBASE_MEMBER_FUNCS_INTERFACE
#include "cFileStatBase.hpp"
#undef CFILESTATBASE_MEMBER_FUNCS_INTERFACE
#undef CFILESTATBASE_MEMBERS_ONLY
};

#if !defined(CFILESTATIMPLEMENT_MEMBERS_ONLY)
///////////////////////////////////////////////////////////////////////
// Typedef: cFileStatImplementImplements
//
//  Author: $author$
//    Date: 8/24/2011
///////////////////////////////////////////////////////////////////////
typedef cImplementBase
cFileStatImplementImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cFileStatImplement
//
// Author: $author$
//   Date: 8/24/2011
///////////////////////////////////////////////////////////////////////
class c_IMPLEMENT_CLASS cFileStatImplement
: virtual public cFileStatInterface,
  virtual public cFileStatImplementImplements
{
public:
//    typedef cFileStatInterface cImplements;
    typedef cFileStatImplementImplements cImplements;
#else // !defined(CFILESTATIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CFILESTATIMPLEMENT_MEMBERS_ONLY) 

#if !defined(CFILESTATIMPLEMENT_MEMBERS_ONLY)
// include cFileStatBase member functions implement
//
#define CFILESTATBASE_MEMBERS_ONLY
#define CFILESTATBASE_MEMBER_FUNCS_IMPLEMENT
#include "cFileStatBase.hpp"
#undef CFILESTATBASE_MEMBER_FUNCS_IMPLEMENT
#undef CFILESTATBASE_MEMBERS_ONLY
};
#else // !defined(CFILESTATIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CFILESTATIMPLEMENT_MEMBERS_ONLY) 

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CFILESTATINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CFILESTATINTERFACE_MEMBERS_ONLY) 

#endif // !defined(_CFILESTATINTERFACE_HPP) || defined(CFILESTATINTERFACE_MEMBERS_ONLY) 
