///////////////////////////////////////////////////////////////////////
//   File: evmutex.hpp
//
// Author: $author$
//   Date: 4/5/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _EVMUTEX_HPP
#define _EVMUTEX_HPP

#include "evwait.hpp"
#include "evtake.hpp"
#include "evgive.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: EvMutex
//
// Author: $author$
//   Date: 4/5/2007
///////////////////////////////////////////////////////////////////////
class EV_EXPORT_CLASS EvMutex
: virtual public EvWait,
  virtual public EvTake,
  virtual public EvGive
{
public:
    typedef EvGive CImplements;
    typedef EvMutex CDerives;
};
#endif // _EVMUTEX_HPP
