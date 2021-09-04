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
//   File: cDLibraryMainInterface.hpp
//
// Author: $author$
//   Date: 10/16/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CDLIBRARYMAININTERFACE_HPP) || defined(CDLIBRARYMAININTERFACE_MEMBERS_ONLY)
#if !defined(_CDLIBRARYMAININTERFACE_HPP) && !defined(CDLIBRARYMAININTERFACE_MEMBERS_ONLY)
#define _CDLIBRARYMAININTERFACE_HPP
#endif // !defined(_CDLIBRARYMAININTERFACE_HPP) && !defined(CDLIBRARYMAININTERFACE_MEMBERS_ONLY) 

#if !defined(CDLIBRARYMAININTERFACE_MEMBERS_ONLY)
#include "cInterfaceBase.hpp"

#define USE_UNIX_DLIBRARY_API

#if defined(WINDOWS) 
// Windows 
#if !defined(USE_WINDOWS_DLIBRARY_API) && !defined(USE_UNIX_DLIBRARY_API)
// Use Windows API 
#define USE_WINDOWS_DLIBRARY_API
#endif // !defined(USE_WINDOWS_DLIBRARY_API) && !defined(USE_UNIX_DLIBRARY_API)
#else // defined(WINDOWS) 
// Unix 
#if !defined(USE_UNIX_DLIBRARY_API) && !defined(USE_WINDOWS_DLIBRARY_API) 
// Use Unix API 
#define USE_WINDOWS_DLIBRARY_API
#endif // !defined(USE_UNIX_DLIBRARY_API) && !defined(USE_WINDOWS_DLIBRARY_API) 
#endif // defined(WINDOWS) 

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cDLibraryMainInterfaceImplements
//
//  Author: $author$
//    Date: 10/16/2011
///////////////////////////////////////////////////////////////////////
typedef cInterfaceBase
cDLibraryMainInterfaceImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cDLibraryMainInterface
//
// Author: $author$
//   Date: 10/16/2011
///////////////////////////////////////////////////////////////////////
class c_INTERFACE_CLASS cDLibraryMainInterface
: virtual public cDLibraryMainInterfaceImplements
{
public:
    typedef cDLibraryMainInterfaceImplements cImplements;
#else // !defined(CDLIBRARYMAININTERFACE_MEMBERS_ONLY) 
#endif // !defined(CDLIBRARYMAININTERFACE_MEMBERS_ONLY) 

#if !defined(CDLIBRARYMAININTERFACE_MEMBERS_ONLY)
// include cDLibraryMainBase member functions interface
//
#define CDLIBRARYMAINBASE_MEMBERS_ONLY
#define CDLIBRARYMAINBASE_MEMBER_FUNCS_INTERFACE
#include "cDLibraryMainBase.hpp"
#undef CDLIBRARYMAINBASE_MEMBER_FUNCS_INTERFACE
#undef CDLIBRARYMAINBASE_MEMBERS_ONLY
};

#if !defined(CDLIBRARYMAINIMPLEMENT_MEMBERS_ONLY)
///////////////////////////////////////////////////////////////////////
//  Class: cDLibraryMainImplement
//
// Author: $author$
//   Date: 10/16/2011
///////////////////////////////////////////////////////////////////////
class c_IMPLEMENT_CLASS cDLibraryMainImplement
: virtual public cDLibraryMainInterface
{
public:
    typedef cDLibraryMainInterface cImplements;
#else // !defined(CDLIBRARYMAINIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CDLIBRARYMAINIMPLEMENT_MEMBERS_ONLY) 

#if !defined(CDLIBRARYMAINIMPLEMENT_MEMBERS_ONLY)
// include cDLibraryMainBase member functions implement
//
#define CDLIBRARYMAINBASE_MEMBERS_ONLY
#define CDLIBRARYMAINBASE_MEMBER_FUNCS_IMPLEMENT
#include "cDLibraryMainBase.hpp"
#undef CDLIBRARYMAINBASE_MEMBER_FUNCS_IMPLEMENT
#undef CDLIBRARYMAINBASE_MEMBERS_ONLY
};
#else // !defined(CDLIBRARYMAINIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CDLIBRARYMAINIMPLEMENT_MEMBERS_ONLY) 

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CDLIBRARYMAININTERFACE_MEMBERS_ONLY) 
#endif // !defined(CDLIBRARYMAININTERFACE_MEMBERS_ONLY) 

#endif // !defined(_CDLIBRARYMAININTERFACE_HPP) || defined(CDLIBRARYMAININTERFACE_MEMBERS_ONLY) 
        

