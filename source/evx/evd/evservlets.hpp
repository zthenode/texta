///////////////////////////////////////////////////////////////////////
//   File: evservlets.hpp
//
// Author: $author$
//   Date: 9/19/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _EVSERVLETS_HPP
#define _EVSERVLETS_HPP

#include <vector>
#include "evservlet.hpp"

///////////////////////////////////////////////////////////////////////
//  Typedef: EvServlets
//
//   Author: $author$
//     Date: 9/19/2007
///////////////////////////////////////////////////////////////////////
typedef ::std::vector
<EvServlet*>
EvServlets;

///////////////////////////////////////////////////////////////////////
//  Typedef: EvServletsIterator
//
//   Author: $author$
//     Date: 9/19/2007
///////////////////////////////////////////////////////////////////////
typedef EvServlets::iterator
EvServletsIterator;

///////////////////////////////////////////////////////////////////////
//  Typedef: const_EvServletsIterator
//
//   Author: $author$
//     Date: 9/19/2007
///////////////////////////////////////////////////////////////////////
typedef EvServlets::const_iterator
const_EvServletsIterator;

#endif // _EVSERVLETS_HPP
