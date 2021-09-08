///////////////////////////////////////////////////////////////////////
//   File: cevcsservlet.hpp
//
// Author: $author$
//   Date: 12/26/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCSSERVLET_HPP
#define _CEVCSSERVLET_HPP

#include "evservlet.hpp"
#include "cevcpservlet.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcsServlet
//
// Author: $author$
//   Date: 12/26/2007
///////////////////////////////////////////////////////////////////////
class CEvcsServlet
: public CEvcpServlet
{
public:
    typedef CEvcpServlet CExtends;
    typedef CEvcsServlet CDerives;
    
    EvcpServlet* m_servletParentContext;
    Evcs* m_evcs;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcsServlet
    //
    //       Author: $author$
    //         Date: 12/25/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcsServlet
    (const char* name,
     LONG length=-1) 
    : CExtends(name, length),
      m_servletParentContext(0),
      m_evcs(0) 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvcsServlet
    //
    //      Author: $author$
    //        Date: 12/25/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvcsServlet()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: ConnectionInitialize
    //
    //   Author: $author$
    //     Date: 12/26/2007
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
    //     Date: 12/26/2007
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

#endif // _CEVCSSERVLET_HPP
