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
#include "cevfilesystementrybase.hpp"
#include "evfilesystementry.hpp"
#include "cevfilepathstring.hpp"
#include "cevfiletime.hpp"
#include "cevtstring.hpp"
#include "cevstring.hpp"
#include "cevbase.hpp"

#if defined(WIN32) 
// Windows
#include "os/win32/cevwin32file.hpp"
#else // defined(WIN32) 
// Uinx
#include "os/unix/cevunixfilesystem.hpp"
#endif // defined(WIN32)

///////////////////////////////////////////////////////////////////////
//  Typedef: CEvFileSystemEntryExtends
//
//   Author: $author$
//     Date: 6/21/2007
///////////////////////////////////////////////////////////////////////
typedef CEvFileSystemEntryFound
<CEvFileSystemEntryFoundExtends>
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

#if defined(TCHAR_NOT_CHAR) 
    typedef CEvTString CEvFindString;
    typedef TCHAR EvFindChar;
#else // defined(TCHAR_NOT_CHAR) 
    typedef CEvString CEvFindString;
    typedef CHAR EvFindChar;
#endif // defined(TCHAR_NOT_CHAR)

    CEvFindString m_findName;
    const EvFindChar* m_findChars;
    LONG m_findLength;

#if defined(WIN32) 
// Windows
    CEvWin32File m_win32File;
#else // defined(WIN32) 
// Unix
    CEvUnixFileSystem m_unixFileSystem;
