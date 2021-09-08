///////////////////////////////////////////////////////////////////////
//   File: cevservletallocator.hpp
//
// Author: $author$
//   Date: 4/21/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVSERVLETALLOCATOR_HPP
#define _CEVSERVLETALLOCATOR_HPP

#include <vector>
#include "evservletallocator.hpp"

///////////////////////////////////////////////////////////////////////
//  Typedef: EvServletVector
//
//   Author: $author$
//     Date: 4/13/2007
///////////////////////////////////////////////////////////////////////
typedef std::vector<EvServlet*>
EvServletVector;

///////////////////////////////////////////////////////////////////////
//  Class: CEvServletAllocator
//
// Author: $author$
//   Date: 4/21/2007
///////////////////////////////////////////////////////////////////////
class CEvServletAllocator
: virtual public EvServletAllocator
{
public:
    typedef EvServletAllocator CImplements;
    typedef CEvServletAllocator CDerives;

    EvServletVector m_servlets;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvServletAllocator
    //
    //       Author: $author$
    //         Date: 4/21/2007
    ///////////////////////////////////////////////////////////////////////
    CEvServletAllocator() 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvServletAllocator
    //
    //      Author: $author$
    //        Date: 4/21/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvServletAllocator()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Initialize
    //
    //   Author: $author$
    //     Date: 4/13/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Initialize() 
    {
        EvError error = EV_ERROR_NONE;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Finalize
    //
    //   Author: $author$
    //     Date: 4/13/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Finalize() 
    {
        EvError error = ReleaseAllServlets();
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: ReleaseAllServlets
    //
    //   Author: $author$
    //     Date: 4/13/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ReleaseAllServlets() 
    {
        EvError error = EV_ERROR_NONE;
        EvError error2;
        EvServletVector::iterator i;
        EvServlet* servlet;

        for (i = m_servlets.begin(); i != m_servlets.end(); i++)
        {
            if ((servlet = *i))
            if ((error2 = servlet->DeleteInstance()))
            if (!error)
                error = error2;
        }
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ReleaseServlet
    //
    //   Author: $author$
    //     Date: 4/21/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ReleaseServlet(EvServlet& servlet) 
    {
        EvError error;
        
        if (!(error = RemoveServlet(servlet)))
            error = servlet.DeleteInstance();
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: AddServlet
    //
    //   Author: $author$
    //     Date: 4/13/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError AddServlet(EvServlet& servlet) 
    {
        EvError error = EV_ERROR_NONE;
        m_servlets.push_back(&servlet);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: RemoveServlet
    //
    //   Author: $author$
    //     Date: 4/13/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError RemoveServlet(EvServlet& servlet) 
    {
        EvError error = EV_ERROR_FAILED;
        EvServletVector::iterator i;

        for (i = m_servlets.begin(); i != m_servlets.end(); i++)
        {
            if (&servlet == *i)
            {
                m_servlets.erase(i);
                return EV_ERROR_NONE;
            }
        }
        return error;
    }
};

#endif // _CEVSERVLETALLOCATOR_HPP
