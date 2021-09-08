///////////////////////////////////////////////////////////////////////
//   File: cevrestartevcpservletallocator.hpp
//
// Author: $author$
//   Date: 8/5/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVRESTARTEVCPSERVLETALLOCATOR_HPP
#define _CEVRESTARTEVCPSERVLETALLOCATOR_HPP

#include "cevcpservletallocator.hpp"
#include "cevevcpservletallocatorfamily.hpp"
#include "cevrestartevcpservlet.hpp"

///////////////////////////////////////////////////////////////////////
//  Typedef: CEvRestartEvcpServletAllocator
//
//   Author: $author$
//     Date: 8/5/2007
///////////////////////////////////////////////////////////////////////
typedef CEvcpServletAllocatorT
<CEvRestartEvcpServlet, EvcpServlet, 
 CEvEvcpServletAllocatorFamily>
CEvRestartEvcpServletAllocator;

#endif // _CEVRESTARTEVCPSERVLETALLOCATOR_HPP
