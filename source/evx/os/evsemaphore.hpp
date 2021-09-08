///////////////////////////////////////////////////////////////////////
//   File: evsemaphore.hpp
//
// Author: $author$
//   Date: 4/5/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _EVSEMAPHORE_HPP
#define _EVSEMAPHORE_HPP

#include "evwait.hpp"
#include "evtake.hpp"
#include "evgive.hpp"
#include "cevbase.hpp"

#if defined(WIN32) 
//
// Windows
//
#else // defined(WIN32) 
//
// Unix
//
#endif // defined(WIN32)

///////////////////////////////////////////////////////////////////////
//  Class: EvSemaphore
//
// Author: $author$
//   Date: 4/5/2007
///////////////////////////////////////////////////////////////////////
class EV_EXPORT_CLASS EvSemaphore
: virtual public EvWait,
  virtual public EvTake,
  virtual public EvGive
{
public:
    typedef EvGive CImplements;
    typedef EvSemaphore CDerives;
};
#endif // _EVSEMAPHORE_HPP
