///////////////////////////////////////////////////////////////////////
//   File: evdes3main.hpp
//
// Author: $author$
//   Date: 11/18/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _EVDES3MAIN_HPP
#define _EVDES3MAIN_HPP

#include "cevciphermain.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvDES3Main
//
// Author: $author$
//   Date: 11/18/2007
///////////////////////////////////////////////////////////////////////
class CEvDES3Main
: public CEvCipherMain
{
public:
    typedef CEvCipherMain CExtends;
    typedef CEvDES3Main CDerives;

    EvDES3* m_cipher;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvDES3Main
    //
    //       Author: $author$
    //         Date: 11/18/2007
    ///////////////////////////////////////////////////////////////////////
    CEvDES3Main()
    : m_cipher(0)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvDES3Main
    //
    //      Author: $author$
    //        Date: 11/18/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvDES3Main()
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
        static unsigned char cbc_ok[32]={
	        0x3F,0xE3,0x01,0xC9,0x62,0xAC,0x01,0xD0,
	        0x22,0x13,0x76,0x3C,0x1C,0xBD,0x4C,0xDC,
	        0x79,0x96,0x57,0xC0,0x64,0xEC,0xF5,0xD4,
	        0x1C,0x67,0x38,0x12,0xCF,0xDE,0x96,0x75
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
        if ((m_cipher = m_crypto.AcquireDES3(error)))
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
        if (!(error = m_crypto.ReleaseDES3(*m_cipher)))
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
        static unsigned char cbc_iv  [8]={
            0xfe,0xdc,0xba,0x98,0x76,0x54,0x32,0x10
            };
        BYTE* value = cbc_iv;
        size = sizeof(cbc_iv);
        return value;
    }
};

#endif // _EVDES3MAIN_HPP
