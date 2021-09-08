///////////////////////////////////////////////////////////////////////
//   File: cevsocket.cpp
//
// Author: $author$
//   Date: 4/8/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#include "cevsocket.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvSocket
//
// Author: $author$
//   Date: 4/8/2007
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
// Function: CEvSocket::Accept
//
//   Author: $author$
//     Date: 4/8/2007
///////////////////////////////////////////////////////////////////////
CEvSocketReference CEvSocket::Accept
#if defined(WIN32) 
// Windows
(EvError& error, bool updateAcceptContext) 
#else // defined(WIN32) 
// Unix
(EvError& error) 
#endif // defined(WIN32)
{
    CEvSocketReference connectionReference;
    CEvSocket* connection;

    if ((connection = new CEvSocket()))
    if ((error = Accept(*connection)))
        delete connection;
    else
#if defined(WIN32) 
// Windows
    {
        if (updateAcceptContext)
        if ((error = connection->UpdateAcceptContext(m_attached)))
        {
            DBE("() failed to update accept context\n");
            connection->Close();
            delete connection;
            return connectionReference;
        }
#endif // defined(WIN32)
        connectionReference.Set(*connection);
#if defined(WIN32) 
// Windows
    }
#endif // defined(WIN32)

    return connectionReference;
}
///////////////////////////////////////////////////////////////////////
// Function: CEvSocket::Reject
//
//   Author: $author$
//     Date: 5/16/2007
///////////////////////////////////////////////////////////////////////
EvError CEvSocket::Reject
(CEvSocketReference& acceptedSocket) 
{
    EvError error = acceptedSocket.Clear();
    return error;
}
