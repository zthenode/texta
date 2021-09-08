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
 *   File: crsaprivatekeygenerator.cxx
 *
 * Author: $author$
 *   Date: $date$
 **********************************************************************
 */
#include "crsaprivatekeygenerator.hxx"
/**
 **********************************************************************
 *  Class: CRSAPrivateKeyGenerator
 *
 * Author: $author$
 *   Date: $date$
 **********************************************************************
 */

/**
 **********************************************************************
 *  Class: CRSAPrivateKey
 *
 * Author: $author$
 *   Date: $date$
 **********************************************************************
 */
/**
 **********************************************************************
 * Function: CRSAPrivateKey::Generate
 *
 *   Author: $author$
 *     Date: $date$
 **********************************************************************
 */
Error CRSAPrivateKey::Generate
(CRSAPublicKey& publicKey, 
 BYTEStream& random, unsigned modbytes, 
 const BYTE* exponent, unsigned expbytes,
 PrimeReaderEvents* prime_reader_events) 
{
    CRSAPrivateKeyGenerator generator(prime_reader_events);
    Error error = generator.Generate
    (*this, publicKey, random, modbytes, exponent, expbytes);
    return error;
}
