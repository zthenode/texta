///////////////////////////////////////////////////////////////////////
//   File: cevputevcpresponse.hpp
//
// Author: $author$
//   Date: 9/12/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVPUTEVCPRESPONSE_HPP
#define _CEVPUTEVCPRESPONSE_HPP

#include "cevcpfilemessage.hpp"
#include "cevfiletimes2evcpheader.hpp"
#include "evfilesystementrytimes.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvPutEvcpResponse
//
// Author: $author$
//   Date: 9/12/2007
///////////////////////////////////////////////////////////////////////
class CEvPutEvcpResponse
: public CEvcpFileMessage
{
public:
    typedef CEvcpFileMessage CExtends;
    typedef CEvPutEvcpResponse CDerives;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvPutEvcpResponse
    //
    //       Author: $author$
    //         Date: 9/12/2007
    ///////////////////////////////////////////////////////////////////////
    CEvPutEvcpResponse(EvcpHeader& header)
    : CExtends(header) 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvPutEvcpResponse
    //
    //      Author: $author$
    //        Date: 9/12/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvPutEvcpResponse()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetFields
    //
    //   Author: $author$
    //     Date: 9/12/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError SetFields
    (const char* evcAction, 
     const char* statusDescription, UINT statusCode) 
    {
        EvError error = EV_ERROR_FAILED;
        LONG length;
        EvcpHeaderField* field;

        if (0 < (length = m_heading.
            SetResponseDescription(statusDescription)))
        if (0 <= (length = m_heading.
            SetResponseStatusUnsigned(statusCode)))
        if ((field = m_header.SetField
            (EVCP_HEADER_FIELD_NAME_ACTION, evcAction)))
            error = EV_ERROR_NONE;
        return error;
    }
};
#endif // _CEVPUTEVCPRESPONSE_HPP
