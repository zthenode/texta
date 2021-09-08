///////////////////////////////////////////////////////////////////////
//   File: cevdllcryptomain.hpp
//
// Author: $author$
//   Date: 1/29/2008
///////////////////////////////////////////////////////////////////////

#ifndef _CEVDLLCRYPTOMAIN_HPP
#define _CEVDLLCRYPTOMAIN_HPP

#include "cevmain.hpp"
#include "evdllcryptoallocator.hpp"
#include "evdebug.h"

///////////////////////////////////////////////////////////////////////
//  Class: CEvDllCryptoMain
//
// Author: $author$
//   Date: 1/29/2008
///////////////////////////////////////////////////////////////////////
class CEvDllCryptoMain
: public CEvMain
{
public:
    typedef CEvMain CExtends;
    typedef CEvDllCryptoMain CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvDllCryptoMain
    //
    //       Author: $author$
    //         Date: 1/29/2008
    ///////////////////////////////////////////////////////////////////////
    CEvDllCryptoMain() 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Main
    //
    //    Author: $author$
    //      Date: 1/29/2008
    ///////////////////////////////////////////////////////////////////////
    virtual int Main
    (int argc, const char** argv, const char** env) 
    {
        int err = CExtends::Main(argc, argv, env);
        EvDllCryptoAllocator* theAllocator;
        EvError error;

        // Make sure the DLL is closed before main exits.
        //
        if ((theAllocator = EvDllCryptoAllocator::GetTheAllocator()))
        if ((error = theAllocator->Close()))
            DBE("() failed to close crypto allocator DLL\n");
        return err;
    }
};

#endif // _CEVDLLCRYPTOMAIN_HPP
