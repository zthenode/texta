///////////////////////////////////////////////////////////////////////
//   File: cevdoevcpservletallocator.cpp
//
// Author: $author$
//   Date: 5/23/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#include "cevdoevcpservletallocator.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvDoEvcpServletAllocator
//
// Author: $author$
//   Date: 5/23/2007
///////////////////////////////////////////////////////////////////////
template<> CEvDoEvcpServletAllocator 
CEvDoEvcpServletAllocator::m_allocator;

#if defined(EV_NO_TEMPLATE_STATIC_MEMBERS) 
static CEvDoEvcpServletAllocator allocator;
#endif // defined(NO_TEMPLATE_STATIC_MEMBER_INSTANCES)
