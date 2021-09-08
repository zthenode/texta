///////////////////////////////////////////////////////////////////////
//   File: cevcpsfinished.hpp
//
// Author: $author$
//   Date: 11/30/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCPSFINISHED_HPP
#define _CEVCPSFINISHED_HPP

#include "cevcpspseudorandom.hpp"
#include "cevcpsmastersecret.hpp"

#define EVCPS_FINISHED_SIZE \
    TLS_FINISHED_SIZE

#define EVCPS_CLIENT_FINISHED_LABEL \
    TLS_CLIENT_FINISHED_LABEL

#define EVCPS_SERVER_FINISHED_LABEL \
    TLS_SERVER_FINISHED_LABEL

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpsFinished
//
// Author: $author$
//   Date: 11/30/2007
///////////////////////////////////////////////////////////////////////
class CEvcpsFinished
: public CEvcpsPseudoRandom
{
public:
    typedef CEvcpsPseudoRandom CExtends;
    typedef CEvcpsFinished CDerives;

    BYTE m_value[EVCPS_FINISHED_SIZE];

    BYTE m_md5HandshakeMessages[EvMD5::EV_HASH_SIZE];
    BYTE m_sha1HandshakeMessages[EvSHA1::EV_HASH_SIZE];

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpsFinished
    //
    //       Author: $author$
    //         Date: 11/30/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpsFinished() 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpsFinished
    //
    //       Author: $author$
    //         Date: 11/30/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpsFinished
    (EvMD5& md5, EvSHA1& sha1,
     CEvcpsMasterSecret& secret,
     CEvcpsList& handshakeMessages,
     const char* label) 
    {
        EvError error;
        LONG length;
        if (0 > (length = Generate
            (md5, sha1, secret, handshakeMessages, label)))
            throw(error = -length);
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Generate
    //
    //   Author: $author$
    //     Date: 11/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Generate
    (EvMD5& md5, EvSHA1& sha1,
     CEvcpsMasterSecret& secret,
     CEvcpsList& handshakeMessages,
     const char* label) 
    {
        LONG length = -EV_ERROR_FAILED;
        LONG count1;
        BYTE value[EVCPS_FINISHED_SIZE];

        if (0 <= (count1 = m_secret.Clear()))
        if (0 <= (count1 = m_seed.Clear()))

        if (0 < (count1 = secret.Write(m_secretWriter)))

        if (0 < (count1 = m_seedWriter.Write(label)))

        if (0 < (count1 = Hash
            ((m_md5HandshakeMessages), 
             sizeof(m_md5HandshakeMessages),
             md5, handshakeMessages)))

        if (0 < (count1 = Hash
            ((m_sha1HandshakeMessages), 
             sizeof(m_sha1HandshakeMessages),
             sha1, handshakeMessages)))

        if (0 < (count1 = m_seedWriter.Write
            ((char*)(m_md5HandshakeMessages), 
             sizeof(m_md5HandshakeMessages))))

        if (0 < (count1 = m_seedWriter.Write
            ((char*)(m_sha1HandshakeMessages), 
             sizeof(m_sha1HandshakeMessages))))

        if (0 < (count1 = GeneratePseudoRandom
            (m_value, m_value, value, sizeof(m_value), md5, sha1)))
            length = count1;
        return length;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Read
    //
    //   Author: $author$
    //     Date: 11/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Read
    (EvCharReader& reader) 
    {
        LONG length = reader.Read
        ((char*)(m_value), sizeof(m_value));
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Write
    //
    //   Author: $author$
    //     Date: 11/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Write
    (EvCharWriter& writer) 
    {
        LONG length = writer.Write
        ((char*)(m_value), sizeof(m_value));
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Sizeof
    //
    //   Author: $author$
    //     Date: 11/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual USHORT Sizeof() const 
    {
        USHORT size = sizeof(m_value);
        return size;
    }
};

#endif // _CEVCPSFINISHED_HPP
