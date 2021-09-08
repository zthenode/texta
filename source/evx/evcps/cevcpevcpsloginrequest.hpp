///////////////////////////////////////////////////////////////////////
//   File: cevcpevcpsloginrequest.hpp
//
// Author: $author$
//   Date: 11/22/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCPEVCPSLOGINREQUEST_HPP
#define _CEVCPEVCPSLOGINREQUEST_HPP

#include "cevcpevcpshandshakerequest.hpp"
#include "cevcpsloginrequest.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpEvcpsLoginRequest
//
// Author: $author$
//   Date: 11/22/2007
///////////////////////////////////////////////////////////////////////
class CEvcpEvcpsLoginRequest
: public CEvcpEvcpsHandshakeRequest
{
public:
    typedef CEvcpEvcpsHandshakeRequest CExtends;
    typedef CEvcpEvcpsLoginRequest CDerives;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpEvcpsLoginRequest
    //
    //       Author: $author$
    //         Date: 11/22/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpEvcpsLoginRequest
    (EvcpHeader& header,
     CEvcpsLoginRequest& request)
    : CExtends
      (header, request, 
       EVCPS_HANDSHAKE_TYPE_LOGIN_REQUEST)
    {
    }
};
#endif // _CEVCPEVCPSLOGINREQUEST_HPP
