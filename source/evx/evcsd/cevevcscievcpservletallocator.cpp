///////////////////////////////////////////////////////////////////////
//   File: cevevcscievcpservletallocator.cpp
//
// Author: $author$
//   Date: 7/31/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#include "cevevcscievcpservletallocator.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvEvcsCiEvcpServletAllocator
//
// Author: $author$
//   Date: 7/31/2007
///////////////////////////////////////////////////////////////////////
template<> CEvEvcsCiEvcpServletAllocator 
CEvEvcsCiEvcpServletAllocator::m_allocator;

#if defined(EV_NO_TEMPLATE_STATIC_MEMBERS) 
static CEvEvcsCiEvcpServletAllocator allocator;
#endif // defined(NO_TEMPLATE_STATIC_MEMBER_INSTANCES)
