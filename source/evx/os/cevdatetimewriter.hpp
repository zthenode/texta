///////////////////////////////////////////////////////////////////////
//   File: cevdatetimewriter.hpp
//
// Author: $author$
//   Date: 7/11/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVDATETIMEWRITER_HPP
#define _CEVDATETIMEWRITER_HPP

#include "evdatetime.hpp"
#include "cevcharwriter.hpp"
#include "cevbase.hpp"

#define DEFAULT_EVDATE_SEPARATOR '/'
#define DEFAULT_EVTIME_SEPARATOR ':'
#define DEFAULT_EVDATETIME_SEPARATOR ' '

///////////////////////////////////////////////////////////////////////
//  Class: CEvDateTimeWriter
//
// Author: $author$
//   Date: 7/11/2007
///////////////////////////////////////////////////////////////////////
template
<class TChar=CHAR,
 class TSize=ULONG,
 class TLength=LONG,
 class TWriter=EvCHARWriter,
 class TExtends=CEvBase,
 class TImplements=EvBase>

class CEvDateTimeWriter
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements CImplements;
    typedef TExtends CExtends;
    typedef CEvDateTimeWriter CDerives;

    TChar m_dateSeparator;
    TChar m_timeSeparator;
    TChar m_dateTimeSeparator;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvDateTimeWriter
    //
    //       Author: $author$
    //         Date: 7/11/2007
    ///////////////////////////////////////////////////////////////////////
    CEvDateTimeWriter() 
    : m_dateSeparator(DEFAULT_EVDATE_SEPARATOR),
      m_timeSeparator(DEFAULT_EVTIME_SEPARATOR),
      m_dateTimeSeparator(DEFAULT_EVDATETIME_SEPARATOR)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Write
    //
    //   Author: $author$
    //     Date: 7/11/2007
    ///////////////////////////////////////////////////////////////////////
    virtual TLength Write
    (TWriter& writer, const EvDateTime& dateTime) 
    {
        TLength length = 0;
        TLength count;
        ULONG y,mo,d,h,m,s,ms;
        bool isPM;

        y = dateTime.GetYear();
        mo = dateTime.GetMonth();
        d = dateTime.GetDay();

        h = dateTime.GetHour(isPM);
        m = dateTime.GetMinute();
        s = dateTime.GetSecond();
        ms = dateTime.GetMillisecond();

        if (0 <= (count = writer.WriteUnsigned(y)))
            length += count;
        if (0 <= (count = writer.Write(&m_dateSeparator, 1)))
            length += count;

        if (0 <= (count = writer.WriteUnsigned(mo)))
            length += count;
        if (0 <= (count = writer.Write(&m_dateSeparator, 1)))
            length += count;

        if (0 <= (count = writer.WriteUnsigned(d)))
            length += count;
        if (0 <= (count = writer.Write(&m_dateTimeSeparator, 1)))
            length += count;


        if (0 <= (count = writer.WriteUnsigned(h)))
            length += count;
        if (0 <= (count = writer.Write(&m_timeSeparator, 1)))
            length += count;

        if (0 <= (count = writer.WriteUnsigned(m)))
            length += count;
        if (0 <= (count = writer.Write(&m_timeSeparator, 1)))
            length += count;

        if (0 <= (count = writer.WriteUnsigned(s)))
            length += count;
        if (0 <= (count = writer.Write(&m_timeSeparator, 1)))
            length += count;

        if (0 <= (count = writer.WriteUnsigned(ms)))
            length += count;

        return length;
    }
};

///////////////////////////////////////////////////////////////////////
//  Typedef: CEvDateTimeCharWriter
//
//   Author: $author$
//     Date: 7/11/2007
///////////////////////////////////////////////////////////////////////
typedef CEvDateTimeWriter
<char, ULONG, LONG, EvCharWriter>
CEvDateTimeCharWriter;

#endif // _CEVDATETIMEWRITER_HPP
