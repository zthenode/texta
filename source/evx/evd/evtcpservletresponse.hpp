///////////////////////////////////////////////////////////////////////
//   File: evtcpservletresponse.hpp
//
// Author: $author$
//   Date: 4/12/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _EVTCPSERVLETRESPONSE_HPP
#define _EVTCPSERVLETRESPONSE_HPP

#include "evservletresponse.hpp"
#include "evtcpservletinteraction.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: EvTcpServletResponse
//
// Author: $author$
//   Date: 4/12/2007
///////////////////////////////////////////////////////////////////////
class EV_EXPORT_CLASS EvTcpServletResponse
: virtual public EvServletResponse,
  virtual public EvTcpServletInteraction
{
public:
    typedef EvServletResponse CImplements;
    typedef EvTcpServletInteraction CExtends;
    typedef EvTcpServletResponse CDerives;
};
#endif // _EVTCPSERVLETRESPONSE_HPP
