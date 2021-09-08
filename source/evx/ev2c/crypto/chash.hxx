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
 *   File: chash.hxx
 *
 * Author: $author$
 *   Date: $date$
 **********************************************************************
 */
#ifndef _CHASH_HXX
#define _CHASH_HXX

#include <string.h>
#include "ccrypto.hxx"

/**
 **********************************************************************
 *  Class: CHash
 *
 * Author: $author$
 *   Date: $date$
 **********************************************************************
 */
class CHash
: public CCrypto
{
public:
    typedef CCrypto CExtends;

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
        IPAD=0x36, 
        OPAD=0x5c
    };

    /**
     **********************************************************************
     * Constructor: CHash
     *
     * Author: $author$
     *   Date: $date$
     **********************************************************************
     */
    CHash
    (int hashsize,
     int blocksize,
     int keymin,
     int keymax,
     BYTE *keybuff,
     BYTE *macbuff,
     BYTE *hashbuff)
    : m_hashsize(hashsize),
      m_blocksize(blocksize),
      m_keymin(keymin),
      m_keymax(keymax),
      m_keylen(0),
      m_keysize(0),
      m_keybuff(keybuff),
      m_macbuff(macbuff),
      m_hashbuff(hashbuff) 
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
    (const BYTE *key=0, int keylen=-1)
    {
        int i;

        if (key)
        {
            if (0 > keylen)
                keylen = (int)(strlen((const char*)key));

            if (keylen < m_keymin)
                return -_ERROR_PARAMETER_SIZE_UNDER;

            if (keylen > m_keymax)
                return -_ERROR_PARAMETER_SIZE_OVER;

            m_keylen = keylen;
            m_keysize = m_keymax;
            memcpy(m_keybuff, key, keylen);
            memset(m_keybuff+keylen, 0, m_keymax-keylen);

            /*
             * HMAC
             */
            for (i=0; i<m_keymax; i++)
                m_keybuff[i] ^= OPAD;
        }
        else m_keysize = m_keylen = keylen = 0;

        Initial();

        if (m_keysize)
        {
            /*
             * HMAC
             */
            for (i=0; i<m_keysize; i++)
                m_keybuff[i] = (m_keybuff[i]^OPAD)^IPAD;

            Update(m_keybuff, m_keysize);

            /*
             * HMAC
             */
            for (i=0; i<m_keysize; i++)
                m_keybuff[i] = (m_keybuff[i]^IPAD)^OPAD;
        }
        return keylen;
    }
    /**
     **********************************************************************
     * Function: Finalize
     *
     * Author: $author$
     *   Date: $date$
     **********************************************************************
     */
    virtual int Finalize
    (BYTE *out, int outsize)
    {
        if (outsize > m_hashsize)
            outsize = m_hashsize;

        Final();

        if (m_keysize)
        {
            /*
             * HMAC
             */
            memcpy(m_macbuff, m_hashbuff, m_hashsize);
            Initial();
            Update(m_keybuff, m_keysize);
            Update(m_macbuff, m_hashsize);
            Final();
        }

        memcpy(out, m_hashbuff, outsize);
        return outsize;
    }
    /**
     **********************************************************************
     * Function: HashFill
     *
     * Author: $author$
     *   Date: $date$
     **********************************************************************
     */
    virtual int HashFill
    (BYTE in, int inrepeat=1)
    {
        int count;

        for (count=0; count<inrepeat; count++)
            Update(&in, 1);
        return count;
    }
    /**
     **********************************************************************
     * Function: Hash
     *
     * Author: $author$
     *   Date: $date$
     **********************************************************************
     */
    virtual int Hash
    (const BYTE *in, int inlen=-1)
    {
        if (0 > inlen)
            inlen = (int)(strlen((const char*)in));

        Update(in, inlen);
        return inlen;
    }

    /**
     **********************************************************************
     * Function: GetHashSize
     *
     * Author: $author$
     *   Date: $date$
     **********************************************************************
     */
    virtual int GetHashSize() const 
    {
        int size = -_ERROR_NOT_IMPLEMENTED;
        return size;
    }
protected:

    int m_hashsize;
    int m_blocksize;
    int m_keymin;
    int m_keymax;
    int m_keylen;
    int m_keysize;
    BYTE *m_keybuff;
    BYTE *m_macbuff;
    BYTE *m_hashbuff;

    /**
     **********************************************************************
     * Function: Initial
     *
     * Author: $author$
     *   Date: $date$
     **********************************************************************
     */
    virtual void Initial() = 0;
    /**
     **********************************************************************
     * Function: Final
     *
     * Author: $author$
     *   Date: $date$
     **********************************************************************
     */
    virtual void Final() = 0;
    /**
     **********************************************************************
     * Function: Update
     *
     * Author: $author$
     *   Date: $date$
     **********************************************************************
     */
    virtual void Update(const BYTE *in, unsigned inlen) = 0;
};
#endif /* _CHASH_HXX */
