///////////////////////////////////////////////////////////////////////
//   File: cevmd5main.hpp
//
// Author: $author$
//   Date: 11/5/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVMD5MAIN_HPP
#define _CEVMD5MAIN_HPP

#include "cevhashmain.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvMD5Main
//
// Author: $author$
//   Date: 11/5/2007
///////////////////////////////////////////////////////////////////////
class CEvMD5Main
: public CEvHashMain
{
public:
    typedef CEvHashMain CExtends;
    typedef CEvMD5Main CDerives;

    EvMD5* m_hash;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvMD5Main
    //
    //       Author: $author$
    //         Date: 11/5/2007
    ///////////////////////////////////////////////////////////////////////
    CEvMD5Main() 
    : m_hash(0)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvMD5Main
    //
    //      Author: $author$
    //        Date: 11/5/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvMD5Main()
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Test
    //
    //    Author: $author$
    //      Date: 11/5/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int Test
    (int argc, const char** argv, const char** env) 
    {
        static const char* test[]={
	    "",
	    "abc",
	    "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789",
	    NULL,
	    };
        static const char* ret[]={
	    "d41d8cd98f00b204e9800998ecf8427e",
	    "900150983cd24fb0d6963f7d28e17f72",
	    "d174ab98d277d9f5a5611c2c9f419d9f",
	    NULL,
	    };
        int err = TestHash(test, ret);
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: AcquireHash
    //
    //   Author: $author$
    //     Date: 11/6/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvHash* 
    AcquireHash(EvError& error) 
    {
        EvHash* acquired = 0;        
        error = EV_ERROR_FAILED;
        acquired = (m_hash = m_crypto.AcquireMD5(error));
        return acquired;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ReleaseHash
    //
    //   Author: $author$
    //     Date: 11/6/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ReleaseHash
    (EvHash& acquired) 
    {
        EvError error = EV_ERROR_FAILED;
        if ((&acquired == (EvHash*)(m_hash)))
        if (!(error = m_crypto.ReleaseMD5(*m_hash)))
            m_hash = 0;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetHashSize
    //
    //   Author: $author$
    //     Date: 11/6/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ULONG GetHashSize() const 
    {
        ULONG value = EvMD5::EV_HASH_SIZE;
        return value;
    }
};

#endif // _CEVMD5MAIN_HPP
