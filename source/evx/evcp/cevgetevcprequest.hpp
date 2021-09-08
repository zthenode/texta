///////////////////////////////////////////////////////////////////////
//   File: cevgetevcprequest.hpp
//
// Author: $author$
//   Date: 9/12/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVGETEVCPREQUEST_HPP
#define _CEVGETEVCPREQUEST_HPP

#include "cevcpfilemessage.hpp"
#include "cevfiletimes2evcpheader.hpp"
#include "evfilesystementrytimes.hpp"
#include "cevbase.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvGetEvcpRequest
//
// Author: $author$
//   Date: 9/12/2007
///////////////////////////////////////////////////////////////////////
class CEvGetEvcpRequest
: public CEvcpFileMessage
{
public:
    typedef CEvcpFileMessage CExtends;
    typedef CEvGetEvcpRequest CDerives;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvGetEvcpRequest
    //
    //       Author: $author$
    //         Date: 9/12/2007
    ///////////////////////////////////////////////////////////////////////
    CEvGetEvcpRequest(EvcpHeader& header)
    : CExtends(header) 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvGetEvcpRequest
    //
    //      Author: $author$
    //        Date: 9/12/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvGetEvcpRequest()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: AddFirstFields
    //
    //   Author: $author$
    //     Date: 9/12/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError AddFirstFields
    (const char* evcPath, const char* evcAction, 
     bool isBinary, bool isRecursive, ULONG blockSize,
     const char* connection) 
    {
        EvError error = EV_ERROR_FAILED;
        LONG length;
        EvcpHeaderField* field;

        if (0 < (length = m_heading.SetRequestMethod(evcAction)))
        if (0 < (length = m_heading.SetRequestPath(evcPath)))
        if ((field = m_header.SetField
            (EVCP_HEADER_FIELD_NAME_IS_BINARY, isBinary
             ?EVCP_HEADER_FIELD_VALUE_YES
             :EVCP_HEADER_FIELD_VALUE_NO)))
        if ((field = m_header.SetField
            (EVCP_HEADER_FIELD_NAME_IS_RECURSIVE, isRecursive
             ?EVCP_HEADER_FIELD_VALUE_YES
             :EVCP_HEADER_FIELD_VALUE_NO)))
        if ((field = m_header.SetFieldUnsigned
            (EVCP_HEADER_FIELD_NAME_BLOCK_SIZE, blockSize)))
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
    virtual EvError RemoveFirstFields() 
    {
        EvError error = EV_ERROR_FAILED;
        EvError error2;

        if (!(error2 = m_header.RemoveField
            (EVCP_HEADER_FIELD_NAME_IS_BINARY)))
        if (!(error2 = m_header.RemoveField
            (EVCP_HEADER_FIELD_NAME_IS_RECURSIVE)))
        if (!(error2 = m_header.RemoveField
            (EVCP_HEADER_FIELD_NAME_BLOCK_SIZE)))
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
    (const char* connection) 
    {
        EvError error = EV_ERROR_FAILED;
        EvcpHeaderField* field;

        if ((field = m_header.SetField
            (EVCP_HEADER_FIELD_NAME_CONNECTION, connection)))
            error = EV_ERROR_NONE;
        return error;
    }
};
#endif // _CEVGETEVCPREQUEST_HPP
