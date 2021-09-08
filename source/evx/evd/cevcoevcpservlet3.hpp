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

#include "cevcpservlet.hpp"
#include "cevcocontextevcpservlet.hpp"

#define DEFAULT_CEVCOEVCPSERVLET_NAME "CO"

///////////////////////////////////////////////////////////////////////
//  Class: CEvCoEvcpServlet
//
// Author: $author$
//   Date: 9/19/2007
///////////////////////////////////////////////////////////////////////
class CEvCoEvcpServlet
: public CEvcpServlet
{
public:
    typedef CEvcpServlet CExtends;
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
    // Destructor: ~CEvCoEvcpServlet
    //
    //      Author: $author$
    //        Date: 9/19/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvCoEvcpServlet()
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

    ///////////////////////////////////////////////////////////////////////
    // Function: Service
    //
    //   Author: $author$
    //     Date: 9/19/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Service
    (EvcpServletRequest& request,
     EvcpServletResponse& response) 
    {
        EvcpStatus status = EVCP_STATUS_INTERNAL_SERVER_ERROR;
        EvError error = EV_ERROR_NONE;
        EvcpServletConnection& connection = response.GetEvcpConnection();
        EvcpServlet* context;

        DBF("() in...\n");

        if ((context = GetEvcpServletContext(connection)))
            error = context->Service(request, response);
        else
        {
		    SetKeepAlive(request, response);
            RespondStatus(response, status);
        }
        DBF("() ...out\n");
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: NewEvcpServletContext
    //
    //   Author: $author$
    //     Date: 9/20/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvcpServlet* NewEvcpServletContext
    (EvcpServletConnection& connection) 
    {
        EvcpServlet* context = 0;
        const char* chars;
        LONG length;

        if ((chars = GetName(length)))
            context = new CEvCoContextEvcpServlet(chars, length);
        return context;
    }
};

#endif // _CEVCOEVCPSERVLET_HPP
