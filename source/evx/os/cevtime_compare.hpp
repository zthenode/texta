///////////////////////////////////////////////////////////////////////
//   File: cevtime_compare.hpp
//
// Author: $author$
//   Date: 6/28/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVTIME_COMPARE_HPP
#define _CEVTIME_COMPARE_HPP
    ///////////////////////////////////////////////////////////////////////
    // Function: CompareTime
    //
    //   Author: $author$
    //     Date: 6/28/2007
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
        if (!(unequal = CompareSecond(time.GetSecond())))
        if (!(unequal = CompareMillisecond(time.GetMillisecond())))
            {}
        return unequal;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: CompareHour
    //
    //   Author: $author$
    //     Date: 6/28/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int CompareHour
    (UINT time,
     bool is12=false,
     bool isPM=false) const
    {
        int unequal = 0;
        UINT hour;
        
        if ((hour = GetHour(isPM, is12)) > time)
            unequal = 1;
        else if (hour < time)
                unequal = -1;
        return unequal;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: CompareMinute
    //
    //   Author: $author$
    //     Date: 6/28/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int CompareMinute
    (UINT time) const
    {
        int unequal = 0;
        UINT minute;
        
        if ((minute = GetMinute()) > time)
            unequal = 1;
        else if (minute < time)
                unequal = -1;
        return unequal;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: CompareSecond
    //
    //   Author: $author$
    //     Date: 6/28/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int CompareSecond
    (UINT time) const
    {
        int unequal = 0;
        UINT second;
        
        if ((second = GetSecond()) > time)
            unequal = 1;
        else if (second < time)
                unequal = -1;
        return unequal;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: CompareMillisecond
    //
    //   Author: $author$
    //     Date: 6/28/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int CompareMillisecond
    (UINT time) const
    {
        int unequal = 0;
        UINT millisecond;
        
        if ((millisecond = GetMillisecond()) > time)
            unequal = 1;
        else if (millisecond < time)
                unequal = -1;
        return unequal;
    }
#endif // _CEVTIME_COMPARE_HPP
