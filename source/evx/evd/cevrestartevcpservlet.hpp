///////////////////////////////////////////////////////////////////////
//   File: cevrestartevcpservlet.hpp
//
// Author: $author$
//   Date: 8/5/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVRESTARTEVCPSERVLET_HPP
#define _CEVRESTARTEVCPSERVLET_HPP

#include "cevcpservlet.hpp"
#include "cevcpservlets.hpp"
#include "cevstringwriter.hpp"

#define DEFAULT_CEVRESTARTEVCPSERVLET_NAME "RESTART"

///////////////////////////////////////////////////////////////////////
//  Class: CEvRestartEvcpServlet
//
// Author: $author$
//   Date: 8/5/2007
///////////////////////////////////////////////////////////////////////
class CEvRestartEvcpServlet
: public CEvcpServlet
{
public:
    typedef CEvcpServlet CExtends;
    typedef CEvRestartEvcpServlet CDerives;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvRestartEvcpServlet
    //
    //       Author: $author$
    //         Date: 8/5/2007
    ///////////////////////////////////////////////////////////////////////
    CEvRestartEvcpServlet
    (const char* name=DEFAULT_CEVRESTARTEVCPSERVLET_NAME,
     LONG length=-1) 
    : CExtends(name, length)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvRestartEvcpServlet
    //
    //      Author: $author$
    //        Date: 8/5/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvRestartEvcpServlet()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Initialize
    //
    //   Author: $author$
    //     Date: 8/5/2007
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
    //     Date: 8/5/2007
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
    //     Date: 8/5/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Service
    (EvcpServletRequest& request,
     EvcpServletResponse& response) 
    {
        EvError error = EV_ERROR_NONE;
        EvServletConnection& connection = request.GetConnection();
        EvServletServer& server = connection.GetServer();
        EvCharWriter& writer = response.GetWriter();
        const char* chars;
        LONG length;

        DBF("() in...\n");

        m_chars.Clear();

        RespondStatusCode
        (m_charsWriter, response, 
         EVCP_STATUS_CODE_OK, 
         EVCP_STATUS_DESC_OK);

        if ((chars = m_chars.Chars(length)))
            DBF("() --> \"%s\"\n", chars);

        writer.Write(chars, length);

        if ((error = server.Restart()))
            DBE("() server restart failed\n");

        DBF("() ...out\n");
        return error;
    }
};

#endif // _CEVRESTARTEVCPSERVLET_HPP
