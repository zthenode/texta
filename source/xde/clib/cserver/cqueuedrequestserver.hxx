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
 *   File: cqueuedrequestserver.hxx
 *
 * Author: $author$
 *   Date: 2/17/2008
 **********************************************************************
 */
#ifndef _CQUEUEDREQUESTSERVER_HXX
#define _CQUEUEDREQUESTSERVER_HXX

#include "cqueuedrequestserverbase.hxx"
#include "cqueue.hxx"
#include "cbase.hxx"
#include "cdebug.h"

#undef CDB_CLASS
#define CDB_CLASS "cQueuedRequestServerT"
/**
 **********************************************************************
 *  Class: cQueuedRequestServerT
 *
 * Author: $author$
 *   Date: 2/17/2008
 **********************************************************************
 */
template
<class TRequest=CHAR,
 class TServer=cQueuedRequestServerBase,
 class TExtends=cQueuedRequestServerBase>
 
class cQueuedRequestServerT
: public TExtends
{
public:
    typedef TExtends cExtends;
    typedef cQueuedRequestServerT cDerives;

    TServer* m_queueServer;

    /**
     **********************************************************************
     * Constructor: cQueuedRequestServerT
     *
     *      Author: $author$
     *        Date: 2/17/2008
     **********************************************************************
     */
    cQueuedRequestServerT
    (TServer* queueServer=0) 
    : m_queueServer(queueServer)
    {
    }
    /**
     **********************************************************************
     * Destructor: cQueuedRequestServerT
     *
     *     Author: $author$
     *       Date: 2/17/2008
     **********************************************************************
     */
    virtual ~cQueuedRequestServerT()
    {
    }

    /**
     **********************************************************************
     * Function: Create
     *
     *   Author: $author$
     *     Date: 2/18/2008
     **********************************************************************
     */
    virtual eError Create
    (TServer& queueServer) 
    {
        eError error = e_ERROR_NONE;
		m_queueServer = &queueServer;
        return error;
    }
    /**
     **********************************************************************
     * Function: Destroy
     *
     *   Author: $author$
     *     Date: 2/18/2008
     **********************************************************************
     */
    virtual eError Destroy
    (TServer& queueServer) 
    {
        eError error = e_ERROR_NONE;
		m_queueServer = 0;
        return error;
    }

    /**
     **********************************************************************
     * Function: Run
     *
     *   Author: $author$
     *     Date: 2/17/2008
     **********************************************************************
     */
    virtual eError Run
    (TServer& requestServer) 
    {
        eError error = e_ERROR_NONE;
        return error;
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
    (TRequest& request,
     TServer& queueServer) 
    {
        eError error = e_ERROR_NONE;
        return error;
    }

    /**
     **********************************************************************
     * Function: Restart
     *
     *   Author: $author$
     *     Date: 2/17/2008
     **********************************************************************
     */
    virtual eError Restart() 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: Stop
     *
     *   Author: $author$
     *     Date: 2/17/2008
     **********************************************************************
     */
    virtual eError Stop() 
    {
        eError error = e_ERROR_NONE;
        return error;
    }

    /**
     **********************************************************************
     * Function: Acquire
     *
     *   Author: $author$
     *     Date: 2/18/2008
     **********************************************************************
     */
    virtual eError Acquire
    (LONG waitMilliSeconds=INFINITE) 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: Release
     *
     *   Author: $author$
     *     Date: 2/18/2008
     **********************************************************************
     */
    virtual eError Release() 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Typedef: cQueuedRequestServer
 *
 *  Author: $author$
 *    Date: 2/18/2008
 **********************************************************************
 */
typedef cQueuedRequestServerT
<CHAR, cQueuedRequestServerBase, cQueuedRequestServerBase>
cQueuedRequestServer;

#endif /* _CQUEUEDREQUESTSERVER_HXX */
