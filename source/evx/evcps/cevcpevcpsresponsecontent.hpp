///////////////////////////////////////////////////////////////////////
//   File: cevcpevcpsresponsecontent.hpp
//
// Author: $author$
//   Date: 12/15/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCPEVCPSRESPONSECONTENT_HPP
#define _CEVCPEVCPSRESPONSECONTENT_HPP

#include "cevcpevcpscontent.hpp"
#include "cevcpresponsecontent.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpEvcpsResponseContent
//
// Author: $author$
//   Date: 12/15/2007
///////////////////////////////////////////////////////////////////////
template 
<class TEvcpsPlaintextList=CEvcpsPlaintextList,
 class TEvcpsPlaintextsIterator=TEvcpsPlaintextList::CPlaintextsIterator,
 class TEvcpsPlaintext=TEvcpsPlaintextList::CPlaintext>

class CEvcpEvcpsResponseContent
: public CEvcpEvcpsContent
  <CEvcpResponseContent, TEvcpsPlaintextList, 
   TEvcpsPlaintextsIterator, TEvcpsPlaintext>
{
public:
    typedef CEvcpEvcpsContent
    <CEvcpResponseContent, TEvcpsPlaintextList, 
     TEvcpsPlaintextsIterator, TEvcpsPlaintext> CExtends;
    typedef CEvcpEvcpsResponseContent CDerives;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpEvcpsResponseContent
    //
    //       Author: $author$
    //         Date: 12/15/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpEvcpsResponseContent
    (EvcpHeader& header) 
    : CExtends(header)
    {
    }
};
#endif // _CEVCPEVCPSRESPONSECONTENT_HPP
