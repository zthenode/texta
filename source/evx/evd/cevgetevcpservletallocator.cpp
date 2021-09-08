///////////////////////////////////////////////////////////////////////
//   File: cevgetevcpservletallocator.cpp
//
// Author: $author$
//   Date: 9/28/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#include "cevgetevcpservletallocator.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvGetEvcpServletAllocator
//
// Author: $author$
//   Date: 9/28/2007
///////////////////////////////////////////////////////////////////////
template<> CEvGetEvcpServletAllocator 
CEvGetEvcpServletAllocator::m_allocator;

#if defined(EV_NO_TEMPLATE_STATIC_MEMBERS) 
static CEvGetEvcpServletAllocator allocator;
#endif // defined(NO_TEMPLATE_STATIC_MEMBER_INSTANCES)
