///////////////////////////////////////////////////////////////////////
//   File: cevcpservletinteraction.hpp
//
// Author: $author$
//   Date: 6/3/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCPSERVLETINTERACTION_HPP
#define _CEVCPSERVLETINTERACTION_HPP

#include "evcpservletinteraction.hpp"
#include "cevservletinteraction.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpServletInteraction
//
// Author: $author$
//   Date: 6/3/2007
///////////////////////////////////////////////////////////////////////
class CEvcpServletInteraction
: virtual public EvcpServletInteraction,
  public CEvServletInteraction
{
public:
    typedef EvcpServletInteraction CImplements;
    typedef CEvServletInteraction CExtends;
    typedef CEvcpServletInteraction CDerives;

    EvcpServletConnection& m_evcpConnection;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpServletInteraction
    //
    //       Author: $author$
    //         Date: 6/3/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpServletInteraction
    (EvcpServletConnection& evcpConnection)
    : CExtends(evcpConnection),
      m_evcpConnection(evcpConnection) 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvcpServletInteraction
    //
    //      Author: $author$
    //        Date: 6/3/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvcpServletInteraction()
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetEvcpConnection
    //
    //   Author: $author$
    //     Date: 6/3/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvcpServletConnection& GetEvcpConnection() const
    {
        return (EvcpServletConnection&)(m_evcpConnection);
    }
};
#endif // _CEVCPSERVLETINTERACTION_HPP
