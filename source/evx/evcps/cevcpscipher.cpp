///////////////////////////////////////////////////////////////////////
//   File: cevcpscipher.cpp
//
// Author: $author$
//   Date: 12/3/2007
///////////////////////////////////////////////////////////////////////

#include "cevcpscipher.hpp"
#include "evaes.hpp"
#include "evdes3.hpp"
#include "evcipher.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpsCipher
//
// Author: $author$
//   Date: 12/3/2007
///////////////////////////////////////////////////////////////////////
CEvcpsBulkCipherAttributes 
CEvcpsBulkCipher::m_attributes[EVCPS_BULK_CIPHER_ALGORITHMS] = 
{
    {EVCPS_CIPHER_TYPE_STREAM,
     EvCipher::EV_BLOCK_SIZE, 
     EvCipher::EV_KEY_SIZE, 
     EvCipher::EV_IV_SIZE},

    {EVCPS_CIPHER_TYPE_BLOCK,
     EvDES3::EV_BLOCK_SIZE, 
     EvDES3::EV_KEY_SIZE, 
     EvDES3::EV_IV_SIZE},

    {EVCPS_CIPHER_TYPE_BLOCK,
     EvAES::EV_BLOCK_SIZE, 
     EvAES::EV_KEY_SIZE, 
     EvAES::EV_IV_SIZE},
};