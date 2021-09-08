///////////////////////////////////////////////////////////////////////
//   File: cevrsaprivatekey.hpp
//
// Author: $author$
//   Date: 10/30/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVRSAPRIVATEKEY_HPP
#define _CEVRSAPRIVATEKEY_HPP

#include "evrsaprivatekey.hpp"
#include "cevrsapublickey.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvRSAPrivateKey
//
// Author: $author$
//   Date: 10/30/2007
///////////////////////////////////////////////////////////////////////
class CEvRSAPrivateKey
: virtual public EvRSAPrivateKey,
  public CEvRSAKey
{
public:
    typedef EvRSAPrivateKey CImplements;
    typedef CEvRSAKey CExtends;
    typedef CEvRSAPrivateKey CDerives;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvRSAPrivateKey
    //
    //       Author: $author$
    //         Date: 10/30/2007
    ///////////////////////////////////////////////////////////////////////
    CEvRSAPrivateKey() 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvRSAPrivateKey
    //
    //      Author: $author$
    //        Date: 10/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvRSAPrivateKey()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Destroy
    //
    //   Author: $author$
    //     Date: 10/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Destroy() 
    {
        EvError error = EV_ERROR_NOT_IMPLEMENTED;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Create
    //
    //   Author: $author$
    //     Date: 10/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Create
    (ULONG pSize) 
    {
        EvError error = EV_ERROR_NOT_IMPLEMENTED;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: CreateMSB
    //
    //   Author: $author$
    //     Date: 10/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError CreateMSB
    (const BYTE* p,
     const BYTE* q,
     const BYTE* dmp1,
     const BYTE* dmq1,
     const BYTE* iqmp,
     ULONG pSize) 
    {
        EvError error = EV_ERROR_NOT_IMPLEMENTED;

        if (!(error = Create(pSize)))
        if ((error = SetMSB
            (p, q, dmp1, dmq1, iqmp, pSize)))
            Destroy();

        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Crypt
    //
    //   Author: $author$
    //     Date: 10/27/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Crypt
    (BYTE* out,
     ULONG outSize,
     const BYTE* in,
     LONG inLength=-1) 
    {
        LONG length = -EV_ERROR_NOT_IMPLEMENTED;
        return length;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetMSB
    //
    //   Author: $author$
    //     Date: 10/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError SetMSB
    (const BYTE* p,
     const BYTE* q,
     const BYTE* dmp1,
     const BYTE* dmq1,
     const BYTE* iqmp,
     ULONG pSize) 
    {
        EvError error = EV_ERROR_NOT_IMPLEMENTED;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetMSB
    //
    //   Author: $author$
    //     Date: 10/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError GetMSB
    (ULONG& pLength,
     BYTE* p,
     BYTE* q,
     BYTE* dmp1,
     BYTE* dmq1,
     BYTE* iqmp,
     ULONG pSize) const 
    {
        EvError error = EV_ERROR_NOT_IMPLEMENTED;
        return error;
    }
};
#endif // _CEVRSAPRIVATEKEY_HPP
