///////////////////////////////////////////////////////////////////////
//   File: cevcpevcpscontent.hpp
//
// Author: $author$
//   Date: 12/16/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCPEVCPSCONTENT_HPP
#define _CEVCPEVCPSCONTENT_HPP

#include "cevcpmessagecontent.hpp"
#include "cevcpsplaintext.hpp"
#include "cevcpsmessagereadevents.hpp"
#include "cevcpsmessage.hpp"
#include "cevcpsplaintextlist.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpEvcpsContent
//
// Author: $author$
//   Date: 12/15/2007
///////////////////////////////////////////////////////////////////////
template 
<class TEvcpMessageContent,
 class TEvcpsPlaintextList=CEvcpsPlaintextList,
 class TEvcpsPlaintextsIterator=TEvcpsPlaintextList::CPlaintextsIterator,
 class TEvcpsPlaintext=TEvcpsPlaintextList::CPlaintext>

class CEvcpEvcpsContent
: public TEvcpMessageContent
{
public:
    typedef TEvcpMessageContent CExtends;
    typedef CEvcpEvcpsContent CDerives;

    CEvcpsRecord m_evcpsRecord;
    CEvString m_evcpsRecordContent;
    CEvStringReader m_evcpsRecordContentReader;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpEvcpsContent
    //
    //       Author: $author$
    //         Date: 12/15/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpEvcpsContent
    (EvcpHeader& header) 
    : CExtends(header),
      m_evcpsRecordContentReader(m_evcpsRecordContent)
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
     EvCharReader*& contentDecoder,
     TEvcpsPlaintextList& plaintextList) 
    {
        LONG length = -EV_ERROR_FAILED;
        LONG count;

        if (0 <= (count = ReadContent(reader, respHeader)))
        if (contentDecoder)
        if (0 < (length = count))
        if (0 > (count = ReadPlaintext
            (*contentDecoder, message, events, plaintextList)))
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
     EvcpsMessageReadEvents& events,
     TEvcpsPlaintextList& plaintextList) 
    {
        LONG length = -EV_ERROR_FAILED;
        LONG count = 0;
        LONG count1,count2;
        TEvcpsPlaintextsIterator i;
        TEvcpsPlaintext* plaintext;
        BYTE contentType;
        EvError error;

        for (i = plaintextList.m_values.begin();
             i != plaintextList.m_values.end(); i++)
        {
            if ((plaintext = *i))
            if (0 < (count1 = message.Read
                (reader, m_evcpsRecord, m_evcpsRecordContent)))
            if ((contentType = plaintext->GetContentType())
                == m_evcpsRecord.m_contentType)
            if (0 <= (count2 = m_evcpsRecordContentReader.Reset()))
            if (0 <= (count2 = message.ReadContent
                (m_evcpsRecordContentReader, m_evcpsRecord)))
            if (!(error = OnReadPlaintextContent
                (message, *plaintext, events, contentType)))
            {
                count += count1;
                continue;
            }
            return length;
        }
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: OnReadPlaintextContent
    //
    //   Author: $author$
    //     Date: 12/14/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnReadPlaintextContent
    (CEvcpsMessage& message,
     TEvcpsPlaintext& plaintext,
     EvcpsMessageReadEvents& events,
     BYTE contentType) 
    {
        EvError error = EV_ERROR_FAILED;
        switch(contentType)
        {
        case EVCPS_CONTENT_TYPE_CHANGE_CIPHER_SPEC:
            error = OnReadChangeCipherSpecPlaintext
            (message, plaintext, events);
            break;

        case EVCPS_CONTENT_TYPE_ALERT:
            error = OnReadAlertPlaintext
            (message, plaintext, events);
            break;

        case EVCPS_CONTENT_TYPE_HANDSHAKE:
            error = OnReadHandshakePlaintext
            (message, plaintext, events);
            break;

        case EVCPS_CONTENT_TYPE_APPLICATION_DATA:
            error = OnReadApplicationDataPlaintext
            (message, plaintext, events);
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
     TEvcpsPlaintext& plaintext,
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
     TEvcpsPlaintext& plaintext,
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
     TEvcpsPlaintext& plaintext,
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
     TEvcpsPlaintext& plaintext,
     EvcpsMessageReadEvents& events) 
    {
        EvError error = EV_ERROR_FAILED;
        return error;
    }
};
#endif // _CEVCPEVCPSCONTENT_HPP
