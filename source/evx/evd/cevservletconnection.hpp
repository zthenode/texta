///////////////////////////////////////////////////////////////////////
//   File: cevservletconnection.hpp
//
// Author: $author$
//   Date: 4/23/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVSERVLETCONNECTION_HPP
#define _CEVSERVLETCONNECTION_HPP

#include "evservletconnections.hpp"
#include "evservletconnection.hpp"
#include "evservlets.hpp"
#include "evservlet.hpp"
#include "cevinstance.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvServletConnection
//
// Author: $author$
//   Date: 4/23/2007
///////////////////////////////////////////////////////////////////////
class CEvServletConnection
: virtual public EvServletConnection,
  public CEvInstance
{
public:
    typedef EvServletConnection CImplements;
    typedef CEvInstance CExtends;
    typedef CEvServletConnection CDerives;

    EvServletServer& m_server;
    EvServlet* m_servlet;
    bool m_keepAlive;
    EvServlets m_servletContexts;
    EvServletConnections m_servletConnections;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvServletConnection
    //
    //       Author: $author$
    //         Date: 4/23/2007
    ///////////////////////////////////////////////////////////////////////
    CEvServletConnection
    (EvServletServer& server, 
     bool isStaticInstance=true) 
    : CExtends(isStaticInstance),
      m_server(server),
      m_servlet(0),
      m_keepAlive(false)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvServletConnection
    //
    //      Author: $author$
    //        Date: 4/23/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvServletConnection()
    {
        EvError error;
        if ((error = Finalize()))
            throw(error);
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
        EvError error = DeleteAllServletContexts();
        EvError error2;
        if ((error2 = DeleteAllServletConnections()) && !error)
            error = error2;
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
        EvError error = EV_ERROR_NONE;
        return error;
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
        EvcpServletConnection* m_evcpServletConnection = 0;
        return m_evcpServletConnection;
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
        EvError error2;
        EvServletConnection* connection;
        EvServletConnectionsIterator i;

        for (i = m_servletConnections.begin(); 
             i != m_servletConnections.end(); i++)
        {
            if ((connection = *i))
            {
                if ((error2 = connection->ConnectionFinalize(*connection)))
                    error = EV_ERROR_FAILED;
                if ((error2 = connection->DeleteInstance()))
                    error = EV_ERROR_FAILED;
            }
        }
        m_servletConnections.clear();
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
        EvServlet* servlet;
        EvServletConnection* connection;

        if ((servlet = servletConnection.GetServlet()))
        if ((connection = FindServletConnection(*servlet)))
        {
            if (&servletConnection == connection)
                error = EV_ERROR_NONE;
        }
        else 
        {
            m_servletConnections.push_back(&servletConnection);
            error = EV_ERROR_NONE;
        }
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
        EvServletConnection* connection;
        EvServletConnectionsIterator i;

        for (i = m_servletConnections.begin(); 
             i != m_servletConnections.end(); i++)
        {
            if ((connection = *i))
            {
                EvServlet* connectionServlet;
                if ((connectionServlet = connection->GetServlet()))
                if (&servlet == connectionServlet)
                {
                    m_servletConnections.erase(i);
                    return connection;
                }
            }
        }
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
        EvServletConnection* connection;
        const_EvServletConnectionsIterator i;

        for (i = m_servletConnections.begin(); 
             i != m_servletConnections.end(); i++)
        {
            if ((connection = *i))
            {
                EvServlet* connectionServlet;
                if ((connectionServlet = connection->GetServlet()))
                if (&servlet == connectionServlet)
                    return connection;
            }
        }
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
        EvError error = EV_ERROR_NONE;
        EvError error2;
        EvServlet* context;
        EvServletsIterator i;

        for (i = m_servletContexts.begin(); 
             i != m_servletContexts.end(); i++)
        {
            if ((context = *i))
            {
                if ((error2 = context->Finalize(m_server)))
                    error = EV_ERROR_FAILED;
                if ((error2 = context->DeleteInstance()))
                    error = EV_ERROR_FAILED;
            }
        }
        m_servletContexts.clear();
        return error;
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
        EvError error = EV_ERROR_FAILED;
        EvServlet* servlet;
        EvServlet* context;

        if ((servlet = servletContext.GetParentServlet()))
        if ((context = FindServletContext(*servlet)))
        {
            if (&servletContext == context)
                error = EV_ERROR_NONE;
        }
        else 
        {
            m_servletContexts.push_back(&servletContext);
            error = EV_ERROR_NONE;
        }
        return error;
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
        EvServlet* context;
        EvServletsIterator i;

        for (i = m_servletContexts.begin(); 
             i != m_servletContexts.end(); i++)
        {
            if ((context = *i))
            {
                EvServlet* contextServlet;
                if ((contextServlet = context->GetParentServlet()))
                if (&servlet == contextServlet)
                {
                    m_servletContexts.erase(i);
                    return context;
                }
            }
        }
        return 0;
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
        EvServlet* context;
        const_EvServletsIterator i;

        for (i = m_servletContexts.begin(); 
             i != m_servletContexts.end(); i++)
        {
            if ((context = *i))
            {
                EvServlet* contextServlet;
                if ((contextServlet = context->GetParentServlet()))
                if (&servlet == contextServlet)
                    return context;
            }
        }
        return 0;
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
        const EvServlet* context;
        const_EvServletsIterator i;
        int unequal;

        for (i = m_servletContexts.begin(); 
             i != m_servletContexts.end(); i++)
        {
            if ((context = *i))
            {
                EvServlet* contextServlet;
                if ((contextServlet = context->GetParentServlet()))
                if (!(unequal = contextServlet->CompareName(name, length)))
                    return (EvServlet*)(context);
            }
        }
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetKeepAlive
    //
    //   Author: $author$
    //     Date: 4/23/2007
    ///////////////////////////////////////////////////////////////////////
    virtual bool SetKeepAlive(bool on=true) 
    {
        return m_keepAlive = on;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetKeepAlive
    //
    //   Author: $author$
    //     Date: 4/23/2007
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetKeepAlive() const 
    {
        return m_keepAlive;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: GetServer
    //
    //   Author: $author$
    //     Date: 5/14/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvServletServer& GetServer() const 
    {
        return m_server;
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
#endif // _CEVSERVLETCONNECTION_HPP
