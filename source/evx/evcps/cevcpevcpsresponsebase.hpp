///////////////////////////////////////////////////////////////////////
//   File: cevcpevcpsresponsebase.hpp
//
// Author: $author$
//   Date: 12/12/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCPEVCPSRESPONSEBASE_HPP
#define _CEVCPEVCPSRESPONSEBASE_HPP

#include "cevcpresponsecontent.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpEvcpsResponseBase
//
// Author: $author$
//   Date: 12/12/2007
///////////////////////////////////////////////////////////////////////
class CEvcpEvcpsResponseBase
: public CEvcpResponseContent
{
public:
    typedef CEvcpResponseContent CExtends;
    typedef CEvcpEvcpsResponseBase CDerives;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpEvcpsResponseBase
    //
    //       Author: $author$
    //         Date: 12/12/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpEvcpsResponseBase
    (EvcpHeader& header) 
    : CExtends(header)
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Read
    //
    //   Author: $author$
    //     Date: 12/12/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Read
    (EvCharReader& reader,
     CEvcpResponse& response) 
    {
        EvcpHeader& respHeader = response.m_header;
        LONG length = Read(reader, respHeader);
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Read
    //
    //   Author: $author$
    //     Date: 12/12/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Read
    (EvCharReader& reader,
     EvcpHeader& respHeader) 
    {
        LONG length = -EV_ERROR_FAILED;
        ULONG contentLength;
        LONG count;
        EvError error;
        char* chars;
        int unequal;

        if (0 < (contentLength = respHeader.GetFieldUnsigned
            (count, EVCP_HEADER_FIELD_NAME_CONTENT_LENGTH)))

        if (0 < (count = m_content.Read(reader, contentLength)))
        {
            if ((unequal = respHeader.CompareField
                (EVCP_HEADER_FIELD_NAME_TRANSFER_ENCODING,
                 EVCP_HEADER_FIELD_NAME_ENCODING_HEX)))
                 m_contentDecoder = &m_contentReader;
            else m_contentDecoder = &m_contentHexDecoder;
            length = count;
        }

        return length;
    }
};
#endif // _CEVCPEVCPSRESPONSEBASE_HPP
