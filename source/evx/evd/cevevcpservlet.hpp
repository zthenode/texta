///////////////////////////////////////////////////////////////////////
//   File: cevevcpservlet.hpp
//
// Author: $author$
//   Date: 12/6/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVEVCPSERVLET_HPP
#define _CEVEVCPSERVLET_HPP

#include "cevcpservlet.hpp"
#include "cevcpservlets.hpp"
#include "cevevcpservletallocatorfamily.hpp"
#include "cevcsallocatorlist.hpp"
#include "evcsacquired.hpp"
#include "cevstringwriter.hpp"

#define DEFAULT_CEVEVCPSERVLET_NAME "EVCP"

///////////////////////////////////////////////////////////////////////
//  Class: CEvEvcpServlet
//
// Author: $author$
//   Date: 12/6/2007
///////////////////////////////////////////////////////////////////////
class CEvEvcpServlet
: public CEvcpServlet
{
public:
    typedef CEvcpServlet CExtends;
    typedef CEvEvcpServlet CDerives;

    typedef EvError (CDerives::*MService)
    (EvcpServletRequest& request,
     EvcpServletResponse& response);

    CEvcpServlets m_actionServlets;
    MService m_service;

    EvcsAcquired m_evcsAcquired;
    Evcs* m_evcs;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvEvcpServlet
    //
    //       Author: $author$
    //         Date: 12/6/2007
    ///////////////////////////////////////////////////////////////////////
    CEvEvcpServlet
    (const char* name=DEFAULT_CEVEVCPSERVLET_NAME,
     LONG length=-1) 
    : CExtends(name, length),
      m_service(&CDerives::ServiceAction),
      m_evcs(0)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvEvcpServlet
    //
    //      Author: $author$
    //        Date: 12/6/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvEvcpServlet()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: ConnectionInitialize
    //
    //   Author: $author$
    //     Date: 12/6/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ConnectionInitialize
    (EvcpServletConnection& connection) 
    {
        EvError error = EV_ERROR_NONE;
        EvError error2;
        DBF("() in...\n");

        if ((error2 = m_actionServlets.
            ConnectionInitialize(connection)))
            error = EV_ERROR_FAILED;

        DBF("() ...out\n");
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ConnectionFinalize
    //
    //   Author: $author$
    //     Date: 12/6/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ConnectionFinalize
    (EvcpServletConnection& connection) 
    {
        EvError error = EV_ERROR_NONE;
        EvError error2;
        EvcsAcquiredIterator i;
        Evcs* acquiredEvcs;

        DBF("() in...\n");

        for (i = m_evcsAcquired.begin();
             i != m_evcsAcquired.end(); i++)
        {
            if ((acquiredEvcs = *i))
            if ((error2 = ReleaseAcquiredEvcs(*acquiredEvcs)))
                error = EV_ERROR_FAILED;
        }

        m_evcsAcquired.clear();

        if ((error2 = m_actionServlets.
            ConnectionFinalize(connection)))
            error = EV_ERROR_FAILED;

        DBF("() ...out\n");
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Initialize
    //
    //   Author: $author$
    //     Date: 12/6/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Initialize(EvServletServer& server) 
    {
        EvError error = EV_ERROR_NONE;
        EvError error2;
        EvServlet* rootServlet;
        CEvEvcpServletAllocatorItem* item;

        DBF("() in...\n");

        if ((error = InitializeEvcs()))
            return error;

        if ((error2 = m_actionServlets.Clear()))
            return EV_ERROR_FAILED;

        rootServlet = GetRootServlet();

        for (item = CEvEvcpServletAllocatorList::GetFirstItem(); 
             item; item = item->GetNextItem())
        {
            EvcpServletAllocator& allocator = item->GetAllocator();
            EvcpServlet* servlet;

            if ((servlet = allocator.AcquireServlet(error2)))
            {
                servlet->SetParentEvcpServlet(this);

                if ((error = servlet->SetRootServlet(rootServlet)))
                {
                    DBE("() failed to set root servlet\n");
                    error = EV_ERROR_FAILED;
                }
                else
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
    //     Date: 12/6/2007
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

        if ((error2 = FinalizeEvcs()) && !error)
            error = error2;

        DBF("() ...out\n");
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: InitializeEvcs
    //
    //   Author: $author$
    //     Date: 9/20/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError InitializeEvcs() 
    {
        EvError error = EV_ERROR_NONE;
        CEvcsAllocatorItem* allocatorItem;

        for (allocatorItem = CEvcsAllocatorList::GetFirstItem();
             allocatorItem; allocatorItem = allocatorItem->GetNextItem())
        {
            EvcsAllocator& allocator = allocatorItem->GetAllocator();
            if ((error = allocator.Initialize()))
            {
                FinalizeEvcsAllocators
                (allocatorItem->GetPrevItem());
                break;
            }
        }
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: FinalizeEvcs
    //
    //   Author: $author$
    //     Date: 9/20/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError FinalizeEvcs() 
    {
        EvError error = FinalizeEvcsAllocators
        (CEvcsAllocatorList::GetLastItem());
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: FinalizeEvcsAllocators
    //
    //   Author: $author$
    //     Date: 9/20/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError FinalizeEvcsAllocators
    (CEvcsAllocatorItem* allocatorItem) 
    {
        EvError error = EV_ERROR_NONE;
        EvError error2;

        for (;allocatorItem; allocatorItem = allocatorItem->GetPrevItem())
        {
            EvcsAllocator& allocator = allocatorItem->GetAllocator();
            if ((error2 = allocator.Finalize()) && !error)
                error = error2;
        }
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: AcquireEvcs
    //
    //   Author: $author$
    //     Date: 5/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual Evcs* AcquireEvcs
    (EvError& error, 
     const char* name=0, LONG length=-1) 
    {
        Evcs* evcs = 0;
        EvcsAllocator* allocator;
        EvError error2;

        error = EV_ERROR_FAILED;

        if (!name || !length)
            evcs = AcquireDefaultEvcs(error);

        else 
        {
            if ((allocator = EvcsAllocator::
                GetAllocator(error2, name,  length)))
            if ((evcs = allocator->AcquireEvcs(error2)))
            {
                m_evcsAcquired.push_back(evcs);
                error = EV_ERROR_NONE;
            }
        }
        return evcs;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ReleaseEvcs
    //
    //   Author: $author$
    //     Date: 5/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ReleaseEvcs(Evcs& evcs) 
    {
        EvError error = EV_ERROR_FAILED;
        EvcsAcquiredIterator i;
        Evcs* acquiredEvcs;

        for (i = m_evcsAcquired.begin();
             i != m_evcsAcquired.end(); i++)
        {
            if (&evcs == (acquiredEvcs = *i))
                return EV_ERROR_NONE;
        }
        DBE("() evcs not acquired\n");
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: AcquireDefaultEvcs
    //
    //   Author: $author$
    //     Date: 5/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual Evcs* AcquireDefaultEvcs(EvError& error) 
    {
        Evcs* evcs = 0;
        EvcsAllocator* allocator;

        if ((evcs = m_evcs))
        {
            error = EV_ERROR_NONE;
            return evcs;
        }

        error = EV_ERROR_FAILED;

        if ((allocator = EvcsAllocator::GetAllocator(error)))
        if ((evcs = allocator->AcquireEvcs(error)))
            m_evcsAcquired.push_back(m_evcs = evcs);
        return evcs;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ReleaseAcquiredEvcs
    //
    //   Author: $author$
    //     Date: 9/20/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ReleaseAcquiredEvcs(Evcs& evcs) 
    {
        EvError error = EV_ERROR_FAILED;
        EvcsAllocator* allocator;

        if ((allocator = evcs.GetAllocator()))
            error = allocator->ReleaseEvcs(evcs);
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Service
    //
    //   Author: $author$
    //     Date: 12/6/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Service
    (EvcpServletRequest& request,
     EvcpServletResponse& response) 
    {
        EvError error = EV_ERROR_NONE;
        EvcpStatus status = EVCP_STATUS_INTERNAL_SERVER_ERROR;

        DBF("() in...\n");
        
        if (m_service)
            error = (this->*m_service)
            (request, response);
            
        else         
        RespondStatus(response, status);
        
        DBF("() ...out\n");
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ServiceAction
    //
    //   Author: $author$
    //     Date: 10/13/2007
    ///////////////////////////////////////////////////////////////////////
    EvError ServiceAction
    (EvcpServletRequest& request,
     EvcpServletResponse& response) 
    {
        EvError error = EV_ERROR_NONE;
        EvcpStatus status = EVCP_STATUS_INTERNAL_SERVER_ERROR;
        EvcpHeader& reqHeader = request.GetHeader();
        EvcpHeaderHeading& reqHeading = reqHeader.GetHeading();
        const char* actionChars;
        LONG actionLength;

        DBF("() in...\n");
        
        if (!(actionChars = reqHeading.
            GetRequestAction(actionLength))
            || (0 >= actionLength))
        {
            DBE("() null action\n");
            RespondStatus(response, status);
        }
        else
        error = ServiceActionNamed
        (request, response, actionChars);        
        
        DBF("() ...out\n");
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ServiceActionNamed
    //
    //   Author: $author$
    //     Date: 10/13/2007
    ///////////////////////////////////////////////////////////////////////
    EvError ServiceActionNamed
    (EvcpServletRequest& request,
     EvcpServletResponse& response,
     const char* actionChars,
     bool isLogin=false) 
    {
        EvError error = EV_ERROR_NONE;
        EvError error2 = EV_ERROR_NONE;
        EvcpStatus status = EVCP_STATUS_INTERNAL_SERVER_ERROR;
        EvcpServlet* actionServlet;

        DBF("() in...\n");
        
        if ((actionServlet = m_actionServlets.
            FindServlet(actionChars)))
        {
            if ((error2 = actionServlet->Service
                (request, response)) && !isLogin)
                DBE("() servlet \"%s\" failed \n", actionChars);
            else if (isLogin)
                    m_service = &CDerives::ServiceAction;
        }
        else DBE("() unable to find servlet \"%s\"\n", actionChars);

        if (error2)
            RespondStatus(response, status);
        
        DBF("() ...out\n");
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: GetEvcpServletContext
    //
    //   Author: $author$
    //     Date: 12/27/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvcpServlet* GetEvcpServletContext
    (EvcpServletConnection& connection) 
    {
        EvcpServlet* context = this;
        return context;
    }
};

#endif // _CEVEVCPSERVLET_HPP
