///////////////////////////////////////////////////////////////////////
//   File: evaesmain.hpp
//
// Author: $author$
//   Date: 11/19/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _EVAESMAIN_HPP
#define _EVAESMAIN_HPP

#include "cevciphermain.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvAESMain
//
// Author: $author$
//   Date: 11/19/2007
///////////////////////////////////////////////////////////////////////
class CEvAESMain
: public CEvCipherMain
{
public:
    typedef CEvCipherMain CExtends;
    typedef CEvAESMain CDerives;

    EvAES* m_cipher;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvAESMain
    //
    //       Author: $author$
    //         Date: 11/19/2007
    ///////////////////////////////////////////////////////////////////////
    CEvAESMain() 
    : m_cipher(0)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvAESMain
    //
    //      Author: $author$
    //        Date: 11/19/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvAESMain()
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Test
    //
    //    Author: $author$
    //      Date: 11/18/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int Test
    (int argc, const char** argv, const char** env) 
    {
        static unsigned char cbc_data[32]={
	        0x37,0x36,0x35,0x34,0x33,0x32,0x31,0x20,
	        0x4E,0x6F,0x77,0x20,0x69,0x73,0x20,0x74,
	        0x68,0x65,0x20,0x74,0x69,0x6D,0x65,0x20,
	        0x66,0x6F,0x72,0x20,0x00,0x00,0x00,0x00
            };

        char cbc_ciphered[32];
        char cbc_deciphered[32];

        int err = TestCipher
        (cbc_ciphered, cbc_deciphered, 
         (const char*)cbc_data, sizeof(cbc_data));
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: AcquireCipher
    //
    //   Author: $author$
    //     Date: 11/18/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvCipher* 
    AcquireCipher(EvError& error) 
    {
        EvCipher* acquired = 0;
        error = EV_ERROR_NOT_IMPLEMENTED;
        if ((m_cipher = m_crypto.AcquireAES(error)))
            acquired = (EvCipher*)(m_cipher);
        return acquired;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ReleaseCipher
    //
    //   Author: $author$
    //     Date: 11/18/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ReleaseCipher
    (EvCipher& acquired) 
    {
        EvError error = EV_ERROR_FAILED;
        if ((&acquired == (EvCipher*)(m_cipher)))
        if (!(error = m_crypto.ReleaseAES(*m_cipher)))
            m_cipher = 0;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetCipherKey
    //
    //   Author: $author$
    //     Date: 11/18/2007
    ///////////////////////////////////////////////////////////////////////
    virtual BYTE* GetCipherKey(ULONG& size) const 
    {
        static unsigned char cbc_key [8*3]={
            0x01,0x23,0x45,0x67,0x89,0xab,0xcd,0xef,
            0xf1,0xe0,0xd3,0xc2,0xb5,0xa4,0x97,0x86,
            0xfe,0xdc,0xba,0x98,0x76,0x54,0x32,0x10
            };
        BYTE* value = cbc_key;
        size = sizeof(cbc_key);
        return value;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetCipherIV
    //
    //   Author: $author$
    //     Date: 11/18/2007
    ///////////////////////////////////////////////////////////////////////
    virtual BYTE* GetCipherIV(ULONG& size) const 
    {
        static unsigned char cbc_iv  [8*2]={
            0xfe,0xdc,0xba,0x98,0x76,0x54,0x32,0x10,
            0x01,0x23,0x45,0x67,0x89,0xab,0xcd,0xef
            };
        BYTE* value = cbc_iv;
        size = sizeof(cbc_iv);
        return value;
    }
};

#endif // _EVAESMAIN_HPP
