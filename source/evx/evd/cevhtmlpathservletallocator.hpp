///////////////////////////////////////////////////////////////////////
//   File: cevhtmlpathservletallocator.hpp
//
// Author: $author$
//   Date: 6/12/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVHTMLPATHSERVLETALLOCATOR_HPP
#define _CEVHTMLPATHSERVLETALLOCATOR_HPP

#include "cevhttppathservletallocatorfamily.hpp"
#include "cevhtmlhttppathservlet.hpp"
#include "cevhttppathservlet.hpp"
#include "evhttppathservlet.hpp"

///////////////////////////////////////////////////////////////////////
//  Typedef: CEvHtmlHttpPathServletAllocator
//
//   Author: $author$
//     Date: 6/12/2007
///////////////////////////////////////////////////////////////////////
typedef CEvcpServletAllocatorT
<CEvHtmlHttpPathServlet, EvHttpPathServlet, 
 CEvHttpPathServletAllocatorFamily>
CEvHtmlHttpPathServletAllocator;

#endif // _CEVHTMLPATHSERVLETALLOCATOR_HPP
