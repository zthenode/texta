///////////////////////////////////////////////////////////////////////
//   File: cevcpssecurityparameters.hpp
//
// Author: $author$
//   Date: 12/1/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCPSSECURITYPARAMETERS_HPP
#define _CEVCPSSECURITYPARAMETERS_HPP

#include "cevcpsbase.hpp"
#include "cevcpsciphersuite.hpp"
#include "cevcpsmastersecret.hpp"
#include "cevcpsrandom.hpp"
#include "cevcpskeyexchange.hpp"
#include "cevcpsmac.hpp"
#include "cevcpscipher.hpp"
#include "cevarraywriter.hpp"
#include "evcipher.hpp"
#include "evhash.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpsSecurityParameters
//
// Author: $author$
//   Date: 12/1/2007
///////////////////////////////////////////////////////////////////////
class CEvcpsSecurityParameters
: public CEvcpsBase
{
public:
    typedef CEvcpsBase CExtends;
    typedef CEvcpsSecurityParameters CDerives;

    BYTE m_bulkCipherAlgorithm;
    BYTE m_cipherType;
    BYTE m_blockSize;
    BYTE m_keySize;
    BYTE m_ivSize;

    BYTE m_macAlgorithm;
    BYTE m_hashSize;

    BYTE m_keyMaterialLength;

    BYTE m_masterSecret[EVCPS_MASTER_SECRET_SIZE];
    BYTE m_clientRandom[EVCPS_RANDOM_SIZE];
    BYTE m_serverRandom[EVCPS_RANDOM_SIZE];

    CEvCharArrayWriter m_masterSecretWriter;
    CEvCharArrayWriter m_clientRandomWriter;
    CEvCharArrayWriter m_serverRandomWriter;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpsSecurityParameters
    //
    //       Author: $author$
    //         Date: 12/1/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpsSecurityParameters()
    : m_masterSecretWriter
      ((char&)(m_masterSecret[0]), sizeof(m_masterSecret)),

      m_clientRandomWriter
      ((char&)(m_clientRandom[0]), sizeof(m_clientRandom)),

      m_serverRandomWriter
      ((char&)(m_serverRandom[0]), sizeof(m_serverRandom))
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Generate
    //
    //   Author: $author$
    //     Date: 12/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Generate
    (CEvcpsCipherSuite& cipherSuite,
     CEvcpsMasterSecret& masterSecret,
     CEvcpsRandom& clientRandom,
     CEvcpsRandom& serverRandom) 
    {
        EvError error = EV_ERROR_FAILED;
        CEvcpsCipherSuiteAttributes& 
        attributes = cipherSuite.GetAttributes();
        LONG count1;

        m_bulkCipherAlgorithm = attributes.m_bulkCipherAlgorithm;
        if (EVCPS_BULK_CIPHER_ALGORITHMS > m_bulkCipherAlgorithm)
        {
            CEvcpsBulkCipherAttributes& cipherAttributes 
            = CEvcpsBulkCipher::m_attributes[m_bulkCipherAlgorithm];

            m_cipherType = cipherAttributes.m_type;
            m_keySize = cipherAttributes.m_keySize;
            m_ivSize = cipherAttributes.m_ivSize;

            m_macAlgorithm = attributes.m_macAlgorithm;
            if (EVCPS_MAC_ALGORITHMS > m_macAlgorithm)
            {
                CEvcpsMacAttributes& macAttributes 
                = CEvcpsMac::m_attributes[m_macAlgorithm];

                m_hashSize = macAttributes.m_hashSize;

                m_keyMaterialLength = m_hashSize*2;
                m_keyMaterialLength += m_keySize*2;
                m_keyMaterialLength += m_ivSize*2;

                if (0 <= (count1 = m_masterSecretWriter.Reset()))
                if (0 < (count1 = masterSecret.Write(m_masterSecretWriter)))
                if (0 <= (count1 = m_clientRandomWriter.Reset()))
                if (0 < (count1 = clientRandom.Write(m_clientRandomWriter)))
                if (0 <= (count1 = m_serverRandomWriter.Reset()))
                if (0 < (count1 = serverRandom.Write(m_serverRandomWriter)))
                    error = EV_ERROR_NONE;
            }
        }
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: SetSecret
    //
    //   Author: $author$
    //     Date: 12/14/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError SetSecret
    (CEvcpsMasterSecret& masterSecret,
     CEvcpsRandom& clientRandom,
     CEvcpsRandom& serverRandom) 
    {
        EvError error = EV_ERROR_FAILED;
        LONG count1;

        if (0 <= (count1 = m_masterSecretWriter.Reset()))
        if (0 < (count1 = masterSecret.Write(m_masterSecretWriter)))

        if (0 <= (count1 = m_clientRandomWriter.Reset()))
        if (0 < (count1 = clientRandom.Write(m_clientRandomWriter)))

        if (0 <= (count1 = m_serverRandomWriter.Reset()))
        if (0 < (count1 = serverRandom.Write(m_serverRandomWriter)))
            error = EV_ERROR_NONE;

        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: SetCipherSuite
    //
    //   Author: $author$
    //     Date: 12/14/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError SetCipherSuite
    (CEvcpsCipherSuite& cipherSuite) 
    {
        EvError error = EV_ERROR_FAILED;
        CEvcpsCipherSuiteAttributes& 
        attributes = cipherSuite.GetAttributes();
        LONG count1;

        m_bulkCipherAlgorithm = attributes.m_bulkCipherAlgorithm;
        if (EVCPS_BULK_CIPHER_ALGORITHMS > m_bulkCipherAlgorithm)
        {
            CEvcpsBulkCipherAttributes& cipherAttributes 
            = CEvcpsBulkCipher::m_attributes[m_bulkCipherAlgorithm];

            m_cipherType = cipherAttributes.m_type;
            m_blockSize = cipherAttributes.m_blockSize;
            m_keySize = cipherAttributes.m_keySize;
            m_ivSize = cipherAttributes.m_ivSize;

            m_macAlgorithm = attributes.m_macAlgorithm;
            if (EVCPS_MAC_ALGORITHMS > m_macAlgorithm)
            {
                CEvcpsMacAttributes& macAttributes 
                = CEvcpsMac::m_attributes[m_macAlgorithm];

                m_hashSize = macAttributes.m_hashSize;

                m_keyMaterialLength = m_hashSize*2;
                m_keyMaterialLength += m_keySize*2;
                m_keyMaterialLength += m_ivSize*2;

                error = EV_ERROR_NONE;
            }
        }
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SelectCipher
    //
    //   Author: $author$
    //     Date: 12/5/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvCipher* SelectCipher
    (ULONG& blockSize, EvCipher* ciphers[EVCPS_BULK_CIPHER_ALGORITHMS]) 
    {
        EvCipher* cipher = 0;
        if (EVCPS_BULK_CIPHER_ALGORITHMS > m_bulkCipherAlgorithm)
        if ((cipher = ciphers[m_bulkCipherAlgorithm]))
            blockSize = cipher->GetBlockSize();
        return cipher;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: SelectHash
    //
    //   Author: $author$
    //     Date: 12/5/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvHash* SelectHash
    (ULONG& hashSize, EvHash* hashes[EVCPS_MAC_ALGORITHMS]) 
    {
        EvHash* hash = 0;
        if (EVCPS_MAC_ALGORITHMS > m_macAlgorithm)
        if ((hash = hashes[m_macAlgorithm]))
            hashSize = hash->GetHashSize();
        return hash;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Read
    //
    //   Author: $author$
    //     Date: 12/1/2007
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
    //     Date: 12/1/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Write
    (EvCharWriter& writer) 
    {
        LONG length = -EV_ERROR_FAILED;
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Sizeof
    //
    //   Author: $author$
    //     Date: 12/1/2007
    ///////////////////////////////////////////////////////////////////////
    virtual USHORT Sizeof() const 
    {
        USHORT size = 0;
        return size;
    }
};

#endif // _CEVCPSSECURITYPARAMETERS_HPP
