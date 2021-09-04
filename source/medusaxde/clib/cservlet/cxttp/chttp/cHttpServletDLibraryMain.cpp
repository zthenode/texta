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
//   File: cHttpServletDLibraryMain.cpp
//
// Author: $author$
//   Date: 10/20/2011
///////////////////////////////////////////////////////////////////////
#include "cHttpServletDLibraryMain.hpp"
#include "cHttpServletDLibraryInterface.hpp"

///////////////////////////////////////////////////////////////////////
// Function: GET_HTTP_SERVLET_ACQUIRER
//
//   Author: $author$
//     Date: 10/27/2011
///////////////////////////////////////////////////////////////////////
PLATFORM_EXPORT cHttpServletAcquirerInterface*
GET_HTTP_SERVLET_ACQUIRER()
{
    cHttpServletAcquirerInterface* theAcquirer = 0;
    cHttpServletDLibraryMainInterface* theMain = 0;
    if ((theMain = cHttpServletDLibraryMainInterface::GetTheMain()))
        theAcquirer = theMain->GetTheAcquirer();
    else
    c_DB_ERROR("() failed on cHttpServletDLibraryMainInterface::GetTheMain()");
    return theAcquirer;
}

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
//  Class: cHttpServletDLibraryMainInterface
//
// Author: $author$
//   Date: 10/27/2011
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
//  Function: cHttpServletDLibraryMainInterface::GetTheMain
//
//    Author: $author$
//      Date: 10/27/2011
///////////////////////////////////////////////////////////////////////
cHttpServletDLibraryMainInterface* 
cHttpServletDLibraryMainInterface::GetTheMain()
{ 
    return cHttpServletDLibraryMain::GetTheMain(); 
}

///////////////////////////////////////////////////////////////////////
//  Class: cHttpServletDLibraryMain
//
// Author: $author$
//   Date: 10/20/2011
///////////////////////////////////////////////////////////////////////
cHttpServletDLibraryMainInterface* cHttpServletDLibraryMain::m_theMain = 0;

#if !defined(CHTTPSERVLETDLIBRARYMAIN_NO_INSTANCE) 
cHttpServletDLibraryMain g_cHttpServletDLibraryMain;
#else // !defined(CHTTPSERVLETDLIBRARYMAIN_NO_INSTANCE) 
#endif // !defined(CHTTPSERVLETDLIBRARYMAIN_NO_INSTANCE) 

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

        

