///////////////////////////////////////////////////////////////////////
//   File: cevevcpcontextevcpservlet.hpp
//
// Author: $author$
//   Date: 10/13/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVEVCPCONTEXTEVCPSERVLET_HPP
#define _CEVEVCPCONTEXTEVCPSERVLET_HPP

#include "cevevcpcontextservlet.hpp"
#include "cevloginevcpservlet.hpp"

#define DEFAULT_CEVEVCPCONTEXTEVCPSERVLET_NAME "EVCP_CONTEXT"

///////////////////////////////////////////////////////////////////////
//  Class: CEvEvcpContextEvcpServlet
//
// Author: $author$
//   Date: 10/13/2007
///////////////////////////////////////////////////////////////////////
class CEvEvcpContextEvcpServlet
: public CEvEvcpContextServlet
{
public:
    typedef CEvEvcpContextServlet CExtends;
    typedef CEvEvcpContextEvcpServlet CDerives;

    typedef EvError (CDerives::*MService)
    (EvcpServletRequest& request,
     EvcpServletResponse& response);

    CEvcpServlets& m_actionServlets;

    MService m_service;

    CEvString m_loginServletName;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvEvcpContextEvcpServlet
    //
    //       Author: $author$
    //         Date: 10/13/2007
    ///////////////////////////////////////////////////////////////////////
    CEvEvcpContextEvcpServlet
    (CEvcpServlets& actionServlets,
     const char* name=DEFAULT_CEVEVCPCONTEXTEVCPSERVLET_NAME,
     LONG length=-1) 
    : CExtends(name, length),
      m_actionServlets(actionServlets),
      m_service(0),
      m_loginServletName(DEFAULT_CEVLOGINEVCPSERVLET_NAME)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvEvcpContextEvcpServlet
    //
    //      Author: $author$
    //        Date: 10/13/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvEvcpContextEvcpServlet()
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
        if (!(error = CExtends::ConnectionInitialize(connection)))
            m_service = &CDerives::ServiceLogin;
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
        m_service = &CDerives::ServiceLogin;
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
        EvcpStatus status = EVCP_STATUS_INTERNAL_SERVER_ERROR;
        EvcpHeader& reqHeader = request.GetHeader();
        EvcpHeaderHeading& reqHeading = reqHeader.GetHeading();
        const char* actionChars;
        LONG actionLength;
        int unequal;

        DBF("() in...\n");

        if (!(actionChars = reqHeading.
            GetRequestAction(actionLength))
            || (0 >= actionLength))
        {
            DBE("() null action\n");
            RespondStatus(response, status);
        }
        else
        if ((unequal = m_loginServletName.Compare
            (actionChars, actionLength)))
        {
            DBE("() invalid action \"%s\"\n", actionChars);
            RespondStatus(response, status);
        }
        else
        error = ServiceActionNamed
        (request, response, actionChars, true);        

        DBF("() ...out\n");
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ServiceAction
    //
    //   Author: $author$
    //     Date: 10/13/2007
    ///////////////////////////////////////////////////////////////////////
    EvError ServiceAction
    (EvcpServletRequest& request,
     EvcpServletResponse& response) 
    {
        EvError error = EV_ERROR_NONE;
        EvcpStatus status = EVCP_STATUS_INTERNAL_SERVER_ERROR;
        EvcpHeader& reqHeader = request.GetHeader();
        EvcpHeaderHeading& reqHeading = reqHeader.GetHeading();
        const char* actionChars;
        LONG actionLength;

        DBF("() in...\n");
        
        if (!(actionChars = reqHeading.
            GetRequestAction(actionLength))
            || (0 >= actionLength))
        {
            DBE("() null action\n");
            RespondStatus(response, status);
        }
        else
        error = ServiceActionNamed
        (request, response, actionChars);        
        
        DBF("() ...out\n");
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ServiceActionNamed
    //
    //   Author: $author$
    //     Date: 10/13/2007
    ///////////////////////////////////////////////////////////////////////
    EvError ServiceActionNamed
    (EvcpServletRequest& request,
     EvcpServletResponse& response,
     const char* actionChars,
     bool isLogin=false) 
    {
        EvError error = EV_ERROR_NONE;
        EvError error2 = EV_ERROR_NONE;
        EvcpStatus status = EVCP_STATUS_INTERNAL_SERVER_ERROR;
        EvcpServlet* actionServlet;

        DBF("() in...\n");
        
        if ((actionServlet = m_actionServlets.
            FindServlet(actionChars)))
        {
            if ((error2 = actionServlet->Service
                (request, response)) && !isLogin)
                DBE("() servlet \"%s\" failed \n", actionChars);
            else if (isLogin)
                    m_service = &CDerives::ServiceAction;
        }
        else DBE("() unable to find servlet \"%s\"\n", actionChars);

        if (error2)
            RespondStatus(response, status);
        
        DBF("() ...out\n");
        return error;
    }
};

#endif // _CEVEVCPCONTEXTEVCPSERVLET_HPP
