///////////////////////////////////////////////////////////////////////
//   File: cevstopevcpservlet.hpp
//
// Author: $author$
//   Date: 5/11/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVSTOPEVCPSERVLET_HPP
#define _CEVSTOPEVCPSERVLET_HPP

#include "cevcpservlet.hpp"
#include "cevcpservlets.hpp"
#include "cevstringwriter.hpp"

#define DEFAULT_CEVSTOPEVCPSERVLET_NAME EVCP_REQUEST_ACTION_NAME_STOP

///////////////////////////////////////////////////////////////////////
//  Class: CEvStopEvcpServlet
//
// Author: $author$
//   Date: 5/11/2007
///////////////////////////////////////////////////////////////////////
class CEvStopEvcpServlet
: public CEvcpServlet
{
public:
    typedef CEvcpServlet CExtends;
    typedef CEvStopEvcpServlet CDerives;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvStopEvcpServlet
    //
    //       Author: $author$
    //         Date: 5/11/2007
    ///////////////////////////////////////////////////////////////////////
    CEvStopEvcpServlet
    (const char* name=DEFAULT_CEVSTOPEVCPSERVLET_NAME,
     LONG length=-1) 
    : CExtends(name, length)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvStopEvcpServlet
    //
    //      Author: $author$
    //        Date: 5/11/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvStopEvcpServlet()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Initialize
    //
    //   Author: $author$
    //     Date: 5/11/2007
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
    //     Date: 5/11/2007
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
    //     Date: 5/11/2007
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

        if ((error = server.End()))
            DBE("() server end failed\n");

        DBF("() ...out\n");
        return error;
    }
};

#endif // _CEVSTOPEVCPSERVLET_HPP
