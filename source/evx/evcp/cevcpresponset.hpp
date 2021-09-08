///////////////////////////////////////////////////////////////////////
//   File: cevcpresponset.hpp
//
// Author: $author$
//   Date: 12/13/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCPRESPONSET_HPP
#define _CEVCPRESPONSET_HPP

#include "cevcpmessage.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpResponseT
//
// Author: $author$
//   Date: 12/13/2007
///////////////////////////////////////////////////////////////////////
template
<class TExtends=CEvcpMessage>

class CEvcpResponseT
: public TExtends
{
public:
    typedef TExtends CExtends;
    typedef CEvcpResponseT CDerives;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpResponseT
    //
    //       Author: $author$
    //         Date: 12/13/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpResponseT(EvcpHeader& header)
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
     const char* statusDescription, 
     UINT statusCode) 
    {
        EvError error = EV_ERROR_FAILED;
        LONG length;
        EvcpHeaderField* field;

        if (0 < (length = (*this).m_heading.
            SetResponseDescription(statusDescription)))

        if (0 <= (length = (*this).m_heading.
            SetResponseStatusUnsigned(statusCode)))

        if ((field = (*this).m_header.SetField
            (EVCP_HEADER_FIELD_NAME_ACTION, evcAction)))

        if ((field = (*this).m_header.SetField
            (EVCP_HEADER_FIELD_NAME_PATH, evcPath)))
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
            (EVCP_HEADER_FIELD_NAME_PATH)))

        if (!(error2 = (*this).m_header.RemoveField
            (EVCP_HEADER_FIELD_NAME_ACTION)))
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

        if (0 < (written = (*this).m_header.WriteResponse(writer)))
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

        if (0 < (written = (*this).m_header.WriteResponse(writer)))
            count = written;
        return count;
    }
};
#endif // _CEVCPRESPONSET_HPP
