///////////////////////////////////////////////////////////////////////
//   File: cevfilesystementrytimes.hpp
//
// Author: $author$
//   Date: 6/21/2007
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

    CEvOSFileTime m_createdOSFileTime;
    CEvOSFileTime m_changedOSFileTime;
    CEvOSFileTime m_modifiedOSFileTime;
    CEvOSFileTime m_accessedOSFileTime;

    CEvOSSystemTime m_osSystemTime;

    CEvFileTime m_createdTime;
    CEvFileTime m_changedTime;
    CEvFileTime m_modifiedTime;
    CEvFileTime m_accessedTime;

    CEvFileTimes m_fileTimes;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvFileSystemEntryTimesT
    //
    //       Author: $author$
    //         Date: 6/21/2007
    ///////////////////////////////////////////////////////////////////////
    CEvFileSystemEntryTimesT() 
    : m_createdTime(true, EvFileTime::EV_TIME_CREATED)
    , m_changedTime(true, EvFileTime::EV_TIME_CHANGED)
    , m_modifiedTime(true, EvFileTime::EV_TIME_MODIFIED)
    , m_accessedTime(true, EvFileTime::EV_TIME_ACCESSED)
    {
        m_fileTimes.push_back(&m_createdTime);
        m_fileTimes.push_back(&m_changedTime);
        m_fileTimes.push_back(&m_modifiedTime);
        m_fileTimes.push_back(&m_accessedTime);
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

        if (!(error = m_createdOSFileTime.ToSystemTime(m_osSystemTime)))
        if (!(error = m_createdTime.SetDateTime(m_osSystemTime)))

        if (!(error = m_changedOSFileTime.ToSystemTime(m_osSystemTime)))
        if (!(error = m_changedTime.SetDateTime(m_osSystemTime)))

        if (!(error = m_modifiedOSFileTime.ToSystemTime(m_osSystemTime)))
        if (!(error = m_modifiedTime.SetDateTime(m_osSystemTime)))

        if (!(error = m_accessedOSFileTime.ToSystemTime(m_osSystemTime)))
            error = m_accessedTime.SetDateTime(m_osSystemTime);

        return error;
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
        EvError error = m_createdTime.SetDateTime(fileTime);
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
        const EvFileTime& time = m_createdTime;
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
        EvError error = m_changedTime.SetDateTime(fileTime);
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
        const EvFileTime& time = m_changedTime;
        return time;
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
