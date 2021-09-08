///////////////////////////////////////////////////////////////////////
//   File: cevrestartevcpservletallocator.cpp
//
// Author: $author$
//   Date: 8/5/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#include "cevrestartevcpservletallocator.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvRestartEvcpServletAllocator
//
// Author: $author$
//   Date: 8/5/2007
///////////////////////////////////////////////////////////////////////
template<> CEvRestartEvcpServletAllocator 
CEvRestartEvcpServletAllocator::m_allocator;

#if defined(EV_NO_TEMPLATE_STATIC_MEMBERS) 
static CEvRestartEvcpServletAllocator allocator;
#endif // defined(NO_TEMPLATE_STATIC_MEMBER_INSTANCES)

