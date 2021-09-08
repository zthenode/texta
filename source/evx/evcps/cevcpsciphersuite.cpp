///////////////////////////////////////////////////////////////////////
//   File: cevcpsciphersuite.cpp
//
// Author: $author$
//   Date: 11/21/2007
///////////////////////////////////////////////////////////////////////

#include "cevcpsciphersuite.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpsCipherSuite
//
// Author: $author$
//   Date: 11/21/2007
///////////////////////////////////////////////////////////////////////

USHORT CEvcpsCipherSuite::m_suiteValue[EVCPS_CIPHER_SUITES] = 
{
    EVCPS_CIPHER_SUITE_VALUE_NULL_WITH_NULL_NULL,
    EVCPS_CIPHER_SUITE_VALUE_RSA_WITH_3DES_EDE_CBC_SHA,
    EVCPS_CIPHER_SUITE_VALUE_RSA_WITH_AES_256_CBC_SHA
};

CEvcpsCipherSuiteAttributes 
CEvcpsCipherSuite::m_suiteAttributes[EVCPS_CIPHER_SUITES] = 
{
    {EVCPS_KEY_EXCHANGE_TYPE_NULL,
     EVCPS_BULK_CIPHER_ALGORITHM_NULL,
     EVCPS_MAC_ALGORITHM_NULL},

    {EVCPS_KEY_EXCHANGE_TYPE_RSA,
     EVCPS_BULK_CIPHER_ALGORITHM_DES3,
     EVCPS_MAC_ALGORITHM_SHA1}, 

    {EVCPS_KEY_EXCHANGE_TYPE_RSA,
     EVCPS_BULK_CIPHER_ALGORITHM_AES256,
     EVCPS_MAC_ALGORITHM_SHA1}
};
