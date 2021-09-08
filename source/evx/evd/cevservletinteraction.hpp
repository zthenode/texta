///////////////////////////////////////////////////////////////////////
//   File: cevservletinteraction.hpp
//
// Author: $author$
//   Date: 4/23/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVSERVLETINTERACTION_HPP
#define _CEVSERVLETINTERACTION_HPP

#include "evservletinteraction.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvServletInteraction
//
// Author: $author$
//   Date: 4/23/2007
///////////////////////////////////////////////////////////////////////
class CEvServletInteraction
: virtual public EvServletInteraction
{
public:
    typedef EvServletInteraction CImplements;
    typedef CEvServletInteraction CDerives;

    EvServletConnection& m_connection;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvServletInteraction
    //
    //       Author: $author$
    //         Date: 4/23/2007
    ///////////////////////////////////////////////////////////////////////
    CEvServletInteraction(EvServletConnection& connection)
    : m_connection(connection)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvServletInteraction
    //
    //      Author: $author$
    //        Date: 4/23/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvServletInteraction()
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetConnection
    //
    //   Author: $author$
    //     Date: 4/23/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvServletConnection& GetConnection() const
    {
        return (EvServletConnection&)(m_connection);
    }
};
#endif // _CEVSERVLETINTERACTION_HPP
