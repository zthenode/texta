///////////////////////////////////////////////////////////////////////
//   File: cevcscheckin.hpp
//
// Author: $author$
//   Date: 5/29/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCSCHECKIN_HPP
#define _CEVCSCHECKIN_HPP

#include "evcscheckin.hpp"
#include "cevcsop.hpp"
#include "cevinstance.hpp"
#include "cevfilesystem.hpp"
#include "cevfiledirectory.hpp"
#include "cevfilepath.hpp"
#include "cevcharfile.hpp"
#include "cevstring.hpp"
#include "evdebug.h"

#define DEFAULT_CEVCS_CHECKIN_TEMP_DIR "EVCS/CI"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcsCheckIn
//
// Author: $author$
//   Date: 5/29/2007
///////////////////////////////////////////////////////////////////////
class CEvcsCheckIn
: virtual public EvcsCheckIn,
  public CEvcsOp
{
public:
    typedef EvcsCheckIn CImplements;
    typedef CEvcsOp CExtends;
    typedef CEvcsCheckIn CDerives;

    CEvString m_name;
    const char* m_nameChars;
    LONG m_nameLength;
    bool m_isBinary;

    CEvFilePath m_tempDirectory;
    CEvFilePath m_tempPath;

    CEvCharFile m_tempFile;

    CEvFileSystem m_fileSystem;
    CEvFileSystemEntry m_fileSystemEntry;
    CEvFileDirectory m_fileDirectory;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcsCheckIn
    //
    //       Author: $author$
    //         Date: 5/29/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcsCheckIn
    (const char* evcName=0, 
     const char* tempDirectory=DEFAULT_CEVCS_CHECKIN_TEMP_DIR,
     bool isBinary=false) 
    : m_nameChars(""),
      m_nameLength(0),
      m_isBinary(false)
    {
        EvError error;
        LONG length;
        if (0 > (length = SetTempDirectory(tempDirectory)))
            throw(error = -length);
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvcsCheckIn
    //
    //      Author: $author$
    //        Date: 5/29/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvcsCheckIn()
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Open
    //
    //   Author: $author$
    //     Date: 5/29/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Open
    (const char* evcName, 
     const EvFileSystemEntryTimes& fileTimes,
     bool isBinary=false) 
    {
        EvError error = EV_ERROR_FAILED;
        EvError error2 = EV_ERROR_FAILED;
        const char* chars;
        LONG length;
        int type;
        int is;

        DBF("() ...in\n");

        if (0 < (length = m_name.Assign(evcName)))
        if ((m_nameChars = m_name.Chars(m_nameLength)) && (0 < m_nameLength))
        if (0 <= (is = SetIsBinary(isBinary)))
        if ((chars = GetTempDirectory(length)) && (0 < length))
        if (0 < (length = m_tempPath.AssignChars(chars, length)))
        if (0 < (length = m_tempPath.
            AppendFileName(m_nameChars, m_nameLength)))
        if ((m_nameChars = m_tempPath.Chars(m_nameLength)) && (0 < m_nameLength))
        {
            DBT("() temp file is \"%s\"\n", m_nameChars);

            if ((chars = m_fileDirectory.GetCurrentPath(length)))
                DBT("() current directory is \"%s\"\n", chars);

            if (EvFileDirectoryEntry::EV_TYPE_NONE 
                < (type = m_fileSystemEntry.Exists(m_nameChars)))
            {
                DBT("() temp file \"%s\" already exists\n", m_nameChars);

                if ((error2 = m_fileSystem.MakeVersion(m_nameChars)))
                    DBE("() failed to make version of \"%s\"\n", m_nameChars);
            }
            else if ((chars = m_tempPath.GetFileDirectory(length)) && (0 < length))
            {
                DBT("() temp directory is \"%s\"\n", chars);

                if ((error2 = m_fileSystem.MakeDirectory(chars)))
                    DBE("() failed to make directory \"%s\"\n", chars);
            }

            if (!error2)
            if ((error2 = m_fileSystemEntry.SetFileTimesToSet(fileTimes)))
                DBE("() failed to set file times to set\n");

            if (!error2)
            if ((error2 = m_tempFile.Open
                (m_nameChars, isBinary
                 ?CEVCSOP_FILE_MODE_WRITE_BINARY
                 :CEVCSOP_FILE_MODE_WRITE_TEXT)))
                DBE("() failed to open file \"%s\"\n", m_nameChars);
            else error = EV_ERROR_NONE;
        }
        DBF("() ...out\n");
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Close
    //
    //   Author: $author$
    //     Date: 5/29/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Close() 
    {
        EvError error;

        DBF("() in...\n");

        if ((error = m_tempFile.Close()))
            DBE("() failed to close temp file\n");
        else if ((error = m_fileSystemEntry.
                  SetExistingTimesSet(m_nameChars)))
                DBE("() failed to set file times for \"%s\"\n", m_nameChars);

        DBF("() ...out\n");
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Write
    //
    //   Author: $author$
    //     Date: 5/29/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Write
    (const char* chars, LONG length=-1) 
    {
        if (0 > (length = m_tempFile.Write(chars, length)))
            DBE("() failed to write to temp file\n");
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Continue
    //
    //   Author: $author$
    //     Date: 6/2/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Continue()
    {
        EvError error = Close();
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Commit
    //
    //   Author: $author$
    //     Date: 5/29/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Commit() 
    {
        EvError error = EV_ERROR_NONE;
        if (!(error = Close()))
        {
            DBT("() check in \"%s\"\n", m_nameChars);
        }
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Cancel
    //
    //   Author: $author$
    //     Date: 5/29/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Cancel() 
    {
        EvError error = EV_ERROR_NONE;
        DBT("() cancel check in \"%s\"\n", m_nameChars);
        if (!(error = Close()))
        {
        }
        return error;
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
    virtual bool GetIsBinary(EvError& error) const 
    {
        return m_isBinary;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: DeleteThis
    //
    //   Author: $author$
    //     Date: 5/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError DeleteThis() 
    {
        delete this;
        return EV_ERROR_NONE;
    }
};
#endif // _CEVCSCHECKIN_HPP
