///////////////////////////////////////////////////////////////////////
//   File: evhttpservletallocator.hpp
//
// Author: $author$
//   Date: 6/12/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _EVHTTPSERVLETALLOCATOR_HPP
#define _EVHTTPSERVLETALLOCATOR_HPP

#include "evservletallocator.hpp"
#include "evhttpservlet.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: EvHttpServletAllocator
//
// Author: $author$
//   Date: 6/12/2007
///////////////////////////////////////////////////////////////////////
class EV_EXPORT_CLASS EvHttpServletAllocator
: virtual public EvServletAllocator
{
public:
    typedef EvServletAllocator CImplements;
    typedef EvHttpServletAllocator CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Function: AcquireServlet
    //
    //   Author: $author$
    //     Date: 6/12/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvHttpServlet* AcquireServlet
    (EvError& error) = 0;
};

#endif // _EVHTTPSERVLETALLOCATOR_HPP
