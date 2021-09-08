///////////////////////////////////////////////////////////////////////
//   File: cevdmanagermain.hpp
//
// Author: $author$
//   Date: 8/3/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVDMANAGERMAIN_HPP
#define _CEVDMANAGERMAIN_HPP

#include "cevtcpclientmain.hpp"
#include "cevdmanager.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvdManagerMain
//
// Author: $author$
//   Date: 8/3/2007
///////////////////////////////////////////////////////////////////////
class CEvdManagerMain
: public CEvTcpClientMain
{
public:
    typedef CEvTcpClientMain CExtends;
    typedef CEvdManagerMain CDerives;

    CEvdManager m_manager;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvdManagerMain
    //
    //       Author: $author$
    //         Date: 8/3/2007
    ///////////////////////////////////////////////////////////////////////
    CEvdManagerMain() 
    {
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

        if (!GetDidMain())
            return Help(argc, argv, env);
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: RestartServer
    //
    //   Author: $author$
    //     Date: 8/3/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError RestartServer() 
    {
        EvError error = m_manager.RestartServer();
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
        EvError error = m_manager.StartServer();
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
        EvError error = m_manager.StopServer();
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
        return m_manager.GetTcpClient();
    }
};

#endif // _CEVDMCEvTcpClient&ANAGERMAIN_HPP
