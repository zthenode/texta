///////////////////////////////////////////////////////////////////////
//   File: cevsystemdatetime.hpp
//
// Author: $author$
//   Date: 7/13/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVSYSTEMDATETIME_HPP
#define _CEVSYSTEMDATETIME_HPP

#include "evsystemdatetime.hpp"
#include "cevsystemdate.hpp"
#include "cevsystemtime.hpp"
#include "cevdatetime.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvSystemDateTime
//
// Author: $author$
//   Date: 7/13/2007
///////////////////////////////////////////////////////////////////////
class CEvSystemDateTime
: virtual public EvSystemDateTime,
  public CEvSystemDateT<CEvSystemTimeT<CEvDateTime> >
{
public:
    typedef EvSystemDateTime CImplements;
    typedef CEvSystemDateT<CEvSystemTimeT<CEvDateTime> > CExtends;
    typedef CEvSystemDateTime CDerives;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvSystemDateTime
    //
    //       Author: $author$
    //         Date: 7/13/2007
    ///////////////////////////////////////////////////////////////////////
    CEvSystemDateTime() 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvSystemDateTime
    //
    //      Author: $author$
    //        Date: 7/13/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvSystemDateTime()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetCurrentDateTime
    //
    //   Author: $author$
    //     Date: 7/13/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError SetCurrentDateTime
    (bool isLocal=false,
     const EvTimezone* timezone=0) 
    {
        EvError error = EV_ERROR_NOT_IMPLEMENTED;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetCurrentDateTime
    //
    //   Author: $author$
    //     Date: 7/13/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError GetCurrentDateTime
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
        m_hour = SystemTime.wHour;
        m_minute = SystemTime.wMinute;
        m_second = SystemTime.wSecond;
        m_millisecond = SystemTime.wMilliseconds;
        error = EV_ERROR_NONE;
#else // defined(WIN32) 
// Unix
#endif // defined(WIN32)
        return error;
    }
};
#endif // _CEVSYSTEMDATETIME_HPP
