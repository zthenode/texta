///////////////////////////////////////////////////////////////////////
//   File: cevcpevcpsapplicationdataresponse.hpp
//
// Author: $author$
//   Date: 12/20/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCPEVCPSAPPLICATIONDATARESPONSE_HPP
#define _CEVCPEVCPSAPPLICATIONDATARESPONSE_HPP

#include "cevcpevcpsresponsecontentbase.hpp"
#include "cevcpevcpsresponse.hpp"
#include "cevcpscontext.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpEvcpsApplicationDataResponse
//
// Author: $author$
//   Date: 12/20/2007
///////////////////////////////////////////////////////////////////////
class CEvcpEvcpsApplicationDataResponse
: public CEvcpEvcpsResponseContentBase
{
public:
    typedef CEvcpEvcpsResponseContentBase CExtends;
    typedef CEvcpEvcpsApplicationDataResponse CDerives;

    CEvcpsGenericBlockCipher& m_genericBlockCipher;
    CEvcpsPlaintext m_plaintext;
    CEvcpEvcpsResponse m_response;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpEvcpsApplicationDataResponse
    //
    //       Author: $author$
    //         Date: 12/20/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpEvcpsApplicationDataResponse
    (EvcpHeader& header,
     CEvcpsGenericBlockCipher& genericBlockCipher) 
    : CExtends(header),

      m_genericBlockCipher(genericBlockCipher),

      m_plaintext
      (m_genericBlockCipher, 
       EVCPS_CONTENT_TYPE_APPLICATION_DATA),

      m_response(header, m_plaintext)
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
     const char* encoding,
     const char* statusDescription, 
     UINT statusCode) 
    {
        EvError error = m_response.SetFields
        (evcAction, evcPath, encoding, 
         statusDescription, statusCode);
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
        EvError error = m_response.RemoveFields();
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

        if (0 < (count1 = Encrypt
            (evcpsContext, chars, length)))
            count = Write(writer);
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Encrypt
    //
    //   Author: $author$
    //     Date: 12/20/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Encrypt
    (CEvcpsContext& evcpsContext,
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
        LONG count = m_response.Write(writer);
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: OnReadApplicationDataPlaintext
    //
    //   Author: $author$
    //     Date: 12/20/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnReadApplicationDataPlaintext
    (CEvcpsMessage& message,
     EvcpsMessageReadEvents& events) 
    {
        EvError error = events.OnReadApplicationData(message);
        return error;
    }
};
#endif // _CEVCPEVCPSAPPLICATIONDATARESPONSE_HPP
