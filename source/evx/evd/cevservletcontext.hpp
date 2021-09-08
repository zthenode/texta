///////////////////////////////////////////////////////////////////////
//   File: cevservletcontext.hpp
//
// Author: $author$
//   Date: 4/30/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVSERVLETCONTEXT_HPP
#define _CEVSERVLETCONTEXT_HPP

#include "evservletcontext.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvServletContext
//
// Author: $author$
//   Date: 4/30/2007
///////////////////////////////////////////////////////////////////////
class CEvServletContext
: virtual public EvServletContext
{
public:
    typedef EvServletContext CImplements;
    typedef CEvServletContext CDerives;

    const EvServlet& m_servlet;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvServletContext
    //
    //       Author: $author$
    //         Date: 4/30/2007
    ///////////////////////////////////////////////////////////////////////
    CEvServletContext(const EvServlet& servlet) 
    : m_servlet(servlet)
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
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetServlet
    //
    //   Author: $author$
    //     Date: 4/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const EvServlet& GetServlet() const 
    {
        return m_servlet;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: DeleteInstance
    //
    //   Author: $author$
    //     Date: 6/3/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError DeleteInstance()
    {
        return DeleteThis();
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: DeleteThis
    //
    //   Author: $author$
    //     Date: 6/3/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError DeleteThis()
    {
        return EV_ERROR_NOT_ALLOWED;
    }
};
#endif // _CEVSERVLETCONTEXT_HPP
