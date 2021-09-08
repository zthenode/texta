///////////////////////////////////////////////////////////////////////
//   File: cevcpsmac.hpp
//
// Author: $author$
//   Date: 12/3/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCPSMAC_HPP
#define _CEVCPSMAC_HPP

#include "evplatform.h"

///////////////////////////////////////////////////////////////////////
//   Enum:  
//
// Author: $author$
//   Date: 12/3/2007
///////////////////////////////////////////////////////////////////////
enum 
{
    EVCPS_MAC_ALGORITHM_NULL,

    EVCPS_MAC_ALGORITHM_MD5,
    EVCPS_MAC_ALGORITHM_SHA1,

    EVCPS_MAC_ALGORITHMS
};

#define EVCPS_MAC_ALGORITHM_NAME_NULL "NULL"
#define EVCPS_MAC_ALGORITHM_NAME_MD5 "MD5"
#define EVCPS_MAC_ALGORITHM_NAME_SHA1 "SHA1"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpsMacAttributes
//
// Author: $author$
//   Date: 12/4/2007
///////////////////////////////////////////////////////////////////////
class CEvcpsMacAttributes
{
public:
    typedef CEvcpsMacAttributes CDerives;

    BYTE m_hashSize;
};

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpsMac
//
// Author: $author$
//   Date: 12/4/2007
///////////////////////////////////////////////////////////////////////
class CEvcpsMac
{
public:
    typedef CEvcpsMac CDerives;

    static CEvcpsMacAttributes
    m_attributes[EVCPS_MAC_ALGORITHMS];
};

#endif // _CEVCPSMAC_HPP
