///////////////////////////////////////////////////////////////////////
//   File: cevservlet.hpp
//
// Author: $author$
//   Date: 4/13/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVSERVLET_HPP
#define _CEVSERVLET_HPP

#include "evservlet.hpp"
#include "cevinstance.hpp"
#include "cevstring.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvServlet
//
// Author: $author$
//   Date: 4/13/2007
///////////////////////////////////////////////////////////////////////
class CEvServlet
: virtual public EvServlet,
  public CEvInstance
{
public:
    typedef EvServlet CImplements;
    typedef CEvInstance CExtends;
    typedef CEvServlet CDerives;

    CEvString m_name;
    EvServlet* m_parentServlet;
    EvServlet* m_rootServlet;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvServlet
    //
    //       Author: $author$
    //         Date: 4/13/2007
    ///////////////////////////////////////////////////////////////////////
    CEvServlet
    (const char* name=0, LONG length=-1) 
    : m_parentServlet(0),
      m_rootServlet(0)
    {
        EvError error;
        if (name)
        if ((error = SetName(name, length)))
            throw(error);
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvServlet
    //
    //      Author: $author$
    //        Date: 4/13/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvServlet()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Initialize
    //
    //   Author: $author$
    //     Date: 4/21/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Initialize(EvServletServer& server) 
    {
        EvError error = EV_ERROR_NONE;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Finalize
    //
    //   Author: $author$
    //     Date: 4/21/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Finalize(EvServletServer& server) 
    {
        EvError error = EV_ERROR_NONE;
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
    // Function: Service
    //
    //   Author: $author$
    //     Date: 4/13/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Service
    (EvServletRequest& request,
     EvServletResponse& response) 
    {
        EvError error = EV_ERROR_NONE;
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetName
    //
    //   Author: $author$
    //     Date: 4/20/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError SetName
    (const char* chars, LONG length=-1) 
    {
        EvError error = EV_ERROR_NONE;
        m_name.Assign(chars, length);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetName
    //
    //   Author: $author$
    //     Date: 4/20/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetName
    (LONG& length) const 
    {
        const char* name = m_name.Chars(length);
        return name;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: CompareName
    //
    //   Author: $author$
    //     Date: 4/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int CompareName
    (const char* chars, LONG length=-1) const
    {
        int unequal = m_name.Compare(chars, length);
        return unequal;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetParentServlet
    //
    //   Author: $author$
    //     Date: 5/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError SetParentServlet
    (EvServlet* servlet) 
    {
        EvError error = EV_ERROR_NONE;
        m_parentServlet = servlet;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetParentServlet
    //
    //   Author: $author$
    //     Date: 5/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvServlet* GetParentServlet() const 
    {
        return m_parentServlet;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetRootServlet
    //
    //   Author: $author$
    //     Date: 12/21/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError SetRootServlet
    (EvServlet* servlet) 
    {
        EvError error = EV_ERROR_NONE;
        m_rootServlet = servlet;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetRootServlet
    //
    //   Author: $author$
    //     Date: 12/21/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvServlet* GetRootServlet() const 
    {
        return m_rootServlet;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: FindServlet
    //
    //   Author: $author$
    //     Date: 5/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvServlet* FindServlet
    (const char* name, LONG length=-1) const
    {
        EvServlet* servlet = 0;
        return servlet;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: DeleteThis
    //
    //   Author: $author$
    //     Date: 1/30/2012
    ///////////////////////////////////////////////////////////////////////
    virtual EvError DeleteThis()
    {
        EvError error = EV_ERROR_NOT_ALLOWED;
        return error;
    }
};
#endif // _CEVSERVLET_HPP
