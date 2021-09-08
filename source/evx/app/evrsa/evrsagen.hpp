///////////////////////////////////////////////////////////////////////
//   File: evrsagen.hpp
//
// Author: $author$
//   Date: 5/1/2014
///////////////////////////////////////////////////////////////////////
#ifndef _EVRSAGEN_HPP
#define _EVRSAGEN_HPP

#include "cevmain.hpp"
#include "cevbuffer.hpp"
#include "cevbytestring.hpp"
#include "crsaprivatekey.hxx"
#include "cpseudorandombytestream.hxx"
#include "cprimereaderevents.hxx"

///////////////////////////////////////////////////////////////////////
//  Class: CEvRSAGen
//
// Author: $author$
//   Date: 5/1/2014
///////////////////////////////////////////////////////////////////////
class CEvRSAGen
: virtual public CPrimeReaderEvents,
  public CEvMain
{
public:
    typedef CPrimeReaderEvents CEvImplements;
    typedef CEvMain CEvExtends;
    typedef CEvRSAGen CEvDerives;

    CPseudoRandomBYTEStream m_pseudoRandom;
    CRSAPrivateKey m_rsaPrivate;
    CRSAPublicKey m_rsaPublic;
    CEvBYTEString m_rsaExponent;
    const BYTE* m_rsaExponentBytes;
    LONG m_rsaExponentLength;
    LONG m_rsaModulusLength;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvRSAGen
    //
    //      Author: $author$
    //        Date: 5/1/2014
    ///////////////////////////////////////////////////////////////////////
    CEvRSAGen(): m_rsaModulusLength(128) {
        static const BYTE rsaExponentBytes[] = {0x01, 0x00, 0x01};
        m_rsaExponent.Assign(rsaExponentBytes, sizeof(rsaExponentBytes));
        m_rsaExponentBytes = m_rsaExponent.HasChars(m_rsaExponentLength);
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvRSAGen
    //
    //     Author: $author$
    //       Date: 5/1/2014
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvRSAGen() {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Run
    //
    //   Author: $author$
    //     Date: 5/1/2014
    ///////////////////////////////////////////////////////////////////////
    virtual int Run(int argc, const char** argv, const char** env) {
        int err = 0;
        int error;
        time_t t;

        m_pseudoRandom.Seed(time(&t));

        if ((error = m_rsaPrivate.Generate
            (m_rsaPublic, m_pseudoRandom, m_rsaModulusLength,
             m_rsaExponentBytes, m_rsaExponentLength, this))) {
            printf("failed %d on m_rsaPrivate.Generate()\n", error);
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: OnReadPrime
    //
    //   Author: $author$
    //     Date: 5/1/2014
    ///////////////////////////////////////////////////////////////////////
    virtual Error OnReadPrime(BIGPRIME *n, unsigned bytes) {
        Error error = _ERROR_NONE;
        printf(".");
        return error;
    }
};

#endif // _EVRSAGEN_HPP 

        

