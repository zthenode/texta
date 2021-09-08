///////////////////////////////////////////////////////////////////////
//   File: cevcoevcpservletallocator.cpp
//
// Author: $author$
//   Date: 4/26/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#include "cevcoevcpservletallocator.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvCoEvcpServletAllocator
//
// Author: $author$
//   Date: 4/26/2007
///////////////////////////////////////////////////////////////////////
template<> CEvCoEvcpServletAllocator 
CEvCoEvcpServletAllocator::m_allocator;

#if defined(EV_NO_TEMPLATE_STATIC_MEMBERS) 
static CEvCoEvcpServletAllocator allocator;
#endif // defined(NO_TEMPLATE_STATIC_MEMBER_INSTANCES)
