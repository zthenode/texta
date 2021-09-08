///////////////////////////////////////////////////////////////////////
//   File: cevstopevcpservletallocator.hpp
//
// Author: $author$
//   Date: 5/11/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVSTOPEVCPSERVLETALLOCATOR_HPP
#define _CEVSTOPEVCPSERVLETALLOCATOR_HPP

#include "cevcpservletallocator.hpp"
#include "cevevcpservletallocatorfamily.hpp"
#include "cevstopevcpservlet.hpp"

///////////////////////////////////////////////////////////////////////
//  Typedef: CEvStopEvcpServletAllocator
//
//   Author: $author$
//     Date: 5/11/2007
///////////////////////////////////////////////////////////////////////
typedef CEvcpServletAllocatorT
<CEvStopEvcpServlet, EvcpServlet, 
 CEvEvcpServletAllocatorFamily>
CEvStopEvcpServletAllocator;

#endif // _CEVSTOPEVCPSERVLETALLOCATOR_HPP
