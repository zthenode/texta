///////////////////////////////////////////////////////////////////////
//   File: evcompares.hpp
//
// Author: $author$
//   Date: 11/21/2007
///////////////////////////////////////////////////////////////////////

#ifndef _EVCOMPARES_HPP
#define _EVCOMPARES_HPP

#include "evbase.hpp"

///////////////////////////////////////////////////////////////////////
//   Enum:  
//
// Author: $author$
//   Date: 6/30/2007
///////////////////////////////////////////////////////////////////////
enum 
{
    EV_COMPARES_TRUE = 0,
    EV_COMPARES_GT,
    EV_COMPARES_LT,
    EV_COMPARES_NE,
    EV_COMPARES_EQ,
    EV_COMPARES_LE,
    EV_COMPARES_GE,
    EV_COMPARES_FALSE,
    EV_COMPARES
};

#define EV_COMPARES_NAME_TRUE "TRUE"
#define EV_COMPARES_NAME_GT "GT"
#define EV_COMPARES_NAME_LT "LT"
#define EV_COMPARES_NAME_NE "NE"
#define EV_COMPARES_NAME_EQ "EQ"
#define EV_COMPARES_NAME_LE "LE"
#define EV_COMPARES_NAME_GE "GE"
#define EV_COMPARES_NAME_FALSE "FALSE"

///////////////////////////////////////////////////////////////////////
//  Class: EvCompares
//
// Author: $author$
//   Date: 11/21/2007
///////////////////////////////////////////////////////////////////////
class EV_EXPORT_CLASS EvCompares
: virtual public EvBase
{
public:
    typedef EvBase CImplements;
    typedef EvCompares CDerives;

    ///////////////////////////////////////////////////////////////////////
    //  Typedef: ComparesWhat
    //
    //   Author: $author$
    //     Date: 6/30/2007
    ///////////////////////////////////////////////////////////////////////
    typedef int ComparesWhat;
    static const char* m_name[EV_COMPARES];

    ///////////////////////////////////////////////////////////////////////
    // Function: Compares
    //
    //   Author: $author$
    //     Date: 6/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual bool Compares(int unequal) = 0;
};

#endif // _EVCOMPARES_HPP
