///////////////////////////////////////////////////////////////////////
//   File: evsystemtime.hpp
//
// Author: $author$
//   Date: 6/18/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _EVSYSTEMTIME_HPP
#define _EVSYSTEMTIME_HPP

#include "evtime.hpp"

#if defined(WIN32) 
// Windows
#if defined(GetCurrentTime) 
#undef GetCurrentTime
#endif // defined(GetCurrentTime)
#else // defined(WIN32) 
// Unix
#endif // defined(WIN32)

///////////////////////////////////////////////////////////////////////
//  Class: EvSystemTime
//
// Author: $author$
//   Date: 6/18/2007
///////////////////////////////////////////////////////////////////////
class EV_EXPORT_CLASS EvSystemTime
: virtual public EvTime
{
public:
    typedef EvTime CImplements;
    typedef EvSystemTime CDerives;

    ///////////////////////////////////////////////////////////////////////
    // Function: SetCurrentTime
    //
    //   Author: $author$
    //     Date: 6/14/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError SetCurrentTime
    (UINT hour,
     UINT minute,
     UINT second,
     bool is12=false,
     bool isPM=false,
     bool isLocal=false,
     const EvTimezone* timezone=0) = 0;
    ///////////////////////////////////////////////////////////////////////
    // Function: GetCurrentTime
    //
    //   Author: $author$
    //     Date: 6/14/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError GetCurrentTime
    (UINT& hour,
     UINT& minute,
     UINT& second,
     bool& isPM,
     bool is12=false,
     bool isLocal=false,
     const EvTimezone* timezone=0) = 0;

    ///////////////////////////////////////////////////////////////////////
    // Function: SetCurrentTime
    //
    //   Author: $author$
    //     Date: 6/14/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError SetCurrentTime
    (bool isLocal=false,
     const EvTimezone* timezone=0) = 0;
    ///////////////////////////////////////////////////////////////////////
    // Function: GetCurrentTime
    //
    //   Author: $author$
    //     Date: 6/14/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError GetCurrentTime
    (bool isLocal=false,
     const EvTimezone* timezone=0) = 0;
};

#endif // _EVSYSTEMTIME_HPP
