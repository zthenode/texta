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
//   File: cWinCrtThread.cpp
//
// Author: $author$
//   Date: 6/21/2011
///////////////////////////////////////////////////////////////////////
#include "cWinCrtThread.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
//  Class: cWinCrtThreadInterface
//
// Author: $author$
//   Date: 6/21/2011
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
//  Function: cWinCrtThreadInterface::ThreadProc
//
//    Author: $author$
//      Date: 6/21/2011
///////////////////////////////////////////////////////////////////////
unsigned __stdcall cWinCrtThreadInterface::ThreadProc
(void* parameter)
{
    unsigned result = 0;
    cWinCrtThreadInterface* thread;

    if ((thread = (cWinCrtThreadInterface*)(parameter)))
        result = thread->Run();
    else
    c_DB_ERROR("() parameter == 0");
    return result;
}

///////////////////////////////////////////////////////////////////////
//  Class: cWinCrtThread
//
// Author: $author$
//   Date: 6/21/2011
///////////////////////////////////////////////////////////////////////


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 
