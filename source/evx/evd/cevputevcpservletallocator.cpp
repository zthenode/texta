///////////////////////////////////////////////////////////////////////
//   File: cevputevcpservletallocator.cpp
//
// Author: $author$
//   Date: 10/5/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#include "cevputevcpservletallocator.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvPutEvcpServletAllocator
//
// Author: $author$
//   Date: 10/5/2007
///////////////////////////////////////////////////////////////////////
template<> CEvPutEvcpServletAllocator 
CEvPutEvcpServletAllocator::m_allocator;

#if defined(EV_NO_TEMPLATE_STATIC_MEMBERS) 
static CEvPutEvcpServletAllocator allocator;
#endif // defined(NO_TEMPLATE_STATIC_MEMBER_INSTANCES)
