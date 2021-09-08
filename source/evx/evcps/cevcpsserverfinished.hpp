///////////////////////////////////////////////////////////////////////
//   File: cevcpsserverfinished.hpp
//
// Author: $author$
//   Date: 12/1/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCPSSERVERFINISHED_HPP
#define _CEVCPSSERVERFINISHED_HPP

#include "cevcpsfinished.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpsServerFinished
//
// Author: $author$
//   Date: 12/1/2007
///////////////////////////////////////////////////////////////////////
class CEvcpsServerFinished
: public CEvcpsFinished
{
public:
    typedef CEvcpsFinished CExtends;
    typedef CEvcpsServerFinished CDerives;

    ///////////////////////////////////////////////////////////////////////
    // Function: Generate
    //
    //   Author: $author$
    //     Date: 11/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Generate
    (EvMD5& md5, EvSHA1& sha1,
     CEvcpsMasterSecret& secret,
     CEvcpsList& handshakeMessages,
     const char* label=EVCPS_SERVER_FINISHED_LABEL) 
    {
        LONG length = CExtends::Generate
        (md5, sha1, secret, handshakeMessages, label);
        return length;
    }
};
#endif // _CEVCPSSERVERFINISHED_HPP
