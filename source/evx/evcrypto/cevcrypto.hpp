///////////////////////////////////////////////////////////////////////
//   File: cevcrypto.hpp
//
// Author: $author$
//   Date: 10/27/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCRYPTO_HPP
#define _CEVCRYPTO_HPP

#include "evcrypto.hpp"
#include "cevinstance.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvCrypto
//
// Author: $author$
//   Date: 10/27/2007
///////////////////////////////////////////////////////////////////////
class CEvCrypto
: virtual public EvCrypto,
  public CEvInstance
{
public:
    typedef EvCrypto CImplements;
    typedef CEvInstance CExtends;
    typedef CEvCrypto CDerives;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvCrypto
    //
    //       Author: $author$
    //         Date: 10/27/2007
    ///////////////////////////////////////////////////////////////////////
    CEvCrypto() 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvCrypto
    //
    //      Author: $author$
    //        Date: 10/27/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvCrypto()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: ReleaseAll
    //
    //   Author: $author$
    //     Date: 10/27/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ReleaseAll() 
    {
        EvError error = EV_ERROR_NOT_IMPLEMENTED;
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: AcquireRSAPublicKey
    //
    //   Author: $author$
    //     Date: 10/27/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvRSAPublicKey* 
    AcquireRSAPublicKey
    (EvError& error) 
    {
        EvRSAPublicKey* key = 0;
        error = EV_ERROR_NOT_IMPLEMENTED;
        return key;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ReleaseRSAPublicKey
    //
    //   Author: $author$
    //     Date: 10/27/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ReleaseRSAPublicKey
    (EvRSAPublicKey& acquired) 
    {
        EvError error = EV_ERROR_NOT_IMPLEMENTED;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ReleaseAllRSAPublicKeys
    //
    //   Author: $author$
    //     Date: 10/27/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ReleaseAllRSAPublicKeys() 
    {
        EvError error = EV_ERROR_NOT_IMPLEMENTED;
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: AcquireRSAPrivateKey
    //
    //   Author: $author$
    //     Date: 10/28/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvRSAPrivateKey* 
    AcquireRSAPrivateKey
    (EvError& error) 
    {
        EvRSAPrivateKey* acquired = 0;
        error = EV_ERROR_NOT_IMPLEMENTED;
        return acquired;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ReleaseRSAPrivateKey
    //
    //   Author: $author$
    //     Date: 10/28/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ReleaseRSAPrivateKey
    (EvRSAPrivateKey& acquired) 
    {
        EvError error = EV_ERROR_NOT_IMPLEMENTED;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ReleaseAllRSAPrivateKeys
    //
    //   Author: $author$
    //     Date: 10/28/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ReleaseAllRSAPrivateKeys() 
    {
        EvError error = EV_ERROR_NOT_IMPLEMENTED;
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: AcquireDES3
    //
    //   Author: $author$
    //     Date: 10/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvDES3* 
    AcquireDES3
    (EvError& error) 
    {
        EvDES3* acquired = 0;
        error = EV_ERROR_NOT_IMPLEMENTED;
        return acquired;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ReleaseDES3
    //
    //   Author: $author$
    //     Date: 10/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ReleaseDES3
    (EvDES3& acquired) 
    {
        EvError error = EV_ERROR_NOT_IMPLEMENTED;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ReleaseAllDES3s
    //
    //   Author: $author$
    //     Date: 10/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ReleaseAllDES3s() 
    {
        EvError error = EV_ERROR_NOT_IMPLEMENTED;
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: AcquireAES
    //
    //   Author: $author$
    //     Date: 10/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvAES* 
    AcquireAES
    (EvError& error) 
    {
        EvAES* acquired = 0;
        error = EV_ERROR_NOT_IMPLEMENTED;
        return acquired;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ReleaseAES
    //
    //   Author: $author$
    //     Date: 10/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ReleaseAES
    (EvAES& acquired) 
    {
        EvError error = EV_ERROR_NOT_IMPLEMENTED;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ReleaseAllAESs
    //
    //   Author: $author$
    //     Date: 10/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ReleaseAllAESs() 
    {
        EvError error = EV_ERROR_NOT_IMPLEMENTED;
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: AcquireMD5
    //
    //   Author: $author$
    //     Date: 10/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvMD5* 
    AcquireMD5
    (EvError& error) 
    {
        EvMD5* acquired = 0;
        error = EV_ERROR_NOT_IMPLEMENTED;
        return acquired;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ReleaseMD5
    //
    //   Author: $author$
    //     Date: 10/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ReleaseMD5
    (EvMD5& acquired) 
    {
        EvError error = EV_ERROR_NOT_IMPLEMENTED;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ReleaseAllMD5s
    //
    //   Author: $author$
    //     Date: 10/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ReleaseAllMD5s() 
    {
        EvError error = EV_ERROR_NOT_IMPLEMENTED;
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: AcquireSHA1
    //
    //   Author: $author$
    //     Date: 10/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvSHA1* 
    AcquireSHA1
    (EvError& error) 
    {
        EvSHA1* acquired = 0;
        error = EV_ERROR_NOT_IMPLEMENTED;
        return acquired;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ReleaseSHA1
    //
    //   Author: $author$
    //     Date: 10/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ReleaseSHA1
    (EvSHA1& acquired) 
    {
        EvError error = EV_ERROR_NOT_IMPLEMENTED;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ReleaseAllSHA1s
    //
    //   Author: $author$
    //     Date: 10/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ReleaseAllSHA1s() 
    {
        EvError error = EV_ERROR_NOT_IMPLEMENTED;
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: DeleteThis
    //
    //   Author: $author$
    //     Date: 10/4/2008
    ///////////////////////////////////////////////////////////////////////
    virtual EvError DeleteThis() 
    {
        EvError error = EV_ERROR_NONE;
        delete this;
        return error;
    }
};
#endif // _CEVCRYPTO_HPP
