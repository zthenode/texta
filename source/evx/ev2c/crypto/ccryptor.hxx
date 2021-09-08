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
 *   File: ccryptor.hxx
 *
 * Author: $author$
 *   Date: $date$
 **********************************************************************
 */
#ifndef _CCRYPTOR_HXX
#define _CCRYPTOR_HXX

#include "cblock.hxx"

/**
 **********************************************************************
 *  Class: CCryptor
 *
 * Author: $author$
 *   Date: $date$
 **********************************************************************
 */
class CCryptor
: public CBlock
{
public:
    typedef CBlock cExtends;
    typedef CCryptor cDerives;

    BYTE m_padding;

    /**
     **********************************************************************
     * Constructor: CCryptor
     *
     *      Author: $author$
     *        Date: $date$
     **********************************************************************
     */
    CCryptor(BYTE padding=0)
    : m_padding(padding) 
    {
    }
    /**
     **********************************************************************
     * Destructor: CCryptor
     *
     *     Author: $author$
     *       Date: $date$
     **********************************************************************
     */
    virtual ~CCryptor()
    {
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
        int result = Crypt(out, outsize, in , inlen);
        return result;
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
        int result = Crypt(out, outsize, in , inlen);
        return result;
    }
    /**
     **********************************************************************
     * Function: Crypt
     *
     * Author: $author$
     *   Date: $date$
     **********************************************************************
     */
    virtual int Crypt
    (BYTE *out, int outsize, const BYTE *in, int inlen=-1)
    {
        int result = -_ERROR_NOT_IMPLEMENTED;
        return result;
    }
};
#endif /* _CCRYPTOR_HXX */
