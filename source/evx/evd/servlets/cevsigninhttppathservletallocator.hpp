///////////////////////////////////////////////////////////////////////
//   File: cevsigninhttppathservletallocator.hpp
//
// Author: $author$
//   Date: 2/1/2012
///////////////////////////////////////////////////////////////////////

#ifndef _CEVSIGNINHTTPPATHSERVLETALLOCATOR_HPP
#define _CEVSIGNINHTTPPATHSERVLETALLOCATOR_HPP

#include "cevhttppathservletallocatorfamily.hpp"
#include "cevsigninhttppathservlet.hpp"
#include "cevhttppathservlet.hpp"
#include "evhttppathservlet.hpp"

///////////////////////////////////////////////////////////////////////
//  Typedef: CEvSignInHttpPathServletAllocator
//
//   Author: $author$
//     Date: 2/1/2012
///////////////////////////////////////////////////////////////////////
typedef CEvcpServletAllocatorT
<CEvSignInHttpPathServlet, EvHttpPathServlet, 
 CEvHttpPathServletAllocatorFamily>
CEvSignInHttpPathServletAllocator;

#endif // _CEVSIGNINHTTPPATHSERVLETALLOCATOR_HPP

        

