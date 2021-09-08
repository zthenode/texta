///////////////////////////////////////////////////////////////////////
//   File: cevevcpservlet.hpp
//
// Author: $author$
//   Date: 4/23/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVEVCPSERVLET_HPP
#define _CEVEVCPSERVLET_HPP

#include "cevcpservletcontext.hpp"
#include "cevcpservlet.hpp"
#include "cevcpservlets.hpp"
#include "cevevcpservletallocatorfamily.hpp"
#include "cevstringwriter.hpp"

#define DEFAULT_CEVEVCPSERVLET_NAME "EVCP"

///////////////////////////////////////////////////////////////////////
//  Class: CEvEvcpServlet
//
// Author: $author$
//   Date: 4/23/2007
///////////////////////////////////////////////////////////////////////
class CEvEvcpServlet
: public CEvcpServlet
{
public:
    typedef CEvcpServlet CExtends;
    typedef CEvEvcpServlet CDerives;

    CEvcpServletContext m_evcpServletContext;
    CEvcpServlets m_actionServlets;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvEvcpServlet
    //
    //       Author: $author$
    //         Date: 4/23/2007
    ///////////////////////////////////////////////////////////////////////
    CEvEvcpServlet
    (const char* name=DEFAULT_CEVEVCPSERVLET_NAME,
     LONG length=-1) 
    : CExtends(name, length), 
      m_evcpServletContext(*this)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvEvcpServlet
    //
    //      Author: $author$
    //        Date: 4/23/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvEvcpServlet()
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
        EvError error2;
        CEvEvcpServletAllocatorItem* item;

        DBF("() in...\n");

        if ((error2 = m_evcpServletContext.Initialize()))
            return EV_ERROR_FAILED;

        if ((error2 = m_actionServlets.Clear()))
            return EV_ERROR_FAILED;

        for (item = CEvEvcpServletAllocatorList::GetFirstItem(); 
             item; item = item->GetNextItem())
        {
            EvcpServletAllocator& allocator = item->GetAllocator();
            EvcpServlet* servlet;

            if ((servlet = allocator.AcquireServlet(error2)))
            {
                servlet->SetParentEvcpServlet(this);

                if ((error = servlet->Initialize(server)))
                {
                    DBE("() failed to initialize servlet\n");
                    error = EV_ERROR_INITIALIZE;
                }
                else if ((error = m_actionServlets.AddServlet(*servlet)))
                {
                    DBE("() failed to add servlet\n");

                    if ((error2 = servlet->Finalize(server)))
                        DBE("() failed to finalize servlet\n");
                }
                else continue;

                if ((error2 = allocator.ReleaseServlet(*servlet)))
                    DBE("() failed to release servlet\n");
            }
            else 
            {
                DBE("() failed to acquire servlet\n");
                error = EV_ERROR_FAILED;
            }
            Finalize(server);
            break;
        }
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
        EvError error2;
        const_CEvcpServletsIterator i;
        EvcpServlet* servlet;

        DBF("() in...\n");
        for (i = m_actionServlets.end(); i != m_actionServlets.begin();)
        {
            if ((servlet = *(--i)))
            if ((error2 = servlet->Finalize(server)) && !error)
                error = EV_ERROR_FINALIZE;
        }
        if ((error2 = m_actionServlets.Clear()) && !error)
            error = EV_ERROR_FAILED;

        if ((error2 = m_evcpServletContext.Finalize()) && !error)
            error = EV_ERROR_FINALIZE;
        DBF("() ...out\n");
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Service
    //
    //   Author: $author$
    //     Date: 4/23/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Service
    (EvcpServletRequest& request,
     EvcpServletResponse& response) 
    {
        EvError error = EV_ERROR_FAILED;
        EvcpHeader& reqHeader = request.GetHeader();
        EvcpHeaderHeading& reqHeading = reqHeader.GetHeading();
        ULONG respStatusCode = EVCP_STATUS_CODE_INTERNAL_SERVER_ERROR;
        const char* respStatusDesc = EVCP_STATUS_DESC_INTERNAL_SERVER_ERROR;
        const char* actionChars;
        LONG actionLength;
        EvcpServlet* actionServlet;

        DBF("() in...\n");

        if ((actionChars = reqHeading.
            GetRequestAction(actionLength))
            && (0 < actionLength))
        {
            if ((actionServlet = m_actionServlets.
                FindServlet(actionChars)))
            {
                if ((error = actionServlet->Service(request, response)))
                    DBE("() servlet \"%s\" failed \n", actionChars);
            }
            else DBE("() unable to find servlet \"%s\"\n", actionChars);
        }
        else DBE("() invalid or null action\n");

        if (error)
            RespondStatusCode
            (response, respStatusCode, respStatusDesc);

        DBF("() ...out\n");
        return EV_ERROR_NONE;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: GetEvcpServletContext
    //
    //   Author: $author$
    //     Date: 5/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvcpServletContext* GetEvcpServletContext
    (EvError& error) const 
    {
        error = EV_ERROR_NONE;
        return ((EvcpServletContext*)(&m_evcpServletContext));
    }
};
#endif // _CEVEVCPSERVLET_HPP
