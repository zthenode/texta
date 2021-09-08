///////////////////////////////////////////////////////////////////////
//   File: evcpservletallocator.hpp
//
// Author: $author$
//   Date: 4/22/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _EVCPSERVLETALLOCATOR_HPP
#define _EVCPSERVLETALLOCATOR_HPP

#include "evservletallocator.hpp"
#include "evcpservlet.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: EvcpServletAllocator
//
// Author: $author$
//   Date: 4/22/2007
///////////////////////////////////////////////////////////////////////
class EV_EXPORT_CLASS EvcpServletAllocator
: virtual public EvServletAllocator
{
public:
    typedef EvServletAllocator CImplements;
    typedef EvcpServletAllocator CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Function: AcquireServlet
    //
    //   Author: $author$
    //     Date: 4/22/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvcpServlet* AcquireServlet
    (EvError& error) = 0;
};

#endif // _EVCPSERVLETALLOCATOR_HPP
