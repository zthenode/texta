///////////////////////////////////////////////////////////////////////
//   File: cevcryptoexporter.cpp
//
// Author: $author$
//   Date: 10/27/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#include "evcryptoexporter.hpp"
#include "cevcryptoexporter.hpp"
#include "evdebug.h"

///////////////////////////////////////////////////////////////////////
//  Class: CEvCryptoExporter
//
// Author: $author$
//   Date: 10/27/2007
///////////////////////////////////////////////////////////////////////
CEvCryptoExporter* CEvCryptoExporter::m_exporter = 0;

///////////////////////////////////////////////////////////////////////
//
// Exported functions
//
///////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
// Function: EV_CRYPTO_ACQUIRE
//
//   Author: $author$
//     Date: 10/27/2007
///////////////////////////////////////////////////////////////////////
EV_PLATFORM_EXPORT EvCrypto* 
EV_CRYPTO_ACQUIRE(EvError& error)
{
    EvCrypto* crypto = 0;
    CEvCryptoExporter* exporter;

    if ((exporter = CEvCryptoExporter::GetExporter()))
        crypto = exporter->AcquireEvCrypto(error);
    return crypto;
}

///////////////////////////////////////////////////////////////////////
// Function: EV_CRYPTO_RELEASE
//
//   Author: $author$
//     Date: 10/27/2007
///////////////////////////////////////////////////////////////////////
EV_PLATFORM_EXPORT EvError 
EV_CRYPTO_RELEASE(EvCrypto* crypto)
{
    EvError error = EV_ERROR_FAILED;
    CEvCryptoExporter* exporter;

    //DBF("() in...\n");

    if ((exporter = CEvCryptoExporter::GetExporter()))
    if (crypto)
    {
        if ((error = exporter->ReleaseCrypto(*crypto)))
            DBE("() exporter->ReleaseCrypto failed\n");
    }
    else 
    if ((error = exporter->ReleaseAllCryptos()))
        DBE("() exporter->ReleaseAllCryptos failed\n");
    return error;
}
