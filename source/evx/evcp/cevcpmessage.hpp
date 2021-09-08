///////////////////////////////////////////////////////////////////////
//   File: cevcpmessage.hpp
//
// Author: $author$
//   Date: 9/5/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCPMESSAGE_HPP
#define _CEVCPMESSAGE_HPP

#include "cevcpheader.hpp"
#include "evcp.h"
#include "cevbase.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpMessage
//
// Author: $author$
//   Date: 9/5/2007
///////////////////////////////////////////////////////////////////////
class CEvcpMessage
: public CEvBase
{
public:
    typedef CEvBase CExtends;
    typedef CEvcpMessage CDerives;

    EvcpHeader& m_header;
    EvcpHeaderHeading& m_heading;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpMessage
    //
    //       Author: $author$
    //         Date: 9/5/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpMessage(EvcpHeader& header)
    : m_header(header),
      m_heading(m_header.GetHeading()) 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvcpMessage
    //
    //      Author: $author$
    //        Date: 9/5/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvcpMessage()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetField
    //
    //   Author: $author$
    //     Date: 12/25/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError SetField
    (const char* fieldName,
     const char* fieldValue) 
    {
        EvError error = EV_ERROR_FAILED;
        EvcpHeaderField* field;

        if ((field = (*this).m_header.
            SetField(fieldName, fieldValue)))
            error = EV_ERROR_NONE;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: RemoveField
    //
    //   Author: $author$
    //     Date: 12/25/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError RemoveField
    (const char* fieldName) 
    {
        EvError error = EV_ERROR_FAILED;
        EvError error2;

        if (!(error2 = (*this).m_header.
            RemoveField(fieldName)))
            error = EV_ERROR_NONE;
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetHeaderField
    //
    //   Author: $author$
    //     Date: 12/13/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvcpHeaderField* SetHeaderField
    (const char* name, const char* value) 
    {
        EvcpHeaderField* field = 0;
        field = m_header.SetField(name, value);
        return field;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetHeaderField
    //
    //   Author: $author$
    //     Date: 12/13/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetHeaderField
    (LONG& length, const char* name) const 
    {
        const char* value = 0;
        value = m_header.GetField(length, name);
        return value;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: GetHeader
    //
    //   Author: $author$
    //     Date: 12/19/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvcpHeader& GetHeader() const 
    {
        return (EvcpHeader&)(m_header);
    }
};
#endif // _CEVCPMESSAGE_HPP
