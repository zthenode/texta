///////////////////////////////////////////////////////////////////////
//   File: cevlockevcpservlet.hpp
//
// Author: $author$
//   Date: 10/9/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVLOCKEVCPSERVLET_HPP
#define _CEVLOCKEVCPSERVLET_HPP

#include "cevcontextedevcpservlet.hpp"
#include "cevlockcontextevcpservlet.hpp"

#define DEFAULT_CEVLOCKEVCPSERVLET_NAME "LOCK"

///////////////////////////////////////////////////////////////////////
//  Class: CEvLockEvcpServlet
//
// Author: $author$
//   Date: 10/9/2007
///////////////////////////////////////////////////////////////////////
class CEvLockEvcpServlet
: public CEvContextedEvcpServlet
{
public:
    typedef CEvContextedEvcpServlet CExtends;
    typedef CEvLockEvcpServlet CDerives;

    bool m_unlock;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvLockEvcpServlet
    //
    //       Author: $author$
    //         Date: 10/9/2007
    ///////////////////////////////////////////////////////////////////////
    CEvLockEvcpServlet
    (bool unlock=false,
     const char* name=DEFAULT_CEVLOCKEVCPSERVLET_NAME,
     LONG length=-1) 
    : CExtends(name, length),
      m_unlock(unlock)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvLockEvcpServlet
    //
    //      Author: $author$
    //        Date: 10/9/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvLockEvcpServlet()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Initialize
    //
    //   Author: $author$
    //     Date: 10/9/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Initialize(EvServletServer& server) 
    {
        EvError error = EV_ERROR_NONE;
        DBF("() in...\n");
        DBF("() ...out\n");
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Finalize
    //
    //   Author: $author$
    //     Date: 10/9/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Finalize(EvServletServer& server) 
    {
        EvError error = EV_ERROR_NONE;
        DBF("() in...\n");
        DBF("() ...out\n");
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: NewEvcpServletContext
    //
    //   Author: $author$
    //     Date: 9/28/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvcpServlet* NewEvcpServletContext
    (EvcpServletConnection& connection) 
    {
        EvcpServlet* context = 0;
        const char* chars;
        LONG length;

        if ((chars = GetName(length)))
            context = new CEvLockContextEvcpServlet
            (m_unlock, chars, length);
        return context;
    }
};

#endif // _CEVLOCKEVCPSERVLET_HPP
