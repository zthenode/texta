///////////////////////////////////////////////////////////////////////
//   File: cevtcpservletconnection.hpp
//
// Author: $author$
//   Date: 4/23/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVTCPSERVLETCONNECTION_HPP
#define _CEVTCPSERVLETCONNECTION_HPP

#include "evtcpservletconnection.hpp"
#include "cevservletconnection.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvTcpServletConnection
//
// Author: $author$
//   Date: 4/23/2007
///////////////////////////////////////////////////////////////////////
class CEvTcpServletConnection
: virtual public EvTcpServletConnection,
  public CEvServletConnection
{
public:
    typedef EvTcpServletConnection CImplements;
    typedef CEvServletConnection CExtends;
    typedef CEvTcpServletConnection CDerives;

    EvTcpServletServer& m_tcpServer;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvTcpServletConnection
    //
    //       Author: $author$
    //         Date: 4/23/2007
    ///////////////////////////////////////////////////////////////////////
    CEvTcpServletConnection
    (EvTcpServletServer& server, bool keepAlive=false)
    : CExtends(server, keepAlive),
      m_tcpServer(server)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvTcpServletConnection
    //
    //      Author: $author$
    //        Date: 4/23/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvTcpServletConnection()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: GetTcpServer
    //
    //   Author: $author$
    //     Date: 5/14/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvTcpServletServer& GetTcpServer() const 
    {
        return m_tcpServer;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: DeleteThis
    //
    //   Author: $author$
    //     Date: 1/30/2012
    ///////////////////////////////////////////////////////////////////////
    virtual EvError DeleteThis()
    {
        EvError error = EV_ERROR_NOT_ALLOWED;
        return error;
    }
};
#endif // _CEVTCPSERVLETCONNECTION_HPP
