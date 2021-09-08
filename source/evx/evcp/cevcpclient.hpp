///////////////////////////////////////////////////////////////////////
//   File: cevcpclient.hpp
//
// Author: $author$
//   Date: 8/3/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCPCLIENT_HPP
#define _CEVCPCLIENT_HPP

#include "cevclient.hpp"
#include "cevcpheader.hpp"
#include "evcpversion.h"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpClient
//
// Author: $author$
//   Date: 8/3/2007
///////////////////////////////////////////////////////////////////////
class CEvcpClient
: public CEvClient
{
public:
    typedef EvClient CExtends;
    typedef CEvcpClient CDerives;

    CEvcpHeader m_requestHeader;
    CEvcpHeader m_responseHeader;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpClient
    //
    //       Author: $author$
    //         Date: 8/3/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpClient
    (const char* protocol=EVC_PROTOCOL_NAME,
     const char* protocolVersionMajor=EVC_PROTOCOL_VERSION_MAJOR,
     const char* protocolVersionMinor=EVC_PROTOCOL_VERSION_MINOR) 
    : m_requestHeader
      (protocol, protocolVersionMajor, protocolVersionMinor)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvcpClient
    //
    //      Author: $author$
    //        Date: 8/3/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvcpClient()
    {
    }
};
#endif // _CEVCPCLIENT_HPP
