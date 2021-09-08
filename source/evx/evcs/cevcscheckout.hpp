///////////////////////////////////////////////////////////////////////
//   File: cevcscheckout.hpp
//
// Author: $author$
//   Date: 8/16/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCSCHECKOUT_HPP
#define _CEVCSCHECKOUT_HPP

#include "evcscheckout.hpp"
#include "cevcscheck.hpp"
#include "cevcsop.hpp"
#include "cev2filesystementrytimesdeligate.hpp"
#include "cevfilesystem.hpp"
#include "cevfiledirectory.hpp"

#define DEFAULT_CEVCS_CHECKOUT_TEMP_DIR "EVCS/CO"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcsCheckOut
//
// Author: $author$
//   Date: 8/16/2007
///////////////////////////////////////////////////////////////////////
class CEvcsCheckOut
: virtual public EvcsCheckOut,
  public CEvcsCheck
{
public:
    typedef EvcsCheckOut CImplements;
    typedef CEvcsCheck CExtends;
    typedef CEvcsCheckOut CDerives;
    
    CEvFileSystemEntry m_fileSystemEntry;
    CEvFileSystemEntry m_vcFileSystemEntry;
    CEv2FileSystemEntryTimesDeligate m_vcFileSystemEntryTimes;

    CEvFileDirectory m_fileDirectory;

    CEvCharFile m_vcFile;
    bool m_isRead;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcsCheckOut
    //
    //       Author: $author$
    //         Date: 8/16/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcsCheckOut
    (const char* evcName=0, 
     const char* tempDirectory=DEFAULT_CEVCS_CHECKOUT_TEMP_DIR,
     const char* vcDirectory=DEFAULT_CEVCS_VC_DIR,
     const char* vcExtension=DEFAULT_CEVCS_VC_EXTENSION,
     bool isBinary=false) 
    : CExtends
      (evcName, tempDirectory, 
       vcDirectory, vcExtension, isBinary),
      m_vcFileSystemEntryTimes(m_vcFileSystemEntry),
      m_isRead(false)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvcsCheckOut
    //
    //      Author: $author$
    //        Date: 8/16/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvcsCheckOut()
    {
        EvError error;

        if (GetIsOpen())
        if ((error = Close(true)))
            throw(error);
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: OpenFirst
    //
    //   Author: $author$
    //     Date: 5/29/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OpenFirst
    (EvFileSystemEntry& fileEntry,
     const char* evcName, 
     bool isBinary=false, 
     bool isRecursive=false) 
    {
        EvError error = OpenFirst
        (m_evcDirectoryFilePath, fileEntry, 
         evcName, isBinary, isRecursive);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: OpenNext
    //
    //   Author: $author$
    //     Date: 5/29/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OpenNext
    (EvFileSystemEntry& fileEntry) 
    {
        EvError error = OpenNext
        (m_evcDirectoryFilePath, fileEntry);
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: OpenFirst
    //
    //   Author: $author$
    //     Date: 5/29/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OpenFirst
    (CEvFilePath& filePath,
     EvFileSystemEntry& fileEntry,
     const char* evcName, 
     bool isBinary=false, 
     bool isRecursive=false) 
    {
        EvError error = EV_ERROR_FAILED;
        EvError error2;
        const char* chars;
        LONG length;
        int entryType;
        int is;

        DBF("() in...\n");

        if (0 <= (is = SetIsBinary(isBinary)))
        if (!(error2 = MakeVcFilename(evcName, true)))
        if ((chars = GetVcFilename(length)) && (0 < length))
        if (EvFileSystemEntry::EV_TYPE_NONE >=
            (entryType = m_vcFileSystemEntry.Exists(chars)))
            DBE("() \"%s\" does not exist\n", chars);
        else
        {
            switch(entryType)
            {
            case EvFileSystemEntry::EV_TYPE_FILE:
                error = OpenFile
                (fileEntry, chars, evcName, isBinary);
                break;

            case EvFileSystemEntry::EV_TYPE_DIRECTORY:
                error = OpenDirectory
                (filePath, fileEntry, 
                 chars, evcName, isBinary, isRecursive);
                break;

            default:
                DBE("() entry \"%s\"'s type is unexpected\n", chars);
            }
        }
        DBF("() ...out\n");
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: OpenNext
    //
    //   Author: $author$
    //     Date: 8/21/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OpenNext
    (CEvFilePath& filePath,
     EvFileSystemEntry& fileEntry) 
    {
        EvError error = ReadDirectoryNext
        (filePath, fileEntry);
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Commit
    //
    //   Author: $author$
    //     Date: 8/16/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Commit() 
    {
        EvError error = EV_ERROR_NONE;
        bool isOpen;
        const char* chars;
        LONG length;

        chars = m_tempPath.Chars(length);

        if ((isOpen = GetIsOpen()))
            Close(true);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Cancel
    //
    //   Author: $author$
    //     Date: 8/16/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Cancel() 
    {
        EvError error = EV_ERROR_NONE;
        bool isOpen;
        if ((isOpen = GetIsOpen()))
            Close(true);
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: OpenFile
    //
    //   Author: $author$
    //     Date: 9/17/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OpenFile
    (EvFileSystemEntry& fileEntry,
     const char* vcName, 
     const char* evcName, 
     bool isBinary=false) 
    {
        EvError error = OpenFile
        (fileEntry, m_vcFileSystemEntryTimes, 
         vcName, evcName, isBinary);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: OpenFile
    //
    //   Author: $author$
    //     Date: 8/22/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OpenFile
    (EvFileSystemEntry& fileEntry,
     const EvFileSystemEntryTimes& fileTimes,
     const char* vcName, 
     const char* evcName, 
     bool isBinary=false) 
    {
        EvError error = EV_ERROR_FAILED;
        EvError error2;
        const char* tempChars;
        LONG tempLength;

        DBF("() in...\n");

        if (!(error2 = MakeTempFilename(evcName)))
        if ((tempChars = GetTempFilename
            (tempLength)) && (0 < tempLength))
        {
            DBT("() check out \"%s\" <-- \"%s\"\n", tempChars, vcName);

            if ((error2 = m_fileSystemEntry.
                SetFileTimesToSet(fileTimes)))
                DBE("() failed to set file times to set\n");

            else if ((error2 = m_vcFile.Open
                    (vcName, isBinary
                     ?CEVCSOP_FILE_MODE_READ_BINARY
                     :CEVCSOP_FILE_MODE_READ_TEXT)))
                    DBE("() failed to open file \"%s\"\n", vcName);

            else if ((error2 = m_tempFile.Open
                    (tempChars, isBinary
                     ?CEVCSOP_FILE_MODE_WRITE_BINARY
                     :CEVCSOP_FILE_MODE_WRITE_TEXT)))
            {
                DBE("() failed to open file \"%s\"\n", tempChars);
                m_vcFile.Close();
            }
            else if ((error2 = fileEntry.
                     CopyFileTimes(fileTimes)))
            {
                DBE("() failed to copy file times\n");
                m_vcFile.Close();
            }
            else
            {
                SetIsOpen();
                SetIsRead(false);
                error = EV_ERROR_NONE;
            }
        }
        DBF("() ...out\n");
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: OpenDirectory
    //
    //   Author: $author$
    //     Date: 8/22/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OpenDirectory
    (EvFileSystemEntry& fileEntry,
     const char* vcName, 
     const char* evcName, 
     bool isBinary=false, 
     bool isRecursive=false) 
    {
        EvError error = OpenDirectory
        (m_evcDirectoryFilePath, fileEntry, 
         vcName, evcName, isBinary, isRecursive);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: OpenDirectory
    //
    //   Author: $author$
    //     Date: 8/22/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OpenDirectory
    (CEvFilePath& filePath,
     EvFileSystemEntry& fileEntry,
     const char* vcName, 
     const char* evcName, 
     bool isBinary=false, 
     bool isRecursive=false) 
    {
        EvError error = EV_ERROR_FAILED;
        int entryType;
        const char* chars;
        LONG length;

        DBF("() in...\n");

        if (0 <= (length = m_vcDirectoryFileDirectory.AssignChars(vcName)))
        if (0 <= (length = m_evcDirectoryFileDirectory.AssignChars(evcName)))
        if (0 <= (length = m_vcDirectoryFilePath.AssignChars(vcName)))
        if (0 <= (length = m_evcDirectoryFilePath.AssignChars(evcName)))
        //if (0 < (entryType = m_fileSystemEntryReader.
        //    ReadFirst(m_vcFilePath, m_vcFileTimes, vcName, 0, isRecursive, true)))
        if (0 < (entryType = m_fileSystemEntryFilter.
            ReadFirst(m_vcFilePath, m_vcFileTimes, vcName, 0, isRecursive, true)))
        {
            if ((chars = m_vcFilePath.HasChars(length)))
            {
                DBT("() read first file \"%s\"\n", chars);

                if (0 < (length = m_vcDirectoryFilePath.
                    AppendFileName(chars, length)))
                if ((vcName = m_vcDirectoryFilePath.HasChars(length)))
                {
                    DBT("() vc file is \"%s\"\n", vcName);

                    if (0 < (length = m_evcDirectoryFilePath.
                        AppendFileName(chars, length)))
                    if ((evcName = m_evcDirectoryFilePath.HasChars(length)))
                    {
                        DBT("() evc file is \"%s\"\n", evcName);

                        if (!(error = OpenFile
                            (fileEntry, m_vcFileTimes, 
                             vcName, evcName, isBinary)))
                        if (&filePath != &m_evcDirectoryFilePath)
                            filePath.Assign(evcName, length);
                    }
                }
            }
        }
        DBF("() ...out\n");
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ReadDirectoryNext
    //
    //   Author: $author$
    //     Date: 9/16/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ReadDirectoryNext
    (EvFileSystemEntry& fileEntry) 
    {
        EvError error = ReadDirectoryNext
        (m_evcDirectoryFilePath, fileEntry);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ReadDirectoryNext
    //
    //   Author: $author$
    //     Date: 9/16/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ReadDirectoryNext
    (CEvFilePath& filePath,
     EvFileSystemEntry& fileEntry) 
    {
        EvError error = EV_ERROR_FAILED;
        bool isBinary = GetIsBinary();
        int entryType;
        const char* vcName;
        const char* evcName;
        const char* chars;
        LONG length;

        DBF("() in...\n");

        if ((vcName = m_vcDirectoryFileDirectory.Chars(length)))
        if ((evcName = m_evcDirectoryFileDirectory.Chars(length)))
        if (0 <= (length = m_vcDirectoryFilePath.AssignChars(vcName)))
        if (0 <= (length = m_evcDirectoryFilePath.AssignChars(evcName)))
        //if (0 < (entryType = m_fileSystemEntryReader.
        //    ReadNext(m_vcFilePath, m_vcFileTimes)))
        if (0 < (entryType = m_fileSystemEntryFilter.
            ReadNext(m_vcFilePath, m_vcFileTimes)))
        {
            if ((chars = m_vcFilePath.HasChars(length)))
            {
                DBT("() read next file \"%s\"\n", chars);

                if (0 < (length = m_vcDirectoryFilePath.
                    AppendFileName(chars, length)))
                if ((vcName = m_vcDirectoryFilePath.HasChars(length)))
                {
                    DBT("() vc file is \"%s\"\n", vcName);

                    if (0 < (length = m_evcDirectoryFilePath.
                        AppendFileName(chars, length)))
                    if ((evcName = m_evcDirectoryFilePath.HasChars(length)))
                    {
                        DBT("() evc file is \"%s\"\n", evcName);

                        if (!(error = OpenFile
                            (fileEntry, m_vcFileTimes, 
                             vcName, evcName, isBinary)))
                        if (&m_evcDirectoryFilePath != &filePath)
                            filePath.Assign(evcName, length);
                    }
                }
            }
        }
        DBF("() ...out\n");
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Close
    //
    //   Author: $author$
    //     Date: 8/22/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Close
    (bool onlyClose=false) 
    {
        EvError error = EV_ERROR_FAILED;
        EvError error2 = EV_ERROR_FAILED;

        DBF("() in...\n");

        if (!(error2 = CloseTemp(onlyClose)))
        if (!(error2 = CloseVc()))
            error = EV_ERROR_NONE;

        SetIsRead(false);
        SetIsOpen(false);
        DBF("() ...out\n");
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: CloseVc
    //
    //   Author: $author$
    //     Date: 8/23/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError CloseVc() 
    {
        EvError error = EV_ERROR_FAILED;
        EvError error2 = EV_ERROR_FAILED;
        const char* vcChars;
        LONG vcLength;

        DBF("() in...\n");

        if (!(vcChars = GetVcFilename
            (vcLength)) || (0 >= vcLength))
            DBE("() invalid vc file name\n");

        else if ((error2 = m_vcFile.Close()))
                DBE("() failed to close vc file \"%s\"\n", vcChars);

        else error = EV_ERROR_NONE;

        DBF("() ...out\n");
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: OpenTemp
    //
    //   Author: $author$
    //     Date: 8/23/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OpenTemp() 
    {
        EvError error = EV_ERROR_FAILED;
        EvError error2 = EV_ERROR_FAILED;
        const char* tempChars;
        LONG tempLength;
        bool isBinary;

        DBF("() in...\n");

        isBinary = GetIsBinary();

        if (!(tempChars = GetTempFilename
            (tempLength)) || (0 >= tempLength))
            DBE("() invalid temp file name\n");

        else if ((error2 = m_tempFile.Open
                 (tempChars, isBinary
                  ?CEVCSOP_FILE_MODE_READ_BINARY
                  :CEVCSOP_FILE_MODE_READ_TEXT)))
                DBE("() failed to open file \"%s\"\n", tempChars);
        else
        {
            SetIsOpen();
            error = EV_ERROR_NONE;
        }
        DBF("() ...out\n");
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: CloseTemp
    //
    //   Author: $author$
    //     Date: 8/23/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError CloseTemp
    (bool onlyClose=false) 
    {
        EvError error = EV_ERROR_FAILED;
        EvError error2 = EV_ERROR_FAILED;
        const char* tempChars;
        LONG tempLength;

        DBF("() in...\n");

        if (!(tempChars = GetTempFilename
            (tempLength)) || (0 >= tempLength))
            DBE("() invalid temp file name\n");

        else if ((error2 = m_tempFile.Close()))
                DBE("() failed to close temp file \"%s\"\n", tempChars);

        else if (onlyClose)
                error = EV_ERROR_NONE;

        else if ((error2 = m_fileSystemEntry.
                  SetExistingTimesSet(tempChars)))
                DBE("() failed to set file times for \"%s\"\n", tempChars);

        if (!error2)
            error = EV_ERROR_NONE;

        DBF("() ...out\n");
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: ReadVc
    //
    //   Author: $author$
    //     Date: 8/23/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ReadVc
    (char* chars, ULONG size) 
    {
        EvError error = EV_ERROR_FAILED;
        LONG read;
        LONG count;
        bool is;

        if ((is = GetIsOpen()))
        {
            while(0 <= (read = m_vcFile.Read(chars, size)))
            {
                if (0 < read)
                if (0 <= (count = m_tempFile.Write(chars, read)))
                if (0 <= (count = m_tempFile.Flush()))
                if ((ULONG)read >= size)
                    continue;
                break;
            }

            if (!(error = Close()))
            if (!(error = OpenTemp()))
                SetIsRead();
        }
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Read
    //
    //   Author: $author$
    //     Date: 8/23/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Read
    (char* chars, ULONG size) 
    {
        LONG length = -EV_ERROR_FAILED;
        LONG read;
        EvError error;
        bool is;

        if ((is = GetIsOpen()))
        {
            if (!(is = GetIsRead()))
            if ((error = ReadVc(chars, size)))
                return length;

            if (0 <= (read = m_tempFile.Read(chars, size)))
            if (size > (ULONG)(length = read))
                Close();
        }
        return length;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetIsRead
    //
    //   Author: $author$
    //     Date: 8/23/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int SetIsRead(bool is=true) 
    {
        m_isRead = is;
        return m_isRead;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetIsRead
    //
    //   Author: $author$
    //     Date: 8/23/2007
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetIsRead() const 
    {
        return m_isRead;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: DeleteThis
    //
    //   Author: $author$
    //     Date: 8/17/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError DeleteThis() 
    {
        delete this;
        return EV_ERROR_NONE;
    }
};

#endif // _CEVCSCHECKOUT_HPP
