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
//   File: cHttpServletDLibraryInterface.hpp
//
// Author: $author$
//   Date: 10/27/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CHTTPSERVLETDLIBRARYINTERFACE_HPP) || defined(CHTTPSERVLETDLIBRARYINTERFACE_MEMBERS_ONLY)
#if !defined(_CHTTPSERVLETDLIBRARYINTERFACE_HPP) && !defined(CHTTPSERVLETDLIBRARYINTERFACE_MEMBERS_ONLY)
#define _CHTTPSERVLETDLIBRARYINTERFACE_HPP
#endif // !defined(_CHTTPSERVLETDLIBRARYINTERFACE_HPP) && !defined(CHTTPSERVLETDLIBRARYINTERFACE_MEMBERS_ONLY) 

#if !defined(CHTTPSERVLETDLIBRARYINTERFACE_MEMBERS_ONLY)
#include "cDLibraryInterface.hpp"
#include "cHttpServletAcquirerInterface.hpp"

#define GET_HTTP_SERVLET_ACQUIRER GetHttpServletAcquirer
#define GET_HTTP_SERVLET_ACQUIRER_SYMBOL \
    DLIBRARY_SYMBOL(GET_HTTP_SERVLET_ACQUIRER)

#if defined(c_NAMESPACE)
using namespace c_NAMESPACE;
#endif // defined(c_NAMESPACE) 

extern "C" 
{
///////////////////////////////////////////////////////////////////////
// Typedef: fGetHttpServletAcquirer
//
//  Author: $author$
//    Date: 10/27/2011
///////////////////////////////////////////////////////////////////////
typedef PLATFORM_EXPORT cHttpServletAcquirerInterface*
fGetHttpServletAcquirer();
///////////////////////////////////////////////////////////////////////
// Function: GET_HTTP_SERVLET_ACQUIRER
//
//   Author: $author$
//     Date: 10/27/2011
///////////////////////////////////////////////////////////////////////
PLATFORM_EXPORT cHttpServletAcquirerInterface*
GET_HTTP_SERVLET_ACQUIRER();
} // extern "C"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cHttpServletDLibraryInterfaceImplements
//
//  Author: $author$
//    Date: 10/27/2011
///////////////////////////////////////////////////////////////////////
typedef cDLibraryInterface
cHttpServletDLibraryInterfaceImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cHttpServletDLibraryInterface
//
// Author: $author$
//   Date: 10/27/2011
///////////////////////////////////////////////////////////////////////
class c_INTERFACE_CLASS cHttpServletDLibraryInterface
: virtual public cHttpServletDLibraryInterfaceImplements
{
public:
    typedef cHttpServletDLibraryInterfaceImplements cImplements;
#else // !defined(CHTTPSERVLETDLIBRARYINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CHTTPSERVLETDLIBRARYINTERFACE_MEMBERS_ONLY) 

#if !defined(CHTTPSERVLETDLIBRARYINTERFACE_MEMBERS_ONLY)
// include cHttpServletDLibrary member functions interface
//
#define CHTTPSERVLETDLIBRARY_MEMBERS_ONLY
#define CHTTPSERVLETDLIBRARY_MEMBER_FUNCS_INTERFACE
#include "cHttpServletDLibrary.hpp"
#undef CHTTPSERVLETDLIBRARY_MEMBER_FUNCS_INTERFACE
#undef CHTTPSERVLETDLIBRARY_MEMBERS_ONLY
};

#if !defined(CHTTPSERVLETDLIBRARYIMPLEMENT_MEMBERS_ONLY)
///////////////////////////////////////////////////////////////////////
//  Class: cHttpServletDLibraryImplement
//
// Author: $author$
//   Date: 10/27/2011
///////////////////////////////////////////////////////////////////////
class c_IMPLEMENT_CLASS cHttpServletDLibraryImplement
: virtual public cHttpServletDLibraryInterface
{
public:
    typedef cHttpServletDLibraryInterface cImplements;
#else // !defined(CHTTPSERVLETDLIBRARYIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CHTTPSERVLETDLIBRARYIMPLEMENT_MEMBERS_ONLY) 

#if !defined(CHTTPSERVLETDLIBRARYIMPLEMENT_MEMBERS_ONLY)
// include cHttpServletDLibrary member functions implement
//
#define CHTTPSERVLETDLIBRARY_MEMBERS_ONLY
#define CHTTPSERVLETDLIBRARY_MEMBER_FUNCS_IMPLEMENT
#include "cHttpServletDLibrary.hpp"
#undef CHTTPSERVLETDLIBRARY_MEMBER_FUNCS_IMPLEMENT
#undef CHTTPSERVLETDLIBRARY_MEMBERS_ONLY
};
#else // !defined(CHTTPSERVLETDLIBRARYIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CHTTPSERVLETDLIBRARYIMPLEMENT_MEMBERS_ONLY) 

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CHTTPSERVLETDLIBRARYINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CHTTPSERVLETDLIBRARYINTERFACE_MEMBERS_ONLY) 

#endif // !defined(_CHTTPSERVLETDLIBRARYINTERFACE_HPP) || defined(CHTTPSERVLETDLIBRARYINTERFACE_MEMBERS_ONLY) 
        

