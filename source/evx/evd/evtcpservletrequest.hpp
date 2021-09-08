///////////////////////////////////////////////////////////////////////
//   File: evtcpservletrequest.hpp
//
// Author: $author$
//   Date: 4/12/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _EVTCPSERVLETREQUEST_HPP
#define _EVTCPSERVLETREQUEST_HPP

#include "evservletrequest.hpp"
#include "evtcpservletinteraction.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: EvTcpServletRequest
//
// Author: $author$
//   Date: 4/12/2007
///////////////////////////////////////////////////////////////////////
class EV_EXPORT_CLASS EvTcpServletRequest
: virtual public EvServletRequest,
  virtual public EvTcpServletInteraction
{
public:
    typedef EvServletRequest CImplements;
    typedef EvTcpServletInteraction CExtends;
    typedef EvTcpServletRequest CDerives;
};
#endif // _EVTCPSERVLETREQUEST_HPP
