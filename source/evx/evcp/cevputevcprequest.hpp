///////////////////////////////////////////////////////////////////////
//   File: cevputevcprequest.hpp
//
// Author: $author$
//   Date: 9/4/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVPUTEVCPREQUEST_HPP
#define _CEVPUTEVCPREQUEST_HPP

#include "cevcpfilemessage.hpp"
#include "cevfiletimes2evcpheader.hpp"
#include "evfilesystementrytimes.hpp"
#include "cevbase.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvPutEvcpRequest
//
// Author: $author$
//   Date: 9/4/2007
///////////////////////////////////////////////////////////////////////
class CEvPutEvcpRequest
: public CEvcpFileMessage
{
public:
    typedef CEvcpFileMessage CExtends;
    typedef CEvPutEvcpRequest CDerives;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvPutEvcpRequest
    //
    //       Author: $author$
    //         Date: 9/4/2007
    ///////////////////////////////////////////////////////////////////////
    CEvPutEvcpRequest(EvcpHeader& header)
    : CExtends(header)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvPutEvcpRequest
    //
    //      Author: $author$
    //        Date: 9/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvPutEvcpRequest()
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: AddFirstFields
    //
    //   Author: $author$
    //     Date: 9/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError AddFirstFields
    (const EvFileSystemEntryTimes& fileEntryTimes,
     const char* evcPath, const char* evcAction, 
     bool isBinary, ULONG blockSize, ULONG blockLength,
     const char* connection) 
    {
        EvError error = EV_ERROR_FAILED;
        EvError error2;
        LONG length;
        EvcpHeaderField* field;

        if (0 < (length = m_heading.SetRequestMethod(evcAction)))
        if (0 < (length = m_heading.SetRequestPath(evcPath)))
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
        if ((field = m_header.SetField
            (EVCP_HEADER_FIELD_NAME_CONNECTION, connection)))
            error = EV_ERROR_NONE;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: RemoveFirstFields
    //
    //   Author: $author$
    //     Date: 9/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError RemoveFirstFields
    (const EvFileSystemEntryTimes& fileEntryTimes) 
    {
        EvError error = EV_ERROR_FAILED;
        EvError error2;

        if (!(error2 = m_header.RemoveField
            (EVCP_HEADER_FIELD_NAME_IS_BINARY)))
        if (!(error2 = m_header.RemoveField
            (EVCP_HEADER_FIELD_NAME_BLOCK_SIZE)))
        if (!(error2 = m_fileTimes2Header.RemoveFileTimeFields
            (m_header, fileEntryTimes)))
            error = EV_ERROR_NONE;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: RemoveFields
    //
    //   Author: $author$
    //     Date: 9/13/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError RemoveFields() 
    {
        EvError error = EV_ERROR_FAILED;
        EvError error2;

        if (!(error2 = m_header.RemoveField
            (EVCP_HEADER_FIELD_NAME_BLOCK_LENGTH)))
            error = EV_ERROR_NONE;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: SetFields
    //
    //   Author: $author$
    //     Date: 9/5/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError SetFields
    (ULONG blockLength,
     const char* connection) 
    {
        EvError error = EV_ERROR_FAILED;
        EvcpHeaderField* field;

        if ((field = m_header.SetFieldUnsigned
            (EVCP_HEADER_FIELD_NAME_BLOCK_LENGTH, blockLength)))
        if ((field = m_header.SetField
            (EVCP_HEADER_FIELD_NAME_CONNECTION, connection)))
            error = EV_ERROR_NONE;
        return error;
    }
};
#endif // _CEVPUTEVCPREQUEST_HPP
