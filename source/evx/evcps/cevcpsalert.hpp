///////////////////////////////////////////////////////////////////////
//   File: cevcpsalert.hpp
//
// Author: $author$
//   Date: 12/8/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCPSALERT_HPP
#define _CEVCPSALERT_HPP

#include "cevcpsbase.hpp"
#include "evtlsatert.hpp"

///////////////////////////////////////////////////////////////////////
//   Enum:  
//
// Author: $author$
//   Date: 12/8/2007
///////////////////////////////////////////////////////////////////////
enum 
{
    EVCPS_ALERT_LEVEL_NONE = TLS_ALERT_LEVEL_NONE,
    EVCPS_ALERT_LEVEL_WARNING = TLS_ALERT_LEVEL_WARNING,
    EVCPS_ALERT_LEVEL_FATAL = TLS_ALERT_LEVEL_FATAL
};

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpsAlert
//
// Author: $author$
//   Date: 12/8/2007
///////////////////////////////////////////////////////////////////////
class CEvcpsAlert
: public CEvcpsBase
{
public:
    typedef CEvcpsBase CExtends;
    typedef CEvcpsAlert CDerives;

    BYTE m_level;
    BYTE m_description;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpsAlert
    //
    //       Author: $author$
    //         Date: 12/8/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpsAlert
    (BYTE level=EVCPS_ALERT_LEVEL_NONE,
     BYTE description=EVCPS_ALERT_LEVEL_NONE)
    : m_level(level),
      m_description(description)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Read
    //
    //   Author: $author$
    //     Date: 12/8/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Read
    (EvCharReader& reader) 
    {
        LONG length = -EV_ERROR_FAILED;
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Write
    //
    //   Author: $author$
    //     Date: 12/8/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Write
    (EvCharWriter& writer) 
    {
        LONG length = -EV_ERROR_FAILED;
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Sizeof
    //
    //   Author: $author$
    //     Date: 12/8/2007
    ///////////////////////////////////////////////////////////////////////
    virtual USHORT Sizeof() const 
    {
        USHORT size = 0;
        return size;
    }
};

#endif // _CEVCPSALERT_HPP
