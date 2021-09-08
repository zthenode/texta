///////////////////////////////////////////////////////////////////////
//   File: cevputevcpservlet.hpp
//
// Author: $author$
//   Date: 10/4/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVPUTEVCPSERVLET_HPP
#define _CEVPUTEVCPSERVLET_HPP

#include "cevcontextedevcpservlet.hpp"
#include "cevputcontextevcpservlet.hpp"

#define DEFAULT_CEVPUTEVCPSERVLET_NAME "PUT"

///////////////////////////////////////////////////////////////////////
//  Class: CEvPutEvcpServlet
//
// Author: $author$
//   Date: 10/4/2007
///////////////////////////////////////////////////////////////////////
class CEvPutEvcpServlet
: public CEvContextedEvcpServlet
{
public:
    typedef CEvContextedEvcpServlet CExtends;
    typedef CEvPutEvcpServlet CDerives;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvPutEvcpServlet
    //
    //       Author: $author$
    //         Date: 10/4/2007
    ///////////////////////////////////////////////////////////////////////
    CEvPutEvcpServlet
    (const char* name=DEFAULT_CEVPUTEVCPSERVLET_NAME,
     LONG length=-1) 
    : CExtends(name, length)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvPutEvcpServlet
    //
    //      Author: $author$
    //        Date: 10/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvPutEvcpServlet()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Initialize
    //
    //   Author: $author$
    //     Date: 10/4/2007
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
    //     Date: 10/4/2007
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
            context = new CEvPutContextEvcpServlet(chars, length);
        return context;
    }
};

#endif // _CEVPUTEVCPSERVLET_HPP
