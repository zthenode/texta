///////////////////////////////////////////////////////////////////////
//   File: cevtime.hpp
//
// Author: $author$
//   Date: 6/14/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVTIME_HPP
#define _CEVTIME_HPP

#include "evtime.hpp"
#include "cevbase.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvTime
//
// Author: $author$
//   Date: 6/14/2007
///////////////////////////////////////////////////////////////////////
template 
<class TExtends=CEvBase,
 class TImplements=EvTime>

class CEvTime
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements CImplements;
    typedef TExtends CExtends;
    typedef CEvTime CDerives;

    UINT m_hour;
    UINT m_minute;
    UINT m_second;
    UINT m_millisecond;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvTime
    //
    //       Author: $author$
    //         Date: 6/14/2007
    ///////////////////////////////////////////////////////////////////////
    CEvTime
    (UINT hour=0,
     UINT minute=0,
     UINT second=0,
     UINT millisecond=0,
     bool is12=false,
     bool isPM=false,
     bool isLocal=false,
     const EvTimezone* timezone=0)
    : m_hour(hour),
      m_minute(minute),
      m_second(second),
      m_millisecond(millisecond)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvTime
    //
    //      Author: $author$
    //        Date: 6/14/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvTime()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Construct
    //
    //   Author: $author$
    //     Date: 6/14/2007
    ///////////////////////////////////////////////////////////////////////
    virtual void Construct
    (UINT hour=0,
     UINT minute=0,
     UINT second=0,
     UINT millisecond=0,
     bool is12=false,
     bool isPM=false,
     bool isLocal=false,
     const EvTimezone* timezone=0)
    {
        m_hour = hour;
        m_minute = minute;
        m_second = second;
        m_millisecond = millisecond;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: CompareTimeMillisecond
    //
    //   Author: $author$
    //     Date: 6/27/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int CompareTimeMillisecond
    (const EvTime& time,
     bool is12=false,
     bool isPM=false,
     bool isLocal=false,
     const EvTimezone* timezone=0) const 
    {
        int unequal = 0;
        if (!(unequal = CompareTime
            (time, is12, isPM, isLocal, timezone)))
            unequal = CompareMillisecond(time.GetMillisecond());
        return unequal;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: CompareTime
    //
    //   Author: $author$
    //     Date: 6/27/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int CompareTime
    (const EvTime& time,
     bool is12=false,
     bool isPM=false,
     bool isLocal=false,
     const EvTimezone* timezone=0) const 
    {
        int unequal = 0;
        if (!(unequal = CompareHour(time.GetHour(isPM, is12))))
        if (!(unequal = CompareMinute(time.GetMinute())))
            unequal = CompareSecond(time.GetSecond());
        return unequal;
    }
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
    // Function: CompareHour
    //
    //   Author: $author$
    //     Date: 6/27/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int CompareHour
    (UINT time) const 
    {
        int unequal = 0;
        if (m_hour > time)
            unequal = 1;
        else if (m_hour < time)
                unequal = -1;
        return unequal;
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
        return m_hour = time;
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
        INT time = m_hour;
        isPM = false;
        return time;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: CompareMinute
    //
    //   Author: $author$
    //     Date: 6/27/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int CompareMinute
    (UINT time) const 
    {
        int unequal = 0;
        if (m_minute > time)
            unequal = 1;
        else if (m_minute < time)
                unequal = -1;
        return unequal;
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
        return m_minute = time;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetMinute
    //
    //   Author: $author$
    //     Date: 6/14/2007
    ///////////////////////////////////////////////////////////////////////
    virtual INT GetMinute() const 
    {
        return m_minute;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: CompareSecond
    //
    //   Author: $author$
    //     Date: 6/27/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int CompareSecond
    (UINT time) const 
    {
        int unequal = 0;
        if (m_second > time)
            unequal = 1;
        else if (m_second < time)
                unequal = -1;
        return unequal;
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
        return m_second = time;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetSecond
    //
    //   Author: $author$
    //     Date: 6/14/2007
    ///////////////////////////////////////////////////////////////////////
    virtual INT GetSecond() const 
    {
        return m_second;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: CompareMillisecond
    //
    //   Author: $author$
    //     Date: 6/27/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int CompareMillisecond
    (UINT time) const
    {
        int unequal = 0;
        if (m_millisecond > time)
            unequal = 1;
        else if (m_millisecond < time)
                unequal = -1;
        return unequal;
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
        return m_millisecond = time;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetMillisecond
    //
    //   Author: $author$
    //     Date: 6/14/2007
    ///////////////////////////////////////////////////////////////////////
    virtual INT GetMillisecond() const 
    {
        return m_millisecond;
    }
};

#endif // _CEVTIME_HPP
