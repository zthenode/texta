///////////////////////////////////////////////////////////////////////
//   File: cevcpsshortopaque.hpp
//
// Author: $author$
//   Date: 11/26/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCPSSHORTOPAQUE_HPP
#define _CEVCPSSHORTOPAQUE_HPP

#include "cevcpsopaque.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpsSHORTOpaque
//
// Author: $author$
//   Date: 11/26/2007
///////////////////////////////////////////////////////////////////////
class CEvcpsSHORTOpaque
: public CEvcpsOpaque<SHORT>
{
public:
    typedef CEvcpsOpaque<SHORT> CExtends;
    typedef CEvcpsSHORTOpaque CDerives;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpsSHORTOpaque
    //
    //       Author: $author$
    //         Date: 11/26/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpsSHORTOpaque
    (const BYTE* chars=0, LONG length=-1) 
    : CExtends(chars, length)
    {
    }
};

#endif // _CEVCPSSHORTOPAQUE_HPP
