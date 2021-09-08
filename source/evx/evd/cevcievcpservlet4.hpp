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

#include "cevcpservlet.hpp"
#include "cevcicontextevcpservlet.hpp"

#define DEFAULT_CEVCIEVCPSERVLET_NAME "CI"

///////////////////////////////////////////////////////////////////////
//  Class: CEvCiEvcpServlet
//
// Author: $author$
//   Date: 9/21/2007
///////////////////////////////////////////////////////////////////////
class CEvCiEvcpServlet
: public CEvcpServlet
{
public:
    typedef CEvcpServlet CExtends;
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
    // Destructor: ~CEvCiEvcpServlet
    //
    //      Author: $author$
    //        Date: 9/21/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvCiEvcpServlet()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Service
    //
    //   Author: $author$
    //     Date: 9/21/2007
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
    //     Date: 9/21/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvcpServlet* NewEvcpServletContext
    (EvcpServletConnection& connection) 
    {
        EvcpServlet* context = 0;
        const char* chars;
        LONG length;

        if ((chars = GetName(length)))
            context = new CEvCiContextEvcpServlet(chars, length);
        return context;
    }
};

#endif // _CEVCIEVCPSERVLET_HPP
