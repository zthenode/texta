///////////////////////////////////////////////////////////////////////
//   File: cevlockevcpservletallocator.hpp
//
// Author: $author$
//   Date: 10/9/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVLOCKEVCPSERVLETALLOCATOR_HPP
#define _CEVLOCKEVCPSERVLETALLOCATOR_HPP

#include "cevcpservletallocator.hpp"
#include "cevevcpservletallocatorfamily.hpp"
#include "cevlockevcpservlet.hpp"

///////////////////////////////////////////////////////////////////////
//  Typedef: CEvLockEvcpServletAllocator
//
//   Author: $author$
//     Date: 10/9/2007
///////////////////////////////////////////////////////////////////////
typedef CEvcpServletAllocatorT
<CEvLockEvcpServlet, EvcpServlet, 
 CEvEvcpServletAllocatorFamily>
CEvLockEvcpServletAllocator;

#endif // _CEVLOCKEVCPSERVLETALLOCATOR_HPP
