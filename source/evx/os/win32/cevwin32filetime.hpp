///////////////////////////////////////////////////////////////////////
//   File: cevwin32filetime.hpp
//
// Author: $author$
//   Date: 6/15/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVWIN32FILETIME_HPP
#define _CEVWIN32FILETIME_HPP

#include "cevwin32systemtime.hpp"
#include "evfiletime.hpp"
#include "evplatform.h"

#if defined(WIN32) 
// Windows
#else // defined(WIN32) 
// Unix
typedef struct _FILETIME 
{  
    DWORD dwLowDateTime;  
    DWORD dwHighDateTime;
} FILETIME, *PFILETIME;
#endif // defined(WIN32)

#if defined(WIN32) 
// Windows
///////////////////////////////////////////////////////////////////////
//  Class: CEvWin32FileTime
//
// Author: $author$
//   Date: 6/15/2007
///////////////////////////////////////////////////////////////////////
class CEvWin32FileTime
: public FILETIME
{
public:
    typedef FILETIME CExtends;
    typedef CEvWin32FileTime CDerives;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvWin32FileTime
    //
    //       Author: $author$
    //         Date: 6/15/2007
    ///////////////////////////////////////////////////////////////////////
    CEvWin32FileTime() 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvWin32FileTime
    //
    //       Author: $author$
    //         Date: 6/15/2007
    ///////////////////////////////////////////////////////////////////////
    CEvWin32FileTime(const CEvWin32FileTime& fileTime) 
    {
        Construct(fileTime);
    }
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvWin32FileTime
    //
    //       Author: $author$
    //         Date: 6/15/2007
    ///////////////////////////////////////////////////////////////////////
    CEvWin32FileTime(const FILETIME& fileTime) 
    {
        Construct(fileTime);
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: ToTime
    //
    //   Author: $author$
    //     Date: 9/11/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ToTime
    (EvFileTime& fileTime,
     bool isLocal=false) const
    {
        SYSTEMTIME systemTime;
        EvError error;
        
        if ((error = ToSystemTime(systemTime, isLocal)))
            return error;

        fileTime.SetYear(systemTime.wYear);
        fileTime.SetMonth(systemTime.wMonth);
        fileTime.SetDay(systemTime.wDay);
        fileTime.SetHour(systemTime.wHour);
        fileTime.SetMinute(systemTime.wMinute);
        fileTime.SetSecond(systemTime.wSecond);
        fileTime.SetMillisecond(systemTime.wMilliseconds);
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: FromTime
    //
    //   Author: $author$
    //     Date: 7/2/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError FromTime
    (const EvFileTime& fileTime,
     bool isLocal=false)
    {
        SYSTEMTIME systemTime;
        EvError error;
        bool isPM;
        
        systemTime.wYear = fileTime.GetYear();
        systemTime.wMonth = fileTime.GetMonth();
        systemTime.wDay = fileTime.GetDay();
        systemTime.wHour = fileTime.GetHour(isPM);
        systemTime.wMinute = fileTime.GetMinute();
        systemTime.wSecond = fileTime.GetSecond();
        systemTime.wMilliseconds = fileTime.GetMillisecond();

        error = FromSystemTime(systemTime, isLocal);
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: ToSystemTime
    //
    //   Author: $author$
    //     Date: 6/16/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ToSystemTime
    (CEvWin32SystemTime& systemTime,
     bool isLocal=false) const
    {
        EvError error = ToSystemTime
        ((CEvWin32SystemTime::CExtends&)systemTime, isLocal);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ToSystemTime
    //
    //   Author: $author$
    //     Date: 6/16/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ToSystemTime
    (SYSTEMTIME& systemTime,
     bool isLocal=false) const
    {
        EvError error = EV_ERROR_FAILED;

        if (isLocal)
        {
            FILETIME fileTime;
            if (FileTimeToLocalFileTime(this, &fileTime))
            if (FileTimeToSystemTime(&fileTime, &systemTime))
                error = EV_ERROR_NONE;
        }
        else if (FileTimeToSystemTime(this, &systemTime))
                error = EV_ERROR_NONE;
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: FromSystemTime
    //
    //   Author: $author$
    //     Date: 7/2/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError FromSystemTime
    (const CEvWin32SystemTime& systemTime,
     bool isLocal=false)
    {
        EvError error = FromSystemTime
        ((const CEvWin32SystemTime::CExtends&)systemTime, isLocal);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: FromSystemTime
    //
    //   Author: $author$
    //     Date: 7/2/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError FromSystemTime
    (const SYSTEMTIME& systemTime,
     bool isLocal=false)
    {
        EvError error = EV_ERROR_FAILED;

        if (isLocal)
        {
            FILETIME fileTime;
            if (SystemTimeToFileTime(&systemTime, &fileTime))
            if (LocalFileTimeToFileTime(&fileTime, this))
                error = EV_ERROR_NONE;
        }
        else if (SystemTimeToFileTime(&systemTime, this))
                error = EV_ERROR_NONE;
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Construct
    //
    //   Author: $author$
    //     Date: 6/15/2007
    ///////////////////////////////////////////////////////////////////////
    void Construct
    (const FILETIME& fileTime) 
    {
        dwLowDateTime = fileTime.dwLowDateTime;
        dwHighDateTime = fileTime.dwHighDateTime;
    }

    ///////////////////////////////////////////////////////////////////////
    // Operator: =
    //
    //   Author: $author$
    //     Date: 6/15/2007
    ///////////////////////////////////////////////////////////////////////
    virtual CEvWin32FileTime& operator =
    (const CEvWin32FileTime& fileTime) 
    {
        Construct(fileTime);
        return *this;
    }
    ///////////////////////////////////////////////////////////////////////
    // Operator: =
    //
    //   Author: $author$
    //     Date: 6/15/2007
    ///////////////////////////////////////////////////////////////////////
    virtual CEvWin32FileTime& operator =
    (const FILETIME& fileTime) 
    {
        Construct(fileTime);
        return *this;
    }
};
#endif // defined(WIN32)

#if defined(WIN32) 
// Windows
///////////////////////////////////////////////////////////////////////
//  Typedef: CEvOSFileTime
//
//   Author: $author$
//     Date: 8/31/2007
///////////////////////////////////////////////////////////////////////
typedef CEvWin32FileTime CEvOSFileTime;
#else // defined(WIN32) 
// Unix
#endif // defined(WIN32)

#endif // _CEVWIN32FILETIME_HPP
