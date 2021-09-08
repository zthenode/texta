///////////////////////////////////////////////////////////////////////
//   File: cevfs.hpp
//
// Author: $author$
//   Date: 9/14/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVFS_HPP
#define _CEVFS_HPP

#include "evfs.hpp"
#include "evcs.hpp"
#include "cevcpfile.hpp"
#include "cevfilesystem.hpp"
#include "cevfilesystementry.hpp"
#include "cevcharfile.hpp"
#include "cevbase.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvfs
//
// Author: $author$
//   Date: 9/14/2007
///////////////////////////////////////////////////////////////////////
class CEvfs
: virtual public Evfs,
  public CEvBase
{
public:
    typedef Evfs CImplements;
    typedef CEvBase CExtends;
    typedef CEvfs CDerives;

    typedef EvError 
    (CDerives::*MCloseFile)();

    CEvFileSystem m_fileSystem;
    CEvFileSystemEntry m_fileEntry;
    CEvFilePath m_fileVersionPath;
    CEvFilePath m_filePath;
    CEvCharFile m_file;

    MCloseFile m_closeFile;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvfs
    //
    //       Author: $author$
    //         Date: 9/14/2007
    ///////////////////////////////////////////////////////////////////////
    CEvfs() 
    : m_closeFile(0)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvfs
    //
    //      Author: $author$
    //        Date: 9/14/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvfs()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: OpenFile2Write
    //
    //   Author: $author$
    //     Date: 9/14/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OpenFile2Write
    (const EvFileSystemEntryTimes& fileTimes,
     const char* filename, bool isBinary=false,
     const char* versionDirectory=0, const char* versionExtension=0) 
    {
        EvError error = EV_ERROR_FAILED;
        EvError error2;
        LONG length;
        int entryType;
        const char* directory;

        if (0 < (length = m_filePath.Assign(filename)))
        if ((filename = m_filePath.HasChars(length)))
        if (!(error2 = m_fileEntry.
            SetFileTimesToSet(fileTimes)))
        {
            if ((entryType = m_fileSystem.
                EntryExists(filename, length)))
            {
                if (versionDirectory || versionExtension)
                {
                    if (!versionDirectory)
                        versionDirectory = DEFAULT_EVFILE_VERSION_DIRECTORY;

                    if (!versionExtension)
                        versionExtension = DEFAULT_EVFILE_VERSION_EXTENSION;

                    if ((error2 = m_fileSystem.MakeVersion
                        (filename, versionDirectory, versionExtension)))
                        filename = 0;
                }
            }
            else 
            {
                if ((directory = m_filePath.
                    GetFileDirectory(length)) && (0 < length))
                if ((error2 = m_fileSystem.
                    MakeDirectory(directory)))
                    filename = 0;
            }

            if (filename)
            if (!(error2 = m_file.Open
                (filename, isBinary
                 ?EVCP_FILE_MODE_WRITE_BINARY
                 :EVCP_FILE_MODE_WRITE_TEXT)))
            {
                m_closeFile = &CDerives::CloseFile2Write;
                error = EV_ERROR_NONE;
            }
        }
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: OpenFile2Read
    //
    //   Author: $author$
    //     Date: 9/14/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OpenFile2Read
    (EvFileSystemEntryTimes& fileTimes,
     const char* filename, bool isBinary=false) 
    {
        EvError error = EV_ERROR_FAILED;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: CloseFile
    //
    //   Author: $author$
    //     Date: 9/14/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError CloseFile() 
    {
        EvError error = EV_ERROR_FAILED;
        if (m_closeFile)
            error = (this->*m_closeFile)();
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: CloseFile2Write
    //
    //   Author: $author$
    //     Date: 9/14/2007
    ///////////////////////////////////////////////////////////////////////
    EvError CloseFile2Write() 
    {
        EvError error = EV_ERROR_FAILED;
        EvError error2;
        const char* filename;
        LONG length;

        m_closeFile = 0;
        if (!(error2 = m_file.Close()))
        if ((filename = m_filePath.HasChars(length)))
        if (!(error2 = m_fileEntry.
            SetExistingTimesSet(filename, length)))
            error = EV_ERROR_NONE;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: CloseFile2Read
    //
    //   Author: $author$
    //     Date: 9/14/2007
    ///////////////////////////////////////////////////////////////////////
    EvError CloseFile2Read() 
    {
        EvError error = EV_ERROR_FAILED;
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: WriteFile
    //
    //   Author: $author$
    //     Date: 9/14/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG WriteFile
    (const char* chars, LONG length=-1) 
    {
        LONG count = m_file.Write(chars, length);
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ReadFile
    //
    //   Author: $author$
    //     Date: 9/14/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG ReadFile
    (char* chars, ULONG size) 
    {
        LONG count = m_file.Read(chars, size);
        return count;
    }
};
#endif // _CEVFS_HPP

