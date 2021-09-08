///////////////////////////////////////////////////////////////////////
//   File: cevcpservletcontext.hpp
//
// Author: $author$
//   Date: 5/24/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCPSERVLETCONTEXT_HPP
#define _CEVCPSERVLETCONTEXT_HPP

#include "evcpservletcontext.hpp"
#include "cevservletcontext.hpp"
#include "cevcsallocatorlist.hpp"
#include "evcsacquired.hpp"
#include "cevcs.hpp"
#include "evdebug.h"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpServletContext
//
// Author: $author$
//   Date: 5/24/2007
///////////////////////////////////////////////////////////////////////
class CEvcpServletContext
: virtual public EvcpServletContext,
  public CEvServletContext
{
public:
    typedef EvcpServletContext CImplements;
    typedef CEvServletContext CExtends;
    typedef CEvcpServletContext CDerives;

    const EvcpServlet& m_evcpServlet;
    EvcsAcquired m_acquired;
    Evcs* m_evcs;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpServletContext
    //
    //       Author: $author$
    //         Date: 5/24/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpServletContext(const EvcpServlet& evcpServlet)
    : CExtends((const EvServlet&)(evcpServlet)),
      m_evcpServlet(evcpServlet),
      m_evcs(0)
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Initialize
    //
    //   Author: $author$
    //     Date: 5/25/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Initialize() 
    {
        EvError error = EV_ERROR_NONE;
        CEvcsAllocatorItem* allocatorItem;

        for (allocatorItem = CEvcsAllocatorList::GetFirstItem();
             allocatorItem; allocatorItem = allocatorItem->GetNextItem())
        {
            EvcsAllocator& allocator = allocatorItem->GetAllocator();
            if ((error = allocator.Initialize()))
            {
                FinalizeAllocators(allocatorItem->GetPrevItem());
                break;
            }
        }
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Finalize
    //
    //   Author: $author$
    //     Date: 5/25/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Finalize() 
    {
        EvError error = EV_ERROR_NONE;
        EvError error2;
        EvcsAcquiredIterator i;
        Evcs* acquiredEvcs;

        for (i = m_acquired.begin();
             i != m_acquired.end(); i++)
        {
            if ((acquiredEvcs = *i))
            if ((error2 = ReleaseAcquiredEvcs
                 (*acquiredEvcs)) && !error)
                error = error2;
        }

        m_acquired.clear();

        if ((error2 = FinalizeAllocators
            (CEvcsAllocatorList::GetLastItem())) && !error)
            error = error2;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: FinalizeAllocators
    //
    //   Author: $author$
    //     Date: 5/28/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError FinalizeAllocators
    (CEvcsAllocatorItem* allocatorItem) 
    {
        EvError error = EV_ERROR_NONE;
        EvError error2;

        for (;allocatorItem; allocatorItem = allocatorItem->GetPrevItem())
        {
            EvcsAllocator& allocator = allocatorItem->GetAllocator();
            if ((error2 = allocator.Finalize()) && !error)
                error = error2;
        }
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: AcquireEvcs
    //
    //   Author: $author$
    //     Date: 5/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual Evcs* AcquireEvcs
    (EvError& error, const char* name, LONG length=-1) 
    {
        Evcs* evcs = 0;
        EvcsAllocator* allocator;

        if (!name || !length)
            evcs = AcquireEvcs(error);

        else if ((allocator = EvcsAllocator::
                  GetAllocator(error, name,  length)))
                evcs = allocator->AcquireEvcs(error);

        return evcs;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: AcquireEvcs
    //
    //   Author: $author$
    //     Date: 5/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual Evcs* AcquireEvcs(EvError& error) 
    {
        Evcs* evcs = 0;
        EvcsAllocator* allocator;

        if ((evcs = m_evcs))
        {
            error = EV_ERROR_NONE;
            return evcs;
        }

        error = EV_ERROR_FAILED;

        if ((allocator = EvcsAllocator::GetAllocator(error)))
        if ((evcs = allocator->AcquireEvcs(error)))
            m_acquired.push_back(m_evcs = evcs);

        return evcs;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ReleaseEvcs
    //
    //   Author: $author$
    //     Date: 5/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ReleaseEvcs(Evcs& evcs) 
    {
        EvError error = EV_ERROR_FAILED;
        EvcsAcquiredIterator i;
        Evcs* acquiredEvcs;

        for (i = m_acquired.begin();
             i != m_acquired.end(); i++)
        {
            if (&evcs == (acquiredEvcs = *i))
                return EV_ERROR_NONE;
        }
        DBE("() evcs not acquired\n");
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ReleaseAcquiredEvcs
    //
    //   Author: $author$
    //     Date: 5/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ReleaseAcquiredEvcs(Evcs& evcs) 
    {
        EvError error = EV_ERROR_FAILED;
        EvcsAllocator* allocator;

        if ((allocator = evcs.GetAllocator()))
            error = allocator->ReleaseEvcs(evcs);
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: GetEvcpServlet
    //
    //   Author: $author$
    //     Date: 5/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const EvcpServlet& GetEvcpServlet() const 
    {
        return m_evcpServlet;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: GetCiServletContext
    //
    //   Author: $author$
    //     Date: 6/3/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvCiServletContext* 
    GetCiServletContext(EvError& error) const
    {
        error = EV_ERROR_NOT_DEFINED;
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetCoServletContext
    //
    //   Author: $author$
    //     Date: 8/19/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvCoServletContext* 
    GetCoServletContext(EvError& error) const
    {
        error = EV_ERROR_NOT_DEFINED;
        return 0;
    }
};
#endif // _CEVCPSERVLETCONTEXT_HPP
