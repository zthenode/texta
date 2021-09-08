///////////////////////////////////////////////////////////////////////
//   File: cevhttppathservletallocatorfamily.cpp
//
// Author: $author$
//   Date: 6/12/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#include "cevhttppathservletallocatorfamily.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvHttpPathServletAllocatorList
//
// Author: $author$
//   Date: 6/12/2007
///////////////////////////////////////////////////////////////////////
template<> CEvHttpPathServletAllocatorItem* 
CEvHttpPathServletAllocatorList::CExtends::m_firstItem = 0;

template<> CEvHttpPathServletAllocatorItem* 
CEvHttpPathServletAllocatorList::CExtends::m_lastItem = 0;

///////////////////////////////////////////////////////////////////////
// Function: CEvHttpPathServletAllocatorList::GetInstance
//
//   Author: $author$
//     Date: 7/25/2007
///////////////////////////////////////////////////////////////////////
CEvHttpPathServletAllocatorList& CEvHttpPathServletAllocatorList::GetInstance() 
{
    static CEvHttpPathServletAllocatorList instance;
    return instance;
}
