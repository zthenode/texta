///////////////////////////////////////////////////////////////////////
//   File: evproperties.hpp
//
// Author: $author$
//   Date: 7/17/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _EVPROPERTIES_HPP
#define _EVPROPERTIES_HPP

#include "evproperty.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: EvProperties
//
// Author: $author$
//   Date: 7/17/2007
///////////////////////////////////////////////////////////////////////
class EV_EXPORT_CLASS EvProperties
: virtual public EvBase
{
public:
    typedef EvBase CImplements;
    typedef EvProperties CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Function: SetPropertyCharsById
    //
    //   Author: $author$
    //     Date: 7/17/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG SetPropertyCharsById
    (EvProperty::EvId id,
     const char* chars,
     LONG length=-1) = 0;
    ///////////////////////////////////////////////////////////////////////
    // Function: GetPropertyCharsById
    //
    //   Author: $author$
    //     Date: 7/17/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetPropertyCharsById
    (LONG& length,
     EvProperty::EvId id) const = 0;
    ///////////////////////////////////////////////////////////////////////
    // Function: GetPropertyUnsignedById
    //
    //   Author: $author$
    //     Date: 7/17/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError GetPropertyUnsignedById
    (ULONG& value, EvProperty::EvId id) const = 0;
    ///////////////////////////////////////////////////////////////////////
    // Function: GetPropertySignedById
    //
    //   Author: $author$
    //     Date: 7/17/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError GetPropertySignedById
    (LONG& value, EvProperty::EvId id) const = 0;
    ///////////////////////////////////////////////////////////////////////
    // Function: GetPropertyBoolById
    //
    //   Author: $author$
    //     Date: 7/17/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError GetPropertyBoolById
    (bool& value, EvProperty::EvId id) const = 0;
};
#endif // _EVPROPERTIES_HPP
