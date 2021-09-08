///////////////////////////////////////////////////////////////////////
//   File: cevdoevcpservlet.hpp
//
// Author: $author$
//   Date: 5/23/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVDOEVCPSERVLET_HPP
#define _CEVDOEVCPSERVLET_HPP

#include "cevcpservlet.hpp"
#include "cevcpservlets.hpp"
#include "cevstringwriter.hpp"
#include "evcs.hpp"

#define DEFAULT_CEVDOEVCPSERVLET_NAME EVCP_REQUEST_ACTION_NAME_DO

///////////////////////////////////////////////////////////////////////
//  Class: CEvDoEvcpServlet
//
// Author: $author$
//   Date: 5/23/2007
///////////////////////////////////////////////////////////////////////
class CEvDoEvcpServlet
: public CEvcpServlet
{
public:
    typedef CEvcpServlet CExtends;
    typedef CEvDoEvcpServlet CDerives;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvDoEvcpServlet
    //
    //       Author: $author$
    //         Date: 5/23/2007
    ///////////////////////////////////////////////////////////////////////
    CEvDoEvcpServlet
    (const char* name=DEFAULT_CEVDOEVCPSERVLET_NAME,
     LONG length=-1) 
    : CExtends(name, length)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvDoEvcpServlet
    //
    //      Author: $author$
    //        Date: 5/23/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvDoEvcpServlet()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Service
    //
    //   Author: $author$
    //     Date: 5/23/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Service
    (EvcpServletRequest& request,
     EvcpServletResponse& response) 
    {
        EvError error = EV_ERROR_NONE;
        EvcpStatus status = EVCP_STATUS_INTERNAL_SERVER_ERROR;
        //EvCharReader& reader = request.GetReader();
        EvcpHeader& reqHeader = request.GetHeader();
        EvcpHeaderHeading& reqHeading = reqHeader.GetHeading();
        EvcpServletConnection& connection = response.GetEvcpConnection();
        Evcs* evcs = 0;
        EvcpServlet* context;
        EvcpServlet* parent;
        EvError error2;
        const char* chars;
        LONG length;
        int unequal;

        DBF("() in...\n");

        if ((parent = GetParentEvcpServlet(error2)))
        if ((context = parent->GetEvcpServletContext(connection)))
        if ((evcs = context->AcquireEvcs(error2)))
        if ((chars = reqHeading.GetRequestPath(length)))
        if (0 < length)
        {
            DBT("() do \"%s\"\n", chars);

            if ((unequal = reqHeading.CompareRequestPath
                (EVCP_REQUEST_ACTION_ARGUMENT_NAME_BEGIN)))
            {
                if ((unequal = reqHeading.CompareRequestPath
                    (EVCP_REQUEST_ACTION_ARGUMENT_NAME_END)))
                {
                    if ((unequal = reqHeading.CompareRequestPath
                        (EVCP_REQUEST_ACTION_ARGUMENT_NAME_CANCEL)))
                    {
                        DBE("() invalid request argument\n");
                        status = EVCP_STATUS_BAD_REQUEST;
                    }
                    else if (!(error = evcs->CancelOp()))
                            status = EVCP_STATUS_OK;
                }
                else if (!(error = evcs->FinishOp()))
                        status = EVCP_STATUS_OK;
            }
            else if (!(error = evcs->StartDoOp()))
                    status = EVCP_STATUS_OK;
        }

        SetKeepAlive(request, response);
        RespondStatus(response, status);

        DBF("() ...out\n");
        return error;
    }
};

#endif // _CEVDOEVCPSERVLET_HPP
