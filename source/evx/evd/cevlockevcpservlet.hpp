///////////////////////////////////////////////////////////////////////
//   File: cevlockevcpservlet.hpp
//
// Author: $author$
//   Date: 12/26/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVLOCKEVCPSERVLET_HPP
#define _CEVLOCKEVCPSERVLET_HPP

#include "cevcsarchiveservlet.hpp"

#define DEFAULT_CEVLOCKEVCPSERVLET_NAME "LOCK"

///////////////////////////////////////////////////////////////////////
//  Class: CEvLockEvcpServlet
//
// Author: $author$
//   Date: 12/26/2007
///////////////////////////////////////////////////////////////////////
class CEvLockEvcpServlet
: public CEvcsArchiveServlet
{
public:
    typedef CEvcsArchiveServlet CExtends;
    typedef CEvLockEvcpServlet CDerives;
    
    typedef EvError (CDerives::*MService)
    (EvcpServletRequest& request,
     EvcpServletResponse& response,
     const char* evcsPath);

    MService m_service;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvLockEvcpServlet
    //
    //       Author: $author$
    //         Date: 12/26/2007
    ///////////////////////////////////////////////////////////////////////
    CEvLockEvcpServlet
    (bool unlock=false,
     const char* name=DEFAULT_CEVLOCKEVCPSERVLET_NAME,
     LONG length=-1) 
    : CExtends(name, length),
      m_service
      (unlock
       ?&CDerives::ServiceUnlock
       :&CDerives::ServiceLock) 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvLockEvcpServlet
    //
    //      Author: $author$
    //        Date: 12/26/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvLockEvcpServlet()
    {
    }
    
    ///////////////////////////////////////////////////////////////////////
    // Function: Initialize
    //
    //   Author: $author$
    //     Date: 12/26/2007
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
    //     Date: 12/26/2007
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
    //     Date: 12/26/2007
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
    //     Date: 12/26/2007
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
    //     Date: 12/26/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Service
    (EvcpServletRequest& request,
     EvcpServletResponse& response) 
    {
        EvError error = EV_ERROR_NONE;
        EvcpStatus status = EVCP_STATUS_INTERNAL_SERVER_ERROR;
        EvcpHeader& reqHeader = request.GetHeader();
        EvcpHeaderHeading& reqHeading = reqHeader.GetHeading();
        const char* chars;
        LONG length;

        DBF("() in...\n");

        if (!(chars = reqHeading.
            GetRequestPath(length)) || (0 >= length))
            DBE("() missing or invalid request path\n");

        else
        if (m_service)
            error = (this->*m_service)
            (request, response, chars);

        else         
        RespondStatus(response, status);

        DBF("() ...out\n");
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: ServiceLock
    //
    //   Author: $author$
    //     Date: 12/26/2007
    ///////////////////////////////////////////////////////////////////////
    EvError ServiceLock
    (EvcpServletRequest& request,
     EvcpServletResponse& response,
     const char* evcsPath) 
    {
        EvError error = EV_ERROR_NONE;
        EvcpStatus status = EVCP_STATUS_INTERNAL_SERVER_ERROR;
        bool isExclusive = false;
        bool isDefered = false;
        EvError error2;

        DBF("() in...\n");

        if (!(error2 = m_archive->LockEntry
            (m_entry, evcsPath, isExclusive, isDefered)))
            status = EVCP_STATUS_OK;

        RespondStatus(response, status);
        DBF("() ...out\n");
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ServiceUnlock
    //
    //   Author: $author$
    //     Date: 12/26/2007
    ///////////////////////////////////////////////////////////////////////
    EvError ServiceUnlock
    (EvcpServletRequest& request,
     EvcpServletResponse& response,
     const char* evcsPath) 
    {
        EvError error = EV_ERROR_NONE;
        EvcpStatus status = EVCP_STATUS_INTERNAL_SERVER_ERROR;
        EvError error2;

        DBF("() in...\n");

        if (!(error2 = m_archive->UnlockEntry
            (m_entry, evcsPath)))
            status = EVCP_STATUS_OK;

        RespondStatus(response, status);
        DBF("() ...out\n");
        return error;
    }
};

#endif // _CEVLOCKEVCPSERVLET_HPP
