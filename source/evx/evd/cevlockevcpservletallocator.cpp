///////////////////////////////////////////////////////////////////////
//   File: cevlockevcpservletallocator.cpp
//
// Author: $author$
//   Date: 10/9/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#include "cevlockevcpservletallocator.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvLockEvcpServletAllocator
//
// Author: $author$
//   Date: 10/9/2007
///////////////////////////////////////////////////////////////////////
template<> CEvLockEvcpServletAllocator 
CEvLockEvcpServletAllocator::m_allocator;

#if defined(EV_NO_TEMPLATE_STATIC_MEMBERS) 
static CEvLockEvcpServletAllocator allocator;
#endif // defined(NO_TEMPLATE_STATIC_MEMBER_INSTANCES)
