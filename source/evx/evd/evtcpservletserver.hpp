///////////////////////////////////////////////////////////////////////
//   File: evtcpservletserver.hpp
//
// Author: $author$
//   Date: 5/14/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _EVTCPSERVLETSERVER_HPP
#define _EVTCPSERVLETSERVER_HPP

#include "evservletserver.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: EvTcpServletServer
//
// Author: $author$
//   Date: 5/14/2007
///////////////////////////////////////////////////////////////////////
class EV_EXPORT_CLASS EvTcpServletServer
: virtual public EvServletServer
{
public:
    typedef EvServletServer CImplements;
    typedef EvTcpServletServer CDerives;
};
#endif // _EVTCPSERVLETSERVER_HPP
