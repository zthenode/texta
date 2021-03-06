///////////////////////////////////////////////////////////////////////
//   File: evwstring.hpp
//
// Author: $author$
//   Date: 5/7/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _EVWSTRING_HPP
#define _EVWSTRING_HPP

#include "evstringt.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: EvWString
//
// Author: $author$
//   Date: 5/7/2007
///////////////////////////////////////////////////////////////////////
class EV_EXPORT_CLASS EvWString
: virtual public EvStringT<WCHAR>
{
public:
    typedef EvStringT<WCHAR> CImplements;
    typedef EvWString CDerives;
};
#endif // _EVWSTRING_HPP
