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
//   File: cWinThread.cpp
//
// Author: $author$
//   Date: 6/14/2011
///////////////////////////////////////////////////////////////////////
#include "cWinThread.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
//  Class: cWinThreadInterface
//
// Author: $author$
//   Date: 6/14/2011
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
//  Function: cWinThreadInterface::ThreadProc
//
//    Author: $author$
//      Date: 6/15/2011
///////////////////////////////////////////////////////////////////////
DWORD WINAPI cWinThreadInterface::ThreadProc
(LPVOID lpParameter)
{
    DWORD dwResult = 0;
    cWinThreadInterface* thread;

    if ((thread = (cWinThreadInterface*)(lpParameter)))
        dwResult = thread->Run();
    else
    c_DB_ERROR("() parameter == 0");

    return dwResult;
}

///////////////////////////////////////////////////////////////////////
//  Class: cWinThread
//
// Author: $author$
//   Date: 6/14/2011
///////////////////////////////////////////////////////////////////////

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

        

