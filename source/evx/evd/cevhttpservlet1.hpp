///////////////////////////////////////////////////////////////////////
//   File: cevhttpservlet.hpp
//
// Author: $author$
//   Date: 4/23/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVHTTPSERVLET_HPP
#define _CEVHTTPSERVLET_HPP

#include "cevcpservlet.hpp"
#include "cevcpservlets.hpp"
#include "cevhttppathservletallocatorfamily.hpp"
#include "cevhttpservletallocatorfamily.hpp"
#include "evcpservletallocatorlist.hpp"
#include "evhttpstatus.h"

#define DEFAULT_CEVHTTPSERVLET_NAME "HTTP"

///////////////////////////////////////////////////////////////////////
//  Class: CEvHttpServlet
//
// Author: $author$
//   Date: 4/23/2007
///////////////////////////////////////////////////////////////////////
class CEvHttpServlet
: public CEvcpServlet
{
public:
    typedef CEvcpServlet CExtends;
    typedef CEvHttpServlet CDerives;

    CEvcpServlets m_actionServlets;
    CEvcpServlets m_pathServlets;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvHttpServlet
    //
    //       Author: $author$
    //         Date: 4/23/2007
    ///////////////////////////////////////////////////////////////////////
    CEvHttpServlet
    (const char* name=DEFAULT_CEVHTTPSERVLET_NAME,
     LONG length=-1) 
    : CExtends(name, length)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvHttpServlet
    //
    //      Author: $author$
    //        Date: 4/23/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvHttpServlet()
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
        //if (!(error = AllocateActionServlets()))
        //    error = AllocatePathServlets();
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
        if (!(error = FinalizeServlets(m_pathServlets, server)))
            error = FinalizeServlets(m_actionServlets, server);
        DBF("() ...out\n");
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: AllocateActionServlets
    //
    //   Author: $author$
    //     Date: 6/12/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError AllocateActionServlets() 
    {
        EvError error = EV_ERROR_NONE;
        EvError error2;
        CEvHttpServletAllocatorItem* item;

        DBF("() in...\n");
/*
        if ((error2 = m_actionServlets.Clear()))
            return EV_ERROR_FAILED;

        for (item = CEvHttpServletAllocatorList::GetFirstItem(); 
             item; item = item->GetNextItem())
        {
            EvcpServletAllocator& allocator = item->GetAllocator();
            EvcpServlet* servlet;

            if ((servlet = allocator.AcquireServlet(error2)))
            {
                if ((error2 = servlet->Initialize()))
                    error = EV_ERROR_INITIALIZE;
                else if ((error2 = m_actionServlets.AddServlet(*servlet)))
                {
                    error = EV_ERROR_FAILED;
                    error2 = servlet->Finalize();
                }
                else continue;

                allocator.ReleaseServlet(*servlet);
                break;
            }
        }
*/
        DBF("() ...out\n");
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: AllocatePathServlets
    //
    //   Author: $author$
    //     Date: 6/12/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError AllocatePathServlets() 
    {
        EvError error = EV_ERROR_NONE;
        EvError error2;
        CEvHttpPathServletAllocatorItem* item;

        DBF("() in...\n");
/*
        if ((error2 = m_pathServlets.Clear()))
            return EV_ERROR_FAILED;

        for (item = CEvHttpPathServletAllocatorList::
             GetFirstItem(); item; item = item->GetNextItem())
        {
            EvHttpPathServletAllocator& allocator = item->GetAllocator();
            EvHttpPathServlet* servlet;

            if ((servlet = allocator.AcquireServlet(error2)))
            {
                if ((error2 = servlet->Initialize()))
                    error = EV_ERROR_INITIALIZE;
                else if ((error2 = m_pathServlets.AddServlet(*servlet)))
                {
                    error = EV_ERROR_FAILED;
                    error2 = servlet->Finalize();
                }
                else continue;

                allocator.ReleaseServlet(*servlet);
                break;
            }
        }
*/
        DBF("() ...out\n");
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: InitializeServlets
    //
    //   Author: $author$
    //     Date: 7/25/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError InitializeServlets
    (CEvcpServlets& servlets,
     EvcpServletAllocatorList& allocators,
     EvServletServer& server) 
    {
        EvError error = EV_ERROR_NONE;
        EvError error2;
        EvcpServletAllocator* allocator;
        EvcpServletAllocatorItem* allocatorItem;

        DBF("() in...\n");

        if ((error2 = servlets.Clear()))
            return EV_ERROR_FAILED;

        for (allocator = allocators.GetFirstAllocator(allocatorItem); 
             allocator; allocators.GetNextAllocator(allocatorItem))
        {
            EvcpServlet* servlet;

            if ((servlet = allocator->AcquireServlet(error2)))
            {
                servlet->SetParentEvcpServlet(this);

                if ((error = servlet->Initialize(server)))
                {
                    DBE("() failed to initialize servlet\n");
                    error = EV_ERROR_INITIALIZE;
                }
                else if ((error = servlets.AddServlet(*servlet)))
                {
                    DBE("() failed to add servlet\n");

                    if ((error2 = servlet->Finalize(server)))
                        DBE("() failed to finalize servlet\n");
                }
                else continue;

                if ((error2 = allocator->ReleaseServlet(*servlet)))
                    DBE("() failed to release servlet\n");
            }
            else 
            {
                DBE("() failed to acquire servlet\n");
                error = EV_ERROR_FAILED;
            }
            FinalizeServlets(servlets, server);
            break;
        }
        DBF("() ...out\n");
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: FinalizeServlets
    //
    //   Author: $author$
    //     Date: 7/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError FinalizeServlets
    (CEvcpServlets& servlets,
     EvServletServer& server) 
    {
        EvError error = EV_ERROR_NONE;
        EvError error2;
        const_CEvcpServletsIterator i;
        EvcpServlet* servlet;

        DBF("() in...\n");
        for (i = servlets.end(); i != servlets.begin();)
        {
            if ((servlet = *(--i)))
            if ((error2 = servlet->Finalize(server)) && !error)
                error = EV_ERROR_FINALIZE;
        }
        if ((error2 = servlets.Clear()) && !error)
            error = EV_ERROR_FAILED;
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
        const char* respChars = 
            "HTTP/1.1 200 OK\n"
            "Content-Type: text/html\n"
            "Content-Length: 38\n"
            "\n"
            "<html><body>EvX</body></html>\n";
        EvError error = EV_ERROR_NONE;
        EvcpHeader& reqHeader = request.GetHeader();
        EvcpHeaderHeading& reqHeading = reqHeader.GetHeading();
        EvCharWriter& writer = response.GetWriter();
        const char* actionChars;
        LONG actionLength;
        EvcpServlet* actionServlet;

        DBF("() in...\n");

        if ((actionChars = reqHeading.
            GetRequestAction(actionLength))
            && (0 < actionLength))

        if ((actionServlet = m_actionServlets.
            FindServlet(actionChars)))
            actionServlet->Service(request, response);

        m_chars.Assign(respChars);
        DBF("() --> \"%s\"\n", m_chars.c_str());
        m_chars.Write(writer);

        DBF("() ...out\n");
        return error;
    }
};
#endif // _CEVHTTPSERVLET_HPP
