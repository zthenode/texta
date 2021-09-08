///////////////////////////////////////////////////////////////////////
//   File: cevcpsloginfinished.hpp
//
// Author: $author$
//   Date: 12/10/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCPSLOGINFINISHED_HPP
#define _CEVCPSLOGINFINISHED_HPP

#include "cevcpsfinished.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpsLoginFinished
//
// Author: $author$
//   Date: 12/10/2007
///////////////////////////////////////////////////////////////////////
class CEvcpsLoginFinished
: public CEvcpsFinished
{
public:
    typedef CEvcpsFinished CExtends;
    typedef CEvcpsLoginFinished CDerives;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpsLoginFinished
    //
    //       Author: $author$
    //         Date: 12/10/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpsLoginFinished() 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpsLoginFinished
    //
    //       Author: $author$
    //         Date: 12/10/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpsLoginFinished
    (EvMD5& md5, EvSHA1& sha1,
     CEvcpsMasterSecret& secret,
     CEvcpsList& handshakeMessages,
     const char* label) 
    : CExtends(md5, sha1, secret, handshakeMessages, label)
    {
    }
};

#endif // _CEVCPSLOGINFINISHED_HPP
