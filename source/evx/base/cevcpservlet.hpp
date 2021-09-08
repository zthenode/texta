///////////////////////////////////////////////////////////////////////
//   File: cevcpservlet.hpp
//
// Author: $author$
//   Date: 4/21/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCPSERVLET_HPP
#define _CEVCPSERVLET_HPP

#include "evcpservlet.hpp"
#include "cevservlet.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpServlet
//
// Author: $author$
//   Date: 4/21/2007
///////////////////////////////////////////////////////////////////////
class CEvcpServlet
: virtual public EvcpServlet,
  public CEvServlet
{
public:
    typedef EvcpServlet CImplements;
    typedef CEvServlet CExtends;
    typedef CEvcpServlet CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpServlet
    //
    //       Author: $author$
    //         Date: 4/21/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpServlet
    (EvcpServletRequest& request,
     EvcpServletResponse& response) 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvcpServlet
    //
    //      Author: $author$
    //        Date: 4/21/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvcpServlet()
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Service
    //
    //   Author: $author$
    //     Date: 4/21/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Service
    (EvcpServletRequest& request,
     EvcpServletResponse& response) 
    {
        EvError error = EV_ERROR_NONE;
        return error;
    }
};

#endif // _CEVCPSERVLET_HPP
