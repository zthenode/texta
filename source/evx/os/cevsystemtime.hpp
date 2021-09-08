///////////////////////////////////////////////////////////////////////
//   File: cevsystemtime.hpp
//
// Author: $author$
//   Date: 6/18/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVSYSTEMTIME_HPP
#define _CEVSYSTEMTIME_HPP

#include "evsystemtime.hpp"
#include "cevtimebase.hpp"
#include "cevtime.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvSystemTimeT
//
// Author: $author$
//   Date: 6/18/2007
///////////////////////////////////////////////////////////////////////
template
<class TExtends=CEvTimeBase,
 class TImplements=EvSystemTime>

class CEvSystemTimeT
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements CImplements;
    typedef TExtends CExtends;
    typedef CEvSystemTimeT CDerives;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvSystemTimeT
    //
    //       Author: $author$
    //         Date: 6/18/2007
    ///////////////////////////////////////////////////////////////////////
    CEvSystemTimeT
    (UINT hour=0,
     UINT minute=0,
     UINT second=0,
     bool is12=false,
     bool isPM=false)
    : CExtends(hour, minute, second, is12, isPM) 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvSystemTimeT
    //
    //      Author: $author$
    //        Date: 6/18/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvSystemTimeT()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetCurrentTime
    //
    //   Author: $author$
    //     Date: 6/14/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError SetCurrentTime
    (UINT hour,
     UINT minute,
     UINT second,
     bool is12=false,
     bool isPM=false,
     bool isLocal=false,
     const EvTimezone* timezone=0) 
    {
        EvError error = EV_ERROR_NOT_IMPLEMENTED;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetCurrentTime
    //
    //   Author: $author$
    //     Date: 6/14/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError GetCurrentTime
    (UINT& hour,
     UINT& minute,
     UINT& second,
     bool& isPM,
     bool is12=false,
     bool isLocal=false,
     const EvTimezone* timezone=0) 
    {
        EvError error = EV_ERROR_NOT_IMPLEMENTED;

        if (!(error = GetCurrentTime(isLocal)))
        {
            hour = (*this).m_hour;
            minute = (*this).m_minute;
            second = (*this).m_second;
            isPM = false;

            if (is12)
            if ((isPM = (12 <= hour)))
            {
                if (12 < hour)
                    hour -= 12;
                else hour = 12;
            }
            else if (1 > hour)
                    hour = 12;
        }
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetCurrentTime
    //
    //   Author: $author$
    //     Date: 6/14/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError SetCurrentTime
    (bool isLocal=false,
     const EvTimezone* timezone=0) 
    {
        EvError error = EV_ERROR_NOT_IMPLEMENTED;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetCurrentTime
    //
    //   Author: $author$
    //     Date: 6/14/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError GetCurrentTime
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

///////////////////////////////////////////////////////////////////////
//  Typedef: CEvSystemTime
//
//   Author: $author$
//     Date: 7/13/2007
///////////////////////////////////////////////////////////////////////
typedef CEvSystemTimeT<CEvTimeBase>
CEvSystemTime;

#endif // _CEVSYSTEMTIME_HPP
