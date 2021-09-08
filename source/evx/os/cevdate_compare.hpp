///////////////////////////////////////////////////////////////////////
//   File: cevdate_compare.hpp
//
// Author: $author$
//   Date: 6/28/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVDATE_COMPARE_HPP
#define _CEVDATE_COMPARE_HPP
    ///////////////////////////////////////////////////////////////////////
    // Function: CompareDate
    //
    //   Author: $author$
    //     Date: 6/28/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int CompareDate
    (const EvDate& date,
     bool isLocal=false,
     const EvTimezone* timezone=0) const
    {
        int unequal = 0;
        
        if (!(unequal = CompareYear(date.GetYear())))
        if (!(unequal = CompareMonth(date.GetMonth())))
        if (!(unequal = CompareDay(date.GetDay())))
            {}
        return unequal;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: CompareYear
    //
    //   Author: $author$
    //     Date: 6/28/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int CompareYear
    (UINT date) const
    {
        int unequal = 0;
        UINT year;
        
        if ((year = GetYear()) > date)
            unequal = 1;
        else if (year < date)
                unequal = -1;
        return unequal;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: CompareMonth
    //
    //   Author: $author$
    //     Date: 6/28/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int CompareMonth
    (UINT date) const
    {
        int unequal = 0;
        UINT month;
        
        if ((month = GetMonth()) > date)
            unequal = 1;
        else if (month < date)
                unequal = -1;
        return unequal;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: CompareDay
    //
    //   Author: $author$
    //     Date: 6/28/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int CompareDay
    (UINT date) const
    {
        int unequal = 0;
        UINT day;
        
        if ((day = GetDay()) > date)
            unequal = 1;
        else if (day < date)
                unequal = -1;
        return unequal;
    }
#endif // _CEVDATE_COMPARE_HPP
