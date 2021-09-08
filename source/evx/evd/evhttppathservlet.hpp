///////////////////////////////////////////////////////////////////////
//   File: evhttppathservlet.hpp
//
// Author: $author$
//   Date: 6/12/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _EVHTTPPATHSERVLET_HPP
#define _EVHTTPPATHSERVLET_HPP

#include "evcpservlet.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: EvHttpPathServlet
//
// Author: $author$
//   Date: 6/12/2007
///////////////////////////////////////////////////////////////////////
class EV_EXPORT_CLASS EvHttpPathServlet
: virtual public EvcpServlet
{
public:
    typedef EvcpServlet CImplements;
    typedef EvHttpPathServlet CDerives;
};

#endif // _EVHTTPPATHSERVLET_HPP
