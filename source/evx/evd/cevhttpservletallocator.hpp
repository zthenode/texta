///////////////////////////////////////////////////////////////////////
//   File: cevhttpservletallocator.hpp
//
// Author: $author$
//   Date: 4/22/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVHTTPSERVLETALLOCATOR_HPP
#define _CEVHTTPSERVLETALLOCATOR_HPP

#include "cevcpservletallocator.hpp"
#include "cevhttpservlet.hpp"

///////////////////////////////////////////////////////////////////////
//  Typedef: CEvHttpServletAllocator
//
//   Author: $author$
//     Date: 4/25/2007
///////////////////////////////////////////////////////////////////////
typedef CEvcpServletAllocatorT
<CEvHttpServlet, EvcpServlet, 
 CEvcpServletAllocatorFamily>
CEvHttpServletAllocator;

#endif // _CEVHTTPSERVLETALLOCATOR_HPP
