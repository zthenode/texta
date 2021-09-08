///////////////////////////////////////////////////////////////////////
//   File: ccevrsaprivatekey.hpp
//
// Author: $author$
//   Date: 10/30/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CCEVRSAPRIVATEKEY_HPP
#define _CCEVRSAPRIVATEKEY_HPP

#include <vector>
#include "cevrsaprivatekey.hpp"
#include "crsaprivatekey.hxx"

///////////////////////////////////////////////////////////////////////
//  Class: CCEvRSAPrivateKey
//
// Author: $author$
//   Date: 10/30/2007
///////////////////////////////////////////////////////////////////////
class CCEvRSAPrivateKey
: public CEvRSAPrivateKey
{
public:
    typedef CEvRSAPrivateKey CExtends;
    typedef CCEvRSAPrivateKey CDerives;

    CRSAPrivateKey m_deligate;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CCEvRSAPrivateKey
    //
    //       Author: $author$
    //         Date: 10/30/2007
    ///////////////////////////////////////////////////////////////////////
    CCEvRSAPrivateKey() 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CCEvRSAPrivateKey
    //
    //      Author: $author$
    //        Date: 10/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CCEvRSAPrivateKey()
    {
        EvError error;
        if (m_isCreated)
        if ((error = Destroy()))
            throw(error);
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
        EvError error = EV_ERROR_FAILED;
        Error err;

        if ((m_isCreated = !(err = m_deligate.Create(pSize))))
            error = EV_ERROR_NONE;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Destroy
    //
    //   Author: $author$
    //     Date: 10/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Destroy() 
    {
        EvError error = EV_ERROR_FAILED;
        Error err;

        if (!m_isCreated)
            error = EV_ERROR_NOT_CREATED;

        if (!(err = m_deligate.Destroy()))
            error = EV_ERROR_NONE;

        m_isCreated = false;
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Crypt
    //
    //   Author: $author$
    //     Date: 10/31/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Crypt
    (BYTE* out,
     ULONG outSize,
     const BYTE* in,
     LONG inLength=-1) 
    {
        LONG length = -EV_ERROR_FAILED;

        length = m_deligate.Crypt(out, outSize, in, inLength);
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
        EvError error = EV_ERROR_FAILED;
        Error err;

        if (!(err = m_deligate.SetMSB
            (p, q, dmp1, dmq1, iqmp, pSize)))
            error = EV_ERROR_NONE;
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
        EvError error = EV_ERROR_FAILED;
        unsigned length;
        Error err;

        if (!(err = m_deligate.GetMSB
            (length, p, q, dmp1, dmq1, iqmp, pSize)))
        {
            pLength = length;
            error = EV_ERROR_NONE;
        }
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetModulusBytes
    //
    //   Author: $author$
    //     Date: 11/26/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG GetModulusBytes() const 
    {
        LONG count = m_deligate.m_modbytes;
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: DeleteThis
    //
    //   Author: $author$
    //     Date: 2/12/2009
    ///////////////////////////////////////////////////////////////////////
    virtual EvError DeleteThis() 
    {
        EvError error = EV_ERROR_NONE;
        delete this;
        return error;
    }
};

///////////////////////////////////////////////////////////////////////
//  Typedef: CCEvRSAPrivateKeys
//
//   Author: $author$
//     Date: 10/31/2007
///////////////////////////////////////////////////////////////////////
typedef ::std::vector<CCEvRSAPrivateKey*>
CCEvRSAPrivateKeys;

///////////////////////////////////////////////////////////////////////
//  Typedef: CCEvRSAPrivateKeysIterator
//
//   Author: $author$
//     Date: 10/31/2007
///////////////////////////////////////////////////////////////////////
typedef CCEvRSAPrivateKeys::iterator
CCEvRSAPrivateKeysIterator;

///////////////////////////////////////////////////////////////////////
//  Typedef: const_CCEvRSAPrivateKeysIterator
//
//   Author: $author$
//     Date: 10/31/2007
///////////////////////////////////////////////////////////////////////
typedef CCEvRSAPrivateKeys::const_iterator
const_CCEvRSAPrivateKeysIterator;

#endif // _CCEVRSAPRIVATEKEY_HPP
