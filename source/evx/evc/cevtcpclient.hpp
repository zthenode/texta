///////////////////////////////////////////////////////////////////////
//   File: cevtcpclient.hpp
//
// Author: $author$
//   Date: 8/2/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVTCPCLIENT_HPP
#define _CEVTCPCLIENT_HPP

#include "cevconnector.hpp"
#include "cevsocket.hpp"
#include "cevstring.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvTcpClient
//
// Author: $author$
//   Date: 8/2/2007
///////////////////////////////////////////////////////////////////////
class CEvTcpClient
: public CEvConnector
{
public:
    typedef CEvConnector CExtends;
    typedef CEvTcpClient CDerives;

    SOCKET_PORT m_port;
    const char* m_hostChars;
    CEvString m_host;

    CEvSocket m_socket;
    CEvSocketReader m_socketReader;
    CEvSocketWriter m_socketWriter;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvTcpClient
    //
    //       Author: $author$
    //         Date: 8/2/2007
    ///////////////////////////////////////////////////////////////////////
    CEvTcpClient
    (const char* host=0,
     SOCKET_PORT port=INVALID_SOCKET_PORT)
    : m_port(port),
      m_hostChars(0),
      m_socketReader(m_socket),
      m_socketWriter(m_socket)
    {
        EvError error;
        LONG length;
        if (host)
        if (0 > (length = SetHost(host)))
            throw(error = -length);
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvTcpClient
    //
    //      Author: $author$
    //        Date: 8/2/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvTcpClient()
    {
        Disconnect();
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Connect
    //
    //   Author: $author$
    //     Date: 8/2/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Connect
    (bool& disconnect) 
    {
        EvError error = EV_ERROR_FAILED;
        bool isConnected;

        disconnect = false;

        if ((isConnected = GetIsConnected()))
            return EV_ERROR_NONE;

        if (m_hostChars)
        {
            if (INVALID_SOCKET_PORT != m_port)
            {
                if ((error = m_socket.Create()))
                    DBE("() failed to create socket\n");
                else if ((error = m_socket.Connect(m_port, m_hostChars)))
                {
                    DBE("() failed to connect to %s:%d\n", m_hostChars, m_port);
                    m_socket.Close(true);
                }
                else SetIsConnected(disconnect = true);
            }
            else DBE("() invalid port %d\n", m_port);
        }
        else DBE("() invalid host \"\"\n");
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Disconnect
    //
    //   Author: $author$
    //     Date: 8/2/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Disconnect
    (bool onlyIfConnected=false) 
    {
        EvError error = EV_ERROR_FAILED;
        bool isConnected;

        if ((isConnected = GetIsConnected()))
        if ((error = m_socket.Close(true)))
            DBE("() failed to close socket\n");

        SetIsConnected(false);
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetHost
    //
    //   Author: $author$
    //     Date: 8/2/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG SetHost
    (const char* chars,
     LONG length=-1) 
    {
        LONG count = m_host.Assign(chars,length);
        m_hostChars = m_host.Chars(length);
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetHost
    //
    //   Author: $author$
    //     Date: 8/2/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetHost
    (LONG& length) const 
    {
        const char* chars = m_host.Chars(length);
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetPort
    //
    //   Author: $author$
    //     Date: 8/3/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError SetPort
    (SOCKET_PORT port) 
    {
        EvError error = EV_ERROR_NONE;
        m_port = port;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetPort
    //
    //   Author: $author$
    //     Date: 8/3/2007
    ///////////////////////////////////////////////////////////////////////
    virtual SOCKET_PORT GetPort() const 
    {
        return m_port;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: GetReader
    //
    //   Author: $author$
    //     Date: 8/3/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvCharReader& GetReader() const 
    {
        EvCharReader& reader = ((EvCharReader&)m_socketReader);
        return reader;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetWriter
    //
    //   Author: $author$
    //     Date: 8/3/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvCharWriter& GetWriter() const 
    {
        EvCharWriter& writer = ((EvCharWriter&)m_socketWriter);
        return writer;
    }
};
#endif // _CEVTCPCLIENT_HPP
