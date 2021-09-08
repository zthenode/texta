///////////////////////////////////////////////////////////////////////
//   File: cevcprequestt.hpp
//
// Author: $author$
//   Date: 12/13/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCPREQUESTT_HPP
#define _CEVCPREQUESTT_HPP

#include "cevcpmessage.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpRequestT
//
// Author: $author$
//   Date: 12/13/2007
///////////////////////////////////////////////////////////////////////
template
<class TExtends=CEvcpMessage>

class CEvcpRequestT
: public TExtends
{
public:
    typedef TExtends CExtends;
    typedef CEvcpRequestT CDerives;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpRequestT
    //
    //       Author: $author$
    //         Date: 12/13/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpRequestT(EvcpHeader& header)
    : CExtends(header) 
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetFields
    //
    //   Author: $author$
    //     Date: 12/13/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError SetFields
    (const char* evcAction, 
     const char* evcPath, 
     const char* connection) 
    {
        EvError error = EV_ERROR_FAILED;
        LONG length;
        EvcpHeaderField* field;

        if (0 < (length = (*this).m_heading.SetRequestMethod(evcAction)))
        if (0 < (length = (*this).m_heading.SetRequestPath(evcPath)))
        if ((field = (*this).m_header.SetField
            (EVCP_HEADER_FIELD_NAME_CONNECTION, connection)))
            error = EV_ERROR_NONE;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: RemoveFields
    //
    //   Author: $author$
    //     Date: 12/13/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError RemoveFields() 
    {
        EvError error = EV_ERROR_FAILED;
        EvError error2;

        if (!(error2 = (*this).m_header.RemoveField
            (EVCP_HEADER_FIELD_NAME_CONNECTION)))
            error = EV_ERROR_NONE;
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Write
    //
    //   Author: $author$
    //     Date: 12/13/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Write
    (EvCharWriter& writer,
     const char* chars,
     LONG length=-1) 
    {
        LONG count = -EV_ERROR_FAILED;
        LONG written = 0;

        if (0 < (written = (*this).m_header.WriteRequest(writer)))
        if (0 <= (length = writer.Write(chars, length)))
            count = written+length;
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Write
    //
    //   Author: $author$
    //     Date: 12/13/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Write
    (EvCharWriter& writer) 
    {
        LONG count = -EV_ERROR_FAILED;
        LONG written = 0;

        if (0 < (written = (*this).m_header.WriteRequest(writer)))
            count = written;
        return count;
    }
};
#endif // _CEVCPREQUESTT_HPP
