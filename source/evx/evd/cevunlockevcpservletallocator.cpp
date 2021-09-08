///////////////////////////////////////////////////////////////////////
//   File: cevunlockevcpservletallocator.cpp
//
// Author: $author$
//   Date: 10/9/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#include "cevunlockevcpservletallocator.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvUnlockEvcpServletAllocator
//
// Author: $author$
//   Date: 10/9/2007
///////////////////////////////////////////////////////////////////////
template<> CEvUnlockEvcpServletAllocator 
CEvUnlockEvcpServletAllocator::m_allocator;

#if defined(EV_NO_TEMPLATE_STATIC_MEMBERS) 
static CEvUnlockEvcpServletAllocator allocator;
#endif // defined(NO_TEMPLATE_STATIC_MEMBER_INSTANCES)
