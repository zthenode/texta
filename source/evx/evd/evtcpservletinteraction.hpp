///////////////////////////////////////////////////////////////////////
//   File: evtcpservletinteraction.hpp
//
// Author: $author$
//   Date: 4/23/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _EVTCPSERVLETINTERACTION_HPP
#define _EVTCPSERVLETINTERACTION_HPP

#include "evservletinteraction.hpp"
#include "evtcpservletconnection.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: EvTcpServletInteraction
//
// Author: $author$
//   Date: 4/23/2007
///////////////////////////////////////////////////////////////////////
class EV_EXPORT_CLASS EvTcpServletInteraction
: virtual public EvServletInteraction
{
public:
    typedef EvServletInteraction CImplements;
    typedef EvTcpServletInteraction CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Function: GetTcpConnection
    //
    //   Author: $author$
    //     Date: 4/23/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvTcpServletConnection& GetTcpConnection() const = 0;
};
#endif // _EVTCPSERVLETINTERACTION_HPP
