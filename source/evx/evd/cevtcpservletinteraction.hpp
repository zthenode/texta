///////////////////////////////////////////////////////////////////////
//   File: cevtcpservletinteraction.hpp
//
// Author: $author$
//   Date: 4/23/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVTCPSERVLETINTERACTION_HPP
#define _CEVTCPSERVLETINTERACTION_HPP

#include "evtcpservletinteraction.hpp"
#include "cevservletinteraction.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvTcpServletInteraction
//
// Author: $author$
//   Date: 4/23/2007
///////////////////////////////////////////////////////////////////////
class CEvTcpServletInteraction
: virtual public EvTcpServletInteraction,
  public CEvServletInteraction
{
public:
    typedef EvTcpServletInteraction CImplements;
    typedef CEvServletInteraction CExtends;
    typedef CEvTcpServletInteraction CDerives;

    EvTcpServletConnection& m_tcpConnection;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvTcpServletInteraction
    //
    //       Author: $author$
    //         Date: 4/23/2007
    ///////////////////////////////////////////////////////////////////////
    CEvTcpServletInteraction
    (EvTcpServletConnection& connection)
    : CExtends(connection),
      m_tcpConnection(connection)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvTcpServletInteraction
    //
    //      Author: $author$
    //        Date: 4/23/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvTcpServletInteraction()
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
#endif // _CEVTCPSERVLETINTERACTION_HPP
