///////////////////////////////////////////////////////////////////////
//   File: cevloginevcpservlet.hpp
//
// Author: $author$
//   Date: 10/13/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVLOGINEVCPSERVLET_HPP
#define _CEVLOGINEVCPSERVLET_HPP

#include "cevlogincontextevcpservlet.hpp"
#include "cevcontextedevcpservlet.hpp"

#define DEFAULT_CEVLOGINEVCPSERVLET_NAME "LOGIN"

///////////////////////////////////////////////////////////////////////
//  Class: CEvLoginEvcpServlet
//
// Author: $author$
//   Date: 10/13/2007
///////////////////////////////////////////////////////////////////////
class CEvLoginEvcpServlet
: public CEvContextedEvcpServlet
{
public:
    typedef CEvContextedEvcpServlet CExtends;
    typedef CEvLoginEvcpServlet CDerives;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvLoginEvcpServlet
    //
    //       Author: $author$
    //         Date: 10/13/2007
    ///////////////////////////////////////////////////////////////////////
    CEvLoginEvcpServlet
    (const char* name=DEFAULT_CEVLOGINEVCPSERVLET_NAME,
     LONG length=-1) 
    : CExtends(name, length)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvLoginEvcpServlet
    //
    //      Author: $author$
    //        Date: 10/13/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvLoginEvcpServlet()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Initialize
    //
    //   Author: $author$
    //     Date: 10/13/2007
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
    //     Date: 10/13/2007
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
    //     Date: 10/13/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvcpServlet* NewEvcpServletContext
    (EvcpServletConnection& connection) 
    {
        EvcpServlet* context = 0;
        const char* chars;
        LONG length;

        if ((chars = GetName(length)))
            context = new CEvLoginContextEvcpServlet
            (chars, length);
        return context;
    }
};

#endif // _CEVLOGINEVCPSERVLET_HPP
