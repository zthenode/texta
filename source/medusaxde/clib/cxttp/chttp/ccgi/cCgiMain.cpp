///////////////////////////////////////////////////////////////////////
// Copyright (c) 1988-2012 $organization$
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
//   File: cCgiMain.cpp
//
// Author: $author$
//   Date: 11/21/2012
///////////////////////////////////////////////////////////////////////
#include "cCgi.h"
#include "cCgiMain.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
//  Class: cCgiMain
//
// Author: $author$
//   Date: 11/21/2012
///////////////////////////////////////////////////////////////////////
static cCgiMain* g_theCgiMain = 0;

///////////////////////////////////////////////////////////////////////
//  Function: cCgiMain::SetTheCgiMain
//
//    Author: $author$
//      Date: 11/21/2012
///////////////////////////////////////////////////////////////////////
cCgiMain* cCgiMain::SetTheCgiMain(cCgiMain* theCgiMain) {
    return g_theCgiMain = theCgiMain;
}
///////////////////////////////////////////////////////////////////////
//  Function: cCgiMain::GetTheCgiMain
//
//    Author: $author$
//      Date: 11/21/2012
///////////////////////////////////////////////////////////////////////
cCgiMain* cCgiMain::GetTheCgiMain() {
    return g_theCgiMain;
}

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

        

