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

#include "cevcontextedevcpservlet.hpp"
#include "cevevcpcontextevcpservlet.hpp"
#include "cevcpservlets.hpp"
#include "cevevcpservletallocatorfamily.hpp"
#include "cevcsallocatorlist.hpp"
#include "cevstringwriter.hpp"

#define DEFAULT_CEVEVCPSERVLET_NAME "EVCP"

///////////////////////////////////////////////////////////////////////
//  Class: CEvEvcpServlet
//
// Author: $author$
//   Date: 4/23/2007
///////////////////////////////////////////////////////////////////////
class CEvEvcpServlet
: public CEvContextedEvcpServlet
{
public:
    typedef CEvContextedEvcpServlet CExtends;
    typedef CEvEvcpServlet CDerives;

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
    : CExtends(name, length)
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

        if ((error = InitializeEvcs()))
            return error;

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
    // Function: NewEvcpServletContext
    //
    //   Author: $author$
    //     Date: 9/20/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvcpServlet* NewEvcpServletContext
    (EvcpServletConnection& connection) 
    {
        EvcpServlet* context = 0;
        const char* chars;
        LONG length;

        if ((chars = GetName(length)))
            context = new CEvEvcpContextEvcpServlet
            (m_actionServlets, chars, length);
        return context;
    }
};
#endif // _CEVEVCPSERVLET_HPP
