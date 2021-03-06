///////////////////////////////////////////////////////////////////////
//   File: evcsdos.hpp
//
// Author: $author$
//   Date: 10/8/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _EVCSDOS_HPP
#define _EVCSDOS_HPP

#include <vector>
#include "evcsdo.hpp"

///////////////////////////////////////////////////////////////////////
//  Typedef: EvcsDos
//
//   Author: $author$
//     Date: 10/8/2007
///////////////////////////////////////////////////////////////////////
typedef ::std::vector<EvcsDo*>
EvcsDos;

///////////////////////////////////////////////////////////////////////
//  Typedef: EvcsDosIterator
//
//   Author: $author$
//     Date: 10/8/2007
///////////////////////////////////////////////////////////////////////
typedef EvcsDos::iterator
EvcsDosIterator;

///////////////////////////////////////////////////////////////////////
//  Typedef: const_EvcsDosIterator
//
//   Author: $author$
//     Date: 10/8/2007
///////////////////////////////////////////////////////////////////////
typedef EvcsDos::const_iterator
const_EvcsDosIterator;

#endif // _EVCSDOS_HPP
