///////////////////////////////////////////////////////////////////////
//   File: cevposthttpservletallocator.hpp
//
// Author: $author$
//   Date: 4/26/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVPOSTHTTPSERVLETALLOCATOR_HPP
#define _CEVPOSTHTTPSERVLETALLOCATOR_HPP

#include "cevcpservletallocator.hpp"
#include "cevhttpservletallocatorfamily.hpp"
#include "cevposthttpservlet.hpp"

///////////////////////////////////////////////////////////////////////
//  Typedef: CEvPostHttpServletAllocator
//
//   Author: $author$
//     Date: 4/26/2007
///////////////////////////////////////////////////////////////////////
typedef CEvcpServletAllocatorT
<CEvPostHttpServlet, EvcpServlet, 
 CEvHttpServletAllocatorFamily>
CEvPostHttpServletAllocator;

#endif // _CEVPOSTHTTPSERVLETALLOCATOR_HPP
