///////////////////////////////////////////////////////////////////////
//   File: evrsaprivatekey.hpp
//
// Author: $author$
//   Date: 10/28/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _EVRSAPRIVATEKEY_HPP
#define _EVRSAPRIVATEKEY_HPP

#include "evrsakey.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: EvRSAPrivateKey
//
// Author: $author$
//   Date: 10/30/2007
///////////////////////////////////////////////////////////////////////
class EV_EXPORT_CLASS EvRSAPrivateKey
: virtual public EvRSAKey
{
public:
    typedef EvRSAKey CImplements;
    typedef EvRSAPrivateKey CDerives;

    ///////////////////////////////////////////////////////////////////////
    // Function: CreateMSB
    //
    //   Author: $author$
    //     Date: 10/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Create
    (ULONG pSize) = 0;
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
     ULONG pSize) = 0;
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
     ULONG pSize) = 0;
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
     ULONG pSize) const = 0;
};
#endif // _EVRSAPRIVATEKEY_HPP
