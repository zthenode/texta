///////////////////////////////////////////////////////////////////////
//   File: cevmd5.hpp
//
// Author: $author$
//   Date: 11/2/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVMD5_HPP
#define _CEVMD5_HPP

#include "evmd5.hpp"
#include "cevhash.hpp"
#include "evmd5allocator.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvMD5
//
// Author: $author$
//   Date: 11/2/2007
///////////////////////////////////////////////////////////////////////
class CEvMD5
: virtual public EvMD5,
  public CEvHash
{
public:
    typedef EvMD5 CImplements;
    typedef CEvHash CExtends;
    typedef CEvMD5 CDerives;

    EvMD5* m_md5Deligate;
    EvMD5Allocator* m_md5Allocator;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvMD5
    //
    //       Author: $author$
    //         Date: 11/2/2007
    ///////////////////////////////////////////////////////////////////////
    CEvMD5(EvMD5* md5Deligate=0)
    : CExtends(md5Deligate),
      m_md5Deligate(md5Deligate),
      m_md5Allocator(0)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvMD5
    //
    //      Author: $author$
    //        Date: 11/2/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvMD5()
    {
        EvError error;
        if (m_md5Deligate)
        if (m_md5Allocator)
        if ((error = m_md5Allocator->ReleaseMD5(*m_md5Deligate)))
            throw(error);
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
        if (!m_md5Deligate)
        {
            EvError error;

            if (!m_md5Allocator)
            if (!(m_md5Allocator = EvMD5Allocator::m_theAllocator))
                return count;

            if (!(m_md5Deligate = m_md5Allocator->AcquireMD5(error)))
                return count;

            //m_md5Allocator->ReleaseMD5(*m_md5Deligate);

            m_deligate = m_md5Deligate;
        }
        count = m_deligate->Initialize(key, length);
        return count;
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
        return hashSize;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: DeleteThis
    //
    //   Author: $author$
    //     Date: 1/7/2012
    ///////////////////////////////////////////////////////////////////////
    virtual EvError DeleteThis()
    {
        return EV_ERROR_NOT_ALLOWED;
    }
};

#endif // _CEVMD5_HPP
