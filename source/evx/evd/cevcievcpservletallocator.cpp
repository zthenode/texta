///////////////////////////////////////////////////////////////////////
//   File: cevcievcpservletallocator.cpp
//
// Author: $author$
//   Date: 4/26/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#include "cevcievcpservletallocator.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvCiEvcpServletAllocator
//
// Author: $author$
//   Date: 4/26/2007
///////////////////////////////////////////////////////////////////////
template<> CEvCiEvcpServletAllocator 
CEvCiEvcpServletAllocator::m_allocator;

#if defined(EV_NO_TEMPLATE_STATIC_MEMBERS) 
static CEvCiEvcpServletAllocator allocator;
#endif // defined(NO_TEMPLATE_STATIC_MEMBER_INSTANCES)
