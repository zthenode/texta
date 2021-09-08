///////////////////////////////////////////////////////////////////////
//   File: cevgetevcpservlet.hpp
//
// Author: $author$
//   Date: 9/28/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVGETEVCPSERVLET_HPP
#define _CEVGETEVCPSERVLET_HPP

#include "cevcontextedevcpservlet.hpp"
#include "cevgetcontextevcpservlet.hpp"

#define DEFAULT_CEVGETEVCPSERVLET_NAME "GET"

///////////////////////////////////////////////////////////////////////
//  Class: CEvGetEvcpServlet
//
// Author: $author$
//   Date: 9/28/2007
///////////////////////////////////////////////////////////////////////
class CEvGetEvcpServlet
: public CEvContextedEvcpServlet
{
public:
    typedef CEvContextedEvcpServlet CExtends;
    typedef CEvGetEvcpServlet CDerives;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvGetEvcpServlet
    //
    //       Author: $author$
    //         Date: 9/28/2007
    ///////////////////////////////////////////////////////////////////////
    CEvGetEvcpServlet
    (const char* name=DEFAULT_CEVGETEVCPSERVLET_NAME,
     LONG length=-1) 
    : CExtends(name, length)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvGetEvcpServlet
    //
    //      Author: $author$
    //        Date: 9/28/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvGetEvcpServlet()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Initialize
    //
    //   Author: $author$
    //     Date: 9/28/2007
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
    //     Date: 9/28/2007
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
    //     Date: 9/28/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvcpServlet* NewEvcpServletContext
    (EvcpServletConnection& connection) 
    {
        EvcpServlet* context = 0;
        const char* chars;
        LONG length;

        if ((chars = GetName(length)))
            context = new CEvGetContextEvcpServlet(chars, length);
        return context;
    }
};

#endif // _CEVGETEVCPSERVLET_HPP
