///////////////////////////////////////////////////////////////////////
//   File: cevcpevcpsapplicationdatarequest.hpp
//
// Author: $author$
//   Date: 12/20/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCPEVCPSAPPLICATIONDATAREQUEST_HPP
#define _CEVCPEVCPSAPPLICATIONDATAREQUEST_HPP

#include "cevcpevcpsrequestcontentbase.hpp"
#include "cevcpevcpsrequest.hpp"
#include "cevcpscontext.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpEvcpsApplicationDataRequest
//
// Author: $author$
//   Date: 12/20/2007
///////////////////////////////////////////////////////////////////////
class CEvcpEvcpsApplicationDataRequest
: public CEvcpEvcpsRequestContentBase
{
public:
    typedef CEvcpEvcpsRequestContentBase CExtends;
    typedef CEvcpEvcpsApplicationDataRequest CDerives;

    CEvcpsGenericBlockCipher& m_genericBlockCipher;
    CEvcpsPlaintext m_plaintext;
    CEvcpEvcpsRequest m_request;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpEvcpsApplicationDataRequest
    //
    //       Author: $author$
    //         Date: 12/20/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpEvcpsApplicationDataRequest
    (EvcpHeader& header,
     CEvcpsGenericBlockCipher& genericBlockCipher) 
    : CExtends(header),

      m_genericBlockCipher(genericBlockCipher),

      m_plaintext
      (m_genericBlockCipher, 
       EVCPS_CONTENT_TYPE_APPLICATION_DATA),

      m_request(header, m_plaintext)
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
        EvError error = m_request.SetFields
        (evcAction, evcPath, connection, encoding);
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
        EvError error = m_request.RemoveFields();
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Write
    //
    //   Author: $author$
    //     Date: 12/20/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Write
    (EvCharWriter& writer, 
     CEvcpsContext& evcpsContext,
     const char* chars, LONG length=-1) 
    {
        LONG count = -EV_ERROR_FAILED;
        LONG count1;

        if (0 < length)
        if (0 < (count1 = m_genericBlockCipher.Encrypt
            (evcpsContext.m_writeSeqNumber, 
             m_plaintext, 
             (const BYTE*)(chars), (ULONG)(length),
             *evcpsContext.m_writeCipher, evcpsContext.m_blockSize, 
             *evcpsContext.m_hash, evcpsContext.m_writeMACSecret, 
             evcpsContext.m_hashSize)))
        if (0 < (count1 = m_request.Write(writer)))
            count = count1;

        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Write
    //
    //   Author: $author$
    //     Date: 12/20/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Write
    (EvCharWriter& writer) 
    {
        LONG length = m_request.Write(writer);
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Read
    //
    //   Author: $author$
    //     Date: 12/20/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Read
    (EvCharReader& reader) 
    {
        LONG length = m_request.Read(reader);
        return length;
    }
};
#endif // _CEVCPEVCPSAPPLICATIONDATAREQUEST_HPP
