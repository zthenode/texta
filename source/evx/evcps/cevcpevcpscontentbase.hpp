///////////////////////////////////////////////////////////////////////
//   File: cevcpevcpscontentbase.hpp
//
// Author: $author$
//   Date: 12/20/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCPEVCPSCONTENTBASE_HPP
#define _CEVCPEVCPSCONTENTBASE_HPP

#include "cevcpmessagecontent.hpp"
#include "cevcpsplaintext.hpp"
#include "cevcpsmessagereadevents.hpp"
#include "cevcpsmessage.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpEvcpsContentBase
//
// Author: $author$
//   Date: 12/20/2007
///////////////////////////////////////////////////////////////////////
template
<class TEvcpMessageContent>

class CEvcpEvcpsContentBase
: public TEvcpMessageContent
{
public:
    typedef TEvcpMessageContent CExtends;
    typedef CEvcpEvcpsContentBase CDerives;

    CEvcpsRecord m_evcpsRecord;
    CEvString m_evcpsRecordContent;
    CEvStringReader m_evcpsRecordContentReader;
    CEvStringWriter m_evcpsRecordContentWriter;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpEvcpsContentBase
    //
    //       Author: $author$
    //         Date: 12/20/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpEvcpsContentBase
    (EvcpHeader& header) 
    : CExtends(header),
      m_evcpsRecordContentReader(m_evcpsRecordContent),
      m_evcpsRecordContentWriter(m_evcpsRecordContent) 
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
     EvcpHeader& respHeader,
     CEvcpsMessage& message,
     EvcpsMessageReadEvents& events,
     EvCharReader*& contentDecoder) 
    {
        LONG length = -EV_ERROR_FAILED;
        LONG count;

        if (0 <= (count = ReadContent(reader, respHeader)))
        if (contentDecoder)
        if (0 < (length = count))
        if (0 > (count = ReadPlaintext
            (*contentDecoder, message, events)))
            length = -EV_ERROR_FAILED;

        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ReadPlaintext
    //
    //   Author: $author$
    //     Date: 12/14/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG ReadPlaintext
    (EvCharReader& reader,
     CEvcpsMessage& message,
     EvcpsMessageReadEvents& events) 
    {
        LONG length = -EV_ERROR_FAILED;
        LONG count = 0;
        LONG count1, count2;
        BYTE contentType;
        EvError error;

        do
        {
            if (0 >= (count1 = message.Read
                (reader, m_evcpsRecord, m_evcpsRecordContent)))
            {
                if (0 < count)
                    break;
            }
            else
            if (!(error = OnReadPlaintext
                (message, events, 
                 (contentType = m_evcpsRecord.m_contentType))))

            if (0 <= (count2 = m_evcpsRecordContentReader.Reset()))
            if (0 <= (count2 = message.ReadContent
                (m_evcpsRecordContentReader, m_evcpsRecord)))

            if (!(error = OnReadPlaintextContent
                (message, events, contentType)))
            {
                count += count1;
                continue;
            }
            return length;
        }
        while (0 < count1);
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: OnReadPlaintext
    //
    //   Author: $author$
    //     Date: 12/20/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnReadPlaintext
    (CEvcpsMessage& message,
     EvcpsMessageReadEvents& events,
     BYTE contentType) 
    {
        EvError error = EV_ERROR_FAILED;
        switch(contentType)
        {
        case EVCPS_CONTENT_TYPE_CHANGE_CIPHER_SPEC:
            error = OnReadChangeCipherSpecPlaintext
            (message, events);
            break;

        case EVCPS_CONTENT_TYPE_ALERT:
        case EVCPS_CONTENT_TYPE_HANDSHAKE:
        case EVCPS_CONTENT_TYPE_APPLICATION_DATA:
            error = EV_ERROR_NONE;
            break;
        }
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: OnReadPlaintextContent
    //
    //   Author: $author$
    //     Date: 12/14/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnReadPlaintextContent
    (CEvcpsMessage& message,
     EvcpsMessageReadEvents& events,
     BYTE contentType) 
    {
        EvError error = EV_ERROR_FAILED;
        switch(contentType)
        {
        case EVCPS_CONTENT_TYPE_CHANGE_CIPHER_SPEC:
            error = EV_ERROR_NONE;
            break;

        case EVCPS_CONTENT_TYPE_ALERT:
            error = OnReadAlertPlaintext
            (message, events);
            break;

        case EVCPS_CONTENT_TYPE_HANDSHAKE:
            error = OnReadHandshakePlaintext
            (message, events);
            break;

        case EVCPS_CONTENT_TYPE_APPLICATION_DATA:
            error = OnReadApplicationDataPlaintext
            (message, events);
            break;
        }
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: OnReadChangeCipherSpecPlaintext
    //
    //   Author: $author$
    //     Date: 12/14/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnReadChangeCipherSpecPlaintext
    (CEvcpsMessage& message,
     EvcpsMessageReadEvents& events) 
    {
        EvError error = EV_ERROR_FAILED;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: OnReadAlertPlaintext
    //
    //   Author: $author$
    //     Date: 12/14/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnReadAlertPlaintext
    (CEvcpsMessage& message,
     EvcpsMessageReadEvents& events) 
    {
        EvError error = EV_ERROR_FAILED;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: OnReadHandshakePlaintext
    //
    //   Author: $author$
    //     Date: 12/14/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnReadHandshakePlaintext
    (CEvcpsMessage& message,
     EvcpsMessageReadEvents& events) 
    {
        EvError error = EV_ERROR_FAILED;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: OnReadApplicationDataPlaintext
    //
    //   Author: $author$
    //     Date: 12/14/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnReadApplicationDataPlaintext
    (CEvcpsMessage& message,
     EvcpsMessageReadEvents& events) 
    {
        EvError error = EV_ERROR_FAILED;
        return error;
    }
};
#endif // _CEVCPEVCPSCONTENTBASE_HPP
