///////////////////////////////////////////////////////////////////////
//   File: cevtcpservletserver.hpp
//
// Author: $author$
//   Date: 8/1/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVTCPSERVLETSERVER_HPP
#define _CEVTCPSERVLETSERVER_HPP

#include "evtcpservletserver.hpp"
#include "evtcpservlet.hpp"
#include "cevproperties.hpp"

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
    typedef CEvProperties CExtends;
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
    // Function: AcquireServlet
    //
    //   Author: $author$
    //     Date: 4/16/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvTcpServlet* AcquireServlet() 
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

#endif // _CEVTCPSERVLETSERVER_HPP
