///////////////////////////////////////////////////////////////////////
//   File: cevfiledirectoryentry.hpp
//
// Author: $author$
//   Date: 5/3/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVFILEDIRECTORYENTRY_HPP
#define _CEVFILEDIRECTORYENTRY_HPP

#include "cevfilesystementryfound.hpp"
#include "cevfilesystementrytimes.hpp"
#include "evfiledirectoryentry.hpp"
#include "cevattached.hpp"
#include "cevtstring.hpp"
#include "cevstring.hpp"
#include "evplatform_security.h"

///////////////////////////////////////////////////////////////////////
// Typedef: CEvFileSystemDirectoryEntryAttached
//
//  Author: $author$
//    Date: 5/4/2007
///////////////////////////////////////////////////////////////////////
typedef CEvAttached
<DIRECTORY, INVALID_DIRECTORY_T, INVALID_DIRECTORY_VALUE, 
 EvFileSystemDirectoryEntryAttached, CEvFileSystemEntryBase> 
CEvFileSystemDirectoryEntryAttached;

///////////////////////////////////////////////////////////////////////
//  Typedef: CEvFileSystemDirectoryEntryFoundExtends
//
//   Author: $author$
//     Date: 6/22/2007
///////////////////////////////////////////////////////////////////////
typedef CEvFileSystemEntryTimesT
<CEvFileSystemDirectoryEntryAttached, 
 EvFileSystemDirectoryEntryImplements>
CEvFileSystemDirectoryEntryFoundExtends;

///////////////////////////////////////////////////////////////////////
//  Typedef: CEvFileSystemDirectoryEntryExtends
//
//   Author: $author$
//     Date: 6/22/2007
///////////////////////////////////////////////////////////////////////
typedef CEvFileSystemEntryFound
<CEvFileSystemDirectoryEntryFoundExtends>
CEvFileSystemDirectoryEntryExtends;

