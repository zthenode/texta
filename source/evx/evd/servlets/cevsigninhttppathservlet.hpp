///////////////////////////////////////////////////////////////////////
//   File: cevsigninhttppathservlet.hpp
//
// Author: $author$
//   Date: 2/1/2012
///////////////////////////////////////////////////////////////////////

#ifndef _CEVSIGNINHTTPPATHSERVLET_HPP
#define _CEVSIGNINHTTPPATHSERVLET_HPP


#include "cevhttppathservlet.hpp"
#include "cevcpservlets.hpp"
#include "cevstringwriter.hpp"

#define DEFAULT_CEVSIGNINHTTPPATHSERVLET_NAME "sign_in"

///////////////////////////////////////////////////////////////////////
//  Class: CEvSignInHttpPathServlet
//
// Author: $author$
//   Date: 2/1/2012
///////////////////////////////////////////////////////////////////////
class CEvSignInHttpPathServlet
: public CEvHttpPathServlet
{
public:
    typedef CEvHttpPathServlet CExtends;
    typedef CEvSignInHttpPathServlet CDerives;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvSignInHttpPathServlet
    //
    //       Author: $author$
    //         Date: 2/1/2012
    ///////////////////////////////////////////////////////////////////////
    CEvSignInHttpPathServlet
    (const char* name=DEFAULT_CEVSIGNINHTTPPATHSERVLET_NAME,
     LONG length=-1) 
    : CExtends(name, length)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvSignInHttpPathServlet
    //
    //      Author: $author$
    //        Date: 2/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvSignInHttpPathServlet()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Initialize
    //
    //   Author: $author$
    //     Date: 2/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Initialize() 
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
    //     Date: 2/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Finalize() 
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
    //     Date: 2/1/2012
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

#endif // _CEVSIGNINHTTPPATHSERVLET_HPP

        

