///////////////////////////////////////////////////////////////////////
//   File: evclient.hpp
//
// Author: $author$
//   Date: 8/3/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _EVCLIENT_HPP
#define _EVCLIENT_HPP

#include "evbase.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: EvClient
//
// Author: $author$
//   Date: 8/3/2007
///////////////////////////////////////////////////////////////////////
class EV_EXPORT_CLASS EvClient
: virtual public EvBase
{
public:
    typedef EvBase CImplements;
    typedef EvClient CDerives;
};
#endif // _EVCLIENT_HPP
