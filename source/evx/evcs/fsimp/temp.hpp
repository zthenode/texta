///////////////////////////////////////////////////////////////////////
//   File: cevfsevcsget.hpp
//
// Author: $author$
//   Date: 10/1/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVFSEVCSGET_HPP
#define _CEVFSEVCSGET_HPP

#include "cevcsget.hpp"
#include "cevcsentry.hpp"
#include "cevfilesystementryfilter.hpp"
#include "cevfilesystementry.hpp"
#include "cevfilesystem.hpp"
#include "cevfilepath.hpp"
#include "cevcscharfile.hpp"

#define DEFAULT_EVCSGET_VC_DIRECTORY "EVD/EVCS/VC"
#define DEFAULT_EVCSGET_GET_DIRECTORY "EVD/EVCS/CO"

///////////////////////////////////////////////////////////////////////
//  Class: CEvfsEvcsGet
//
// Author: $author$
//   Date: 10/1/2007
///////////////////////////////////////////////////////////////////////
class CEvfsEvcsGet
: public CEvcsGet
{
public:
    typedef CEvcsGet CExtends;
    typedef CEvfsEvcsGet CDerives;

    typedef LONG (CDerives::*MReadBlock)
    (EvcsEntry& entry,
     char* chars, ULONG size);

    CEvFilePath m_vcDirectory;
    CEvFilePath m_vcPath;
    CEvFilePath m_vcFilePath;

    CEvFilePath m_tempDirectory;
    CEvFilePath m_tempPath;
    CEvFilePath m_tempFilePath;

    CEvFilePath m_entryPath;
    CEvFileSystemEntryFilter m_fileEntryFilter;

    CEvcsCharFile m_vcFile;
    CEvcsCharFile m_tempFile;

    CEvFileSystemEntry m_fileSystemEntry;
    CEvFileSystem m_fileSystem;

    bool m_isBinary;
    const char* m_versionDirectory;
    const char* m_versionExtension;

    MReadBlock m_readBlock;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvfsEvcsGet
    //
    //       Author: $author$
    //         Date: 10/1/2007
    ///////////////////////////////////////////////////////////////////////
    CEvfsEvcsGet
    (const char* vcDirectory=DEFAULT_EVCSGET_VC_DIRECTORY,
     const char* tempDirectory=DEFAULT_EVCSGET_GET_DIRECTORY) 
    : m_isBinary(false),
      m_versionDirectory(0),
      m_versionExtension(0),
      m_readBlock(0)
    {
        EvError error;
        LONG length;

        if (0 > (length = m_vcDirectory.AssignChars(vcDirectory)))
            throw(error = -length);

        if (0 > (length = m_tempDirectory.AssignChars(tempDirectory)))
            throw(error = -length);
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvfsEvcsGet
    //
    //      Author: $author$
    //        Date: 10/1/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvfsEvcsGet()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Finish
    //
    //   Author: $author$
    //     Date: 10/2/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Finish() 
    {
        EvError error = EV_ERROR_NONE;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Cancel
    //
    //   Author: $author$
    //     Date: 10/2/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Cancel() 
    {
        EvError error = Close();
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: OpenFirst
    //
    //   Author: $author$
    //     Date: 9/28/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OpenFirst
    (EvcsEntry& entry,
     const char* entryPathName,
     bool isRecursive=false) 
    {
        EvFilePath& entryFilePath = entry.GetFilePath();
        EvFilePath& entryRelativeFilePath = entry.GetRelativeFilePath();
        EvFileSystemEntryTimes& entryFileTimes = entry.GetFileTimes();
        EvError error = EV_ERROR_FAILED;
        const char* chars;
        LONG length;
        int entryType;
        int pathEntryType;

        if (0 < (length = m_entryPath.AssignChars(entryPathName)))
        if ((chars = m_entryPath.HasChars(length)))
        if (0 < (length = entryFilePath.AssignChars(chars, length)))
        if ((chars = entryFilePath.HasChars(length)))
        if ((chars = m_tempDirectory.Chars(length)))
        if (0 <= (length = m_tempPath.AssignChars(chars)))
        if (0 < (length = m_tempPath.AppendFileName(entryPathName)))
        if ((chars = m_tempPath.HasChars(length)))
        if ((chars = m_vcDirectory.Chars(length)))
        if (0 < (length = m_vcPath.AssignChars(chars)))
        if (0 < (length = m_vcPath.AppendFileName(entryPathName)))
        if ((entryPathName = m_vcPath.HasChars(length)))
        if (0 < (entryType = m_fileEntryFilter.ReadFirst
            (entryRelativeFilePath, entryFileTimes, 
             pathEntryType, entryPathName, 0, isRecursive)))
        if (EvFileSystemEntry::EV_TYPE_DIRECTORY != pathEntryType)
        {
            error  = OpenFile(entry);
        }
        else
        {
            error  = OpenFile(entry);
        }

        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: OpenNext
    //
    //   Author: $author$
    //     Date: 9/28/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OpenNext
    (EvcsEntry& entry) 
    {
        EvFilePath& entryRelativeFilePath = entry.GetRelativeFilePath();
        EvFileSystemEntryTimes& entryFileTimes = entry.GetFileTimes();
        EvError error = EV_ERROR_FAILED;
        int entryType;

        if (0 < (entryType = m_fileEntryFilter.ReadNext
            (entryRelativeFilePath, entryFileTimes)))
             error = OpenFile(entry);

        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Close
    //
    //   Author: $author$
    //     Date: 9/28/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Close() 
    {
        EvError error = CloseTempFile();
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: OpenFile
    //
    //   Author: $author$
    //     Date: 10/1/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OpenFile
    (EvcsEntry& entry) 
    {
        EvFilePath& entryFilePath = entry.GetFilePath();
        EvFilePath& entryRelativeFilePath = entry.GetRelativeFilePath();
        EvError error = EV_ERROR_FAILED;
        const char* entryPathName;
        const char* chars;
        LONG length;

        if ((entryPathName = entryRelativeFilePath.HasChars(length)))
        if (0 < (length = entryFilePath.AppendName(entryPathName, length)))
        if ((chars = entryFilePath.HasChars(length)))
        if ((chars = m_tempPath.HasChars(length)))
        if (0 < (length = m_tempFilePath.AssignChars(chars, length)))
        if (0 < (length = m_tempFilePath.AppendFileName(entryPathName)))
        if ((chars = m_tempFilePath.HasChars(length)))
        {
            m_readBlock = &CDerives::FirstReadBlock;
            error = EV_ERROR_NONE;
        }

        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ReadBlock
    //
    //   Author: $author$
    //     Date: 9/28/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG ReadBlock
    (EvcsEntry& entry,
     char* chars, ULONG size) 
    {
        LONG count = -EV_ERROR_FAILED;
        if (m_readBlock)
            count = (this->*m_readBlock)(entry, chars, size);
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: FirstReadBlock
    //
    //   Author: $author$
    //     Date: 10/2/2007
    ///////////////////////////////////////////////////////////////////////
    LONG FirstReadBlock
    (EvcsEntry& entry,
     char* chars, ULONG size) 
    {
        EvFileSystemEntryTimes& entryFileTimes = entry.GetFileTimes();
        LONG count = -EV_ERROR_FAILED;
        const char* vcFilePathName;
        const char* tempFilePathName;
        LONG length;
        LONG flushed;
        EvError error2;

        m_readBlock = 0;

        if ((vcFilePathName = m_vcFilePath.HasChars(length)))
        {
            DBT("() vc file is \"%s\"\n", vcFilePathName);

            if ((tempFilePathName = m_tempFilePath.HasChars(length)))
            {
                DBT("() temp file is \"%s\"\n", tempFilePathName);

                if ((error2 = m_fileSystemEntry.
                    SetFileTimesToSet(entryFileTimes)))
                    DBE("() failed to set file times to set\n");

                else if ((error2 = m_vcFile.OpenToRead
                        (vcFilePathName, m_isBinary)))
                        DBE("() failed to open vc file \"%s\"\n", vcFilePathName);

                else if ((error2 = m_tempFile.OpenToWrite
                        (m_fileSystem, tempFilePathName, m_isBinary, 
                         true, true, m_versionDirectory, m_versionExtension)))
                {
                    DBE("() failed to open temp file \"%s\"\n", tempFilePathName);
                    CloseVcFile();
                }
                else
                {
                    while(0 <= (length = m_vcFile.Read(chars, size)))
                    {
                        if (0 < length)
                        if (0 < (length = m_tempFile.Write(chars, length)))
                        if (0 <= (flushed = m_tempFile.Flush()))
                        if ((ULONG)length >= size)
                            continue;
                        break;
                    }

                    CloseVcFile();

                    if (!(error2 = CloseTempFile()))
                    if ((error2 = m_fileSystemEntry.
                        SetExistingTimesSet(tempFilePathName)))
                        DBE("() failed to set file times for \"%s\"\n", tempFilePathName);

                    else if ((error2 = m_tempFile.OpenToRead
                            (tempFilePathName, m_isBinary)))
                            DBE("() failed to open temp file \"%s\"\n", tempFilePathName);

                    else count = m_tempFile.Read(chars, size);
                }
            }
        }
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: NextReadBlock
    //
    //   Author: $author$
    //     Date: 10/2/2007
    ///////////////////////////////////////////////////////////////////////
    LONG NextReadBlock
    (EvcsEntry& entry,
     char* chars, ULONG size) 
    {
        LONG count = -EV_ERROR_FAILED;
        const char* vcPathName;
        const char* tempPathName;
        LONG length;

        m_readBlock = 0;
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: CloseVcFile
    //
    //   Author: $author$
    //     Date: 10/3/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError CloseVcFile() 
    {
        EvError error = EV_ERROR_FAILED;
        EvError error2;

        if ((error2 = m_vcFile.Close()))
            DBE("() failed to close vc file\n");
        else error = EV_ERROR_NONE;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: CloseTempFile
    //
    //   Author: $author$
    //     Date: 10/3/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError CloseTempFile() 
    {
        EvError error = EV_ERROR_FAILED;
        EvError error2;

        if ((error2 = m_tempFile.Close()))
            DBE("() failed to close temp file\n");
        else error = EV_ERROR_NONE;
        return error;
    }
};
#endif // _CEVFSEVCSGET_HPP
