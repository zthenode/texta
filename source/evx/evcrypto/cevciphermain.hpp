///////////////////////////////////////////////////////////////////////
//   File: cevciphermain.hpp
//
// Author: $author$
//   Date: 11/18/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCIPHERMAIN_HPP
#define _CEVCIPHERMAIN_HPP

#include "cevcryptomain.hpp"
#include "cevchar2xwriter.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvCipherMain
//
// Author: $author$
//   Date: 11/18/2007
///////////////////////////////////////////////////////////////////////
class CEvCipherMain
: public CEvCryptoMain
{
public:
    typedef CEvCryptoMain CExtends;
    typedef CEvCipherMain CDerives;

    static CDerives* m_theMain;
    CDerives* m_oldMain;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvCipherMain
    //
    //       Author: $author$
    //         Date: 11/18/2007
    ///////////////////////////////////////////////////////////////////////
    CEvCipherMain() 
    {
        m_theMain = this;
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvCipherMain
    //
    //      Author: $author$
    //        Date: 11/18/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvCipherMain()
    {
        if (this == m_theMain)
            m_theMain = m_oldMain;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: TestCipher
    //
    //    Author: $author$
    //      Date: 11/18/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int TestCipher
    (char* ciphered, char* deciphered, 
     const char* in, unsigned size) 
    {
        CEvChar2XWriter writer(m_stdOut);
        int err = 0;
        EvError error;
        EvCipher* cipher;
        const BYTE* key;
        const BYTE* iv;
        ULONG keySize;
        ULONG ivSize;

        if ((key = GetCipherKey(keySize)))
        if ((iv = GetCipherIV(ivSize)))
        if ((cipher = AcquireCipher(error)))
        {
            if (0 <= (cipher->Initialize
                (key, keySize, iv, ivSize)))
            {
                writer.WriteLine(in, size);

                if (0 <= (cipher->Encrypt
                    ((BYTE*)ciphered, size, (BYTE*)in, size)))
                {
                    writer.WriteLine(ciphered, size);

                    if (0 <= (cipher->Initialize
                        (key, keySize, iv, ivSize)))
                    if (0 <= (cipher->Decrypt
                        ((BYTE*)deciphered, size, (BYTE*)ciphered, size)))
                        writer.WriteLine(deciphered, size);
                }
            }
            ReleaseCipher(*cipher);
        }
        return err;
    }
};

#endif // _CEVCIPHERMAIN_HPP
