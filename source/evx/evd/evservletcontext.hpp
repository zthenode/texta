///////////////////////////////////////////////////////////////////////
//   File: evservletcontext.hpp
//
// Author: $author$
//   Date: 4/27/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _EVSERVLETCONTEXT_HPP
#define _EVSERVLETCONTEXT_HPP

#include <vector>
#include "evinitializer.hpp"
#include "evfinalizer.hpp"
#include "evinstance.hpp"

class EV_EXPORT_CLASS EvServlet;

///////////////////////////////////////////////////////////////////////
//  Class: EvServletContext
//
// Author: $author$
//   Date: 4/27/2007
///////////////////////////////////////////////////////////////////////
class EV_EXPORT_CLASS EvServletContext
: virtual public EvInitializer,
  virtual public EvFinalizer,
  virtual public EvInstance
{
public:
    typedef EvInitializer CInitImplements;
    typedef EvFinalizer CFinalImplements;
    typedef EvInstance CImplements;
    typedef EvServletContext CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Function: GetServlet
    //
    //   Author: $author$
    //     Date: 4/27/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const EvServlet& GetServlet() const = 0;
};

///////////////////////////////////////////////////////////////////////
//  Typedef: EvServletContexts
//
//   Author: $author$
//     Date: 4/27/2007
///////////////////////////////////////////////////////////////////////
typedef ::std::vector
<EvServletContext*>
EvServletContexts;

///////////////////////////////////////////////////////////////////////
//  Typedef: EvServletContextsIterator
//
//   Author: $author$
//     Date: 6/12/2007
///////////////////////////////////////////////////////////////////////
typedef EvServletContexts::iterator
EvServletContextsIterator;

///////////////////////////////////////////////////////////////////////
//  Typedef: const_EvServletContextsIterator
//
//   Author: $author$
//     Date: 6/12/2007
///////////////////////////////////////////////////////////////////////
typedef EvServletContexts::const_iterator
const_EvServletContextsIterator;

#endif // _EVSERVLETCONTEXT_HPP
