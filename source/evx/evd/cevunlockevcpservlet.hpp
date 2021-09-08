///////////////////////////////////////////////////////////////////////
//   File: cevunlockevcpservlet.hpp
//
// Author: $author$
//   Date: 10/9/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVUNLOCKEVCPSERVLET_HPP
#define _CEVUNLOCKEVCPSERVLET_HPP

#include "cevlockevcpservlet.hpp"

#define DEFAULT_CEVUNLOCKEVCPSERVLET_NAME "UNLOCK"

///////////////////////////////////////////////////////////////////////
//  Class: CEvUnlockEvcpServlet
//
// Author: $author$
//   Date: 10/9/2007
///////////////////////////////////////////////////////////////////////
class CEvUnlockEvcpServlet
: public CEvLockEvcpServlet
{
public:
    typedef CEvLockEvcpServlet CExtends;
    typedef CEvUnlockEvcpServlet CDerives;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvUnlockEvcpServlet
    //
    //       Author: $author$
    //         Date: 10/9/2007
    ///////////////////////////////////////////////////////////////////////
    CEvUnlockEvcpServlet
    (const char* name=DEFAULT_CEVUNLOCKEVCPSERVLET_NAME,
     LONG length=-1) 
    : CExtends(true, name, length)
    {
    }
};

#endif // _CEVUNLOCKEVCPSERVLET_HPP

