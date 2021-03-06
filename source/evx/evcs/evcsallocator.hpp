///////////////////////////////////////////////////////////////////////
//   File: evcsallocator.hpp
//
// Author: $author$
//   Date: 5/24/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _EVCSALLOCATOR_HPP
#define _EVCSALLOCATOR_HPP

#include "evinitializer.hpp"
#include "evfinalizer.hpp"
#include "evcs.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: EvcsAllocator
//
// Author: $author$
//   Date: 5/24/2007
///////////////////////////////////////////////////////////////////////
class EV_EXPORT_CLASS EvcsAllocator
: virtual public EvInitializer,
  virtual public EvFinalizer
{
public:
    typedef EvInitializer CInitImplements;
    typedef EvFinalizer CFinalImplements;
    typedef EvcsAllocator CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Function: GetAllocator
    //
    //   Author: $author$
    //     Date: 5/24/2007
    ///////////////////////////////////////////////////////////////////////
    static EvcsAllocator* GetAllocator
    (EvError& error, const char* name=0, LONG length=-1);
    ///////////////////////////////////////////////////////////////////////
    // Function: AcquireEvcs
    //
    //   Author: $author$
    //     Date: 5/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual Evcs* AcquireEvcs(EvError& error) = 0;
    ///////////////////////////////////////////////////////////////////////
    // Function: ReleaseEvcs
    //
    //   Author: $author$
    //     Date: 5/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ReleaseEvcs(Evcs& evcs) = 0;
    ///////////////////////////////////////////////////////////////////////
    // Function: SetName
    //
    //   Author: $author$
    //     Date: 5/26/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG SetName
    (const char* chars, LONG length=-1) = 0;
    ///////////////////////////////////////////////////////////////////////
    // Function: GetName
    //
    //   Author: $author$
    //     Date: 5/26/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetName
    (LONG& length) const = 0;
};
#endif // _EVCSALLOCATOR_HPP
