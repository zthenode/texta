///////////////////////////////////////////////////////////////////////
//   File: cevcipher.hpp
//
// Author: $author$
//   Date: 11/1/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCIPHER_HPP
#define _CEVCIPHER_HPP

#include "evcipher.hpp"
#include "cevdecryptor.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvCipher
//
// Author: $author$
//   Date: 11/1/2007
///////////////////////////////////////////////////////////////////////
class CEvCipher
: virtual public EvCipher,
  public CEvDecryptor
{
public:
    typedef EvCipher CImplements;
    typedef CEvDecryptor CExtends;
    typedef CEvCipher CDerives;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvCipher
    //
    //       Author: $author$
    //         Date: 11/1/2007
    ///////////////////////////////////////////////////////////////////////
    CEvCipher() 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvCipher
    //
    //      Author: $author$
    //        Date: 11/1/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvCipher()
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
        LONG count = -EV_ERROR_NOT_ALLOWED;
        if (!key || !keyLength)
        if (!iv || !ivLength)
            return 0;
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
        if (0 > inLength)
            inLength = strlen((char*)(in));

        if (inLength > outSize)
            inLength = outSize;

        if (out != in)
            memcpy(out, in, inLength);

        return inLength;
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
        if (0 > inLength)
            inLength = strlen((char*)(in));

        if (inLength > outSize)
            inLength = outSize;

        if (out != in)
            memcpy(out, in, inLength);

        return inLength;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetIVSize
    //
    //   Author: $author$
    //     Date: 10/25/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG SetIVSize
    (ULONG size) 
    {
        LONG length = -EV_ERROR_NOT_ALLOWED;
        if (!size)
            return 0;
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetIVSize
    //
    //   Author: $author$
    //     Date: 10/25/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG GetIVSize() const 
    {
        LONG length = 0;
        return length;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: GetBlockSize
    //
    //   Author: $author$
    //     Date: 12/5/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG GetBlockSize() const 
    {
        LONG blockSize = EV_BLOCK_SIZE;
        return blockSize;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: DeleteThis
    //
    //   Author: $author$
    //     Date: 1/30/2012
    ///////////////////////////////////////////////////////////////////////
    virtual EvError DeleteThis()
    {
        EvError error = EV_ERROR_NOT_ALLOWED;
        return error;
    }
};

#endif // _CEVCIPHER_HPP
