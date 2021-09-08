///////////////////////////////////////////////////////////////////////
//   File: cevputevcpservletallocator.hpp
//
// Author: $author$
//   Date: 10/5/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVPUTEVCPSERVLETALLOCATOR_HPP
#define _CEVPUTEVCPSERVLETALLOCATOR_HPP


#include "cevcpservletallocator.hpp"
#include "cevevcpservletallocatorfamily.hpp"
#include "cevputevcpservlet.hpp"

///////////////////////////////////////////////////////////////////////
//  Typedef: CEvPutEvcpServletAllocator
//
//   Author: $author$
//     Date: 10/5/2007
///////////////////////////////////////////////////////////////////////
typedef CEvcpServletAllocatorT
<CEvPutEvcpServlet, EvcpServlet, 
 CEvEvcpServletAllocatorFamily>
CEvPutEvcpServletAllocator;

#endif // _CEVPUTEVCPSERVLETALLOCATOR_HPP
