///////////////////////////////////////////////////////////////////////
//   File: cevcoevcpservletallocator.hpp
//
// Author: $author$
//   Date: 4/26/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCOEVCPSERVLETALLOCATOR_HPP
#define _CEVCOEVCPSERVLETALLOCATOR_HPP

#include "cevcpservletallocator.hpp"
#include "cevevcpservletallocatorfamily.hpp"
#include "cevcoevcpservlet.hpp"

///////////////////////////////////////////////////////////////////////
//  Typedef: CEvCoEvcpServletAllocator
//
//   Author: $author$
//     Date: 4/26/2007
///////////////////////////////////////////////////////////////////////
typedef CEvcpServletAllocatorT
<CEvCoEvcpServlet, EvcpServlet, 
 CEvEvcpServletAllocatorFamily>
CEvCoEvcpServletAllocator;

#endif // _CEVCOEVCPSERVLETALLOCATOR_HPP
