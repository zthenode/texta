///////////////////////////////////////////////////////////////////////
//   File: cevunixsystemtime.hpp
//
// Author: $author$
//   Date: 8/10/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVUNIXSYSTEMTIME_HPP
#define _CEVUNIXSYSTEMTIME_HPP

#include "evplatform_time.h"
#include "evdatetime.hpp"
#include "cevbase.hpp"
#include "evdebug.h"

#if defined(WIN32) 
// Windows
#else // defined(WIN32) 
// Unix
#endif // defined(WIN32)

///////////////////////////////////////////////////////////////////////
//  Class: CEvUnixSystemTime
//
// Author: $author$
//   Date: 8/10/2007
///////////////////////////////////////////////////////////////////////
class CEvUnixSystemTime
: virtual public EvDateTime,
  public CEvBase
{
public:
    typedef EvDateTime CImplements;
    typedef CEvBase CExtends;
    typedef CEvUnixSystemTime CDerives;
    typedef struct tm CContains;

    struct tm m_tm;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvUnixSystemTime
    //
    //       Author: $author$
    //         Date: 8/10/2007
    ///////////////////////////////////////////////////////////////////////
    CEvUnixSystemTime() 
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: GetCurrentDateTime
    //
    //   Author: $author$
    //     Date: 8/12/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError GetCurrentDateTime
    (bool isLocal=false,
     const EvTimezone* timezone=0)
    {
        EvError error = EV_ERROR_FAILED;
        struct tm* tm = 0;
        time_t t;

        DBF("() ...in\n");

        if (INVALID_TIME == (t = time(&t)))
            DBE("() failed on time\n");
        {
            if (isLocal)
            {
                if (timezone)
                {
                    DBE("() use of timezone not implemented\n");
                    return EV_ERROR_NOT_IMPLEMENTED;
                }

                if (!(tm = localtime_r(&t, &m_tm)))
                    DBE("() failed on localtime_r\n");
                else error = EV_ERROR_NONE;
            }
            else if (!(tm = gmtime_r(&t, &m_tm)))
                    DBE("() failed on gmtime_r\n");
            else error = EV_ERROR_NONE;
        }

        DBF("() ...out\n");
        return error;
    }

#include "cevdatetime_compare.hpp"

    ///////////////////////////////////////////////////////////////////////
    // Function: SetDateTime
    //
    //   Author: $author$
    //     Date: 8/10/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError SetDateTime
    (const EvDateTime& dateTime,
     bool isLocal=false,
     const EvTimezone* timezone=0,
     bool is12=false,
     bool isPM=false) 
    {
        EvError error = EV_ERROR_NONE;
        if (!(error = SetTime(dateTime, is12, isPM, isLocal, timezone)))
            error = SetDate(dateTime, isLocal, timezone);
        return error;
    }

#include "cevdate_compare.hpp"

    ///////////////////////////////////////////////////////////////////////
    // Function: SetDate
    //
    //   Author: $author$
    //     Date: 6/21/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError SetDate
    (const EvDate& date,
     bool isLocal=false,
     const EvTimezone* timezone=0) 
    {
        EvError error = EV_ERROR_NONE;
        INT year=date.GetYear();
        INT month=date.GetMonth();
        INT day=date.GetDay();

        //DBT("() %d/%d/%d\n", year, month, day);
        SetYear(year);
        SetMonth(month);
        SetDay(day);
        return error;
    }

#include "cevtime_compare.hpp"

    ///////////////////////////////////////////////////////////////////////
    // Function: SetTime
    //
    //   Author: $author$
    //     Date: 6/21/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError SetTime
    (const EvTime& time,
     bool is12=false,
     bool isPM=false,
     bool isLocal=false,
     const EvTimezone* timezone=0) 
    {
        EvError error = EV_ERROR_NONE;
        SetHour(time.GetHour(isPM));
        SetMinute(time.GetMinute());
        SetSecond(time.GetSecond());
        SetMillisecond(time.GetMillisecond());
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetYear
    //
    //   Author: $author$
    //     Date: 8/10/2007
    ///////////////////////////////////////////////////////////////////////
    virtual INT SetYear
    (UINT date) 
    {
        m_tm.tm_year = date-1900;
        return m_tm.tm_year;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetYear
    //
    //   Author: $author$
    //     Date: 8/10/2007
    ///////////////////////////////////////////////////////////////////////
    virtual INT GetYear() const 
    {
        INT year=m_tm.tm_year;
        //DBT("() %p = %d\n", &m_tm, year);
        return year+1900;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: SetMonth
    //
    //   Author: $author$
    //     Date: 8/10/2007
    ///////////////////////////////////////////////////////////////////////
    virtual INT SetMonth
    (UINT date) 
    {
        m_tm.tm_mon = date-1;
        return m_tm.tm_mon;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetMonth
    //
    //   Author: $author$
    //     Date: 8/10/2007
    ///////////////////////////////////////////////////////////////////////
    virtual INT GetMonth() const 
    {
        return m_tm.tm_mon+1;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: SetDay
    //
    //   Author: $author$
    //     Date: 8/10/2007
    ///////////////////////////////////////////////////////////////////////
    virtual INT SetDay
    (UINT date) 
    {
        m_tm.tm_mday = date;
        return m_tm.tm_mday;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetDay
    //
    //   Author: $author$
    //     Date: 8/10/2007
    ///////////////////////////////////////////////////////////////////////
    virtual INT GetDay() const 
    {
        return m_tm.tm_mday;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: SetDayOfWeek
    //
    //   Author: $author$
    //     Date: 8/10/2007
    ///////////////////////////////////////////////////////////////////////
    virtual INT SetDayOfWeek
    (UINT date) 
    {
        m_tm.tm_wday = date;
        return m_tm.tm_wday;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetDayOfWeek
    //
    //   Author: $author$
    //     Date: 8/10/2007
    ///////////////////////////////////////////////////////////////////////
    virtual INT GetDayOfWeek() const 
    {
        return m_tm.tm_wday;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetHour
    //
    //   Author: $author$
    //     Date: 8/10/2007
    ///////////////////////////////////////////////////////////////////////
    virtual INT SetHour
    (UINT time,
     bool is12=false,
     bool isPM=false) 
    {
        return m_tm.tm_hour = time;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetHour
    //
    //   Author: $author$
    //     Date: 8/10/2007
    ///////////////////////////////////////////////////////////////////////
    virtual INT GetHour
    (bool& isPM,
     bool is12=false) const 
    {
        isPM = false;
        return m_tm.tm_hour;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetMinute
    //
    //   Author: $author$
    //     Date: 8/10/2007
    ///////////////////////////////////////////////////////////////////////
    virtual INT SetMinute
    (UINT time) 
    {
        return m_tm.tm_min = time;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetMinute
    //
    //   Author: $author$
    //     Date: 8/10/2007
    ///////////////////////////////////////////////////////////////////////
    virtual INT GetMinute() const 
    {
        return m_tm.tm_min;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetSecond
    //
    //   Author: $author$
    //     Date: 8/10/2007
    ///////////////////////////////////////////////////////////////////////
    virtual INT SetSecond
    (UINT time) 
    {
        return m_tm.tm_sec = time;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetSecond
    //
    //   Author: $author$
    //     Date: 8/10/2007
    ///////////////////////////////////////////////////////////////////////
    virtual INT GetSecond() const 
    {
        return m_tm.tm_sec;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetMillisecond
    //
    //   Author: $author$
    //     Date: 8/10/2007
    ///////////////////////////////////////////////////////////////////////
    virtual INT SetMillisecond
    (UINT time) 
    {
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetMillisecond
    //
    //   Author: $author$
    //     Date: 8/10/2007
    ///////////////////////////////////////////////////////////////////////
    virtual INT GetMillisecond() const 
    {
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    // Operator: structtm
    //
    //   Author: $author$
    //     Date: 8/10/2007
    ///////////////////////////////////////////////////////////////////////
    virtual operator struct tm&() 
    {
        //DBT("() %p\n", &m_tm);
        return m_tm;
    }
    ///////////////////////////////////////////////////////////////////////
    // Operator: structtm
    //
    //   Author: $author$
    //     Date: 8/10/2007
    ///////////////////////////////////////////////////////////////////////
    virtual operator const struct tm&() const 
    {
        return m_tm;
    }
};

#if defined(WIN32) 
// Windows
#else // defined(WIN32) 
// Unix
///////////////////////////////////////////////////////////////////////
//  Typedef: CEvOSSystemTime
//
//   Author: $author$
//     Date: 8/31/2007
///////////////////////////////////////////////////////////////////////
typedef CEvUnixSystemTime CEvOSSystemTime;
#endif // defined(WIN32)
#endif // _CEVUNIXSYSTEMTIME_HPP
