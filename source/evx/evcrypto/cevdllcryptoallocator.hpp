///////////////////////////////////////////////////////////////////////
//   File: cevdllcryptoallocator.hpp
//
// Author: $author$
//   Date: 1/27/2008
///////////////////////////////////////////////////////////////////////

#ifndef _CEVDLLCRYPTOALLOCATOR_HPP
#define _CEVDLLCRYPTOALLOCATOR_HPP

#include "evdllcryptoallocator.hpp"
#include "evmd5allocator.hpp"
#include "cevcryptodll.hpp"
#include "cevbase.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvDllCryptoAllocator
//
// Author: $author$
//   Date: 1/27/2008
///////////////////////////////////////////////////////////////////////
class CEvDllCryptoAllocator
: virtual public EvDllCryptoAllocator,
  virtual public EvMD5Allocator,
  public CEvBase
{
public:
    typedef EvMD5Allocator CEvImplements;
    typedef CEvBase CEvExtends;
    typedef CEvDllCryptoAllocator CEvDerives;

    EvDllCryptoAllocator* m_oldDllCryptoAllocator;
    EvMD5Allocator* m_oldMD5Allocator;
    CEvCryptoDll m_cryptoDll;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvDllCryptoAllocator
    //
    //      Author: $author$
    //        Date: 1/27/2008
    ///////////////////////////////////////////////////////////////////////
    CEvDllCryptoAllocator() 
    : m_oldDllCryptoAllocator(EvDllCryptoAllocator::m_theAllocator),
      m_oldMD5Allocator(EvMD5Allocator::m_theAllocator)
    {
        EvDllCryptoAllocator::m_theAllocator = this;
        EvMD5Allocator::m_theAllocator = this;
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: CEvDllCryptoAllocator
    //
    //     Author: $author$
    //       Date: 1/27/2008
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvDllCryptoAllocator()
    {
        if (this == EvDllCryptoAllocator::m_theAllocator)
            EvDllCryptoAllocator::m_theAllocator = m_oldDllCryptoAllocator;

        if (this == EvMD5Allocator::m_theAllocator)
            EvMD5Allocator::m_theAllocator = m_oldMD5Allocator;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Open
    //
    //   Author: $author$
    //     Date: 1/29/2008
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Open
    (const char* dllFilename=0,
     bool onlyClosed=false) 
    {
        EvError error = m_cryptoDll.Open(dllFilename, onlyClosed);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Close
    //
    //   Author: $author$
    //     Date: 1/29/2008
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Close
    (bool onlyOpened=false) 
    {
        EvError error = m_cryptoDll.Close(onlyOpened);
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
        EvMD5* acquired = m_cryptoDll.AcquireMD5(error);
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
        EvError error = m_cryptoDll.ReleaseMD5(acquired);
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
        EvError error = m_cryptoDll.ReleaseAllMD5s();
        return error;
    }
};
#endif // _CEVDLLCRYPTOALLOCATOR_HPP 
