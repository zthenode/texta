///////////////////////////////////////////////////////////////////////
//   File: cevcsdmain.hpp
//
// Author: $author$
//   Date: 7/30/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCSDMAIN_HPP
#define _CEVCSDMAIN_HPP

#include "cevcsd.hpp"
#include "cevmain.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvEvcsDMain
//
// Author: $author$
//   Date: 7/30/2007
///////////////////////////////////////////////////////////////////////
class CEvEvcsDMain
: public CEvMain
{
public:
    typedef CEvMain CExtends;
    typedef CEvEvcsDMain CDerives;

    CEvcsDServer m_server;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvEvcsDMain
    //
    //       Author: $author$
    //         Date: 7/30/2007
    ///////////////////////////////////////////////////////////////////////
    CEvEvcsDMain() 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Run
    //
    //    Author: $author$
    //      Date: 7/30/2007
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
    // Function: RunServer
    //
    //   Author: $author$
    //     Date: 7/31/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError RunServer() 
    {
        EvError error = EV_ERROR_FAILED;
        bool restart;

        do
        {
            restart = false;
            if (!(error = m_server.Start(8088)))
            if ((error = m_server.Finish(restart)))
                break;
        }
        while(restart);
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetCiDirectory
    //
    //   Author: $author$
    //     Date: 7/31/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG SetCiDirectory
    (const char* chars,
     LONG length=-1) 
    {
        LONG count = m_server.SetCiDirectory(chars,length);
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetCiDirectory
    //
    //   Author: $author$
    //     Date: 7/31/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetCiDirectory
    (LONG& length) const 
    {
        const char* chars = m_server.GetCiDirectory(length);
        return chars;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: SetCoDirectory
    //
    //   Author: $author$
    //     Date: 7/31/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG SetCoDirectory
    (const char* chars,
     LONG length=-1) 
    {
        LONG count = m_server.SetCoDirectory(chars,length);
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetCoDirectory
    //
    //   Author: $author$
    //     Date: 7/31/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetCoDirectory
    (LONG& length) const 
    {
        const char* chars = m_server.GetCoDirectory(length);
        return chars;
    }
};

#endif // _CEVCSDMAIN_HPP
