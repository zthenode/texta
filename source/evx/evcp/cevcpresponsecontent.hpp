///////////////////////////////////////////////////////////////////////
//   File: cevcpresponsecontent.hpp
//
// Author: $author$
//   Date: 11/23/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCPRESPONSECONTENT_HPP
#define _CEVCPRESPONSECONTENT_HPP

#include "cevcpresponset.hpp"
#include "cevcpmessagecontent.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpResponseContent
//
// Author: $author$
//   Date: 11/23/2007
///////////////////////////////////////////////////////////////////////
class CEvcpResponseContent
: public CEvcpResponseT
  <CEvcpMessageContent>
{
public:
    typedef CEvcpResponseT
    <CEvcpMessageContent> CExtends;
    typedef CEvcpResponseContent CDerives;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpResponseContent
    //
    //       Author: $author$
    //         Date: 11/23/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpResponseContent
    (EvcpHeader& header) 
    : CExtends(header)
    {
    }
};
#endif // _CEVCPRESPONSECONTENT_HPP
