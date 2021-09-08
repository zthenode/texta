///////////////////////////////////////////////////////////////////////
//   File: cevevcpsevcpservletallocator.hpp
//
// Author: $author$
//   Date: 12/6/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVEVCPSEVCPSERVLETALLOCATOR_HPP
#define _CEVEVCPSEVCPSERVLETALLOCATOR_HPP


#include "cevcpservletallocator.hpp"
#include "cevevcpservletallocatorfamily.hpp"
#include "cevevcpsevcpservlet.hpp"

///////////////////////////////////////////////////////////////////////
//  Typedef: CEvEvcpsEvcpServletAllocator
//
//   Author: $author$
//     Date: 12/6/2007
///////////////////////////////////////////////////////////////////////
typedef CEvcpServletAllocatorT
<CEvEvcpsEvcpServlet, EvcpServlet, 
 CEvEvcpServletAllocatorFamily>
CEvEvcpsEvcpServletAllocator;

#endif // _CEVEVCPSEVCPSERVLETALLOCATOR_HPP
