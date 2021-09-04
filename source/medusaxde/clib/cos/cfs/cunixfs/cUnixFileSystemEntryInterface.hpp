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
//   File: cUnixFileSystemEntryInterface.hpp
//
// Author: $author$
//   Date: 8/24/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CUNIXFILESYSTEMENTRYINTERFACE_HPP) || defined(CUNIXFILESYSTEMENTRYINTERFACE_MEMBERS_ONLY)
#if !defined(_CUNIXFILESYSTEMENTRYINTERFACE_HPP) && !defined(CUNIXFILESYSTEMENTRYINTERFACE_MEMBERS_ONLY)
#define _CUNIXFILESYSTEMENTRYINTERFACE_HPP
#endif // !defined(_CUNIXFILESYSTEMENTRYINTERFACE_HPP) && !defined(CUNIXFILESYSTEMENTRYINTERFACE_MEMBERS_ONLY) 

#if !defined(CUNIXFILESYSTEMENTRYINTERFACE_MEMBERS_ONLY)
#include "cFileSystemEntryInterface.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cUnixFileSystemEntryInterfaceImplements
//
//  Author: $author$
//    Date: 8/24/2011
///////////////////////////////////////////////////////////////////////
typedef cFileSystemEntryInterface
cUnixFileSystemEntryInterfaceImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cUnixFileSystemEntryInterface
//
// Author: $author$
//   Date: 8/24/2011
///////////////////////////////////////////////////////////////////////
class c_INTERFACE_CLASS cUnixFileSystemEntryInterface
: virtual public cUnixFileSystemEntryInterfaceImplements
{
public:
    typedef cUnixFileSystemEntryInterfaceImplements cImplements;
#else // !defined(CUNIXFILESYSTEMENTRYINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CUNIXFILESYSTEMENTRYINTERFACE_MEMBERS_ONLY) 

#if !defined(CUNIXFILESYSTEMENTRYINTERFACE_MEMBERS_ONLY)
// include cUnixFileSystemEntry member functions interface
//
#define CUNIXFILESYSTEMENTRY_MEMBERS_ONLY
#define CUNIXFILESYSTEMENTRY_MEMBER_FUNCS_INTERFACE
#include "cUnixFileSystemEntry.hpp"
#undef CUNIXFILESYSTEMENTRY_MEMBER_FUNCS_INTERFACE
#undef CUNIXFILESYSTEMENTRY_MEMBERS_ONLY
};

#if !defined(CUNIXFILESYSTEMENTRYIMPLEMENT_MEMBERS_ONLY)
///////////////////////////////////////////////////////////////////////
// Typedef: cUnixFileSystemEntryImplementImplements
//
//  Author: $author$
//    Date: 8/24/2011
///////////////////////////////////////////////////////////////////////
typedef cFileSystemEntryImplement
cUnixFileSystemEntryImplementImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cUnixFileSystemEntryImplement
//
// Author: $author$
//   Date: 8/24/2011
///////////////////////////////////////////////////////////////////////
class c_IMPLEMENT_CLASS cUnixFileSystemEntryImplement
: virtual public cUnixFileSystemEntryInterface,
  virtual public cUnixFileSystemEntryImplementImplements
{
public:
    //typedef cUnixFileSystemEntryInterface cImplements;
    typedef cUnixFileSystemEntryImplementImplements cImplements;
#else // !defined(CUNIXFILESYSTEMENTRYIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CUNIXFILESYSTEMENTRYIMPLEMENT_MEMBERS_ONLY) 

#if !defined(CUNIXFILESYSTEMENTRYIMPLEMENT_MEMBERS_ONLY)
// include cUnixFileSystemEntry member functions implement
// 
#define CUNIXFILESYSTEMENTRY_MEMBERS_ONLY
#define CUNIXFILESYSTEMENTRY_MEMBER_FUNCS_IMPLEMENT
#include "cUnixFileSystemEntry.hpp"
#undef CUNIXFILESYSTEMENTRY_MEMBER_FUNCS_IMPLEMENT
#undef CUNIXFILESYSTEMENTRY_MEMBERS_ONLY
};
#else // !defined(CUNIXFILESYSTEMENTRYIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CUNIXFILESYSTEMENTRYIMPLEMENT_MEMBERS_ONLY) 

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CUNIXFILESYSTEMENTRYINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CUNIXFILESYSTEMENTRYINTERFACE_MEMBERS_ONLY) 

#endif // !defined(_CUNIXFILESYSTEMENTRYINTERFACE_HPP) || defined(CUNIXFILESYSTEMENTRYINTERFACE_MEMBERS_ONLY) 
        

