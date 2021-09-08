///////////////////////////////////////////////////////////////////////
//   File: ccevcipher.hpp
//
// Author: $author$
//   Date: 11/16/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CCEVCIPHER_HPP
#define _CCEVCIPHER_HPP

#include <vector>
#include "evcipher.hpp"
#include "cevcipher.hpp"
#include "ccipher.hxx"

///////////////////////////////////////////////////////////////////////
//  Class: CCEvCipher
//
// Author: $author$
//   Date: 11/16/2007
///////////////////////////////////////////////////////////////////////
class CCEvCipher
: public CEvCipher
{
public:
    typedef EvCipher CImplements;
    typedef CEvCipher CExtends;
    typedef CCEvCipher CDerives;

    CCipher* m_deligate;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CCEvCipher
    //
    //       Author: $author$
    //         Date: 11/16/2007
    ///////////////////////////////////////////////////////////////////////
    CCEvCipher() 
    : m_deligate(0)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CCEvCipher
    //
    //      Author: $author$
    //        Date: 11/16/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CCEvCipher()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Initialize
    //
    //   Author: $author$
    //     Date: 11/16/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Initialize
    (const BYTE* key, LONG keyLength=-1,
     const BYTE* iv=0, LONG ivLength=-1,
     BYTE padding=0) 
    {
        LONG count = -EV_ERROR_FAILED;
        int len;
        if (m_deligate)
        if (0 <= (len = m_deligate->Initialize
            (key, keyLength, iv, ivLength, padding)))
            count = len;
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Encrypt
    //
    //   Author: $author$
    //     Date: 10/27/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Encrypt
    (BYTE* out,
     ULONG outSize,
     const BYTE* in,
     LONG inLength=-1) 
    {
        LONG count = -EV_ERROR_FAILED;
        int len;
        if (m_deligate)
        if (0 <= (len = m_deligate->Encrypt
            (out, outSize, in, inLength)))
            count = len;
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Decrypt
    //
    //   Author: $author$
    //     Date: 10/27/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Decrypt
    (BYTE* out,
     ULONG outSize,
     const BYTE* in,
     LONG inLength=-1) 
    {
        LONG count = -EV_ERROR_FAILED;
        int len;
        if (m_deligate)
        if (0 <= (len = m_deligate->Decrypt
            (out, outSize, in, inLength)))
            count = len;
        return count;
    }
};

///////////////////////////////////////////////////////////////////////
//  Typedef: CCEvCiphers
//
//   Author: $author$
//     Date: 11/16/2007
///////////////////////////////////////////////////////////////////////
typedef ::std::vector<CCEvCipher*>
CCEvCiphers;

///////////////////////////////////////////////////////////////////////
//  Typedef: CCEvCiphersIterator
//
//   Author: $author$
//     Date: 11/16/2007
///////////////////////////////////////////////////////////////////////
typedef CCEvCiphers::iterator
CCEvCiphersIterator;

///////////////////////////////////////////////////////////////////////
//  Typedef: const_CCEvCiphersIterator
//
//   Author: $author$
//     Date: 11/16/2007
///////////////////////////////////////////////////////////////////////
typedef CCEvCiphers::const_iterator
const_CCEvCiphersIterator;

#endif // _CCEVCIPHER_HPP
