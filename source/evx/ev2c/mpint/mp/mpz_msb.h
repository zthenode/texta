/**
 **********************************************************************
 * Copyright (c) 1988-2005 $author$.
 *
 * This software is provided by the author and contributors ``as is'' and
 * any express or implied warranties, including, but not limited to, the
 * implied warranties of merchantability and fitness for a particular purpose
 * are disclaimed.  In no event shall the author or contributors be liable
 * for any direct, indirect, incidental, special, exemplary, or consequential
 * damages (including, but not limited to, procurement of substitute goods
 * or services; loss of use, data, or profits; or business interruption)
 * however caused and on any theory of liability, whether in contract, strict
 * liability, or tort (including negligence or otherwise) arising in any way
 * out of the use of this software, even if advised of the possibility of
 * such damage.
 *
 *   File: mpz_msb.h
 *
 * Author: $author$
 *   Date: 2/1/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _MPZ_MSB_H
#define _MPZ_MSB_H

#include <gmp.h>

#if defined(__cplusplus)
extern "C" {
#endif

/**
 **********************************************************************
 * Function: mpz_get_msb
 *
 *   Author: $author$
 *     Date: 2/1/2005
 **********************************************************************
 */
mp_size_t mpz_get_msb _PROTO ((unsigned char *, mp_size_t , mpz_srcptr));
/**
 **********************************************************************
 * Function: mpz_set_msb
 *
 *   Author: $author$
 *     Date: 2/1/2005
 **********************************************************************
 */
mp_size_t mpz_set_msb _PROTO ((mpz_ptr, const unsigned char *, mp_size_t));

#if defined(__cplusplus)
}
#endif

#endif
