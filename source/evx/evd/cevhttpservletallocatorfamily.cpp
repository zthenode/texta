///////////////////////////////////////////////////////////////////////
//   File: cevhttpservletallocatorfamily.cpp
//
// Author: $author$
//   Date: 4/27/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#include "cevhttpservletallocatorfamily.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvHttpServletAllocatorList
//
// Author: $author$
//   Date: 4/27/2007
///////////////////////////////////////////////////////////////////////
template<> CEvHttpServletAllocatorItem* 
CEvHttpServletAllocatorList::CExtends::m_firstItem = 0;

template<> CEvHttpServletAllocatorItem* 
CEvHttpServletAllocatorList::CExtends::m_lastItem = 0;

///////////////////////////////////////////////////////////////////////
// Function: CEvHttpServletAllocatorList::GetInstance
//
//   Author: $author$
//     Date: 7/25/2007
///////////////////////////////////////////////////////////////////////
CEvHttpServletAllocatorList& CEvHttpServletAllocatorList::GetInstance() 
{
    static CEvHttpServletAllocatorList instance;
    return instance;
}
