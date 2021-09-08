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
#include "cevcscheck.hpp"
#include "cevcsop.hpp"
#include "cevinstance.hpp"
#include "cevfilesystem.hpp"
#include "cevfilepath.hpp"
#include "cevcharfile.hpp"
#include "cevstring.hpp"
#include "evdebug.h"

#define DEFAULT_CEVCS_CHECKIN_TEMP_DIR DEFAULT_CEVCS_DIR "/CI"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcsCheckIn
//
// Author: $author$
//   Date: 5/29/2007
///////////////////////////////////////////////////////////////////////
class CEvcsCheckIn
: virtual public EvcsCheckIn,
  public CEvcsCheck
{
public:
    typedef EvcsCheckIn CImplements;
    typedef CEvcsCheck CExtends;
    typedef CEvcsCheckIn CDerives;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcsCheckIn
    //
    //       Author: $author$
    //         Date: 5/29/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcsCheckIn
    (const char* evcName=0, 
     const char* tempDirectory=DEFAULT_CEVCS_CHECKIN_TEMP_DIR,
     const char* vcDirectory=DEFAULT_CEVCS_VC_DIR,
     const char* vcExtension=DEFAULT_CEVCS_VC_EXTENSION,
     bool isBinary=false) 
    : CExtends
      (evcName, tempDirectory, 
       vcDirectory, vcExtension, isBinary)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvcsCheckIn
    //
    //      Author: $author$
    //        Date: 5/29/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvcsCheckIn()
    {
        EvError error;

        if (GetIsOpen())
        if ((error = Close(true)))
            throw(error);
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
        const char* tempChars;
        LONG tempLength;
        int is;

        DBF("() in...\n");

        if (0 <= (is = SetIsBinary(isBinary)))
        if (!(error2 = MakeTempFilename(evcName)))
        if ((tempChars = GetTempFilename
            (tempLength)) && (0 < tempLength))
        if ((error2 = m_tempFileSystemEntry.
            SetFileTimesToSet(fileTimes)))
            DBE("() failed to set file times to set\n");

        else if ((error2 = m_tempFile.Open
                (tempChars, isBinary
                 ?CEVCSOP_FILE_MODE_WRITE_BINARY
                 :CEVCSOP_FILE_MODE_WRITE_TEXT)))
                DBE("() failed to open file \"%s\"\n", tempChars);

        else if (0 <= (is = SetIsOpen()))
                error = EV_ERROR_NONE;

        DBF("() ...out\n");
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Close
    //
    //   Author: $author$
    //     Date: 5/29/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Close
    (bool onlyClose=false) 
    {
        EvError error = EV_ERROR_FAILED;
        EvError error2;
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

        else if ((error2 = m_tempFileSystemEntry.
                  SetExistingTimesSet(tempChars)))
                DBE("() failed to set file times for \"%s\"\n", tempChars);

        else error = EV_ERROR_NONE;

        SetIsOpen(false);
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
        EvError error = EV_ERROR_FAILED;
        EvError error2;
        const char* chars;
        const char* tempChars;
        LONG tempLength;
        LONG length;

        if (!(error2 = Close()))
        if ((chars = GetName(length)) && (0 < length))
        if ((tempChars = GetTempFilename
            (tempLength)) && (0 < tempLength))
        if (!(error2 = MakeVcFilename(chars)))
        if ((chars = GetVcFilename(length)) && (0 < length))
        {
            DBT("() check in \"%s\" --> \"%s\"\n", tempChars, chars);

            if ((error2 = m_fileSystem.RenameFile(tempChars, chars)))
                DBE("() failed to rename file \"%s\" to \"%s\"\n", tempChars, chars);

            else if ((error2 = m_tempFileSystemEntry.
                      SetExistingTimesSet(chars)))
                    DBE("() failed to set file times for \"%s\"\n", chars);

            else error = EV_ERROR_NONE;
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
        const char* tempChars;
        LONG tempLength;

        if ((tempChars = GetTempFilename
            (tempLength)) && (0 < tempLength))
        {
            DBT("() cancel check in \"%s\"\n", tempChars);
            if (!(error = Close()))
            {
            }
        }
        return error;
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
