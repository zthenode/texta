///////////////////////////////////////////////////////////////////////
//   File: evcscontent.hpp
//
// Author: $author$
//   Date: 10/4/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _EVCSCONTENT_HPP
#define _EVCSCONTENT_HPP

#include "evinstance.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: EvcsContent
//
// Author: $author$
//   Date: 10/4/2007
///////////////////////////////////////////////////////////////////////
class EV_EXPORT_CLASS EvcsContent
: virtual public EvInstance
{
public:
    typedef EvInstance CImplements;
    typedef EvcsContent CDerives;

    typedef int Type;
    ///////////////////////////////////////////////////////////////////////
    //   Enum:  
    //
    // Author: $author$
    //   Date: 10/4/2007
    ///////////////////////////////////////////////////////////////////////
    enum 
    {
        EV_TYPE_NONE = 0,

        EV_TYPE_TEXT = (1<<0),
        EV_TYPE_BINARY = (1<<1),
        EV_TYPE_IMAGE = (1<<2),

        EV_TYPE_NEXT,
        EV_TYPE_LAST = (EV_TYPE_NEXT-1),

        EV_TYPE_ANY  = ((EV_TYPE_LAST<<1)-1)
    };

    ///////////////////////////////////////////////////////////////////////
    //   Enum:  
    //
    // Author: $author$
    //   Date: 10/4/2007
    ///////////////////////////////////////////////////////////////////////
    enum 
    {
        EV_TYPE_TEXT_PLAIN = 0,
        EV_TYPE_TEXT_HTML  = (1<<0),
        EV_TYPE_TEXT_XML   = (1<<1),

        EV_TYPE_TEXT_NEXT,
        EV_TYPE_TEXT_LAST  = (EV_TYPE_TEXT_NEXT-1),

        EV_TYPE_TEXT_ANY   = ((EV_TYPE_TEXT_LAST<<1)-1)
    };
};
#endif // _EVCSCONTENT_HPP
