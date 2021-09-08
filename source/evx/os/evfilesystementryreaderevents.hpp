///////////////////////////////////////////////////////////////////////
//   File: evfilesystementryreaderevents.hpp
//
// Author: $author$
//   Date: 6/24/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _EVFILESYSTEMENTRYREADEREVENTS_HPP
#define _EVFILESYSTEMENTRYREADEREVENTS_HPP

#include "evfilesystementry.hpp"
#include "evfilepath.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: EvFileSystemEntryReaderEvents
//
// Author: $author$
//   Date: 6/24/2007
///////////////////////////////////////////////////////////////////////
class EV_EXPORT_CLASS EvFileSystemEntryReaderEvents
: virtual public EvBase
{
public:
    typedef EvBase CImplements;
    typedef EvFileSystemEntryReaderEvents CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Function: OnFileSystemEntry
    //
    //   Author: $author$
    //     Date: 6/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnFileSystemEntry
    (const EvFileSystemEntry& entry,
     const EvFilePath& path,
     const EvFilePath& reflectedPath,
     EvFileSystemEntryReaderEvents* deligate=0) = 0;
    ///////////////////////////////////////////////////////////////////////
    // Function: OnFileSystemFileEntry
    //
    //   Author: $author$
    //     Date: 6/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnFileSystemFileEntry
    (const EvFileSystemEntry& entry,
     const EvFilePath& path,
     const EvFilePath& reflectedPath,
     EvFileSystemEntryReaderEvents* deligate=0) = 0;
    ///////////////////////////////////////////////////////////////////////
    // Function: OnFileSystemFileEntrySymbolicLink
    //
    //   Author: $author$
    //     Date: 6/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnFileSystemFileEntrySymbolicLink
    (const EvFileSystemEntry& entry,
     const EvFilePath& path,
     const EvFilePath& reflectedPath,
     EvFileSystemEntryReaderEvents* deligate=0) = 0;
    ///////////////////////////////////////////////////////////////////////
    // Function: OnFileSystemDirectoryEntry
    //
    //   Author: $author$
    //     Date: 6/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnFileSystemDirectoryEntry
    (const EvFileSystemEntry& entry, 
     const EvFilePath& path,
     const EvFilePath& reflectedPath,
     EvFileSystemEntryReaderEvents* deligate=0) = 0;
    ///////////////////////////////////////////////////////////////////////
    // Function: OnFileSystemDirectoryEntrySymbolicLink
    //
    //   Author: $author$
    //     Date: 6/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnFileSystemDirectoryEntrySymbolicLink
    (const EvFileSystemEntry& entry,
     const EvFilePath& path,
     const EvFilePath& reflectedPath,
     EvFileSystemEntryReaderEvents* deligate=0) = 0;

    ///////////////////////////////////////////////////////////////////////
    // Function: OnFileDirectoryEntry
    //
    //   Author: $author$
    //     Date: 6/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnFileDirectoryEntry
    (const EvFileDirectoryEntry& entry,
     const EvFilePath& path,
     const EvFilePath& reflectedPath,
     EvFileSystemEntryReaderEvents* deligate=0) = 0;
    ///////////////////////////////////////////////////////////////////////
    // Function: OnFileDirectoryFileEntrySymbolicLink
    //
    //   Author: $author$
    //     Date: 6/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnFileDirectoryFileEntrySymbolicLink
    (const EvFileDirectoryEntry& entry,
     const EvFilePath& path,
     const EvFilePath& reflectedPath,
     EvFileSystemEntryReaderEvents* deligate=0) = 0;
    ///////////////////////////////////////////////////////////////////////
    // Function: OnFileDirectoryFileEntry
    //
    //   Author: $author$
    //     Date: 6/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnFileDirectoryFileEntry
    (const EvFileDirectoryEntry& entry,
     const EvFilePath& path,
     const EvFilePath& reflectedPath,
     EvFileSystemEntryReaderEvents* deligate=0) = 0;
    ///////////////////////////////////////////////////////////////////////
    // Function: OnFileDirectoryDirectoryEntrySymbolicLink
    //
    //   Author: $author$
    //     Date: 6/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnFileDirectoryDirectoryEntrySymbolicLink
    (const EvFileDirectoryEntry& entry,
     const EvFilePath& path,
     const EvFilePath& reflectedPath,
     EvFileSystemEntryReaderEvents* deligate=0) = 0;
    ///////////////////////////////////////////////////////////////////////
    // Function: OnFileDirectoryDirectoryEntry
    //
    //   Author: $author$
    //     Date: 6/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnFileDirectoryDirectoryEntry
    (const EvFileDirectoryEntry& entry,
     const EvFilePath& path,
     const EvFilePath& reflectedPath,
     EvFileSystemEntryReaderEvents* deligate=0) = 0;
};

