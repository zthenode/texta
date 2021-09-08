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
 *   File: smallprimes.h
 *
 * Author: $author$
 *   Date: $date$
 **********************************************************************
 */
#ifndef _SMALLPRIMES_H
#define _SMALLPRIMES_H

#define SMALL_PRIMES_SIZE 1028

#if defined(__cplusplus)
extern "C" {
#endif /* defined(__cplusplus) */

extern const unsigned short g_small_primes[SMALL_PRIMES_SIZE];

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /* _SMALLPRIMES_H */
