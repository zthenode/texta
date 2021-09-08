///////////////////////////////////////////////////////////////////////
//   File: cevmsticks.hpp
//
// Author: $author$
//   Date: 6/12/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVMSTICKS_HPP
#define _CEVMSTICKS_HPP

#include "evplatform_ticks.h"
#include "evticks.hpp"
#include "cevbase.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvMillisecondTicks
//
// Author: $author$
//   Date: 6/12/2007
///////////////////////////////////////////////////////////////////////
class EV_EXPORT_CLASS CEvMillisecondTicks
: virtual public EvTicks,
  public CEvBase
{
public:
    typedef EvTicks CImplements;
    typedef CEvBase CExtends;
    typedef CEvMillisecondTicks CDerives;

    DWORD m_ticks;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvMillisecondTicks
    //
    //       Author: $author$
    //         Date: 6/12/2007
    ///////////////////////////////////////////////////////////////////////
    CEvMillisecondTicks() 
    : m_ticks(0)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetCurrentTicks
    //
    //   Author: $author$
    //     Date: 6/12/2007
    ///////////////////////////////////////////////////////////////////////
    virtual DWORD GetCurrentTicks() 
    {
        m_ticks = GetMillisecondTicks();
        return m_ticks;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetElapsedTicks
    //
    //   Author: $author$
    //     Date: 6/12/2007
    ///////////////////////////////////////////////////////////////////////
    virtual DWORD GetElapsedTicks() 
    {
        DWORD ticks = GetElapsedTicks(m_ticks);
        return ticks;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetElapsedTicks
    //
    //   Author: $author$
    //     Date: 6/12/2007
    ///////////////////////////////////////////////////////////////////////
    virtual DWORD GetElapsedTicks
    (DWORD startTicks) 
    {
        DWORD ticks = GetMillisecondTicks();

        if (ticks < startTicks)
            ticks = startTicks - ticks;
        else ticks = ticks - startTicks;
        return ticks;
    }
};
#endif // _CEVMSTICKS_HPP
