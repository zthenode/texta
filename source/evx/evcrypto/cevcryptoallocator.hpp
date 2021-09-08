///////////////////////////////////////////////////////////////////////
//   File: cevcryptoallocator.hpp
//
// Author: $author$
//   Date: 10/27/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCRYPTOALLOCATOR_HPP
#define _CEVCRYPTOALLOCATOR_HPP

#include <vector>
#include "evcryptoallocator.hpp"
#include "cevbase.hpp"

///////////////////////////////////////////////////////////////////////
//  Typedef: EvCryptoVector
//
//   Author: $author$
//     Date: 4/13/2007
///////////////////////////////////////////////////////////////////////
typedef std::vector<EvCrypto*>
EvCryptoVector;

///////////////////////////////////////////////////////////////////////
//  Class: CEvCryptoAllocator
//
// Author: $author$
//   Date: 4/21/2007
///////////////////////////////////////////////////////////////////////
class CEvCryptoAllocator
: virtual public EvCryptoAllocator,
  public CEvBase
{
public:
    typedef EvCryptoAllocator CImplements;
    typedef CEvBase CExtends;
    typedef CEvCryptoAllocator CDerives;

    EvCryptoVector m_cryptos;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvCryptoAllocator
    //
    //       Author: $author$
    //         Date: 4/21/2007
    ///////////////////////////////////////////////////////////////////////
    CEvCryptoAllocator() 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvCryptoAllocator
    //
    //      Author: $author$
    //        Date: 4/21/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvCryptoAllocator()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Initialize
    //
    //   Author: $author$
    //     Date: 4/13/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Initialize() 
    {
        EvError error = EV_ERROR_NONE;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Finalize
    //
    //   Author: $author$
    //     Date: 4/13/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Finalize() 
    {
        EvError error = ReleaseAllCryptos();
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: AcquireCrypto
    //
    //   Author: $author$
    //     Date: 10/29/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvCrypto* AcquireCrypto(EvError &error) 
    {
        EvCrypto* crypto = 0;
        error = EV_ERROR_FAILED;
        return crypto;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ReleaseAllCryptos
    //
    //   Author: $author$
    //     Date: 4/13/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ReleaseAllCryptos() 
    {
        EvError error = EV_ERROR_NONE;
        EvError error2;
        EvCryptoVector::iterator i;
        EvCrypto* crypto;

        for (i = m_cryptos.begin(); i != m_cryptos.end(); i++)
        {
            if ((crypto = *i))
            if ((error2 = crypto->DeleteInstance()))
            if (!error)
                error = error2;
        }
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ReleaseCrypto
    //
    //   Author: $author$
    //     Date: 4/21/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ReleaseCrypto(EvCrypto& crypto) 
    {
        EvError error;
        
        if (!(error = RemoveCrypto(crypto)))
            error = crypto.DeleteInstance();
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: AddCrypto
    //
    //   Author: $author$
    //     Date: 4/13/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError AddCrypto(EvCrypto& crypto) 
    {
        EvError error = EV_ERROR_NONE;
        m_cryptos.push_back(&crypto);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: RemoveCrypto
    //
    //   Author: $author$
    //     Date: 4/13/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError RemoveCrypto(EvCrypto& crypto) 
    {
        EvError error = EV_ERROR_FAILED;
        EvCryptoVector::iterator i;

        for (i = m_cryptos.begin(); i != m_cryptos.end(); i++)
        {
            if (&crypto == *i)
            {
                m_cryptos.erase(i);
                return EV_ERROR_NONE;
            }
        }
        return error;
    }
};

#endif // _CEVCRYPTOALLOCATOR_HPP
