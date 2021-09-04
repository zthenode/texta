///////////////////////////////////////////////////////////////////////
// Copyright (c) 1988-2011 $organization$
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
//   File: cUnixDLibraryMain_init_fini.cpp
//
// Author: $author$
//   Date: 10/16/2011
///////////////////////////////////////////////////////////////////////
#include "cUnixDLibraryMainInterface.hpp"
#include "cplatform_dlibrary.h"
#include "cDebug.hpp"

#if defined(c_NAMESPACE)
using namespace c_NAMESPACE;
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Function: _init
//
//   Author: $author$
//     Date: 10/16/2011
///////////////////////////////////////////////////////////////////////
#if defined(GNU_INIT_FINI) 
// Gnu _init and _fini 
void __attribute__ ((constructor)) cdlibrary_init(void)
#else // defined(GNU_INIT_FINI) 
// Otherwise 
void _init(void) 
#endif // defined(GNU_INIT_FINI) 
{
    cUnixDLibraryMainInterface* theMain = 0;
    eError error;
    c_DB_TRACE("() in...");
    if ((theMain = cUnixDLibraryMainInterface::GetTheMain()))
    {
        if ((error = theMain->Init()))
            c_DB_ERROR("() failed on theMain->Init() == " << error);
    }
    else
    c_DB_ERROR("() failed on cUnixDLibraryMainInterface::GetTheMain() == 0");
    c_DB_TRACE("() ...out");
}
///////////////////////////////////////////////////////////////////////
// Function: _fini
//
//   Author: $author$
//     Date: 10/16/2011
///////////////////////////////////////////////////////////////////////
#if defined(GNU_INIT_FINI) 
// Gnu _init and _fini 
void __attribute__ ((destructor)) cdlibrary_fini(void)
#else // defined(GNU_INIT_FINI) 
// Otherwise 
void _fini(void) 
#endif // defined(GNU_INIT_FINI) 
{
    cUnixDLibraryMainInterface* theMain = 0;
    eError error;
    c_DB_TRACE("() in...");
    if ((theMain = cUnixDLibraryMainInterface::GetTheMain()))
    {
        if ((error = theMain->Finish()))
            c_DB_ERROR("() failed on theMain->Finish() == " << error);
    }
    else
    c_DB_ERROR("() failed on cUnixDLibraryMainInterface::GetTheMain() == 0");
    c_DB_TRACE("() ...out");
}
