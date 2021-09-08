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
//   File: ccevmd5allocator.hpp
//
// Author: $author$
//   Date: 11/30/2019
///////////////////////////////////////////////////////////////////////
#ifndef _CCEVMD5ALLOCATOR_HPP
#define _CCEVMD5ALLOCATOR_HPP

#include "cevmd5allocator.hpp"
#include "ccevmd5.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
//  Class: CCEvMD5Allocator
//
// Author: $author$
//   Date: 11/30/2019
///////////////////////////////////////////////////////////////////////
class CCEvMD5Allocator
: public CEvMD5Allocator
{
public:
    typedef CEvMD5Allocator cExtends;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CCEvMD5Allocator
    //
    //      Author: $author$
    //        Date: 11/30/2019
    ///////////////////////////////////////////////////////////////////////
    CCEvMD5Allocator() {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CCEvMD5Allocator
    //
    //     Author: $author$
    //       Date: 11/30/2019
    ///////////////////////////////////////////////////////////////////////
    virtual ~CCEvMD5Allocator() {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: AcquireMD5
    //
    //   Author: $author$
    //     Date: 10/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvMD5* AcquireMD5 (EvError& error) {
        EvMD5* acquired = new CCEvMD5;
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
        delete &acquired;
        return error;
    }
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _CCEVMD5ALLOCATOR_HPP 

