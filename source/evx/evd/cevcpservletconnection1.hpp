///////////////////////////////////////////////////////////////////////
//   File: cevcpservletconnection.hpp
//
// Author: $author$
//   Date: 6/3/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCPSERVLETCONNECTION_HPP
#define _CEVCPSERVLETCONNECTION_HPP

#include "evcpservletconnection.hpp"
#include "cevservletconnection.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpServletConnection
//
// Author: $author$
//   Date: 6/3/2007
///////////////////////////////////////////////////////////////////////
class CEvcpServletConnection
: virtual public EvcpServletConnection
{
public:
    typedef EvcpServletConnection CImplements;
    typedef CEvcpServletConnection CDerives;

    EvServletConnection& m_servletConnection;
    EvcpServletContexts m_evcpServletContexts;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpServletConnection
    //
    //       Author: $author$
    //         Date: 6/3/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpServletConnection
    (EvServletConnection& servletConnection) 
    : m_servletConnection(servletConnection) 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvcpServletConnection
    //
    //      Author: $author$
    //        Date: 6/3/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvcpServletConnection()
    {
        EvError error;
        if ((error = Finalize()))
            throw(error);
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: DeleteAllEvcpServletContexts
    //
    //   Author: $author$
    //     Date: 6/12/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError DeleteAllEvcpServletContexts() 
    {
        EvError error = EV_ERROR_NONE;
        EvError error2;
        EvcpServletContext* context;
        EvcpServletContextsIterator i;

        for (i = m_evcpServletContexts.begin(); 
             i != m_evcpServletContexts.end(); i++)
        {
            if ((context = *i))
			{
				context->Finalize();
				if ((error2 = context->DeleteInstance()))
					error = EV_ERROR_FAILED;
			}
        }
        m_evcpServletContexts.clear();
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: AddEvcpServletContext
    //
    //   Author: $author$
    //     Date: 6/3/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError AddEvcpServletContext
    (EvcpServletContext& servletContext) 
    {
        EvError error = EV_ERROR_NONE;
        const EvcpServlet& servlet = servletContext.GetEvcpServlet();
        EvcpServletContext* context;

        if ((context = FindEvcpServletContext(servlet)))
        {
            if (&servletContext != context)
                error = EV_ERROR_FAILED;
        }
        else m_evcpServletContexts.push_back(&servletContext);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: RemoveEvcpServletContext
    //
    //   Author: $author$
    //     Date: 6/3/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvServletContext* RemoveEvcpServletContext
    (const EvcpServlet& servlet)
    {
        EvcpServletContext* context;
        EvcpServletContextsIterator i;

        for (i = m_evcpServletContexts.begin(); 
             i != m_evcpServletContexts.end(); i++)
        {
            if ((context = *i))
            {
                const EvcpServlet& contextServlet = context->GetEvcpServlet();
                if (&contextServlet == &servlet)
                {
                    m_evcpServletContexts.erase(i);
                    return context;
                }
            }
        }
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: FindEvcpServletContext
    //
    //   Author: $author$
    //     Date: 6/3/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvcpServletContext* FindEvcpServletContext
    (const EvcpServlet& servlet) const 
    {
        EvcpServletContext* context;
        const_EvcpServletContextsIterator i;

        for (i = m_evcpServletContexts.begin(); 
             i != m_evcpServletContexts.end(); i++)
        {
            if ((context = *i))
            {
                const EvcpServlet& contextServlet = context->GetEvcpServlet();
                if (&contextServlet == &servlet)
                    return context;
            }
        }
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Initialize
    //
    //   Author: $author$
    //     Date: 9/10/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Initialize() 
    {
        EvError error = EV_ERROR_NONE;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Finalize
    //
    //   Author: $author$
    //     Date: 9/10/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Finalize() 
    {
        EvError error = DeleteAllEvcpServletContexts();
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: DeleteAllServletContexts
    //
    //   Author: $author$
    //     Date: 6/12/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError DeleteAllServletContexts() 
    {
        return m_servletConnection.
            DeleteAllServletContexts();
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: AddServletContext
    //
    //   Author: $author$
    //     Date: 4/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError AddServletContext
    (EvServletContext& servletContext) 
    {
        return m_servletConnection.
            AddServletContext(servletContext);
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: RemoveServletContext
    //
    //   Author: $author$
    //     Date: 4/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvServletContext* RemoveServletContext
    (const EvServlet& servlet)
    {
        return m_servletConnection.
            RemoveServletContext(servlet);
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: FindServletContext
    //
    //   Author: $author$
    //     Date: 4/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvServletContext* FindServletContext
    (const EvServlet& servlet) const 
    {
        return m_servletConnection.
            FindServletContext(servlet);
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: FindServletContextByName
    //
    //   Author: $author$
    //     Date: 5/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvServletContext* FindServletContextByName
    (const char* name, LONG length=-1) const 
    {
        return m_servletConnection.
            FindServletContextByName(name, length);
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetKeepAlive
    //
    //   Author: $author$
    //     Date: 4/23/2007
    ///////////////////////////////////////////////////////////////////////
    virtual bool SetKeepAlive(bool on=true) 
    {
        return m_servletConnection.SetKeepAlive(on);
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetKeepAlive
    //
    //   Author: $author$
    //     Date: 4/23/2007
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetKeepAlive() const 
    {
        return m_servletConnection.GetKeepAlive();
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: GetServer
    //
    //   Author: $author$
    //     Date: 5/14/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvServletServer& GetServer() const 
    {
        return m_servletConnection.GetServer();
    }
};
#endif // _CEVCPSERVLETCONNECTION_HPP
