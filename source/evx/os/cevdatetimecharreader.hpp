///////////////////////////////////////////////////////////////////////
//   File: cevdatetimecharreader.hpp
//
// Author: $author$
//   Date: 7/11/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVDATETIMECHARREADER_HPP
#define _CEVDATETIMECHARREADER_HPP

#include "cevchar2datetimewriter.hpp"
#include "cevchar2datetimeevents.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvDateTimeCharReader
//
// Author: $author$
//   Date: 7/11/2007
///////////////////////////////////////////////////////////////////////
class CEvDateTimeCharReader
: public CEvChar2DateTimeEvents
{
public:
    typedef CEvChar2DateTimeEvents CExtends;
    typedef CEvDateTimeCharReader CDerives;

    CEvChar2DateTimeWriter m_writer;
    EvDateTime* m_dateTime;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvDateTimeCharReader
    //
    //       Author: $author$
    //         Date: 7/11/2007
    ///////////////////////////////////////////////////////////////////////
    CEvDateTimeCharReader() 
    : m_writer(*this),
      m_dateTime(0)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Read
    //
    //   Author: $author$
    //     Date: 7/11/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Read
    (EvDateTime& dateTime,
     const char* chars,
     LONG length=-1) 
    {
        LONG count = -EV_ERROR_FAILED;
        EvDateTime* oldDateTime = m_dateTime;
        EvError error;

        m_dateTime = &dateTime;

        if (!(error = m_writer.Initialize()))
        {
            count = m_writer.Write(chars, length);
            if ((error = m_writer.Finalize()))
                count = -EV_ERROR_FAILED;
        }
        m_dateTime = oldDateTime;
        return count;
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
        if (m_dateTime)
            m_dateTime->SetYear(value);
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
        if (m_dateTime)
            m_dateTime->SetMonth(value);
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
        if (m_dateTime)
            m_dateTime->SetDay(value);
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
        if (m_dateTime)
            m_dateTime->SetHour(value);
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
        if (m_dateTime)
            m_dateTime->SetMinute(value);
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
        if (m_dateTime)
            m_dateTime->SetSecond(value);
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
        if (m_dateTime)
            m_dateTime->SetMillisecond(value);
        return error;
    }
};
#endif // _CEVDATETIMECHARREADER_HPP
