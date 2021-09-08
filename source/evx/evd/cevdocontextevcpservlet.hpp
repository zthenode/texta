///////////////////////////////////////////////////////////////////////
//   File: cevdocontextevcpservlet.hpp
//
// Author: $author$
//   Date: 10/8/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVDOCONTEXTEVCPSERVLET_HPP
#define _CEVDOCONTEXTEVCPSERVLET_HPP

#include "cevcsarchivecontextevcpservlet.hpp"

#define DEFAULT_CEVDOCONTEXTEVCPSERVLET_NAME "DO_CONTEXT"

///////////////////////////////////////////////////////////////////////
//  Class: CEvDoContextEvcpServlet
//
// Author: $author$
//   Date: 10/8/2007
///////////////////////////////////////////////////////////////////////
class CEvDoContextEvcpServlet
: public CEvcsArchiveContextEvcpServlet
{
public:
    typedef CEvcsArchiveContextEvcpServlet CExtends;
    typedef CEvDoContextEvcpServlet CDerives;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvDoContextEvcpServlet
    //
    //       Author: $author$
    //         Date: 10/8/2007
    ///////////////////////////////////////////////////////////////////////
    CEvDoContextEvcpServlet
    (const char* name=DEFAULT_CEVDOCONTEXTEVCPSERVLET_NAME,
     LONG length=-1) 
    : CExtends(name, length)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvDoContextEvcpServlet
    //
    //      Author: $author$
    //        Date: 10/8/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvDoContextEvcpServlet()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Service
    //
    //   Author: $author$
    //     Date: 10/8/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Service
    (EvcpServletRequest& request,
     EvcpServletResponse& response) 
    {
        EvError error = EV_ERROR_NONE;
        EvcpStatus status = EVCP_STATUS_INTERNAL_SERVER_ERROR;
        EvCharReader& reader = request.GetReader();
        EvcpHeader& reqHeader = request.GetHeader();
        EvcpHeaderHeading& reqHeading = reqHeader.GetHeading();
        EvCharWriter& writer = response.GetWriter();
        EvcpHeader& respHeader = response.GetHeader();
        EvcpHeaderHeading& respHeading = respHeader.GetHeading();
        EvcpServletConnection& connection = response.GetEvcpConnection();
        const char* chars;
        LONG length;
        int unequal;
        EvError error2;

        DBF("() in...\n");

        if (!(chars = reqHeading.
            GetRequestPath(length)) || (0 >= length))
            DBE("() missing or invalid request path\n");

        else
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
                    else if (!(error2 = m_archive->CancelDo()))
                            status = EVCP_STATUS_OK;
                }
                else if (!(error2 = m_archive->FinishDo()))
                        status = EVCP_STATUS_OK;
            }
            else if (!(error2 = m_archive->Do()))
                    status = EVCP_STATUS_OK;
        }
        RespondStatus(response, status);
        DBF("() ...out\n");
        return error;
    }
};

#endif // _CEVDOCONTEXTEVCPSERVLET_HPP
