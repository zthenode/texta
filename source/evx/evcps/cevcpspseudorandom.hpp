///////////////////////////////////////////////////////////////////////
//   File: cevcpspseudorandom.hpp
//
// Author: $author$
//   Date: 11/30/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCPSPSEUDORANDOM_HPP
#define _CEVCPSPSEUDORANDOM_HPP

#include "cevcpslist.hpp"
#include "cevcharhashwriter.hpp"
#include "cevstringwriter.hpp"
#include "cevstring.hpp"
#include "evmd5.hpp"
#include "evsha1.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpsPseudoRandom
//
// Author: $author$
//   Date: 11/30/2007
///////////////////////////////////////////////////////////////////////
class CEvcpsPseudoRandom
: public CEvcpsBase
{
public:
    typedef CEvcpsBase CExtends;
    typedef CEvcpsPseudoRandom CDerives;

    CEvString m_secret;
    CEvStringWriter m_secretWriter;

    CEvString m_seed;
    CEvStringWriter m_seedWriter;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpsPseudoRandom
    //
    //       Author: $author$
    //         Date: 11/30/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpsPseudoRandom() 
    : m_secretWriter(m_secret),
      m_seedWriter(m_seed)
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: GeneratePseudoRandom
    //
    //   Author: $author$
    //     Date: 11/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG GeneratePseudoRandom
    (BYTE* pseudoRandom,
     BYTE* md5PseudoRandom, 
     BYTE* sha1PseudoRandom, 
     LONG pseudoRandomSize,
     EvMD5& md5, EvSHA1& sha1) 
    {
        LONG length = -EV_ERROR_FAILED;
        LONG count1, count2;
        LONG secretLength1;
        LONG secretLength2;
        LONG seedLength;
        const char* secretChars1;
        const char* secretChars2;
        const char* seedChars;

        if ((seedChars = m_seed.HasChars(seedLength)))
        if ((secretChars1 = m_secret.HasChars(secretLength1)))
        {
            secretLength1 = (secretLength1 >> 1) 
            + (secretLength2 = (secretLength1 & 1));

            secretChars2 = secretChars1 
            + (secretLength1 - secretLength2);

            if (0 < (count1 = PMD5
                (md5PseudoRandom, pseudoRandomSize,
                 (BYTE*)secretChars1, secretLength1,
                 (BYTE*)seedChars, seedLength, md5)))

            if (0 < (count1 = PSHA1
                (sha1PseudoRandom, pseudoRandomSize,
                 (BYTE*)secretChars2, secretLength1,
                 (BYTE*)seedChars, seedLength, sha1)))
            {
                for (count2=0; count2<count1; count2++)
                    pseudoRandom[count2]
                    = md5PseudoRandom[count2] 
                    ^ sha1PseudoRandom[count2];

                length = count1;
            }
        }
        return length;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: PMD5
    //
    //   Author: $author$
    //     Date: 11/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG PMD5
    (BYTE* hashed, ULONG hashedSize, 
     const BYTE* secret, LONG secretSize,
     const BYTE* seed, LONG seedSize,
     EvMD5& md5) 
    {
        LONG length = PHash
        (hashed, hashedSize, secret, secretSize, 
         seed, seedSize, md5, EvMD5::EV_HASH_SIZE);
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: PSHA1
    //
    //   Author: $author$
    //     Date: 11/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG PSHA1
    (BYTE* hashed, ULONG hashedSize, 
     const BYTE* secret, LONG secretSize,
     const BYTE* seed, LONG seedSize,
     EvSHA1& sha1) 
    {
        LONG length = PHash
        (hashed, hashedSize, secret, secretSize, 
         seed, seedSize, sha1, EvSHA1::EV_HASH_SIZE);
        return length;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: PHash
    //
    //   Author: $author$
    //     Date: 11/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG PHash
    (BYTE* hashed, ULONG hashedSize, 
     const BYTE* secret, LONG secretSize,
     const BYTE* seed, LONG seedSize,
     EvHash& hash, ULONG hashSize) 
    {
        const BYTE* Ai = seed;
        LONG AiSize = seedSize;
        LONG length = -EV_ERROR_FAILED;
        LONG count1;
        LONG count2;
        ULONG size;

        if (hashedSize < (size = hashSize))
            size = hashedSize;

        if (0 > (count1 = HMACHash
            (hashed, size, secret, secretSize, 
             Ai, AiSize, seed, seedSize, hash)))
             return length;

        AiSize = hashSize;
        Ai = hashed;
        hashed += hashSize;

        while(count1 < (LONG)hashedSize)
        {
            if (hashedSize < (count1 + (size = hashSize)))
                size = (hashedSize - count1);

            if (0 > (count2 = HMACHash
                (hashed, size, secret, secretSize, 
                 Ai, AiSize, seed, seedSize, hash)))
                 return length;

            Ai += count2;
            hashed += count2;
            count1 += count2;
        }
        return count1;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: HMACHash
    //
    //   Author: $author$
    //     Date: 11/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG HMACHash
    (BYTE* hashed, ULONG hashedSize, 
     const BYTE* secret, LONG secretSize,
     const BYTE* Ai, LONG AiSize,
     const BYTE* seed, LONG seedSize,
     EvHash& hash) 
    {
        LONG length = -EV_ERROR_FAILED;
        LONG count1;
        if (0 < (count1 = hash.Initialize(secret, secretSize)))
        if (0 < (count1 = hash.Hash(Ai, AiSize)))
        if (0 < (count1 = hash.Hash(seed, seedSize)))
        if (0 < (count1 = hash.Finalize(hashed, hashedSize)))
            length = count1;
        return length;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Hash
    //
    //   Author: $author$
    //     Date: 11/27/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Hash
    (BYTE* hashed, ULONG hashSize, 
     EvHash& hash, CEvcpsBase& message) 
    {
        CEvCharHashWriter hashWriter(hash);
        LONG length = -EV_ERROR_FAILED;
        LONG count;

        if (0 <= (count = hash.Initialize()))
        if (0 < (count = message.Write(hashWriter)))
        if (0 < (count = hash.Finalize(hashed, hashSize)))
            length = count;
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
        LONG length = -EV_ERROR_FAILED;
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
        LONG length = -EV_ERROR_FAILED;
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
        USHORT size = 0;
        return size;
    }
};

#endif // _CEVCPSPSEUDORANDOM_HPP
