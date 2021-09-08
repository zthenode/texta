///////////////////////////////////////////////////////////////////////
//   File: cevstopevcpservletallocator.cpp
//
// Author: $author$
//   Date: 5/11/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#include "cevstopevcpservletallocator.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvStopEvcpServletAllocator
//
// Author: $author$
//   Date: 5/11/2007
///////////////////////////////////////////////////////////////////////
template<> CEvStopEvcpServletAllocator 
CEvStopEvcpServletAllocator::m_allocator;

#if defined(EV_NO_TEMPLATE_STATIC_MEMBERS) 
static CEvStopEvcpServletAllocator allocator;
#endif // defined(NO_TEMPLATE_STATIC_MEMBER_INSTANCES)
