///////////////////////////////////////////////////////////////////////
//   File: evciservletcontext.hpp
//
// Author: $author$
//   Date: 6/3/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _EVCISERVLETCONTEXT_HPP
#define _EVCISERVLETCONTEXT_HPP

#include "evcservletcontext.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: EvCiServletContext
//
// Author: $author$
//   Date: 6/3/2007
///////////////////////////////////////////////////////////////////////
class EV_EXPORT_CLASS EvCiServletContext
: virtual public EvCServletContext
{
public:
    typedef EvCServletContext CImplements;
    typedef EvCiServletContext CDerives;
};
#endif // _EVCISERVLETCONTEXT_HPP
