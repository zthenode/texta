///////////////////////////////////////////////////////////////////////
//   File: cevcryptoacquirer.hpp
//
// Author: $author$
//   Date: 10/29/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCRYPTOACQUIRER_HPP
#define _CEVCRYPTOACQUIRER_HPP

#include "evcryptoacquirer.hpp"
#include "cevbase.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvCryptoAcquirer
//
// Author: $author$
//   Date: 10/29/2007
///////////////////////////////////////////////////////////////////////
class CEvCryptoAcquirer
: virtual public EvCryptoAcquirer,
  public CEvBase
{
public:
    typedef EvCryptoAcquirer CImplements;
    typedef CEvBase CExtends;
    typedef CEvCryptoAcquirer CDerives;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvCryptoAcquirer
    //
    //       Author: $author$
    //         Date: 10/29/2007
    ///////////////////////////////////////////////////////////////////////
    CEvCryptoAcquirer() 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvCryptoAcquirer
    //
    //      Author: $author$
    //        Date: 10/29/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvCryptoAcquirer()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: AcquireCrypto
    //
    //   Author: $author$
    //     Date: 10/29/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvCrypto* 
    AcquireCrypto
    (EvError& error) 
    {
        EvCrypto* acquired = 0;
        error = EV_ERROR_NOT_IMPLEMENTED;
        return acquired;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ReleaseCrypto
    //
    //   Author: $author$
    //     Date: 10/29/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ReleaseCrypto
    (EvCrypto& acquired) 
    {
        EvError error = EV_ERROR_NOT_IMPLEMENTED;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ReleaseAllCryptos
    //
    //   Author: $author$
    //     Date: 10/29/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ReleaseAllCryptos() 
    {
        EvError error = EV_ERROR_NOT_IMPLEMENTED;
        return error;
    }
};

#endif // _CEVCRYPTOACQUIRER_HPP
