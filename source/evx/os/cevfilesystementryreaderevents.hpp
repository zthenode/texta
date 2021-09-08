///////////////////////////////////////////////////////////////////////
//   File: cevfilesystementryreaderevents.hpp
//
// Author: $author$
//   Date: 7/10/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVFILESYSTEMENTRYREADEREVENTS_HPP
#define _CEVFILESYSTEMENTRYREADEREVENTS_HPP

#include "evfilesystementryreaderevents.hpp"
#include "cevbase.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvFileSystemEntryReaderEvents
//
// Author: $author$
//   Date: 7/10/2007
///////////////////////////////////////////////////////////////////////
class CEvFileSystemEntryReaderEvents
: virtual public EvFileSystemEntryReaderEvents,
  public CEvBase
{
public:
    typedef EvFileSystemEntryReaderEvents CImplements;
    typedef CEvBase CExtends;
    typedef CEvFileSystemEntryReaderEvents CDerives;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvFileSystemEntryReaderEvents
    //
    //       Author: $author$
    //         Date: 7/10/2007
    ///////////////////////////////////////////////////////////////////////
    CEvFileSystemEntryReaderEvents() 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvFileSystemEntryReaderEvents
    //
    //      Author: $author$
    //        Date: 7/10/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvFileSystemEntryReaderEvents()
    {
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
};
#endif // _CEVFILESYSTEMENTRYREADEREVENTS_HPP
