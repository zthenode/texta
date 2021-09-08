///////////////////////////////////////////////////////////////////////
//   File: cevcpsrsaclientkeyexchange.hpp
//
// Author: $author$
//   Date: 11/29/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCPSRSACLIENTKEYEXCHANGE_HPP
#define _CEVCPSRSACLIENTKEYEXCHANGE_HPP

#include "cevcpsrsaencryptedpremastersecret.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpsRSAClientKeyExchange
//
// Author: $author$
//   Date: 11/29/2007
///////////////////////////////////////////////////////////////////////
class CEvcpsRSAClientKeyExchange
: public CEvcpsRSAEncryptedPreMasterSecret
{
public:
    typedef CEvcpsRSAEncryptedPreMasterSecret CExtends;
    typedef CEvcpsRSAClientKeyExchange CDerives;
};
#endif // _CEVCPSRSACLIENTKEYEXCHANGE_HPP
