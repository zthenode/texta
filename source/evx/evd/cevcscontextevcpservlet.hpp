///////////////////////////////////////////////////////////////////////
//   File: cevcscontextevcpservlet.hpp
//
// Author: $author$
//   Date: 9/21/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCSCONTEXTEVCPSERVLET_HPP
#define _CEVCSCONTEXTEVCPSERVLET_HPP

#include "cevcontextevcpservlet.hpp"
#include "cevcpservlet.hpp"
#include "cevcpservlets.hpp"
#include "cevstringwriter.hpp"

#define DEFAULT_CEVCSCONTEXTEVCPSERVLET_NAME "CEVCS_CONTEXT"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcsContextEvcpServlet
//
// Author: $author$
//   Date: 9/21/2007
///////////////////////////////////////////////////////////////////////
class CEvcsContextEvcpServlet
: public CEvContextEvcpServlet
{
public:
    typedef CEvContextEvcpServlet CExtends;
    typedef CEvcsContextEvcpServlet CDerives;

    EvcpServlet* m_servletParentContext;
    Evcs* m_evcs;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcsContextEvcpServlet
    //
    //       Author: $author$
    //         Date: 9/21/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcsContextEvcpServlet
    (const char* name=DEFAULT_CEVCSCONTEXTEVCPSERVLET_NAME,
     LONG length=-1) 
    : CExtends(name, length),
      m_servletParentContext(0),
      m_evcs(0)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvcsContextEvcpServlet
    //
    //      Author: $author$
    //        Date: 9/21/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvcsContextEvcpServlet()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: ConnectionInitialize
    //
    //   Author: $author$
    //     Date: 9/21/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ConnectionInitialize
    (EvcpServletConnection& connection) 
    {
        EvError error = EV_ERROR_FAILED;
        EvError error2;

        DBF("() in...\n");

        if ((m_servletParentContext = GetServletParentContext(connection)))
        if ((m_evcs = m_servletParentContext->AcquireEvcs(error2)))
            error = EV_ERROR_NONE;

        DBF("() ...out\n");
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ConnectionFinalize
    //
    //   Author: $author$
    //     Date: 9/21/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ConnectionFinalize
    (EvcpServletConnection& connection) 
    {
        EvError error = EV_ERROR_NONE;

        DBF("() in...\n");

        m_evcs = 0;
        m_servletParentContext = 0;

        DBF("() ...out\n");
        return error;
    }
};

#endif // _CEVCSCONTEXTEVCPSERVLET_HPP
