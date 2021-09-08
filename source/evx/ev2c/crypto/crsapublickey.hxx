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
 *   File: crsapublickey.hxx
 *
 * Author: $author$
 *   Date: $date$
 **********************************************************************
 */
#ifndef _CRSAPUBLICKEY_HXX
#define _CRSAPUBLICKEY_HXX

#include "crsakey.hxx"

/**
 **********************************************************************
 *  Class: CRSAPublicKey
 *
 * Author: $author$
 *   Date: $date$
 **********************************************************************
 */
class CRSAPublicKey
: public CRSAKey
{
public:
    typedef CRSAKey CExtends;
    typedef CRSAPublicKey CDerives;

    unsigned m_expbytes;

#if defined(_CRSA_BN)
/*
 * BIGNUM implementation
 */
    BIGNUM *m_modulus;
    BIGNUM *m_exponent;
#elif defined(_CRSA_MP) 
/*
 * MP_INT implementation
 */
    MP_INT m_modulus;
    MP_INT m_exponent;
#else /* defined(_CRSA_BN) */
/*
 * Otherwise 
 */
#endif /* defined(_CRSA_BN) */

    /**
     **********************************************************************
     * Constructor: CRSAPublicKey
     *
     *      Author: $author$
     *        Date: $date$
     **********************************************************************
     */
    CRSAPublicKey() 
    : m_expbytes(0)
    {
    }
    /**
     **********************************************************************
     * Constructor: CRSAPublicKey
     *
     *      Author: $author$
     *        Date: $date$
     **********************************************************************
     */
    CRSAPublicKey(unsigned modbytes,unsigned expbytes) 
    : m_expbytes(0)
    {
        Error error;
        if ((error = Create(modbytes, expbytes)))
            throw(error);
    }
    /**
     **********************************************************************
     * Destructor: CRSAPublicKey
     *
     *     Author: $author$
     *       Date: $date$
     **********************************************************************
     */
    virtual ~CRSAPublicKey()
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
     * Author: $author$
     *   Date: $date$
     **********************************************************************
     */
    virtual Error Create() 
    {
        Error error = _ERROR_NOT_ALLOWED;
        return error;
    }
    /**
     **********************************************************************
     * Function: Create
     *
     * Author: $author$
     *   Date: $date$
     **********************************************************************
     */
    virtual Error Create(unsigned modbytes, unsigned expbytes) 
    {
        Error error;

        if (m_is_created)
        if ((m_modbytes != modbytes) 
            || (m_expbytes != expbytes))
            return _ERROR_ALREADY_CREATED;
        else return _ERROR_NONE;

#if defined(_CRSA_BN)
/*
 * BIGNUM implementation
 */
        error = _ERROR_NEW;

        if ((m_modulus = BN_new())!=0)
        {
            if ((m_exponent = BN_new())!=0)
            {
                m_modbytes = modbytes;
                m_expbytes = expbytes;

                if (!(error = CExtends::Create()))
                    return error;

                BN_free(m_exponent);
            }
            BN_free(m_modulus);
        }
#elif defined(_CRSA_MP) 
/*
 * MP_INT implementation
 */
        mpz_init_set_ui(&m_modulus,0);
        mpz_init_set_ui(&m_exponent,0);
        m_modbytes=modbytes;
        m_expbytes=expbytes;

        if (!(error = CExtends::Create()))
            return error;

        mpz_clear(&m_modulus);
        mpz_clear(&m_exponent);
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
     * Author: $author$
     *   Date: $date$
     **********************************************************************
     */
    virtual Error Destroy() 
    {
        Error error = _ERROR_NOT_CREATED;

        if (m_is_created)
        {
#if defined(_CRSA_BN)
/*
 * BIGNUM implementation
 */
            BN_free(m_modulus);
            BN_free(m_exponent);
#elif defined(_CRSA_MP) 
/*
 * MP_INT implementation
 */
            mpz_clear(&m_modulus);
            mpz_clear(&m_exponent);
#else /* defined(_CRSA_BN) */
/*
 * Otherwise 
 */
#endif /* defined(_CRSA_BN) */
            error = CExtends::Destroy();
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: Create
     *
     * Author: $author$
     *   Date: $date$
     **********************************************************************
     */
    virtual Error CreateMSB
    (const BYTE *modulus,unsigned modsize,
     const BYTE *exponent,unsigned expsize) 
    {
        Error error;

        if (m_is_created)
            return _ERROR_ALREADY_CREATED;

        if (!(error = Create(modsize, expsize)))
        {
            if (!(error=SetMSB
                (modulus, modsize, exponent, expsize)))
                return error;

            Destroy();
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: SetMSB
     *
     * Author: $author$
     *   Date: $date$
     **********************************************************************
     */
    virtual Error SetMSB
    (const BYTE *modulus,unsigned modsize,
     const BYTE *exponent,unsigned expsize) 
    {
        Error error = _ERROR_FAILED;

        if (!m_is_created)
            return _ERROR_NOT_CREATED;

        m_modbytes = modsize;
        m_expbytes = expsize;

#if defined(_CRSA_BN)
/*
 * BIGNUM implementation
 */
        BN_set_msb(m_modulus, modulus, modsize);
        BN_set_msb(m_exponent, exponent, expsize);
#elif defined(_CRSA_MP) 
/*
 * MP_INT implementation
 */
        mpz_set_msb(&m_modulus, modulus, modsize);
        mpz_set_msb(&m_exponent, exponent, expsize);
#else /* defined(_CRSA_BN) */
/*
 * Otherwise 
 */
#endif /* defined(_CRSA_BN) */
        return _ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: GetMSB
     *
     *   Author: $author$
     *     Date: $date$
     **********************************************************************
     */
    virtual Error GetMSB
    (unsigned& modlength,
     unsigned& explength,
     BYTE *modulus,unsigned modsize,
     BYTE *exponent,unsigned expsize) const 
    {
        Error error = _ERROR_FAILED;

        if (!m_is_created)
            return _ERROR_NOT_CREATED;

        if ((m_modbytes > modsize)
            || (m_expbytes > expsize))
            return _ERROR_KEY_SIZE_UNDER;

        if (m_modbytes < modsize)
            modsize = m_modbytes;

        if (m_expbytes < expsize)
            expsize = m_expbytes;

#if defined(_CRSA_BN)
/*
 * BIGNUM implementation
 */
        BN_get_msb(m_modulus, modulus, modsize);
        BN_get_msb(m_exponent, exponent, expsize);
#elif defined(_CRSA_MP) 
/*
 * MP_INT implementation
 */
        mpz_get_msb(modulus, modsize, &m_modulus);
        mpz_get_msb(exponent, expsize, &m_exponent);
#else /* defined(_CRSA_BN) */
/*
 * Otherwise 
 */
#endif /* defined(_CRSA_BN) */

        modlength = m_modbytes;
        explength = m_expbytes;
        return error;
    }

    /**
     **********************************************************************
     * Function: Crypt
     *
     * Author: $author$
     *   Date: $date$
     **********************************************************************
     */
    virtual int Crypt
    (BYTE *out, int outsize, const BYTE *in, int inlen=-1)
    {
        unsigned inbytes;

        if (!m_is_created)
            return -_ERROR_NOT_CREATED;

        if (0 > inlen)
            inlen = (int)(strlen((const char*)in));

        if (outsize < inlen)
            return _ERROR_INVALID_PARAMETER_SIZE;

        if (m_modbytes != (inbytes = inlen))
            return _ERROR_BLOCK_SIZE;

#if defined(_CRSA_BN)
/*
 * BIGNUM implementation
 */
        BN_set_msb(m_temp, in, inbytes);
        BN_mod_exp(m_temp, m_temp, m_exponent, m_modulus, m_ctx);
        BN_get_msb(m_temp, out, inbytes);
#elif defined(_CRSA_MP) 
/*
 * MP_INT implementation
 */
        mpz_set_msb(&m_temp, in, inbytes);
        mpz_powm(&m_temp, &m_temp, &m_exponent, &m_modulus);
        mpz_get_msb(out, inbytes, &m_temp);
#else /* defined(_CRSA_BN) */
/*
 * Otherwise 
 */
#endif /* defined(_CRSA_BN) */
        return inlen;
    }

    /**
     **********************************************************************
     * Function: GetModulusSize
     *
     * Author: $author$
     *   Date: $date$
     **********************************************************************
     */
    inline unsigned GetModulusSize() const 
    {
        return m_modbytes;
    }
    /**
     **********************************************************************
     * Function: GetExponentSize
     *
     * Author: $author$
     *   Date: $date$
     **********************************************************************
     */
    inline unsigned GetExponentSize() const 
    {
        return m_expbytes;
    }
};
#endif /* _CRSAPUBLICKEY_HXX */
