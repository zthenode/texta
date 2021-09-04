/**
 **********************************************************************
 * Copyright (c) 1988-2008 $organization$
 *
 * This software is provided by the author and contributors ``as is'' 
 * and any express or implied warranties, including, but not limited to, 
 * the implied warranties of merchantability and fitness for a particular 
 * purpose are disclaimed. In no event shall the author or contributors 
 * be liable for any direct, indirect, incidental, special, exemplary, 
 * or consequential damages (including, but not limited to, procurement 
 * of substitute goods or services; loss of use, data, or profits; or 
 * business interruption) however caused and on any theory of liability, 
 * whether in contract, strict liability, or tort (including negligence 
 * or otherwise) arising in any way out of the use of this software, 
 * even if advised of the possibility of such damage.
 *
 *   File: cservletsocketqueueserver.hxx
 *
 * Author: $author$
 *   Date: 2/26/2008
 **********************************************************************
 */
#ifndef _CSERVLETSOCKETQUEUESERVER_HXX
#define _CSERVLETSOCKETQUEUESERVER_HXX

#include "csocketqueueserver.hxx"
#include "cservletserver.hxx"
#include "cservletservice.hxx"
#include "cservletconnector.hxx"
#include "cservletconnection.hxx"
#include "cservletrequest.hxx"
#include "cservletresponse.hxx"
#include "cbinarytextprotocolservlet.hxx"
#include "cservlet.hxx"
#include "cdebug.h"

/**
 **********************************************************************
 *  Class: cServletSocketQueueServer
 *
 * Author: $author$
 *   Date: 2/26/2008
 **********************************************************************
 */
class cServletSocketQueueServer
: public cSocketQueueServer
{
public:
    typedef cSocketQueueServer cExtends;
    typedef cServletSocketQueueServer cDerives;

    cServletServer m_server;
    cServletService m_service;
    cServletConnector m_connector;
    cServletConnection m_connection;
    cServletRequest m_request;
    cServletResponse m_response;
    cBinaryTextProtocolServlet m_acquireServlet;
    cServletInterface* m_servlet;

    /**
     **********************************************************************
     * Constructor: cServletSocketQueueServer
     *
     *      Author: $author$
     *        Date: 2/26/2008
     **********************************************************************
     */
    cServletSocketQueueServer()
    : m_servlet(0) 
    {
    }
    /**
     **********************************************************************
     * Destructor: cServletSocketQueueServer
     *
     *     Author: $author$
     *       Date: 2/26/2008
     **********************************************************************
     */
    virtual ~cServletSocketQueueServer()
    {
    }
    /**
     **********************************************************************
     * Function: Service
     *
     *   Author: $author$
     *     Date: 2/17/2008
     **********************************************************************
     */
    virtual eError Service
    (cSocketReference& request,
     cQueuedSocketServer& queueServer) 
    {
        cSocket& sock = *request;
        eError error = e_ERROR_NONE;
        eError error2;
        if (m_servlet)
        {
            cReaderInterface* reader = m_request.GetReader(error2);
            if (!(error2 = m_request.SetReader(&sock)))
            {
                error = m_servlet->Service(m_request, m_response);
                m_request.SetReader(reader);
            }
        }
        if ((error2 = sock.Close(true)))
            DBE("() failed to close socket\n");
        return error;
    }
    /**
     **********************************************************************
     * Function: AcceptRequests
     *
     *   Author: $author$
     *     Date: 2/28/2008
     **********************************************************************
     */
    virtual eError AcceptRequests
    (LONG waitMilliSeconds=INFINITE) 
    {
        eError error = e_ERROR_NONE;
        eError error2;
        if (!(m_servlet = AcquireServlet(error2)))
        {
            DBE("() failed to acquire servlet\n");
            return error2;
        }
        error = cExtends::AcceptRequests(waitMilliSeconds);
        if ((error2 = ReleaseServlet(*m_servlet)))
        {
            DBE("() failed to release servlet\n");
            if (!error)
                error = error2;
        }
        return error;
    }

    /**
     **********************************************************************
     * Function: InitializeExtends
     *
     *   Author: $author$
     *     Date: 2/19/2008
     **********************************************************************
     */
    virtual eError InitializeExtends
    (cSocketQueueServer& extends) 
    {
        eError error = e_ERROR_FAILED;
        eError error2;
        if (!(error2 = m_server.AddService(m_service)))
        if (!(error2 = m_service.AddConnector(m_connector)))
        if (!(error2 = m_connector.SetConnection(&m_connection)))
        if (!(error2 = m_request.SetConnection(&m_connection)))
        if (!(error2 = m_response.SetConnection(&m_connection)))
            error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: FinalizeExtends
     *
     *   Author: $author$
     *     Date: 2/19/2008
     **********************************************************************
     */
    virtual eError FinalizeExtends
    (cSocketQueueServer& extends) 
    {
        eError error = e_ERROR_NONE;
        return error;
    }

    /**
     **********************************************************************
     * Function: AcquireServlet
     *
     *   Author: $author$
     *     Date: 2/28/2008
     **********************************************************************
     */
    virtual cServletInterface* 
    AcquireServlet(eError& error) 
    {
        m_servlet = &m_acquireServlet;
        error = e_ERROR_NONE;
        return m_servlet;
    }
    /**
     **********************************************************************
     * Function: ReleaseServlet
     *
     *   Author: $author$
     *     Date: 2/28/2008
     **********************************************************************
     */
    virtual eError ReleaseServlet
    (cServletInterface& servlet) 
    {
        eError error = e_ERROR_NONE;
        if (&servlet != m_servlet)
            error = e_ERROR_NOT_ACQUIRED;
        else m_servlet = 0;
        return error;
    }
};
#endif /* _CSERVLETSOCKETQUEUESERVER_HXX */
