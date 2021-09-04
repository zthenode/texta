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
//   File: cHttpServletDLibraryMainInterface.hpp
//
// Author: $author$
//   Date: 10/20/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CHTTPSERVLETDLIBRARYMAININTERFACE_HPP) || defined(CHTTPSERVLETDLIBRARYMAININTERFACE_MEMBERS_ONLY)
#if !defined(_CHTTPSERVLETDLIBRARYMAININTERFACE_HPP) && !defined(CHTTPSERVLETDLIBRARYMAININTERFACE_MEMBERS_ONLY)
#define _CHTTPSERVLETDLIBRARYMAININTERFACE_HPP
#endif // !defined(_CHTTPSERVLETDLIBRARYMAININTERFACE_HPP) && !defined(CHTTPSERVLETDLIBRARYMAININTERFACE_MEMBERS_ONLY) 

#if !defined(CHTTPSERVLETDLIBRARYMAININTERFACE_MEMBERS_ONLY)
#include "cDLibraryMainInterface.hpp"
#include "cHttpServletAcquirerInterface.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cHttpServletDLibraryMainInterfaceImplements
//
//  Author: $author$
//    Date: 10/20/2011
///////////////////////////////////////////////////////////////////////
typedef cDLibraryMainInterface
cHttpServletDLibraryMainInterfaceImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cHttpServletDLibraryMainInterface
//
// Author: $author$
//   Date: 10/20/2011
///////////////////////////////////////////////////////////////////////
class c_INTERFACE_CLASS cHttpServletDLibraryMainInterface
: virtual public cHttpServletDLibraryMainInterfaceImplements
{
public:
    typedef cHttpServletDLibraryMainInterfaceImplements cImplements;
#else // !defined(CHTTPSERVLETDLIBRARYMAININTERFACE_MEMBERS_ONLY) 
#endif // !defined(CHTTPSERVLETDLIBRARYMAININTERFACE_MEMBERS_ONLY) 

#if !defined(CHTTPSERVLETDLIBRARYMAININTERFACE_MEMBERS_ONLY)
// include cHttpServletDLibraryMain member functions interface
//
#define CHTTPSERVLETDLIBRARYMAIN_MEMBERS_ONLY
#define CHTTPSERVLETDLIBRARYMAIN_MEMBER_FUNCS_INTERFACE
#include "cHttpServletDLibraryMain.hpp"
#undef CHTTPSERVLETDLIBRARYMAIN_MEMBER_FUNCS_INTERFACE
#undef CHTTPSERVLETDLIBRARYMAIN_MEMBERS_ONLY
};

#if !defined(CHTTPSERVLETDLIBRARYMAINIMPLEMENT_MEMBERS_ONLY)
///////////////////////////////////////////////////////////////////////
//  Class: cHttpServletDLibraryMainImplement
//
// Author: $author$
//   Date: 10/20/2011
///////////////////////////////////////////////////////////////////////
class c_IMPLEMENT_CLASS cHttpServletDLibraryMainImplement
: virtual public cHttpServletDLibraryMainInterface,
  virtual public cDLibraryMainImplement
{
public:
    typedef cHttpServletDLibraryMainInterface cImplements;
    //typedef cDLibraryMainImplement cImplements;
#else // !defined(CHTTPSERVLETDLIBRARYMAINIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CHTTPSERVLETDLIBRARYMAINIMPLEMENT_MEMBERS_ONLY) 

#if !defined(CHTTPSERVLETDLIBRARYMAINIMPLEMENT_MEMBERS_ONLY)
// include cHttpServletDLibraryMain member functions implement
//
#define CHTTPSERVLETDLIBRARYMAIN_MEMBERS_ONLY
#define CHTTPSERVLETDLIBRARYMAIN_MEMBER_FUNCS_IMPLEMENT
#include "cHttpServletDLibraryMain.hpp"
#undef CHTTPSERVLETDLIBRARYMAIN_MEMBER_FUNCS_IMPLEMENT
#undef CHTTPSERVLETDLIBRARYMAIN_MEMBERS_ONLY
};
#else // !defined(CHTTPSERVLETDLIBRARYMAINIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CHTTPSERVLETDLIBRARYMAINIMPLEMENT_MEMBERS_ONLY) 

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CHTTPSERVLETDLIBRARYMAININTERFACE_MEMBERS_ONLY) 
#endif // !defined(CHTTPSERVLETDLIBRARYMAININTERFACE_MEMBERS_ONLY) 

#endif // !defined(_CHTTPSERVLETDLIBRARYMAININTERFACE_HPP) || defined(CHTTPSERVLETDLIBRARYMAININTERFACE_MEMBERS_ONLY) 
        

