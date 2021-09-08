///////////////////////////////////////////////////////////////////////
//   File: cevcpclientmain.hpp
//
// Author: $author$
//   Date: 12/11/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCPCLIENTMAIN_HPP
#define _CEVCPCLIENTMAIN_HPP

#include "cevmain.hpp"
#include "cevcpresponse.hpp"
#include "cevcprequest.hpp"
#include "cevsocket.hpp"
#include "evdebug.h"
#include "evd.h"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpClientMain
//
// Author: $author$
//   Date: 12/11/2007
///////////////////////////////////////////////////////////////////////
class CEvcpClientMain
: public CEvMain
{
public:
    typedef CEvMain CExtends;
    typedef CEvcpClientMain CDerives;

    static CEvcpClientMain* m_theMain;
    CEvcpClientMain* m_oldMain;

    CEvcpHeader m_reqHeader;
    CEvcpHeader m_respHeader;

    EvcpHeaderHeading& m_reqHeading;
    EvcpHeaderHeading& m_respHeading;

    CEvcpRequest m_request;
    CEvcpResponse m_response;

    CEvCharFile m_responseFile;

    CEvSocket m_socket;
    CEvSocketReader m_socketReader;
    CEvSocketWriter m_socketWriter;

    EvCharReader* m_reader;
    EvCharWriter* m_writer;

    bool m_isConnected;
    bool m_isOpen;

    SHORT m_tcpPort;
    const char* m_tcpHost;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpClientMain
    //
    //       Author: $author$
    //         Date: 12/11/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpClientMain
    (SHORT tcpPort=DEFAULT_EVD_TCP_PORT,
     const char* tcpHost=DEFAULT_EVD_TCP_HOST)
    : m_oldMain(m_theMain),
      m_reqHeading(m_reqHeader.GetHeading()),
      m_respHeading(m_respHeader.GetHeading()),
      m_request(m_reqHeader),
      m_response(m_respHeader),
      m_socketReader(m_socket),
      m_socketWriter(m_socket),
      m_reader(&m_stdIn),
      m_writer(&m_stdOut),
      m_isConnected(false),
      m_isOpen(false),
      m_tcpPort(tcpPort),
      m_tcpHost(tcpHost)
    {
        EvError error;
        if ((error = Construct()))
            throw(error);
        m_theMain = this;
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvcpClientMain
    //
    //      Author: $author$
    //        Date: 12/11/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvcpClientMain()
    {
        EvError error;

        if (this == m_theMain)
            m_theMain = m_oldMain;

        if ((error = Destruct()))
            throw(error);
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Construct
    //
    //   Author: $author$
    //     Date: 9/6/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Construct() 
    {
        EvError error = EV_ERROR_FAILED;
        LONG length;

        if (0 < (length = m_reqHeading.SetProtocol(EVC_PROTOCOL_NAME)))
        if (0 < (length = m_reqHeading.SetProtocolVersionMajor(EVC_PROTOCOL_VERSION_MAJOR)))
        if (0 < (length = m_reqHeading.SetProtocolVersionMinor(EVC_PROTOCOL_VERSION_MINOR)))
        if (0 < (length = m_respHeading.SetProtocol(EVC_PROTOCOL_NAME)))
        if (0 < (length = m_respHeading.SetProtocolVersionMajor(EVC_PROTOCOL_VERSION_MAJOR)))
        if (0 < (length = m_respHeading.SetProtocolVersionMinor(EVC_PROTOCOL_VERSION_MINOR)))
            error = EV_ERROR_NONE;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Destruct
    //
    //   Author: $author$
    //     Date: 9/6/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Destruct() 
    {
        EvError error = EV_ERROR_FAILED;
        EvError error2;

        if (!(error2 = Disconnect()))
        if (!(error2 = CloseResponseFile()))
            error = EV_ERROR_NONE;
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: ReadOKResponse
    //
    //   Author: $author$
    //     Date: 9/12/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ReadOKResponse() 
    {
        EvError error = EV_ERROR_FAILED;
        bool isConnected;
        bool isOpen;
        const char* chars;
        LONG length;
        int unequal;

        if (!(isConnected = GetIsConnected())
            && !(isOpen = GetIsOpen()))
            return EV_ERROR_NONE;

        error = ReadOKResponse(*m_reader);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ReadOKResponse
    //
    //   Author: $author$
    //     Date: 12/22/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ReadOKResponse
    (EvCharReader& reader) 
    {
        EvError error = EV_ERROR_FAILED;
        const char* chars;
        LONG length;
        int unequal;

        if (0 >= (length = m_respHeader.Read(reader)))
            DBE("() failed to read header\n");

        else if (!m_respHeading.GetIsResponse())
                DBE("() read unexpected header type\n");

        else if ((unequal = m_respHeading.
                 CompareUnsignedResponseStatus
                 (EVCP_STATUS_CODE_OK)))
        {
            if ((chars = m_respHeading.
                GetResponseStatus(length)) && (0 <= length))
                DBE("() received status \"%s\"\n", chars);
        }
        else error = EV_ERROR_NONE;

        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Connect
    //
    //   Author: $author$
    //     Date: 9/6/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Connect
    (const char* host,
     USHORT port) 
    {
        EvError error = EV_ERROR_FAILED;
        EvError error2;
        bool isConnected;

        if ((isConnected = GetIsConnected()))
            return EV_ERROR_NONE;

        if (!(error2 = m_socket.Create()))
        {
            m_socket.SetNoDelayOpt();

            if ((error2 = m_socket.Connect(port, host)))
                DBE("() unable to connect to \"%s\":%d\n", host, port);
            else
            {
                m_reader = &m_socketReader;
                m_writer = &m_socketWriter;
                SetIsConnected();
                return EV_ERROR_NONE;
            }
            m_socket.Close();
        }
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Disconnect
    //
    //   Author: $author$
    //     Date: 9/6/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Disconnect() 
    {
        EvError error = EV_ERROR_FAILED;
        EvError error2;
        bool isConnected;

        m_reader = &m_stdIn;
        m_writer = &m_stdOut;

        if (!(isConnected = GetIsConnected()))
            return EV_ERROR_NONE;

        SetIsConnected(false);

        if (!(error2 = m_socket.Close()))
            error = EV_ERROR_NONE;
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: OpenResponseFile
    //
    //   Author: $author$
    //     Date: 9/12/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OpenResponseFile
    (const char* filename) 
    {
        EvError error = EV_ERROR_FAILED;
        EvError error2;

        if ((error2 = m_responseFile.
            Open(filename, EVFILE_MODE_READ_BINARY)))
            DBE("() failed to open response file \"%s\"\n", filename);
        else
        {
            m_reader = &m_responseFile;
            SetIsOpen();
            error = EV_ERROR_NONE;
        }
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: CloseResponseFile
    //
    //   Author: $author$
    //     Date: 9/12/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError CloseResponseFile() 
    {
        EvError error = EV_ERROR_FAILED;
        EvError error2;
        bool isOpen;

        m_reader = &m_stdIn;
        SetIsOpen(false);

        if (!(isOpen = GetIsOpen()))
            return EV_ERROR_NONE;

        if (!(error2 = m_responseFile.Close()))
            error = EV_ERROR_NONE;
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetIsConnected
    //
    //   Author: $author$
    //     Date: 9/6/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int SetIsConnected
    (bool is=true) 
    {
        m_isConnected = is;
        return m_isConnected;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetIsConnected
    //
    //   Author: $author$
    //     Date: 9/6/2007
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetIsConnected() const 
    {
        return m_isConnected;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetIsOpen
    //
    //   Author: $author$
    //     Date: 9/12/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int SetIsOpen
    (bool is=true) 
    {
        m_isOpen = is;
        return m_isOpen;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetIsOpen
    //
    //   Author: $author$
    //     Date: 9/12/2007
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetIsOpen() const 
    {
        return m_isOpen;
    }
};

#endif // _CEVCPCLIENTMAIN_HPP
