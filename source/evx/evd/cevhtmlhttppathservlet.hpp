///////////////////////////////////////////////////////////////////////
//   File: cevhtmlhttppathservlet.hpp
//
// Author: $author$
//   Date: 6/12/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVHTMLHTTPPATHSERVLET_HPP
#define _CEVHTMLHTTPPATHSERVLET_HPP

#include "cevhttppathservlet.hpp"

#define DEFAULT_CEVHTMLHTTPPATHSERVLET_NAME "html"

///////////////////////////////////////////////////////////////////////
//  Class: CEvHtmlHttpPathServlet
//
// Author: $author$
//   Date: 6/12/2007
///////////////////////////////////////////////////////////////////////
class CEvHtmlHttpPathServlet
: public CEvHttpPathServlet
{
public:
    typedef CEvHttpPathServlet CExtends;
    typedef CEvHtmlHttpPathServlet CDerives;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvHtmlHttpPathServlet
    //
    //       Author: $author$
    //         Date: 6/12/2007
    ///////////////////////////////////////////////////////////////////////
    CEvHtmlHttpPathServlet
    (const char* name=DEFAULT_CEVHTMLHTTPPATHSERVLET_NAME,
     LONG length=-1) 
    : CExtends(name, length)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvHtmlHttpPathServlet
    //
    //      Author: $author$
    //        Date: 6/12/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvHtmlHttpPathServlet()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Initialize
    //
    //   Author: $author$
    //     Date: 6/12/2007
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
    //     Date: 6/12/2007
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
    //     Date: 6/12/2007
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

#endif // _CEVHTMLHTTPPATHSERVLET_HPP
