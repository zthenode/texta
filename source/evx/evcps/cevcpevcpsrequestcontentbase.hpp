///////////////////////////////////////////////////////////////////////
//   File: cevcpevcpsrequestcontentbase.hpp
//
// Author: $author$
//   Date: 12/20/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCPEVCPSREQUESTCONTENTBASE_HPP
#define _CEVCPEVCPSREQUESTCONTENTBASE_HPP

#include "cevcpevcpscontentbase.hpp"
#include "cevcprequestcontent.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpEvcpsRequestContentBase
//
// Author: $author$
//   Date: 12/20/2007
///////////////////////////////////////////////////////////////////////
class CEvcpEvcpsRequestContentBase
: public CEvcpEvcpsContentBase<CEvcpRequestContent>
{
public:
    typedef CEvcpEvcpsContentBase<CEvcpRequestContent> CExtends;
    typedef CEvcpEvcpsRequestContentBase CDerives;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpEvcpsRequestContentBase
    //
    //       Author: $author$
    //         Date: 12/20/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpEvcpsRequestContentBase
    (EvcpHeader& header) 
    : CExtends(header)
    {
    }
};
#endif // _CEVCPEVCPSREQUESTCONTENTBASE_HPP
