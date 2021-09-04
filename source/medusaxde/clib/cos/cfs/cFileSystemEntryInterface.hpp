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
//   File: cFileSystemEntryInterface.hpp
//
// Author: $author$
//   Date: 7/30/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CFILESYSTEMENTRYINTERFACE_HPP) || defined(CFILESYSTEMENTRYINTERFACE_MEMBERS_ONLY)
#if !defined(_CFILESYSTEMENTRYINTERFACE_HPP) && !defined(CFILESYSTEMENTRYINTERFACE_MEMBERS_ONLY)
#define _CFILESYSTEMENTRYINTERFACE_HPP
#endif // !defined(_CFILESYSTEMENTRYINTERFACE_HPP) && !defined(CFILESYSTEMENTRYINTERFACE_MEMBERS_ONLY) 

#if !defined(CFILESYSTEMENTRYINTERFACE_MEMBERS_ONLY)
#include "cFileSystemEntryType.hpp"
#include "cInterfaceBase.hpp"
#include "cImplementBase.hpp"
#include "cString.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cFileSystemEntryInterfaceImplements
//
//  Author: $author$
//    Date: 7/30/2011
///////////////////////////////////////////////////////////////////////
typedef cInterfaceBase
cFileSystemEntryInterfaceImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cFileSystemEntryInterface
//
// Author: $author$
//   Date: 7/30/2011
///////////////////////////////////////////////////////////////////////
class c_INTERFACE_CLASS cFileSystemEntryInterface
: virtual public cFileSystemEntryInterfaceImplements
{
public:
    typedef cFileSystemEntryInterfaceImplements cImplements;
#else // !defined(CFILESYSTEMENTRYINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CFILESYSTEMENTRYINTERFACE_MEMBERS_ONLY) 

#if !defined(CFILESYSTEMENTRYINTERFACE_MEMBERS_ONLY)
// include cFileSystemEntry member functions interface
//
#define CFILESYSTEMENTRYBASE_MEMBERS_ONLY
#define CFILESYSTEMENTRYBASE_MEMBER_FUNCS_INTERFACE
#include "cFileSystemEntryBase.hpp"
#undef CFILESYSTEMENTRYBASE_MEMBER_FUNCS_INTERFACE
#undef CFILESYSTEMENTRYBASE_MEMBERS_ONLY
};

#if !defined(CFILESYSTEMENTRYIMPLEMENT_MEMBERS_ONLY)
///////////////////////////////////////////////////////////////////////
// Typedef: cFileSystemEntryImplementImplements
//
//  Author: $author$
//    Date: 7/30/2011
///////////////////////////////////////////////////////////////////////
typedef cImplementBase
cFileSystemEntryImplementImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cFileSystemEntryImplement
//
// Author: $author$
//   Date: 7/30/2011
///////////////////////////////////////////////////////////////////////
class c_IMPLEMENT_CLASS cFileSystemEntryImplement
: virtual public cFileSystemEntryInterface,
  virtual public cFileSystemEntryImplementImplements
{
public:
    //typedef cFileSystemEntryInterface cImplements;
    typedef cFileSystemEntryImplementImplements cImplements;
#else // !defined(CFILESYSTEMENTRYIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CFILESYSTEMENTRYIMPLEMENT_MEMBERS_ONLY) 

#if !defined(CFILESYSTEMENTRYIMPLEMENT_MEMBERS_ONLY)
// include cFileSystemEntry member functions implement
//
#define CFILESYSTEMENTRYBASE_MEMBERS_ONLY
#define CFILESYSTEMENTRYBASE_MEMBER_FUNCS_IMPLEMENT
#include "cFileSystemEntryBase.hpp"
#undef CFILESYSTEMENTRYBASE_MEMBER_FUNCS_IMPLEMENT
#undef CFILESYSTEMENTRYBASE_MEMBERS_ONLY
};
#else // !defined(CFILESYSTEMENTRYIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CFILESYSTEMENTRYIMPLEMENT_MEMBERS_ONLY) 

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CFILESYSTEMENTRYINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CFILESYSTEMENTRYINTERFACE_MEMBERS_ONLY) 

#endif // !defined(_CFILESYSTEMENTRYINTERFACE_HPP) || defined(CFILESYSTEMENTRYINTERFACE_MEMBERS_ONLY) 
