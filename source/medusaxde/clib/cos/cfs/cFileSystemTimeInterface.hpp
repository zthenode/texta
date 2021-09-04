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
//   File: cFileSystemTimeInterface.hpp
//
// Author: $author$
//   Date: 7/31/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CFILESYSTEMTIMEINTERFACE_HPP) || defined(CFILESYSTEMTIMEINTERFACE_MEMBERS_ONLY)
#if !defined(_CFILESYSTEMTIMEINTERFACE_HPP) && !defined(CFILESYSTEMTIMEINTERFACE_MEMBERS_ONLY)
#define _CFILESYSTEMTIMEINTERFACE_HPP
#endif // !defined(_CFILESYSTEMTIMEINTERFACE_HPP) && !defined(CFILESYSTEMTIMEINTERFACE_MEMBERS_ONLY) 

#if !defined(CFILESYSTEMTIMEINTERFACE_MEMBERS_ONLY)
#include "cInterfaceBase.hpp"
#include "cImplementBase.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cFileSystemTimeInterfaceImplements
//
//  Author: $author$
//    Date: 7/31/2011
///////////////////////////////////////////////////////////////////////
typedef cInterfaceBase
cFileSystemTimeInterfaceImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cFileSystemTimeInterface
//
// Author: $author$
//   Date: 7/31/2011
///////////////////////////////////////////////////////////////////////
class c_INTERFACE_CLASS cFileSystemTimeInterface
: virtual public cFileSystemTimeInterfaceImplements
{
public:
    typedef cFileSystemTimeInterfaceImplements cImplements;
#else // !defined(CFILESYSTEMTIMEINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CFILESYSTEMTIMEINTERFACE_MEMBERS_ONLY) 

#if !defined(CFILESYSTEMTIMEINTERFACE_MEMBERS_ONLY)
// include cFileSystemTimeBase member functions interface
//
#define CFILESYSTEMTIMEBASE_MEMBERS_ONLY
#define CFILESYSTEMTIMEBASE_MEMBER_FUNCS_INTERFACE
#include "cFileSystemTimeBase.hpp"
#undef CFILESYSTEMTIMEBASE_MEMBER_FUNCS_INTERFACE
#undef CFILESYSTEMTIMEBASE_MEMBERS_ONLY
};

#if !defined(CFILESYSTEMTIMEIMPLEMENT_MEMBERS_ONLY)
///////////////////////////////////////////////////////////////////////
// Typedef: cFileSystemEntryTimeImplementImplements
//
//  Author: $author$
//    Date: 7/31/2011
///////////////////////////////////////////////////////////////////////
typedef cImplementBase
cFileSystemTimeImplementImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cFileSystemTimeImplement
//
// Author: $author$
//   Date: 7/31/2011
///////////////////////////////////////////////////////////////////////
class c_IMPLEMENT_CLASS cFileSystemTimeImplement
: virtual public cFileSystemTimeInterface,
  virtual public cFileSystemTimeImplementImplements
{
public:
    //typedef cFileSystemTimeInterface cImplements;
    typedef cFileSystemTimeImplementImplements cImplements;
#else // !defined(CFILESYSTEMTIMEIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CFILESYSTEMTIMEIMPLEMENT_MEMBERS_ONLY) 

#if !defined(CFILESYSTEMTIMEIMPLEMENT_MEMBERS_ONLY)
// include cFileSystemTimeBase member functions implement
//
#define CFILESYSTEMTIMEBASE_MEMBERS_ONLY
#define CFILESYSTEMTIMEBASE_MEMBER_FUNCS_IMPLEMENT
#include "cFileSystemTimeBase.hpp"
#undef CFILESYSTEMTIMEBASE_MEMBER_FUNCS_IMPLEMENT
#undef CFILESYSTEMTIMEBASE_MEMBERS_ONLY
};
#else // !defined(CFILESYSTEMTIMEIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CFILESYSTEMTIMEIMPLEMENT_MEMBERS_ONLY) 

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CFILESYSTEMTIMEINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CFILESYSTEMTIMEINTERFACE_MEMBERS_ONLY) 

#endif // !defined(_CFILESYSTEMTIMEINTERFACE_HPP) || defined(CFILESYSTEMTIMEINTERFACE_MEMBERS_ONLY) 
