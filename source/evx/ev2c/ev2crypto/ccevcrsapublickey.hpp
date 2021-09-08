///////////////////////////////////////////////////////////////////////
//   File: ccevcrsapublickey.hpp
//
// Author: $author$
//   Date: 10/27/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CCEVCRSAPUBLICKEY_HPP
#define _CCEVCRSAPUBLICKEY_HPP

#include <vector>
#include "cevrsapublickey.hpp"
#include "crsapublickey.hxx"

///////////////////////////////////////////////////////////////////////
//  Class: CCEvRSAPublicKey
//
// Author: $author$
//   Date: 10/27/2007
///////////////////////////////////////////////////////////////////////
class CCEvRSAPublicKey
: public CEvRSAPublicKey
{
public:
    typedef CEvRSAPublicKey CExtends;
    typedef CCEvRSAPublicKey CDerives;

    CRSAPublicKey m_deligate;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CCEvRSAPublicKey
    //
    //       Author: $author$
    //         Date: 10/27/2007
    ///////////////////////////////////////////////////////////////////////
    CCEvRSAPublicKey() 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CCEvRSAPublicKey
    //
    //      Author: $author$
    //        Date: 10/27/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CCEvRSAPublicKey()
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
    //     Date: 10/27/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Create
    (ULONG modSize, ULONG expSize) 
    {
        EvError error = EV_ERROR_FAILED;
        Error err;

        if ((m_isCreated = !(err = m_deligate.Create(modSize, expSize))))
            error = EV_ERROR_NONE;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Destroy
    //
    //   Author: $author$
    //     Date: 10/27/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Destroy() 
    {
        EvError error = EV_ERROR_FAILED;
        Error err;

        if (!m_isCreated)
            error = EV_ERROR_NOT_CREATED;

        if (!(err = m_deligate.Destroy()))
            error = EV_ERROR_NONE;
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
        LONG length = -EV_ERROR_FAILED;
        int len;

        if (0 <= (len = m_deligate.Crypt
            (out, outSize, in, inLength)))
            length = len;

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
        EvError error = EV_ERROR_FAILED;
        Error err;

        if (!(err = m_deligate.SetMSB
            (modulus, modSize, exponent, expSize)))
            error = EV_ERROR_NONE;
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
        EvError error = EV_ERROR_FAILED;
        Error err;
        unsigned modlength;
        unsigned explength;

        if (!(err = m_deligate.GetMSB
            (modlength, explength,
             modulus, modSize, 
             exponent, expSize)))
        {
            modLength = modlength;
            expLength = explength;
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
//  Typedef: CCEvRSAPublicKeys
//
//   Author: $author$
//     Date: 10/27/2007
///////////////////////////////////////////////////////////////////////
typedef ::std::vector<CCEvRSAPublicKey*>
CCEvRSAPublicKeys;

///////////////////////////////////////////////////////////////////////
//  Typedef: CCEvRSAPublicKeysIterator
//
//   Author: $author$
//     Date: 10/27/2007
///////////////////////////////////////////////////////////////////////
typedef CCEvRSAPublicKeys::iterator
CCEvRSAPublicKeysIterator;

///////////////////////////////////////////////////////////////////////
//  Typedef: const_CCEvRSAPublicKeysIterator
//
//   Author: $author$
//     Date: 10/27/2007
///////////////////////////////////////////////////////////////////////
typedef CCEvRSAPublicKeys::const_iterator
const_CCEvRSAPublicKeysIterator;

#endif // _CCEVCRSAPUBLICKEY_HPP
