///////////////////////////////////////////////////////////////////////
//   File: cevfilesystementry.hpp
//
// Author: $author$
//   Date: 6/2/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVFILESYSTEMENTRY_HPP
#define _CEVFILESYSTEMENTRY_HPP

#include "cevfilesystementryfound.hpp"
#include "cevfilesystementrytimes.hpp"
#include "evfilesystementry.hpp"
#include "cevfiletime.hpp"
#include "cevtstring.hpp"
#include "cevstring.hpp"
#include "cevbase.hpp"

///////////////////////////////////////////////////////////////////////
//  Typedef: CEvFileSystemEntryExtends
//
//   Author: $author$
//     Date: 6/21/2007
///////////////////////////////////////////////////////////////////////
typedef CEvFileSystemEntryFoundExtends
CEvFileSystemEntryExtends;

///////////////////////////////////////////////////////////////////////
//  Class: CEvFileSystemEntry
//
// Author: $author$
//   Date: 6/2/2007
///////////////////////////////////////////////////////////////////////
class CEvFileSystemEntry
: virtual public EvFileSystemEntry,
  public CEvFileSystemEntryExtends
{
public:
    typedef EvFileSystemEntry CImplements;
    typedef CEvFileSystemEntryExtends CExtends;
    typedef CEvFileSystemEntry CDerives;

#if defined(WIN32) 
// Windows
    CEvWin32FindData m_win32FindData;
#if defined(TCHAR_NOT_CHAR) 
    CEvTString m_findName;
#endif // defined(TCHAR_NOT_CHAR)
#else // defined(WIN32) 
// Unix
    struct stat m_st;
#endif // defined(WIN32)

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvFileSystemEntry
    //
    //       Author: $author$
    //         Date: 6/2/2007
    ///////////////////////////////////////////////////////////////////////
    CEvFileSystemEntry
    (const char* chars=0, LONG length=-1) 
    {
        int type;
        EvError error;

        if (chars)
        if (0 > (type = Exists(chars, length)))
            throw(error = -type);
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Exists
    //
    //   Author: $author$
    //     Date: 6/2/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int Exists
    (const char* chars, LONG length=-1) 
    {
        int type = EV_TYPE_NONE;
        EvError error;

        if ((chars) && (0 >= length))
        {
#if defined(WIN32) 
// Windows
            HANDLE handle;
#if defined(TCHAR_NOT_CHAR) 
            const TCHAR* tchars;
            if (0 < (length = m_findName.Assignc(chars, length)))
            if ((tchars = m_findName.Chars(length)) && (0 < length))
            if ((handle = FindFirstFile(tchars, &m_win32FindData)))
#else // defined(TCHAR_NOT_CHAR) 
            if ((handle = FindFirstFile(chars, &m_win32FindData)))
#endif // defined(TCHAR_NOT_CHAR)
            {
                FindClose(handle);

                if (FILE_ATTRIBUTE_DIRECTORY == 
                    (FILE_ATTRIBUTE_DIRECTORY & m_win32FindData.dwFileAttributes))
                    type = EV_TYPE_DIRECTORY;
                else type = EV_TYPE_FILE;

                error = GetFoundFileTimes();
            }
#else // defined(WIN32) 
// Unix
            int err;

            if (!(err = stat(chars, &m_st)))
            if (S_IFDIR == (S_IFDIR & m_st.st_mode))
                type = EV_TYPE_DIRECTORY;
            else type = EV_TYPE_FILE;
#endif // defined(WIN32)
        }
        return type;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: GetFoundFileTimes
    //
    //   Author: $author$
    //     Date: 6/22/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError GetFoundFileTimes() 
    {
        EvError error = EV_ERROR_NONE;

#if defined(WIN32) 
// Windows
        m_modifiedWin32Time = (m_win32FindData.ftLastWriteTime);
        m_createdWin32Time = (m_win32FindData.ftCreationTime);
        m_accessedWin32Time = (m_win32FindData.ftLastAccessTime);
        error = GetFileTimes();
#else // defined(WIN32) 
// Unix
#endif // defined(WIN32)
        return error;
    }
};
#endif // _CEVFILESYSTEMENTRY_HPP
