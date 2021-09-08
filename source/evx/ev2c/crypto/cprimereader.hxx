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
 *   File: cprimereader.hxx
 *
 * Author: $author$
 *   Date: $date$
 **********************************************************************
 */
#ifndef _CPRIMEREADER_HXX
#define _CPRIMEREADER_HXX

#include "cprimereaderevents.hxx"
#include "bytestream.hxx"

/**
 **********************************************************************
 *  Class: CPrimeReader
 *
 * Author: $author$
 *   Date: $date$
 **********************************************************************
 */
class CPrimeReader
: public CPrimeReaderEvents
{
public:
    typedef CPrimeReaderEvents CExtends;
    typedef CPrimeReader CDerives;

    /**
     **********************************************************************
     * Constructor: CPrimeReader
     *
     *      Author: $author$
     *        Date: $date$
     **********************************************************************
     */
    CPrimeReader
    (PrimeReaderEvents* events=0) 
    : CExtends(events) 
    {
    }
    /**
     **********************************************************************
     * Function: ReadMSB
     *
     *   Author: $author$
     *     Date: $date$
     **********************************************************************
     */
    virtual Error ReadMSB
    (BIGPRIME* n,
     unsigned bytes,
     BYTEStream& stream) 
    {
        Error error = _ERROR_FAILED;
        BYTE byte;
        unsigned i;
        int b;

#if defined(_CRSA_BN)
/*
 * BIGNUM implementation
 */
        BN_set_word(n,0);
#elif defined(_CRSA_MP) 
/*
 * MP_INT implementation
 */
        mpz_set_ui(n,0);
#else /* defined(_CRSA_BN) */
/*
 * Otherwise 
 */
#endif /* defined(_CRSA_BN) */

        for (i=0; i<bytes; i++)
        {
#if !defined(_CRSA_NO_REMOVE_ZEROS) 
            do
            {
#endif /* !defined(_CRSA_NO_REMOVE_ZEROS) */
            if (0 > (b = stream.Getb()))
                return _ERROR_FAILED;
            else byte = b;
#if !defined(_CRSA_NO_REMOVE_ZEROS) 
            }
            while (!(byte & 0xF) || !(byte & 0xF0));
#endif /* !defined(_CRSA_NO_REMOVE_ZEROS) */

#if defined(_CRSA_BN)
/*
 * BIGNUM implementation
 */
            BN_lshift(n,n,8);
            BN_add_word(n,byte);
#elif defined(_CRSA_MP) 
/*
 * MP_INT implementation
 */
            mpz_mul_2exp(n,n,8);
            mpz_add_ui(n,n,byte);
#else /* defined(_CRSA_BN) */
/*
 * Otherwise 
 */
#endif /* defined(_CRSA_BN) */
        }

#if defined(_CRSA_BN) | defined(_CRSA_MP) 
/*
 * BIGNUM or MP_INT implementation
 */
        error = OnReadPrime(n, bytes);
#endif /* defined(_CRSA_BN) | defined(_CRSA_MP)*/
        return error;
    }
};
#endif /* _CPRIMEREADER_HXX */
