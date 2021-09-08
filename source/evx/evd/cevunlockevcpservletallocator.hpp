///////////////////////////////////////////////////////////////////////
//   File: cevunlockevcpservletallocator.hpp
//
// Author: $author$
//   Date: 10/9/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVUNLOCKEVCPSERVLETALLOCATOR_HPP
#define _CEVUNLOCKEVCPSERVLETALLOCATOR_HPP

#include "cevcpservletallocator.hpp"
#include "cevevcpservletallocatorfamily.hpp"
#include "cevunlockevcpservlet.hpp"

///////////////////////////////////////////////////////////////////////
//  Typedef: CEvUnlockEvcpServletAllocator
//
//   Author: $author$
//     Date: 10/9/2007
///////////////////////////////////////////////////////////////////////
typedef CEvcpServletAllocatorT
<CEvUnlockEvcpServlet, EvcpServlet, 
 CEvEvcpServletAllocatorFamily>
CEvUnlockEvcpServletAllocator;

#endif // _CEVUNLOCKEVCPSERVLETALLOCATOR_HPP
