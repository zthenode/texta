///////////////////////////////////////////////////////////////////////
//   File: cevunixfiletime.hpp
//
// Author: $author$
//   Date: 8/7/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVUNIXFILETIME_HPP
#define _CEVUNIXFILETIME_HPP

#include "cevunixsystemtime.hpp"
#include "evfiletime.hpp"
#include "evplatform_stat.h"
#include "evplatform_time.h"
#include "evdebug.h"

#if defined(WIN32) 
// Windows
#else // defined(WIN32) 
// Unix
#endif // defined(WIN32)

///////////////////////////////////////////////////////////////////////
//  Class: CEvUnixFileTime
//
// Author: $author$
//   Date: 8/7/2007
///////////////////////////////////////////////////////////////////////
class CEvUnixFileTime
{
public:
    typedef CEvUnixFileTime CDerives;

    time_t m_time;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvUnixFileTime
    //
    //       Author: $author$
    //         Date: 8/7/2007
    ///////////////////////////////////////////////////////////////////////
    CEvUnixFileTime() 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvUnixFileTime
    //
    //       Author: $author$
    //         Date: 9/4/2007
    ///////////////////////////////////////////////////////////////////////
    CEvUnixFileTime(const CEvUnixFileTime& fileTime)
    : m_time(fileTime.GetFileTime())
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: ToTime
    //
    //   Author: $author$
    //     Date: 9/11/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ToTime
    (EvFileTime& fileTime,
     bool isLocal=false) const
    {
        struct tm systemTime;
        EvError error;
        
        if ((error = ToSystemTime(systemTime, isLocal)))
            return error;

        fileTime.SetYear(systemTime.wYear);
        fileTime.SetMonth(systemTime.wMonth);
        fileTime.SetDay(systemTime.wDay);
        fileTime.SetHour(systemTime.wHour);
        fileTime.SetMinute(systemTime.wMinute);
        fileTime.SetSecond(systemTime.wSecond);
        fileTime.SetMillisecond(systemTime.wMilliseconds);
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: FromTime
    //
    //   Author: $author$
    //     Date: 8/7/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError FromTime
    (const EvFileTime& fileTime,
     bool isLocal=false)
    {
        EvError error = EV_ERROR_FAILED;
        struct tm systemTime;
        bool isPM;

        memset(&systemTime, 0, sizeof(struct tm));
        systemTime.tm_year = fileTime.GetYear()-1900;
        systemTime.tm_mon = fileTime.GetMonth()-1;
        systemTime.tm_mday = fileTime.GetDay();
        systemTime.tm_hour = fileTime.GetHour(isPM);
        systemTime.tm_min = fileTime.GetMinute();
        systemTime.tm_sec = fileTime.GetSecond();

		DBT
		("() %d/%d/%d %d:%d:%d\n", 
		 systemTime.tm_year, systemTime.tm_mon, systemTime.tm_mday,
		 systemTime.tm_hour, systemTime.tm_min, systemTime.tm_sec);

        error = FromSystemTime(systemTime, isLocal);
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: ToSystemTime
    //
    //   Author: $author$
    //     Date: 8/10/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ToSystemTime
    (CEvUnixSystemTime& systemTime,
     bool isLocal=false) const
    {
        EvError error = ToSystemTime
        ((CEvUnixSystemTime::CContains&)systemTime, isLocal);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ToSystemTime
    //
    //   Author: $author$
    //     Date: 8/10/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ToSystemTime
    (struct tm& systemTime,
     bool isLocal=false) const
    {
        EvError error = EV_ERROR_NONE;
        if (isLocal)
            localtime_r(&m_time, &systemTime);
        else gmtime_r(&m_time, &systemTime);
        //DBT("() %d/%d/%d\n", systemTime.tm_year, systemTime.tm_mon, systemTime.tm_mday);
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: FromSystemTime
    //
    //   Author: $author$
    //     Date: 8/10/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError FromSystemTime
    (const CEvUnixSystemTime& systemTime,
     bool isLocal=false)
    {
        EvError error = FromSystemTime
        ((const CEvUnixSystemTime::CContains&)systemTime, isLocal);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: FromSystemTime
    //
    //   Author: $author$
    //     Date: 8/7/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError FromSystemTime
    (const struct tm& systemTime,
     bool isLocal=false)
    {
        EvError error = EV_ERROR_NONE;
        struct tm fromTime = systemTime;
        time_t localTime = mktime(&fromTime);

        if (isLocal)
            m_time = localTime;
        else
        {
            time_t globalTime;
            time_t diffTime;
            struct tm tm;

            time(&globalTime);
            gmtime_r(&globalTime, &tm);
            diffTime = mktime(&tm)-globalTime;
            m_time = localTime-diffTime;
            DBT
            ("() global time is %d - %d = %d\n", 
             (int)localTime, (int)diffTime, (int)m_time);
        }
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: GetFileTime
    //
    //   Author: $author$
    //     Date: 8/7/2007
    ///////////////////////////////////////////////////////////////////////
    virtual time_t GetFileTime() const
    {
        return m_time;
    }

    ///////////////////////////////////////////////////////////////////////
    // Operator: =
    //
    //   Author: $author$
    //     Date: 9/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual CEvUnixFileTime& 
    operator = (time_t time) 
    {
        m_time = time;
        return *this;
    }
};

#if defined(WIN32) 
// Windows
#else // defined(WIN32) 
// Unix
///////////////////////////////////////////////////////////////////////
//  Typedef: CEvOSFileTime
//
//   Author: $author$
//     Date: 8/31/2007
///////////////////////////////////////////////////////////////////////
typedef CEvUnixFileTime CEvOSFileTime;
#endif // defined(WIN32)

#endif // _CEVUNIXFILETIME_HPP
