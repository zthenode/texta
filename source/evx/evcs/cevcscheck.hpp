///////////////////////////////////////////////////////////////////////
//   File: cevcscheck.hpp
//
// Author: $author$
//   Date: 8/16/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCSCHECK_HPP
#define _CEVCSCHECK_HPP

#include "evcscheck.hpp"
#include "cevcsop.hpp"
#include "cevfilesystementryfilter.hpp"
#include "cevfilesystementryreader.hpp"
#include "cevfilesystem.hpp"
#include "cevcharfile.hpp"
#include "cevstring.hpp"
#include "evdebug.h"

#define DEFAULT_CEVCS_DIR "EVCS"
#define DEFAULT_CEVCS_TEMP_DIR DEFAULT_CEVCS_DIR "/TEMP"
#define DEFAULT_CEVCS_VC_DIR DEFAULT_CEVCS_DIR "/VC"
#define DEFAULT_CEVCS_VC_EXTENSION DEFAULT_EVFILE_VERSION_EXTENSION

///////////////////////////////////////////////////////////////////////
//  Class: CEvcsCheck
//
// Author: $author$
//   Date: 8/16/2007
///////////////////////////////////////////////////////////////////////
class CEvcsCheck
: virtual public EvcsCheck,
  public CEvcsOp
{
public:
    typedef EvcsCheck CImplements;
    typedef CEvcsOp CExtends;
    typedef CEvcsCheck CDerives;
    
    bool m_isBinary;

    CEvString m_name;

    CEvString m_vcExtension;
    CEvString m_vcExtensionMatch;

    CEvFilePath m_vcDirectory;
    CEvFilePath m_vcPath;

    CEvFilePath m_vcFilePath;
    CEvFilePath m_vcDirectoryFilePath;
    CEvFilePath m_evcDirectoryFilePath;
    CEvFilePath m_vcDirectoryFileDirectory;
    CEvFilePath m_evcDirectoryFileDirectory;

    CEvFileSystemEntryTimes m_vcFileTimes;

    CEvFilePath m_tempDirectory;
    CEvFilePath m_tempPath;

    CEvCharFile m_tempFile;
    CEvFileSystemEntry m_tempFileSystemEntry;

    CEvFileSystem m_fileSystem;
    CEvFileSystemEntry m_fileSystemEntry;
    CEvFileSystemEntryReader m_fileSystemEntryReader;
    CEvFileSystemEntryFilter m_fileSystemEntryFilter;

    bool m_isOpen;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcsCheck
    //
    //       Author: $author$
    //         Date: 8/16/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcsCheck
    (const char* evcName=0, 
     const char* tempDirectory=DEFAULT_CEVCS_TEMP_DIR,
     const char* vcDirectory=DEFAULT_CEVCS_VC_DIR,
     const char* vcExtension=DEFAULT_CEVCS_VC_EXTENSION,
     bool isBinary=false) 
    : m_isBinary(isBinary),
      m_isOpen(false)
    {
        EvError error;
        LONG length;

        if (evcName)
        if (0 > (length = SetName(evcName)))
            throw(error = -length);

        if (tempDirectory)
        if (0 > (length = SetTempDirectory(tempDirectory)))
            throw(error = -length);

        if (vcDirectory)
        if (0 > (length = SetVcDirectory(vcDirectory)))
            throw(error = -length);

        if (vcExtension)
        if (0 > (length = SetVcExtension(vcExtension)))
            throw(error = -length);
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvcsCheck
    //
    //      Author: $author$
    //        Date: 8/16/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvcsCheck()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Commit
    //
    //   Author: $author$
    //     Date: 8/16/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Commit() 
    {
        EvError error = EV_ERROR_FAILED;
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
        EvError error = EV_ERROR_FAILED;
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: MakeTempFilename
    //
    //   Author: $author$
    //     Date: 8/16/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError MakeTempFilename
    (const char* evcName,
     bool forReading=false) 
    {
        EvError error = EV_ERROR_FAILED;
        EvError error2;
        const char* chars;
        const char* tempChars;
        LONG tempLength;
        LONG length;
        int type;

        DBF("() in...\n");

        if (0 < (length = SetName(evcName)))
        if ((chars = GetTempDirectory(length)) && (0 < length))
        if (0 < (length = m_tempPath.AssignChars(chars, length)))
        if ((chars = GetName(length)) && (0 < length))
        if (0 < (length = m_tempPath.AppendFileName(chars, length)))
        if ((tempChars = m_tempPath.Chars
            (tempLength)) && (0 < tempLength))
        {
            DBT("() temp file is \"%s\"\n", tempChars);

            if ((chars = m_fileSystem.GetCurrentDirectory(length)))
                DBT("() current directory is \"%s\"\n", chars);

            if (EvFileDirectoryEntry::EV_TYPE_NONE 
                < (type = m_fileSystemEntry.Exists(tempChars)))
            {
                DBT("() temp file \"%s\" already exists\n", tempChars);

                if (!forReading)
                if ((error2 = m_fileSystem.MakeVersion(tempChars)))
                    DBE("() failed to make version of \"%s\"\n", tempChars);
            }
            else if (forReading)
                    DBE("() temp file \"%s\" does not exist\n", tempChars);
            else if ((chars = m_tempPath.GetFileDirectory(length)) && (0 < length))
            {
                DBT("() temp directory is \"%s\"\n", chars);

                if ((error2 = m_fileSystem.MakeDirectory(chars)))
                    DBE("() failed to make directory \"%s\"\n", chars);
            }

            if (!error2)
                error = EV_ERROR_NONE;
        }
        DBF("() ...out\n");
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: MakeVcFilename
    //
    //   Author: $author$
    //     Date: 8/16/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError MakeVcFilename
    (const char* evcName,
     bool forReading=false) 
    {
        EvError error = EV_ERROR_FAILED;
        EvError error2 = EV_ERROR_NONE;
        const char* chars;
        const char* vcChars;
        LONG vcLength;
        LONG length;
        int type;

        DBF("() in...\n");

        if ((chars = GetVcDirectory(length)) && (0 < length))
        if (0 < (length = m_vcPath.AssignChars(chars, length)))
        if (0 < (length = m_vcPath.AppendFileName(evcName)))
        if ((vcChars = m_vcPath.Chars
            (vcLength)) && (0 < vcLength))
        {
            DBT("() vc file is \"%s\"\n", vcChars);

            if ((chars = m_fileSystem.GetCurrentDirectory(length)))
                DBT("() current directory is \"%s\"\n", chars);

            if (EvFileDirectoryEntry::EV_TYPE_NONE 
                < (type = m_fileSystemEntry.Exists(vcChars)))
            {
                DBT("() vc file \"%s\" already exists\n", vcChars);

                if (!forReading)
                if ((error2 = m_fileSystem.MakeVersion(vcChars)))
                    DBE("() failed to make version of \"%s\"\n", vcChars);
            }
            else if (forReading)
                    DBE("() vc file \"%s\" does not exist\n", vcChars);
            else if ((chars = m_vcPath.GetFileDirectory(length)) && (0 < length))
            {
                DBT("() vc directory is \"%s\"\n", chars);

                if ((error2 = m_fileSystem.MakeDirectory(chars)))
                    DBE("() failed to make directory \"%s\"\n", chars);
            }

            if (!error2)
                error = EV_ERROR_NONE;
        }
        DBF("() ...out\n");
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetName
    //
    //   Author: $author$
    //     Date: 8/16/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG SetName
    (const char* chars, LONG length=-1) 
    {
        LONG count = m_name.Assign(chars,length);
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetName
    //
    //   Author: $author$
    //     Date: 8/16/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetName
    (LONG& length) const 
    {
        const char* chars = m_name.Chars(length);
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetVcExtension
    //
    //   Author: $author$
    //     Date: 8/16/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG SetVcExtension
    (const char* chars, LONG length=-1) 
    {
        LONG count;
        EvError error2;
        
        if (0 <= (count = m_vcExtension.Assign(chars, length)))
        if (0 < (length = m_vcExtensionMatch.Assign(EVFILEPATH_MATCH_PATTERN_WILDCARD)))
        if (0 < (length = m_vcExtensionMatch.Append(EVFILEPATH_MATCH_PATTERN_EXTENSION_SEPARATOR)))
        if (0 < (length = m_vcExtensionMatch.Append(chars, count)))
        if (0 < (length = m_vcExtensionMatch.Append(EVFILEPATH_MATCH_PATTERN_WILDCARD)))
        if ((chars = m_vcExtensionMatch.Chars(length)))
        if (!(error2 = m_fileSystemEntryFilter.SetSkipMatch(chars, length)))
            return count;

        return -EV_ERROR_FAILED;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetVcExtension
    //
    //   Author: $author$
    //     Date: 8/16/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetVcExtension
    (LONG& length) const 
    {
        const char* chars = m_vcExtension.Chars(length);
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetVcDirectory
    //
    //   Author: $author$
    //     Date: 8/16/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG SetVcDirectory
    (const char* chars,
     LONG length=-1) 
    {
        LONG count = m_vcDirectory.Assign(chars,length);
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetVcDirectory
    //
    //   Author: $author$
    //     Date: 8/16/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetVcDirectory
    (LONG& length) const 
    {
        const char* chars = m_vcDirectory.Chars(length);
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetTempDirectory
    //
    //   Author: $author$
    //     Date: 7/27/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG SetTempDirectory
    (const char* chars,
     LONG length=-1) 
    {
        LONG count = m_tempDirectory.Assign(chars,length);
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetTempDirectory
    //
    //   Author: $author$
    //     Date: 7/27/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetTempDirectory
    (LONG& length) const 
    {
        const char* chars = m_tempDirectory.Chars(length);
        return chars;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetTempFilename
    //
    //   Author: $author$
    //     Date: 8/16/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetTempFilename
    (LONG& length) const 
    {
        const char* chars = m_tempPath.Chars(length);
        return chars;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetVcFilename
    //
    //   Author: $author$
    //     Date: 8/16/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetVcFilename
    (LONG& length) const 
    {
        const char* chars = m_vcPath.Chars(length);
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetIsBinary
    //
    //   Author: $author$
    //     Date: 5/31/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int SetIsBinary(bool is=true) 
    {
        m_isBinary = is;
        return m_isBinary;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetIsBinary
    //
    //   Author: $author$
    //     Date: 5/31/2007
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetIsBinary() const 
    {
        return m_isBinary;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetIsOpen
    //
    //   Author: $author$
    //     Date: 8/22/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int SetIsOpen(bool is=true) 
    {
        m_isOpen = is;
        return m_isOpen;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetIsOpen
    //
    //   Author: $author$
    //     Date: 8/22/2007
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetIsOpen() const 
    {
        return m_isOpen;
    }
};

#endif // _CEVCSCHECK_HPP
