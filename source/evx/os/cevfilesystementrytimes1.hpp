///////////////////////////////////////////////////////////////////////
//   File: cevfilesystementrytimes.hpp
//
// Author: $author$
//   Date: 6/21/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVFILESYSTEMENTRYTIMES_HPP
#define _CEVFILESYSTEMENTRYTIMES_HPP

#include "evfilesystementrytimes.hpp"
#include "evfilesystementrybase.hpp"
#include "cevfiletime.hpp"
#include "cevbase.hpp"

#if defined(WIN32) 
// Windows
#include "os/win32/cevwin32filetime.hpp"
#include "os/win32/cevwin32systemtime.hpp"
#else // defined(WIN32) 
// Unix
#include "os/unix/cevunixfiletime.hpp"
#include "os/unix/cevunixsystemtime.hpp"
#endif // defined(WIN32)

///////////////////////////////////////////////////////////////////////
//  Class: CEvFileSystemEntryTimesT
//
// Author: $author$
//   Date: 6/21/2007
///////////////////////////////////////////////////////////////////////
template
<class TExtends=CEvBase,
 class TImplements=EvFileSystemEntryTimes>

class CEvFileSystemEntryTimesT
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements CImplements;
    typedef TExtends CExtends;
    typedef CEvFileSystemEntryTimesT CDerives;

#if defined(WIN32) 
// Windows
    CEvWin32FileTime m_modifiedWin32Time;
    CEvWin32FileTime m_createdWin32Time;
    CEvWin32FileTime m_accessedWin32Time;
    CEvWin32SystemTime m_systemWin32Time;
#else // defined(WIN32) 
// Unix
    CEvUnixFileTime m_modifiedUnixTime;
    CEvUnixFileTime m_changedUnixTime;
    CEvUnixFileTime m_accessedUnixTime;
    CEvUnixSystemTime m_systemUnixTime;
#endif // defined(WIN32)

    CEvFileTime m_modifiedTime;
    CEvFileTime m_accessedTime;
#if defined(WIN32) 
// Windows
    CEvFileTime m_createdTime;
#else // defined(WIN32) 
// Unix
    CEvFileTime m_changedTime;
#endif // defined(WIN32)

    CEvFileTimes m_fileTimes;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvFileSystemEntryTimesT
    //
    //       Author: $author$
    //         Date: 6/21/2007
    ///////////////////////////////////////////////////////////////////////
    CEvFileSystemEntryTimesT() 
    : m_modifiedTime(true, EvFileTime::EV_TIME_MODIFIED)
    , m_accessedTime(true, EvFileTime::EV_TIME_ACCESSED)
#if defined(WIN32) 
// Windows
    , m_createdTime(true, EvFileTime::EV_TIME_CREATED)
#else // defined(WIN32) 
// Unix
    , m_changedTime(true, EvFileTime::EV_TIME_CHANGED)
