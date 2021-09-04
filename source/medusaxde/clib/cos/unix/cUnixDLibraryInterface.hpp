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
//   File: cUnixDLibraryInterface.hpp
//
// Author: $author$
//   Date: 10/13/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CUNIXDLIBRARYINTERFACE_HPP) || defined(CUNIXDLIBRARYINTERFACE_MEMBERS_ONLY)
#if !defined(_CUNIXDLIBRARYINTERFACE_HPP) && !defined(CUNIXDLIBRARYINTERFACE_MEMBERS_ONLY)
#define _CUNIXDLIBRARYINTERFACE_HPP
#endif // !defined(_CUNIXDLIBRARYINTERFACE_HPP) && !defined(CUNIXDLIBRARYINTERFACE_MEMBERS_ONLY) 

#if !defined(CUNIXDLIBRARYINTERFACE_MEMBERS_ONLY)
#include "cDLibraryInterface.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cUnixDLibraryInterfaceImplements
//
//  Author: $author$
//    Date: 10/13/2011
///////////////////////////////////////////////////////////////////////
typedef cDLibraryInterface
cUnixDLibraryInterfaceImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cUnixDLibraryInterface
//
// Author: $author$
//   Date: 10/13/2011
///////////////////////////////////////////////////////////////////////
class c_INTERFACE_CLASS cUnixDLibraryInterface
: virtual public cUnixDLibraryInterfaceImplements
{
public:
    typedef cUnixDLibraryInterfaceImplements cImplements;
#else // !defined(CUNIXDLIBRARYINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CUNIXDLIBRARYINTERFACE_MEMBERS_ONLY) 

#if !defined(CUNIXDLIBRARYINTERFACE_MEMBERS_ONLY)
// include cUnixDLibrary member functions interface
//
#define CUNIXDLIBRARY_MEMBERS_ONLY
#define CUNIXDLIBRARY_MEMBER_FUNCS_INTERFACE
#include "cUnixDLibrary.hpp"
#undef CUNIXDLIBRARY_MEMBER_FUNCS_INTERFACE
#undef CUNIXDLIBRARY_MEMBERS_ONLY
};

#if !defined(CUNIXDLIBRARYIMPLEMENT_MEMBERS_ONLY)
///////////////////////////////////////////////////////////////////////
//  Class: cUnixDLibraryImplement
//
// Author: $author$
//   Date: 10/13/2011
///////////////////////////////////////////////////////////////////////
class c_IMPLEMENT_CLASS cUnixDLibraryImplement
: virtual public cUnixDLibraryInterface
{
public:
    typedef cUnixDLibraryInterface cImplements;
#else // !defined(CUNIXDLIBRARYIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CUNIXDLIBRARYIMPLEMENT_MEMBERS_ONLY) 

#if !defined(CUNIXDLIBRARYIMPLEMENT_MEMBERS_ONLY)
// include cUnixDLibrary member functions implement
//
#define CUNIXDLIBRARY_MEMBERS_ONLY
#define CUNIXDLIBRARY_MEMBER_FUNCS_IMPLEMENT
#include "cUnixDLibrary.hpp"
#undef CUNIXDLIBRARY_MEMBER_FUNCS_IMPLEMENT
#undef CUNIXDLIBRARY_MEMBERS_ONLY
};
#else // !defined(CUNIXDLIBRARYIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CUNIXDLIBRARYIMPLEMENT_MEMBERS_ONLY) 

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CUNIXDLIBRARYINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CUNIXDLIBRARYINTERFACE_MEMBERS_ONLY) 

#endif // !defined(_CUNIXDLIBRARYINTERFACE_HPP) || defined(CUNIXDLIBRARYINTERFACE_MEMBERS_ONLY) 
        

