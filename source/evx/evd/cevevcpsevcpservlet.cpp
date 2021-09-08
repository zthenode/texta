///////////////////////////////////////////////////////////////////////
//   File: cevevcpsevcpservlet.cpp
//
// Author: $author$
//   Date: 12/6/2007
///////////////////////////////////////////////////////////////////////

#include "cevevcpsevcpservlet.hpp"

#include "cevrsa_test_keys.cpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvEvcpsEvcpServlet
//
// Author: $author$
//   Date: 12/6/2007
///////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
// Function: CEvEvcpsEvcpServlet::GetRSAPublicKey
//
//   Author: $author$
//     Date: 12/10/2007
///////////////////////////////////////////////////////////////////////
LONG CEvEvcpsEvcpServlet::GetRSAPublicKey
(const BYTE*& rsaModulus, SHORT& rsaModulusBytes,
 const BYTE*& rsaExponent, SHORT& rsaExponentBytes)
{
    LONG length = -EV_ERROR_FAILED;
    rsaModulus = rsaPublicM;
    rsaModulusBytes = sizeof(rsaPublicM);
    rsaExponent = rsaPublicE; 
    rsaExponentBytes = sizeof(rsaPublicE);
    return length = rsaModulusBytes;
}

///////////////////////////////////////////////////////////////////////
// Function: CEvEvcpsEvcpServlet::GetRSAPrivateKey
//
//   Author: $author$
//     Date: 12/10/2007
///////////////////////////////////////////////////////////////////////
LONG CEvEvcpsEvcpServlet::GetRSAPrivateKey
(const BYTE*& rsaP,const BYTE*& rsaQ, 
 const BYTE*& rsaDmp1, const BYTE*& rsaDmq1,
 const BYTE*& rsaIqmp, SHORT& rsaPBytes) 
{
    LONG length = -EV_ERROR_FAILED;
    rsaP = rsaPrivateP;
    rsaQ = rsaPrivateQ; 
    rsaDmp1 = rsaPrivateDmp1;
    rsaDmq1 = rsaPrivateDmq1;
    rsaIqmp = rsaPrivateIqmp;
    rsaPBytes = sizeof(rsaPrivateP);
    return length = rsaPBytes + rsaPBytes;
}
