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
  public CEvServletConnection
{
public:
    typedef EvcpServletConnection CImplements;
    typedef CEvServletConnection CExtends;
    typedef CEvcpServletConnection CDerives;

    EvServletConnection& m_servletConnection;
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
    : CExtends(servletConnection.GetServer(), isStaticInstance),
      m_servletConnection(servletConnection),
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
    // Function: Finalize
    //
    //   Author: $author$
    //     Date: 9/10/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Finalize() 
    {
        EvError error = DeleteAllEvcpServletContexts();
        EvError error2;
        if ((error2 = CExtends::Finalize()) && !error)
            error = error2;
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
        EvError error2;
        if ((error2 = CExtends::ConnectionFinalize
            (connection)) && !error)
            error = error2;
        return error;
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
