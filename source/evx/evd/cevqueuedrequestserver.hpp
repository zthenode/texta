///////////////////////////////////////////////////////////////////////
//   File: cevqueuedrequestserver.hpp
//
// Author: $author$
//   Date: 4/5/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVQUEUEDREQUESTSERVER_HPP
#define _CEVQUEUEDREQUESTSERVER_HPP

#include "cevbase.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvQueuedRequestServer
//
// Author: $author$
//   Date: 4/5/2007
///////////////////////////////////////////////////////////////////////
template
<class TServer,
 class TRequest,
 class TBase=CEvBase>

class CEvQueuedRequestServer
: public TBase
{
public:
    typedef TBase CExtends;
    typedef CEvQueuedRequestServer CDerives;
    typedef TServer CEvServer;
    typedef TRequest CEvRequest;

	TServer* m_queueServer;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvQueuedRequestServer
    //
    //       Author: $author$
    //         Date: 4/5/2007
    ///////////////////////////////////////////////////////////////////////
    CEvQueuedRequestServer
    (TServer* queueServer=0) 
    : m_queueServer(queueServer)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvQueuedRequestServer
    //
    //      Author: $author$
    //        Date: 4/5/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvQueuedRequestServer()
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Create
    //
    //   Author: $author$
    //     Date: 4/5/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Create
    (TServer& queueServer) 
    {
        EvError error = EV_ERROR_NONE;
		m_queueServer = &queueServer;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Destroy
    //
    //   Author: $author$
    //     Date: 4/5/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Destroy
    (TServer& queueServer) 
    {
        EvError error = EV_ERROR_NONE;
		m_queueServer = 0;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Run
    //
    //   Author: $author$
    //     Date: 4/5/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Run
    (TServer& requestServer) 
    {
        EvError error = EV_ERROR_FAILED;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Service
    //
    //   Author: $author$
    //     Date: 4/5/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Service
    (TRequest& request,
     TServer& queueServer) 
    {
        EvError error = EV_ERROR_FAILED;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: End
    //
    //   Author: $author$
    //     Date: 4/5/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError End() 
    {
        EvError error = EV_ERROR_FAILED;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Restart
    //
    //   Author: $author$
    //     Date: 8/5/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Restart() 
    {
        EvError error = EV_ERROR_FAILED;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Stop
    //
    //   Author: $author$
    //     Date: 5/12/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Stop() 
    {
        EvError error = EV_ERROR_NONE;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Aquire
    //
    //   Author: $author$
    //     Date: 4/5/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Aquire
    (LONG waitMilliSeconds=INFINITE) 
    {
        EvError error = EV_ERROR_FAILED;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Release
    //
    //   Author: $author$
    //     Date: 4/5/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Release() 
    {
        EvError error = EV_ERROR_FAILED;
        return error;
    }
};
#endif // _CEVQUEUEDREQUESTSERVER_HPP
