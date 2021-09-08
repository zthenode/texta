///////////////////////////////////////////////////////////////////////
//   File: cevcievcpservletallocator.hpp
//
// Author: $author$
//   Date: 4/26/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCIEVCPSERVLETALLOCATOR_HPP
#define _CEVCIEVCPSERVLETALLOCATOR_HPP

#include "cevcpservletallocator.hpp"
#include "cevevcpservletallocatorfamily.hpp"
#include "cevcievcpservlet.hpp"

///////////////////////////////////////////////////////////////////////
//  Typedef: CEvCiEvcpServletAllocator
//
//   Author: $author$
//     Date: 4/26/2007
///////////////////////////////////////////////////////////////////////
typedef CEvcpServletAllocatorT
<CEvCiEvcpServlet, EvcpServlet, 
 CEvEvcpServletAllocatorFamily>
CEvCiEvcpServletAllocator;

#endif // _CEVCIEVCPSERVLETALLOCATOR_HPP
