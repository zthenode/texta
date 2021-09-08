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
 *   File: crsaprivatekeygenerator.hxx
 *
 * Author: $author$
 *   Date: $date$
 **********************************************************************
 */
#ifndef _CRSAPRIVATEKEYGENERATOR_HXX
#define _CRSAPRIVATEKEYGENERATOR_HXX

#include "cprimegenerator.hxx"
#include "cmillerrabinprimality.hxx"
#include "crsaprivatekey.hxx"
#include "crsapublickey.hxx"

/**
 **********************************************************************
 *  Class: CRSAPrivateKeyGenerator
 *
 * Author: $author$
 *   Date: $date$
 **********************************************************************
 */
class CRSAPrivateKeyGenerator
: public CBase
{
public:
    typedef CBase CExtends;
    typedef CRSAPrivateKeyGenerator CDerives;

#if defined(_CRSA_BN)
/*
 * BIGNUM implementation
 */
    typedef BIGNUM* BIGINT;
#elif defined(_CRSA_MP) 
/*
 * MP_INT implementation
 */
    typedef MP_INT BIGINT;
#else /* defined(_CRSA_BN) */
/*
 * Otherwise 
 */
#endif /* defined(_CRSA_BN) */

    CPrimeGenerator m_prime_generator;

    /**
     **********************************************************************
     * Constructor: CRSAPrivateKeyGenerator
     *
     *      Author: $author$
     *        Date: $date$
     **********************************************************************
     */
    CRSAPrivateKeyGenerator
    (PrimeReaderEvents* prime_reader_events=0,
     unsigned miller_rabin_reps=_CRSA_MILLER_RABIN_REPS) 
    : m_prime_generator(prime_reader_events, miller_rabin_reps) 
    {
    }
    /**
     **********************************************************************
     * Destructor: CRSAPrivateKeyGenerator
     *
     *     Author: $author$
     *       Date: $date$
     **********************************************************************
     */
    virtual ~CRSAPrivateKeyGenerator()
    {
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
    (CRSAPrivateKey& privatekey, 
     CRSAPublicKey& publickey, 
     BYTEStream& random, unsigned modbytes,
     const BYTE* exponent, unsigned expbytes) 
    {
        BIGINT& p = privatekey.m_p;
        BIGINT& q = privatekey.m_q;
        BIGINT& dmp1 = privatekey.m_dmp1;
        BIGINT& dmq1 = privatekey.m_dmq1;
        BIGINT& iqmp = privatekey.m_iqmp;
        BIGINT& e = publickey.m_exponent;
        BIGINT& n = publickey.m_modulus;

        Error error = _ERROR_FAILED;
        unsigned bytes, bits, ebits, modbits;
        bool retryp, retryq;
        int cmp;

#if defined(_CRSA_BN)
/*
 * BIGNUM implementation
 */
        BIGNUM *p_minus_1,*q_minus_1,*phi,*F,*G,*d,*one,*temp;
#elif defined(_CRSA_MP) 
/*
 * MP_INT implementation
 */
        MP_INT p_minus_1,q_minus_1,phi,F,G,d,one,temp;
#else /* defined(_CRSA_BN) */
/*
 * Otherwise 
 */
#endif /* defined(_CRSA_BN) */

        /* Compute the number of bits in each prime. 
         */
        bytes = modbytes/2;
        bits = bytes*8;
        ebits = expbytes*8;
        modbits = bits*2;

        if (!(error = m_prime_generator.Create()))
        {
        if (!(error = publickey.Create(modbytes,expbytes)))
        {
        if (!(error = privatekey.Create(bytes=modbytes/2)))
        {
#if defined(_CRSA_BN)
/*
 * BIGNUM implementation
 */
        BN_CTX* ctx = privatekey.m_ctx;
        BIGNUM* pp = p;
        BIGNUM* qp = q;

        if ((p_minus_1 = BN_new())!=NULL)
        {
        if ((q_minus_1 = BN_new())!=NULL)
        {
        if ((phi = BN_new())!=NULL)
        {
        if ((G = BN_new())!=NULL)
        {
        if ((F = BN_new())!=NULL)
        {
        if ((one = BN_new())!=NULL)
        {
        if ((temp = BN_new())!=NULL)
        {
        BN_set_word(one,1);
#elif defined(_CRSA_MP) 
/*
 * MP_INT implementation
 */
        MP_INT* pp = &p;
        MP_INT* qp = &q;

        mpz_init_set_ui(&p_minus_1,0);
        mpz_init_set_ui(&q_minus_1,0);
        mpz_init_set_ui(&phi,0);
        mpz_init_set_ui(&G,0);
        mpz_init_set_ui(&F,0);
        mpz_init_set_ui(&d,0);
        mpz_init_set_ui(&one,1);
        mpz_init_set_ui(&temp,0);
#else /* defined(_CRSA_BN) */
/*
 * Otherwise 
 */
        cMPUnsigned* pp = &p;
        cMPUnsigned* qp = &q;
#endif /* defined(_CRSA_BN) */

#if defined(_CRSA_BN)
/*
 * BIGNUM implementation
 */
#elif defined(_CRSA_MP) 
/*
 * MP_INT implementation
 */
#else /* defined(_CRSA_BN) */
/*
 * Otherwise 
 */
#endif /* defined(_CRSA_BN) */

        do
        {
            retryp = false;

            /* Generate random number p. 
             */
            if ((error=m_prime_generator.Generate(pp,bytes,random)))
                break;

        do
        {
            retryq = false;

            /* Generate random number q. 
             */
            if ((error=m_prime_generator.Generate(qp,bytes,random)))
                break;

            /* n = p * q (the public modulus). 
             */
#if defined(_CRSA_BN)
/*
 * BIGNUM implementation
 */
            BN_mul(n,p,q);
#elif defined(_CRSA_MP) 
/*
 * MP_INT implementation
 */
            mpz_mul(&n, &p, &q);
#else /* defined(_CRSA_BN) */
/*
 * Otherwise 
 */
#endif /* defined(_CRSA_BN) */

#if !defined(_CRSA_NO_CHECK_BITS) 
            /* Make sure that p*q will be modbits in size.
             */
#if defined(_CRSA_BN)
/*
 * BIGNUM implementation
 */
            if (BN_num_bits(n)!=(int)modbits)
#elif defined(_CRSA_MP) 
/*
 * MP_INT implementation
 */
            mpz_tdiv_q_2exp(&temp, &n, modbits-1);
            if (!mpz_get_ui(&temp))
            if (!mpz_getbit(&n, modbits-1))
#else /* defined(_CRSA_BN) */
/*
 * Otherwise 
 */
#endif /* defined(_CRSA_BN) */
            {
                /* Not big enough so we will try again.
                 */
                retryp = true;
                continue;
            }
#endif /* !defined(_CRSA_NO_CHECK_BITS) */

            /* See if q < p. 
             */
            cmp = 0;
#if defined(_CRSA_BN)
/*
 * BIGNUM implementation
 */
            cmp = BN_cmp(p,q);
#elif defined(_CRSA_MP) 
/*
 * MP_INT implementation
 */
            cmp=mpz_cmp(&p,&q);
#else /* defined(_CRSA_BN) */
/*
 * Otherwise 
 */
#endif /* defined(_CRSA_BN) */
            if (!cmp)
            {
                /* q == p
                 */
                retryq = true;
                continue;
            }
            else if (cmp<0)
            {
                /* p < q
                 */
#if defined(_CRSA_BN)
/*
 * BIGNUM implementation
 */
                BN_copy(p_minus_1,q);
                BN_copy(q_minus_1,p);
#elif defined(_CRSA_MP) 
/*
 * MP_INT implementation
 */
                mpz_set(&p_minus_1, &q);
                mpz_set(&q_minus_1, &p);
#else /* defined(_CRSA_BN) */
/*
 * Otherwise 
 */
#endif /* defined(_CRSA_BN) */

#if !defined(_CRSA_NO_SORT_PRIMES) 
                /* swap p and q
                 */
#if defined(_CRSA_BN)
/*
 * BIGNUM implementation
 */
                BN_copy(q,p);
                BN_copy(p,q_minus_1);
#elif defined(_CRSA_MP) 
/*
 * MP_INT implementation
 */
                mpz_set(&q, &p);
                mpz_set(&p, &q_minus_1);
#else /* defined(_CRSA_BN) */
/*
 * Otherwise 
 */
#endif /* defined(_CRSA_BN) */
#endif /* !defined(_CRSA_NO_SORT_PRIMES) */
            }
            else 
            {
                /* p > q
                 */
#if defined(_CRSA_BN)
/*
 * BIGNUM implementation
 */
                BN_copy(p_minus_1,p);
                BN_copy(q_minus_1,q);
#elif defined(_CRSA_MP) 
/*
 * MP_INT implementation
 */
                mpz_set(&p_minus_1, &p);
                mpz_set(&q_minus_1, &q);
#else /* defined(_CRSA_BN) */
/*
 * Otherwise 
 */
#endif /* defined(_CRSA_BN) */
            }

#if !defined(_CRSA_NO_CHECK_CLOSE) 
            /* Make sure that p and q are not too close together
             */
#if defined(_CRSA_BN)
/*
 * BIGNUM implementation
 */
            BN_sub(temp,p_minus_1,q_minus_1);
            BN_rshift(p_minus_1,p_minus_1,10);

            if (BN_cmp(temp,p_minus_1)<0)
#elif defined(_CRSA_MP) 
/*
 * MP_INT implementation
 */
            mpz_sub(&temp, &p_minus_1, &q_minus_1);
            mpz_div_2exp(&p_minus_1, &p_minus_1, 10);

            if (mpz_cmp(&temp, &p_minus_1)<0)
#else /* defined(_CRSA_BN) */
/*
 * Otherwise 
 */
#endif /* defined(_CRSA_BN) */
            {
                /* p-q < p>>10 (they are too close)
                 */
                retryq = true;
                continue;
            }
#endif /* !defined(_CRSA_NO_CHECK_CLOSE) */

            /* Make certain p and q are relatively prime
             * (in case one or both were false positives...
             * Though this is quite improbable). 
             */
#if defined(_CRSA_BN)
/*
 * BIGNUM implementation
 */
            BN_gcd(temp,p,q,ctx);
            if (BN_cmp(temp,one))
#elif defined(_CRSA_MP) 
/*
 * MP_INT implementation
 */
            mpz_gcd(&temp, &p, &q);
            if (mpz_cmp_ui(&temp, 1))
#else /* defined(_CRSA_BN) */
/*
 * Otherwise 
 */
#endif /* defined(_CRSA_BN) */
            {
                retryq = true;
                continue;
            }

            /* Derive the RSA private key from the primes.
             * Given mutual primes p and q, derive RSA key components n, e, d, and u.
             * The exponent e will be at least ebits bits in size.
             * p must be smaller than q.
             */

            /* Compute p-1 and q-1. 
             */
#if defined(_CRSA_BN)
/*
 * BIGNUM implementation
 */
            BN_sub(p_minus_1,p,one);
            BN_sub(q_minus_1,q,one);
#elif defined(_CRSA_MP) 
/*
 * MP_INT implementation
 */
            mpz_sub_ui(&p_minus_1, &p, 1);
            mpz_sub_ui(&q_minus_1, &q, 1);
#else /* defined(_CRSA_BN) */
/*
 * Otherwise 
 */
#endif /* defined(_CRSA_BN) */

            /* phi = (p - 1) * (q - 1); the number of positive integers less than p*q
             * that are relatively prime to p*q. 
             */
#if defined(_CRSA_BN)
/*
 * BIGNUM implementation
 */
            BN_mul(phi,p_minus_1,q_minus_1);
#elif defined(_CRSA_MP) 
/*
 * MP_INT implementation
 */
            mpz_mul(&phi, &p_minus_1, &q_minus_1);
#else /* defined(_CRSA_BN) */
/*
 * Otherwise 
 */
#endif /* defined(_CRSA_BN) */

            /* G is the number of "spare key sets" for a given modulus n.  The smaller
             * G is, the better.  The smallest G can get is 2.
             * F = phi / G; the number of relative prime numbers per spare key set. 
             */
#if defined(_CRSA_BN)
/*
 * BIGNUM implementation
 */
            BN_gcd(G,p_minus_1,q_minus_1,ctx);
            BN_div(F,temp,phi,G,ctx);
#elif defined(_CRSA_MP) 
/*
 * MP_INT implementation
 */
            mpz_gcd(&G, &p_minus_1, &q_minus_1);
            mpz_div(&F, &phi, &G);
#else /* defined(_CRSA_BN) */
/*
 * Otherwise 
 */
#endif /* defined(_CRSA_BN) */

            if (exponent)
            {
#if defined(_CRSA_BN)
/*
 * BIGNUM implementation
 */
                BN_set_msb(e,exponent,expbytes);
#elif defined(_CRSA_MP) 
/*
 * MP_INT implementation
 */
                mpz_set_msb(&e, exponent, expbytes);
#else /* defined(_CRSA_BN) */
/*
 * Otherwise 
 */
#endif /* defined(_CRSA_BN) */
            }
            else
            {
                /* Find a suitable e (the public exponent). 
                 */
#if defined(_CRSA_BN)
/*
 * BIGNUM implementation
 */
                BN_set_word(e,1);
                BN_lshift(e,e,ebits);
                BN_add_word(e,1);
#elif defined(_CRSA_MP) 
/*
 * MP_INT implementation
 */
                mpz_set_ui(&e, 1);
                mpz_mul_2exp(&e, &e, ebits);
                mpz_add_ui(&e, &e, 1);
#else /* defined(_CRSA_BN) */
/*
 * Otherwise 
 */
#endif /* defined(_CRSA_BN) */

                /* make lowest bit 1
                /* Keep adding 2 until it is relatively prime to (p-1)(q-1). 
                 */
                cmp = 0;
                do
                {
#if defined(_CRSA_BN)
/*
 * BIGNUM implementation
 */
                    BN_gcd(temp,e,phi,ctx);
                    if ((cmp = BN_cmp(temp,one))>0)
                        BN_add_word(e,2);
#elif defined(_CRSA_MP) 
/*
 * MP_INT implementation
 */
                    mpz_gcd(&temp, &e, &phi);
                    if ((cmp=mpz_cmp_ui(&temp, 1))>0)
                        mpz_add_ui(&e, &e, 2);
#else /* defined(_CRSA_BN) */
/*
 * Otherwise 
 */
#endif /* defined(_CRSA_BN) */
                }
                while (cmp>0);
            }

            /* d is the multiplicative inverse of e, mod F.  Could also be mod 
             * (p-1)(q-1); however, we try to choose the smallest possible d. 
             */
#if defined(_CRSA_BN)
/*
 * BIGNUM implementation
 */
            d = BN_mod_inverse(e,F,ctx);
            if (d)
            {
#elif defined(_CRSA_MP) 
/*
 * MP_INT implementation
 */
            mpz_mod_inverse(&d, &e, &F);
#else /* defined(_CRSA_BN) */
/*
 * Otherwise 
 */
#endif /* defined(_CRSA_BN) */

            /* Compute dmp1 = d mod p-1. 
             */
#if defined(_CRSA_BN)
/*
 * BIGNUM implementation
 */
            BN_mod(dmp1,d,p_minus_1,ctx);
#elif defined(_CRSA_MP) 
/*
 * MP_INT implementation
 */
            mpz_mod(&dmp1, &d, &p_minus_1);
#else /* defined(_CRSA_BN) */
/*
 * Otherwise 
 */
#endif /* defined(_CRSA_BN) */

            /* Compute dmq1 = d mod q-1. 
             */
#if defined(_CRSA_BN)
/*
 * BIGNUM implementation
 */
            BN_mod(dmq1,d,q_minus_1,ctx);
            BN_free(d);
            }
#elif defined(_CRSA_MP) 
/*
 * MP_INT implementation
 */
            mpz_mod(&dmq1, &d, &q_minus_1);
#else /* defined(_CRSA_BN) */
/*
 * Otherwise 
 */
#endif /* defined(_CRSA_BN) */

            /* iqmp is the multiplicative inverse of q, mod p, if q < p.  It is used
             * when doing private key RSA operations using the chinese remainder
             * theorem method. 
             */
#if defined(_CRSA_BN)
/*
 * BIGNUM implementation
 */
            d = BN_mod_inverse(q,p,ctx);
            if (d)
            {
            BN_copy(iqmp,d);
            BN_free(d);
            }
#elif defined(_CRSA_MP) 
/*
 * MP_INT implementation
 */
            mpz_mod_inverse(&iqmp, &q, &p);
#else /* defined(_CRSA_BN) */
/*
 * Otherwise 
 */
#endif /* defined(_CRSA_BN) */
        }
        while (retryq);
        }
        while (retryp);

#if defined(_CRSA_BN)
/*
 * BIGNUM implementation
 */
        BN_free(temp);
        }
        BN_free(one);
        }
        BN_free(F);
        }
        BN_free(G);
        }
        BN_free(phi);
        }
        BN_free(q_minus_1);
        }
        BN_free(p_minus_1);
        }
#elif defined(_CRSA_MP) 
/*
 * MP_INT implementation
 */
        mpz_clear(&p_minus_1);
        mpz_clear(&q_minus_1);
        mpz_clear(&phi);
        mpz_clear(&G);
        mpz_clear(&F);
        mpz_clear(&d);
        mpz_clear(&one);
        mpz_clear(&temp);
#else /* defined(_CRSA_BN) */
/*
 * Otherwise 
 */
#endif /* defined(_CRSA_BN) */

        if (error)
            privatekey.Destroy();
        }
        if (error)
            publickey.Destroy();
        }
        m_prime_generator.Destroy();
        }
        return error;
    }
};
#endif /* _CRSAPRIVATEKEYGENERATOR_HXX */
