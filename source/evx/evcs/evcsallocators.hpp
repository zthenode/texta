///////////////////////////////////////////////////////////////////////
//   File: evcsallocators.hpp
//
// Author: $author$
//   Date: 5/28/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _EVCSALLOCATORS_HPP
#define _EVCSALLOCATORS_HPP

#include <vector>
#include "evcsallocator.hpp"

///////////////////////////////////////////////////////////////////////
//  Typedef: EvcsAllocators
//
//   Author: $author$
//     Date: 5/28/2007
///////////////////////////////////////////////////////////////////////
typedef ::std::vector<EvcsAllocator*>
EvcsAllocators;

///////////////////////////////////////////////////////////////////////
//  Typedef: EvcsAllocatorsIterator
//
//   Author: $author$
//     Date: 5/28/2007
///////////////////////////////////////////////////////////////////////
typedef EvcsAllocators::iterator
EvcsAllocatorsIterator;

///////////////////////////////////////////////////////////////////////
//  Typedef: const_EvcsAllocatorsIterator
//
//   Author: $author$
//     Date: 5/28/2007
///////////////////////////////////////////////////////////////////////
typedef EvcsAllocators::const_iterator
const_EvcsAllocatorsIterator;

#endif // _EVCSALLOCATORS_HPP