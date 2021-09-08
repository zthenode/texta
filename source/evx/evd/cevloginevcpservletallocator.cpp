///////////////////////////////////////////////////////////////////////
//   File: cevloginevcpservletallocator.cpp
//
// Author: $author$
//   Date: 10/13/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#include "cevloginevcpservletallocator.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvLoginEvcpServletAllocator
//
// Author: $author$
//   Date: 10/13/2007
///////////////////////////////////////////////////////////////////////
template<> CEvLoginEvcpServletAllocator 
CEvLoginEvcpServletAllocator::m_allocator;

#if defined(EV_NO_TEMPLATE_STATIC_MEMBERS) 
static CEvLoginEvcpServletAllocator allocator;
#endif // defined(NO_TEMPLATE_STATIC_MEMBER_INSTANCES)
