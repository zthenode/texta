///////////////////////////////////////////////////////////////////////
//   File: evcpservletrequest.hpp
//
// Author: $author$
//   Date: 4/21/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _EVCPSERVLETREQUEST_HPP
#define _EVCPSERVLETREQUEST_HPP

#include "evservletrequest.hpp"
#include "evcpservletinteraction.hpp"
#include "evcpheader.hpp"
#include "evcprequest.h"

///////////////////////////////////////////////////////////////////////
//  Class: EvcpServletRequest
//
// Author: $author$
//   Date: 4/21/2007
///////////////////////////////////////////////////////////////////////
class EV_EXPORT_CLASS EvcpServletRequest
: virtual public EvServletRequest,
  virtual public EvcpServletInteraction
{
public:
    typedef EvServletRequest CImplements;
    typedef EvcpServletRequest CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Function: GetHeader
    //
    //   Author: $author$
    //     Date: 4/23/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvcpHeader& GetHeader() const = 0;
};

#endif // _EVCPSERVLETREQUEST_HPP
