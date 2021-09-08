///////////////////////////////////////////////////////////////////////
//   File: cevcpsclientfinished.hpp
//
// Author: $author$
//   Date: 12/1/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCPSCLIENTFINISHED_HPP
#define _CEVCPSCLIENTFINISHED_HPP

#include "cevcpsfinished.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpsClientFinished
//
// Author: $author$
//   Date: 12/1/2007
///////////////////////////////////////////////////////////////////////
class CEvcpsClientFinished
: public CEvcpsFinished
{
public:
    typedef CEvcpsFinished CExtends;
    typedef CEvcpsClientFinished CDerives;

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
     const char* label=EVCPS_CLIENT_FINISHED_LABEL) 
    {
        LONG length = CExtends::Generate
        (md5, sha1, secret, handshakeMessages, label);
        return length;
    }
};
#endif // _CEVCPSCLIENTFINISHED_HPP
