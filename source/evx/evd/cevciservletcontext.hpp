///////////////////////////////////////////////////////////////////////
//   File: cevciservletcontext.hpp
//
// Author: $author$
//   Date: 6/3/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCISERVLETCONTEXT_HPP
#define _CEVCISERVLETCONTEXT_HPP

#include "evciservletcontext.hpp"
#include "cevcservletcontext.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvCiServletContext
//
// Author: $author$
//   Date: 6/3/2007
///////////////////////////////////////////////////////////////////////
class CEvCiServletContext
: virtual public EvCiServletContext,
  public CEvCServletContext
{
public:
    typedef EvCiServletContext CImplements;
    typedef CEvCServletContext CExtends;
    typedef CEvCiServletContext CDerives;

    Evcs& m_evcs;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvCiServletContext
    //
    //       Author: $author$
    //         Date: 6/3/2007
    ///////////////////////////////////////////////////////////////////////
    CEvCiServletContext
    (Evcs& evcs, const EvcpServlet& evcpServlet)
    : CExtends(evcpServlet),
      m_evcs(evcs)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvCiServletContext
    //
    //      Author: $author$
    //        Date: 6/3/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvCiServletContext()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: GetCiServletContext
    //
    //   Author: $author$
    //     Date: 6/3/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvCiServletContext* 
    GetCiServletContext(EvError& error) const
    {
        error = EV_ERROR_NONE;
        return (EvCiServletContext*)(this);
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: DeleteThis
    //
    //   Author: $author$
    //     Date: 6/3/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError DeleteThis()
    {
        delete this;
        return EV_ERROR_NONE;
    }
};
#endif // _CEVCISERVLETCONTEXT_HPP