///////////////////////////////////////////////////////////////////////
//  Class: EvFileSystemEntryReaderEventsImplement
//
// Author: $author$
//   Date: 5/19/2008
///////////////////////////////////////////////////////////////////////
class EV_EXPORT_CLASS EvFileSystemEntryReaderEventsImplement
: virtual public EvFileSystemEntryReaderEvents
{
public:
    typedef EvFileSystemEntryReaderEvents CEvImplements;
    typedef EvFileSystemEntryReaderEventsImplement CEvDerives;
    ///////////////////////////////////////////////////////////////////////
    // Function: OnFileSystemEntry
    //
    //   Author: $author$
    //     Date: 6/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnFileSystemEntry
    (const EvFileSystemEntry& entry,
     const EvFilePath& path,
     const EvFilePath& reflectedPath,
     EvFileSystemEntryReaderEvents* deligate=0)
    {
        EvError error = EV_ERROR_NONE;
        if (deligate)
            error = deligate->OnFileSystemEntry
            (entry, path, reflectedPath);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: OnFileSystemFileEntry
    //
    //   Author: $author$
    //     Date: 6/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnFileSystemFileEntry
    (const EvFileSystemEntry& entry,
     const EvFilePath& path,
     const EvFilePath& reflectedPath,
     EvFileSystemEntryReaderEvents* deligate=0)
    {
        EvError error = EV_ERROR_NONE;
        if (deligate)
            error = deligate->OnFileSystemFileEntry
            (entry, path, reflectedPath);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: OnFileSystemDirectoryEntry
    //
    //   Author: $author$
    //     Date: 6/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnFileSystemDirectoryEntry
    (const EvFileSystemEntry& entry, 
     const EvFilePath& path,
     const EvFilePath& reflectedPath,
     EvFileSystemEntryReaderEvents* deligate=0)
    {
        EvError error = EV_ERROR_NONE;
        if (deligate)
            error = deligate->OnFileSystemDirectoryEntry
            (entry, path, reflectedPath);
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: OnFileDirectoryEntry
    //
    //   Author: $author$
    //     Date: 6/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnFileDirectoryEntry
    (const EvFileDirectoryEntry& entry,
     const EvFilePath& path,
     const EvFilePath& reflectedPath,
     EvFileSystemEntryReaderEvents* deligate=0)
    {
        EvError error = EV_ERROR_NONE;
        if (deligate)
            error = deligate->OnFileDirectoryEntry
            (entry, path, reflectedPath);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: OnFileDirectoryFileEntry
    //
    //   Author: $author$
    //     Date: 6/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnFileDirectoryFileEntry
    (const EvFileDirectoryEntry& entry,
     const EvFilePath& path,
     const EvFilePath& reflectedPath,
     EvFileSystemEntryReaderEvents* deligate=0)
    {
        EvError error = EV_ERROR_NONE;
        if (deligate)
            error = deligate->OnFileDirectoryFileEntry
            (entry, path, reflectedPath);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: OnFileDirectoryDirectoryEntry
    //
    //   Author: $author$
    //     Date: 6/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnFileDirectoryDirectoryEntry
    (const EvFileDirectoryEntry& entry,
     const EvFilePath& path,
     const EvFilePath& reflectedPath,
     EvFileSystemEntryReaderEvents* deligate=0)
    {
        EvError error = EV_ERROR_NONE;
        if (deligate)
            error = deligate->OnFileDirectoryDirectoryEntry
            (entry, path, reflectedPath);
        return error;
    }
};
#endif // _EVFILESYSTEMENTRYREADEREVENTS_HPP
