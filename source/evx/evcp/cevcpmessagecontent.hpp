///////////////////////////////////////////////////////////////////////
//   File: cevcpmessagecontent.hpp
//
// Author: $author$
//   Date: 12/13/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCPMESSAGECONTENT_HPP
#define _CEVCPMESSAGECONTENT_HPP

#include "cevcpmessage.hpp"
#include "cevcpcharhexdecoder.hpp"
#include "cevcpcharhexencoder.hpp"
#include "cevstringwriter.hpp"
#include "cevstringreader.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpMessageContent
//
// Author: $author$
//   Date: 12/13/2007
///////////////////////////////////////////////////////////////////////
class CEvcpMessageContent
: public CEvcpMessage
{
public:
    typedef CEvcpMessage CExtends;
    typedef CEvcpMessageContent CDerives;

    CEvString m_content;

    CEvStringReader m_contentReader;
    CEvStringWriter m_contentWriter;

    CEvcpCharHexDecoder m_contentHexDecoder;
    CEvcpCharHexEncoder m_contentHexEncoder;

    EvCharReader* m_contentDecoder;
    EvCharWriter* m_contentEncoder;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpMessageContent
    //
    //       Author: $author$
    //         Date: 12/13/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpMessageContent
    (EvcpHeader& header) 
    : CExtends(header),
      m_contentReader(m_content),
      m_contentWriter(m_content),
      m_contentHexDecoder(m_contentReader),
      m_contentHexEncoder(m_contentWriter),
      m_contentDecoder(&m_contentReader),
      m_contentEncoder(&m_contentWriter) 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvcpMessageContent
    //
    //      Author: $author$
    //        Date: 12/13/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvcpMessageContent()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: ReadContent
    //
    //   Author: $author$
    //     Date: 12/13/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG ReadContent
    (EvCharReader& reader,
     EvcpHeader& header) 
    {
        LONG length = -EV_ERROR_FAILED;
        ULONG contentLength;
        LONG count;
        int unequal;

        if (0 > (count = m_contentReader.Reset()))
            return length;

        if (!(contentLength = header.GetFieldUnsigned
            (count, EVCP_HEADER_FIELD_NAME_CONTENT_LENGTH)))

        if (0 <= (count = m_content.Clear()))
            return 0;
        else return length;

        if (0 < (count = m_content.Read(reader, contentLength)))
        {
            if ((unequal = header.CompareField
                (EVCP_HEADER_FIELD_NAME_TRANSFER_ENCODING,
                 EVCP_HEADER_FIELD_NAME_ENCODING_HEX)))
                 m_contentDecoder = &m_contentReader;
            else m_contentDecoder = &m_contentHexDecoder;
            length = count;
        }
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: WriteContent
    //
    //   Author: $author$
    //     Date: 12/13/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG WriteContent
    (EvCharWriter& writer,
     EvcpHeader& header) 
    {
        LONG length = -EV_ERROR_FAILED;
        ULONG contentLength;
        LONG count;

        if (!(contentLength = header.GetFieldUnsigned
            (count, EVCP_HEADER_FIELD_NAME_CONTENT_LENGTH)))
            return 0;

        if (0 < (count = m_content.Write(writer)))
            length = count;

        return length;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetHeaderField
    //
    //   Author: $author$
    //     Date: 12/13/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvcpHeaderField* SetHeaderField
    (const char* name, const char* value) 
    {
        EvcpHeaderField* field = 0;
        int unequal;

        if ((field = CExtends::SetHeaderField(name, value)))

        if (!(unequal = field->CompareFieldName
            (EVCP_HEADER_FIELD_NAME_TRANSFER_ENCODING)))

        if (!(unequal = field->CompareFieldValue
            (EVCP_HEADER_FIELD_NAME_ENCODING_HEX)))
            m_contentEncoder = &m_contentHexEncoder;

        else m_contentEncoder = &m_contentWriter;
        return field;
    }
};
#endif // _CEVCPMESSAGECONTENT_HPP
