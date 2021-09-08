///////////////////////////////////////////////////////////////////////
//   File: cevdatetime.hpp
//
// Author: $author$
//   Date: 6/21/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVDATETIME_HPP
#define _CEVDATETIME_HPP

#include "cevtimebasedate.hpp"
#include "evdatetime.hpp"
#include "cevdate.hpp"
#include "cevtime.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvDateTimeT
//
// Author: $author$
//   Date: 6/21/2007
///////////////////////////////////////////////////////////////////////
template
<class TExtends=CEvTimeBaseDate,
 class TImplements=EvDateTime>

class CEvDateTimeT
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements CImplements;
    typedef TExtends CExtends;
    typedef CEvDateTimeT CDerives;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvDateTimeT
    //
    //       Author: $author$
    //         Date: 6/21/2007
    ///////////////////////////////////////////////////////////////////////
    CEvDateTimeT
    (UINT year=0,
     UINT month=0,
     UINT day=0,
     UINT hour=0,
     UINT minute=0,
     UINT second=0,
     UINT millisecond=0,
     bool isLocal=false,
     const EvTimezone* timezone=0,
     bool is12=false,
     bool isPM=false) 
    : CExtends(year, month, day, isLocal, timezone)
    {
        CExtends::CExtends::Construct
        (hour, minute, second, millisecond, is12, isPM);
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvDateTimeT
    //
    //      Author: $author$
    //        Date: 6/21/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvDateTimeT()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: CompareDateTime
    //
    //   Author: $author$
    //     Date: 6/27/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int CompareDateTime
    (const EvDateTime& dateTime,
     bool isLocal=false,
     const EvTimezone* timezone=0,
     bool is12=false,
     bool isPM=false) const 
    {
        int unequal = 0;
        if (!(unequal = (*this).CompareDate(dateTime, isLocal, timezone)))
            unequal = (*this).CompareTime(dateTime, is12, isPM);
        return unequal;
    }
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
        if (!(error = (*this).SetTime(dateTime, is12, isPM, isLocal, timezone)))
            error = (*this).SetDate(dateTime, isLocal, timezone);
        return error;
    }
};

///////////////////////////////////////////////////////////////////////
//  Typedef: CEvDateTime
//
//   Author: $author$
//     Date: 7/13/2007
///////////////////////////////////////////////////////////////////////
typedef CEvDateTimeT<CEvTimeBaseDate>
CEvDateTime;

#endif // _CEVDATETIME_HPP
