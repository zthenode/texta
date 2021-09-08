///////////////////////////////////////////////////////////////////////
//   File: cevchar2datetimeevents.hpp
//
// Author: $author$
//   Date: 7/11/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCHAR2DATETIMEEVENTS_HPP
#define _CEVCHAR2DATETIMEEVENTS_HPP

#include "evchar2datetimeevents.hpp"
#include "cevbase.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvChar2DateTimeEvents
//
// Author: $author$
//   Date: 7/11/2007
///////////////////////////////////////////////////////////////////////
class CEvChar2DateTimeEvents
: virtual public EvChar2DateTimeEvents,
  public CEvBase
{
public:
    typedef EvChar2DateTimeEvents CImplements;
    typedef CEvBase CExtends;
    typedef CEvChar2DateTimeEvents CDerives;

    EvChar2DateTimeEvents* m_deligate;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvChar2DateTimeEvents
    //
    //       Author: $author$
    //         Date: 7/11/2007
    ///////////////////////////////////////////////////////////////////////
    CEvChar2DateTimeEvents
    (EvChar2DateTimeEvents* deligate=0) 
    : m_deligate(deligate)
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: OnYear
    //
    //   Author: $author$
    //     Date: 7/11/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnYear
    (ULONG value, const char* chars,
     LONG length=-1) 
    {
        EvError error = EV_ERROR_NONE;
        if (m_deligate)
            error = m_deligate->OnYear(value,chars,length);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: OnMonth
    //
    //   Author: $author$
    //     Date: 7/11/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnMonth
    (ULONG value, const char* chars,
     LONG length=-1) 
    {
        EvError error = EV_ERROR_NONE;
        if (m_deligate)
            error = m_deligate->OnMonth(value,chars,length);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: OnDay
    //
    //   Author: $author$
    //     Date: 7/11/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnDay
    (ULONG value, const char* chars,
     LONG length=-1) 
    {
        EvError error = EV_ERROR_NONE;
        if (m_deligate)
            error = m_deligate->OnDay(value,chars,length);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: OnHour
    //
    //   Author: $author$
    //     Date: 7/11/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnHour
    (ULONG value, const char* chars,
     LONG length=-1) 
    {
        EvError error = EV_ERROR_NONE;
        if (m_deligate)
            error = m_deligate->OnHour(value,chars,length);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: OnMinute
    //
    //   Author: $author$
    //     Date: 7/11/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnMinute
    (ULONG value, const char* chars,
     LONG length=-1) 
    {
        EvError error = EV_ERROR_NONE;
        if (m_deligate)
            error = m_deligate->OnMinute(value,chars,length);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: OnSecond
    //
    //   Author: $author$
    //     Date: 7/11/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnSecond
    (ULONG value, const char* chars,
     LONG length=-1) 
    {
        EvError error = EV_ERROR_NONE;
        if (m_deligate)
            error = m_deligate->OnSecond(value,chars,length);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: OnMillisecond
    //
    //   Author: $author$
    //     Date: 7/11/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnMillisecond
    (ULONG value, const char* chars,
     LONG length=-1) 
    {
        EvError error = EV_ERROR_NONE;
        if (m_deligate)
            error = m_deligate->OnMillisecond(value,chars,length);
        return error;
    }
};
#endif // _CEVCHAR2DATETIMEEVENTS_HPP
