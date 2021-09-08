///////////////////////////////////////////////////////////////////////
//   File: cevcpscipher.hpp
//
// Author: $author$
//   Date: 12/3/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCPSCIPHER_HPP
#define _CEVCPSCIPHER_HPP

#include "evplatform.h"

///////////////////////////////////////////////////////////////////////
//   Enum:  
//
// Author: $author$
//   Date: 12/3/2007
///////////////////////////////////////////////////////////////////////
enum 
{
    EVCPS_CIPHER_TYPE_STREAM,
    EVCPS_CIPHER_TYPE_BLOCK,

    EVCPS_CIPHER_TYPES
};

#define EVCPS_CIPHER_TYPE_NAME_STREAM "STREAM"
#define EVCPS_CIPHER_TYPE_NAME_BLOCK "BLOCK"

///////////////////////////////////////////////////////////////////////
//   Enum:  
//
// Author: $author$
//   Date: 12/3/2007
///////////////////////////////////////////////////////////////////////
enum 
{
    EVCPS_BULK_CIPHER_ALGORITHM_NULL,

    EVCPS_BULK_CIPHER_ALGORITHM_DES3,
    EVCPS_BULK_CIPHER_ALGORITHM_AES256,

    EVCPS_BULK_CIPHER_ALGORITHMS
};

#define EVCPS_BULK_CIPHER_ALGORITHM_NAME_NULL "NULL"
#define EVCPS_BULK_CIPHER_ALGORITHM_NAME_DES3 "DES3"
#define EVCPS_BULK_CIPHER_ALGORITHM_NAME_AES256 "AES256"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpsBulkCipherAttributes
//
// Author: $author$
//   Date: 12/3/2007
///////////////////////////////////////////////////////////////////////
class CEvcpsBulkCipherAttributes
{
public:
    typedef CEvcpsBulkCipherAttributes CDerives;

    BYTE m_type;
    BYTE m_blockSize;
    BYTE m_keySize;
    BYTE m_ivSize;
};

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpsBulkCipher
//
// Author: $author$
//   Date: 12/3/2007
///////////////////////////////////////////////////////////////////////
class CEvcpsBulkCipher
{
public:
    typedef CEvcpsBulkCipher CDerives;

    static CEvcpsBulkCipherAttributes 
    m_attributes[EVCPS_BULK_CIPHER_ALGORITHMS];
};

#endif // _CEVCPSCIPHER_HPP
