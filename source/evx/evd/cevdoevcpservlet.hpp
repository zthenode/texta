///////////////////////////////////////////////////////////////////////
//   File: cevdoevcpservlet.hpp
//
// Author: $author$
//   Date: 10/8/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVDOEVCPSERVLET_HPP
#define _CEVDOEVCPSERVLET_HPP

#include "cevcontextedevcpservlet.hpp"
#include "cevdocontextevcpservlet.hpp"

#define DEFAULT_CEVDOEVCPSERVLET_NAME "DO"

///////////////////////////////////////////////////////////////////////
//  Class: CEvDoEvcpServlet
//
// Author: $author$
//   Date: 10/8/2007
///////////////////////////////////////////////////////////////////////
class CEvDoEvcpServlet
: public CEvContextedEvcpServlet
{
public:
    typedef CEvContextedEvcpServlet CExtends;
    typedef CEvDoEvcpServlet CDerives;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvDoEvcpServlet
    //
    //       Author: $author$
    //         Date: 10/8/2007
    ///////////////////////////////////////////////////////////////////////
    CEvDoEvcpServlet
    (const char* name=DEFAULT_CEVDOEVCPSERVLET_NAME,
     LONG length=-1) 
    : CExtends(name, length)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvDoEvcpServlet
    //
    //      Author: $author$
    //        Date: 10/8/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvDoEvcpServlet()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Initialize
    //
    //   Author: $author$
    //     Date: 10/8/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Initialize(EvServletServer& server) 
    {
        EvError error = EV_ERROR_NONE;
        DBF("() in...\n");
        DBF("() ...out\n");
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Finalize
    //
    //   Author: $author$
    //     Date: 10/8/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Finalize(EvServletServer& server) 
    {
        EvError error = EV_ERROR_NONE;
        DBF("() in...\n");
        DBF("() ...out\n");
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: NewEvcpServletContext
    //
    //   Author: $author$
    //     Date: 10/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvcpServlet* NewEvcpServletContext
    (EvcpServletConnection& connection) 
    {
        EvcpServlet* context = 0;
        const char* chars;
        LONG length;

        if ((chars = GetName(length)))
            context = new CEvDoContextEvcpServlet(chars, length);
        return context;
    }
};

#endif // _CEVDOEVCPSERVLET_HPP
