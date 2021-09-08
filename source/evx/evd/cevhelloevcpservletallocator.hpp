///////////////////////////////////////////////////////////////////////
//   File: cevhelloevcpservletallocator.hpp
//
// Author: $author$
//   Date: 8/14/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVHELLOEVCPSERVLETALLOCATOR_HPP
#define _CEVHELLOEVCPSERVLETALLOCATOR_HPP

#include "cevcpservletallocator.hpp"
#include "cevevcpservletallocatorfamily.hpp"
#include "cevhelloevcpservlet.hpp"

///////////////////////////////////////////////////////////////////////
//  Typedef: CEvHelloEvcpServletAllocator
//
//   Author: $author$
//     Date: 8/14/2007
///////////////////////////////////////////////////////////////////////
typedef CEvcpServletAllocatorT
<CEvHelloEvcpServlet, EvcpServlet, 
 CEvEvcpServletAllocatorFamily>
CEvHelloEvcpServletAllocator;

#endif // _CEVHELLOEVCPSERVLETALLOCATOR_HPP
