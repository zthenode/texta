///////////////////////////////////////////////////////////////////////
//   File: evtcpservletconnection.hpp
//
// Author: $author$
//   Date: 4/23/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _EVTCPSERVLETCONNECTION_HPP
#define _EVTCPSERVLETCONNECTION_HPP

#include "evtcpservletserver.hpp"
#include "evservletconnection.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: EvTcpServletConnection
//
// Author: $author$
//   Date: 4/23/2007
///////////////////////////////////////////////////////////////////////
class EV_EXPORT_CLASS EvTcpServletConnection
: virtual public EvServletConnection
{
public:
    typedef EvServletConnection CImplements;
    typedef EvTcpServletConnection CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Function: GetTcpServer
    //
    //   Author: $author$
    //     Date: 5/14/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvTcpServletServer& GetTcpServer() const = 0;
};

#endif // _EVTCPSERVLETCONNECTION_HPP
