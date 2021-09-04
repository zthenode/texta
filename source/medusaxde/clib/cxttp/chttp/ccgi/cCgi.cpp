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
//   File: cCgi.cpp
//
// Author: $author$
//   Date: 6/23/2011
///////////////////////////////////////////////////////////////////////
#include "cCgi.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
//  Class: cCgi
//
// Author: $author$
//   Date: 6/23/2011
///////////////////////////////////////////////////////////////////////
//cCgiInterface* cCgi::m_theCgi = 0;
cCgiInterface* g_theCgi = 0;

///////////////////////////////////////////////////////////////////////
//  Class: cCgiInterface
//
// Author: $author$
//   Date: 6/23/2011
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
//  Function: cCgiInterface::SetTheCgi
//
//    Author: $author$
//      Date: 7/26/2011
///////////////////////////////////////////////////////////////////////
cCgiInterface* cCgiInterface::SetTheCgi(cCgiInterface* theCgi)
{
    //cCgiInterface* theOldCgi = cCgi::m_theCgi;
    //cCgi::m_theCgi = theCgi;
    cCgiInterface* theOldCgi = g_theCgi;
    g_theCgi = theCgi;
    return theOldCgi;
}
///////////////////////////////////////////////////////////////////////
//  Function: cCgiInterface::GetTheCgi
//
//    Author: $author$
//      Date: 6/23/2011
///////////////////////////////////////////////////////////////////////
cCgiInterface* cCgiInterface::GetTheCgi()
{
    //cCgiInterface* theCgi = cCgi::m_theCgi;
    cCgiInterface* theCgi = g_theCgi;
    return theCgi;
}

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 
