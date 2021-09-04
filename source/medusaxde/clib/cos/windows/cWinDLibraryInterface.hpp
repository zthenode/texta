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
//   File: cWinDLibraryInterface.hpp
//
// Author: $author$
//   Date: 10/13/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CWINDLIBRARYINTERFACE_HPP) || defined(CWINDLIBRARYINTERFACE_MEMBERS_ONLY)
#if !defined(_CWINDLIBRARYINTERFACE_HPP) && !defined(CWINDLIBRARYINTERFACE_MEMBERS_ONLY)
#define _CWINDLIBRARYINTERFACE_HPP
#endif // !defined(_CWINDLIBRARYINTERFACE_HPP) && !defined(CWINDLIBRARYINTERFACE_MEMBERS_ONLY) 

#if !defined(CWINDLIBRARYINTERFACE_MEMBERS_ONLY)
#include "cDLibraryInterface.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cWinDLibraryInterfaceImplements
//
//  Author: $author$
//    Date: 10/13/2011
///////////////////////////////////////////////////////////////////////
typedef cDLibraryInterface
cWinDLibraryInterfaceImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cWinDLibraryInterface
//
// Author: $author$
//   Date: 10/13/2011
///////////////////////////////////////////////////////////////////////
class c_INTERFACE_CLASS cWinDLibraryInterface
: virtual public cWinDLibraryInterfaceImplements
{
public:
    typedef cWinDLibraryInterfaceImplements cImplements;
#else // !defined(CWINDLIBRARYINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CWINDLIBRARYINTERFACE_MEMBERS_ONLY) 

#if !defined(CWINDLIBRARYINTERFACE_MEMBERS_ONLY)
// include cWinDLibrary member functions interface
//
#define CWINDLIBRARY_MEMBERS_ONLY
#define CWINDLIBRARY_MEMBER_FUNCS_INTERFACE
#include "cWinDLibrary.hpp"
#undef CWINDLIBRARY_MEMBER_FUNCS_INTERFACE
#undef CWINDLIBRARY_MEMBERS_ONLY
};

#if !defined(CWINDLIBRARYIMPLEMENT_MEMBERS_ONLY)
///////////////////////////////////////////////////////////////////////
//  Class: cWinDLibraryImplement
//
// Author: $author$
//   Date: 10/13/2011
///////////////////////////////////////////////////////////////////////
class c_IMPLEMENT_CLASS cWinDLibraryImplement
: virtual public cWinDLibraryInterface
{
public:
    typedef cWinDLibraryInterface cImplements;
#else // !defined(CWINDLIBRARYIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CWINDLIBRARYIMPLEMENT_MEMBERS_ONLY) 

#if !defined(CWINDLIBRARYIMPLEMENT_MEMBERS_ONLY)
// include cWinDLibrary member functions implement
//
#define CWINDLIBRARY_MEMBERS_ONLY
#define CWINDLIBRARY_MEMBER_FUNCS_IMPLEMENT
#include "cWinDLibrary.hpp"
#undef CWINDLIBRARY_MEMBER_FUNCS_IMPLEMENT
#undef CWINDLIBRARY_MEMBERS_ONLY
};
#else // !defined(CWINDLIBRARYIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CWINDLIBRARYIMPLEMENT_MEMBERS_ONLY) 

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CWINDLIBRARYINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CWINDLIBRARYINTERFACE_MEMBERS_ONLY) 

#endif // !defined(_CWINDLIBRARYINTERFACE_HPP) || defined(CWINDLIBRARYINTERFACE_MEMBERS_ONLY) 
        

