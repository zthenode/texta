///////////////////////////////////////////////////////////////////////
//   File: evrsa.hpp
//
// Author: $author$
//   Date: 10/29/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _EVRSA_HPP
#define _EVRSA_HPP

#include "cevcryptomain.hpp"
#include "cevchar2xwriter.hpp"

#include "evrsa_keys.cpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvRSAMain
//
// Author: $author$
//   Date: 10/29/2007
///////////////////////////////////////////////////////////////////////
class CEvRSAMain
: public CEvCryptoMain
{
public:
    typedef CEvCryptoMain CExtends;
    typedef CEvRSAMain CDerives;

    BYTE m_in[sizeof(rsaPublicM)];
    BYTE m_eout[sizeof(rsaPublicM)];
    BYTE m_dout[sizeof(rsaPublicM)];

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvRSAMain
    //
    //       Author: $author$
    //         Date: 10/30/2007
    ///////////////////////////////////////////////////////////////////////
    CEvRSAMain(const char* dllFilename=DEFAULT_CRYPTO_DLL_NAME)
    : CExtends(dllFilename)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvRSAMain
    //
    //      Author: $author$
    //        Date: 10/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvRSAMain()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Run
    //
    //    Author: $author$
    //      Date: 10/29/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int Run
    (int argc, const char** argv, const char** env) 
    {
        CEvChar2XWriter writer(m_stdOut);
        int err = 0;
        EvError error;
        LONG length;
        EvRSAPublicKey* publicKey;
        EvRSAPrivateKey* privateKey;

        memset(m_in, 0x12, sizeof(m_in));
        memset(m_eout, 0x34, sizeof(m_eout));
        memset(m_dout, 0x56, sizeof(m_dout));

        writer.WriteLine((const char*)m_in, sizeof(m_in));

        if ((publicKey = m_crypto.AcquireRSAPublicKey(error)))
        {
            if (!(error = publicKey->CreateMSB
                (rsaPublicM, sizeof(rsaPublicM), 
                 rsaPublicE, sizeof(rsaPublicE))))

            if (0 < (length = publicKey->Crypt
                (m_eout, sizeof(m_eout), m_in, sizeof(m_in))))
                writer.WriteLine((const char*)m_eout, sizeof(m_eout));

            m_crypto.ReleaseRSAPublicKey(*publicKey);
        }

        if ((privateKey = m_crypto.AcquireRSAPrivateKey(error)))
        {
            if (!(error = privateKey->CreateMSB
                (rsaPrivateP, rsaPrivateQ, 
                 rsaPrivateDmp1, rsaPrivateDmq1, 
                 rsaPrivateIqmp, sizeof(rsaPrivateP))))

            if (0 < (length = privateKey->Crypt
                (m_dout, sizeof(m_dout), m_eout, sizeof(m_eout))))
                writer.WriteLine((const char*)m_dout, sizeof(m_dout));

            m_crypto.ReleaseRSAPrivateKey(*privateKey);
        }
        m_crypto.Close();
        return err;
    }
};

#endif // _EVRSA_HPP
