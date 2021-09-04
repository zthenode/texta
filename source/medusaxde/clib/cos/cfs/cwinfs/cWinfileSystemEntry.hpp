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
//   File: cWinFileSystemEntry.hpp
//
// Author: $author$
//   Date: 7/31/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CWINFILESYSTEMENTRY_HPP) || defined(CWINFILESYSTEMENTRY_MEMBERS_ONLY)
#if !defined(_CWINFILESYSTEMENTRY_HPP) && !defined(CWINFILESYSTEMENTRY_MEMBERS_ONLY)
#define _CWINFILESYSTEMENTRY_HPP
#endif // !defined(_CWINFILESYSTEMENTRY_HPP) && !defined(CWINFILESYSTEMENTRY_MEMBERS_ONLY) 

#if !defined(CWINFILESYSTEMENTRY_MEMBERS_ONLY)
#include "cWinFileSystemEntryInterface.hpp"
#include "cWinFindFileData.hpp"
#include "cFileSystemEntryBase.hpp"
#include "cDebug.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cWinFileSystemEntryExtend
//
//  Author: $author$
//    Date: 7/31/2011
///////////////////////////////////////////////////////////////////////
typedef cFileSystemEntryBase
cWinFileSystemEntryExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cWinFileSystemEntry
//
// Author: $author$
//   Date: 7/31/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cWinFileSystemEntry
: virtual public cWinFileSystemEntryImplement,
  public cWinFileSystemEntryExtend
{
public:
    typedef cWinFileSystemEntryImplement cImplements;
    typedef cWinFileSystemEntryExtend cExtends;

    cTString m_findFileName;
    cWinFindFileData m_findFileData;

    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cWinFileSystemEntry
    //
    //       Author: $author$
    //         Date: 7/31/2011
    ///////////////////////////////////////////////////////////////////////
    cWinFileSystemEntry()
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cWinFileSystemEntry
    //
    //      Author: $author$
    //        Date: 7/31/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cWinFileSystemEntry()
    {
    }
#else // !defined(CWINFILESYSTEMENTRY_MEMBERS_ONLY) 
#endif // !defined(CWINFILESYSTEMENTRY_MEMBERS_ONLY) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: SetFileFoundAttributes
    //
    //    Author: $author$
    //      Date: 8/1/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eFileSystemEntryType SetFileFoundAttributes
    (const WIN32_FIND_DATA& findFileData)
#if defined(CWINFILESYSTEMENTRY_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CWINFILESYSTEMENTRY_MEMBER_FUNCS_INTERFACE) 
    {
        eFileSystemEntryType type = e_FILE_SYSTEM_ENTRY_TYPE_NONE;
#if !defined(CWINFILESYSTEMENTRY_MEMBER_FUNCS_IMPLEMENT)
        if (!(FILE_ATTRIBUTE_DIRECTORY & findFileData.dwFileAttributes))
            type = SetType(e_FILE_SYSTEM_ENTRY_TYPE_FILE);
        else
        type = SetType(e_FILE_SYSTEM_ENTRY_TYPE_DIRECTORY);
#else // !defined(CWINFILESYSTEMENTRY_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CWINFILESYSTEMENTRY_MEMBER_FUNCS_IMPLEMENT) 
        return type;
    }
#endif // defined(CWINFILESYSTEMENTRY_MEMBER_FUNCS_INTERFACE) 

#if !defined(CWINFILESYSTEMENTRY_MEMBERS_ONLY)
    ///////////////////////////////////////////////////////////////////////
    //  Function: Exists
    //
    //    Author: $author$
    //      Date: 7/30/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eFileSystemEntryType Exists
    (const cString& fileName)
    {
        eFileSystemEntryType type = e_FILE_SYSTEM_ENTRY_TYPE_NONE;
        LPWIN32_FIND_DATA lpFindFileData = &(WIN32_FIND_DATA&)(m_findFileData);
        LPCTSTR lpFindFileName;
        HANDLE hFound;
        if (0 < (m_findFileName.Assign_char(fileName.Chars())))
        if ((lpFindFileName = m_findFileName.HasChars()))
        if (INVALID_HANDLE_VALUE != 
            (hFound = FindFirstFile(lpFindFileName, lpFindFileData)))
        {
            type = SetFileFoundAttributes(m_findFileData);
            FindClose(hFound);
        }
        else
        c_DB_TRACE("() failed on FindFirstFile(\"" << lpFindFileName << "\",...)");
        return type;
    }
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CWINFILESYSTEMENTRY_MEMBERS_ONLY) 
#endif // !defined(CWINFILESYSTEMENTRY_MEMBERS_ONLY) 

#endif // !defined(_CWINFILESYSTEMENTRY_HPP) || defined(CWINFILESYSTEMENTRY_MEMBERS_ONLY) 
