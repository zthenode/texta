///////////////////////////////////////////////////////////////////////
//   File: cevcprequestcontent.hpp
//
// Author: $author$
//   Date: 11/23/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCPREQUESTCONTENT_HPP
#define _CEVCPREQUESTCONTENT_HPP

#include "cevcprequestt.hpp"
#include "cevcpmessagecontent.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpRequestContent
//
// Author: $author$
//   Date: 11/23/2007
///////////////////////////////////////////////////////////////////////
class CEvcpRequestContent
: public CEvcpRequestT<CEvcpMessageContent>
{
public:
    typedef CEvcpRequestT<CEvcpMessageContent> CExtends;
    typedef CEvcpRequestContent CDerives;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpRequestContent
    //
    //       Author: $author$
    //         Date: 11/23/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpRequestContent
    (EvcpHeader& header) 
    : CExtends(header) 
    {
    }
};
#endif // _CEVCPREQUESTCONTENT_HPP
