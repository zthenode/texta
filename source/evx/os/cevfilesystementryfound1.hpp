///////////////////////////////////////////////////////////////////////
//   File: cevfilesystementryfound.hpp
//
// Author: $author$
//   Date: 6/22/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVFILESYSTEMENTRYFOUND_HPP
#define _CEVFILESYSTEMENTRYFOUND_HPP

#include "evplatform_stat.h"
#include "cevfilesystementrytimes.hpp"
#include "cevfilesystementrybase.hpp"
#include "evfilesystementry.hpp"

#if defined(WIN32) 
// Windows
#include "os/win32/cevwin32finddata.hpp"
#define EV_GET_FOUND_ENTRY_PARAMS const CEvWin32FindData& win32FindData 
#define EV_GET_FOUND_ENTRY_ARGS win32FindData
#define EV_GET_FOUND_ENTRY_M_ARGS m_win32FindData
#else // defined(WIN32) 
// Unix
#define EV_GET_FOUND_ENTRY_PARAMS const struct stat& st
#define EV_GET_FOUND_ENTRY_ARGS st
#define EV_GET_FOUND_ENTRY_M_ARGS m_st
#endif // defined(WIN32)

///////////////////////////////////////////////////////////////////////
//  Typedef: CEvFileSystemEntryFoundExtends
//
//   Author: $author$
//     Date: 6/22/2007
///////////////////////////////////////////////////////////////////////
typedef CEvFileSystemEntryTimesT
<CEvFileSystemEntryBase, 
 EvFileSystemEntryImplements>
CEvFileSystemEntryFoundExtends;

///////////////////////////////////////////////////////////////////////
//  Class: CEvFileSystemEntryFound
//
// Author: $author$
//   Date: 6/22/2007
///////////////////////////////////////////////////////////////////////
template
<class TExtends=CEvFileSystemEntryFoundExtends>

class CEvFileSystemEntryFound
: virtual public EvFileSystemEntryBase,
  public TExtends
{
public:
    typedef EvFileSystemEntryBase CImplements;
    typedef TExtends CExtends;
    typedef CEvFileSystemEntryFound CDerives;

#if defined(WIN32) 
// Windows
    CEvWin32FindData m_win32FindData;
#else // defined(WIN32) 
// Unix
    struct stat m_st;
#endif // defined(WIN32)

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvFileSystemEntryFound
    //
    //       Author: $author$
    //         Date: 6/22/2007
    ///////////////////////////////////////////////////////////////////////
    CEvFileSystemEntryFound()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: GetFoundEntryAttributes
    //
    //   Author: $author$
    //     Date: 6/22/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int GetFoundEntryAttributes() 
    {
        EvType type = GetFoundEntryAttributes
        (EV_GET_FOUND_ENTRY_M_ARGS);
        return type;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetFoundEntryAttributes
    //
    //   Author: $author$
    //     Date: 6/22/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int GetFoundEntryAttributes
    (EV_GET_FOUND_ENTRY_PARAMS)
    {
        EvError error = EV_ERROR_NONE;
        EvType type = EV_TYPE_NONE;

        if (0 < (type = GetFoundEntryType(EV_GET_FOUND_ENTRY_ARGS)))
        if ((error = GetFoundEntryTimes(EV_GET_FOUND_ENTRY_ARGS)))
            type = -error;
        return type;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ClearFoundEntryAttributes
    //
    //   Author: $author$
    //     Date: 6/22/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ClearFoundEntryAttributes() 
    {
        EvError error = EV_ERROR_NONE;
        SetType(EV_TYPE_NONE);
        SetIsArchive(false);
        SetIsCompressed(false);
        SetIsEncrypted(false);
        SetIsHidden(false);
        SetIsOffline(false);
        SetIsReadOnly(false);
        SetIsSystem(false);
        SetIsTemporary(false);
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: GetFoundEntryName
    //
    //   Author: $author$
    //     Date: 7/10/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG GetFoundEntryName() 
    {
        LONG length = GetFoundEntryName
        (EV_GET_FOUND_ENTRY_M_ARGS);
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetFoundEntryName
    //
    //   Author: $author$
    //     Date: 7/10/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG GetFoundEntryName
    (EV_GET_FOUND_ENTRY_PARAMS) 
    {
        LONG length = -EV_ERROR_FAILED;
#if defined(WIN32) 
// Windows
        length = m_name.Assignt
        (win32FindData.cFileName);
#else // defined(WIN32) 
// Unix
#endif // defined(WIN32)
        return length;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: GetFoundEntryType
    //
    //   Author: $author$
    //     Date: 6/22/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int GetFoundEntryType() 
    {
        int type = GetFoundEntryType(EV_GET_FOUND_ENTRY_M_ARGS);
        return type;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetFoundEntryType
    //
    //   Author: $author$
    //     Date: 6/22/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int GetFoundEntryType
    (EV_GET_FOUND_ENTRY_PARAMS)
    {
        int type = EV_TYPE_NONE;
#if defined(WIN32) 
// Windows
        int is;
        if (FILE_ATTRIBUTE_DIRECTORY == 
            (FILE_ATTRIBUTE_DIRECTORY & win32FindData.dwFileAttributes))
            type = (m_type = EV_TYPE_DIRECTORY);
        else type = (m_type = EV_TYPE_FILE);

        if (0 > (is = SetIsHidden
            (FILE_ATTRIBUTE_HIDDEN == 
             (win32FindData.dwFileAttributes & FILE_ATTRIBUTE_HIDDEN))))
             type = -is;
#else // defined(WIN32) 
// Unix
#endif // defined(WIN32)
        return type;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetFoundEntryTimes
    //
    //   Author: $author$
    //     Date: 6/22/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError GetFoundEntryTimes() 
    {
        EvError error = GetFoundEntryTimes
        (EV_GET_FOUND_ENTRY_M_ARGS);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetFoundEntryTimes
    //
    //   Author: $author$
    //     Date: 6/22/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError GetFoundEntryTimes
    (EV_GET_FOUND_ENTRY_PARAMS)
    {
        EvError error = EV_ERROR_NONE;

#if defined(WIN32) 
// Windows
        m_modifiedWin32Time = (win32FindData.ftLastWriteTime);
        m_createdWin32Time = (win32FindData.ftCreationTime);
        m_accessedWin32Time = (win32FindData.ftLastAccessTime);
        error = GetFileTimes();
#else // defined(WIN32) 
// Unix
#endif // defined(WIN32)
        return error;
    }
};
#endif // _CEVFILESYSTEMENTRYFOUND_HPP
