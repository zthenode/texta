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
 *   File: csocketqueueserver.hxx
 *
 * Author: $author$
 *   Date: 2/21/2008
 **********************************************************************
 */
#ifndef _CSOCKETQUEUESERVER_HXX
#define _CSOCKETQUEUESERVER_HXX

#include "crequestqueueserver.hxx"
#include "cqueuedrequestserver.hxx"
#include "csocketreferencequeue.hxx"
#include "cqueue.hxx"
#include "csocket.hxx"
#include "csockets.hxx"

#define DEFAULT_SOCKET_SERVER_PORT 8008

/**
 **********************************************************************
 *  Class: cQueuedSocketServer
 *
 * Author: $author$
 *   Date: 2/19/2008
 **********************************************************************
 */
class cQueuedSocketServer
: public cQueuedRequestServerT
  <cSocketReference, cQueuedSocketServer, cBase>
{
public:
    typedef cQueuedRequestServerT
    <cSocketReference, cQueuedSocketServer, cBase> cExtends;
    typedef cQueuedSocketServer cDerives;
};

/**
 **********************************************************************
 *  Class: cSocketQueueServer
 *
 * Author: $author$
 *   Date: 2/19/2008
 **********************************************************************
 */
class cSocketQueueServer
: public cRequestQueueServerT
  <cSocketReference,TLENGTH,cSocketReferenceQueue,cQueuedSocketServer>
{
public:
    typedef cRequestQueueServerT
    <cSocketReference,TLENGTH,cSocketReferenceQueue,cQueuedSocketServer> cExtends;
    typedef cSocketQueueServer cDerives;

    SOCKET_PORT m_socketPort;
    cSocket m_socket;
    cSockets m_sockets;

    /**
     **********************************************************************
     * Constructor: cSocketQueueServer
     *
     *      Author: $author$
     *        Date: 2/19/2008
     **********************************************************************
     */
    cSocketQueueServer
    (SOCKET_PORT socketPort=DEFAULT_SOCKET_SERVER_PORT) 
    : m_socketPort(socketPort)
    {
    }
    /**
     **********************************************************************
     * Destructor: cSocketQueueServer
     *
     *     Author: $author$
     *       Date: 2/19/2008
     **********************************************************************
     */
    virtual ~cSocketQueueServer()
    {
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
        eError error = e_ERROR_NONE;
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
     * Function: Initialize
     *
     *   Author: $author$
     *     Date: 2/19/2008
     **********************************************************************
     */
    virtual eError Initialize() 
    {
        eError error = e_ERROR_FAILED;
        eError error2;
        if ((error2 = m_sockets.Initialize()))
            DBE("() failed to initialize sockets\n");
        else
        if ((error2 = m_socket.Open()))
            DBE("() failed to open socket\n");
        else
        if ((error2 = m_socket.Bind(m_socketPort)))
        {
            DBE("() failed to bind socket\n");
            m_socket.Close(true);
        }
        else
        if ((error2 = m_socket.Listen()))
        {
            DBE("() failed to listen on socket\n");
            m_socket.Close(true);
        }
        else
        if ((error = InitializeExtends(*this)))
            Finalize();
        else
        error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: Finalize
     *
     *   Author: $author$
     *     Date: 2/19/2008
     **********************************************************************
     */
    virtual eError Finalize() 
    {
        eError error = e_ERROR_FAILED;
        eError error1;
        eError error2;
        if ((error1 = FinalizeExtends(*this)))
            error = error1;
        if ((error2 = m_socket.Close()))
            DBE("() failed to close socket\n");
        else
        if ((error2 = m_sockets.Finalize()))
            DBE("() failed to finalize sockets\n");
        else
        error = error1;
        return error;
    }
    /**
     **********************************************************************
     * Function: Accept
     *
     *   Author: $author$
     *     Date: 2/17/2008
     **********************************************************************
     */
    virtual TLENGTH Accept
    (cSocketReference& request, 
     LONG waitMilliSeconds=INFINITE) 
    {
        TLENGTH count = 0;
        eError error = e_ERROR_NONE;
        if ((request = m_socket.Accept(error, true)))
            count = 1;
        else
        if (error)
            count = -e_ERROR_FAILED;
        return count;
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
        eError error = e_ERROR_NONE;
        return error;
    }
};

#endif /* _CSOCKETQUEUESERVER_HXX */
