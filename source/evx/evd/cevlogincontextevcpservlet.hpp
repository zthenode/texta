///////////////////////////////////////////////////////////////////////
//   File: cevlogincontextevcpservlet.hpp
//
// Author: $author$
//   Date: 10/13/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVLOGINCONTEXTEVCPSERVLET_HPP
#define _CEVLOGINCONTEXTEVCPSERVLET_HPP

#include "cevcontextevcpservlet.hpp"

#define DEFAULT_CEVLOGINCONTEXTEVCPSERVLET_NAME "LOGIN_CONTEXT"

///////////////////////////////////////////////////////////////////////
//  Class: CEvLoginContextEvcpServlet
//
// Author: $author$
//   Date: 10/13/2007
///////////////////////////////////////////////////////////////////////
class CEvLoginContextEvcpServlet
: public CEvContextEvcpServlet
{
public:
    typedef CEvContextEvcpServlet CExtends;
    typedef CEvLoginContextEvcpServlet CDerives;

    typedef EvError (CDerives::*MService)
    (EvcpServletRequest& request,
     EvcpServletResponse& response);

    MService m_service;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvLoginContextEvcpServlet
    //
    //       Author: $author$
    //         Date: 10/13/2007
    ///////////////////////////////////////////////////////////////////////
    CEvLoginContextEvcpServlet
    (const char* name=DEFAULT_CEVLOGINCONTEXTEVCPSERVLET_NAME,
     LONG length=-1) 
    : CExtends(name, length),
      m_service(0)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvLoginContextEvcpServlet
    //
    //      Author: $author$
    //        Date: 10/13/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvLoginContextEvcpServlet()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: ConnectionInitialize
    //
    //   Author: $author$
    //     Date: 10/13/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ConnectionInitialize
    (EvcpServletConnection& connection) 
    {
        EvError error = EV_ERROR_NONE;
        DBF("() in...\n");
        error = CExtends::ConnectionInitialize(connection);
        DBF("() ...out\n");
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ConnectionFinalize
    //
    //   Author: $author$
    //     Date: 10/13/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ConnectionFinalize
    (EvcpServletConnection& connection) 
    {
        EvError error = EV_ERROR_NONE;
        DBF("() in...\n");
        error = CExtends::ConnectionFinalize(connection);
        DBF("() ...out\n");
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Service
    //
    //   Author: $author$
    //     Date: 10/13/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Service
    (EvcpServletRequest& request,
     EvcpServletResponse& response) 
    {
        EvError error = EV_ERROR_NONE;
        EvcpStatus status = EVCP_STATUS_INTERNAL_SERVER_ERROR;
        EvCharReader& reader = request.GetReader();
        EvcpHeader& reqHeader = request.GetHeader();
        EvcpHeaderHeading& reqHeading = reqHeader.GetHeading();
        EvCharWriter& writer = response.GetWriter();
        EvcpHeader& respHeader = response.GetHeader();
        EvcpHeaderHeading& respHeading = respHeader.GetHeading();
        EvcpServletConnection& connection = response.GetEvcpConnection();

        DBF("() in...\n");
        
        if (m_service)
            error = (this->*m_service)
            (request, response);
            
        else         
        RespondStatus(response, status);
        
        DBF("() ...out\n");
        return error;
    }
};

#endif // _CEVLOGINCONTEXTEVCPSERVLET_HPP
