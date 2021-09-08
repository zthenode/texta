///////////////////////////////////////////////////////////////////////
//   File: cevcpevcpsresponsecontentbase.hpp
//
// Author: $author$
//   Date: 12/20/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCPEVCPSRESPONSECONTENTBASE_HPP
#define _CEVCPEVCPSRESPONSECONTENTBASE_HPP

#include "cevcpevcpscontentbase.hpp"
#include "cevcpresponsecontent.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpEvcpsResponseContentBase
//
// Author: $author$
//   Date: 12/20/2007
///////////////////////////////////////////////////////////////////////
class CEvcpEvcpsResponseContentBase
: public CEvcpEvcpsContentBase<CEvcpResponseContent>
{
public:
    typedef CEvcpEvcpsContentBase<CEvcpResponseContent> CExtends;
    typedef CEvcpEvcpsResponseContentBase CDerives;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpEvcpsResponseContentBase
    //
    //       Author: $author$
    //         Date: 12/20/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpEvcpsResponseContentBase
    (EvcpHeader& header) 
    : CExtends(header)
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Read
    //
    //   Author: $author$
    //     Date: 12/20/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Read
    (EvCharReader& reader,
     EvcpHeader& respHeader,
     CEvcpsMessage& message,
     EvcpsMessageReadEvents& events) 
    {
        LONG length = CExtends::Read
        (reader, respHeader, message, 
         events, m_contentDecoder);
        return length;
    }
};
#endif // _CEVCPEVCPSRESPONSECONTENTBASE_HPP
