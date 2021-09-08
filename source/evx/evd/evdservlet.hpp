///////////////////////////////////////////////////////////////////////
//   File: evdservlet.hpp
//
// Author: $author$
//   Date: 9/10/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _EVDSERVLET_HPP
#define _EVDSERVLET_HPP

#include "cevdtcpservletserver.hpp"
#include "cevtcpservletdll.hpp"
#include "cevtcpservletconnection.hpp"
#include "cevtcpservletresponse.hpp"
#include "cevtcpservletrequest.hpp"
#include "cevservletserver.hpp"
#include "cevservletconnection.hpp"
#include "cevservletresponse.hpp"
#include "cevservletrequest.hpp"
#include "cevsocket.hpp"
#include "cevmain.hpp"

#define DEFAULT_EVDSERVLET_SERVLET_DLL_FILENAME "libevdservlet." DLL_FILE_EXTENSION_CHARS
#define DEFAULT_EVDSERVLET_REQUEST_FILENAME "request.evcp"
#define DEFAULT_EVDSERVLET_TCP_PORT 8008

///////////////////////////////////////////////////////////////////////
//  Class: CEvdServletMain
//
// Author: $author$
//   Date: 4/13/2007
///////////////////////////////////////////////////////////////////////
class CEvdServletMain
: public CEvMain
{
public:
    typedef CEvMain CExtends;
    typedef CEvdServletMain CDerives;

    CEvString m_servletDllFilename;
    CEvTcpServletDll m_servletDll;

    EvServlet* m_servlet;
    CEvServletServer m_server;
    CEvServletConnection m_connection;

    CEvString m_requestFilename;
    CEvCharFile m_requestFile;

    EvCharReader& m_requestReader;
    EvCharWriter& m_responseWriter;

    CEvServletRequest m_request;
    CEvServletResponse m_response;

    SHORT m_tcpPort;

    CEvSocket m_tcpSocket;
    CEvSocket m_tcpAcceptSocket;

    EvTcpServlet* m_tcpServlet;
    CEvdTcpServletServer m_tcpServer;
    CEvTcpServletConnection m_tcpServletConnection;

    CEvSocketReader m_tcpRequestReader;
    CEvSocketWriter m_tcpResponseWriter;

    CEvTcpServletRequest m_tcpRequest;
    CEvTcpServletResponse m_tcpResponse;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvdServletMain
    //
    //       Author: $author$
    //         Date: 4/13/2007
    ///////////////////////////////////////////////////////////////////////
    CEvdServletMain
    (const char* requestFilename=DEFAULT_EVDSERVLET_SERVLET_DLL_FILENAME,
     const char* servletDllFilename=DEFAULT_EVDSERVLET_REQUEST_FILENAME,
     SHORT tcpPort=DEFAULT_EVDSERVLET_TCP_PORT) 
    : m_servletDllFilename(servletDllFilename),
      m_servlet(0),
      m_connection(m_server),
      m_requestFilename(requestFilename),
      m_requestReader(m_requestFile),
      m_responseWriter(m_stdOut),
      m_request(m_connection, m_requestReader),
      m_response(m_connection, m_responseWriter),
      m_tcpPort(tcpPort),
      m_tcpServlet(0),
      m_tcpServletConnection(m_tcpServer),
      m_tcpRequestReader(m_tcpAcceptSocket),
      m_tcpResponseWriter(m_tcpAcceptSocket),
      m_tcpRequest
      (m_tcpServletConnection, m_tcpRequestReader),
      m_tcpResponse
      (m_tcpServletConnection, m_tcpResponseWriter)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvdServletMain
    //
    //      Author: $author$
    //        Date: 4/13/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvdServletMain()
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Run
    //
    //   Author: $author$
    //     Date: 4/13/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int Run
    (int argc,
     const char** argv,
     const char** env) 
    {
        int result = 0;
        const char* servletDllFilename;
        const char* requestFilename;
        LONG length;
        EvError error;

        if (!GetDidMain())
        if ((servletDllFilename = m_servletDllFilename.HasChars(length)))
        if (!(error = m_servletDll.Open(servletDllFilename)))
        {
            if ((m_servlet = m_servletDll.AcquireEvServlet(error)))
            {
                if (!(error = m_servlet->Initialize(m_server)))
                {
                    if ((requestFilename = m_requestFilename.HasChars(length)))
                    if (!(error = m_requestFile.
                        Open(requestFilename, EVFILE_MODE_READ_BINARY)))
                    {
                        if ((error = m_connection.Initialize()))
                            DBE("() failed to initialize connection\n");
                        else
                        {
                            if ((error = m_servlet->
                                ConnectionInitialize(m_connection)))
                                DBE("() failed to connection initialize servlet\n");
                            else
                            {
                                if ((error = m_servlet->Service(m_request, m_response)))
                                    DBE("() failed on servlet service\n");

                                if ((error = m_servlet->
                                    ConnectionFinalize(m_connection)))
                                    DBE("() failed to connection finalize servlet\n");
                            }
                            if ((error = m_connection.Finalize()))
                                DBE("() failed to Finalize connection\n");
                        }
                        error = m_requestFile.Close();
                    }
                    error = m_servlet->Finalize(m_server);
                }
                m_servletDll.ReleaseEvServlet(*m_servlet);
            }
            m_servletDll.Close();
        }
        return result;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Listen
    //
    //   Author: $author$
    //     Date: 4/13/2007
    ///////////////////////////////////////////////////////////////////////
    virtual void Listen() 
    {
        const char* servletDllFilename;
        LONG length;
        EvError error;

        if ((servletDllFilename = m_servletDllFilename.HasChars(length)))
        if (!(error = m_servletDll.Open(servletDllFilename)))
        {
            if ((m_tcpServlet = m_servletDll.AcquireServlet(error)))
            {
                if (!(error = m_tcpServlet->Initialize(m_tcpServer)))
                {
                    if (!(error = m_tcpSocket.Create()))
                    {
                        if (!(error = m_tcpSocket.Bind(m_tcpPort)))
                        if (!(error = m_tcpSocket.Listen()))
                        if (!(error = m_tcpSocket.Accept(m_tcpAcceptSocket)))
                        {
                            if (!(error = m_tcpAcceptSocket.SetNoDelayOpt()))
                            if ((error = m_tcpServletConnection.Initialize()))
                                DBE("() failed to initialize connection\n");
                            else
                            {
                                /*if ((error = m_tcpServlet->
                                    ConnectionInitialize(m_connection)))
                                    DBE("() failed to connection initialize servlet\n");
                                else
                                {*/
                                    if ((error = m_tcpServlet->
                                        Service(m_tcpRequest, m_tcpResponse)))
                                        DBE("() failed on servlet service\n");

                                    /*if ((error = m_tcpServlet->
                                        ConnectionFinalize(m_connection)))
                                        DBE("() failed to connection finalize servlet\n");
                                }*/
                                if ((error = m_tcpServletConnection.Finalize()))
                                    DBE("() failed to Finalize connection\n");
                            }
                            m_tcpAcceptSocket.Close();
                        }
                        m_tcpSocket.Close();
                    }
                    error = m_tcpServlet->Finalize(m_tcpServer);
                }
                m_servletDll.ReleaseServlet(*m_tcpServlet);
            }
            m_servletDll.Close();
        }
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetRequestFilename
    //
    //   Author: $author$
    //     Date: 9/10/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG SetRequestFilename
    (const char* chars,
     LONG length=-1) 
    {
        LONG count = m_requestFilename.Assign(chars,length);
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetRequestFilename
    //
    //   Author: $author$
    //     Date: 9/10/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetRequestFilename
    (LONG& length) const 
    {
        return m_requestFilename.Chars(length);
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetServletDllFilename
    //
    //   Author: $author$
    //     Date: 9/10/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG SetServletDllFilename
    (const char* chars,
     LONG length=-1) 
    {
        LONG count = m_servletDllFilename.Assign(chars,length);
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetServletDllFilename
    //
    //   Author: $author$
    //     Date: 9/10/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetServletDllFilename
    (LONG& length) const 
    {
        return m_servletDllFilename.Chars(length);
    }
};

#endif // _EVDSERVLET_HPP


