///////////////////////////////////////////////////////////////////////
//   File: evconnector.hpp
//
// Author: $author$
//   Date: 8/2/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _EVCONNECTOR_HPP
#define _EVCONNECTOR_HPP

#include "evbase.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: EvConnector
//
// Author: $author$
//   Date: 8/2/2007
///////////////////////////////////////////////////////////////////////
class EV_EXPORT_CLASS EvConnector
: virtual public EvBase
{
public:
    typedef EvBase CImplements;
    typedef EvConnector CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Function: SetIsConnected
    //
    //   Author: $author$
    //     Date: 8/2/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int SetIsConnected
    (bool is=true) = 0;
    ///////////////////////////////////////////////////////////////////////
    // Function: GetIsConnected
    //
    //   Author: $author$
    //     Date: 8/2/2007
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetIsConnected() const = 0;
};
#endif // _EVCONNECTOR_HPP
