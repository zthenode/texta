///////////////////////////////////////////////////////////////////////
//   File: evcryptobase.hpp
//
// Author: $author$
//   Date: 11/19/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _EVCRYPTOBASE_HPP
#define _EVCRYPTOBASE_HPP

#include "evbase.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: EvCryptoBase
//
// Author: $author$
//   Date: 11/19/2007
///////////////////////////////////////////////////////////////////////
class EV_EXPORT_CLASS EvCryptoBase
: virtual public EvBase
{
public:
    typedef EvBase CImplements;
    typedef EvCryptoBase CDerives;

    ///////////////////////////////////////////////////////////////////////
    //   Enum:  
    //
    // Author: $author$
    //   Date: 10/25/2007
    ///////////////////////////////////////////////////////////////////////
    enum 
    {
        EV_FIRST_ERROR = ::EV_NEXT_ERROR,

        EV_ERROR_KEY_SIZE_INVALID = EV_FIRST_ERROR,
        EV_ERROR_KEY_SIZE_UNDER,
        EV_ERROR_KEY_SIZE_OVER,

        EV_ERROR_IV_SIZE_INVALID,
        EV_ERROR_IV_SIZE_UNDER,
        EV_ERROR_IV_SIZE_OVER,

        EV_ERROR_BLOCK_SIZE_INVALID,
        EV_ERROR_BLOCK_SIZE_UNDER,
        EV_ERROR_BLOCK_SIZE_OVER,

        EV_NEXT_ERROR,
        EV_LAST_ERROR = EV_NEXT_ERROR-1,

        EV_ERRORS = EV_LAST_ERROR-EV_FIRST_ERROR+1
    };
};
#endif // _EVCRYPTOBASE_HPP
