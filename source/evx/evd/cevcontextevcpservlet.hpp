///////////////////////////////////////////////////////////////////////
//   File: cevcontextevcpservlet.hpp
//
// Author: $author$
//   Date: 9/21/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCONTEXTEVCPSERVLET_HPP
#define _CEVCONTEXTEVCPSERVLET_HPP

#include "cevcpservlet.hpp"
#include "cevcpservlets.hpp"
#include "cevstringwriter.hpp"
#include "evdebug_error.h"

#define DEFAULT_CEVCONTEXTEVCPSERVLET_NAME "CONTEXT"

///////////////////////////////////////////////////////////////////////
//  Class: CEvContextEvcpServlet
//
// Author: $author$
//   Date: 9/21/2007
///////////////////////////////////////////////////////////////////////
class CEvContextEvcpServlet
: public CEvcpServlet
{
public:
    typedef CEvcpServlet CExtends;
    typedef CEvContextEvcpServlet CDerives;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvContextEvcpServlet
    //
    //       Author: $author$
    //         Date: 9/21/2007
    ///////////////////////////////////////////////////////////////////////
    CEvContextEvcpServlet
    (const char* name=DEFAULT_CEVCONTEXTEVCPSERVLET_NAME,
     LONG length=-1) 
    : CExtends(name, length)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvContextEvcpServlet
    //
    //      Author: $author$
    //        Date: 9/21/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvContextEvcpServlet()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Initialize
    //
    //   Author: $author$
    //     Date: 9/21/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Initialize(EvServletServer& server) 
    {
        EvError error = EV_ERROR_NOT_ALLOWED;
        DBE_ERROR_NOT_ALLOWED;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Finalize
    //
    //   Author: $author$
    //     Date: 9/21/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Finalize(EvServletServer& server) 
    {
        EvError error = EV_ERROR_NOT_ALLOWED;
        DBE_ERROR_NOT_ALLOWED;
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Service
    //
    //   Author: $author$
    //     Date: 9/21/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Service
    (EvcpServletRequest& request,
     EvcpServletResponse& response) 
    {
        EvError error = EV_ERROR_NOT_ALLOWED;
        DBE_ERROR_NOT_ALLOWED;
        return error;
    }
};

#endif // _CEVCONTEXTEVCPSERVLET_HPP
