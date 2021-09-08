///////////////////////////////////////////////////////////////////////
//   File: cevcoservletcontext.hpp
//
// Author: $author$
//   Date: 8/19/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCOSERVLETCONTEXT_HPP
#define _CEVCOSERVLETCONTEXT_HPP

#include "evcoservletcontext.hpp"
#include "cevcservletcontext.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvCoServletContext
//
// Author: $author$
//   Date: 8/19/2007
///////////////////////////////////////////////////////////////////////
class CEvCoServletContext
: virtual public EvCoServletContext,
  public CEvCServletContext
{
public:
    typedef EvCoServletContext CImplements;
    typedef CEvCServletContext CExtends;
    typedef CEvCoServletContext CDerives;

    Evcs& m_evcs;
    ULONG m_block;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvCoServletContext
    //
    //       Author: $author$
    //         Date: 8/19/2007
    ///////////////////////////////////////////////////////////////////////
    CEvCoServletContext
    (Evcs& evcs, const EvcpServlet& evcpServlet)
    : CExtends(evcpServlet),
      m_evcs(evcs),
      m_block(0) 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvCoServletContext
    //
    //      Author: $author$
    //        Date: 8/19/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvCoServletContext()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Finalize
    //
    //   Author: $author$
    //     Date: 8/29/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Finalize() 
    {
        EvError error = EV_ERROR_NONE;
        m_evcs.FinishOp();
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetBlock
    //
    //   Author: $author$
    //     Date: 9/21/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG SetBlock(ULONG block) 
    {
        m_block = block;
        return (LONG)m_block;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetBlock
    //
    //   Author: $author$
    //     Date: 8/21/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ULONG GetBlock(EvError& error) const 
    {
        error = EV_ERROR_NONE;
        return m_block;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: GetCoServletContext
    //
    //   Author: $author$
    //     Date: 8/19/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvCoServletContext* 
    GetCoServletContext(EvError& error) const
    {
        error = EV_ERROR_NONE;
        return (EvCoServletContext*)(this);
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: DeleteThis
    //
    //   Author: $author$
    //     Date: 8/19/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError DeleteThis()
    {
        delete this;
        return EV_ERROR_NONE;
    }
};
#endif // _CEVCOSERVLETCONTEXT_HPP
