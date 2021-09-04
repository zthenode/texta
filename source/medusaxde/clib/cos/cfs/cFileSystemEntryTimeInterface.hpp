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
//   File: cFileSystemEntryTimeInterface.hpp
//
// Author: $author$
//   Date: 7/31/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CFILESYSTEMENTRYTIMEINTERFACE_HPP) || defined(CFILESYSTEMENTRYTIMEINTERFACE_MEMBERS_ONLY)
#if !defined(_CFILESYSTEMENTRYTIMEINTERFACE_HPP) && !defined(CFILESYSTEMENTRYTIMEINTERFACE_MEMBERS_ONLY)
#define _CFILESYSTEMENTRYTIMEINTERFACE_HPP
#endif // !defined(_CFILESYSTEMENTRYTIMEINTERFACE_HPP) && !defined(CFILESYSTEMENTRYTIMEINTERFACE_MEMBERS_ONLY) 

#if !defined(CFILESYSTEMENTRYTIMEINTERFACE_MEMBERS_ONLY)
#include "cFileSystemTimeInterface.hpp"
#include "cFileSystemEntryTimeWhen.hpp"
#include "cInterfaceBase.hpp"
#include "cImplementBase.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cFileSystemEntryTimeInterfaceImplements
//
//  Author: $author$
//    Date: 7/31/2011
///////////////////////////////////////////////////////////////////////
typedef cFileSystemTimeInterface
cFileSystemEntryTimeInterfaceImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cFileSystemEntryTimeInterface
//
// Author: $author$
//   Date: 7/31/2011
///////////////////////////////////////////////////////////////////////
class c_INTERFACE_CLASS cFileSystemEntryTimeInterface
: virtual public cFileSystemEntryTimeInterfaceImplements
{
public:
    typedef cFileSystemEntryTimeInterfaceImplements cImplements;
#else // !defined(CFILESYSTEMENTRYTIMEINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CFILESYSTEMENTRYTIMEINTERFACE_MEMBERS_ONLY) 

#if !defined(CFILESYSTEMENTRYTIMEINTERFACE_MEMBERS_ONLY)
// include cFileSystemEntryTimeBase member functions interface
//
#define CFILESYSTEMENTRYTIMEBASE_MEMBERS_ONLY
#define CFILESYSTEMENTRYTIMEBASE_MEMBER_FUNCS_INTERFACE
#include "cFileSystemEntryTimeBase.hpp"
#undef CFILESYSTEMENTRYTIMEBASE_MEMBER_FUNCS_INTERFACE
#undef CFILESYSTEMENTRYTIMEBASE_MEMBERS_ONLY
};

#if !defined(CFILESYSTEMENTRYTIMEIMPLEMENT_MEMBERS_ONLY)
///////////////////////////////////////////////////////////////////////
// Typedef: cFileSystemEntryTimeImplementImplements
//
//  Author: $author$
//    Date: 7/31/2011
///////////////////////////////////////////////////////////////////////
typedef cFileSystemTimeImplement
cFileSystemEntryTimeImplementImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cFileSystemEntryTimeImplement
//
// Author: $author$
//   Date: 7/31/2011
///////////////////////////////////////////////////////////////////////
class c_IMPLEMENT_CLASS cFileSystemEntryTimeImplement
: virtual public cFileSystemEntryTimeInterface,
  virtual public cFileSystemEntryTimeImplementImplements
{
public:
    //typedef cFileSystemEntryTimeInterface cImplements;
    typedef cFileSystemEntryTimeImplementImplements cImplements;
#else // !defined(CFILESYSTEMENTRYTIMEIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CFILESYSTEMENTRYTIMEIMPLEMENT_MEMBERS_ONLY) 

#if !defined(CFILESYSTEMENTRYTIMEIMPLEMENT_MEMBERS_ONLY)
// include cFileSystemEntryTimeBase member functions implement
//
#define CFILESYSTEMENTRYTIMEBASE_MEMBERS_ONLY
#define CFILESYSTEMENTRYTIMEBASE_MEMBER_FUNCS_IMPLEMENT
#include "cFileSystemEntryTimeBase.hpp"
#undef CFILESYSTEMENTRYTIMEBASE_MEMBER_FUNCS_IMPLEMENT
#undef CFILESYSTEMENTRYTIMEBASE_MEMBERS_ONLY
};
#else // !defined(CFILESYSTEMENTRYTIMEIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CFILESYSTEMENTRYTIMEIMPLEMENT_MEMBERS_ONLY) 

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CFILESYSTEMENTRYTIMEINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CFILESYSTEMENTRYTIMEINTERFACE_MEMBERS_ONLY) 

#endif // !defined(_CFILESYSTEMENTRYTIMEINTERFACE_HPP) || defined(CFILESYSTEMENTRYTIMEINTERFACE_MEMBERS_ONLY) 
        

