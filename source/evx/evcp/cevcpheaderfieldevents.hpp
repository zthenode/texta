///////////////////////////////////////////////////////////////////////
//   File: cevcpheaderfieldevents.hpp
//
// Author: $author$
//   Date: 4/23/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCPHEADERFIELDEVENTS_HPP
#define _CEVCPHEADERFIELDEVENTS_HPP

#include "evcpheaderfieldevents.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpHeaderFieldEvents
//
// Author: $author$
//   Date: 4/23/2007
///////////////////////////////////////////////////////////////////////
class CEvcpHeaderFieldEvents
: virtual public EvcpHeaderFieldEvents
{
public:
    typedef EvcpHeaderFieldEvents CImplements;
    typedef CEvcpHeaderFieldEvents CDerives;

    EvcpHeaderFieldEvents& m_events;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpHeaderFieldEvents
    //
    //       Author: $author$
    //         Date: 4/23/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpHeaderFieldEvents(EvcpHeaderFieldEvents& events)
    : m_events(events)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: OnFieldName
    //
    //   Author: $author$
    //     Date: 4/23/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnFieldName
    (const char* chars) 
    {
        EvError error = m_events.OnFieldName(chars);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: OnFieldValue
    //
    //   Author: $author$
    //     Date: 4/23/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnFieldValue
    (const char* chars) 
    {
        EvError error = m_events.OnFieldValue(chars);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: OnFieldCR
    //
    //   Author: $author$
    //     Date: 5/16/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnFieldCR
    (const char* chars) 
    {
        EvError error = m_events.OnFieldCR(chars);
        return error;
    }
};

#endif // _CEVCPHEADERFIELDEVENTS_HPP
