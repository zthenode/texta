///////////////////////////////////////////////////////////////////////
//   File: cevposthttpservlet.hpp
//
// Author: $author$
//   Date: 4/26/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVPOSTHTTPSERVLET_HPP
#define _CEVPOSTHTTPSERVLET_HPP

#include "cevcpservlet.hpp"
#include "cevcpservlets.hpp"
#include "cevstringwriter.hpp"

#define DEFAULT_CEVPOSTHTTPSERVLET_NAME "POST"

///////////////////////////////////////////////////////////////////////
//  Class: CEvPostHttpServlet
//
// Author: $author$
//   Date: 4/26/2007
///////////////////////////////////////////////////////////////////////
class CEvPostHttpServlet
: public CEvcpServlet
{
public:
    typedef CEvcpServlet CExtends;
    typedef CEvPostHttpServlet CDerives;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvPostHttpServlet
    //
    //       Author: $author$
    //         Date: 4/26/2007
    ///////////////////////////////////////////////////////////////////////
    CEvPostHttpServlet
    (const char* name=DEFAULT_CEVPOSTHTTPSERVLET_NAME) 
    {
        EvError error;

        if (name)
        if ((error = SetName(name)))
            throw(error);
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvPostHttpServlet
    //
    //      Author: $author$
    //        Date: 4/26/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvPostHttpServlet()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Initialize
    //
    //   Author: $author$
    //     Date: 4/26/2007
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
    //     Date: 4/26/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Finalize(EvServletServer& server) 
    {
        EvError error = EV_ERROR_NONE;
        DBF("() in...\n");
        DBF("() ...out\n");
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Service
    //
    //   Author: $author$
    //     Date: 4/26/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Service
    (EvcpServletRequest& request,
     EvcpServletResponse& response) 
    {
        EvError error = EV_ERROR_NONE;
        EvCharReader& reader = request.GetReader();
        EvcpHeader& reqHeader = request.GetHeader();
        EvcpHeaderHeading& reqHeading = reqHeader.GetHeading();

        DBF("() in...\n");
        DBF("() ...out\n");
        return error;
    }
};
#endif // _CEVPOSTHTTPSERVLET_HPP
