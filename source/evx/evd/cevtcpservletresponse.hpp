///////////////////////////////////////////////////////////////////////
//   File: cevtcpservletresponse.hpp
//
// Author: $author$
//   Date: 4/16/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVTCPSERVLETRESPONSE_HPP
#define _CEVTCPSERVLETRESPONSE_HPP

#include "evtcpservletinteraction.hpp"
#include "evtcpservletresponse.hpp"
#include "cevservletresponse.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvTcpServletResponse
//
// Author: $author$
//   Date: 4/16/2007
///////////////////////////////////////////////////////////////////////
class CEvTcpServletResponse
: virtual public EvTcpServletResponse,
  public CEvServletResponse
{
public:
    typedef EvTcpServletResponse CImplements;
    typedef CEvServletResponse CExtends;
    typedef CEvTcpServletResponse CDerives;

    EvTcpServletConnection& m_tcpConnection;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvTcpServletResponse
    //
    //       Author: $author$
    //         Date: 4/16/2007
    ///////////////////////////////////////////////////////////////////////
    CEvTcpServletResponse
    (EvTcpServletConnection& connection,
     EvCharWriter& writer)
    : CExtends(connection, writer),
      m_tcpConnection(connection) 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvTcpServletResponse
    //
    //       Author: $author$
    //         Date: 4/16/2007
    ///////////////////////////////////////////////////////////////////////
    CEvTcpServletResponse(const CEvTcpServletResponse& response)
    : CExtends(response.GetConnection(), response.GetWriter()),
      m_tcpConnection(response.GetTcpConnection()) 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvTcpServletResponse
    //
    //      Author: $author$
    //        Date: 4/16/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvTcpServletResponse()
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetTcpConnection
    //
    //   Author: $author$
    //     Date: 5/23/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvTcpServletConnection& GetTcpConnection() const 
    {
        return (EvTcpServletConnection&)(m_tcpConnection);
    }
};
#endif // _CEVTCPSERVLETRESPONSE_HPP
