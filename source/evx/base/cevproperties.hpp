///////////////////////////////////////////////////////////////////////
//   File: cevproperties.hpp
//
// Author: $author$
//   Date: 7/17/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVPROPERTIES_HPP
#define _CEVPROPERTIES_HPP

#include "evproperties.hpp"
#include "cevbase.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvProperties
//
// Author: $author$
//   Date: 7/17/2007
///////////////////////////////////////////////////////////////////////
class CEvProperties
: virtual public EvProperties,
  public CEvBase
{
public:
    typedef EvProperties CImplements;
    typedef CEvBase CExtends;
    typedef CEvProperties CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvProperties
    //
    //       Author: $author$
    //         Date: 7/17/2007
    ///////////////////////////////////////////////////////////////////////
    CEvProperties() 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvProperties
    //
    //      Author: $author$
    //        Date: 7/17/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvProperties()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetPropertyCharsById
    //
    //   Author: $author$
    //     Date: 7/17/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG SetPropertyCharsById
    (EvProperty::EvId id,
     const char* chars,
     LONG length=-1) 
    {
        length = -EV_ERROR_NOT_IMPLEMENTED;
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetPropertyCharsById
    //
    //   Author: $author$
    //     Date: 7/17/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetPropertyCharsById
    (LONG& length,
     EvProperty::EvId id) const 
    {
        const char* chars = 0;
        length = -EV_ERROR_NOT_IMPLEMENTED;
        return chars;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetPropertyUnsignedById
    //
    //   Author: $author$
    //     Date: 7/17/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError GetPropertyUnsignedById
    (ULONG& value, EvProperty::EvId id) const 
    {
        EvError error = EV_ERROR_NOT_IMPLEMENTED;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetPropertySignedById
    //
    //   Author: $author$
    //     Date: 7/17/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError GetPropertySignedById
    (LONG& value, EvProperty::EvId id) const 
    {
        EvError error = EV_ERROR_NOT_IMPLEMENTED;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetPropertyBoolById
    //
    //   Author: $author$
    //     Date: 7/17/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError GetPropertyBoolById
    (bool& value, EvProperty::EvId id) const 
    {
        EvError error = EV_ERROR_NOT_IMPLEMENTED;
        return error;
    }
};
#endif // _CEVPROPERTIES_HPP
