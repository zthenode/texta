///////////////////////////////////////////////////////////////////////
//   File: cevcservletcontext.hpp
//
// Author: $author$
//   Date: 8/19/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCSERVLETCONTEXT_HPP
#define _CEVCSERVLETCONTEXT_HPP

#include "evcservletcontext.hpp"
#include "cevcpservletcontext.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvCServletContext
//
// Author: $author$
//   Date: 8/19/2007
///////////////////////////////////////////////////////////////////////
class CEvCServletContext
: virtual public EvCServletContext,
  public CEvcpServletContext
{
public:
    typedef EvCServletContext CImplements;
    typedef CEvcpServletContext CExtends;
    typedef CEvCServletContext CDerives;

    ULONG m_blockSize;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvCServletContext
    //
    //       Author: $author$
    //         Date: 8/19/2007
    ///////////////////////////////////////////////////////////////////////
    CEvCServletContext(const EvcpServlet& evcpServlet)
    : CExtends(evcpServlet),
      m_blockSize(0) 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvCServletContext
    //
    //      Author: $author$
    //        Date: 8/19/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvCServletContext()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetBlockSize
    //
    //   Author: $author$
    //     Date: 6/3/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG SetBlockSize(ULONG size) 
    {
        m_blockSize = size;
        return (LONG)m_blockSize;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetBlockSize
    //
    //   Author: $author$
    //     Date: 6/3/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ULONG GetBlockSize(EvError& error) const 
    {
        error = EV_ERROR_NONE;
        return m_blockSize;
    }
};
#endif // _CEVCSERVLETCONTEXT_HPP
