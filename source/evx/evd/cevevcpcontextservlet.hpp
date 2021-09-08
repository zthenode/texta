///////////////////////////////////////////////////////////////////////
//   File: cevevcpcontextservlet.hpp
//
// Author: $author$
//   Date: 9/20/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVEVCPCONTEXTSERVLET_HPP
#define _CEVEVCPCONTEXTSERVLET_HPP

#include "cevcontextevcpservlet.hpp"
#include "cevcpservlets.hpp"
#include "evcsacquired.hpp"
#include "evcsallocator.hpp"
#include "cevcs.hpp"

#define DEFAULT_CEVEVCPCONTEXTSERVLET_NAME "EVCP_CONTEXT"

///////////////////////////////////////////////////////////////////////
//  Class: CEvEvcpContextServlet
//
// Author: $author$
//   Date: 9/20/2007
///////////////////////////////////////////////////////////////////////
class CEvEvcpContextServlet
: public CEvContextEvcpServlet
{
public:
    typedef CEvContextEvcpServlet CExtends;
    typedef CEvEvcpContextServlet CDerives;

    EvcsAcquired m_acquired;
    Evcs* m_evcs;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvEvcpContextServlet
    //
    //       Author: $author$
    //         Date: 9/20/2007
    ///////////////////////////////////////////////////////////////////////
    CEvEvcpContextServlet
    (const char* name=DEFAULT_CEVEVCPCONTEXTSERVLET_NAME,
     LONG length=-1) 
    : CExtends(name, length),
      m_evcs(0)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvEvcpContextServlet
    //
    //      Author: $author$
    //        Date: 9/20/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvEvcpContextServlet()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: ConnectionInitialize
    //
    //   Author: $author$
    //     Date: 9/20/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ConnectionInitialize
    (EvcpServletConnection& connection) 
    {
        EvError error = EV_ERROR_NONE;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ConnectionFinalize
    //
    //   Author: $author$
    //     Date: 9/20/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ConnectionFinalize
    (EvcpServletConnection& connection) 
    {
        EvError error = EV_ERROR_NONE;
        EvError error2;
        EvcsAcquiredIterator i;
        Evcs* acquiredEvcs;

        for (i = m_acquired.begin();
             i != m_acquired.end(); i++)
        {
            if ((acquiredEvcs = *i))
            if ((error2 = ReleaseAcquiredEvcs(*acquiredEvcs)))
                error = EV_ERROR_FAILED;
        }

        m_acquired.clear();
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: AcquireEvcs
    //
    //   Author: $author$
    //     Date: 5/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual Evcs* AcquireEvcs
    (EvError& error, 
     const char* name=0, LONG length=-1) 
    {
        Evcs* evcs = 0;
        EvcsAllocator* allocator;
        EvError error2;

        error = EV_ERROR_FAILED;

        if (!name || !length)
            evcs = AcquireDefaultEvcs(error);

        else 
        {
            if ((allocator = EvcsAllocator::
                GetAllocator(error2, name,  length)))
            if ((evcs = allocator->AcquireEvcs(error2)))
            {
                m_acquired.push_back(evcs);
                error = EV_ERROR_NONE;
            }
        }
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
    // Function: AcquireDefaultEvcs
    //
    //   Author: $author$
    //     Date: 5/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual Evcs* AcquireDefaultEvcs(EvError& error) 
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
    // Function: ReleaseAcquiredEvcs
    //
    //   Author: $author$
    //     Date: 9/20/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ReleaseAcquiredEvcs(Evcs& evcs) 
    {
        EvError error = EV_ERROR_FAILED;
        EvcsAllocator* allocator;

        if ((allocator = evcs.GetAllocator()))
            error = allocator->ReleaseEvcs(evcs);
        return error;
    }
};

#endif // _CEVEVCPCONTEXTSERVLET_HPP
