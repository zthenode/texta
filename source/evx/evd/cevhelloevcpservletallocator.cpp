///////////////////////////////////////////////////////////////////////
//   File: cevhelloevcpservletallocator.cpp
//
// Author: $author$
//   Date: 8/14/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#include "cevhelloevcpservletallocator.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvHelloEvcpServletAllocator
//
// Author: $author$
//   Date: 8/14/2007
///////////////////////////////////////////////////////////////////////
template<> CEvHelloEvcpServletAllocator 
CEvHelloEvcpServletAllocator::m_allocator;

#if defined(EV_NO_TEMPLATE_STATIC_MEMBERS) 
static CEvHelloEvcpServletAllocator allocator;
#endif // defined(NO_TEMPLATE_STATIC_MEMBER_INSTANCES)
