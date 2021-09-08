///////////////////////////////////////////////////////////////////////
//   File: cevhelloevcpservlet.hpp
//
// Author: $author$
//   Date: 8/14/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVHELLOEVCPSERVLET_HPP
#define _CEVHELLOEVCPSERVLET_HPP

#include "cevcpservlet.hpp"
#include "cevcpservlets.hpp"
#include "cevstringwriter.hpp"

#define DEFAULT_CEVHELLOEVCPSERVLET_NAME "HELLO"

///////////////////////////////////////////////////////////////////////
//  Class: CEvHelloEvcpServlet
//
// Author: $author$
//   Date: 8/14/2007
///////////////////////////////////////////////////////////////////////
class CEvHelloEvcpServlet
: public CEvcpServlet
{
public:
    typedef CEvcpServlet CExtends;
    typedef CEvHelloEvcpServlet CDerives;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvHelloEvcpServlet
    //
    //       Author: $author$
    //         Date: 8/14/2007
    ///////////////////////////////////////////////////////////////////////
    CEvHelloEvcpServlet
    (const char* name=DEFAULT_CEVHELLOEVCPSERVLET_NAME,
     LONG length=-1) 
    : CExtends(name, length)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvHelloEvcpServlet
    //
    //      Author: $author$
    //        Date: 8/14/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvHelloEvcpServlet()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Initialize
    //
    //   Author: $author$
    //     Date: 8/14/2007
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
    //     Date: 8/14/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Finalize(EvServletServer& server) 
    {
        EvError error = EV_ERROR_NONE;
        DBF("() in...\n");
        DBF("() ...out\n");
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Service
    //
    //   Author: $author$
    //     Date: 8/14/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Service
    (EvcpServletRequest& request,
     EvcpServletResponse& response) 
    {
        EvError error = EV_ERROR_NONE;
        EvcpStatus status = EVCP_STATUS_OK;

        DBF("() in...\n");
        RespondStatus(response, status);
        DBF("() ...out\n");
        return error;
    }
};

#endif // _CEVHELLOEVCPSERVLET_HPP
