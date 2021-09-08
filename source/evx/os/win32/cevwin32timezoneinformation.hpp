///////////////////////////////////////////////////////////////////////
//   File: cevwin32timezoneinformation.hpp
//
// Author: $author$
//   Date: 6/20/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVWIN32TIMEZONEINFORMATION_HPP
#define _CEVWIN32TIMEZONEINFORMATION_HPP

#include "evplatform.h"
#include "everror.h"

#if defined(WIN32) 
// Windows
#else // defined(WIN32) 
// Unix
typedef struct _TIME_ZONE_INFORMATION 
{  
    LONG Bias;  
    WCHAR StandardName[32];  
    SYSTEMTIME StandardDate;  
    LONG StandardBias;  
    WCHAR DaylightName[32];  
    SYSTEMTIME DaylightDate;  
    LONG DaylightBias;
} TIME_ZONE_INFORMATION;
#endif // defined(WIN32)

///////////////////////////////////////////////////////////////////////
//  Class: CEvWin32TimeZoneInformation
//
// Author: $author$
//   Date: 6/20/2007
///////////////////////////////////////////////////////////////////////
class CEvWin32TimeZoneInformation
: public TIME_ZONE_INFORMATION
{
public:
    typedef TIME_ZONE_INFORMATION CExtends;
    typedef CEvWin32TimeZoneInformation CDerives;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvWin32TimeZoneInformation
    //
    //       Author: $author$
    //         Date: 6/20/2007
    ///////////////////////////////////////////////////////////////////////
    CEvWin32TimeZoneInformation() 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvWin32TimeZoneInformation
    //
    //      Author: $author$
    //        Date: 6/20/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvWin32TimeZoneInformation()
    {
    }
};

#endif // _CEVWIN32TIMEZONEINFORMATION_HPP
