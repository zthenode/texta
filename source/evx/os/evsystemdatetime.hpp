///////////////////////////////////////////////////////////////////////
//   File: evsystemdatetime.hpp
//
// Author: $author$
//   Date: 7/13/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _EVSYSTEMDATETIME_HPP
#define _EVSYSTEMDATETIME_HPP

#include "evsystemtime.hpp"
#include "evsystemdate.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: EvSystemDateTime
//
// Author: $author$
//   Date: 7/13/2007
///////////////////////////////////////////////////////////////////////
class EV_EXPORT_CLASS EvSystemDateTime
: virtual public EvSystemTime,
  virtual public EvSystemDate
{
public:
    typedef EvSystemDate CImplements;
    typedef EvSystemDateTime CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Function: SetCurrentDateTime
    //
    //   Author: $author$
    //     Date: 7/13/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError SetCurrentDateTime
    (bool isLocal=false,
     const EvTimezone* timezone=0) = 0;
    ///////////////////////////////////////////////////////////////////////
    // Function: GetCurrentDateTime
    //
    //   Author: $author$
    //     Date: 7/13/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError GetCurrentDateTime
    (bool isLocal=false,
     const EvTimezone* timezone=0) = 0;
};
#endif // _EVSYSTEMDATETIME_HPP
