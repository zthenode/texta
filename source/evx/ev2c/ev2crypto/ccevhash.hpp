///////////////////////////////////////////////////////////////////////
//   File: ccevhash.hpp
//
// Author: $author$
//   Date: 11/5/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CCEVHASH_HPP
#define _CCEVHASH_HPP

#include <vector>
#include "evhash.hpp"
#include "cevhash.hpp"
#include "chash.hxx"

///////////////////////////////////////////////////////////////////////
//  Class: CCEvHash
//
// Author: $author$
//   Date: 11/5/2007
///////////////////////////////////////////////////////////////////////
class CCEvHash
: virtual public EvHash,
  public CEvHash
{
public:
    typedef EvHash CImplements;
    typedef CEvHash CExtends;
    typedef CCEvHash CDerives;

    CHash* m_hash;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CCEvHash
    //
    //       Author: $author$
    //         Date: 11/5/2007
    ///////////////////////////////////////////////////////////////////////
    CCEvHash() 
    : m_hash(0)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CCEvHash
    //
    //      Author: $author$
    //        Date: 11/5/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CCEvHash()
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
        LONG count = -EV_ERROR_FAILED;
        int len;
        if (m_hash)
        if (0 <= (len = m_hash->Initialize(key, length)))
            count = len;
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
        LONG count = -EV_ERROR_FAILED;
        int len;
        if (m_hash)
        if (0 <= (len = m_hash->Finalize(out, size)))
            count = len;
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
        LONG count = -EV_ERROR_FAILED;
        int len;
        if (m_hash)
        if (0 <= (len = m_hash->Hash(in, length)))
            count = len;
        return count;
    }
};

///////////////////////////////////////////////////////////////////////
//  Typedef: CCEvHashs
//
//   Author: $author$
//     Date: 11/5/2007
///////////////////////////////////////////////////////////////////////
typedef ::std::vector<CCEvHash*>
CCEvHashs;

///////////////////////////////////////////////////////////////////////
//  Typedef: CCEvHashsIterator
//
//   Author: $author$
//     Date: 11/5/2007
///////////////////////////////////////////////////////////////////////
typedef CCEvHashs::iterator
CCEvHashsIterator;

///////////////////////////////////////////////////////////////////////
//  Typedef: const_CCEvHashsIterator
//
//   Author: $author$
//     Date: 11/5/2007
///////////////////////////////////////////////////////////////////////
typedef CCEvHashs::const_iterator
const_CCEvHashsIterator;

#endif // _CCEVHASH_HPP
