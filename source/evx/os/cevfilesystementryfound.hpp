///////////////////////////////////////////////////////////////////////
//   File: cevfilesystementryfound.hpp
//
// Author: $author$
//   Date: 6/22/2007
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
#define EV_GET_FOUND_ENTRY_PARAMS const struct stat& st, const struct stat& lst
#define EV_GET_FOUND_ENTRY_ARGS st, lst
#define EV_GET_FOUND_ENTRY_M_ARGS m_st, m_lst
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
    struct stat m_lst;
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
        SetSize(0);
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
        ULONGLONG usize;
        LONGLONG size;
        int is;
        if (FILE_ATTRIBUTE_DIRECTORY == 
            (FILE_ATTRIBUTE_DIRECTORY & win32FindData.dwFileAttributes))
            type = (m_type = EV_TYPE_DIRECTORY);
        else {
            type = (m_type = EV_TYPE_FILE);
            if (FILE_ATTRIBUTE_REPARSE_POINT ==
                (FILE_ATTRIBUTE_REPARSE_POINT & win32FindData.dwFileAttributes))
                type = (m_type |= EV_TYPE_SYMBOLIC_LINK);
        }

        usize = win32FindData.nFileSizeHigh;
        usize <<= (sizeof(LONG) << 3);
        usize |= win32FindData.nFileSizeLow;

        if (0 > (size = SetSize(usize)))
            type = (int)(-size);
        else
        if (0 > (is = SetIsHidden
            (FILE_ATTRIBUTE_HIDDEN == 
             (win32FindData.dwFileAttributes & FILE_ATTRIBUTE_HIDDEN))))
             type = -is;
#else // defined(WIN32) 
// Unix
        off_t size;
        mode_t fmt;

        if (S_IFDIR == (S_IFDIR & st.st_mode)) {
            type = ((*this).m_type = EV_TYPE_DIRECTORY);
        } else {
            type = ((*this).m_type = EV_TYPE_FILE);
        }
        if (S_IFLNK == (fmt = (S_IFMT & (lst.st_mode))))
            type = ((*this).m_type |= EV_TYPE_SYMBOLIC_LINK);

        if (0 <= (size = st.st_size))
        if (0 > (size = SetSize((ULONGLONG)(size))))
            type = (int)(-size);
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
        m_createdOSFileTime = (win32FindData.ftCreationTime);
        m_changedOSFileTime = (win32FindData.ftLastWriteTime);
        m_modifiedOSFileTime = (win32FindData.ftLastWriteTime);
        m_accessedOSFileTime = (win32FindData.ftLastAccessTime);
        error = GetFileTimes();
#else // defined(WIN32) 
// Unix
        (*this).m_createdOSFileTime = (st.st_ctime);
        (*this).m_changedOSFileTime = (st.st_ctime);
        (*this).m_modifiedOSFileTime = (st.st_mtime);
        (*this).m_accessedOSFileTime = (st.st_atime);
        error = (*this).GetFileTimes();
#endif // defined(WIN32)
        return error;
    }
};
#endif // _CEVFILESYSTEMENTRYFOUND_HPP
