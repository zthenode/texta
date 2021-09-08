///////////////////////////////////////////////////////////////////////
//   File: cevgethttpservlet.hpp
//
// Author: $author$
//   Date: 4/26/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVGETHTTPSERVLET_HPP
#define _CEVGETHTTPSERVLET_HPP

#include "cevcpservlet.hpp"
#include "cevcpservlets.hpp"
#include "cevstringwriter.hpp"

#define DEFAULT_CEVGETHTTPSERVLET_NAME "GET"

///////////////////////////////////////////////////////////////////////
//  Class: CEvGetHttpServlet
//
// Author: $author$
//   Date: 4/26/2007
///////////////////////////////////////////////////////////////////////
class CEvGetHttpServlet
: public CEvcpServlet
{
public:
    typedef CEvcpServlet CExtends;
    typedef CEvGetHttpServlet CDerives;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvGetHttpServlet
    //
    //       Author: $author$
    //         Date: 4/26/2007
    ///////////////////////////////////////////////////////////////////////
    CEvGetHttpServlet
    (const char* name=DEFAULT_CEVGETHTTPSERVLET_NAME, 
     LONG length=-1) 
    : CExtends(name, length) 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvGetHttpServlet
    //
    //      Author: $author$
    //        Date: 4/26/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvGetHttpServlet()
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

#endif // _CEVGETHTTPSERVLET_HPP
