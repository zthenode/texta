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
 *   File: primereaderevents.hxx
 *
 * Author: $author$
 *   Date: $date$
 **********************************************************************
 */
#ifndef _PRIMEREADEREVENTS_HXX
#define _PRIMEREADEREVENTS_HXX

#include "base.hxx"
#include "crsakey.hxx"

#if defined(_CRSA_BN)
/*
 * BIGNUM implementation
 */
typedef BIGNUM BIGPRIME;
#elif defined(_CRSA_MP) 
/*
 * MP_INT implementation
 */
typedef MP_INT BIGPRIME;
#else /* defined(_CRSA_BN) */
/*
 * Otherwise 
 */
#endif /* defined(_CRSA_BN) */

/**
 **********************************************************************
 *  Class: PrimeReaderEvents
 *
 * Author: $author$
 *   Date: $date$
 **********************************************************************
 */
class PrimeReaderEvents
: virtual public Base
{
public:
    typedef Base CImplements;
    typedef PrimeReaderEvents CDerives;
    /**
     **********************************************************************
     * Function: OnReadPrime
     *
     *   Author: $author$
     *     Date: $date$
     **********************************************************************
     */
    virtual Error OnReadPrime
    (BIGPRIME *n, unsigned bytes) = 0;
};
#endif /* _PRIMEREADEREVENTS_HXX */
