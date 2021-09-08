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

#include "cevtcpservletserver.hpp"
#include "evtcpservletserver.hpp"
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
//  Class: CEvQueuedSocketRequestServletServer
//
// Author: $author$
//   Date: 4/6/2007
///////////////////////////////////////////////////////////////////////
class CEvQueuedSocketRequestServletServer
: public CEvQueuedRequestServer
  <CEvQueuedSocketRequestServletServer,
   CEvSocketReference,
   CEvTcpServletServer>
{
public:
    typedef CEvQueuedRequestServer
    <CEvQueuedSocketRequestServletServer,
     CEvSocketReference,
     CEvTcpServletServer> CExtends;
    typedef CEvQueuedSocketRequestServletServer CDerives;
};

///////////////////////////////////////////////////////////////////////
//  Class: CEvQueuedSocketRequestServletThread
//
// Author: $author$
//   Date: 4/6/2007
///////////////////////////////////////////////////////////////////////
class CEvQueuedSocketRequestServletThread
: public CEvThread<CEvQueuedSocketRequestServletServer>
{
public:
    typedef CEvThread<CEvQueuedSocketRequestServletServer> CExtends;
    typedef CEvQueuedSocketRequestServletThread CDerives;

    EvTcpServlet* m_servlet;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvQueuedSocketRequestServletThread
    //
    //       Author: $author$
    //         Date: 4/16/2007
    ///////////////////////////////////////////////////////////////////////
    CEvQueuedSocketRequestServletThread() 
    : m_servlet(0)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvQueuedSocketRequestServletThread
    //
    //      Author: $author$
    //        Date: 4/16/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvQueuedSocketRequestServletThread()
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

        DBT("() in...\n");

		if (m_queueServer)
        {
            if ((m_servlet = m_queueServer->AcquireServlet()))
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
        DBT("() ...out\n");
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
//  Typedef: CEvSocketReferenceQueue
//
//   Author: $author$
//     Date: 8/1/2007
///////////////////////////////////////////////////////////////////////
typedef ::std::deque<CEvSocketReference>
CEvSocketReferenceQueue;

///////////////////////////////////////////////////////////////////////
//  Class: CEvThreadedQueuedSocketRequestServer
//
// Author: $author$
//   Date: 4/6/2007
///////////////////////////////////////////////////////////////////////
template
<class TQueuedSocketRequestThread,
 class TQueuedSocketRequestThreadVector,
 class TQueuedSocketRequestThreadVectorIterator>

class CEvThreadedQueuedSocketRequestServer
: public CEvThreadedQueuedRequestServer
  <TQueuedSocketRequestThread,
   CEvSocketReference,
   CEvQueuedSocketRequestServletServer,
   CEvSocketReferenceQueue,
   TQueuedSocketRequestThreadVector,
   TQueuedSocketRequestThreadVectorIterator>
{
public:
    typedef CEvThreadedQueuedRequestServer
    <TQueuedSocketRequestThread,
     CEvSocketReference,
     CEvQueuedSocketRequestServletServer,
     CEvSocketReferenceQueue,
     TQueuedSocketRequestThreadVector,
     TQueuedSocketRequestThreadVectorIterator> CExtends;
    typedef CEvThreadedQueuedSocketRequestServer CDerives;

    CEvTcpServletServer& m_servletServer;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvThreadedQueuedSocketRequestServer
    //
    //       Author: $author$
    //         Date: 4/16/2007
    ///////////////////////////////////////////////////////////////////////
    CEvThreadedQueuedSocketRequestServer
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
    // Function: AcquireServlet
    //
    //   Author: $author$
    //     Date: 4/16/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvTcpServlet* AcquireServlet() 
    {
        EvTcpServlet* servlet = m_servletServer.AcquireServlet();
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
#define CDB_CLASS "CEvThreadedTcpServletServer"
///////////////////////////////////////////////////////////////////////
//  Class: CEvThreadedTcpServletServer
//
// Author: $author$
//   Date: 7/31/2007
///////////////////////////////////////////////////////////////////////
template
<class TQueuedSocketRequestThread,
 class TQueuedSocketRequestThreadVector,
 class TQueuedSocketRequestThreadVectorIterator>

class CEvThreadedTcpServletServer
: public CEvTcpServletServer
{
public:
    typedef CEvTcpServletServer CExtends;
    typedef CEvThreadedTcpServletServer CDerives;

	CEvSocket m_socket;
	CEvThreadedQueuedSocketRequestServer
	<TQueuedSocketRequestThread,
     TQueuedSocketRequestThreadVector,
     TQueuedSocketRequestThreadVectorIterator> m_requestServer;

    USHORT m_port;
    UINT m_threads;
    bool m_tcpNoDelayOn;
    bool m_socketDontLingerOn;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvThreadedTcpServletServer
    //
    //       Author: $author$
    //         Date: 7/31/2007
    ///////////////////////////////////////////////////////////////////////
    CEvThreadedTcpServletServer
    (bool tcpNoDelayOn=DEFAULT_CEVTCPSERVER_TCP_NO_DELAY_ON,
     bool socketDontLingerOn=DEFAULT_CEVTCPSERVER_SOCKET_DONT_LINGER_ON) 
    : m_requestServer(*this),
      m_port(INVALID_SOCKET_PORT),
      m_threads(0),
      m_tcpNoDelayOn(tcpNoDelayOn),
      m_socketDontLingerOn(socketDontLingerOn)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvThreadedTcpServletServer
    //
    //      Author: $author$
    //        Date: 7/31/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvThreadedTcpServletServer()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Start
    //
    //   Author: $author$
    //     Date: 7/31/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Start
    (USHORT port, UINT threads=1) 
    {
        EvError error = EV_ERROR_FAILED;

		if ((error = CreateSocket(port)))
			return error;

		if ((error = m_requestServer.Start(threads)))
		{
			CDBE("() failed to start request server\n");
			CloseSocket();
            return error;
		}

        m_port = port;
        m_threads = threads;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Finish
    //
    //   Author: $author$
    //     Date: 7/31/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Finish(bool& restart) 
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
                if ((error2 = SetSocketOpts(*acceptedSocket)))
                {
                    m_socket.Reject(acceptedSocket);
                    break;
                }
#endif // !defined(WIN32)
				m_requestServer.Add(acceptedSocket);
			}
			else CDBE("() failed to accept socket connection on %d...\n", m_port);
		}
		while (!error2);

		if ((error2 = m_requestServer.Finish(restart)))
		{
			CDBE("() failed to finish request server\n");
			if (!error)
				error = error2;
		}

        if ((error2 = CloseSocket()) && !error)
            error = error2;

        m_port = INVALID_SOCKET_PORT;
        m_threads = 0;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Stop
    //
    //   Author: $author$
    //     Date: 7/31/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Stop() 
    {
        EvError error = CloseSocket();
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: CreateSocket
    //
    //   Author: $author$
    //     Date: 7/31/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError CreateSocket(USHORT port) 
    {
        EvError error = EV_ERROR_FAILED;

		if ((error = m_socket.Create()))
		{
			CDBE("() failed to create socket\n");
			return error;
		}

#if defined(WIN32) 
// Windows
		if ((error = SetSocketOpts(m_socket)))
		{
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
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: CloseSocket
    //
    //   Author: $author$
    //     Date: 7/31/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError CloseSocket() 
    {
        EvError error = EV_ERROR_FAILED;

#if defined(WIN32) 
// Windows
#else // defined(WIN32) 
// Unix
		if ((error = m_socket.ShutDown()))
		{
			CDBE("() failed to shutdown socket\n");
			return error;
		}
#endif // defined(WIN32)
		if ((error = m_socket.Close()))
		{
			CDBE("() failed to close socket\n");
			return error;
		}
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetSocketOpts
    //
    //   Author: $author$
    //     Date: 7/31/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError SetSocketOpts(CEvSocket& socket) 
    {
        EvError error = EV_ERROR_NONE;
		EvError error2;

        if (GetTcpNoDelayOn())
		if ((error2 = socket.SetNoDelayOpt()))
		{
			CDBE("() failed to set nodelay socketopt\n");
			return EV_ERROR_FAILED;
		}
        if (GetSocketDontLingerOn())
		if ((error2 = socket.SetDontLingerOpt()))
		{
			CDBE("() failed to set dontlinger socketopt\n");
			return EV_ERROR_FAILED;
		}
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: AcquireServlet
    //
    //   Author: $author$
    //     Date: 7/31/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvTcpServlet* AcquireServlet() 
    {
        EvTcpServlet* servlet = 0;
        EvError error;

        if (!(servlet = AllocateServlet(error)))
            CDBE("() failed to allocate servlet\n");

        else if ((error = servlet->Initialize(*this)))
        {
            CDBE("() failed to initialize servlet\n");

            if ((error = FreeServlet(*servlet)))
                CDBE("() failed to free servlet\n");

            servlet = 0;
        }
        return servlet;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ReleaseServlet
    //
    //   Author: $author$
    //     Date: 7/31/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ReleaseServlet
    (EvTcpServlet& servlet) 
    {
        EvError error = EV_ERROR_FAILED;
        EvError error2;

        if ((error = servlet.Finalize(*this)))
            CDBE("() failed to finalize servlet\n");

        if ((error2 = FreeServlet(servlet)))
        {
            CDBE("() failed to free servlet\n");
            if (!error)
                error = error2;
        }
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: AllocateServlet
    //
    //   Author: $author$
    //     Date: 7/31/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvTcpServlet* AllocateServlet(EvError& error) 
    {
        EvTcpServlet* servlet = 0;
        error = EV_ERROR_FAILED;
        return servlet;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: FreeServlet
    //
    //   Author: $author$
    //     Date: 7/31/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError FreeServlet(EvTcpServlet& servlet) 
    {
        EvError error = EV_ERROR_FAILED;
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetTcpNoDelayOn
    //
    //   Author: $author$
    //     Date: 7/31/2007
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
    //     Date: 7/31/2007
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetTcpNoDelayOn() const 
    {
        return m_tcpNoDelayOn;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetSocketDontLingerOn
    //
    //   Author: $author$
    //     Date: 7/31/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int SetSocketDontLingerOn
    (bool on=true) 
    {
        m_socketDontLingerOn = on;
        return m_socketDontLingerOn;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetSocketDontLingerOn
    //
    //   Author: $author$
    //     Date: 7/31/2007
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetSocketDontLingerOn() const 
    {
        return m_socketDontLingerOn;
    }
};
#undef CDB_CLASS

#undef CDB_CLASS
#define CDB_CLASS "CEvThreadedDllTcpServletServer"
///////////////////////////////////////////////////////////////////////
//  Class: CEvThreadedDllTcpServletServer
//
// Author: $author$
//   Date: 4/6/2007
///////////////////////////////////////////////////////////////////////
template
<class TQueuedSocketRequestThread,
 class TQueuedSocketRequestThreadVector,
 class TQueuedSocketRequestThreadVectorIterator>

class CEvThreadedDllTcpServletServer
: public CEvThreadedTcpServletServer
  <TQueuedSocketRequestThread,
   TQueuedSocketRequestThreadVector,
   TQueuedSocketRequestThreadVectorIterator>
{
public:
    typedef CEvThreadedTcpServletServer
    <TQueuedSocketRequestThread,
     TQueuedSocketRequestThreadVector,
     TQueuedSocketRequestThreadVectorIterator> CExtends;
    typedef CEvThreadedDllTcpServletServer CDerives;

    CEvString m_servletDllFilename;

    CEvTcpServletDll m_servletDll;
	CEvMutex m_servletDllMutex;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvThreadedDllTcpServletServer
    //
    //       Author: $author$
    //         Date: 4/6/2007
    ///////////////////////////////////////////////////////////////////////
    CEvThreadedDllTcpServletServer
    (bool tcpNoDelayOn=DEFAULT_CEVTCPSERVER_TCP_NO_DELAY_ON,
     bool socketDontLingerOn=DEFAULT_CEVTCPSERVER_SOCKET_DONT_LINGER_ON) 
    : CExtends(tcpNoDelayOn, socketDontLingerOn)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvThreadedDllTcpServletServer
    //
    //      Author: $author$
    //        Date: 4/6/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvThreadedDllTcpServletServer()
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
        LONG length;

        if (servletDllFilename)
        if (0 >= (length = m_servletDllFilename.Assign(servletDllFilename)))
        {
            CDBE("() invalid servlet DLL filename \"%s\"\n", servletDllFilename);
            return error;
        }

        if ((servletDllFilename = m_servletDllFilename.Chars(length)) || (0 < length))
        if ((error = m_servletDll.Open(servletDllFilename)))
            CDBE("() failed to open Dll \"%s\"\n", servletDllFilename);

		if ((error = m_servletDllMutex.Create()))
		{
			CDBE("() failed to create servlet Dll mutex\n");
			return error;
		}

        error = CExtends::Start(port, threads);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Finish
    //
    //   Author: $author$
    //     Date: 4/6/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Finish(bool& restart) 
    {
        EvError error = CExtends::Finish(restart);
		EvError error2;
        const char* servletDllFilename;
        LONG length;

        if ((error2 = m_servletDllMutex.Destroy()))
		{
			CDBE("() failed to destroy servlet Dll mutex\n");
			if (!error)
                error = EV_ERROR_FAILED;
		}

        if ((servletDllFilename = m_servletDllFilename.Chars(length)) || (0 < length))
        if ((error = m_servletDll.Close()))
        {
            CDBE("() failed to close Dll \"%s\"\n", servletDllFilename);
			if (!error)
                error = EV_ERROR_FAILED;
        }
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: AcquireServlet
    //
    //   Author: $author$
    //     Date: 4/16/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvTcpServlet* AcquireServlet() 
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
};
#undef CDB_CLASS

#endif // _CEVTCPSERVER_HPP
