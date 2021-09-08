///////////////////////////////////////////////////////////////////////
//   File: cevdoevcpservletallocator.hpp
//
// Author: $author$
//   Date: 5/23/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVDOEVCPSERVLETALLOCATOR_HPP
#define _CEVDOEVCPSERVLETALLOCATOR_HPP

#include "cevcpservletallocator.hpp"
#include "cevevcpservletallocatorfamily.hpp"
#include "cevdoevcpservlet.hpp"

///////////////////////////////////////////////////////////////////////
//  Typedef: CEvDoEvcpServletAllocator
//
//   Author: $author$
//     Date: 5/23/2007
///////////////////////////////////////////////////////////////////////
typedef CEvcpServletAllocatorT
<CEvDoEvcpServlet, EvcpServlet, 
 CEvEvcpServletAllocatorFamily>
CEvDoEvcpServletAllocator;

#endif // _CEVDOEVCPSERVLETALLOCATOR_HPP
