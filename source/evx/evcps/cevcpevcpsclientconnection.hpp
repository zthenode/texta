///////////////////////////////////////////////////////////////////////
//   File: cevcpevcpsclientconnection.hpp
//
// Author: $author$
//   Date: 12/20/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCPEVCPSCLIENTCONNECTION_HPP
#define _CEVCPEVCPSCLIENTCONNECTION_HPP

#include "cevcpevcpsclient.hpp"
#include "cevcharstream.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpEvcpsClientConnection
//
// Author: $author$
//   Date: 12/20/2007
///////////////////////////////////////////////////////////////////////
class CEvcpEvcpsClientConnection
: public CEvCharStream
{
public:
    typedef CEvCharStream CExtends;
    typedef CEvcpEvcpsClientConnection CDerives;

    CEvcpEvcpsClient& m_client;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpEvcpsClientConnection
    //
    //       Author: $author$
    //         Date: 12/20/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpEvcpsClientConnection
    (CEvcpEvcpsClient& client) 
    : m_client(client)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvcpEvcpsClientConnection
    //
    //      Author: $author$
    //        Date: 12/20/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvcpEvcpsClientConnection()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Read
    //
    //   Author: $author$
    //     Date: 12/20/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Read
    (char* chars, ULONG size) 
    {
        LONG length = m_client.Read(chars, size);
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Write
    //
    //   Author: $author$
    //     Date: 12/20/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Write
    (const char* chars, LONG length=-1) 
    {
        LONG count = m_client.Write(chars, length);
        return count;
    }
};
#endif // _CEVCPEVCPSCLIENTCONNECTION_HPP
