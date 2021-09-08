///////////////////////////////////////////////////////////////////////
//   File: cevcpfilemessage.hpp
//
// Author: $author$
//   Date: 9/5/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCPFILEMESSAGE_HPP
#define _CEVCPFILEMESSAGE_HPP

#include "cevcpmessage.hpp"
#include "cevfiletimes2evcpheader.hpp"
#include "evfilesystementrytimes.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpFileMessage
//
// Author: $author$
//   Date: 9/5/2007
///////////////////////////////////////////////////////////////////////
class CEvcpFileMessage
: public CEvcpMessage
{
public:
    typedef CEvcpMessage CExtends;
    typedef CEvcpFileMessage CDerives;

    CEvFileTimes2EvcpHeader m_fileTimes2Header;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpFileMessage
    //
    //       Author: $author$
    //         Date: 9/5/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpFileMessage(EvcpHeader& header)
    : CExtends(header) 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvcpFileMessage
    //
    //      Author: $author$
    //        Date: 9/5/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvcpFileMessage()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetFields
    //
    //   Author: $author$
    //     Date: 9/5/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError SetFields(ULONG blockLength) 
    {
        EvError error = EV_ERROR_FAILED;
        EvcpHeaderField* field;

        if ((field = m_header.SetFieldUnsigned
            (EVCP_HEADER_FIELD_NAME_BLOCK_LENGTH, blockLength)))
            error = EV_ERROR_NONE;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: RemoveFields
    //
    //   Author: $author$
    //     Date: 9/13/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError RemoveFields() 
    {
        EvError error = EV_ERROR_FAILED;
        EvError error2;

        if (!(error2 = m_header.RemoveField
            (EVCP_HEADER_FIELD_NAME_BLOCK_LENGTH)))
            error = EV_ERROR_NONE;
        return error;
    }
};
#endif // _CEVCPFILEMESSAGE_HPP
