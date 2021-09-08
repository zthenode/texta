///////////////////////////////////////////////////////////////////////
//   File: cevcpheader2filetimes.hpp
//
// Author: $author$
//   Date: 9/13/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCPHEADER2FILETIMES_HPP
#define _CEVCPHEADER2FILETIMES_HPP

#include "cevbase.hpp"
#include "cevsystemdatetime.hpp"
#include "cevdatetimecharreader.hpp"
#include "cevfilesystementrytimes.hpp"
#include "evcpheader.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpHeader2FileTimes
//
// Author: $author$
//   Date: 9/13/2007
///////////////////////////////////////////////////////////////////////
class CEvcpHeader2FileTimes
: public CEvBase
{
public:
    typedef CEvBase CExtends;
    typedef CEvcpHeader2FileTimes CDerives;

    CEvString m_fieldName;
    CEvSystemDateTime m_systemDateTime;
    CEvDateTimeCharReader m_dateTimeReader;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpHeader2FileTimes
    //
    //       Author: $author$
    //         Date: 9/13/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpHeader2FileTimes() 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvcpHeader2FileTimes
    //
    //      Author: $author$
    //        Date: 9/13/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvcpHeader2FileTimes()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: GetFileTimeFields
    //
    //   Author: $author$
    //     Date: 9/13/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError GetFileTimeFields
    (EvFileSystemEntryTimes& fileTimes,
     const EvcpHeader& header) 
    {
        EvError error = EV_ERROR_NONE;
        CEvFileTimesIterator i;
        EvFileTime* fileTime;
        EvFileTime::EvType type;
        const char* typeChars;
        const char* fieldChars;
        const char* dateTimeChars;
        LONG length;

        DBF("() in...\n");

        //
        // Get current date and time
        //
        if ((error = m_systemDateTime.GetCurrentDateTime()))
        {
            DBE("() failed to get current date and time\n");
            return error;
        }

        for (fileTime = fileTimes.SetFirstFileTime(i);
             fileTime; fileTime = fileTimes.SetNextFileTime(i))
        {
            type = fileTime->GetType();

            if ((typeChars = EvFileTime::GetTypeName(type)))
            {
                DBT("() getting \"%s\" time\n", typeChars);

                if (0 < (length = m_fieldName.Assign
                    (EVCP_HEADER_FIELD_NAME_TIME_)))

                if (0 < (length = m_fieldName.Append(typeChars)))
                if ((fieldChars = m_fieldName.HasChars(length)))

                if ((dateTimeChars = header.GetField
                    (length, fieldChars, length)) && (0 < length))

                if (0 < (length = m_dateTimeReader.Read
                    (*fileTime, dateTimeChars, length)))
                    continue;
                else DBE("() failed to read date and time from field\n");
            }

            //
            // Set file time to current date and time
            //
            if ((error = fileTime->SetDateTime(m_systemDateTime)))
            {
                DBE("() failed to set \"%s\" time\n", typeChars);
                break;
            }
        }
        DBF("() ...out\n");
        return error;
    }
};
#endif // _CEVCPHEADER2FILETIMES_HPP
