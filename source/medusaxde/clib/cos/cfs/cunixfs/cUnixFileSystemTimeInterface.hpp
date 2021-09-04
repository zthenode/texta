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
//   File: cUnixFileSystemTimeInterface.hpp
//
// Author: $author$
//   Date: 8/25/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CUNIXFILESYSTEMTIMEINTERFACE_HPP) || defined(CUNIXFILESYSTEMTIMEINTERFACE_MEMBERS_ONLY)
#if !defined(_CUNIXFILESYSTEMTIMEINTERFACE_HPP) && !defined(CUNIXFILESYSTEMTIMEINTERFACE_MEMBERS_ONLY)
#define _CUNIXFILESYSTEMTIMEINTERFACE_HPP
#endif // !defined(_CUNIXFILESYSTEMTIMEINTERFACE_HPP) && !defined(CUNIXFILESYSTEMTIMEINTERFACE_MEMBERS_ONLY) 

#if !defined(CUNIXFILESYSTEMTIMEINTERFACE_MEMBERS_ONLY)
#include "cplatform_time.h"
#include "cFileSystemTimeInterface.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cUnixFileSystemTimeInterfaceImplements
//
//  Author: $author$
//    Date: 8/25/2011
///////////////////////////////////////////////////////////////////////
typedef cFileSystemTimeInterface
cUnixFileSystemTimeInterfaceImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cUnixFileSystemTimeInterface
//
// Author: $author$
//   Date: 8/25/2011
///////////////////////////////////////////////////////////////////////
class c_INTERFACE_CLASS cUnixFileSystemTimeInterface
: virtual public cUnixFileSystemTimeInterfaceImplements
{
public:
    typedef cUnixFileSystemTimeInterfaceImplements cImplements;
#else // !defined(CUNIXFILESYSTEMTIMEINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CUNIXFILESYSTEMTIMEINTERFACE_MEMBERS_ONLY) 

#if !defined(CUNIXFILESYSTEMTIMEINTERFACE_MEMBERS_ONLY)
// include cUnixFileSystemTime member functions interface
//
#define CUNIXFILESYSTEMTIME_MEMBERS_ONLY
#define CUNIXFILESYSTEMTIME_MEMBER_FUNCS_INTERFACE
#include "cUnixFileSystemTime.hpp"
#undef CUNIXFILESYSTEMTIME_MEMBER_FUNCS_INTERFACE
#undef CUNIXFILESYSTEMTIME_MEMBERS_ONLY
};

#if !defined(CUNIXFILESYSTEMTIMEIMPLEMENT_MEMBERS_ONLY)
///////////////////////////////////////////////////////////////////////
// Typedef: cUnixFileSystemTimeImplementImplements
//
//  Author: $author$
//    Date: 8/25/2011
///////////////////////////////////////////////////////////////////////
typedef cFileSystemTimeImplement
cUnixFileSystemTimeImplementImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cUnixFileSystemTimeImplement
//
// Author: $author$
//   Date: 8/25/2011
///////////////////////////////////////////////////////////////////////
class c_IMPLEMENT_CLASS cUnixFileSystemTimeImplement
: virtual public cUnixFileSystemTimeInterface,
  virtual public cUnixFileSystemTimeImplementImplements
{
public:
    //typedef cUnixFileSystemTimeInterface cImplements;
    typedef cUnixFileSystemTimeImplementImplements cImplements;
#else // !defined(CUNIXFILESYSTEMTIMEIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CUNIXFILESYSTEMTIMEIMPLEMENT_MEMBERS_ONLY) 

#if !defined(CUNIXFILESYSTEMTIMEIMPLEMENT_MEMBERS_ONLY)
// include cUnixFileSystemTime member functions implement
// 
#define CUNIXFILESYSTEMTIME_MEMBERS_ONLY
#define CUNIXFILESYSTEMTIME_MEMBER_FUNCS_IMPLEMENT
#include "cUnixFileSystemTime.hpp"
#undef CUNIXFILESYSTEMTIME_MEMBER_FUNCS_IMPLEMENT
#undef CUNIXFILESYSTEMTIME_MEMBERS_ONLY
};
#else // !defined(CUNIXFILESYSTEMTIMEIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CUNIXFILESYSTEMTIMEIMPLEMENT_MEMBERS_ONLY) 


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CUNIXFILESYSTEMTIMEINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CUNIXFILESYSTEMTIMEINTERFACE_MEMBERS_ONLY) 

#endif // !defined(_CUNIXFILESYSTEMTIMEINTERFACE_HPP) || defined(CUNIXFILESYSTEMTIMEINTERFACE_MEMBERS_ONLY) 
        

