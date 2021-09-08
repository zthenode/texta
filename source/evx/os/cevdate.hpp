///////////////////////////////////////////////////////////////////////
//   File: cevdate.hpp
//
// Author: $author$
//   Date: 6/14/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVDATE_HPP
#define _CEVDATE_HPP

#include "evdate.hpp"
#include "cevbase.hpp"
#include "evdebug.h"

#if defined(WIN32) 
// Windows
#else // defined(WIN32) 
// Unix
#endif // defined(WIN32)

#undef CDB_CLASS
#define CDB_CLASS "CEvDate"
///////////////////////////////////////////////////////////////////////
//  Class: CEvDate
//
// Author: $author$
//   Date: 6/14/2007
///////////////////////////////////////////////////////////////////////
template 
<class TExtends=CEvBase,
 class TImplements=EvDate>

class CEvDate
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements CImplements;
    typedef TExtends CExtends;
    typedef CEvDate CDerives;

    UINT m_year;
    UINT m_month;
    UINT m_day;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvDate
    //
    //       Author: $author$
    //         Date: 6/14/2007
    ///////////////////////////////////////////////////////////////////////
    CEvDate
    (UINT year=0,
     UINT month=0,
     UINT day=0,
     bool isLocal=false,
     const EvTimezone* timezone=0)
    : m_year(year),
      m_month(month),
      m_day(day)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvDate
    //
    //      Author: $author$
    //        Date: 6/14/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvDate()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: CompareDate
    //
    //   Author: $author$
    //     Date: 6/27/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int CompareDate
    (const EvDate& date,
     bool isLocal=false,
     const EvTimezone* timezone=0) const
    {
        int unequal = 0;
        if (!(unequal = CompareYear(date.GetYear())))
        if (!(unequal  = CompareMonth(date.GetMonth())))
            unequal = CompareDay(date.GetDay());
        return unequal;
    }
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

        //CDBT("() %d/%d/%d\n", year, month, day);
        SetYear(year);
        SetMonth(month);
        SetDay(day);
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: CompareYear
    //
    //   Author: $author$
    //     Date: 6/14/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int CompareYear
    (UINT date) const
    {
        int unequal = 0;
        if (m_year > date)
            unequal = 1;
        else if (m_year < date)
                unequal = -1;
        return unequal;
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
        m_year = date;
        return m_year;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetYear
    //
    //   Author: $author$
    //     Date: 6/14/2007
    ///////////////////////////////////////////////////////////////////////
    virtual INT GetYear() const 
    {
        return m_year;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: CompareMonth
    //
    //   Author: $author$
    //     Date: 6/14/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int CompareMonth
    (UINT date) const
    {
        int unequal = 0;
        if (m_month > date)
            unequal = 1;
        else if (m_month < date)
                unequal = -1;
        return unequal;
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
        m_month = date;
        return m_month;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetMonth
    //
    //   Author: $author$
    //     Date: 6/14/2007
    ///////////////////////////////////////////////////////////////////////
    virtual INT GetMonth() const 
    {
        return m_month;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: CompareDay
    //
    //   Author: $author$
    //     Date: 6/14/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int CompareDay
    (UINT date) const
    {
        int unequal = 0;
        if (m_day > date)
            unequal = 1;
        else if (m_day < date)
                unequal = -1;
        return unequal;
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
        m_day = date;
        return m_day;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetDay
    //
    //   Author: $author$
    //     Date: 6/14/2007
    ///////////////////////////////////////////////////////////////////////
    virtual INT GetDay() const 
    {
        return m_day;
    }
};
#undef CDB_CLASS

#endif // _CEVDATE_HPP
