///////////////////////////////////////////////////////////////////////
//   File: cevcscharfile.hpp
//
// Author: $author$
//   Date: 10/2/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCSCHARFILE_HPP
#define _CEVCSCHARFILE_HPP

#include "cevcharfile.hpp"
#include "evfilesystem.hpp"
#include "cevfilepath.hpp"
#include "evcsfile.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcsCharFile
//
// Author: $author$
//   Date: 10/2/2007
///////////////////////////////////////////////////////////////////////
class CEvcsCharFile
: public CEvCharFile
{
public:
    typedef CEvCharFile CExtends;
    typedef CEvcsCharFile CDerives;

    CEvFilePath m_filePath;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcsCharFile
    //
    //       Author: $author$
    //         Date: 10/2/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcsCharFile
    (const char* filename=0,
     const char* mode=EVFILE_MODE_READ) 
    {
        EvError error;
        if (filename)
        if ((error = Open(filename, mode)))
            throw(error);
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvcsCharFile
    //
    //      Author: $author$
    //        Date: 10/2/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvcsCharFile()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Rename
    //
    //   Author: $author$
    //     Date: 10/2/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Rename
    (EvFileSystem& fileSystem,
     const char* oldFilename,
     const char* filename,
     bool makeDirectory=false,
     bool makeVersion=false,
     const char* versionDirectory=0, 
     const char* versionExtension=0, 
     ULONG versions=0) 
    {
        EvError error = EV_ERROR_FAILED;
        EvError error2;
        LONG length;
        int unequal;

        if (0 >= (length = m_filePath.AssignChars(oldFilename)))
            return EV_ERROR_FAILED;

        if (!(unequal = m_filePath.Compare(filename)))
            return EV_ERROR_FAILED;

        if (makeVersion)
        {
            if ((error2 = MakeVersion
                (fileSystem, filename, makeDirectory,
                 versionDirectory, versionExtension, versions)))
                return error2;
        }
        else if (makeDirectory)
        {
            if ((error2 = MakeDirectory
                (fileSystem, filename)))
                return error2;
        }

        if ((error2 = fileSystem.RenameFile
           (oldFilename, filename)))
           DBE
           ("() failed to rename file \"%s\" to \"%s\"\n", 
            oldFilename, filename);
        else error = EV_ERROR_NONE;

        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: OpenToWrite
    //
    //   Author: $author$
    //     Date: 10/2/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OpenToWrite
    (EvFileSystem& fileSystem,
     const char* filename,
     bool isBinary=false,
     bool makeDirectory=false,
     bool makeVersion=false,
     const char* versionDirectory=0, 
     const char* versionExtension=0, 
     ULONG versions=0) 
    {
        EvError error = EV_ERROR_FAILED;
        EvError error2;

        if (makeVersion)
        {
            if ((error2 = MakeVersion
                (fileSystem, filename, makeDirectory,
                 versionDirectory, versionExtension, versions)))
                return error2;
        }
        else if (makeDirectory)
        {
            if ((error2 = MakeDirectory
                (fileSystem, filename)))
                return error2;
        }

        if ((error2 = Open
           (filename, isBinary
            ?EVCS_FILE_MODE_WRITE_BINARY
            :EVCS_FILE_MODE_WRITE_TEXT)))
           DBE("() failed to open file \"%s\"\n", filename);
        else error = EV_ERROR_NONE;

        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: OpenToRead
    //
    //   Author: $author$
    //     Date: 10/2/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OpenToRead
    (const char* filename,
     bool isBinary=false) 
    {
        EvError error = EV_ERROR_FAILED;
        EvError error2;

        if ((error2 = Open
           (filename, isBinary
            ?EVCS_FILE_MODE_READ_BINARY
            :EVCS_FILE_MODE_READ_TEXT)))
           DBE("() failed to open file \"%s\"\n", filename);
        else error = EV_ERROR_NONE;

        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: MakeVersion
    //
    //   Author: $author$
    //     Date: 10/2/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError MakeVersion
    (EvFileSystem& fileSystem,
     const char* filename,
     bool makeDirectory=false,
     const char* versionDirectory=0, 
     const char* versionExtension=0, 
     ULONG versions=0) 
    {
        EvError error = EV_ERROR_FAILED;
        EvError error2;
        const char* chars;
        LONG length;
        int type;

        if ((chars = fileSystem.GetCurrentDirectory(length)))
            DBT("() current directory is \"%s\"\n", chars);

        if (0 < (type = fileSystem.EntryExists(filename)))
        {
            DBT("() file \"%s\" already exists\n", filename);

            if ((error2 = fileSystem.MakeVersion
                (filename, versionDirectory, versionExtension, versions)))
                DBE("() failed to make version of \"%s\"\n", filename);
            else error = EV_ERROR_NONE;
        }
        else if (makeDirectory)
                error = MakeDirectory(fileSystem, filename);
        else error = EV_ERROR_NONE;

        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: MakeDirectory
    //
    //   Author: $author$
    //     Date: 10/2/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError MakeDirectory
    (EvFileSystem& fileSystem,
     const char* filename) 
    {
        EvError error = EV_ERROR_FAILED;
        EvError error2;
        const char* chars;
        LONG length;

        if (0 < (length = m_filePath.Assign(filename)))
        if ((chars = m_filePath.HasFileDirectory(length)))
        {
            DBT("() file directory is \"%s\"\n", chars);

            if ((error2 = fileSystem.MakeDirectory(chars)))
                DBE("() failed to make directory \"%s\"\n", chars);
            else error = EV_ERROR_NONE;
        }
        else error = EV_ERROR_NONE;

        return error;
    }
};
#endif // _CEVCSCHARFILE_HPP
