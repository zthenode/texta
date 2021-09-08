///////////////////////////////////////////////////////////////////////
//   File: cevgetevcpservletallocator.hpp
//
// Author: $author$
//   Date: 9/28/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVGETEVCPSERVLETALLOCATOR_HPP
#define _CEVGETEVCPSERVLETALLOCATOR_HPP

#include "cevcpservletallocator.hpp"
#include "cevevcpservletallocatorfamily.hpp"
#include "cevgetevcpservlet.hpp"

///////////////////////////////////////////////////////////////////////
//  Typedef: CEvGetEvcpServletAllocator
//
//   Author: $author$
//     Date: 9/28/2007
///////////////////////////////////////////////////////////////////////
typedef CEvcpServletAllocatorT
<CEvGetEvcpServlet, EvcpServlet, 
 CEvEvcpServletAllocatorFamily>
CEvGetEvcpServletAllocator;

#endif // _CEVGETEVCPSERVLETALLOCATOR_HPP
