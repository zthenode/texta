///////////////////////////////////////////////////////////////////////
//   File: evcpservletinteraction.hpp
//
// Author: $author$
//   Date: 6/3/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _EVCPSERVLETINTERACTION_HPP
#define _EVCPSERVLETINTERACTION_HPP

#include "evservletinteraction.hpp"
#include "evcpservletconnection.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: EvcpServletInteraction
//
// Author: $author$
//   Date: 6/3/2007
///////////////////////////////////////////////////////////////////////
class EV_EXPORT_CLASS EvcpServletInteraction
: virtual public EvServletInteraction
{
public:
    typedef EvServletInteraction CImplements;
    typedef EvcpServletInteraction CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Function: GetEvcpConnection
    //
    //   Author: $author$
    //     Date: 6/3/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvcpServletConnection& GetEvcpConnection() const = 0;
};
#endif // _EVCPSERVLETINTERACTION_HPP
