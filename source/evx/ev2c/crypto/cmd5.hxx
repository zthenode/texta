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
 *   File: cmd5.hxx
 *
 * Author: $author$
 *   Date: $date$
 **********************************************************************
 */
#ifndef _CMD5_HXX
#define _CMD5_HXX

#include "chash.hxx"

/**
 **********************************************************************
 *  Class: CMD5
 *
 * Author: $author$
 *   Date: $date$
 **********************************************************************
 */
class CMD5
: public CHash
{
public:
    typedef CHash CExtends;

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
        HASHSIZE  = 16,
        BLOCKSIZE = 64,
        KEYMIN    = 1,
        KEYMAX    = BLOCKSIZE,
        KEYSIZE   = BLOCKSIZE,
    };

    /**
     **********************************************************************
     * Constructor: CMD5
     *
     * Author: $author$
     *   Date: $date$
     **********************************************************************
     */
    CMD5() 
    : CExtends
      (HASHSIZE,
       BLOCKSIZE,
       KEYMIN,
       KEYMAX,
       m_key,
       m_mac,
       m_hash)
    {
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
        int size = HASHSIZE;
        return size;
    }

protected:

    uint32 m_A,m_B,m_C,m_D,m_L,m_H;
    BYTE m_hash[HASHSIZE];
    BYTE m_in[BLOCKSIZE];
    BYTE m_key[BLOCKSIZE];
    BYTE m_mac[HASHSIZE];

    /**
     **********************************************************************
     * Function: Initial
     *
     * Author: $author$
     *   Date: $date$
     **********************************************************************
     */
    virtual void Initial();
    /**
     **********************************************************************
     * Function: Final
     *
     * Author: $author$
     *   Date: $date$
     **********************************************************************
     */
    virtual void Final();
    /**
     **********************************************************************
     * Function: Update
     *
     * Author: $author$
     *   Date: $date$
     **********************************************************************
     */
    virtual void Update(const BYTE *in, unsigned inlen);
    /**
     **********************************************************************
     * Function: Transform
     *
     * Author: $author$
     *   Date: $date$
     **********************************************************************
     */
    void Transform();
};
#endif /* _CMD5_HXX */
