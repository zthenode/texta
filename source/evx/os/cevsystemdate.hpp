///////////////////////////////////////////////////////////////////////
//   File: cevsystemdate.hpp
//
// Author: $author$
//   Date: 6/18/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVSYSTEMDATE_HPP
#define _CEVSYSTEMDATE_HPP

#include "evsystemdate.hpp"
#include "cevdatebase.hpp"
#include "cevdate.hpp"
#include "cevbase.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvSystemDateT
//
// Author: $author$
//   Date: 6/18/2007
///////////////////////////////////////////////////////////////////////
template
<class TExtends=CEvDateBase,
 class TImplements=EvSystemDate>

class CEvSystemDateT
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements CImplements;
    typedef TExtends CExtends;
    typedef CEvSystemDateT CDerives;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvSystemDateT
    //
    //       Author: $author$
    //         Date: 6/18/2007
    ///////////////////////////////////////////////////////////////////////
    CEvSystemDateT() 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvSystemDateT
    //
    //      Author: $author$
    //        Date: 6/18/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvSystemDateT()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetCurrentDate
    //
    //   Author: $author$
    //     Date: 6/14/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError SetCurrentDate
    (UINT year,
     UINT month,
     UINT day,
     bool isLocal=false,
     const EvTimezone* timezone=0) 
    {
        EvError error = EV_ERROR_NOT_IMPLEMENTED;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetCurrentDate
    //
    //   Author: $author$
    //     Date: 6/14/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError GetCurrentDate
    (UINT& year,
     UINT& month,
     UINT& day,
     bool isLocal=false,
     const EvTimezone* timezone=0)
    {
        EvError error = EV_ERROR_NOT_IMPLEMENTED;

        if (!(error = GetCurrentDate(isLocal, timezone)))
        {
            year = (*this).m_year;
            month = (*this).m_month;
            day = (*this).m_day;
        }
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetCurrentDate
    //
    //   Author: $author$
    //     Date: 6/14/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError SetCurrentDate
    (bool isLocal=false,
     const EvTimezone* timezone=0) 
    {
        EvError error = EV_ERROR_NOT_IMPLEMENTED;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetCurrentDate
    //
    //   Author: $author$
    //     Date: 6/14/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError GetCurrentDate
    (bool isLocal=false,
     const EvTimezone* timezone=0)
    {
        EvError error = EV_ERROR_NOT_IMPLEMENTED;

#if defined(WIN32) 
// Windows
        SYSTEMTIME SystemTime;
        if (isLocal)
            GetLocalTime(&SystemTime);
        else GetSystemTime(&SystemTime);
        m_year = SystemTime.wYear;
        m_month = SystemTime.wMonth;
        m_day = SystemTime.wDay;
        error = EV_ERROR_NONE;
#else // defined(WIN32) 
// Unix
#endif // defined(WIN32)

        return error;
    }
};

///////////////////////////////////////////////////////////////////////
//  Typedef: CEvSystemDate
//
//   Author: $author$
//     Date: 7/13/2007
///////////////////////////////////////////////////////////////////////
typedef CEvSystemDateT<CEvDateBase>
CEvSystemDate;

#endif // _CEVSYSTEMDATE_HPP
