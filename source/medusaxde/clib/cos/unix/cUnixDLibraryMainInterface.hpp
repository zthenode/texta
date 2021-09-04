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
//   File: cUnixDLibraryMainInterface.hpp
//
// Author: $author$
//   Date: 10/16/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CUNIXDLIBRARYMAININTERFACE_HPP) || defined(CUNIXDLIBRARYMAININTERFACE_MEMBERS_ONLY)
#if !defined(_CUNIXDLIBRARYMAININTERFACE_HPP) && !defined(CUNIXDLIBRARYMAININTERFACE_MEMBERS_ONLY)
#define _CUNIXDLIBRARYMAININTERFACE_HPP
#endif // !defined(_CUNIXDLIBRARYMAININTERFACE_HPP) && !defined(CUNIXDLIBRARYMAININTERFACE_MEMBERS_ONLY) 

#if !defined(CUNIXDLIBRARYMAININTERFACE_MEMBERS_ONLY)
#include "cDLibraryMainInterface.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cUnixDLibraryMainInterfaceImplements
//
//  Author: $author$
//    Date: 10/16/2011
///////////////////////////////////////////////////////////////////////
typedef cDLibraryMainInterface
cUnixDLibraryMainInterfaceImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cUnixDLibraryMainInterface
//
// Author: $author$
//   Date: 10/16/2011
///////////////////////////////////////////////////////////////////////
class c_INTERFACE_CLASS cUnixDLibraryMainInterface
: virtual public cUnixDLibraryMainInterfaceImplements
{
public:
    typedef cUnixDLibraryMainInterfaceImplements cImplements;
#else // !defined(CUNIXDLIBRARYMAININTERFACE_MEMBERS_ONLY) 
#endif // !defined(CUNIXDLIBRARYMAININTERFACE_MEMBERS_ONLY) 

#if !defined(CUNIXDLIBRARYMAININTERFACE_MEMBERS_ONLY)
// include cUnixDLibraryMain member functions interface
//
#define CUNIXDLIBRARYMAIN_MEMBERS_ONLY
#define CUNIXDLIBRARYMAIN_MEMBER_FUNCS_INTERFACE
#include "cUnixDLibraryMain.hpp"
#undef CUNIXDLIBRARYMAIN_MEMBER_FUNCS_INTERFACE
#undef CUNIXDLIBRARYMAIN_MEMBERS_ONLY
};

#if !defined(CUNIXDLIBRARYMAINIMPLEMENT_MEMBERS_ONLY)
///////////////////////////////////////////////////////////////////////
//  Class: cUnixDLibraryMainImplement
//
// Author: $author$
//   Date: 10/16/2011
///////////////////////////////////////////////////////////////////////
class c_IMPLEMENT_CLASS cUnixDLibraryMainImplement
: virtual public cUnixDLibraryMainInterface
{
public:
    typedef cUnixDLibraryMainInterface cImplements;
#else // !defined(CUNIXDLIBRARYMAINIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CUNIXDLIBRARYMAINIMPLEMENT_MEMBERS_ONLY) 

#if !defined(CUNIXDLIBRARYMAINIMPLEMENT_MEMBERS_ONLY)
// include cUnixDLibraryMain member functions implement
//
#define CUNIXDLIBRARYMAIN_MEMBERS_ONLY
#define CUNIXDLIBRARYMAIN_MEMBER_FUNCS_IMPLEMENT
#include "cUnixDLibraryMain.hpp"
#undef CUNIXDLIBRARYMAIN_MEMBER_FUNCS_IMPLEMENT
#undef CUNIXDLIBRARYMAIN_MEMBERS_ONLY
};
#else // !defined(CUNIXDLIBRARYMAINIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CUNIXDLIBRARYMAINIMPLEMENT_MEMBERS_ONLY) 

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CUNIXDLIBRARYMAININTERFACE_MEMBERS_ONLY) 
#endif // !defined(CUNIXDLIBRARYMAININTERFACE_MEMBERS_ONLY) 

#endif // !defined(_CUNIXDLIBRARYMAININTERFACE_HPP) || defined(CUNIXDLIBRARYMAININTERFACE_MEMBERS_ONLY) 
        

