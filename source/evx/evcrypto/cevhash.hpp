///////////////////////////////////////////////////////////////////////
//   File: cevhash.hpp
//
// Author: $author$
//   Date: 11/2/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVHASH_HPP
#define _CEVHASH_HPP

#include <string.h>
#include "evhash.hpp"
#include "cevencryptor.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvHash
//
// Author: $author$
//   Date: 11/2/2007
///////////////////////////////////////////////////////////////////////
class CEvHash
: virtual public EvHash,
  public CEvEncryptor
{
public:
    typedef EvHash CImplements;
    typedef CEvEncryptor CExtends;
    typedef CEvHash CDerives;

    EvHash* m_deligate;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvHash
    //
    //       Author: $author$
    //         Date: 11/2/2007
    ///////////////////////////////////////////////////////////////////////
    CEvHash(EvHash* deligate=0)
    : m_deligate(deligate) 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvHash
    //
    //      Author: $author$
    //        Date: 11/2/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvHash()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Initialize
    //
    //   Author: $author$
    //     Date: 11/5/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Initialize
    (const BYTE* key=0,
     LONG length=-1) 
    {
        LONG count = -EV_ERROR_NOT_ALLOWED;
        if (m_deligate)
            count = m_deligate->Initialize(key, length);
        else
        if (!key || !length)
            return 0;
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Finalize
    //
    //   Author: $author$
    //     Date: 11/5/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Finalize
    (BYTE* out,
     ULONG size) 
    {
        LONG count = 0;
        if (m_deligate)
            count = m_deligate->Finalize(out, size);
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Hash
    //
    //   Author: $author$
    //     Date: 11/5/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Hash
    (const BYTE* in,
     LONG length=-1) 
    {
        if (m_deligate)
            length = m_deligate->Hash(in, length);
        else
        if (0 > length)
            length = (LONG)strlen((char*)(in));
        return length;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: GetHashSize
    //
    //   Author: $author$
    //     Date: 12/5/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG GetHashSize() const 
    {
        LONG hashSize = EV_HASH_SIZE;
        if (m_deligate)
            hashSize = m_deligate->GetHashSize();
        return hashSize;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: DeleteThis
    //
    //   Author: $author$
    //     Date: 1/30/2012
    ///////////////////////////////////////////////////////////////////////
    virtual EvError DeleteThis()
    {
        EvError error = EV_ERROR_NOT_ALLOWED;
        return error;
    }
};

#endif // _CEVHASH_HPP