#endif // defined(WIN32)

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvFileSystemEntry
    //
    //       Author: $author$
    //         Date: 6/2/2007
    ///////////////////////////////////////////////////////////////////////
    CEvFileSystemEntry
    (const char* chars=0, LONG length=-1) 
    : m_findChars(0),
      m_findLength(0)
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

        ClearFoundEntryAttributes();

        if ((chars) && (0 != length))
        {
#if defined(WIN32) 
// Windows
            HANDLE handle;
            if ((m_findChars = GetFindName(chars, length)))
            if (INVALID_HANDLE_VALUE != (handle = FindFirstFile
                (m_findChars, &m_win32FindData)))
            {
                FindClose(handle);
                if (0 < (type = GetFoundEntryAttributes()))
                if (0 >= (length = GetFoundEntryName()))
                    type = -EV_ERROR_FAILED;
            }
#else // defined(WIN32) 
// Unix
            int err;
            if ((m_findChars = GetFindName(chars, length)))
            if (!(err = stat(m_findChars, &m_st)))
            if (S_IFDIR == (S_IFDIR & m_st.st_mode))
                type = EV_TYPE_DIRECTORY;
            else type = EV_TYPE_FILE;
#endif // defined(WIN32)
        }
        return type;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetExistingTimes
    //
    //   Author: $author$
    //     Date: 7/29/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError SetExistingTimes
    (const char* chars, LONG length=-1) 
    {
        EvError error = SetExistingTimes(*this, chars, length);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: SetExistingTimes
    //
    //   Author: $author$
    //     Date: 7/3/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError SetExistingTimes
    (const EvFileSystemEntry& fileEntry,
     const char* chars, LONG length=-1) 
    {
        EvError error = EV_ERROR_FAILED;
#if defined(WIN32) 
// Windows
        EvError error2;
        if ((m_findChars = GetFindName(chars, length)))
        if (!(error2 = m_win32File.
            Open(m_findChars, GENERIC_WRITE)))
        {
            error = SetFileTimes(fileEntry);
            Close();
        }
#else // defined(WIN32) 
// Unix
        int err;
        if ((m_findChars = GetFindName(chars, length)))
        if (!(err = stat(m_findChars, &m_st)))
            error = SetFileTimes(fileEntry);
#endif // defined(WIN32)
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: SetExistingTimesSet
    //
    //   Author: $author$
    //     Date: 7/29/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError SetExistingTimesSet
    (const char* chars, LONG length=-1) 
    {
        EvError error = EV_ERROR_FAILED;
#if defined(WIN32) 
// Windows
        EvError error2;
        DBF("() in...\n");
        if ((m_findChars = GetFindName(chars, length)))
        if (!(error2 = m_win32File.
            Open(m_findChars, GENERIC_WRITE)))
        {
            error = SetFileTimesSet();
            Close();
        }
#else // defined(WIN32) 
// Unix
        int err;
        DBF("() in...\n");
        if (!(m_findChars = GetFindName(chars, length)))
			DBE("() failed on GetFindName\n");
        else if (!(err = stat(m_findChars, &m_st)))
				error = SetFileTimesSet();
        else DBE("() failed to stat \"%s\"\n", m_findChars);
#endif // defined(WIN32)
        DBF("() ...out\n");
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetFileTimes
    //
    //   Author: $author$
    //     Date: 7/3/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError SetFileTimes
    (const EvFileSystemEntry& fileEntry) 
    {
        EvError error = EV_ERROR_FAILED;
        const EvFileTime& modifiedTime = fileEntry.GetModifiedFileTime();
        const EvFileTime& accessedTime = fileEntry.GetAccessedFileTime();
        EvError error2;
#if defined(WIN32) 
// Windows
        const EvFileTime& createdTime = fileEntry.GetCreatedFileTime();

        if (!(error2 = m_createdWin32Time.FromTime(createdTime)))
        if (!(error2 = m_modifiedWin32Time.FromTime(modifiedTime)))
        if (!(error2 = m_accessedWin32Time.FromTime(accessedTime)))
            error = SetFileTimesSet();
#else // defined(WIN32) 
// Unix
        const EvFileTime& changedTime = fileEntry.GetChangedFileTime();

        if (!(error2 = m_changedUnixTime.FromTime(changedTime)))
        if (!(error2 = m_modifiedUnixTime.FromTime(modifiedTime)))
        if (!(error2 = m_accessedUnixTime.FromTime(accessedTime)))
            error = SetFileTimesSet();
#endif // defined(WIN32)
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: SetFileTimesSet
    //
    //   Author: $author$
    //     Date: 7/29/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError SetFileTimesSet() 
    {
        EvError error = EV_ERROR_FAILED;
#if defined(WIN32) 
// Windows
        HANDLE win32Handle;

        DBF("() in...\n");
        if (!(win32Handle = m_win32File.Attached()))
            return EV_ERROR_NOT_ATTACHED;

        if (SetFileTime
            (win32Handle, &m_createdWin32Time, 
             &m_accessedWin32Time, &m_modifiedWin32Time))
            error = EV_ERROR_NONE;
#else // defined(WIN32) 
// Unix
        EvError error2;
        DBF("() in...\n");
        if (!(m_findChars = m_findName.Chars
			(m_findLength)) || (0 >= m_findLength))
			DBE("() failed on m_findName.Chars\n");
        else if (!(error2 = SetFileTime
				(m_findChars, &m_changedUnixTime, 
				 &m_accessedUnixTime, &m_modifiedUnixTime)))
            error = EV_ERROR_NONE;
        else DBE("() failed on SetFileTime\n");
#endif // defined(WIN32)
        DBF("() ...out\n");
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Close
    //
    //   Author: $author$
    //     Date: 7/3/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Close() 
    {
        EvError error = EV_ERROR_FAILED;
#if defined(WIN32) 
// Windows
        error = m_win32File.Close();
#else // defined(WIN32) 
// Unix
#endif // defined(WIN32)
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: GetFindName
    //
    //   Author: $author$
    //     Date: 7/2/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const EvFindChar* GetFindName
    (const char* chars, LONG length=-1) 
    {
        const EvFindChar* findChars = 0;

#if defined(WIN32) && defined(TCHAR_NOT_CHAR) 
        if (0 < (length = m_findName.Assignc(chars, length)))
        if (!(findChars = m_findName.Chars(length)) || (0 >= length))
            return 0;
#else // defined(WIN32) && defined(TCHAR_NOT_CHAR)
        if (0 > length)
            findChars = chars;
        else if (0 < length)
        {
            if (chars[length-1])
            {
                if (0 < (length = m_findName.Assign(chars, length)))
                if ((chars = m_findName.Chars(length)) && (0 < length))
                    findChars = chars;
            }
            else findChars = chars;
        }
#endif // defined(WIN32) && defined(TCHAR_NOT_CHAR)

        return findChars;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetFileTimesToSet
    //
    //   Author: $author$
    //     Date: 7/29/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError SetFileTimesToSet
    (const EvFileSystemEntryTimes& fileTimes) 
    {
        EvError error = EV_ERROR_FAILED;
        const EvFileTime& accessedTime = fileTimes.GetAccessedFileTime();
        const EvFileTime& modifiedTime = fileTimes.GetModifiedFileTime();
#if defined(WIN32) 
// Windows
        const EvFileTime& createdTime = fileTimes.GetCreatedFileTime();
        EvError error2;

        DBF("() in...\n");
        if (!(error2 = m_modifiedWin32Time.FromTime(modifiedTime)))
        if (!(error2 = m_accessedWin32Time.FromTime(accessedTime)))
        if (!(error2 = m_createdWin32Time.FromTime(createdTime)))
            error = EV_ERROR_NONE;
#else // defined(WIN32) 
// Unix
        EvError error2 = EV_ERROR_FAILED;

        DBF("() in...\n");
        if (!(error2 = m_modifiedUnixTime.FromTime(modifiedTime)))
        if (!(error2 = m_accessedUnixTime.FromTime(accessedTime)))
        if (!(error2 = m_changedUnixTime.FromTime(modifiedTime)))
            error = EV_ERROR_NONE;
#endif // defined(WIN32)
        DBF("() ...out\n");
        return error;
    }

#if defined(WIN32) 
// Windows
#else // defined(WIN32) 
// Unix
    ///////////////////////////////////////////////////////////////////////
    // Function: SetFileTime
    //
    //   Author: $author$
    //     Date: 8/9/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError SetFileTime
    (const char* filename,
     const CEvUnixFileTime* changedTime,
     const CEvUnixFileTime* accessedTime,
     const CEvUnixFileTime* modifiedTime) 
    {
        EvError error;
        
        DBF("() in...\n");
        if ((error = m_unixFileSystem.SetFileTime
            (filename, changedTime, accessedTime, modifiedTime)))
            DBE("() failed on m_unixFileSystem.SetFileTime\n");
        DBF("() ...out\n");
        return error;
    }
#endif // defined(WIN32)

    ///////////////////////////////////////////////////////////////////////
    // Function: SetName
    //
    //   Author: $author$
    //     Date: 7/2/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG SetName
    (const char* chars,
     LONG length=-1) 
    {
        length = m_name.Assign(chars,length);
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetName
    //
    //   Author: $author$
    //     Date: 7/2/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetName
    (LONG& length) const 
    {
        const char* chars = m_name.Chars(length);
        return chars;
    }
};
#endif // _CEVFILESYSTEMENTRY_HPP
