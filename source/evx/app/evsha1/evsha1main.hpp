///////////////////////////////////////////////////////////////////////
//   File: evsha1main.hpp
//
// Author: $author$
//   Date: 11/4/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _EVSHA1MAIN_HPP
#define _EVSHA1MAIN_HPP

#include "cevhashmain.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvSHA1Main
//
// Author: $author$
//   Date: 11/4/2007
///////////////////////////////////////////////////////////////////////
class CEvSHA1Main
: public CEvHashMain
{
public:
    typedef CEvHashMain CExtends;
    typedef CEvSHA1Main CDerives;

    EvSHA1* m_hash;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvSHA1Main
    //
    //       Author: $author$
    //         Date: 11/4/2007
    ///////////////////////////////////////////////////////////////////////
    CEvSHA1Main() 
    : m_hash(0)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvSHA1Main
    //
    //      Author: $author$
    //        Date: 11/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvSHA1Main()
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Test
    //
    //    Author: $author$
    //      Date: 11/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int Test
    (int argc, const char** argv, const char** env) 
    {
        static const char* test[]={
        "",
	    "abc",
	    "abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq",
	    NULL,
	    };
        static const char* ret[]={
        "da39a3ee5e6b4b0d3255bfef95601890afd80709",
	    "a9993e364706816aba3e25717850c26c9cd0d89d",
	    "84983e441c3bd26ebaae4aa1f95129e5e54670f1",
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
        acquired = (m_hash = m_crypto.AcquireSHA1(error));
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
        if (!(error = m_crypto.ReleaseSHA1(*m_hash)))
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
        ULONG value = EvSHA1::EV_HASH_SIZE;
        return value;
    }
};

#endif // _EVSHA1MAIN_HPP
