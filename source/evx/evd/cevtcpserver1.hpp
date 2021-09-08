///////////////////////////////////////////////////////////////////////
//   File: cevtcpserver.hpp
//
// Author: $author$
//   Date: 4/6/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVTCPSERVER_HPP
#define _CEVTCPSERVER_HPP

#include "evservletserver.hpp"
#include "cevtcpservletrequest.hpp"
#include "cevtcpservletresponse.hpp"
#include "cevtcpservletconnection.hpp"
#include "cevtcpservletdll.hpp"
#include "cevqueuedrequestserver.hpp"
#include "cevthreadedqueuedrequestserver.hpp"
#include "cevthread.hpp"
#include "cevsocket.hpp"
#include "evdebug.h"
#include "cevreference.hpp"
#include "cevstring.hpp"
#include "cevproperties.hpp"

#define DEFAULT_CEVTCPSERVER_TCP_NO_DELAY_ON true
#define DEFAULT_CEVTCPSERVER_SOCKET_DONT_LINGER_ON true
#define DEFAULT_CEVTCPSERVER_SOCKET_LINGER 0

///////////////////////////////////////////////////////////////////////
//  Class: CEvTcpServletServer
//
// Author: $author$
//   Date: 4/16/2007
///////////////////////////////////////////////////////////////////////
class CEvTcpServletServer
: virtual public EvTcpServletServer,
  public CEvProperties
{
public:
    typedef EvTcpServletServer CImplements;
    typedef CEvBase CExtends;
    typedef CEvTcpServletServer CDerives;

    ///////////////////////////////////////////////////////////////////////
    // Function: End
    //
    //   Author: $author$
    //     Date: 5/14/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError End() 
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
    // Function: AquireServlet
    //
    //   Author: $author$
    //     Date: 4/16/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvTcpServlet* AquireServlet() 
    {
        EvTcpServlet* servlet = 0;
        return servlet;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ReleaseServlet
    //
    //   Author: $author$
    //     Date: 4/21/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ReleaseServlet
    (EvTcpServlet& servlet) 
    {
        EvError error = EV_ERROR_FAILED;
        return error;
    }
};

///////////////////////////////////////////////////////////////////////
//  Class: CEvQueuedSocketServer
//
// Author: $author$
//   Date: 4/6/2007
///////////////////////////////////////////////////////////////////////
class CEvQueuedSocketServer
: public CEvQueuedRequestServer
  <CEvQueuedSocketServer,
   CEvSocketReference,
   CEvTcpServletServer>
{
public:
    typedef CEvQueuedRequestServer
    <CEvQueuedSocketServer,
     CEvSocketReference,
     CEvTcpServletServer> CExtends;
    typedef CEvQueuedSocketServer CDerives;
};

///////////////////////////////////////////////////////////////////////
//  Class: CEvQueuedSocketThread
//
// Author: $author$
//   Date: 4/6/2007
///////////////////////////////////////////////////////////////////////
class CEvQueuedSocketThread
: public CEvThread<CEvQueuedSocketServer>
{
public:
    typedef CEvThread<CEvQueuedSocketServer> CExtends;
    typedef CEvQueuedSocketThread CDerives;

    EvTcpServlet* m_servlet;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvQueuedSocketThread
    //
    //       Author: $author$
    //         Date: 4/16/2007
    ///////////////////////////////////////////////////////////////////////
    CEvQueuedSocketThread() 
    : m_servlet(0)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvQueuedSocketThread
    //
    //      Author: $author$
    //        Date: 4/16/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvQueuedSocketThread()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Run
    //
    //   Author: $author$
    //     Date: 4/6/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Run() 
    {
        EvError error = EV_ERROR_FAILED;
        EvError error2;

		if (m_queueServer)
        {
            if ((m_servlet = m_queueServer->AquireServlet()))
            {
			    error = m_queueServer->Run(*this);

                if ((error2 = m_queueServer->ReleaseServlet(*m_servlet)))
                {
                    DBE("() failed to release Tcp servlet\n");

                    if (!error)
                        error = error2;
                }

                m_servlet = 0;
            }
            else DBE("() failed to acquire Tcp servlet\n");
        }
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Service
    //
    //   Author: $author$
    //     Date: 4/6/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Service
    (CEvSocketReference& connectionReference,
     CEvServer& queueServer) 
    {
        EvError error = EV_ERROR_FAILED;
        EvError error2;
        CEvSocket* connection;

		DBF("() in...\n");

        if ((connection = connectionReference.m_referenced))
		    error = Process(queueServer, *connection);

		if ((error2 = connectionReference.Close()))
		{
			DBE("() failed to close socket connection\n");
			if (!error)
				error = error2;
		}

		DBF("() ...out\n");
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Process
    //
    //   Author: $author$
    //     Date: 4/6/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Process
    (CEvServer& queueServer, CEvSocket& connection) 
    {
        EvError error = EV_ERROR_NONE;
        CEvTcpServletConnection tcpConnection(queueServer);
        CEvSocketReader reader(connection);
        CEvTcpServletRequest request(tcpConnection, reader);
        CEvSocketWriter writer(connection);
        CEvTcpServletResponse response(tcpConnection, writer);

        if (m_servlet)
        if ((error = m_servlet->Service(request, response)))
            DBE("() failed on servlet service\n");
        return error;
    }
};

///////////////////////////////////////////////////////////////////////
//  Class: CEvThreadedQueuedSocketServer
//
// Author: $author$
//   Date: 4/6/2007
///////////////////////////////////////////////////////////////////////
template
<class TQueuedSocketThread>

class CEvThreadedQueuedSocketServer
: public CEvThreadedQueuedRequestServer
  <TQueuedSocketThread,
   CEvSocketReference,
   CEvQueuedSocketServer>
{
public:
    typedef CEvThreadedQueuedRequestServer
    <TQueuedSocketThread,
     CEvSocketReference,
     CEvQueuedSocketServer> CExtends;
    typedef CEvThreadedQueuedSocketServer CDerives;

    CEvTcpServletServer& m_servletServer;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvThreadedQueuedSocketServer
    //
    //       Author: $author$
    //         Date: 4/16/2007
    ///////////////////////////////////////////////////////////////////////
    CEvThreadedQueuedSocketServer
    (CEvTcpServletServer& servletServer) 
    : m_servletServer(servletServer)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Stop
    //
    //   Author: $author$
    //     Date: 5/12/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Stop() 
    {
        EvError error = m_servletServer.Stop();
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: AquireServlet
    //
    //   Author: $author$
    //     Date: 4/16/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvTcpServlet* AquireServlet() 
    {
        EvTcpServlet* servlet = m_servletServer.AquireServlet();
        return servlet;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ReleaseServlet
    //
    //   Author: $author$
    //     Date: 4/21/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ReleaseServlet
    (EvTcpServlet& servlet) 
    {
        EvError error = m_servletServer.ReleaseServlet(servlet);
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: GetPropertyCharsById
    //
    //   Author: $author$
    //     Date: 7/17/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetPropertyCharsById
    (LONG& length,
     EvProperty::EvId id) const 
    {
        const char* chars = m_servletServer.GetPropertyCharsById(length, id);
        return chars;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetPropertyUnsignedById
    //
    //   Author: $author$
    //     Date: 7/17/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError GetPropertyUnsignedById
    (ULONG& value, EvProperty::EvId id) const 
    {
        EvError error = m_servletServer.GetPropertyUnsignedById(value, id);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetPropertySignedById
    //
    //   Author: $author$
    //     Date: 7/17/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError GetPropertySignedById
    (LONG& value, EvProperty::EvId id) const 
    {
        EvError error = m_servletServer.GetPropertySignedById(value, id);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetPropertyBoolById
    //
    //   Author: $author$
    //     Date: 7/17/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError GetPropertyBoolById
    (bool& value, EvProperty::EvId id) const 
    {
        EvError error = m_servletServer.GetPropertyBoolById(value, id);
        return error;
    }
};

#undef CDB_CLASS
#define CDB_CLASS "CEvTcpServer"
///////////////////////////////////////////////////////////////////////
//  Class: CEvTcpServer
//
// Author: $author$
//   Date: 4/6/2007
///////////////////////////////////////////////////////////////////////
template
<class TQueuedSocketThread>

class CEvTcpServer
: public CEvTcpServletServer
{
public:
    typedef CEvTcpServletServer CExtends;
    typedef CEvTcpServer CDerives;

	CEvSocket m_socket;
	CEvThreadedQueuedSocketServer
	<TQueuedSocketThread> m_requestServer;

    USHORT m_port;
    UINT m_threads;
    bool m_tcpNoDelayOn;
    CEvString m_servletDllFilename;

    CEvTcpServletDll m_servletDll;
	CEvMutex m_servletDllMutex;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvTcpServer
    //
    //       Author: $author$
    //         Date: 4/6/2007
    ///////////////////////////////////////////////////////////////////////
    CEvTcpServer() 
    : m_requestServer(*this),
      m_port(INVALID_SOCKET_PORT),
      m_threads(0),
      m_tcpNoDelayOn(DEFAULT_CEVTCPSERVER_TCP_NO_DELAY_ON)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvTcpServer
    //
    //      Author: $author$
    //        Date: 4/6/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvTcpServer()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Start
    //
    //   Author: $author$
    //     Date: 4/6/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Start
    (USHORT port, UINT threads=1, 
     const char* servletDllFilename=0) 
    {
        EvError error = EV_ERROR_FAILED;

        if (servletDllFilename)
            m_servletDllFilename = servletDllFilename;
        else servletDllFilename = m_servletDllFilename.c_str();

        if ((error = m_servletDll.Open(servletDllFilename)))
            CDBE("() failed to open Dll \"%s\"\n", servletDllFilename);

		if ((error = m_socket.Create()))
		{
			CDBE("() failed to create socket\n");
			return error;
		}

#if defined(WIN32) 
// Windows
        if (GetTcpNoDelayOn())
		if ((error = m_socket.SetNoDelayOpt()))
		{
			CDBE("() failed to set nodelay socketopt\n");
            m_socket.Close();
			return error;
		}
#endif // defined(WIN32)

		if ((error = m_socket.Bind(port)))
		{
			CDBE("() failed to bind socket to port %d\n", port);
			m_socket.Close();
			return error;
		}

		if ((error = m_socket.Listen()))
		{
			CDBE("() failed to listen on socket\n");
			m_socket.Close();
			return error;
		}

		if ((error = m_servletDllMutex.Create()))
		{
			CDBE("() failed to create servlet Dll mutex\n");
			return error;
		}

		if ((error = m_requestServer.Start(threads)))
		{
			CDBE("() failed to start request server\n");
            m_servletDllMutex.Destroy();
			m_socket.Close();
		}

        m_port = port;
        m_threads = threads;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Finish
    //
    //   Author: $author$
    //     Date: 4/6/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Finish() 
    {
        EvError error = EV_ERROR_NONE;
		EvError error2;

		do
		{
			CDBF("() waiting to accept socket connection on %d...\n", m_port);

			CEvSocketReference acceptedSocket;

#if defined(WIN32) 
// Windows
			if ((acceptedSocket = m_socket.
                Accept(error2, GetTcpNoDelayOn())))
#else // defined(WIN32) 
// Unix
			if ((acceptedSocket = m_socket.Accept(error2)))
#endif // defined(WIN32)
			{
				CDBF("() ...accepted socket connection on %d...\n", m_port);

#if !defined(WIN32) 
// Unix
                if (GetTcpNoDelayOn())
                if ((error2 = acceptedSocket->SetNoDelayOpt()))
                {
                    CDBE("() failed to set nodelay option on socket...\n");
                    m_socket.Reject(*acceptedSocket);
                }
                else
#endif // !defined(WIN32)
				m_requestServer.Add(acceptedSocket);
			}
			else CDBE("() failed to accept socket connection on %d...\n", m_port);
		}
		while (!error2);

		if ((error2 = m_requestServer.Finish()))
		{
			CDBE("() failed to finish request server\n");
			if (!error)
				error = error2;
		}

        m_port = INVALID_SOCKET_PORT;
        m_threads = 0;
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
        EvError error = m_socket.Close();
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: AquireServlet
    //
    //   Author: $author$
    //     Date: 4/16/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvTcpServlet* AquireServlet() 
    {
        EvTcpServlet* servlet = 0;
        EvError error;

        if (!(error = m_servletDllMutex.Acquire()))
        {
            if (!(servlet = m_servletDll.AcquireServlet(error)))
                CDBE("() failed to acquire servlet\n");

            else if ((error = servlet->Initialize(*this)))
            {
                CDBE("() failed to initialize servlet\n");

                if ((error = m_servletDll.ReleaseServlet(*servlet)))
                    CDBE("() failed to release servlet\n");

                servlet = 0;
            }
            m_servletDllMutex.Release();
        }
        return servlet;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ReleaseServlet
    //
    //   Author: $author$
    //     Date: 4/21/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ReleaseServlet(EvTcpServlet& servlet) 
    {
        EvError error, error2;

        if (!(error = m_servletDllMutex.Acquire()))
        {
            if ((error = servlet.Finalize(*this)))
                CDBE("() failed to finalize servlet\n");

            if ((error2 = m_servletDll.ReleaseServlet(servlet)))
            {
                CDBE("() failed to release servlet\n");

                if (!error)
                    error = error2;
            }

            m_servletDllMutex.Release();
        }
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetTcpNoDelayOn
    //
    //   Author: $author$
    //     Date: 5/16/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int SetTcpNoDelayOn
    (bool on=true) 
    {
        m_tcpNoDelayOn = on;
        return m_tcpNoDelayOn;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetTcpNoDelayOn
    //
    //   Author: $author$
    //     Date: 5/16/2007
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetTcpNoDelayOn() const 
    {
        return m_tcpNoDelayOn;
    }
};

#endif // _CEVTCPSERVER_HPP
