///////////////////////////////////////////////////////////////////////
//   File: cevcievcpservlet.hpp
//
// Author: $author$
//   Date: 9/21/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCIEVCPSERVLET_HPP
#define _CEVCIEVCPSERVLET_HPP

#include "cevputevcpservlet.hpp"

#define DEFAULT_CEVCIEVCPSERVLET_NAME "CI"

///////////////////////////////////////////////////////////////////////
//  Class: CEvCiEvcpServlet
//
// Author: $author$
//   Date: 9/21/2007
///////////////////////////////////////////////////////////////////////
class CEvCiEvcpServlet
: public CEvPutEvcpServlet
{
public:
    typedef CEvPutEvcpServlet CExtends;
    typedef CEvCiEvcpServlet CDerives;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvCiEvcpServlet
    //
    //       Author: $author$
    //         Date: 9/21/2007
    ///////////////////////////////////////////////////////////////////////
    CEvCiEvcpServlet
    (const char* name=DEFAULT_CEVCIEVCPSERVLET_NAME,
     LONG length=-1) 
    : CExtends(name, length)
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Initialize
    //
    //   Author: $author$
    //     Date: 10/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Initialize(EvServletServer& server) 
    {
        EvError error = EV_ERROR_NONE;
        DBF("() in...\n");
        DBF("() ...out\n");
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Finalize
    //
    //   Author: $author$
    //     Date: 10/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Finalize(EvServletServer& server) 
    {
        EvError error = EV_ERROR_NONE;
        DBF("() in...\n");
        DBF("() ...out\n");
        return error;
    }
};

#endif // _CEVCIEVCPSERVLET_HPP