///////////////////////////////////////////////////////////////////////
//  Class: CEvFileSystemDirectoryEntry
//
// Author: $author$
//   Date: 6/23/2007
///////////////////////////////////////////////////////////////////////
class CEvFileSystemDirectoryEntry
: virtual public EvFileSystemDirectoryEntry,
  public CEvFileSystemDirectoryEntryExtends
{
public:
    typedef EvFileSystemDirectoryEntry CImplements;
    typedef CEvFileSystemDirectoryEntryExtends CExtends;
    typedef CEvFileSystemDirectoryEntry CDerives;

    static const char m_separator;
    static const char* m_currentDirectoryName;
    static const char* m_parentDirectoryName;

#if defined(WIN32) 
// Windows
#else // defined(WIN32) 
// Unix
    const struct dirent *m_dirent;
    CEvString m_statDir;
    CEvString m_statPath;
#endif // defined(WIN32)

    CEvTString m_namet;
    bool m_isCircular;
    bool m_isCurrent;
    bool m_isParent;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvFileSystemDirectoryEntry
    //
    //       Author: $author$
    //         Date: 6/23/2007
    ///////////////////////////////////////////////////////////////////////
    CEvFileSystemDirectoryEntry() 
    : m_isCircular(false),
      m_isCurrent(false),
      m_isParent(false)
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: GetEntry
    //
    //   Author: $author$
    //     Date: 5/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError GetEntry
#if defined(WIN32) 
// Windows
    (DIRECTORY attached, 
     const CEvWin32FindData& win32FindData)
#else // defined(WIN32) 
// Unix
    (DIRECTORY attached, 
     const struct dirent& dirent, 
     const char* pathChars)
#endif // defined(WIN32)
    {
        EvError error = EV_ERROR_FAILED;
#if !defined(WIN32) 
// Unix
        LONG length;
#endif // !defined(WIN32)

        ClearFoundEntryAttributes();

#if defined(WIN32) 
// Windows
        if (!(error = GetFoundEntry(win32FindData)))
            error = Attach(attached);
#else // defined(WIN32) 
// Unix
        m_dirent = &dirent;
        if (0 < (length = m_statDir.Assign(pathChars)))
        if (!(error = GetFoundEntry(dirent)))
            error = Attach(attached);
#endif // defined(WIN32)
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetFoundEntry
    //
    //   Author: $author$
    //     Date: 6/22/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError GetFoundEntry() 
    {
        EvError error = GetFoundEntry
#if defined(WIN32) 
// Windows
        (m_win32FindData);
#else // defined(WIN32) 
// Unix
        (*m_dirent);
#endif // defined(WIN32)
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetFoundEntry
    //
    //   Author: $author$
    //     Date: 6/22/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError GetFoundEntry 
#if defined(WIN32) 
// Windows
    (const CEvWin32FindData& win32FindData) 
#else // defined(WIN32) 
// Unix
    (const struct dirent& dirent) 
#endif // defined(WIN32)
    {
        EvError error = EV_ERROR_NONE;
        LONG length;
        int unequal;
        int type;

#if defined(WIN32) 
// Windows
        if (0 < (length = SetNamet(win32FindData.cFileName)))
        if (0 < (length = GetFoundEntryName(win32FindData)))
        if (0 <= (type = GetFoundEntryAttributes(win32FindData)))
            error = EV_ERROR_NONE;
#else // defined(WIN32) 
// Unix
        const char* chars;
        int err;

        if (0 < (length = SetName(dirent.d_name)))
        if ((chars = m_statDir.Chars(length)) && (0 < length))
        if (0 < (length = m_statPath.Assign(chars, length)))
        if (0 < (length = m_statPath.Append(&m_separator, 1)))
        if (0 < (length = m_statPath.Append(dirent.d_name)))
        if ((chars = m_statPath.Chars(length)) && (0 < length))
        {
            DBT("() stat(\"%s\", ...)...\n", chars);

            if ((err = stat(chars, &m_st)))
                DBI("() failed to stat \"%s\"\n", chars);

            else {
                if ((err = lstat(chars, &m_lst))) {
                    DBI("() failed to lstat \"%s\"\n", chars);
                    memset(&m_lst, 0, sizeof(m_lst));
                }
                if (0 < (type = GetFoundEntryAttributes()))
                    error = EV_ERROR_NONE;
            }
        }
#endif // defined(WIN32)

        if (!error)
        if (!(unequal = m_name.Compare(m_currentDirectoryName)))
            SetIsCurrent();
        else
        if (!(unequal = m_name.Compare(m_parentDirectoryName)))
            SetIsParent();

        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: ClearFoundEntryAttributes
    //
    //   Author: $author$
    //     Date: 5/22/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ClearFoundEntryAttributes() 
    {
        EvError error = CExtends::ClearFoundEntryAttributes();
        SetIsCircular(false);
        SetIsCurrent(false);
        SetIsParent(false);
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: CopyFileTimesTo
    //
    //   Author: $author$
    //     Date: 9/16/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError CopyFileTimesTo
    (EvFileSystemEntryTimes& fileTimes) const
    {
        const EvFileTime& createdTime = GetCreatedFileTime();
        const EvFileTime& changedTime = GetChangedFileTime();
        const EvFileTime& modifiedTime = GetModifiedFileTime();
        const EvFileTime& accessedTime = GetAccessedFileTime();
        EvError error = EV_ERROR_FAILED;
        EvError error2;
        if (!(error2 = fileTimes.SetCreatedFileTime(createdTime)))
        if (!(error2 = fileTimes.SetChangedFileTime(changedTime)))
        if (!(error2 = fileTimes.SetModifiedFileTime(modifiedTime)))
        if (!(error2 = fileTimes.SetAccessedFileTime(accessedTime)))
            error = EV_ERROR_NONE;
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetNamet
    //
    //   Author: $author$
    //     Date: 5/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG SetNamet
    (const TCHAR* chars, LONG length=-1) 
    {
        m_name.Assignt(chars, length);
        m_namet.Assign(chars, length);
        length = m_namet.Length();
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetNamet
    //
    //   Author: $author$
    //     Date: 5/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const TCHAR* GetNamet
    (LONG& length) const 
    {
        const TCHAR* chars = m_namet.Chars(length);
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetIsCircular
    //
    //   Author: $author$
    //     Date: 5/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int SetIsCircular(bool is=true) 
    {
        m_isCircular = is;
        return m_isCircular;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetIsCircular
    //
    //   Author: $author$
    //     Date: 5/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetIsCircular() const 
    {
        return m_isCircular;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetIsCurrent
    //
    //   Author: $author$
    //     Date: 5/20/2008
    ///////////////////////////////////////////////////////////////////////
    virtual bool SetIsCurrent
    (bool is=true) 
    {
        if ((m_isCurrent = is))
        {
            m_isCircular = true;
            m_isParent = false;
        }
        return m_isCurrent;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetIsCurrent
    //
    //   Author: $author$
    //     Date: 5/20/2008
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetIsCurrent() const 
    {
        return m_isCurrent;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetIsParent
    //
    //   Author: $author$
    //     Date: 5/20/2008
    ///////////////////////////////////////////////////////////////////////
    virtual bool SetIsParent
    (bool is=true) 
    {
        if ((m_isParent = is))
        {
            m_isCircular = true;
            m_isCurrent = false;
        }
        return m_isParent;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetIsParent
    //
    //   Author: $author$
    //     Date: 5/20/2008
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetIsParent() const 
    {
        return m_isParent;
    }
};

///////////////////////////////////////////////////////////////////////
//  Class: CEvFileDirectoryEntry
//
// Author: $author$
//   Date: 5/3/2007
///////////////////////////////////////////////////////////////////////
class CEvFileDirectoryEntry
: virtual public EvFileDirectoryEntry,
  public CEvFileSystemDirectoryEntry
{
public:
    typedef EvFileDirectoryEntry CImplements;
    typedef CEvFileSystemDirectoryEntry CExtends;
    typedef CEvFileDirectoryEntry CDerives;

    ///////////////////////////////////////////////////////////////////////
    // Function: GetNextEntry
    //
    //   Author: $author$
    //     Date: 5/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError GetNextEntry() 
    {
        EvError error = EV_ERROR_FAILED;

        if (INVALID_DIRECTORY == m_attached)
            return EV_ERROR_NOT_ATTACHED;

        ClearFoundEntryAttributes();

#if defined(WIN32) 
// Windows
        if (FindNextFile(m_attached, &m_win32FindData))
            error = GetFoundEntry();
#else // defined(WIN32) 
// Unix
        if ((m_dirent = readdir(m_attached)))
            error = GetFoundEntry();
#endif // defined(WIN32)
        return error;
    }
};
#endif // _CEVFILEDIRECTORYENTRY_HPP
