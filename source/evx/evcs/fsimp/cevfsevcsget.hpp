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
#include "cevfilesystementryfilter.hpp"
#include "cevfsevcsaction.hpp"
#include "evfsevcs.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvfsEvcsGet
//
// Author: $author$
//   Date: 10/1/2007
///////////////////////////////////////////////////////////////////////
class CEvfsEvcsGet
: public CEvfsEvcsAction<CEvcsGet>
{
public:
    typedef CEvfsEvcsAction<CEvcsGet> CExtends;
    typedef CEvfsEvcsGet CDerives;

    typedef LONG (CDerives::*MReadBlock)
    (EvcsEntry& entry,
     char* chars, ULONG size);

    CEvFileSystemEntryFilter m_fileEntryFilter;

    MReadBlock m_readBlock;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvfsEvcsGet
    //
    //       Author: $author$
    //         Date: 10/1/2007
    ///////////////////////////////////////////////////////////////////////
    CEvfsEvcsGet
    (EvcsArchive& archive,
     const char* vcDirectory=DEFAULT_EVFSEVCS_VC_DIRECTORY,
     const char* tempDirectory=DEFAULT_EVFSEVCS_GET_DIRECTORY) 
    : CExtends(archive, vcDirectory, tempDirectory),
      m_readBlock(0)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvfsEvcsGet
    //
    //      Author: $author$
    //        Date: 10/1/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvfsEvcsGet()
    {
        EvError error;
        if ((error = Close()))
            throw(error);
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
        const char* vcPathName;
        const char* chars;
        LONG length;
        int entryType;
        int pathEntryType;

        if (0 < (length = entryFilePath.AssignChars(entryPathName)))
        if ((chars = m_tempDirectory.Chars(length)))
        if (0 <= (length = m_tempPath.AssignChars(chars)))
        if (0 <= (length = m_tempFilePath.AssignChars(chars)))
        if ((chars = m_vcDirectory.Chars(length)))
        if (0 < (length = m_vcPath.AssignChars(chars)))
        if (0 < (length = m_vcFilePath.AssignChars(chars)))
        if (0 < (length = m_vcFilePath.AppendFileName(entryPathName)))
        if ((vcPathName = m_vcFilePath.HasChars(length)))
        if (0 < (entryType = m_fileEntryFilter.ReadFirst
            (entryRelativeFilePath, entryFileTimes, 
             pathEntryType, vcPathName, 0, isRecursive)))
        if (EvFileSystemEntry::EV_TYPE_DIRECTORY != pathEntryType)
        {
            if ((chars = m_vcFilePath.GetFileDirectory(length)))
            if (0 <= (length = m_entryPath.AssignChars(chars, length)))
            if (0 <= (length = m_tempPath.AppendFileName(chars, length)))
            if (0 <= (length = m_vcPath.AppendFileName(chars, length)))
                error  = OpenFile(entry);
        }
        else
        {
            if (0 < (length = m_entryPath.AssignChars(entryPathName)))
            if (0 < (length = m_tempPath.AppendFileName(entryPathName)))
            if (0 < (length = m_vcPath.AppendFileName(entryPathName)))
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

        if ((chars = m_entryPath.HasChars(length)))
        if (0 < (length = entryFilePath.AssignChars(chars, length)))
        if ((entryPathName = entryRelativeFilePath.HasChars(length)))
        if (0 < (length = entryFilePath.AppendName(entryPathName, length)))
        if ((chars = entryFilePath.HasChars(length)))
        if ((chars = m_tempPath.HasChars(length)))
        if (0 < (length = m_tempFilePath.AssignChars(chars, length)))
        if (0 < (length = m_tempFilePath.AppendFileName(entryPathName)))
        if ((chars = m_tempFilePath.HasChars(length)))
        if ((chars = m_vcPath.HasChars(length)))
        if (0 < (length = m_vcFilePath.AssignChars(chars, length)))
        if (0 < (length = m_vcFilePath.AppendFileName(entryPathName)))
        if ((chars = m_vcFilePath.HasChars(length)))
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

                    else if ((LONG)(size) <= (count = m_tempFile.Read(chars, size)))
                            m_readBlock = &CDerives::NextReadBlock;
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
        LONG count;
        if ((0 >= (count = m_tempFile.Read(chars, size)))
            || (size > (ULONG)(count)))
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
