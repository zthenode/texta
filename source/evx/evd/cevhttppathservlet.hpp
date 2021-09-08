///////////////////////////////////////////////////////////////////////
//   File: cevhttppathservlet.hpp
//
// Author: $author$
//   Date: 6/12/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVHTTPPATHSERVLET_HPP
#define _CEVHTTPPATHSERVLET_HPP

#include "evhttppathservlet.hpp"
#include "cevcpservlet.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvHttpPathServlet
//
// Author: $author$
//   Date: 6/12/2007
///////////////////////////////////////////////////////////////////////
class CEvHttpPathServlet
: virtual public EvHttpPathServlet,
  public CEvcpServlet
{
public:
    typedef EvHttpPathServlet CImplements;
    typedef CEvcpServlet CExtends;
    typedef CEvHttpPathServlet CDerives;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvHttpPathServlet
    //
    //       Author: $author$
    //         Date: 6/12/2007
    ///////////////////////////////////////////////////////////////////////
    CEvHttpPathServlet
    (const char* name, LONG length=-1) 
    : CExtends(name, length)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvHttpPathServlet
    //
    //      Author: $author$
    //        Date: 6/12/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvHttpPathServlet()
    {
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

#endif // _CEVHTTPPATHSERVLET_HPP
