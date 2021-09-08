///////////////////////////////////////////////////////////////////////
//   File: cevwin32systemtime.hpp
//
// Author: $author$
//   Date: 6/16/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVWIN32SYSTEMTIME_HPP
#define _CEVWIN32SYSTEMTIME_HPP

#include "evplatform.h"
#include "everror.h"
#include "evdatetime.hpp"

#if defined(WIN32) 
// Windows
#else // defined(WIN32) 
// Unix
typedef struct _SYSTEMTIME 
{
   WORD wYear;         // year
   WORD wMonth;        // month (1..12)
   WORD wDayOfWeek;    // day of week (0..6)
   WORD wDay;          // dot of month (1..31)
   WORD wHour;         // hour (0..23)
   WORD wMinute;       // minute (0..59)
   WORD wSecond;       // seond (0..59)
   WORD wMilliseconds; // milliseconds (0..)
} SYSTEMTIME;
#endif // defined(WIN32)

///////////////////////////////////////////////////////////////////////
//  Class: CEvWin32SystemTime
//
// Author: $author$
//   Date: 6/16/2007
///////////////////////////////////////////////////////////////////////
class CEvWin32SystemTime
: virtual public EvDateTime,
  public SYSTEMTIME
{
public:
    typedef EvDateTime CImplements;
    typedef SYSTEMTIME CExtends;
    typedef CEvWin32SystemTime CDerives;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvWin32SystemTime
    //
    //       Author: $author$
    //         Date: 6/16/2007
    ///////////////////////////////////////////////////////////////////////
    CEvWin32SystemTime() 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvWin32SystemTime
    //
    //      Author: $author$
    //        Date: 6/16/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvWin32SystemTime()
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

        if (isLocal)
            GetLocalTime(((CExtends*)this));
        else GetSystemTime(((CExtends*)this));
        error = EV_ERROR_NONE;
        return error;
    }

#include "cevdatetime_compare.hpp"

    ///////////////////////////////////////////////////////////////////////
    // Function: SetDateTime
    //
    //   Author: $author$
    //     Date: 6/21/2007
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
        SetYear(date.GetYear());
        SetMonth(date.GetMonth());
        SetDay(date.GetDay());
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
    //     Date: 6/14/2007
    ///////////////////////////////////////////////////////////////////////
    virtual INT SetYear
    (UINT date) 
    {
        wYear = date;
        return wYear;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetYear
    //
    //   Author: $author$
    //     Date: 6/14/2007
    ///////////////////////////////////////////////////////////////////////
    virtual INT GetYear() const 
    {
        return wYear;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: SetMonth
    //
    //   Author: $author$
    //     Date: 6/14/2007
    ///////////////////////////////////////////////////////////////////////
    virtual INT SetMonth
    (UINT date) 
    {
        wMonth = date;
        return wMonth;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetMonth
    //
    //   Author: $author$
    //     Date: 6/14/2007
    ///////////////////////////////////////////////////////////////////////
    virtual INT GetMonth() const 
    {
        return wMonth;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: SetDay
    //
    //   Author: $author$
    //     Date: 6/14/2007
    ///////////////////////////////////////////////////////////////////////
    virtual INT SetDay
    (UINT date) 
    {
        wDay = date;
        return wDay;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetDay
    //
    //   Author: $author$
    //     Date: 6/14/2007
    ///////////////////////////////////////////////////////////////////////
    virtual INT GetDay() const 
    {
        return wDay;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: SetDayOfWeek
    //
    //   Author: $author$
    //     Date: 6/14/2007
    ///////////////////////////////////////////////////////////////////////
    virtual INT SetDayOfWeek
    (UINT date) 
    {
        wDayOfWeek = date;
        return wDayOfWeek;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetDayOfWeek
    //
    //   Author: $author$
    //     Date: 6/14/2007
    ///////////////////////////////////////////////////////////////////////
    virtual INT GetDayOfWeek() const 
    {
        return wDayOfWeek;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetHour
    //
    //   Author: $author$
    //     Date: 6/14/2007
    ///////////////////////////////////////////////////////////////////////
    virtual INT SetHour
    (UINT time,
     bool is12=false,
     bool isPM=false) 
    {
        return wHour = time;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetHour
    //
    //   Author: $author$
    //     Date: 6/14/2007
    ///////////////////////////////////////////////////////////////////////
    virtual INT GetHour
    (bool& isPM,
     bool is12=false) const 
    {
        isPM = false;
        return wHour;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetMinute
    //
    //   Author: $author$
    //     Date: 6/14/2007
    ///////////////////////////////////////////////////////////////////////
    virtual INT SetMinute
    (UINT time) 
    {
        return wMinute = time;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetMinute
    //
    //   Author: $author$
    //     Date: 6/14/2007
    ///////////////////////////////////////////////////////////////////////
    virtual INT GetMinute() const 
    {
        return wMinute;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetSecond
    //
    //   Author: $author$
    //     Date: 6/14/2007
    ///////////////////////////////////////////////////////////////////////
    virtual INT SetSecond
    (UINT time) 
    {
        return wSecond = time;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetSecond
    //
    //   Author: $author$
    //     Date: 6/14/2007
    ///////////////////////////////////////////////////////////////////////
    virtual INT GetSecond() const 
    {
        return wSecond;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetMillisecond
    //
    //   Author: $author$
    //     Date: 6/14/2007
    ///////////////////////////////////////////////////////////////////////
    virtual INT SetMillisecond
    (UINT time) 
    {
        return wMilliseconds = time;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetMillisecond
    //
    //   Author: $author$
    //     Date: 6/14/2007
    ///////////////////////////////////////////////////////////////////////
    virtual INT GetMillisecond() const 
    {
        return wMilliseconds;
    }
};

#if defined(WIN32) 
// Windows
///////////////////////////////////////////////////////////////////////
//  Typedef: CEvOSSystemTime
//
//   Author: $author$
//     Date: 8/31/2007
///////////////////////////////////////////////////////////////////////
typedef CEvWin32SystemTime CEvOSSystemTime;
#else // defined(WIN32) 
// Unix
#endif // defined(WIN32)

#endif // _CEVWIN32SYSTEMTIME_HPP
