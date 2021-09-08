///////////////////////////////////////////////////////////////////////
//   File: cevchar2datetimewriter.hpp
//
// Author: $author$
//   Date: 7/11/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCHAR2DATETIMEWRITER_HPP
#define _CEVCHAR2DATETIMEWRITER_HPP

#include "evchar2datetimeevents.hpp"
#include "cevcharreaderwriter.hpp"
#include "cevstring.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvChar2DateTimeWriter
//
// Author: $author$
//   Date: 7/11/2007
///////////////////////////////////////////////////////////////////////
class CEvChar2DateTimeWriter
: public CEvCharReaderWriter
{
public:
    typedef CEvCharReaderWriter CExtends;
    typedef CEvChar2DateTimeWriter CDerives;

    typedef EvError (CDerives::*MFinal)();
    typedef LONG (CDerives::*MPut)(char c);

    EvChar2DateTimeEvents& m_events;
    MFinal m_final;
    MPut m_put;
    CEvString m_token;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvChar2DateTimeWriter
    //
    //       Author: $author$
    //         Date: 7/11/2007
    ///////////////////////////////////////////////////////////////////////
    CEvChar2DateTimeWriter
    (EvChar2DateTimeEvents& events) 
    : m_events(events),
      m_final(&CDerives::Final),
      m_put(&CDerives::YearPut)
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Initialize
    //
    //   Author: $author$
    //     Date: 7/11/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Initialize() 
    {
        EvError error = EV_ERROR_NONE;
        m_final = &CDerives::Final;
        m_put = &CDerives::YearPut;
        m_token.Clear();
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Finalize
    //
    //   Author: $author$
    //     Date: 7/11/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Finalize() 
    {
        EvError error = EV_ERROR_FAILED;
        if (m_final) error = (this->*m_final)();
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Putc
    //
    //   Author: $author$
    //     Date: 7/11/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Putc(char c) 
    {
        LONG count = -EV_ERROR_FAILED;
        if (m_put) count = (this->*m_put)(c);
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Final
    //
    //   Author: $author$
    //     Date: 7/11/2007
    ///////////////////////////////////////////////////////////////////////
    EvError Final() 
    {
        EvError error = EV_ERROR_NONE;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: MillisecondFinal
    //
    //   Author: $author$
    //     Date: 7/11/2007
    ///////////////////////////////////////////////////////////////////////
    EvError MillisecondFinal() 
    {
        EvError error = EV_ERROR_NONE;
        ULONG value;
        LONG length;
        const char* chars;

        value = m_token.Unsigned(length);
        if ((chars = m_token.Chars(length)) && (0 < length))
            error = m_events.OnMillisecond(value,chars,length);
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Put
    //
    //   Author: $author$
    //     Date: 7/11/2007
    ///////////////////////////////////////////////////////////////////////
    LONG Put
    (char c) 
    {
        LONG length = 1;
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: YearPut
    //
    //   Author: $author$
    //     Date: 7/11/2007
    ///////////////////////////////////////////////////////////////////////
    LONG YearPut
    (char c) 
    {
        LONG length;
        EvError error;
        ULONG value;
        const char* chars;
        switch(c)
        {
        case '/':
            break;
        default:
            length = m_token.Append(&c, 1);
            return length;
        }
        value = m_token.Unsigned(length);
        if ((chars = m_token.Chars(length)) && (0 < length))
        if ((error = m_events.OnYear(value,chars,length)))
            length = -error;
        else length = 1;
        m_token.Clear();
        m_put = &CDerives::MonthPut;
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: MonthPut
    //
    //   Author: $author$
    //     Date: 7/11/2007
    ///////////////////////////////////////////////////////////////////////
    LONG MonthPut
    (char c) 
    {
        LONG length;
        EvError error;
        ULONG value;
        const char* chars;
        switch(c)
        {
        case '/':
            break;
        default:
            length = m_token.Append(&c, 1);
            return length;
        }
        value = m_token.Unsigned(length);
        if ((chars = m_token.Chars(length)) && (0 < length))
        if ((error = m_events.OnMonth(value,chars,length)))
            length = -error;
        else length = 1;
        m_token.Clear();
        m_put = &CDerives::DayPut;
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: DayPut
    //
    //   Author: $author$
    //     Date: 7/11/2007
    ///////////////////////////////////////////////////////////////////////
    LONG DayPut
    (char c) 
    {
        LONG length;
        EvError error;
        ULONG value;
        const char* chars;
        switch(c)
        {
        case ' ':
            break;
        default:
            length = m_token.Append(&c, 1);
            return length;
        }
        value = m_token.Unsigned(length);
        if ((chars = m_token.Chars(length)) && (0 < length))
        if ((error = m_events.OnDay(value,chars,length)))
            length = -error;
        else length = 1;
        m_token.Clear();
        m_put = &CDerives::HourPut;
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: HourPut
    //
    //   Author: $author$
    //     Date: 7/11/2007
    ///////////////////////////////////////////////////////////////////////
    LONG HourPut
    (char c) 
    {
        LONG length;
        EvError error;
        ULONG value;
        const char* chars;
        switch(c)
        {
        case ':':
            break;
        default:
            length = m_token.Append(&c, 1);
            return length;
        }
        value = m_token.Unsigned(length);
        if ((chars = m_token.Chars(length)) && (0 < length))
        if ((error = m_events.OnHour(value,chars,length)))
            length = -error;
        else length = 1;
        m_token.Clear();
        m_put = &CDerives::MinutePut;
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: MinutePut
    //
    //   Author: $author$
    //     Date: 7/11/2007
    ///////////////////////////////////////////////////////////////////////
    LONG MinutePut
    (char c) 
    {
        LONG length;
        EvError error;
        ULONG value;
        const char* chars;
        switch(c)
        {
        case ':':
            break;
        default:
            length = m_token.Append(&c, 1);
            return length;
        }
        value = m_token.Unsigned(length);
        if ((chars = m_token.Chars(length)) && (0 < length))
        if ((error = m_events.OnMinute(value,chars,length)))
            length = -error;
        else length = 1;
        m_token.Clear();
        m_put = &CDerives::SecondPut;
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: SecondPut
    //
    //   Author: $author$
    //     Date: 7/11/2007
    ///////////////////////////////////////////////////////////////////////
    LONG SecondPut
    (char c) 
    {
        LONG length;
        EvError error;
        ULONG value;
        const char* chars;
        switch(c)
        {
        case ':':
            break;
        default:
            length = m_token.Append(&c, 1);
            return length;
        }
        value = m_token.Unsigned(length);
        if ((chars = m_token.Chars(length)) && (0 < length))
        if ((error = m_events.OnSecond(value,chars,length)))
            length = -error;
        else length = 1;
        m_token.Clear();
        m_put = &CDerives::MillisecondPut;
        m_final = &CDerives::MillisecondFinal;
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: MillisecondPut
    //
    //   Author: $author$
    //     Date: 7/11/2007
    ///////////////////////////////////////////////////////////////////////
    LONG MillisecondPut
    (char c) 
    {
        LONG length;
        EvError error;
        ULONG value;
        const char* chars;
        switch(c)
        {
        case ' ':
            break;
        default:
            length = m_token.Append(&c, 1);
            return length;
        }
        value = m_token.Unsigned(length);
        if ((chars = m_token.Chars(length)) && (0 < length))
        if ((error = m_events.OnMillisecond(value,chars,length)))
            length = -error;
        else length = 1;
        m_token.Clear();
        m_put = &CDerives::Put;
        return length;
    }
};
#endif // _CEVCHAR2DATETIMEWRITER_HPP
