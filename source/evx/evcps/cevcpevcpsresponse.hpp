///////////////////////////////////////////////////////////////////////
//   File: cevcpevcpsresponse.hpp
//
// Author: $author$
//   Date: 11/28/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCPEVCPSRESPONSE_HPP
#define _CEVCPEVCPSRESPONSE_HPP

#include "cevcpresponsecontent.hpp"
#include "cevcpshexencoder.hpp"
#include "cevcpsbase.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpEvcpsResponse
//
// Author: $author$
//   Date: 11/28/2007
///////////////////////////////////////////////////////////////////////
class CEvcpEvcpsResponse
: public CEvcpResponseContent
{
public:
    typedef CEvcpResponseContent CExtends;
    typedef CEvcpEvcpsResponse CDerives;

    CEvcpsBase& m_response;
    CEvcpsEncoder m_nullEncoder;
    CEvcpsHexEncoder m_hexEncoder;
    CEvcpsEncoder* m_encoder;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpEvcpsResponse
    //
    //       Author: $author$
    //         Date: 11/28/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpEvcpsResponse
    (EvcpHeader& header,
     CEvcpsBase& response) 
    : CExtends(header),
      m_response(response),
      m_nullEncoder(m_response),
      m_hexEncoder(m_response),
      m_encoder(&m_nullEncoder) 
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetFields
    //
    //   Author: $author$
    //     Date: 11/28/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError SetFields
    (const char* evcPath, 
     const char* encoding,
     const char* statusDescription, 
     UINT statusCode) 
    {
        EvError error = SetFields
        (EVCP_REQUEST_ACTION_NAME_EVCPS,
         evcPath, encoding, statusDescription, statusCode);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: SetFields
    //
    //   Author: $author$
    //     Date: 11/28/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError SetFields
    (const char* evcAction, 
     const char* evcPath, 
     const char* encoding,
     const char* statusDescription, 
     UINT statusCode) 
    {
        EvError error = EV_ERROR_FAILED;
        EvError error2;
        EvcpHeaderField* field;
        int unequal;

        if ((error2 = CExtends::SetFields
            (evcAction, evcPath, statusDescription, statusCode)))
            return error2;

        if ((field = m_header.SetField
            (EVCP_HEADER_FIELD_NAME_TRANSFER_ENCODING, encoding)))
        {
            if ((unequal = field->CompareFieldValue
                (EVCP_HEADER_FIELD_NAME_ENCODING_HEX)))
                m_encoder = &m_nullEncoder;
            else m_encoder = &m_hexEncoder;

            error = EV_ERROR_NONE;
        }
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: RemoveFields
    //
    //   Author: $author$
    //     Date: 12/13/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError RemoveFields() 
    {
        EvError error = EV_ERROR_FAILED;
        EvError error1, error2;

        m_encoder = &m_nullEncoder;

        error1 = m_header.RemoveField
        (EVCP_HEADER_FIELD_NAME_TRANSFER_ENCODING);

        if (!(error2 = CExtends::RemoveFields()) && !error1)
            error = EV_ERROR_NONE;

        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Read
    //
    //   Author: $author$
    //     Date: 11/22/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Read
    (EvCharReader& reader) 
    {
        LONG length = -EV_ERROR_FAILED;
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Write
    //
    //   Author: $author$
    //     Date: 11/22/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Write
    (EvCharWriter& writer) 
    {
        LONG length = -EV_ERROR_FAILED;
        LONG count1, count2;
        EvcpHeaderField* field;

        if (0 > (count2 = m_contentWriter.Reset()))
            return length;

        if (0 > (count2 = m_encoder->Write(m_contentWriter)))
            return length;

        if (!(field = m_header.SetFieldUnsigned
            (EVCP_HEADER_FIELD_NAME_CONTENT_LENGTH, count2)))
            return length;

        if (0 > (count1 = CExtends::Write(writer)))
            return length;

        if (0 > (count2 = m_content.Write(writer)))
            return length;

        length = count1 + count2;
        return length;
    }
};
#endif // _CEVCPEVCPSRESPONSE_HPP
