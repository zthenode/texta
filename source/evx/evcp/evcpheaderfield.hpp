///////////////////////////////////////////////////////////////////////
//   File: evcpheaderfield.hpp
//
// Author: $author$
//   Date: 4/24/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _EVCPHEADERFIELD_HPP
#define _EVCPHEADERFIELD_HPP

#include "evcpheaderfield.h"
#include "evcpheaderline.hpp"
#include "evbase.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: EvcpHeaderField
//
// Author: $author$
//   Date: 4/24/2007
///////////////////////////////////////////////////////////////////////
class EV_EXPORT_CLASS EvcpHeaderField
: virtual public EvcpHeaderLine
{
public:
    typedef EvcpHeaderLine CImplements;
    typedef EvcpHeaderField CDerives;

    ///////////////////////////////////////////////////////////////////////
    // Function: CompareFieldName
    //
    //   Author: $author$
    //     Date: 4/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int CompareFieldName
    (const char* chars, LONG length=-1) const = 0;
    ///////////////////////////////////////////////////////////////////////
    // Function: SetFieldName
    //
    //   Author: $author$
    //     Date: 4/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG SetFieldName
    (const char* chars, LONG length=-1) = 0;
    ///////////////////////////////////////////////////////////////////////
    // Function: GetFieldName
    //
    //   Author: $author$
    //     Date: 4/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetFieldName
    (LONG& length) const = 0;

    ///////////////////////////////////////////////////////////////////////
    // Function: CompareFieldValue
    //
    //   Author: $author$
    //     Date: 4/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int CompareFieldValue
    (const char* chars, LONG length=-1) const = 0;

    ///////////////////////////////////////////////////////////////////////
    // Function: SetUnsignedFieldValue
    //
    //   Author: $author$
    //     Date: 5/18/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG SetUnsignedFieldValue
    (ULONG value) = 0;
    ///////////////////////////////////////////////////////////////////////
    // Function: SetSignedFieldValue
    //
    //   Author: $author$
    //     Date: 5/18/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG SetSignedFieldValue
    (LONG value) = 0;
    ///////////////////////////////////////////////////////////////////////
    // Function: SetFieldValue
    //
    //   Author: $author$
    //     Date: 4/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG SetFieldValue
    (const char* chars, LONG length=-1) = 0;
    ///////////////////////////////////////////////////////////////////////
    // Function: GetFieldValue
    //
    //   Author: $author$
    //     Date: 4/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetFieldValue
    (LONG& length) const = 0;
    ///////////////////////////////////////////////////////////////////////
    // Function: GetSignedFieldValue
    //
    //   Author: $author$
    //     Date: 4/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG GetSignedFieldValue(LONG& digits) const = 0;
    ///////////////////////////////////////////////////////////////////////
    // Function: GetUnsignedFieldValue
    //
    //   Author: $author$
    //     Date: 4/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ULONG GetUnsignedFieldValue(LONG& digits) const = 0;
};
#endif // _EVCPHEADERFIELD_HPP
