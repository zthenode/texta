///////////////////////////////////////////////////////////////////////
//   File: cevgethttpservletallocator.hpp
//
// Author: $author$
//   Date: 4/26/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVGETHTTPSERVLETALLOCATOR_HPP
#define _CEVGETHTTPSERVLETALLOCATOR_HPP

#include "cevcpservletallocator.hpp"
#include "cevhttpservletallocatorfamily.hpp"
#include "cevgethttpservlet.hpp"

///////////////////////////////////////////////////////////////////////
//  Typedef: CEvGetHttpServletAllocator
//
//   Author: $author$
//     Date: 4/26/2007
///////////////////////////////////////////////////////////////////////
typedef CEvcpServletAllocatorT
<CEvGetHttpServlet, EvcpServlet, 
 CEvHttpServletAllocatorFamily>
CEvGetHttpServletAllocator;

#endif // _CEVGETHTTPSERVLETALLOCATOR_HPP
