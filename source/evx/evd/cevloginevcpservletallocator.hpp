///////////////////////////////////////////////////////////////////////
//   File: cevloginevcpservletallocator.hpp
//
// Author: $author$
//   Date: 10/13/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVLOGINEVCPSERVLETALLOCATOR_HPP
#define _CEVLOGINEVCPSERVLETALLOCATOR_HPP


#include "cevcpservletallocator.hpp"
#include "cevevcpservletallocatorfamily.hpp"
#include "cevloginevcpservlet.hpp"

///////////////////////////////////////////////////////////////////////
//  Typedef: CEvLoginEvcpServletAllocator
//
//   Author: $author$
//     Date: 10/13/2007
///////////////////////////////////////////////////////////////////////
typedef CEvcpServletAllocatorT
<CEvLoginEvcpServlet, EvcpServlet, 
 CEvEvcpServletAllocatorFamily>
CEvLoginEvcpServletAllocator;

#endif // _CEVLOGINEVCPSERVLETALLOCATOR_HPP
