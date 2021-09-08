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
#include "evcpservlets.hpp"
#include "cevinstance.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpServletConnection
//
// Author: $author$
//   Date: 6/3/2007
///////////////////////////////////////////////////////////////////////
class CEvcpServletConnection
: virtual public EvcpServletConnection,
  public CEvInstance
{
public:
    typedef EvcpServletConnection CImplements;
    typedef CEvInstance CExtends;
    typedef CEvcpServletConnection CDerives;

    EvServletConnection& m_servletConnection;
    EvServletServer& m_servletServer;
    EvServlet* m_servlet;
    EvcpServlets m_evcpServletContexts;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpServletConnection
    //
    //       Author: $author$
    //         Date: 6/3/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpServletConnection
    (EvServletConnection& servletConnection,
     bool isStaticInstance=true) 
    : CExtends(isStaticInstance),
      m_servletConnection(servletConnection),
      m_servletServer(m_servletConnection.GetServer()),
      m_servlet(0)
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
        EvcpServlet* context;
        EvcpServletsIterator i;

        for (i = m_evcpServletContexts.begin(); 
             i != m_evcpServletContexts.end(); i++)
        {
            if ((context = *i))
			{
                if ((error2 = context->ConnectionFinalize(*this)))
					error = EV_ERROR_FAILED;
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
    (EvcpServlet& servletContext) 
    {
        EvError error = EV_ERROR_FAILED;
        EvError error2;
        EvcpServlet* servlet;
        EvcpServlet* context;

        if ((servlet = servletContext.GetParentEvcpServlet(error2)))
        if ((context = FindEvcpServletContext(*servlet)))
        {
            if (&servletContext == context)
                error = EV_ERROR_NONE;
        }
        else 
        {
            m_evcpServletContexts.push_back(&servletContext);
            error = EV_ERROR_NONE;
        }
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: RemoveEvcpServletContext
    //
    //   Author: $author$
    //     Date: 6/3/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvServlet* RemoveEvcpServletContext
    (const EvcpServlet& servlet)
    {
        EvError error2;
        EvcpServlet* context;
        EvcpServletsIterator i;

        for (i = m_evcpServletContexts.begin(); 
             i != m_evcpServletContexts.end(); i++)
        {
            if ((context = *i))
            {
                EvcpServlet* contextServlet;
                if ((contextServlet = context->GetParentEvcpServlet(error2)))
                if (&servlet == contextServlet)
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
    virtual EvcpServlet* FindEvcpServletContext
    (const EvcpServlet& servlet) const 
    {
        EvError error2;
        const EvcpServlet* context;
        const_EvcpServletsIterator i;

        for (i = m_evcpServletContexts.begin(); 
             i != m_evcpServletContexts.end(); i++)
        {
            if ((context = *i))
            {
                EvcpServlet* contextServlet;
                if ((contextServlet = context->GetParentEvcpServlet(error2)))
                if (&servlet == contextServlet)
                    return (EvcpServlet*)(context);
            }
        }
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: GetEvcpServletConnection
    //
    //   Author: $author$
    //     Date: 9/23/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvcpServletConnection* 
    GetEvcpServletConnection() const 
    {
        return (EvcpServletConnection*)(this);
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
    // Function: ConnectionInitialize
    //
    //   Author: $author$
    //     Date: 9/22/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ConnectionInitialize
    (EvServletConnection& connection) 
    {
        EvError error = EV_ERROR_NONE;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ConnectionFinalize
    //
    //   Author: $author$
    //     Date: 9/22/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ConnectionFinalize
    (EvServletConnection& connection) 
    {
        EvError error = DeleteAllEvcpServletContexts();
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: DeleteAllServletConnections
    //
    //   Author: $author$
    //     Date: 9/22/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError DeleteAllServletConnections() 
    {
        EvError error = EV_ERROR_NONE;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: AddServletConnection
    //
    //   Author: $author$
    //     Date: 4/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError AddServletConnection
    (EvServletConnection& servletConnection) 
    {
        EvError error = EV_ERROR_FAILED;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: RemoveServletConnection
    //
    //   Author: $author$
    //     Date: 4/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvServletConnection* RemoveServletConnection
    (const EvServlet& servlet)
    {
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: FindServletConnection
    //
    //   Author: $author$
    //     Date: 4/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvServletConnection* FindServletConnection
    (const EvServlet& servlet) const 
    {
        return 0;
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
    (EvServlet& servletContext) 
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
    virtual EvServlet* RemoveServletContext
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
    virtual EvServlet* FindServletContext
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
    virtual EvServlet* FindServletContextByName
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

    ///////////////////////////////////////////////////////////////////////
    // Function: SetServlet
    //
    //   Author: $author$
    //     Date: 9/23/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError SetServlet
    (EvServlet* servlet) 
    {
        EvError error = EV_ERROR_NONE;
        m_servlet = servlet;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetServlet
    //
    //   Author: $author$
    //     Date: 9/23/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvServlet* GetServlet() const 
    {
        return m_servlet;
    }
};
#endif // _CEVCPSERVLETCONNECTION_HPP
