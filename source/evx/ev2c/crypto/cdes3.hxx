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
 *   File: cdes3.hxx
 *
 * Author: $author$
 *   Date: $date$
 **********************************************************************
 */
#ifndef _CDES3_HXX
#define _CDES3_HXX

#include "ccipher.hxx"

/**
 **********************************************************************
 *  Class: CDES
 *
 * Author: $author$
 *   Date: $date$
 **********************************************************************
 */
class CDES
: public CCipher
{
public:
    typedef CCipher CExtends;

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
        BLOCKSIZE = 8,
        KEYMIN    = 8,
        KEYMAX    = 8,
        KEYSIZE   = 8,
        IVMIN     = 8,
        IVMAX     = 8,
        IVSIZE    = 8
    };

    /**
     **********************************************************************
     * Constructor: CDES
     *
     * Author: $author$
     *   Date: $date$
     **********************************************************************
     */
    CDES() 
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
        int length = KEYMAX+IVMAX;

        if (0 > keylen)
            keylen = (int)strlen((const char*)key);

        if (KEYMIN > keylen)
            return -_ERROR_PARAMETER_SIZE_UNDER;

        if (KEYMAX < keylen)
            return -_ERROR_PARAMETER_SIZE_OVER;

        CopyRepeat(m_key, KEYMAX, key, keylen);

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
        InitSchedule(m_schedule[0], m_key);
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
        tBlock block;
        int outlen,size;

        if (0 > inlen)
            inlen = (int)strlen((const char*)in);

        outlen = ((inlen+BLOCKSIZE-1)/BLOCKSIZE)*BLOCKSIZE;

        if (outsize < outlen)
            return -_ERROR_PARAMETER_SIZE_UNDER;

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
        tBlock block;
        int outlen,size;

        if (0 > inlen)
            inlen = (int)strlen((const char*)in);

        outlen = ((inlen+BLOCKSIZE-1)/BLOCKSIZE)*BLOCKSIZE;

        if (outsize < outlen)
            return -_ERROR_PARAMETER_SIZE_UNDER;

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

    typedef BYTE tBlock[BLOCKSIZE];
    typedef BYTE tKey[BLOCKSIZE*3];
    typedef uint32 tSchedule[32];

    static const uint32 m_setkey[8][64];
    static const uint32 m_encrypt[8][64];

    tKey m_key;
    tBlock m_iv;
    tSchedule m_schedule[3];

    /**
     **********************************************************************
     * Function: InitSchedule
     *
     * Author: $author$
     *   Date: $date$
     **********************************************************************
     */
    void InitSchedule
    (tSchedule schedule, const tBlock key);
    /**
     **********************************************************************
     * Function: Encode
     *
     * Author: $author$
     *   Date: $date$
     **********************************************************************
     */
    void Encode
    (uint32 data[2], tSchedule schedule);
    /**
     **********************************************************************
     * Function: Decode
     *
     * Author: $author$
     *   Date: $date$
     **********************************************************************
     */
    void Decode
    (uint32 data[2], tSchedule schedule);
    /**
     **********************************************************************
     * Function: EncryptBlock
     *
     * Author: $author$
     *   Date: $date$
     **********************************************************************
     */
    virtual void EncryptBlock
    (tBlock out, const tBlock in);
    /**
     **********************************************************************
     * Function: DecryptBlock
     *
     * Author: $author$
     *   Date: $date$
     **********************************************************************
     */
    virtual void DecryptBlock
    (tBlock out, const tBlock in);
};

/**
 **********************************************************************
 *  Class: CDES3
 *
 * Author: $author$
 *   Date: $date$
 **********************************************************************
 */
class CDES3
: public CDES
{
public:
    typedef CDES CExtends;

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
        KEYMIN    = CExtends::KEYMIN*3,
        KEYMAX    = CExtends::KEYMAX*3,
        KEYSIZE   = CExtends::KEYSIZE*3,
    };

    /**
     **********************************************************************
     * Constructor: CDES3
     *
     * Author: $author$
     *   Date: $date$
     **********************************************************************
     */
    CDES3() 
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
        int length = KEYMAX+IVMAX;

        if (0 > keylen)
            keylen = (int)strlen((const char*)key);

        if (KEYMIN > keylen)
            return -_ERROR_PARAMETER_SIZE_UNDER;

        if (KEYMAX < keylen)
            return -_ERROR_PARAMETER_SIZE_OVER;

        CopyRepeat(m_key, KEYMAX, key, keylen);

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
        InitSchedule(m_schedule[0], m_key);
        InitSchedule(m_schedule[1], m_key+8);
        InitSchedule(m_schedule[2], m_key+16);
        return length;
    }
    /**
     **********************************************************************
     * Function: EncryptBlock
     *
     * Author: $author$
     *   Date: $date$
     **********************************************************************
     */
    virtual void EncryptBlock
    (tBlock out, const tBlock in);
    /**
     **********************************************************************
     * Function: DecryptBlock
     *
     * Author: $author$
     *   Date: $date$
     **********************************************************************
     */
    virtual void DecryptBlock
    (tBlock out, const tBlock in);
};
#endif /* _CDES3_HXX */
