///////////////////////////////////////////////////////////////////////
//   File: evcscheck.hpp
//
// Author: $author$
//   Date: 8/16/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _EVCSCHECK_HPP
#define _EVCSCHECK_HPP

#include "evcsop.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: EvcsCheck
//
// Author: $author$
//   Date: 8/16/2007
///////////////////////////////////////////////////////////////////////
class EV_EXPORT_CLASS EvcsCheck
: virtual public EvcsOp
{
public:
    typedef EvcsOp CImplements;
    typedef EvcsCheck CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Function: SetIsBinary
    //
    //   Author: $author$
    //     Date: 5/31/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int SetIsBinary(bool is=true) = 0;
    ///////////////////////////////////////////////////////////////////////
    // Function: GetIsBinary
    //
    //   Author: $author$
    //     Date: 5/31/2007
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetIsBinary() const = 0;
};

#endif // _EVCSCHECK_HPP