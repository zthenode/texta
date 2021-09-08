///////////////////////////////////////////////////////////////////////
//   File: cevloginevcpservlet.hpp
//
// Author: $author$
//   Date: 10/13/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVLOGINEVCPSERVLET_HPP
#define _CEVLOGINEVCPSERVLET_HPP

#include "cevcpservlet.hpp"

#define DEFAULT_CEVLOGINEVCPSERVLET_NAME "LOGIN"

///////////////////////////////////////////////////////////////////////
//  Class: CEvLoginEvcpServlet
//
// Author: $author$
//   Date: 10/13/2007
///////////////////////////////////////////////////////////////////////
class CEvLoginEvcpServlet
: public CEvcpServlet
{
public:
    typedef CEvcpServlet CExtends;
    typedef CEvLoginEvcpServlet CDerives;

    typedef EvError (CDerives::*MService)
    (EvcpServletRequest& request,
     EvcpServletResponse& response);

    MService m_service;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvLoginEvcpServlet
    //
    //       Author: $author$
    //         Date: 10/13/2007
    ///////////////////////////////////////////////////////////////////////
    CEvLoginEvcpServlet
    (const char* name=DEFAULT_CEVLOGINEVCPSERVLET_NAME,
     LONG length=-1) 
    : CExtends(name, length),
      m_service(0)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvLoginEvcpServlet
    //
    //      Author: $author$
    //        Date: 10/13/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvLoginEvcpServlet()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Initialize
    //
    //   Author: $author$
    //     Date: 10/13/2007
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
    //     Date: 10/13/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Finalize(EvServletServer& server) 
    {
        EvError error = EV_ERROR_NONE;
        DBF("() in...\n");
        DBF("() ...out\n");
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: ConnectionInitialize
    //
    //   Author: $author$
    //     Date: 12/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ConnectionInitialize
    (EvcpServletConnection& connection) 
    {
        EvError error = EV_ERROR_NONE;
        DBF("() in...\n");
        //error = CExtends::ConnectionInitialize(connection);
        m_service = &CDerives::ServiceLogin;
        DBF("() ...out\n");
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ConnectionFinalize
    //
    //   Author: $author$
    //     Date: 12/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ConnectionFinalize
    (EvcpServletConnection& connection) 
    {
        EvError error = EV_ERROR_NONE;
        DBF("() in...\n");
        //error = CExtends::ConnectionFinalize(connection);
        m_service = 0;
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

    ///////////////////////////////////////////////////////////////////////
    // Function: ServiceLogin
    //
    //   Author: $author$
    //     Date: 10/13/2007
    ///////////////////////////////////////////////////////////////////////
    EvError ServiceLogin
    (EvcpServletRequest& request,
     EvcpServletResponse& response) 
    {
        EvError error = EV_ERROR_NONE;
        EvcpStatus status = EVCP_STATUS_OK;

        DBF("() in...\n");
        RespondStatus(response, status);
        m_service = &CDerives::ServiceLogout;
        DBF("() ...out\n");
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ServiceLogout
    //
    //   Author: $author$
    //     Date: 10/13/2007
    ///////////////////////////////////////////////////////////////////////
    EvError ServiceLogout
    (EvcpServletRequest& request,
     EvcpServletResponse& response) 
    {
        EvError error = EV_ERROR_NONE;
        EvcpStatus status = EVCP_STATUS_OK;

        DBF("() in...\n");
        RespondStatus(response, status);
        m_service = &CDerives::ServiceLogin;
        DBF("() ...out\n");
        return error;
    }
};

#endif // _CEVLOGINEVCPSERVLET_HPP
