///////////////////////////////////////////////////////////////////////
// Copyright (c) 1988-2019 $organization$
//
// This software is provided by the author and contributors ``as is'' 
// and any express or implied warranties, including, but not limited to, 
// the implied warranties of merchantability and fitness for a particular 
// purpose are disclaimed. In no event shall the author or contributors 
// be liable for any direct, indirect, incidental, special, exemplary, 
// or consequential damages (including, but not limited to, procurement 
// of substitute goods or services; loss of use, data, or profits; or 
// business interruption) however caused and on any theory of liability, 
// whether in contract, strict liability, or tort (including negligence 
// or otherwise) arising in any way out of the use of this software, 
// even if advised of the possibility of such damage.
//
//   File: cevmd5allocator.hpp
//
// Author: $author$
//   Date: 11/30/2019
///////////////////////////////////////////////////////////////////////
#ifndef _CEVMD5ALLOCATOR_HPP
#define _CEVMD5ALLOCATOR_HPP

#include "evmd5allocator.hpp"
#include "cevbase.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
//  Class: CEvMD5Allocator
//
// Author: $author$
//   Date: 11/30/2019
///////////////////////////////////////////////////////////////////////
class CEvMD5Allocator
: virtual public EvMD5Allocator,
  public CEvBase
{
public:
    typedef EvMD5Allocator cImplements;
    typedef CEvBase cExtends;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvMD5Allocator
    //
    //      Author: $author$
    //        Date: 11/30/2019
    ///////////////////////////////////////////////////////////////////////
    CEvMD5Allocator(): m_theOldAllocator(m_theAllocator) {
        m_theAllocator = this;
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvMD5Allocator
    //
    //     Author: $author$
    //       Date: 11/30/2019
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvMD5Allocator() {
        if ((m_theAllocator == this)) {
            m_theAllocator = m_theOldAllocator;
        }
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: AcquireMD5
    //
    //   Author: $author$
    //     Date: 10/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvMD5* AcquireMD5 (EvError& error) {
        EvMD5* acquired = 0;
        error = 0;
        return acquired;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ReleaseMD5
    //
    //   Author: $author$
    //     Date: 10/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ReleaseMD5 (EvMD5& acquired) {
        EvError error = 0;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ReleaseAllMD5s
    //
    //   Author: $author$
    //     Date: 10/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ReleaseAllMD5s() {
        EvError error = 0;
        return error;
    }

protected:
    EvMD5Allocator* m_theOldAllocator;
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _CEVMD5ALLOCATOR_HPP 

