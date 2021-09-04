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
//   File: cFileSystemEntryType.hpp
//
// Author: $author$
//   Date: 7/30/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CFILESYSTEMENTRYTYPE_HPP) || defined(CFILESYSTEMENTRYTYPE_MEMBERS_ONLY)
#if !defined(_CFILESYSTEMENTRYTYPE_HPP) && !defined(CFILESYSTEMENTRYTYPE_MEMBERS_ONLY)
#define _CFILESYSTEMENTRYTYPE_HPP
#endif // !defined(_CFILESYSTEMENTRYTYPE_HPP) && !defined(CFILESYSTEMENTRYTYPE_MEMBERS_ONLY) 

#if !defined(CFILESYSTEMENTRYTYPE_MEMBERS_ONLY)
#include "cInstanceBase.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
//    Enum: eFileSystemEntryType
//
//  Author: $author$
//    Date: 7/30/2011
///////////////////////////////////////////////////////////////////////
typedef int eFileSystemEntryType;
enum
{
    e_FILE_SYSTEM_ENTRY_TYPE_NONE = (0),

    e_FILE_SYSTEM_ENTRY_TYPE_FILE          = (1),
    e_FILE_SYSTEM_ENTRY_TYPE_DIRECTORY     = (1 << 1),
    e_FILE_SYSTEM_ENTRY_TYPE_SYMBOLIC_LINK = (1 << 2),
    e_FILE_SYSTEM_ENTRY_TYPE_HARD_LINK     = (1 << 3),
    e_FILE_SYSTEM_ENTRY_TYPE_BLOCK_DEVICE  = (1 << 4),
    e_FILE_SYSTEM_ENTRY_TYPE_CHAR_DEVICE   = (1 << 5),

    e_FILE_SYSTEM_ENTRY_TYPE_NEXT,
    e_FILE_SYSTEM_ENTRY_TYPE_ANY = (((e_FILE_SYSTEM_ENTRY_TYPE_NEXT - 1) << 1) - 1)
};

///////////////////////////////////////////////////////////////////////
//  Class: cFileSystemEntryType
//
// Author: $author$
//   Date: 7/30/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cFileSystemEntryType
{
public:
#else // !defined(CFILESYSTEMENTRYTYPE_MEMBERS_ONLY) 
#endif // !defined(CFILESYSTEMENTRYTYPE_MEMBERS_ONLY) 

#if !defined(CFILESYSTEMENTRYTYPE_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CFILESYSTEMENTRYTYPE_MEMBERS_ONLY) 
#endif // !defined(CFILESYSTEMENTRYTYPE_MEMBERS_ONLY) 

#endif // !defined(_CFILESYSTEMENTRYTYPE_HPP) || defined(CFILESYSTEMENTRYTYPE_MEMBERS_ONLY) 
        

