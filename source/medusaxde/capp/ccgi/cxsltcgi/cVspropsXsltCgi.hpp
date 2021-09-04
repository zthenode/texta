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
//   File: cVspropsXsltCgi.hpp
//
// Author: $author$
//   Date: 11/20/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CVSPROPSXSLTCGI_HPP) || defined(CVSPROPSXSLTCGI_MEMBERS_ONLY)
#if !defined(_CVSPROPSXSLTCGI_HPP) && !defined(CVSPROPSXSLTCGI_MEMBERS_ONLY)
#define _CVSPROPSXSLTCGI_HPP
#endif // !defined(_CVSPROPSXSLTCGI_HPP) && !defined(CVSPROPSXSLTCGI_MEMBERS_ONLY) 

#if !defined(CVSPROPSXSLTCGI_MEMBERS_ONLY)

#if !defined(CXSLTCGI_NAME) 
#define CXSLTCGI_NAME "cVspropsXsltCgi"
#else // !defined(CXSLTCGI_NAME) 
#endif // !defined(CXSLTCGI_NAME) 

#include "cVcprojXsltCgi.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cVspropsXsltCgiExtend
//
//  Author: $author$
//    Date: 11/20/2011
///////////////////////////////////////////////////////////////////////
typedef cVcprojXsltCgi
cVspropsXsltCgiExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cVspropsXsltCgi
//
// Author: $author$
//   Date: 11/20/2011
///////////////////////////////////////////////////////////////////////
class c_EXPORT_CLASS cVspropsXsltCgi
: public cVspropsXsltCgiExtend
{
public:
    typedef cVspropsXsltCgiExtend cExtends;
    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cVspropsXsltCgi
    //
    //       Author: $author$
    //         Date: 11/20/2011
    ///////////////////////////////////////////////////////////////////////
    cVspropsXsltCgi()
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cVspropsXsltCgi
    //
    //      Author: $author$
    //        Date: 11/20/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cVspropsXsltCgi()
    {
    }
#else // !defined(CVSPROPSXSLTCGI_MEMBERS_ONLY) 
#endif // !defined(CVSPROPSXSLTCGI_MEMBERS_ONLY) 

#if !defined(CVSPROPSXSLTCGI_MEMBERS_ONLY)
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CVSPROPSXSLTCGI_MEMBERS_ONLY) 
#endif // !defined(CVSPROPSXSLTCGI_MEMBERS_ONLY) 

#endif // !defined(_CVSPROPSXSLTCGI_HPP) || defined(CVSPROPSXSLTCGI_MEMBERS_ONLY) 
        

