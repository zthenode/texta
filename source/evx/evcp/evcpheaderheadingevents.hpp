///////////////////////////////////////////////////////////////////////
//   File: evcpheaderheadingevents.hpp
//
// Author: $author$
//   Date: 5/16/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _EVCPHEADERHEADINGEVENTS_HPP
#define _EVCPHEADERHEADINGEVENTS_HPP

#include "evbase.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: EvcpHeaderHeadingEvents
//
// Author: $author$
//   Date: 5/16/2007
///////////////////////////////////////////////////////////////////////
class EV_EXPORT_CLASS EvcpHeaderHeadingEvents
: virtual public EvBase
{
public:
    typedef EvBase CImplements;
    typedef EvcpHeaderHeadingEvents CDerives;

    ///////////////////////////////////////////////////////////////////////
    // Function: OnRequestAction
    //
    //   Author: $author$
    //     Date: 4/19/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnRequestAction(const char* chars) = 0;
    ///////////////////////////////////////////////////////////////////////
    // Function: OnRequestPath
    //
    //   Author: $author$
    //     Date: 4/19/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnRequestPath(const char* chars) = 0;
    ///////////////////////////////////////////////////////////////////////
    // Function: OnRequestProtocol
    //
    //   Author: $author$
    //     Date: 4/19/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnRequestProtocol(const char* chars) = 0;

    ///////////////////////////////////////////////////////////////////////
    // Function: OnResponseProtocol
    //
    //   Author: $author$
    //     Date: 4/19/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnResponseProtocol(const char* chars) = 0;
    ///////////////////////////////////////////////////////////////////////
    // Function: OnResponseStatus
    //
    //   Author: $author$
    //     Date: 4/19/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnResponseStatus(const char* chars) = 0;
    ///////////////////////////////////////////////////////////////////////
    // Function: OnResponseDescription
    //
    //   Author: $author$
    //     Date: 4/19/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnResponseDescription(const char* chars) = 0;

    ///////////////////////////////////////////////////////////////////////
    // Function: OnProtocolVersionMajor
    //
    //   Author: $author$
    //     Date: 4/19/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnProtocolVersionMajor(const char* chars) = 0;
    ///////////////////////////////////////////////////////////////////////
    // Function: OnProtocolVersionMinor
    //
    //   Author: $author$
    //     Date: 4/19/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnProtocolVersionMinor(const char* chars) = 0;

    ///////////////////////////////////////////////////////////////////////
    // Function: OnHeadingCR
    //
    //   Author: $author$
    //     Date: 5/16/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnHeadingCR
    (const char* chars) = 0;
};
#endif // _EVCPHEADERHEADINGEVENTS_HPP