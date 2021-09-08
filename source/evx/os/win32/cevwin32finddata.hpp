///////////////////////////////////////////////////////////////////////
//   File: cevwin32finddata.hpp
//
// Author: $author$
//   Date: 6/15/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVWIN32FINDDATA_HPP
#define _CEVWIN32FINDDATA_HPP

#include "evplatform.h"

#if defined(WIN32) 
// Windows
#else // defined(WIN32) 
// Unix
typedef struct _WIN32_FIND_DATA 
{
  DWORD    dwFileAttributes; 
  FILETIME ftCreationTime; 
  FILETIME ftLastAccessTime; 
  FILETIME ftLastWriteTime; 
  DWORD    nFileSizeHigh; 
  DWORD    nFileSizeLow; 
  DWORD    dwReserved0; 
  DWORD    dwReserved1; 
  TCHAR    cFileName[ MAX_PATH ]; 
  TCHAR    cAlternateFileName[ 14 ]; 
} WIN32_FIND_DATA, *PWIN32_FIND_DATA;
#endif // defined(WIN32)

#if defined(WIN32) 
// Windows
///////////////////////////////////////////////////////////////////////
//  Class: CEvWin32FindData
//
// Author: $author$
//   Date: 6/15/2007
///////////////////////////////////////////////////////////////////////
class CEvWin32FindData
: public WIN32_FIND_DATA
{
public:
    typedef WIN32_FIND_DATA CExtends;
    typedef CEvWin32FindData CDerives;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvWin32FindData
    //
    //       Author: $author$
    //         Date: 6/15/2007
    ///////////////////////////////////////////////////////////////////////
    CEvWin32FindData() 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvWin32FindData
    //
    //       Author: $author$
    //         Date: 6/15/2007
    ///////////////////////////////////////////////////////////////////////
    CEvWin32FindData(const CEvWin32FindData& findData) 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvWin32FindData
    //
    //       Author: $author$
    //         Date: 6/15/2007
    ///////////////////////////////////////////////////////////////////////
    CEvWin32FindData(const WIN32_FIND_DATA& findData) 
    {
    }
};
#else // defined(WIN32) 
// Unix
#endif // defined(WIN32)

#endif // _CEVWIN32FINDDATA_HPP
