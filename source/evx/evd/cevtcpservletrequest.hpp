///////////////////////////////////////////////////////////////////////
//   File: cevtcpservletrequest.hpp
//
// Author: $author$
//   Date: 4/16/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVTCPSERVLETREQUEST_HPP
#define _CEVTCPSERVLETREQUEST_HPP

#include "evtcpservletinteraction.hpp"
#include "evtcpservletrequest.hpp"
#include "cevservletrequest.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvTcpServletRequest
//
// Author: $author$
//   Date: 4/16/2007
///////////////////////////////////////////////////////////////////////
class CEvTcpServletRequest
: virtual public EvTcpServletRequest,
  public CEvServletRequest
{
public:
    typedef EvTcpServletRequest CImplements;
    typedef CEvServletRequest CExtends;
    typedef CEvTcpServletRequest CDerives;

    EvTcpServletConnection& m_tcpConnection;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvTcpServletRequest
    //
    //       Author: $author$
    //         Date: 4/16/2007
    ///////////////////////////////////////////////////////////////////////
    CEvTcpServletRequest
    (EvTcpServletConnection& connection,
     EvCharReader& reader) 
    : CExtends(connection, reader),
      m_tcpConnection(connection)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvTcpServletRequest
    //
    //       Author: $author$
    //         Date: 4/16/2007
    ///////////////////////////////////////////////////////////////////////
    CEvTcpServletRequest(const CEvTcpServletRequest& request) 
    : CExtends(request.GetConnection(), request.GetReader()),
      m_tcpConnection(request.GetTcpConnection())
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvTcpServletRequest
    //
    //      Author: $author$
    //        Date: 4/16/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvTcpServletRequest()
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetTcpConnection
    //
    //   Author: $author$
    //     Date: 4/23/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvTcpServletConnection& GetTcpConnection() const 
    {
        return (EvTcpServletConnection&)(m_tcpConnection);
    }
};
#endif // _CEVTCPSERVLETREQUEST_HPP
