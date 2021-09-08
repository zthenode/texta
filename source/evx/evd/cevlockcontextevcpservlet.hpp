///////////////////////////////////////////////////////////////////////
//   File: cevlockcontextevcpservlet.hpp
//
// Author: $author$
//   Date: 10/9/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVLOCKCONTEXTEVCPSERVLET_HPP
#define _CEVLOCKCONTEXTEVCPSERVLET_HPP

#include "cevcsarchivecontextevcpservlet.hpp"

#define DEFAULT_CEVLOCKCONTEXTEVCPSERVLET_NAME "LOCK_CONTEXT"

///////////////////////////////////////////////////////////////////////
//  Class: CEvLockContextEvcpServlet
//
// Author: $author$
//   Date: 10/9/2007
///////////////////////////////////////////////////////////////////////
class CEvLockContextEvcpServlet
: public CEvcsArchiveContextEvcpServlet
{
public:
    typedef CEvcsArchiveContextEvcpServlet CExtends;
    typedef CEvLockContextEvcpServlet CDerives;

    typedef EvError (CDerives::*MService)
    (EvcpServletRequest& request,
     EvcpServletResponse& response,
     const char* evcsPath);

    MService m_service;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvLockContextEvcpServlet
    //
    //       Author: $author$
    //         Date: 10/9/2007
    ///////////////////////////////////////////////////////////////////////
    CEvLockContextEvcpServlet
    (bool unlock=false,
     const char* name=DEFAULT_CEVLOCKCONTEXTEVCPSERVLET_NAME,
     LONG length=-1) 
    : CExtends(name, length),
      m_service
      (unlock
       ?&CDerives::ServiceUnlock
       :&CDerives::ServiceLock)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvLockContextEvcpServlet
    //
    //      Author: $author$
    //        Date: 10/9/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvLockContextEvcpServlet()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: ConnectionInitialize
    //
    //   Author: $author$
    //     Date: 10/9/2007
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
    //     Date: 10/9/2007
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
    //     Date: 10/9/2007
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
    //     Date: 10/9/2007
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
    //     Date: 10/9/2007
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

#endif // _CEVLOCKCONTEXTEVCPSERVLET_HPP
