///////////////////////////////////////////////////////////////////////
//   File: evcpservletresponse.hpp
//
// Author: $author$
//   Date: 4/21/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _EVCPSERVLETRESPONSE_HPP
#define _EVCPSERVLETRESPONSE_HPP

#include "evservletresponse.hpp"
#include "evcpservletinteraction.hpp"
#include "evcpheader.hpp"
#include "evcpresponse.h"

///////////////////////////////////////////////////////////////////////
//  Class: EvcpServletResponse
//
// Author: $author$
//   Date: 4/21/2007
///////////////////////////////////////////////////////////////////////
class EV_EXPORT_CLASS EvcpServletResponse
: virtual public EvServletResponse,
  virtual public EvcpServletInteraction
{
public:
    typedef EvServletResponse CImplements;
    typedef EvcpServletResponse CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Function: Write
    //
    //   Author: $author$
    //     Date: 4/25/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Write
    (EvCharWriter& writer, LONG length=-1) = 0;
    ///////////////////////////////////////////////////////////////////////
    // Function: GetHeader
    //
    //   Author: $author$
    //     Date: 4/23/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvcpHeader& GetHeader() const = 0;
};

#endif // _EVCPSERVLETRESPONSE_HPP
