///////////////////////////////////////////////////////////////////////
//   File: cevevcpsevcpservletallocator.cpp
//
// Author: $author$
//   Date: 12/6/2007
///////////////////////////////////////////////////////////////////////

#include "cevevcpsevcpservletallocator.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvEvcpsEvcpServletAllocator
//
// Author: $author$
//   Date: 12/6/2007
///////////////////////////////////////////////////////////////////////
template<> CEvEvcpsEvcpServletAllocator 
CEvEvcpsEvcpServletAllocator::m_allocator;

#if defined(EV_NO_TEMPLATE_STATIC_MEMBERS) 
static CEvEvcpsEvcpServletAllocator allocator;
#endif // defined(NO_TEMPLATE_STATIC_MEMBER_INSTANCES)
