/**
 **********************************************************************
 * Copyright (c) $year$ $author$
 *
 * This software is provided by the author and contributors ``as is'' 
 * and any express or implied warranties, including, but not limited to, 
 * the implied warranties of merchantability and fitness for a particular 
 * purpose are disclaimed. In no event shall the author or contributors 
 * be liable for any direct, indirect, incidental, special, exemplary, 
 * or consequential damages (including, but not limited to, procurement 
 * of substitute goods or services; loss of use, data, or profits; or 
 * business interruption) however caused and on any theory of liability, 
 * whether in contract, strict liability, or tort (including negligence 
 * or otherwise) arising in any way out of the use of this software, 
 * even if advised of the possibility of such damage.
 *
 *   File: caes.hxx
 *
 * Author: $author$
 *   Date: $date$
 **********************************************************************
 */
#ifndef _CAES_HXX
#define _CAES_HXX

#include "ccipher.hxx"

/**
 **********************************************************************
 *  Class: CAES
 *
 * Author: $author$
 *   Date: $date$
 **********************************************************************
 */
class CAES
: public CCipher
{
public:
    typedef CCipher cExtends;
    typedef CAES cDerives;

    /**
     **********************************************************************
     * Enum: 
     *
     * Author: $author$
     *   Date: $date$
     **********************************************************************
     */
    enum
    {
        BLOCKSIZE = 16,

        KEYMIN    = 16,
        KEYMAX    = 32,
        KEYINC    = 8,
        KEYSIZE   = 16,

        IVMIN     = 16,
        IVMAX     = 16,
        IVINC     = 16,
        IVSIZE    = 16
    };

protected:

    typedef BYTE tBlock[BLOCKSIZE];
    typedef BYTE tKey[KEYMAX];

    unsigned m_keysize;
    tKey m_key;
    tBlock m_iv;

    unsigned nr;
    uint32* rk;
    uint32 buf[68];

public:

    /**
     **********************************************************************
     * Constructor: CAES
     *
     * Author: $author$
     *   Date: $date$
     **********************************************************************
     */
    CAES() 
    {
    }

    /**
     **********************************************************************
     * Function: Initialize
     *
     * Author: $author$
     *   Date: $date$
     **********************************************************************
     */
    virtual int Initialize
    (const BYTE *key, int keylen=-1,
     const BYTE *iv=0, int ivlen=-1,
     BYTE padding=0)
    {
        int length = IVMAX;

        if (0 > keylen)
            keylen = (int)strlen((const char*)key);

        if (KEYMIN > keylen)
            return -_ERROR_PARAMETER_SIZE_UNDER;

        if (KEYMAX < keylen)
            return -_ERROR_PARAMETER_SIZE_OVER;

        CopyRepeat(m_key, KEYMAX, key, keylen);

        m_keysize = KEYMIN; 

        while (m_keysize < (unsigned)keylen)
            m_keysize += KEYINC;

        length += m_keysize;

        if (iv)
        {
            if (0 > ivlen)
                ivlen = (int)strlen((const char*)iv);

            if (IVMIN > ivlen)
                return -_ERROR_PARAMETER_SIZE_UNDER;

            if (IVMAX < ivlen)
                return -_ERROR_PARAMETER_SIZE_OVER;

            CopyRepeat(m_iv, IVMAX, iv, ivlen);
        }
        else
        {
            if (IVMAX < keylen)
                keylen = IVMAX;

            CopyRepeat(m_iv, IVMAX, key, keylen);
        }

        m_padding = padding;
        return length;
    }

    /**
     **********************************************************************
     * Function: Encrypt
     *
     * Author: $author$
     *   Date: $date$
     **********************************************************************
     */
    virtual int Encrypt
    (BYTE *out, int outsize, const BYTE *in, int inlen=-1)
    {
        Error error;
        tBlock block;
        int outlen,size;

        if (0 > inlen)
            inlen = (int)strlen((const char*)in);

        outlen = ((inlen+BLOCKSIZE-1)/BLOCKSIZE)*BLOCKSIZE;

        if (outsize < outlen)
            return -_ERROR_PARAMETER_SIZE_UNDER;

        if ((error = InitEncryptKeySchedule(m_key, m_keysize)))
            return -error;

        for (outlen=0; inlen>0; inlen-=size, outlen+=BLOCKSIZE)
        {
            if ((size=inlen) >= BLOCKSIZE)
            {
                size=BLOCKSIZE;
                EncryptBlock(out+outlen, in+outlen);
            }
            else
            {
                memcpy(block, in+outlen, size);
                memset(block+size, m_padding, BLOCKSIZE-size);
                EncryptBlock(out+outlen, block);
            }
        }
        return outlen;
    }
    /**
     **********************************************************************
     * Function: Decrypt
     *
     * Author: $author$
     *   Date: $date$
     **********************************************************************
     */
    virtual int Decrypt
    (BYTE *out, int outsize, const BYTE *in, int inlen=-1)
    {
        Error error;
        tBlock block;
        int outlen,size;

        if (0 > inlen)
            inlen = (int)strlen((const char*)in);

        outlen = ((inlen+BLOCKSIZE-1)/BLOCKSIZE)*BLOCKSIZE;

        if (outsize < outlen)
            return -_ERROR_PARAMETER_SIZE_UNDER;

        if ((error = InitDecryptKeySchedule(m_key, m_keysize)))
            return -error;

        for (outlen=0; inlen>0; inlen-=size, outlen+=BLOCKSIZE)
        {
            if ((size=inlen) >= BLOCKSIZE)
            {
                size=BLOCKSIZE;
                DecryptBlock(out+outlen, in+outlen);
            }
            else
            {
                memcpy(block, in+outlen, size);
                memset(block+size, m_padding, BLOCKSIZE-size);
                DecryptBlock(out+outlen, block);
            }
        }
        return outlen;
    }

protected:

    /**
     **********************************************************************
     * Function: InitEncryptKeySchedule
     *
     * Author: $author$
     *   Date: $date$
     **********************************************************************
     */
    Error InitEncryptKeySchedule
    (const BYTE* key,
     unsigned keysize);
    /**
     **********************************************************************
     * Function: InitDecryptKeySchedule
     *
     * Author: $author$
     *   Date: $date$
     **********************************************************************
     */
    Error InitDecryptKeySchedule
    (const BYTE* key,
     unsigned keysize);
    /**
     **********************************************************************
     * Function: EncryptBlock
     *
     * Author: $author$
     *   Date: $date$
     **********************************************************************
     */
    void EncryptBlock
    (tBlock out,
     const tBlock in);
    /**
     **********************************************************************
     * Function: DecryptBlock
     *
     * Author: $author$
     *   Date: $date$
     **********************************************************************
     */
    void DecryptBlock
    (tBlock out,
     const tBlock in);
    /**
     **********************************************************************
     * Function: EncodeBlock
     *
     * Author: $author$
     *   Date: $date$
     **********************************************************************
     */
    void EncodeBlock
    (tBlock output,
     const tBlock input);
    /**
     **********************************************************************
     * Function: DecodeBlock
     *
     * Author: $author$
     *   Date: $date$
     **********************************************************************
     */
    void DecodeBlock
    (tBlock output,
     const tBlock input);
};
#endif /* _CAES_HXX */
