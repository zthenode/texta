///////////////////////////////////////////////////////////////////////
//   File: cevcpevcpsrequest.hpp
//
// Author: $author$
//   Date: 11/28/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCPEVCPSREQUEST_HPP
#define _CEVCPEVCPSREQUEST_HPP

#include "cevcprequestcontent.hpp"
#include "cevcpshexencoder.hpp"
#include "cevcpsbase.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpEvcpsRequest
//
// Author: $author$
//   Date: 11/28/2007
///////////////////////////////////////////////////////////////////////
class CEvcpEvcpsRequest
: public CEvcpRequestContent
{
public:
    typedef CEvcpRequestContent CExtends;
    typedef CEvcpEvcpsRequest CDerives;

    CEvcpsBase& m_request;
    CEvcpsEncoder m_nullEncoder;
    CEvcpsHexEncoder m_hexEncoder;
    CEvcpsEncoder* m_encoder;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpEvcpsRequest
    //
    //       Author: $author$
    //         Date: 11/28/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpEvcpsRequest
    (EvcpHeader& header,
     CEvcpsBase& request) 
    : CExtends(header),
      m_request(request),
      m_nullEncoder(m_request),
      m_hexEncoder(m_request),
      m_encoder(&m_nullEncoder)
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetFields
    //
    //   Author: $author$
    //     Date: 11/23/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError SetFields
    (const char* evcAction, 
     const char* evcPath, 
     const char* connection,
     const char* encoding) 
    {
        EvError error = EV_ERROR_FAILED;
        EvError error2;
        EvcpHeaderField* field;
        int unequal;

        if ((error2 = CExtends::SetFields
            (evcAction, evcPath, connection)))
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
#endif // _CEVCPEVCPSREQUEST_HPP
