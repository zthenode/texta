///////////////////////////////////////////////////////////////////////
//   File: cevcontextedevcpservlet.hpp
//
// Author: $author$
//   Date: 10/4/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCONTEXTEDEVCPSERVLET_HPP
#define _CEVCONTEXTEDEVCPSERVLET_HPP

#include "cevcpservlet.hpp"

#define DEFAULT_CEVCONTEXTEDEVCPSERVLET_NAME "CONTEXTED"

///////////////////////////////////////////////////////////////////////
//  Class: CEvContextedEvcpServlet
//
// Author: $author$
//   Date: 10/4/2007
///////////////////////////////////////////////////////////////////////
class CEvContextedEvcpServlet
: public CEvcpServlet
{
public:
    typedef CEvcpServlet CExtends;
    typedef CEvContextedEvcpServlet CDerives;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvContextedEvcpServlet
    //
    //       Author: $author$
    //         Date: 10/4/2007
    ///////////////////////////////////////////////////////////////////////
    CEvContextedEvcpServlet
    (const char* name=DEFAULT_CEVCONTEXTEDEVCPSERVLET_NAME,
     LONG length=-1) 
    : CExtends(name, length)
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Service
    //
    //   Author: $author$
    //     Date: 10/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Service
    (EvcpServletRequest& request,
     EvcpServletResponse& response) 
    {
        EvError error = EV_ERROR_NONE;
        EvcpStatus status = EVCP_STATUS_INTERNAL_SERVER_ERROR;
        EvcpServletConnection& connection = response.GetEvcpConnection();
        EvcpServlet* context;

        DBF("() in...\n");

        SetKeepAlive(request, response);

        if ((context = GetEvcpServletContext(connection)))
            error = context->Service(request, response);
        else RespondStatus(response, status);

        DBF("() ...out\n");
        return error;
    }
};

#endif // _CEVCONTEXTEDEVCPSERVLET_HPP
