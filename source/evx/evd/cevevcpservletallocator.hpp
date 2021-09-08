///////////////////////////////////////////////////////////////////////
//   File: cevevcpservletallocator.hpp
//
// Author: $author$
//   Date: 4/22/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVEVCPSERVLETALLOCATOR_HPP
#define _CEVEVCPSERVLETALLOCATOR_HPP

#include "cevcpservletallocator.hpp"
#include "cevevcpservlet.hpp"

///////////////////////////////////////////////////////////////////////
//  Typedef: CEvEvcpServletAllocator
//
//   Author: $author$
//     Date: 4/25/2007
///////////////////////////////////////////////////////////////////////
typedef CEvcpServletAllocatorT
<CEvEvcpServlet, EvcpServlet, 
 CEvcpServletAllocatorFamily>
CEvEvcpServletAllocator;

#endif // _CEVEVCPSERVLETALLOCATOR_HPP
