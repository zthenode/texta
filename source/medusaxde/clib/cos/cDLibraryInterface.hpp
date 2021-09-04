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
//   File: cDLibraryInterface.hpp
//
// Author: $author$
//   Date: 10/13/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CDLIBRARYINTERFACE_HPP) || defined(CDLIBRARYINTERFACE_MEMBERS_ONLY)
#if !defined(_CDLIBRARYINTERFACE_HPP) && !defined(CDLIBRARYINTERFACE_MEMBERS_ONLY)
#define _CDLIBRARYINTERFACE_HPP
#endif // !defined(_CDLIBRARYINTERFACE_HPP) && !defined(CDLIBRARYINTERFACE_MEMBERS_ONLY) 

#if !defined(CDLIBRARYINTERFACE_MEMBERS_ONLY)
#include "cplatform_dlibrary.hpp"
#include "cInterfaceBase.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cDLibraryInterfaceImplements
//
//  Author: $author$
//    Date: 10/13/2011
///////////////////////////////////////////////////////////////////////
typedef cInterfaceBase
cDLibraryInterfaceImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cDLibraryInterface
//
// Author: $author$
//   Date: 10/13/2011
///////////////////////////////////////////////////////////////////////
class c_INTERFACE_CLASS cDLibraryInterface
: virtual public cDLibraryInterfaceImplements
{
public:
    typedef cDLibraryInterfaceImplements cImplements;
#else // !defined(CDLIBRARYINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CDLIBRARYINTERFACE_MEMBERS_ONLY) 

#if !defined(CDLIBRARYINTERFACE_MEMBERS_ONLY)
// include cDLibraryBase member functions interface
//
#define CDLIBRARYBASE_MEMBERS_ONLY
#define CDLIBRARYBASE_MEMBER_FUNCS_INTERFACE
#include "cDLibraryBase.hpp"
#undef CDLIBRARYBASE_MEMBER_FUNCS_INTERFACE
#undef CDLIBRARYBASE_MEMBERS_ONLY
};

#if !defined(CDLIBRARYIMPLEMENT_MEMBERS_ONLY)
///////////////////////////////////////////////////////////////////////
//  Class: cDLibraryImplement
//
// Author: $author$
//   Date: 10/13/2011
///////////////////////////////////////////////////////////////////////
class c_IMPLEMENT_CLASS cDLibraryImplement
: virtual public cDLibraryInterface
{
public:
    typedef cDLibraryInterface cImplements;
#else // !defined(CDLIBRARYIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CDLIBRARYIMPLEMENT_MEMBERS_ONLY) 

#if !defined(CDLIBRARYIMPLEMENT_MEMBERS_ONLY)
// include cDLibraryBase member functions implement
//
#define CDLIBRARYBASE_MEMBERS_ONLY
#define CDLIBRARYBASE_MEMBER_FUNCS_IMPLEMENT
#include "cDLibraryBase.hpp"
#undef CDLIBRARYBASE_MEMBER_FUNCS_IMPLEMENT
#undef CDLIBRARYBASE_MEMBERS_ONLY
};
#else // !defined(CDLIBRARYIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CDLIBRARYIMPLEMENT_MEMBERS_ONLY) 

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CDLIBRARYINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CDLIBRARYINTERFACE_MEMBERS_ONLY) 

#endif // !defined(_CDLIBRARYINTERFACE_HPP) || defined(CDLIBRARYINTERFACE_MEMBERS_ONLY) 
        

