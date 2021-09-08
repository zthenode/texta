///////////////////////////////////////////////////////////////////////
//   File: cevfiletimes2charwriter.hpp
//
// Author: $author$
//   Date: 9/2/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVFILETIMES2CHARWRITER_HPP
#define _CEVFILETIMES2CHARWRITER_HPP

#include "evfilesystementrytimes.hpp"
#include "cevdatetime2charwriter.hpp"
#include "cevbase.hpp"

#define DEFAULT_TIMES2CHAR_NAME_SEPARATOR ": "
#define DEFAULT_TIMES2CHAR_TIME_SEPARATOR "\n"

///////////////////////////////////////////////////////////////////////
//  Class: CEvFileTimes2CharWriter
//
// Author: $author$
//   Date: 9/2/2007
///////////////////////////////////////////////////////////////////////
class CEvFileTimes2CharWriter
: public CEvBase
{
public:
    typedef CEvBase CExtends;
    typedef CEvFileTimes2CharWriter CDerives;

    CEvString m_nameSeparator;
    CEvString m_timeSeparator;
    CEvDateTime2CharWriter m_dateTimeWriter;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvFileTimes2CharWriter
    //
    //       Author: $author$
    //         Date: 9/2/2007
    ///////////////////////////////////////////////////////////////////////
    CEvFileTimes2CharWriter
    (const char* nameSeparator=DEFAULT_TIMES2CHAR_NAME_SEPARATOR,
     const char* timeSeparator=DEFAULT_TIMES2CHAR_TIME_SEPARATOR)
    {
        EvError error;
        LONG length;

        if (nameSeparator)
        if (0 > (length = m_nameSeparator.Assign(nameSeparator)))
            throw(error = -length);

        if (timeSeparator)
        if (0 > (length = m_timeSeparator.Assign(timeSeparator)))
            throw(error = -length);
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvFileTimes2CharWriter
    //
    //      Author: $author$
    //        Date: 9/2/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvFileTimes2CharWriter()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: WriteFileTimes
    //
    //   Author: $author$
    //     Date: 9/2/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG WriteFileTimes
    (EvCharWriter& writer,
	 const EvFileSystemEntryTimes& entryTimes) 
    {
        LONG count = 0;
        LONG length;
        const EvFileTime* fileTime;
        const_CEvFileTimesIterator i;

        for (fileTime = entryTimes.GetFirstFileTime(i); 
             fileTime; fileTime = entryTimes.GetNextFileTime(i))
        {
            if (0 <= (length = WriteFileTime(writer, *fileTime)))
            {
                count += length;
				continue;
            }
            break;
        }
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: WriteFileTime
    //
    //   Author: $author$
    //     Date: 9/3/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG WriteFileTime
    (EvCharWriter& writer,
	 const EvFileTime& fileTime) 
    {
        LONG count = -EV_ERROR_FAILED;
        LONG length = 0;
        const char* chars;
        EvFileTime::EvType fileTimeType;

        if (0 <= (fileTimeType = fileTime.GetType()))
        if ((chars = EvFileTime::GetTypeName(fileTimeType)))
        if (0 <= (length = WriteFileTimeName(writer, chars)))
        {
            count = length;
            if (0 <= (length = m_dateTimeWriter.Write(writer, fileTime)))
            {
                count += length;
                if ((chars = m_timeSeparator.Chars(length)) && (0 < length))
                if (0 <= (length = writer.Write(chars, length)))
                    count += length;
            }
        }
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: WriteFileTimeName
    //
    //   Author: $author$
    //     Date: 9/2/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG WriteFileTimeName
    (EvCharWriter& writer,
	 const char* chars, LONG length=-1) 
    {
        LONG count;
        if (0 <= (count = writer.Write(chars, length)))
        if ((chars = m_nameSeparator.Chars(length)) && (0 < length))
        if (0 <= (length = writer.Write(chars, length)))
            count += length;
        return count;
    }
};
#endif // _CEVFILETIMES2CHARWRITER_HPP
