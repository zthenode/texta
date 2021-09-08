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
#include "evdebug.h"

#if defined(WIN32) 
// Windows
#include "os/win32/cevwin32systemtime.hpp"
#else // defined(WIN32) 
// Unix
#include "os/unix/cevunixsystemtime.hpp"
#endif // defined(WIN32)

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

#if defined(WIN32) 
// Windows
    CEvWin32SystemTime m_systemTime;
#else // defined(WIN32) 
// Unix
    CEvUnixSystemTime m_systemTime;
#endif // defined(WIN32)

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
        EvError error = EV_ERROR_FAILED;
        EvError error2;
        bool isPM;

        DBF("() in...\n");

        if ((error2 = m_systemTime.
            GetCurrentDateTime(isLocal, timezone)))
        {
            DBE("() failed on GetCurrentDateTime\n");
            return error;
        }

        m_year = m_systemTime.GetYear();
        m_month = m_systemTime.GetMonth();
        m_day = m_systemTime.GetDay();
        m_hour = m_systemTime.GetHour(isPM);
        m_minute = m_systemTime.GetMinute();
        m_second = m_systemTime.GetSecond();
        m_millisecond = m_systemTime.GetMillisecond();
        error = EV_ERROR_NONE;

        DBF("() ...out\n");
        return error;
    }
};
#endif // _CEVSYSTEMDATETIME_HPP
