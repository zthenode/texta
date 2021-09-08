///////////////////////////////////////////////////////////////////////
//   File: cevdatetime_compare.hpp
//
// Author: $author$
//   Date: 6/28/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVDATETIME_COMPARE_HPP
#define _CEVDATETIME_COMPARE_HPP
    ///////////////////////////////////////////////////////////////////////
    // Function: CompareDateTime
    //
    //   Author: $author$
    //     Date: 6/28/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int CompareDateTime
    (const EvDateTime& datetime,
     bool isLocal=false,
     const EvTimezone* timezone=0,
     bool is12=false,
     bool isPM=false) const
    {
        int unequal = 0;
        
        if (!(unequal = CompareDate
            (datetime, isLocal, timezone)))
        if (!(unequal = CompareTime
            (datetime, is12, isPM, isLocal, timezone)))
            {}
        return unequal;
    }
#endif // _CEVDATETIME_COMPARE_HPP
