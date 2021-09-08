///////////////////////////////////////////////////////////////////////
//   File: evcryptoexporter.hpp
//
// Author: $author$
//   Date: 10/27/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _EVCRYPTOEXPORTER_HPP
#define _EVCRYPTOEXPORTER_HPP

#include "evplatform_dll.h"
#include "evcryptoacquirer.hpp"

#define EV_CRYPTO_ACQUIRE EvCryptoAcquire
#define EV_CRYPTO_ACQUIRE_SYMBOL DLL_SYMBOL(EV_CRYPTO_ACQUIRE)

#define EV_CRYPTO_RELEASE EvCryptoRelease
#define EV_CRYPTO_RELEASE_SYMBOL DLL_SYMBOL(EV_CRYPTO_RELEASE)

extern "C" 
{
///////////////////////////////////////////////////////////////////////
//  Typedef: FEvCryptoAcquire
//
//   Author: $author$
//     Date: 10/29/2007
///////////////////////////////////////////////////////////////////////
typedef EV_PLATFORM_EXPORT EvCrypto*
FEvCryptoAcquire(EvError& error);

///////////////////////////////////////////////////////////////////////
//  Typedef: FEvCryptoRelease
//
//   Author: $author$
//     Date: 10/29/2007
///////////////////////////////////////////////////////////////////////
typedef EV_PLATFORM_EXPORT EvError
FEvCryptoRelease(EvCrypto* crypto);

///////////////////////////////////////////////////////////////////////
// Function: EV_CRYPTO_ACQUIRE
//
//   Author: $author$
//     Date: 10/29/2007
///////////////////////////////////////////////////////////////////////
EV_PLATFORM_EXPORT EvCrypto* 
EV_CRYPTO_ACQUIRE(EvError& error);

///////////////////////////////////////////////////////////////////////
// Function: EV_CRYPTO_RELEASE
//
//   Author: $author$
//     Date: 10/29/2007
///////////////////////////////////////////////////////////////////////
EV_PLATFORM_EXPORT EvError 
EV_CRYPTO_RELEASE(EvCrypto* crypto=0);
} // extern "C"

///////////////////////////////////////////////////////////////////////
//  Class: EvCryptoExporter
//
// Author: $author$
//   Date: 10/29/2007
///////////////////////////////////////////////////////////////////////
class EV_EXPORT_CLASS EvCryptoExporter
: virtual public EvCryptoAcquirer
{
public:
    typedef EvCryptoAcquirer CImplements;
    typedef EvCryptoExporter CDerives;
};
#endif // _EVCRYPTOEXPORTER_HPP
