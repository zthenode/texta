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
 *   File: cprimegenerator.hxx
 *
 * Author: $author$
 *   Date: $date$
 **********************************************************************
 */
#ifndef _CPRIMEGENERATOR_HXX
#define _CPRIMEGENERATOR_HXX

#include "cmillerrabinprimality.hxx"
#include "cprimereader.hxx"

#define _CRSA_MILLER_RABIN_REPS 25

#if !defined(_CRSA_NO_SMALL_PRIME_TEST) 
#include "smallprimes.h"
#define _CRSA_SMALL_PRIME_DIFFERENCE 0x7/*0000000*/
#endif /* !defined(_CRSA_NO_SMALL_PRIME_TEST) */

/**
 **********************************************************************
 *  Class: CPrimeGenerator
 *
 * Author: $author$
 *   Date: $date$
 **********************************************************************
 */
class CPrimeGenerator
: public CPrimeReader
{
public:
    typedef CPrimeReader CExtends;
    typedef CPrimeGenerator CDerives;

    bool m_is_created;

#if defined(_CRSA_BN)
/*
 * BIGNUM implementation
 */
    BIGNUM *m_temp1,*m_temp2;
    BN_CTX *m_ctx;
#elif defined(_CRSA_MP) 
/*
 * MP_INT implementation
 */
    MP_INT m_temp1,m_temp2;
#else /* defined(_CRSA_BN) */
/*
 * Otherwise 
 */
#endif /* defined(_CRSA_BN) */

#if !defined(_CRSA_NO_SMALL_PRIME_TEST) 
    long m_small_prime_difference;
    long m_moduli[sizeof(g_small_primes)/sizeof(g_small_primes[0])];
#endif /* !defined(_CRSA_NO_SMALL_PRIME_TEST) */

    unsigned m_miller_rabin_reps;
    CMillerRabinPrimality m_miller_rabin;

    /**
     **********************************************************************
     * Constructor: CPrimeGenerator
     *
     *      Author: $author$
     *        Date: $date$
     **********************************************************************
     */
    CPrimeGenerator
    (PrimeReaderEvents* events=0,
#if !defined(_CRSA_NO_SMALL_PRIME_TEST) 
     long small_prime_difference=_CRSA_SMALL_PRIME_DIFFERENCE,
#endif /* !defined(_CRSA_NO_SMALL_PRIME_TEST) */
     unsigned miller_rabin_reps=_CRSA_MILLER_RABIN_REPS) 
    : CExtends(events),
      m_is_created(false),
#if !defined(_CRSA_NO_SMALL_PRIME_TEST) 
      m_small_prime_difference(small_prime_difference),
#endif /* !defined(_CRSA_NO_SMALL_PRIME_TEST) */
      m_miller_rabin_reps(miller_rabin_reps),
      m_miller_rabin(events) 
    {
    }
    /**
     **********************************************************************
     * Destructor: CPrimeGenerator
     *
     *     Author: $author$
     *       Date: $date$
     **********************************************************************
     */
    virtual ~CPrimeGenerator()
    {
        Error error;
        if (m_is_created)
        if ((error = Destroy()))
            throw(error);
    }

    /**
     **********************************************************************
     * Function: Create
     *
     *   Author: $author$
     *     Date: $date$
     **********************************************************************
     */
    virtual Error Create() 
    {
        Error error = _ERROR_FAILED;

        if (m_is_created)
            return _ERROR_ALREADY_CREATED;

#if defined(_CRSA_BN)
/*
 * BIGNUM implementation
 */
        if ((m_temp1=BN_new()))
        {
        if ((m_temp2=BN_new()))
        {
        if ((m_ctx=BN_CTX_new()))
        {
#elif defined(_CRSA_MP) 
/*
 * MP_INT implementation
 */
        mpz_init_set_ui(&m_temp1,0);
        mpz_init_set_ui(&m_temp2,0);
#else /* defined(_CRSA_BN) */
/*
 * Otherwise 
 */
#endif /* defined(_CRSA_BN) */

        if (!(error = m_miller_rabin.Create()))
        {
            m_is_created = true;
            return error;
        }

#if defined(_CRSA_BN)
/*
 * BIGNUM implementation
 */
        BN_CTX_free(m_ctx);
        }
        BN_free(m_temp2);
        }
        BN_free(m_temp1);
        }
#elif defined(_CRSA_MP) 
/*
 * MP_INT implementation
 */
        mpz_clear(&m_temp1);
        mpz_clear(&m_temp2);
#else /* defined(_CRSA_BN) */
/*
 * Otherwise 
 */
#endif /* defined(_CRSA_BN) */
        return error;
    }
    /**
     **********************************************************************
     * Function: Destroy
     *
     *   Author: $author$
     *     Date: $date$
     **********************************************************************
     */
    virtual Error Destroy() 
    {
        Error error = _ERROR_FAILED;

        if (!m_is_created)
            return _ERROR_NOT_CREATED;

        error = m_miller_rabin.Destroy();

#if defined(_CRSA_BN)
/*
 * BIGNUM implementation
 */
        BN_CTX_free(m_ctx);
        BN_free(m_temp2);
        BN_free(m_temp1);
#elif defined(_CRSA_MP) 
/*
 * MP_INT implementation
 */
        mpz_clear(&m_temp2);
        mpz_clear(&m_temp1);
#else /* defined(_CRSA_BN) */
/*
 * Otherwise 
 */
#endif /* defined(_CRSA_BN) */

        m_is_created = false;
        return error;
    }

    /**
     **********************************************************************
     * Function: Generate
     *
     *   Author: $author$
     *     Date: $date$
     **********************************************************************
     */
    virtual Error Generate
    (BIGPRIME *prime, unsigned bytes, BYTEStream& random) 
    {
        Error error = _ERROR_FAILED;
        bool retry;
        unsigned bits;

#if !defined(_CRSA_NO_SMALL_PRIME_TEST) 
        long difference, small_prime;
        unsigned i,num_primes;
#endif /* !defined(_CRSA_NO_SMALL_PRIME_TEST) */

        bits=(bytes<<3);
        retry=true;

        do
        {
            /* Pick a random integer of the appropriate size. 
             */
            if ((error = ReadMSB(prime,bytes,random)))
                return error;
                 
            /* Set the lowest bit to make it odd. 
             */
#if defined(_CRSA_BN)
/*
 * BIGNUM implementation
 */
            BN_set_bit(prime,0); 
#elif defined(_CRSA_MP) 
/*
 * MP_INT implementation
 */
            mpz_set_ui(&m_temp1,1);
            mpz_ior(prime,prime,&m_temp1);
#else /* defined(_CRSA_BN) */
/*
 * Otherwise 
 */
#endif /* defined(_CRSA_BN) */

            /* Set the highest bit to make it n bits. 
             */
#if defined(_CRSA_BN)
/*
 * BIGNUM implementation
 */
            BN_set_bit(prime,(bits-1));
#elif defined(_CRSA_MP) 
/*
 * MP_INT implementation
 */
            mpz_mul_2exp(&m_temp1,&m_temp1,(bits-1));
            mpz_ior(prime,prime,&m_temp1); 
#else /* defined(_CRSA_BN) */
/*
 * Otherwise 
 */
#endif /* defined(_CRSA_BN) */

#if defined(_CRSA_SET_TWO_HIGHEST_BITS)
            /* Set the second highest bit. 
             */
#if defined(_CRSA_BN)
/*
 * BIGNUM implementation
 */
            BN_set_bit(prime,(bits-2)); 
#elif defined(_CRSA_MP) 
/*
 * MP_INT implementation
 */
            mpz_tdiv_q_2exp(&m_temp1,&m_temp1,1);
            mpz_ior(prime,prime,&m_temp1); 
#else /* defined(_CRSA_BN) */
/*
 * Otherwise 
 */
#endif /* defined(_CRSA_BN) */
#endif /* defined(_CRSA_SET_TWO_HIGHEST_BITS) */

#if !defined(_CRSA_NO_SMALL_PRIME_TEST) 
            /* Initialize moduli of the small primes with respect to the
             * random number. 
             */
            if (bits < 16)
                /* Don't use the table for very small numbers.
                 */
                num_primes = 0;
            else
            {
                for (num_primes = 0; g_small_primes[num_primes] != 0; num_primes++)
                {
#if defined(_CRSA_BN)
/*
 * BIGNUM implementation
 */
                    m_moduli[num_primes]=BN_mod_word(prime,g_small_primes[num_primes]);
#elif defined(_CRSA_MP) 
/*
 * MP_INT implementation
 */
                    mpz_mod_ui(&m_temp1, prime, g_small_primes[num_primes]);
                    m_moduli[num_primes]=mpz_get_ui(&m_temp1);
#else /* defined(_CRSA_BN) */
/*
 * Otherwise 
 */
#endif /* defined(_CRSA_BN) */
                }
            }

            /* Look for numbers that are not evenly divisible
             * by any of the small primes. 
             */
            for (difference = 0; 
                 difference <= m_small_prime_difference; 
                 difference += 2)
            {
                /* Check if it is a multiple of any small prime. Note that this
                 * updates the moduli into negative values as difference grows.
                 */
                for (i = 0; i < num_primes; i++)
                {
                    while ((m_moduli[i] + difference) 
                           >= (small_prime = (long)(g_small_primes[i])))
                        m_moduli[i] -= small_prime;

                    if ((m_moduli[i] + difference) == 0)
                        break;
                }

                if (i < num_primes)
                    /* Multiple of a known prime. 
                     */
                    continue; 

                /* It passed the small prime test (not divisible by any of them).
                 * Compute the number in question. 
                 */
#if defined(_CRSA_BN)
/*
 * BIGNUM implementation
 */
                BN_add_word(prime,difference);
#elif defined(_CRSA_MP) 
/*
 * MP_INT implementation
 */
                mpz_add_ui(prime,prime,difference);
#else /* defined(_CRSA_BN) */
/*
 * Otherwise 
 */
#endif /* defined(_CRSA_BN) */

                OnReadPrime(prime, bytes);
#endif /* !defined(_CRSA_NO_SMALL_PRIME_TEST) */

                /* Perform the fermat test for witness 2.  This means:
                 * it is not prime if 2^n mod n != 2. 
                 */
#if defined(_CRSA_BN)
/*
 * BIGNUM implementation
 */
                BN_set_word(m_temp1,2);
                BN_mod_exp(m_temp2,m_temp1,prime,prime,m_ctx);

                if (BN_cmp(m_temp1,m_temp2))
#elif defined(_CRSA_MP) 
/*
 * MP_INT implementation
 */
                mpz_set_ui(&m_temp1,2);
                mpz_powm(&m_temp2,&m_temp1,prime,prime);

                if (mpz_cmp(&m_temp1,&m_temp2))
#else /* defined(_CRSA_BN) */
/*
 * Otherwise 
 */
#endif /* defined(_CRSA_BN) */
                    /* Failed the fermat test for witness 2.
                     */
                    continue;

                /* Perform the Miller Rabin primality test.
                 */
                if ((error=m_miller_rabin.ProbablyPrime
                    (prime,bytes,m_miller_rabin_reps,random)))
                    /* Failed the Miller Rabin probable primality test.
                     */
                    continue;

                /* Found a (probable) prime.
                 * Sanity check: does it still have the high bit set
                 * (we might have wrapped around)? 
                 */
#if defined(_CRSA_BN)
/*
 * BIGNUM implementation
 */
                if (BN_is_bit_set(prime,bits-1))
#elif defined(_CRSA_MP) 
/*
 * MP_INT implementation
 */
                mpz_tdiv_q_2exp(&m_temp1, prime, bits-1);
                if (mpz_get_ui(&m_temp1))
#else /* defined(_CRSA_BN) */
/*
 * Otherwise 
 */
#endif /* defined(_CRSA_BN) */
                /* passed sanity check!
                 * it does still have the high bit set
                 */
                    retry = false;

#if !defined(_CRSA_NO_SMALL_PRIME_TEST)
                break;
            }
#endif /* !defined(_CRSA_NO_SMALL_PRIME_TEST) */
        }
        while (retry);

#if defined(_CRSA_BN) | defined(_CRSA_MP) 
/*
 * BIGNUM or MP_INT implementation
 */
        error = _ERROR_NONE;
#endif /* defined(_CRSA_BN) | defined(_CRSA_MP)*/

        return error;
    }
};
#endif /* _CPRIMEGENERATOR_HXX */
