///////////////////////////////////////////////////////////////////////
//   File: cevevcpservletallocator.cpp
//
// Author: $author$
//   Date: 4/22/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#include "cevevcpservletallocator.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvEvcpServletAllocator
//
// Author: $author$
//   Date: 4/22/2007
///////////////////////////////////////////////////////////////////////
template<> CEvEvcpServletAllocator 
CEvEvcpServletAllocator::m_allocator;

#if defined(EV_NO_TEMPLATE_STATIC_MEMBERS) 
static CEvEvcpServletAllocator allocator;
#endif // defined(NO_TEMPLATE_STATIC_MEMBER_INSTANCES)
