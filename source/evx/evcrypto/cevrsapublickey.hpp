///////////////////////////////////////////////////////////////////////
//   File: cevrsapublickey.hpp
//
// Author: $author$
//   Date: 10/27/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVRSAPUBLICKEY_HPP
#define _CEVRSAPUBLICKEY_HPP

#include "evrsapublickey.hpp"
#include "cevrsakey.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvRSAPublicKey
//
// Author: $author$
//   Date: 10/27/2007
///////////////////////////////////////////////////////////////////////
class CEvRSAPublicKey
: virtual public EvRSAPublicKey,
  public CEvRSAKey
{
public:
    typedef EvRSAPublicKey CImplements;
    typedef CEvRSAKey CExtends;
    typedef CEvRSAPublicKey CDerives;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvRSAPublicKey
    //
    //       Author: $author$
    //         Date: 10/27/2007
    ///////////////////////////////////////////////////////////////////////
    CEvRSAPublicKey() 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvRSAPublicKey
    //
    //      Author: $author$
    //        Date: 10/27/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvRSAPublicKey()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Create
    //
    //   Author: $author$
    //     Date: 10/27/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Create
    (ULONG modSize, ULONG expSize) 
    {
        EvError error = EV_ERROR_NOT_IMPLEMENTED;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: CreateMSB
    //
    //   Author: $author$
    //     Date: 10/27/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError CreateMSB
    (const BYTE* modulus,
     ULONG modSize,
     const BYTE* exponent,
     ULONG expSize) 
    {
        EvError error = EV_ERROR_NOT_IMPLEMENTED;

        if (!(error = Create(modSize, expSize)))
        if ((error = SetMSB
            (modulus, modSize, exponent, expSize)))
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
    //     Date: 10/27/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError SetMSB
    (const BYTE* modulus,
     ULONG modSize,
     const BYTE* exponent,
     ULONG expSize) 
    {
        EvError error = EV_ERROR_NOT_IMPLEMENTED;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetMSB
    //
    //   Author: $author$
    //     Date: 10/27/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError GetMSB
    (ULONG& modLength,
     ULONG& expLength,
     BYTE* modulus,
     ULONG modSize,
     BYTE* exponent,
     ULONG expSize) const 
    {
        EvError error = EV_ERROR_NOT_IMPLEMENTED;
        return error;
    }
};
#endif // _CEVRSAPUBLICKEY_HPP
