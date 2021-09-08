///////////////////////////////////////////////////////////////////////
//   File: cevfsevcsput.hpp
//
// Author: $author$
//   Date: 10/4/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVFSEVCSPUT_HPP
#define _CEVFSEVCSPUT_HPP

#include "cevcsput.hpp"
#include "cevfsevcsaction.hpp"
#include "evfsevcs.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvfsEvcsPut
//
// Author: $author$
//   Date: 10/4/2007
///////////////////////////////////////////////////////////////////////
class CEvfsEvcsPut
: public CEvfsEvcsAction<CEvcsPut>
{
public:
    typedef CEvfsEvcsAction<CEvcsPut> CExtends;
    typedef CEvfsEvcsPut CDerives;

    EvcsDo* m_do;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvfsEvcsPut
    //
    //       Author: $author$
    //         Date: 10/4/2007
    ///////////////////////////////////////////////////////////////////////
    CEvfsEvcsPut
    (EvcsArchive& archive,
     const char* vcDirectory=DEFAULT_EVFSEVCS_VC_DIRECTORY,
     const char* tempDirectory=DEFAULT_EVFSEVCS_PUT_DIRECTORY) 
    : CExtends(archive, vcDirectory, tempDirectory),
      m_do(0)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvfsEvcsPut
    //
    //      Author: $author$
    //        Date: 10/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvfsEvcsPut()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Finish
    //
    //   Author: $author$
    //     Date: 10/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Finish() 
    {
        EvError error;
        EvError error2;
        
        if (!(error = Close()))
        {
            if (!m_do)
            if ((m_do = m_archive.GetDo(error2)))
            if (!(error2 = m_do->AddAction(*this)))
                return error;

            m_do = 0;
            error = CommitTempFile();
        }
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Cancel
    //
    //   Author: $author$
    //     Date: 10/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Cancel() 
    {
        EvError error = Close();
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Open
    //
    //   Author: $author$
    //     Date: 10/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Open
    (const EvcsEntry& entry,
     const char* entryPathName) 
    {
        const EvFileSystemEntryTimes& entryFileTimes = entry.GetFileTimes();
        EvError error = EV_ERROR_FAILED;
        const char* tempFilePathName;
        const char* vcFilePathName;
        const char* chars;
        LONG length;
        EvError error2;

        if ((chars = m_tempDirectory.Chars(length)))
        if (0 <= (length = m_tempPath.AssignChars(chars)))
        if (0 <= (length = m_tempFilePath.AssignChars(chars)))
        if (0 < (length = m_tempFilePath.AppendFileName(entryPathName)))
        if ((tempFilePathName = m_tempFilePath.HasChars(length)))
        {
            DBT("() temp file is \"%s\"\n", tempFilePathName);

            if ((chars = m_vcDirectory.Chars(length)))
            if (0 < (length = m_vcPath.AssignChars(chars)))
            if (0 < (length = m_vcFilePath.AssignChars(chars)))
            if (0 < (length = m_vcFilePath.AppendFileName(entryPathName)))
            if ((vcFilePathName = m_vcFilePath.HasChars(length)))
            {
                DBT("() vc file is \"%s\"\n", vcFilePathName);

                if ((error2 = m_fileSystemEntry.
                    SetFileTimesToSet(entryFileTimes)))
                    DBE("() failed to set file times to set\n");

                else 
                if ((error2 = m_tempFile.OpenToWrite
                    (m_fileSystem, tempFilePathName, m_isBinary, 
                     true, true, m_versionDirectory, m_versionExtension)))
                    DBE("() failed to open temp file \"%s\"\n", tempFilePathName);
                else
                error = EV_ERROR_NONE;
            }
        }
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Close
    //
    //   Author: $author$
    //     Date: 10/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Close() 
    {
        EvError error = CloseTempFile();
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: WriteBlock
    //
    //   Author: $author$
    //     Date: 10/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG WriteBlock
    (EvcsEntry& entry,
     char* chars, ULONG size) 
    {
        LONG count = m_tempFile.Write(chars, size);
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: CommitTempFile
    //
    //   Author: $author$
    //     Date: 10/8/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError CommitTempFile() 
    {
        EvError error = EV_ERROR_FAILED;
        EvError error2;
        const char* tempFilePathName;
        const char* vcFilePathName;
        LONG length;

        if ((tempFilePathName = m_tempFilePath.HasChars(length)))
        if ((vcFilePathName = m_vcFilePath.HasChars(length)))
        {
            DBT
            ("() commit \"%s\" --> \"%s\"\n",
             tempFilePathName, vcFilePathName);

            if (!(error2 = m_tempFile.Rename
                (m_fileSystem, tempFilePathName, vcFilePathName, 
                 true, true, m_versionDirectory, m_versionExtension)))
                error = EV_ERROR_NONE;
        }
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: CloseTempFile
    //
    //   Author: $author$
    //     Date: 10/6/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError CloseTempFile() 
    {
        EvError error = EV_ERROR_FAILED;
        EvError error2;
        const char* tempFilePathName;
        LONG length;
        bool isOpen;

        if (!(isOpen = m_tempFile.GetIsOpen()))
            error = EV_ERROR_NONE;
        else
        if ((error2 = m_tempFile.Close()))
            DBE("() failed to close temp file\n");
        else 
        if ((tempFilePathName = m_tempFilePath.HasChars(length)))
        {
            if ((error2 = m_fileSystemEntry.
                SetExistingTimesSet(tempFilePathName)))
                DBE("() failed to set file times for \"%s\"\n", tempFilePathName);
            else
            error = EV_ERROR_NONE;
        }
        return error;
    }
};
#endif // _CEVFSEVCSPUT_HPP
