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
 *   File: ccipher.hxx
 *
 * Author: $author$
 *   Date: $date$
 **********************************************************************
 */
#ifndef _CCIPHER_HXX
#define _CCIPHER_HXX

#include "ccryptor.hxx"

/**
 **********************************************************************
 *  Class: CCipher
 *
 * Author: $author$
 *   Date: $date$
 **********************************************************************
 */
class CCipher
: public CCryptor
{
public:
    typedef CCryptor CExtends;

    /**
     **********************************************************************
     * Constructor: CCipher
     *
     * Author: $author$
     *   Date: $date$
     **********************************************************************
     */
    CCipher(BYTE padding=0)
    : CExtends(padding)
    {
    }
    /**
     **********************************************************************
     * Function: Initialize
     *
     *   Author: $author$
     *     Date: 1/8/2005
     **********************************************************************
     */
    virtual int Initialize
    (const BYTE *key, int keylen=-1,
     const BYTE *iv=0, int ivlen=-1,
     BYTE padding=0)
    {
        int result = -_ERROR_NOT_IMPLEMENTED;
        return result;
    }
};
#endif /* _CCIPHER_HXX */
