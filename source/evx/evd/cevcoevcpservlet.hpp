///////////////////////////////////////////////////////////////////////
//   File: cevcoevcpservlet.hpp
//
// Author: $author$
//   Date: 9/19/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCOEVCPSERVLET_HPP
#define _CEVCOEVCPSERVLET_HPP

#include "cevgetevcpservlet.hpp"

#define DEFAULT_CEVCOEVCPSERVLET_NAME "CO"

///////////////////////////////////////////////////////////////////////
//  Class: CEvCoEvcpServlet
//
// Author: $author$
//   Date: 9/19/2007
///////////////////////////////////////////////////////////////////////
class CEvCoEvcpServlet
: public CEvGetEvcpServlet
{
public:
    typedef CEvGetEvcpServlet CExtends;
    typedef CEvCoEvcpServlet CDerives;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvCoEvcpServlet
    //
    //       Author: $author$
    //         Date: 9/19/2007
    ///////////////////////////////////////////////////////////////////////
    CEvCoEvcpServlet
    (const char* name=DEFAULT_CEVCOEVCPSERVLET_NAME,
     LONG length=-1) 
    : CExtends(name, length)
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Initialize
    //
    //   Author: $author$
    //     Date: 9/19/2007
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
    //     Date: 9/19/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Finalize(EvServletServer& server) 
    {
        EvError error = EV_ERROR_NONE;
        DBF("() in...\n");
        DBF("() ...out\n");
        return error;
    }
};

#endif // _CEVCOEVCPSERVLET_HPP
