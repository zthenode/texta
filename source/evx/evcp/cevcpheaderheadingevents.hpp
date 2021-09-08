///////////////////////////////////////////////////////////////////////
//   File: cevcpheaderheadingevents.hpp
//
// Author: $author$
//   Date: 4/21/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCPHEADERHEADINGEVENTS_HPP
#define _CEVCPHEADERHEADINGEVENTS_HPP

#include "evcpheaderheadingevents.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpHeaderHeadingEvents
//
// Author: $author$
//   Date: 4/20/2007
///////////////////////////////////////////////////////////////////////
class CEvcpHeaderHeadingEvents
: virtual public EvcpHeaderHeadingEvents
{
public:
    typedef EvcpHeaderHeadingEvents CImplements;
    typedef CEvcpHeaderHeadingEvents CDerives;

    EvcpHeaderHeadingEvents& m_events;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpHeaderHeadingEvents
    //
    //       Author: $author$
    //         Date: 4/20/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpHeaderHeadingEvents(EvcpHeaderHeadingEvents& events) 
    : m_events(events)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: OnRequestAction
    //
    //   Author: $author$
    //     Date: 4/19/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnRequestAction(const char* chars) 
    {
        EvError error = m_events.OnRequestAction(chars);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: OnRequestPath
    //
    //   Author: $author$
    //     Date: 4/19/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnRequestPath(const char* chars) 
    {
        EvError error = m_events.OnRequestPath(chars);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: OnRequestProtocol
    //
    //   Author: $author$
    //     Date: 4/19/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnRequestProtocol(const char* chars) 
    {
        EvError error = m_events.OnRequestProtocol(chars);
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: OnResponseProtocol
    //
    //   Author: $author$
    //     Date: 4/19/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnResponseProtocol(const char* chars) 
    {
        EvError error = m_events.OnResponseProtocol(chars);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: OnResponseStatus
    //
    //   Author: $author$
    //     Date: 4/19/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnResponseStatus(const char* chars) 
    {
        EvError error = m_events.OnResponseStatus(chars);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: OnResponseDescription
    //
    //   Author: $author$
    //     Date: 4/19/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnResponseDescription(const char* chars) 
    {
        EvError error = m_events.OnResponseDescription(chars);
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: OnProtocolVersionMajor
    //
    //   Author: $author$
    //     Date: 4/19/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnProtocolVersionMajor(const char* chars) 
    {
        EvError error = m_events.OnProtocolVersionMajor(chars);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: OnProtocolVersionMinor
    //
    //   Author: $author$
    //     Date: 4/19/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnProtocolVersionMinor(const char* chars) 
    {
        EvError error = m_events.OnProtocolVersionMinor(chars);
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: OnHeadingCR
    //
    //   Author: $author$
    //     Date: 5/16/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnHeadingCR
    (const char* chars) 
    {
        EvError error = m_events.OnHeadingCR(chars);
        return error;
    }
};

#endif // _CEVCPHEADERHEADINGEVENTS_HPP
