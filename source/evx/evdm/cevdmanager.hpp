///////////////////////////////////////////////////////////////////////
//   File: cevdmanager.hpp
//
// Author: $author$
//   Date: 8/3/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVDMANAGER_HPP
#define _CEVDMANAGER_HPP

#include "cevcpclient.hpp"
#include "cevtcpclient.hpp"
#include "evcp.h"

///////////////////////////////////////////////////////////////////////
//  Class: CEvdManager
//
// Author: $author$
//   Date: 8/3/2007
///////////////////////////////////////////////////////////////////////
class CEvdManager
: public CEvcpClient
{
public:
    typedef CEvcpClient CExtends;
    typedef CEvdManager CDerives;

    CEvTcpClient m_client;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvdManager
    //
    //       Author: $author$
    //         Date: 8/3/2007
    ///////////////////////////////////////////////////////////////////////
    CEvdManager() 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvdManager
    //
    //      Author: $author$
    //        Date: 8/3/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvdManager()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: RestartServer
    //
    //   Author: $author$
    //     Date: 8/3/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError RestartServer() 
    {
        EvError error = ServerAction
        (EVCP_REQUEST_ACTION_NAME_RESTART);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: StartServer
    //
    //   Author: $author$
    //     Date: 8/3/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError StartServer() 
    {
        EvError error = ServerAction
        (EVCP_REQUEST_ACTION_NAME_START);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: StopServer
    //
    //   Author: $author$
    //     Date: 8/3/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError StopServer() 
    {
        EvError error = ServerAction
        (EVCP_REQUEST_ACTION_NAME_STOP);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ServerAction
    //
    //   Author: $author$
    //     Date: 8/3/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ServerAction
    (const char* action, 
     const char* argument=EVCP_REQUEST_ACTION_ARGUMENT_NAME_NOW) 
    {
        EvError error = EV_ERROR_FAILED;
        EvError error2;
        bool disconnect;
        LONG length;

        if (0 < (length = m_requestHeader.m_heading.
            SetRequestAction(action)))
        if (0 < (length = m_requestHeader.m_heading.
            SetRequestPath(argument)))
        if (!(error = SendRequest(disconnect, true)))
        {
            error = ReceiveOk();
            if (disconnect)
            if ((error2 = m_client.Disconnect()) && !error)
                error = error2;
        }
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: ReceiveOk
    //
    //   Author: $author$
    //     Date: 8/3/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ReceiveOk() 
    {
        EvError error = EV_ERROR_FAILED;
        EvError error2;
        bool disconnect;
        LONG length;
        const char* chars;
        int unequal;

        if (!(error2 = ReceiveResponse(disconnect)))
        {
            const EvcpHeaderHeading& heading = m_responseHeader.GetHeading();

            if ((chars = heading.GetResponseStatus(length)))
                DBT("() received response status \"%s\"\n", chars);
            else chars = "";

            if ((unequal = heading.
                CompareUnsignedResponseStatus(EVCP_STATUS_CODE_OK)))
                DBE
                ("() response status \"%s\" != \"%d\" (\"%s\")\n", 
                 chars, EVCP_STATUS_CODE_OK, EVCP_STATUS_DESC_OK);
            else 
            {
                DBT
                ("() response status \"%s\" == \"%s\"\n", 
                 chars, EVCP_STATUS_DESC_OK);
                error = EV_ERROR_NONE;
            }

            if (disconnect)
            if ((error2 = m_client.Disconnect()) && !error)
                error = error2;
        }
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SendRequest
    //
    //   Author: $author$
    //     Date: 8/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError SendRequest
    (bool& disconnect, bool dontDisconnect=false) 
    {
        EvError error = EV_ERROR_FAILED;
        EvError error2;
        LONG length;

        if (!(error = m_client.Connect(disconnect)))
        {
            EvCharWriter& writer = m_client.GetWriter();
            if (0 >= (length = m_requestHeader.WriteRequest(writer)))
            {
                DBE("() failed to write request header\n");
                error = EV_ERROR_FAILED;
            }
            if (disconnect)
            if (dontDisconnect)
                disconnect = false;
            else if ((error2 = m_client.Disconnect()) && !error)
                    error = error2;
        }
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ReceiveRequest
    //
    //   Author: $author$
    //     Date: 8/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ReceiveRequest
    (bool& disconnect, bool dontDisconnect=false) 
    {
        EvError error = EV_ERROR_FAILED;
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SendResponse
    //
    //   Author: $author$
    //     Date: 8/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError SendResponse
    (bool& disconnect, bool dontDisconnect=false) 
    {
        EvError error = EV_ERROR_FAILED;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ReceiveResponse
    //
    //   Author: $author$
    //     Date: 8/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ReceiveResponse
    (bool& disconnect, bool dontDisconnect=false) 
    {
        EvError error = EV_ERROR_FAILED;
        EvError error2;
        LONG length;

        if (!(error = m_client.Connect(disconnect)))
        {
            EvCharReader& reader = m_client.GetReader();
            if (0 >= (length = m_responseHeader.Read(reader)))
            {
                DBE("() failed to read response header\n");
                error = EV_ERROR_FAILED;
            }
            else 
            {
                const EvcpHeaderHeading& heading = m_responseHeader.GetHeading();
                if (!heading.GetIsResponse())
                    error = EV_ERROR_FAILED;
            }
            if (disconnect)
            if (dontDisconnect)
                disconnect = false;
            else if ((error2 = m_client.Disconnect()) && !error)
                    error = error2;
        }
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: GetTcpClient
    //
    //   Author: $author$
    //     Date: 8/3/2007
    ///////////////////////////////////////////////////////////////////////
    virtual CEvTcpClient& GetTcpClient() const
    {
        return (CEvTcpClient&)(m_client);
    }
};
#endif // _CEVDMANAGER_HPP