#endif // defined(WIN32)
    {
        m_fileTimes.push_back(&m_modifiedTime);
        m_fileTimes.push_back(&m_accessedTime);
#if defined(WIN32) 
// Windows
        m_fileTimes.push_back(&m_createdTime);
#else // defined(WIN32) 
// Unix
        m_fileTimes.push_back(&m_changedTime);
#endif // defined(WIN32)
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: GetFileTimes
    //
    //   Author: $author$
    //     Date: 6/22/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError GetFileTimes() 
    {
        EvError error = EV_ERROR_NONE;

#if defined(WIN32) 
// Windows
        if (!(error = m_modifiedWin32Time.ToSystemTime(m_systemWin32Time)))
        if (!(error = m_modifiedTime.SetDateTime(m_systemWin32Time)))
        if (!(error = m_createdWin32Time.ToSystemTime(m_systemWin32Time)))
        if (!(error = m_createdTime.SetDateTime(m_systemWin32Time)))
        if (!(error = m_accessedWin32Time.ToSystemTime(m_systemWin32Time)))
            error = m_accessedTime.SetDateTime(m_systemWin32Time);
#else // defined(WIN32) 
// Unix
        if (!(error = m_modifiedUnixTime.ToSystemTime(m_systemUnixTime)))
        if (!(error = m_modifiedTime.SetDateTime(m_systemUnixTime)))
        if (!(error = m_changedUnixTime.ToSystemTime(m_systemUnixTime)))
        if (!(error = m_changedTime.SetDateTime(m_systemUnixTime)))
        if (!(error = m_accessedUnixTime.ToSystemTime(m_systemUnixTime)))
            error = m_accessedTime.SetDateTime(m_systemUnixTime);
#endif // defined(WIN32)
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetModifiedFileTime
    //
    //   Author: $author$
    //     Date: 8/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError SetModifiedFileTime
    (const EvFileTime& fileTime) 
    {
        EvError error = m_modifiedTime.SetDateTime(fileTime);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetModifiedFileTime
    //
    //   Author: $author$
    //     Date: 6/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const EvFileTime& GetModifiedFileTime() const 
    {
        const EvFileTime& time = m_modifiedTime;
        return time;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetCreatedFileTime
    //
    //   Author: $author$
    //     Date: 8/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError SetCreatedFileTime
    (const EvFileTime& fileTime) 
    {
#if defined(WIN32) 
// Windows
        EvError error = m_createdTime.SetDateTime(fileTime);
#else // defined(WIN32) 
// Unix
        EvError error = EV_ERROR_NONE;
#endif // defined(WIN32)
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetCreatedFileTime
    //
    //   Author: $author$
    //     Date: 6/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const EvFileTime& GetCreatedFileTime() const 
    {
#if defined(WIN32) 
// Windows
        const EvFileTime& time = m_createdTime;
#else // defined(WIN32) 
// Unix
        const EvFileTime& time = m_modifiedTime;
#endif // defined(WIN32)
        return time;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetAccessedFileTime
    //
    //   Author: $author$
    //     Date: 8/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError SetAccessedFileTime
    (const EvFileTime& fileTime) 
    {
        EvError error = m_accessedTime.SetDateTime(fileTime);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetAccessedFileTime
    //
    //   Author: $author$
    //     Date: 6/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const EvFileTime& GetAccessedFileTime() const 
    {
        const EvFileTime& time = m_accessedTime;
        return time;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetChangedFileTime
    //
    //   Author: $author$
    //     Date: 8/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError SetChangedFileTime
    (const EvFileTime& fileTime) 
    {
#if defined(WIN32) 
// Windows
        EvError error = EV_ERROR_NONE;
#else // defined(WIN32) 
// Unix
        EvError error = m_changedTime.SetDateTime(fileTime);
#endif // defined(WIN32)
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetChangedFileTime
    //
    //   Author: $author$
    //     Date: 8/9/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const EvFileTime& GetChangedFileTime() const 
    {
#if defined(WIN32) 
// Windows
        const EvFileTime& time = m_modifiedTime;
#else // defined(WIN32) 
// Unix
        const EvFileTime& time = m_changedTime;
#endif // defined(WIN32)
        return time;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: GetFirstFileTime
    //
    //   Author: $author$
    //     Date: 6/20/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const EvFileTime* GetFirstFileTime
    (const_CEvFileTimesIterator& iterator) const 
    {
        const EvFileTime* time = 0;

        if (m_fileTimes.end() != (iterator = m_fileTimes.begin()))
            time = *iterator;
        return time;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetNextFileTime
    //
    //   Author: $author$
    //     Date: 6/20/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const EvFileTime* GetNextFileTime
    (const_CEvFileTimesIterator& iterator) const 
    {
        const EvFileTime* time = 0;
        const_CEvFileTimesIterator end;

        if (iterator != (end = m_fileTimes.end()))
        if (end != ++iterator)
            time = *iterator;
        return time;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetFirstFileTime
    //
    //   Author: $author$
    //     Date: 6/20/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvFileTime* SetFirstFileTime
    (CEvFileTimesIterator& iterator)
    {
        EvFileTime* time = 0;

        if (m_fileTimes.end() != (iterator = m_fileTimes.begin()))
            time = *iterator;
        return time;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: SetNextFileTime
    //
    //   Author: $author$
    //     Date: 6/20/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvFileTime* SetNextFileTime
    (CEvFileTimesIterator& iterator)
    {
        EvFileTime* time = 0;
        CEvFileTimesIterator end;

        if (iterator != (end = m_fileTimes.end()))
        if (end != ++iterator)
            time = *iterator;
        return time;
    }
};

///////////////////////////////////////////////////////////////////////
//  Typedef: CEvFileSystemEntryTimes
//
//   Author: $author$
//     Date: 7/13/2007
///////////////////////////////////////////////////////////////////////
typedef CEvFileSystemEntryTimesT<CEvBase>
CEvFileSystemEntryTimes;

#endif // _CEVFILESYSTEMENTRYTIMES_HPP
