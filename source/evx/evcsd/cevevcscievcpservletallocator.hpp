///////////////////////////////////////////////////////////////////////
//   File: cevevcscievcpservletallocator.hpp
//
// Author: $author$
//   Date: 7/31/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVEVCSCIEVCPSERVLETALLOCATOR_HPP
#define _CEVEVCSCIEVCPSERVLETALLOCATOR_HPP

#include "cevcpservletallocator.hpp"
#include "cevevcpservletallocatorfamily.hpp"
#include "cevevcscievcpservlet.hpp"

///////////////////////////////////////////////////////////////////////
//  Typedef: CEvEvcsCiEvcpServletAllocator
//
//   Author: $author$
//     Date: 7/31/2007
///////////////////////////////////////////////////////////////////////
typedef CEvcpServletAllocatorT
<CEvEvcsCiEvcpServlet, EvcpServlet, 
 CEvEvcpServletAllocatorFamily>
CEvEvcsCiEvcpServletAllocator;

#endif // _CEVEVCSCIEVCPSERVLETALLOCATOR_HPP
