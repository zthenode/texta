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
 *   File: crsakey.hxx
 *
 * Author: $author$
 *   Date: $date$
 **********************************************************************
 */
#ifndef _CRSAKEY_HXX
#define _CRSAKEY_HXX

#include "ccryptor.hxx"

#if !defined(_CRSA_BN) && !defined(_CRSA_MP)
#define _CRSA_BN
#endif /* !defined(_CRSA_BN) && !defined(_CRSA_MP) */

#if defined(_CRSA_BN)
/*
 * BIGNUM implementation
 */
#include "bn_msb.h"
#elif defined(_CRSA_MP) 
/*
 * MP_INT implementation
 */
#include "mpz_msb.h"
#else /* defined(_CRSA_BN) */
/*
 * Otherwise 
 */
#endif /* defined(_CRSA_BN) */

/**
 **********************************************************************
 *  Class: CRSAKey
 *
 * Author: $author$
 *   Date: $date$
 **********************************************************************
 */
class CRSAKey
: public CCryptor
{
public:
    typedef CCryptor CExtends;
    typedef CRSAKey CDerives;

    bool m_is_created;
    unsigned m_modbytes;

#if defined(_CRSA_BN)
/*
 * BIGNUM implementation
 */
    BIGNUM *m_temp;
    BN_CTX *m_ctx;
#elif defined(_CRSA_MP) 
/*
 * MP_INT implementation
 */
    MP_INT m_temp;
#else /* defined(_CRSA_BN) */
/*
 * Otherwise 
 */
#endif /* defined(_CRSA_BN) */

    /**
     **********************************************************************
     * Constructor: CRSAKey
     *
     *      Author: $author$
     *        Date: $date$
     **********************************************************************
     */
    CRSAKey() 
    : m_is_created(false),
      m_modbytes(0)
#if defined(_CRSA_BN)
/*
 * BIGNUM implementation
 */
     ,m_temp(0),
      m_ctx(0)
#endif
    {
    }
    /**
     **********************************************************************
     * Destructor: CRSAKey
     *
     *     Author: $author$
     *       Date: $date$
     **********************************************************************
     */
    virtual ~CRSAKey()
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
        Error error;

        if (m_is_created)
            return _ERROR_ALREADY_CREATED;

#if defined(_CRSA_BN)
/*
 * BIGNUM implementation
 */
        error = _ERROR_NEW;

        if ((m_temp = BN_new()))
        {
            if ((m_ctx = BN_CTX_new()))
            {
                m_is_created = true;
                return _ERROR_NONE;
            }
            BN_free(m_temp);
        }
#elif defined(_CRSA_MP) 
/*
 * MP_INT implementation
 */
        mpz_init_set_ui(&m_temp,0);
        m_is_created = true;
        error = _ERROR_NONE;
#else /* defined(_CRSA_BN) */
/*
 * Otherwise 
 */
#endif /* defined(_CRSA_BN) */
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
    virtual Error Create(unsigned modbytes) 
    {
        Error error;
        if (!(error = CDerives::Create()))
            m_modbytes = modbytes;
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
            BN_free(m_temp);
            BN_CTX_free(m_ctx);
#elif defined(_CRSA_MP) 
/*
 * MP_INT implementation
 */
            mpz_clear(&m_temp);
#else /* defined(_CRSA_BN) */
/*
 * Otherwise 
 */
#endif /* defined(_CRSA_BN) */
            m_modbytes = 0;
            m_is_created = false;
            error = _ERROR_NONE;
        }
        return error;
    }
};
#endif /* _CRSAKEY_HXX */
