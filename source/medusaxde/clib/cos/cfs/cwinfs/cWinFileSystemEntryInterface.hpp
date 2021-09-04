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
//   File: cWinFileSystemEntryInterface.hpp
//
// Author: $author$
//   Date: 8/1/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CWINFILESYSTEMENTRYINTERFACE_HPP) || defined(CWINFILESYSTEMENTRYINTERFACE_MEMBERS_ONLY)
#if !defined(_CWINFILESYSTEMENTRYINTERFACE_HPP) && !defined(CWINFILESYSTEMENTRYINTERFACE_MEMBERS_ONLY)
#define _CWINFILESYSTEMENTRYINTERFACE_HPP
#endif // !defined(_CWINFILESYSTEMENTRYINTERFACE_HPP) && !defined(CWINFILESYSTEMENTRYINTERFACE_MEMBERS_ONLY) 

#if !defined(CWINFILESYSTEMENTRYINTERFACE_MEMBERS_ONLY)
#include "cFileSystemEntryInterface.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cWinFileSystemEntryInterfaceImplements
//
//  Author: $author$
//    Date: 8/1/2011
///////////////////////////////////////////////////////////////////////
typedef cFileSystemEntryInterface
cWinFileSystemEntryInterfaceImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cWinFileSystemEntryInterface
//
// Author: $author$
//   Date: 8/1/2011
///////////////////////////////////////////////////////////////////////
class c_INTERFACE_CLASS cWinFileSystemEntryInterface
: virtual public cWinFileSystemEntryInterfaceImplements
{
public:
    typedef cWinFileSystemEntryInterfaceImplements cImplements;
#else // !defined(CWINFILESYSTEMENTRYINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CWINFILESYSTEMENTRYINTERFACE_MEMBERS_ONLY) 

#if !defined(CWINFILESYSTEMENTRYINTERFACE_MEMBERS_ONLY)
// include cWinFileSystemEntry member functions interface
//
#define CWINFILESYSTEMENTRY_MEMBERS_ONLY
#define CWINFILESYSTEMENTRY_MEMBER_FUNCS_INTERFACE
#include "cWinFileSystemEntry.hpp"
#undef CWINFILESYSTEMENTRY_MEMBER_FUNCS_INTERFACE
#undef CWINFILESYSTEMENTRY_MEMBERS_ONLY
};

#if !defined(CWINFILESYSTEMENTRYIMPLEMENT_MEMBERS_ONLY)
///////////////////////////////////////////////////////////////////////
// Typedef: cWinFileSystemEntryImplementImplements
//
//  Author: $author$
//    Date: 8/1/2011
///////////////////////////////////////////////////////////////////////
typedef cFileSystemEntryImplement
cWinFileSystemEntryImplementImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cWinFileSystemEntryImplement
//
// Author: $author$
//   Date: 8/1/2011
///////////////////////////////////////////////////////////////////////
class c_IMPLEMENT_CLASS cWinFileSystemEntryImplement
: virtual public cWinFileSystemEntryInterface,
  virtual public cWinFileSystemEntryImplementImplements
{
public:
    //typedef cWinFileSystemEntryInterface cImplements;
    typedef cWinFileSystemEntryImplementImplements cImplements;
#else // !defined(CWINFILESYSTEMENTRYIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CWINFILESYSTEMENTRYIMPLEMENT_MEMBERS_ONLY) 

#if !defined(CWINFILESYSTEMENTRYIMPLEMENT_MEMBERS_ONLY)
// include cWinFileSystemEntry member functions implement
//
#define CWINFILESYSTEMENTRY_MEMBERS_ONLY
#define CWINFILESYSTEMENTRY_MEMBER_FUNCS_IMPLEMENT
#include "cWinFileSystemEntry.hpp"
#undef CWINFILESYSTEMENTRY_MEMBER_FUNCS_IMPLEMENT
#undef CWINFILESYSTEMENTRY_MEMBERS_ONLY
};
#else // !defined(CWINFILESYSTEMENTRYIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CWINFILESYSTEMENTRYIMPLEMENT_MEMBERS_ONLY) 

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CWINFILESYSTEMENTRYINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CWINFILESYSTEMENTRYINTERFACE_MEMBERS_ONLY) 

#endif // !defined(_CWINFILESYSTEMENTRYINTERFACE_HPP) || defined(CWINFILESYSTEMENTRYINTERFACE_MEMBERS_ONLY) 
        

