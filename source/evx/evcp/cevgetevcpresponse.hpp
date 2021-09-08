///////////////////////////////////////////////////////////////////////
//   File: cevgetevcpresponse.hpp
//
// Author: $author$
//   Date: 9/5/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVGETEVCPRESPONSE_HPP
#define _CEVGETEVCPRESPONSE_HPP

#include "cevcpfilemessage.hpp"
#include "cevfiletimes2evcpheader.hpp"
#include "evfilesystementrytimes.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvGetEvcpResponse
//
// Author: $author$
//   Date: 9/5/2007
///////////////////////////////////////////////////////////////////////
class CEvGetEvcpResponse
: public CEvcpFileMessage
{
public:
    typedef CEvcpFileMessage CExtends;
    typedef CEvGetEvcpResponse CDerives;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvGetEvcpResponse
    //
    //       Author: $author$
    //         Date: 9/5/2007
    ///////////////////////////////////////////////////////////////////////
    CEvGetEvcpResponse(EvcpHeader& header)
    : CExtends(header) 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvGetEvcpResponse
    //
    //      Author: $author$
    //        Date: 9/5/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvGetEvcpResponse()
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: AddFirstFields
    //
    //   Author: $author$
    //     Date: 9/5/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError AddFirstFields
    (const EvFileSystemEntryTimes& fileEntryTimes,
     const char* evcPath, const char* evcAction, 
     const char* statusDescription, UINT statusCode, 
     bool isBinary, ULONG blockSize, ULONG blockLength) 
    {
        EvError error = EV_ERROR_FAILED;
        EvError error2;
        LONG length;
        EvcpHeaderField* field;

        if (0 < (length = m_heading.
            SetResponseDescription(statusDescription)))
        if (0 <= (length = m_heading.
            SetResponseStatusUnsigned(statusCode)))
        if ((field = m_header.SetField
            (EVCP_HEADER_FIELD_NAME_ACTION, evcAction)))
        if ((field = m_header.SetField
            (EVCP_HEADER_FIELD_NAME_PATH, evcPath)))
        if (!(error2 = m_fileTimes2Header.SetFileTimeFields
            (m_header, fileEntryTimes)))
        if ((field = m_header.SetField
            (EVCP_HEADER_FIELD_NAME_IS_BINARY, isBinary
             ?EVCP_HEADER_FIELD_VALUE_YES
             :EVCP_HEADER_FIELD_VALUE_NO)))
        if ((field = m_header.SetFieldUnsigned
            (EVCP_HEADER_FIELD_NAME_BLOCK_SIZE, blockSize)))
        if ((field = m_header.SetFieldUnsigned
            (EVCP_HEADER_FIELD_NAME_BLOCK_LENGTH, blockLength)))
            error = EV_ERROR_NONE;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: RemoveFirstFields
    //
    //   Author: $author$
    //     Date: 9/5/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError RemoveFirstFields
    (const EvFileSystemEntryTimes& fileEntryTimes) 
    {
        EvError error = EV_ERROR_FAILED;
        EvError error2;

        if (!(error2 = m_header.RemoveField
            (EVCP_HEADER_FIELD_NAME_BLOCK_SIZE)))
        if (!(error2 = m_header.RemoveField
            (EVCP_HEADER_FIELD_NAME_IS_BINARY)))
        if (!(error2 = m_fileTimes2Header.RemoveFileTimeFields
            (m_header, fileEntryTimes)))
        if (!(error2 = m_header.RemoveField
            (EVCP_HEADER_FIELD_NAME_PATH)))
        if (!(error2 = m_header.RemoveField
            (EVCP_HEADER_FIELD_NAME_ACTION)))
            error = EV_ERROR_NONE;
        return error;
    }
};
#endif // _CEVGETEVCPRESPONSE_HPP
