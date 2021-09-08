///////////////////////////////////////////////////////////////////////
//   File: evhttppathservletallocator.hpp
//
// Author: $author$
//   Date: 6/12/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _EVHTTPPATHSERVLETALLOCATOR_HPP
#define _EVHTTPPATHSERVLETALLOCATOR_HPP

#include "evcpservletallocator.hpp"
#include "evhttppathservlet.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: EvHttpPathServletAllocator
//
// Author: $author$
//   Date: 6/12/2007
///////////////////////////////////////////////////////////////////////
class EV_EXPORT_CLASS EvHttpPathServletAllocator
: virtual public EvcpServletAllocator
{
public:
    typedef EvcpServletAllocator CImplements;
    typedef EvHttpPathServletAllocator CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Function: AcquireServlet
    //
    //   Author: $author$
    //     Date: 6/12/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvHttpPathServlet* 
    AcquireServlet(EvError& error) = 0;
};

#endif // _EVHTTPPATHSERVLETALLOCATOR_HPP
