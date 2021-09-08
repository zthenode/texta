///////////////////////////////////////////////////////////////////////
//   File: cevfiletimes2evcpheader.hpp
//
// Author: $author$
//   Date: 8/24/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVFILETIMES2EVCPHEADER_HPP
#define _CEVFILETIMES2EVCPHEADER_HPP

#include "evfilesystementrytimes.hpp"
#include "evcpheader.hpp"
#include "cevdatetimewriter.hpp"
#include "cevstringwriter.hpp"
#include "cevstring.hpp"
#include "cevbase.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvFileTimes2EvcpHeader
//
// Author: $author$
//   Date: 8/24/2007
///////////////////////////////////////////////////////////////////////
class CEvFileTimes2EvcpHeader
: public CEvBase
{
public:
    typedef CEvBase CExtends;
    typedef CEvFileTimes2EvcpHeader CDerives;

    CEvString m_fieldName;
    CEvString m_fieldValue;
    CEvStringWriter m_fieldValueWriter;
    CEvDateTimeCharWriter m_dateTimeWriter;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvFileTimes2EvcpHeader
    //
    //       Author: $author$
    //         Date: 8/24/2007
    ///////////////////////////////////////////////////////////////////////
    CEvFileTimes2EvcpHeader()
	: m_fieldValueWriter(m_fieldValue)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvFileTimes2EvcpHeader
    //
    //      Author: $author$
    //        Date: 8/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvFileTimes2EvcpHeader()
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: SetFileTimeFields
    //
    //   Author: $author$
    //     Date: 8/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError SetFileTimeFields
    (EvcpHeader& header,
	 const EvFileSystemEntryTimes& entryTimes) 
    {
        EvError error = EV_ERROR_NONE;
        const char* fileTimeName;
        const char* fileTimeValue;
        const EvFileTime* fileTime;
        EvFileTime::EvType fileTimeType;
        const_CEvFileTimesIterator i;
        EvcpHeaderField *field;
        LONG length;

        for (fileTime = entryTimes.GetFirstFileTime(i); 
             fileTime; fileTime = entryTimes.GetNextFileTime(i))
        {
            if (0 <= (fileTimeType = fileTime->GetType()))
            if ((fileTimeName = EvFileTime::GetTypeName(fileTimeType)))
            if (0 < (length = m_fieldName.Assign
                (EVCP_HEADER_FIELD_NAME_TIME_)))
            if (0 < (length = m_fieldName.Append(fileTimeName)))
            if ((fileTimeName = m_fieldName.Chars(length)) && (0 < length))
            if (0 <= (length = m_fieldValue.Clear()))
            if (0 <= (length = m_dateTimeWriter.Write
                (m_fieldValueWriter, *fileTime)))
            if ((fileTimeValue = m_fieldValue.Chars(length)) && (0 <= length))
			{
				DBT("() file %s time is %s\n", fileTimeName, fileTimeValue);
				if ((field = header.SetField
					(fileTimeName, fileTimeValue)))
					continue;
			}
            break;
        }
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: RemoveFileTimeFields
    //
    //   Author: $author$
    //     Date: 8/29/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError RemoveFileTimeFields
    (EvcpHeader& header,
	 const EvFileSystemEntryTimes& entryTimes) 
    {
        EvError error = EV_ERROR_NONE;
        EvError error2 = EV_ERROR_NONE;
        const char* fileTimeName;
        const EvFileTime* fileTime;
        EvFileTime::EvType fileTimeType;
        const_CEvFileTimesIterator i;
        LONG length;

        for (fileTime = entryTimes.GetFirstFileTime(i); 
             fileTime; fileTime = entryTimes.GetNextFileTime(i))
        {
            if (0 <= (fileTimeType = fileTime->GetType()))
            if ((fileTimeName = EvFileTime::GetTypeName(fileTimeType)))
            if (0 < (length = m_fieldName.Assign
                (EVCP_HEADER_FIELD_NAME_TIME_)))
            if (0 < (length = m_fieldName.Append(fileTimeName)))
            if ((fileTimeName = m_fieldName.Chars(length)) && (0 < length))
			{
				DBT("() remove file %s time field...\n", fileTimeName);
				if ((error2 = header.RemoveField(fileTimeName)))
                {
				    DBE("() ...failed to remove file %s time field\n", fileTimeName);
                    error = EV_ERROR_FAILED;
                }
				else continue;
			}
            break;
        }
        return error;
    }
};
#endif // _CEVFILETIMES2EVCPHEADER_HPP
