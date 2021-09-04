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
//   File: cUnixFileSystemEntryTimeInterface.hpp
//
// Author: $author$
//   Date: 8/25/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CUNIXFILESYSTEMENTRYTIMEINTERFACE_HPP) || defined(CUNIXFILESYSTEMENTRYTIMEINTERFACE_MEMBERS_ONLY)
#if !defined(_CUNIXFILESYSTEMENTRYTIMEINTERFACE_HPP) && !defined(CUNIXFILESYSTEMENTRYTIMEINTERFACE_MEMBERS_ONLY)
#define _CUNIXFILESYSTEMENTRYTIMEINTERFACE_HPP
#endif // !defined(_CUNIXFILESYSTEMENTRYTIMEINTERFACE_HPP) && !defined(CUNIXFILESYSTEMENTRYTIMEINTERFACE_MEMBERS_ONLY) 

#if !defined(CUNIXFILESYSTEMENTRYTIMEINTERFACE_MEMBERS_ONLY)
#include "cFileSystemEntryTimeInterface.hpp"
#include "cUnixFileSystemTimeInterface.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cUnixFileSystemEntryTimeInterfaceImplements
//
//  Author: $author$
//    Date: 8/25/2011
///////////////////////////////////////////////////////////////////////
typedef cFileSystemEntryTimeInterface
cUnixFileSystemEntryTimeInterfaceImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cUnixFileSystemEntryTimeInterface
//
// Author: $author$
//   Date: 8/25/2011
///////////////////////////////////////////////////////////////////////
class c_INTERFACE_CLASS cUnixFileSystemEntryTimeInterface
: virtual public cUnixFileSystemEntryTimeInterfaceImplements
{
public:
    typedef cUnixFileSystemEntryTimeInterfaceImplements cImplements;
#else // !defined(CUNIXFILESYSTEMENTRYTIMEINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CUNIXFILESYSTEMENTRYTIMEINTERFACE_MEMBERS_ONLY) 

#if !defined(CUNIXFILESYSTEMENTRYTIMEINTERFACE_MEMBERS_ONLY)
// include cUnixFileSystemEntryTime member functions interface
//
#define CUNIXFILESYSTEMENTRYTIME_MEMBERS_ONLY
#define CUNIXFILESYSTEMENTRYTIME_MEMBER_FUNCS_INTERFACE
#include "cUnixFileSystemEntryTime.hpp"
#undef CUNIXFILESYSTEMENTRYTIME_MEMBER_FUNCS_INTERFACE
#undef CUNIXFILESYSTEMENTRYTIME_MEMBERS_ONLY
};

#if !defined(CUNIXFILESYSTEMENTRYTIMEIMPLEMENT_MEMBERS_ONLY)
///////////////////////////////////////////////////////////////////////
// Typedef: cUnixFileSystemEntryTimeImplementImplements
//
//  Author: $author$
//    Date: 8/25/2011
///////////////////////////////////////////////////////////////////////
typedef cFileSystemEntryTimeImplement
cUnixFileSystemEntryTimeImplementImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cUnixFileSystemEntryTimeImplement
//
// Author: $author$
//   Date: 8/25/2011
///////////////////////////////////////////////////////////////////////
class c_IMPLEMENT_CLASS cUnixFileSystemEntryTimeImplement
: virtual public cUnixFileSystemEntryTimeInterface,
  virtual public cUnixFileSystemTimeImplementImplements,
  virtual public cUnixFileSystemEntryTimeImplementImplements
{
public:
    //typedef cUnixFileSystemEntryTimeInterface cImplements;
    typedef cUnixFileSystemEntryTimeImplementImplements cImplements;
#else // !defined(CUNIXFILESYSTEMENTRYTIMEIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CUNIXFILESYSTEMENTRYTIMEIMPLEMENT_MEMBERS_ONLY) 

#if !defined(CUNIXFILESYSTEMENTRYTIMEIMPLEMENT_MEMBERS_ONLY)
// include cUnixFileSystemEntryTime member functions implement
//
#define CUNIXFILESYSTEMENTRYTIME_MEMBERS_ONLY
#define CUNIXFILESYSTEMENTRYTIME_MEMBER_FUNCS_IMPLEMENT
#include "cUnixFileSystemEntryTime.hpp"
#undef CUNIXFILESYSTEMENTRYTIME_MEMBER_FUNCS_IMPLEMENT
#undef CUNIXFILESYSTEMENTRYTIME_MEMBERS_ONLY
};
#else // !defined(CUNIXFILESYSTEMENTRYTIMEIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CUNIXFILESYSTEMENTRYTIMEIMPLEMENT_MEMBERS_ONLY) 

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CUNIXFILESYSTEMENTRYTIMEINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CUNIXFILESYSTEMENTRYTIMEINTERFACE_MEMBERS_ONLY) 

#endif // !defined(_CUNIXFILESYSTEMENTRYTIMEINTERFACE_HPP) || defined(CUNIXFILESYSTEMENTRYTIMEINTERFACE_MEMBERS_ONLY) 
        

