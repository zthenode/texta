///////////////////////////////////////////////////////////////////////
//   File: evsystemdate.hpp
//
// Author: $author$
//   Date: 6/18/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _EVSYSTEMDATE_HPP
#define _EVSYSTEMDATE_HPP

#include "evdate.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: EvSystemDate
//
// Author: $author$
//   Date: 6/18/2007
///////////////////////////////////////////////////////////////////////
class EV_EXPORT_CLASS EvSystemDate
: virtual public EvDate
{
public:
    typedef EvDate CImplements;
    typedef EvSystemDate CDerives;

    ///////////////////////////////////////////////////////////////////////
    // Function: SetCurrentDate
    //
    //   Author: $author$
    //     Date: 6/14/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError SetCurrentDate
    (UINT year,
     UINT month,
     UINT day,
     bool isLocal=false,
     const EvTimezone* timezone=0) = 0;
    ///////////////////////////////////////////////////////////////////////
    // Function: GetCurrentDate
    //
    //   Author: $author$
    //     Date: 6/14/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError GetCurrentDate
    (UINT& year,
     UINT& month,
     UINT& day,
     bool isLocal=false,
     const EvTimezone* timezone=0) = 0;

    ///////////////////////////////////////////////////////////////////////
    // Function: SetCurrentDate
    //
    //   Author: $author$
    //     Date: 6/14/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError SetCurrentDate
    (bool isLocal=false,
     const EvTimezone* timezone=0) = 0;
    ///////////////////////////////////////////////////////////////////////
    // Function: GetCurrentDate
    //
    //   Author: $author$
    //     Date: 6/14/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError GetCurrentDate
    (bool isLocal=false,
     const EvTimezone* timezone=0) = 0;
};

#endif // _EVSYSTEMDATE_HPP
