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
#include "cevfilepath.hpp"
#include "cevfilepathstring.hpp"
#include "cevfiletime.hpp"
#include "cevtstring.hpp"
#include "cevstring.hpp"
#include "cevdatetimestring.hpp"
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
    CEvFilePath m_unixEntryPath;
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
            if (0 < (type = GetFoundEntryAttributes()))
            if (0 < (length = m_unixEntryPath.Assign(chars, length)))
            if ((chars = m_unixEntryPath.GetFileName(length)) && (0 < length))
                length = m_name.Assign(chars, length);
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
        else if ((err = stat(m_findChars, &m_st)))
                DBE("() failed to stat \"%s\"\n", m_findChars);
        else error = SetFileTimesSet();
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
        if (!(error = SetFileTimesToSet(fileEntry)))
            error = SetFileTimesSet();
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: SetFileTimes
    //
    //   Author: $author$
    //     Date: 9/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError SetFileTimes
    (const EvFileSystemEntryTimes& fileTimes) 
    {
        EvError error = EV_ERROR_FAILED;
        if (!(error = SetFileTimesToSet(fileTimes)))
            error = SetFileTimesSet();
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
        EvError error2;
        CEvFileTime createdTime;
        CEvFileTime changedTime;
        CEvFileTime modifiedTime;
        CEvFileTime accessedTime;
        CEvDateTimeString dtc;

        if (!(error2 = m_createdOSFileTime.ToTime(createdTime)))
        if (!(error2 = m_changedOSFileTime.ToTime(changedTime)))
        if (!(error2 = m_modifiedOSFileTime.ToTime(modifiedTime)))
        if (!(error2 = m_accessedOSFileTime.ToTime(accessedTime)))
        {
        dtc.Assign(createdTime);
        DBT("() created time %s\n", dtc.c_str());
        dtc.Assign(changedTime);
        DBT("() changed time %s\n", dtc.c_str());
        dtc.Assign(modifiedTime);
        DBT("() modified time %s\n", dtc.c_str());
        dtc.Assign(accessedTime);
        DBT("() accessed time %s\n", dtc.c_str());
        }

#if defined(WIN32) 
// Windows
        HANDLE win32Handle;

        DBF("() in...\n");
        if (!(win32Handle = m_win32File.Attached()))
            return EV_ERROR_NOT_ATTACHED;

        if (SetFileTime
            (win32Handle, &m_createdOSFileTime, 
             &m_accessedOSFileTime, &m_modifiedOSFileTime))
            error = EV_ERROR_NONE;
#else // defined(WIN32) 
// Unix
        EvError error2;
        DBF("() in...\n");
        if (!(m_findChars = m_findName.Chars
			(m_findLength)) || (0 >= m_findLength))
			DBE("() failed on m_findName.Chars\n");
        else if ((error2 = m_unixFileSystem.SetFileTime
                (m_findChars, &m_changedOSFileTime, 
                 &m_accessedOSFileTime, &m_modifiedOSFileTime)))
                DBE("() failed on m_unixFileSystem.SetFileTime\n");
        else error = EV_ERROR_NONE;
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

        if (0 < (length = m_findName.Assignc(chars, length)))
        if (!(findChars = m_findName.Chars(length)) || (0 >= length))
            return 0;
        return findChars;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetFileTimesToSet
    //
    //   Author: $author$
    //     Date: 7/29/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError SetFileTimesToSet
    (const EvFileSystemEntry& fileEntry) 
    {
        const EvFileTime& createdTime = fileEntry.GetCreatedFileTime();
        const EvFileTime& changedTime = fileEntry.GetChangedFileTime();
        const EvFileTime& modifiedTime = fileEntry.GetModifiedFileTime();
        const EvFileTime& accessedTime = fileEntry.GetAccessedFileTime();
        EvError error = SetFileTimesToSet
        (createdTime, changedTime, modifiedTime, accessedTime);
        return error;
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
        const EvFileTime& createdTime = fileTimes.GetCreatedFileTime();
        const EvFileTime& changedTime = fileTimes.GetChangedFileTime();
        const EvFileTime& modifiedTime = fileTimes.GetModifiedFileTime();
        const EvFileTime& accessedTime = fileTimes.GetAccessedFileTime();
        EvError error = SetFileTimesToSet
        (createdTime, changedTime, modifiedTime, accessedTime);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: SetFileTimesToSet
    //
    //   Author: $author$
    //     Date: 9/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError SetFileTimesToSet
    (const EvFileTime& createdTime,
     const EvFileTime& changedTime,
     const EvFileTime& modifiedTime,
     const EvFileTime& accessedTime) 
    {
        EvError error = EV_ERROR_FAILED;
        EvError error2;

        CEvDateTimeString dtc;
        dtc.Assign(createdTime);
        DBT("() created time %s\n", dtc.c_str());
        dtc.Assign(changedTime);
        DBT("() changed time %s\n", dtc.c_str());
        dtc.Assign(modifiedTime);
        DBT("() modified time %s\n", dtc.c_str());
        dtc.Assign(accessedTime);
        DBT("() accessed time %s\n", dtc.c_str());
        
        if (!(error2 = m_createdOSFileTime.FromTime(createdTime)))
        if (!(error2 = m_changedOSFileTime.FromTime(changedTime)))
        if (!(error2 = m_modifiedOSFileTime.FromTime(modifiedTime)))
        if (!(error2 = m_accessedOSFileTime.FromTime(accessedTime)))
            error = EV_ERROR_NONE;
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: CopyFileTimes
    //
    //   Author: $author$
    //     Date: 8/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError CopyFileTimes
    (const EvFileSystemEntry& fileEntry) 
    {
        const EvFileTime& createdTime = fileEntry.GetCreatedFileTime();
        const EvFileTime& changedTime = fileEntry.GetChangedFileTime();
        const EvFileTime& modifiedTime = fileEntry.GetModifiedFileTime();
        const EvFileTime& accessedTime = fileEntry.GetAccessedFileTime();
        EvError error = CopyFileTimes
        (createdTime, changedTime, modifiedTime, accessedTime);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: CopyFileTimes
    //
    //   Author: $author$
    //     Date: 8/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError CopyFileTimes
    (const EvFileSystemEntryTimes& fileTimes) 
    {
        const EvFileTime& createdTime = fileTimes.GetCreatedFileTime();
        const EvFileTime& changedTime = fileTimes.GetChangedFileTime();
        const EvFileTime& modifiedTime = fileTimes.GetModifiedFileTime();
        const EvFileTime& accessedTime = fileTimes.GetAccessedFileTime();
        EvError error = CopyFileTimes
        (createdTime, changedTime, modifiedTime, accessedTime);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: CopyFileTimes
    //
    //   Author: $author$
    //     Date: 9/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError CopyFileTimes
    (const EvFileTime& createdTime,
     const EvFileTime& changedTime,
     const EvFileTime& modifiedTime,
     const EvFileTime& accessedTime) 
    {
        EvError error = EV_ERROR_FAILED;
        EvError error2;
        if (!(error2 = SetCreatedFileTime(createdTime)))
        if (!(error2 = SetChangedFileTime(changedTime)))
        if (!(error2 = SetModifiedFileTime(modifiedTime)))
        if (!(error2 = SetAccessedFileTime(accessedTime)))
            error = EV_ERROR_NONE;
        return error;
    }

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
