///////////////////////////////////////////////////////////////////////
//   File: cevcploginrequest.hpp
//
// Author: $author$
//   Date: 12/21/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCPLOGINREQUEST_HPP
#define _CEVCPLOGINREQUEST_HPP

#include "cevcprequest.hpp"
#include "cevcpcharhexencoder.hpp"
#include "cevsha1.hpp"
#include "cevbytereadwritebuffer.hpp"
#include "cevstringwriter.hpp"
#include "cevstring.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpLoginRequest
//
// Author: $author$
//   Date: 12/21/2007
///////////////////////////////////////////////////////////////////////
class CEvcpLoginRequest
: public CEvcpRequest
{
public:
    typedef CEvcpRequest CExtends;
    typedef CEvcpLoginRequest CDerives;

    CEvBYTEReadWriteBuffer m_hash;
    CEvString m_hashString;
    CEvStringWriter m_hashStringWriter;
    CEvcpCharHexEncoder m_hexEncoder;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpLoginRequest
    //
    //       Author: $author$
    //         Date: 12/21/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpLoginRequest(EvcpHeader& header)
    : CExtends(header),
      m_hashStringWriter(m_hashString),
      m_hexEncoder(m_hashStringWriter)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvcpLoginRequest
    //
    //      Author: $author$
    //        Date: 12/21/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvcpLoginRequest()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetFields
    //
    //   Author: $author$
    //     Date: 12/13/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError SetFields
    (EvSHA1& sha1,
     const char* userName, 
     const char* userPassword) 
    {
        EvError error = EV_ERROR_FAILED;
        LONG hashSize = EvSHA1::EV_HASH_SIZE;
        EvError error2;
        BYTE* bytes;
        const char* chars;
        LONG length;

        if (!(error2 = m_hash.AllocateBuffer(hashSize)))
        if ((bytes = m_hash.GetWriteBuffer(length))
            && (hashSize <= length))
        if (0 <= (length = sha1.Initialize()))
        if (0 < (length = m_hashString.Assign(userName)))
        if ((chars = m_hashString.HasChars(length)))
        if (0 < (length = sha1.Hash((const BYTE*)(chars), length)))
        if (0 < (length = m_hashString.Assign(userPassword)))
        if ((chars = m_hashString.HasChars(length)))
        if (0 < (length = sha1.Hash((const BYTE*)(chars), length)))
        if (0 < (length = sha1.Finalize(bytes, hashSize)))
        if (0 <= (length = m_hashStringWriter.Reset()))
        if (0 < (length = m_hexEncoder.Write
            ((char*)(bytes), hashSize)))
        if ((chars = m_hashString.HasChars(length)))
        if (!(error2 = CExtends::SetFields
            (EVCP_REQUEST_ACTION_NAME_LOGIN, userName, 
             EVCP_HEADER_FIELD_VALUE_CONNECTION_KEEPALIVE)))
        if (!(error2 = SetField
            (EVCP_HEADER_FIELD_NAME_CREDENTIALS, chars)))
            error = EV_ERROR_NONE;
        else CExtends::RemoveFields();

        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: RemoveFields
    //
    //   Author: $author$
    //     Date: 12/25/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError RemoveFields() 
    {
        EvError error = EV_ERROR_NONE;
        EvError error2;

        if ((error2 = RemoveField
            (EVCP_HEADER_FIELD_NAME_CREDENTIALS)))
            error = EV_ERROR_FAILED;

        if ((error2 = CExtends::RemoveFields()))
            error = EV_ERROR_FAILED;
        return error;
    }
};
#endif // _CEVCPLOGINREQUEST_HPP
