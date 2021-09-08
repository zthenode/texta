///////////////////////////////////////////////////////////////////////
//   File: cevtcpservlet.hpp
//
// Author: $author$
//   Date: 4/12/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVTCPSERVLET_HPP
#define _CEVTCPSERVLET_HPP

#include "evtcpservlet.hpp"
#include "cevservlet.hpp"
#include "evdebug.h"

///////////////////////////////////////////////////////////////////////
//  Class: CEvTcpServlet
//
// Author: $author$
//   Date: 4/12/2007
///////////////////////////////////////////////////////////////////////
class CEvTcpServlet
: virtual public EvTcpServlet,
  public CEvServlet
{
public:
    typedef EvTcpServlet CImplements;
    typedef CEvServlet CExtends;
    typedef CEvTcpServlet CDerives;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvTcpServlet
    //
    //       Author: $author$
    //         Date: 4/12/2007
    ///////////////////////////////////////////////////////////////////////
    CEvTcpServlet
    (const char* name=0, LONG length=-1) 
    : CExtends(name, length)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvTcpServlet
    //
    //      Author: $author$
    //        Date: 4/12/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvTcpServlet()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Initialize
    //
    //   Author: $author$
    //     Date: 7/17/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Initialize(EvTcpServletServer& server) 
    {
        EvError error = ((CExtends*)this)->Initialize(server);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Finalize
    //
    //   Author: $author$
    //     Date: 7/17/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Finalize(EvTcpServletServer& server) 
    {
        EvError error = ((CExtends*)this)->Finalize(server);
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Service
    //
    //   Author: $author$
    //     Date: 4/12/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Service
    (EvTcpServletRequest& request,
     EvTcpServletResponse& response) 
    {
        EvServletConnection& connection = request.GetConnection();
        CExtends& extends = ((CExtends&)(*this));
        EvError error, error2;
        
        if (!(error = extends.ConnectionInitialize(connection)))
        {
            error = extends.Service(request, response);

            if ((error2 = extends.ConnectionFinalize
                (connection)) && !error)
                error = error2;
        }
        return error;
    }
};
#endif // _CEVTCPSERVLET_HPP
