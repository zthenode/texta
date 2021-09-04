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
//   File: cPThread.cpp
//
// Author: $author$
//   Date: 6/16/2011
///////////////////////////////////////////////////////////////////////
#include "cPThread.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
//  Class: cPThreadInterface
//
// Author: $author$
//   Date: 6/16/2011
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
//  Function: cPThreadInterface::ThreadRoutine
//
//    Author: $author$
//      Date: 6/16/2011
///////////////////////////////////////////////////////////////////////
void* cPThreadInterface::ThreadRoutine(void* arg)
{
    void* result = 0;
    cPThreadInterface* thread;
    eError error;

    if ((thread = (cPThreadInterface*)(arg)))
        error = thread->Run();
    else
    c_DB_ERROR("() arg == 0");
    return result;
}

///////////////////////////////////////////////////////////////////////
//  Class: cPThread
//
// Author: $author$
//   Date: 6/16/2011
///////////////////////////////////////////////////////////////////////

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

        

