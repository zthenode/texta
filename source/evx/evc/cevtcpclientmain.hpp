///////////////////////////////////////////////////////////////////////
//   File: cevtcpclientmain.hpp
//
// Author: $author$
//   Date: 8/3/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVTCPCLIENTMAIN_HPP
#define _CEVTCPCLIENTMAIN_HPP

#include "cevmain.hpp"
#include "cevtcpclient.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvTcpClientMain
//
// Author: $author$
//   Date: 8/3/2007
///////////////////////////////////////////////////////////////////////
class CEvTcpClientMain
: public CEvMain
{
public:
    typedef CEvMain CExtends;
    typedef CEvTcpClientMain CDerives;

    static CDerives* m_instance;
    CDerives* m_oldInstance;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvTcpClientMain
    //
    //       Author: $author$
    //         Date: 8/3/2007
    ///////////////////////////////////////////////////////////////////////
    CEvTcpClientMain()
    : m_oldInstance(m_instance)
    {
        m_instance = this;
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvTcpClientMain
    //
    //      Author: $author$
    //        Date: 8/3/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvTcpClientMain()
    {
        if (this == m_instance)
            m_instance = m_oldInstance;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Run
    //
    //    Author: $author$
    //      Date: 8/3/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int Run
    (int argc, const char** argv, const char** env) 
    {
        int err = 0;
        return err;
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
        EvError error = GetTcpClient().Connect(disconnect);
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
        EvError error = GetTcpClient().Disconnect(onlyIfConnected);
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
        LONG count = GetTcpClient().SetHost(chars,length);
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
        const char* chars = GetTcpClient().GetHost(length);
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
        EvError error = GetTcpClient().SetPort(port);
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
        SOCKET_PORT port = GetTcpClient().GetPort();
        return port;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: GetInstance
    //
    //   Author: $author$
    //     Date: 8/3/2007
    ///////////////////////////////////////////////////////////////////////
    virtual CEvTcpClient& GetTcpClient() const = 0;

    ///////////////////////////////////////////////////////////////////////
    // Function: GetInstance
    //
    //   Author: $author$
    //     Date: 8/3/2007
    ///////////////////////////////////////////////////////////////////////
    static CEvTcpClientMain* GetInstance() 
    {
        return m_instance;
    }
};

#endif // _CEVTCPCLIENTMAIN_HPP
