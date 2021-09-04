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
//   File: cFileSystemEntryTimeWhen.hpp
//
// Author: $author$
//   Date: 7/31/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CFILESYSTEMENTRYTIMEWHEN_HPP) || defined(CFILESYSTEMENTRYTIMEWHEN_MEMBERS_ONLY)
#if !defined(_CFILESYSTEMENTRYTIMEWHEN_HPP) && !defined(CFILESYSTEMENTRYTIMEWHEN_MEMBERS_ONLY)
#define _CFILESYSTEMENTRYTIMEWHEN_HPP
#endif // !defined(_CFILESYSTEMENTRYTIMEWHEN_HPP) && !defined(CFILESYSTEMENTRYTIMEWHEN_MEMBERS_ONLY) 

#if !defined(CFILESYSTEMENTRYTIMEWHEN_MEMBERS_ONLY)
#include "cInstanceBase.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
//    Enum: eFileSystemEntryTimeWhen
//
//  Author: $author$
//    Date: 7/31/2011
///////////////////////////////////////////////////////////////////////
typedef int eFileSystemEntryTimeWhen;
enum
{
    e_FILE_SYSTEM_ENTRY_TIME_WHEN_NONE = 0,

    e_FILE_SYSTEM_ENTRY_TIME_WHEN_MODIFIED = (1),
    e_FILE_SYSTEM_ENTRY_TIME_WHEN_CREATED  = (1 << 1),
    e_FILE_SYSTEM_ENTRY_TIME_WHEN_ACCESSED = (1 << 2),
    e_FILE_SYSTEM_ENTRY_TIME_WHEN_CHANGED  = (1 << 3),

    e_FILE_SYSTEM_ENTRY_TIME_WHEN_NEXT,
    e_FILE_SYSTEM_ENTRY_TIME_WHEN_ANY = (((e_FILE_SYSTEM_ENTRY_TIME_WHEN_NEXT - 1) << 1) - 1)
};

///////////////////////////////////////////////////////////////////////
//  Class: cFileSystemEntryTimeWhen
//
// Author: $author$
//   Date: 7/31/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cFileSystemEntryTimeWhen
{
public:
#else // !defined(CFILESYSTEMENTRYTIMEWHEN_MEMBERS_ONLY) 
#endif // !defined(CFILESYSTEMENTRYTIMEWHEN_MEMBERS_ONLY) 

#if !defined(CFILESYSTEMENTRYTIMEWHEN_MEMBERS_ONLY)
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CFILESYSTEMENTRYTIMEWHEN_MEMBERS_ONLY) 
#endif // !defined(CFILESYSTEMENTRYTIMEWHEN_MEMBERS_ONLY) 

#endif // !defined(_CFILESYSTEMENTRYTIMEWHEN_HPP) || defined(CFILESYSTEMENTRYTIMEWHEN_MEMBERS_ONLY) 
        

