///////////////////////////////////////////////////////////////////////
//   File: cevfilesystem.hpp
//
// Author: $author$
//   Date: 7/5/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVFILESYSTEM_HPP
#define _CEVFILESYSTEM_HPP

#include "evfilesystem.hpp"
#include "cevfilesystementry.hpp"
#include "cevfilepath.hpp"
#include "cevfilestring.hpp"

#define DEFAULT_EVFILE_VERSION_DIRECTORY "V"
#define DEFAULT_EVFILE_VERSION_EXTENSION "v"
#define DEFAULT_EVFILE_VERSIONS 100

#define CEVFILESYSTEM_CURRENT_DIRECTORY_SIZE 1024

///////////////////////////////////////////////////////////////////////
//  Class: CEvFileSystem
//
// Author: $author$
//   Date: 7/5/2007
///////////////////////////////////////////////////////////////////////
class CEvFileSystem
: virtual public EvFileSystem,
  public CEvBase
{
public:
    typedef EvFileSystem CImplements;
    typedef CEvBase CExtends;
    typedef CEvFileSystem CDerives;

    CEvString m_versionDirectory;
    CEvString m_versionExtension;
    ULONG m_versions;

    CEvFilePath m_filePath;
    CEvFilePath m_fileDirectoryPath;
    CEvFilePath m_fileMakeDirectoryPath;
    CEvFilePath m_fileVersionExistsPath;
    CEvFilePath m_fileVersionPath;

    CEvFileString m_fileString;

    CEvFileSystemEntry m_entry;

    char m_currentDirectory[CEVFILESYSTEM_CURRENT_DIRECTORY_SIZE];

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvFileSystem
    //
    //       Author: $author$
    //         Date: 7/5/2007
    ///////////////////////////////////////////////////////////////////////
    CEvFileSystem() 
    : m_versionDirectory(DEFAULT_EVFILE_VERSION_DIRECTORY),
      m_versionExtension(DEFAULT_EVFILE_VERSION_EXTENSION),
      m_versions(DEFAULT_EVFILE_VERSIONS)
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: MakeDirectory
    //
    //   Author: $author$
    //     Date: 7/5/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError MakeDirectory
    (const char* chars,
     bool doesNotExistOnly=false) 
    {
        EvError error = EV_ERROR_FAILED;
        EvFileSystemEntry::EvType entryType;
        const_CEvFilePathDirectoriesIterator i;
        EvFilePathDirectory* d;
        bool doesNotExist;
        bool omitSeparator;
        LONG length;
        int err;

        if (0 < (length = m_fileDirectoryPath.AssignChars(chars)))
        if (0 < (length = m_fileDirectoryPath.AppendFileName("*")))
        if ((chars = m_fileDirectoryPath.GetFileDirectory(length)) && (0 < length))
        if (EvFileSystemEntry::EV_TYPE_NONE 
            < (entryType = m_entry.Exists(chars, length)))
        {
            if ((EvFileSystemEntry::EV_TYPE_DIRECTORY 
                 == entryType) && !doesNotExistOnly)
                 error = EV_ERROR_NONE;
        }
        else
        {
            omitSeparator = false;
            m_fileMakeDirectoryPath.Clear();

            if ((chars = m_fileDirectoryPath.GetVolume(length)) && (0 < length))
            if (0 >= (length = m_fileMakeDirectoryPath.
                AppendFileDirectoryVolumeChars(chars, length)))
                return error;

            if ((omitSeparator = (m_fileDirectoryPath.GetIsRoot())))
            if (0 >= (length = m_fileMakeDirectoryPath.
                AppendFileDirectorySeparator()))
                return error;

            doesNotExist = false;
            error = EV_ERROR_NONE;

            for (d = m_fileDirectoryPath.GetFirstDirectory(i);
                 d; d = m_fileDirectoryPath.GetNextDirectory(i), 
                    omitSeparator = false)
            {
                if ((chars = d->Chars(length)) && (0 < length))
                if (0 < (length = m_fileMakeDirectoryPath.
                    AppendFileDirectoryChars(chars, length, omitSeparator)))
                if ((chars = m_fileMakeDirectoryPath.
                    GetFileDirectory(length)) && (0 < length))
                {
                    if (!doesNotExist)
                    if (EvFileSystemEntry::EV_TYPE_NONE
                        >= (entryType = m_entry.Exists(chars, length)))
                        doesNotExist = true;

                    if (doesNotExist)
                    if ((err = mkdir(chars, S_IRWX)))
                    {
                        DBE("() failed to mkdir \"%s\"\n", chars);
                        error = EV_ERROR_FAILED;
                        break;
                    }
                    continue;
                }
                break;
            }
        }

        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: MakeVersion
    //
    //   Author: $author$
    //     Date: 7/12/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError MakeVersion
    (const char* chars, 
     const char* versionDirectory=0, 
     const char* versionExtension=0, 
     ULONG versions=0) 
    {
        EvError error = EV_ERROR_FAILED;
        EvFileSystemEntry::EvType entryType;
        const char* existsChars;
        const char* versionChars;
        LONG versionLength;
        ULONG version;
        LONG length;

        if ((EvFileSystemEntry::EV_TYPE_NONE 
            >= (entryType = m_entry.Exists(chars)))
            || (EvFileSystemEntry::EV_TYPE_DIRECTORY 
                == entryType))
            return error;

        if (!versionDirectory)
        if ((versionChars = m_versionDirectory.Chars(length)) && (0 < length))
           versionDirectory  = versionChars;

        if (!versionExtension)
        if (!(versionExtension = m_versionExtension.Chars(length)) || (0 >= length))
            return error;

        if (0 < (length = m_filePath.Assign(chars)))
        if ((existsChars = (chars = m_filePath.Chars(length))) && (0 < length))
        {
            if (versionDirectory)
            if ((versionChars = m_filePath.
                GetFileDirectory(length)) && (0 < length))
            if (0 < (length = m_fileVersionExistsPath.
                AssignChars(versionChars, length)))
            if (0 < (length = m_fileVersionExistsPath.
                AppendDirectory(versionDirectory)))
            if ((versionChars = m_filePath.
                GetFileName(length)) && (0 < length))
            if (0 < (length = m_fileVersionExistsPath.
                AppendFileName(versionChars)))
            if ((versionDirectory = m_fileVersionExistsPath.
                GetFileDirectory(length)) && (0 < length))
            if ((versionChars = m_fileVersionExistsPath
                .Chars(length)) && (0 < length))
                existsChars = versionChars;

            if (existsChars == chars)
                versionDirectory = 0;

            if (1 > versions)
                versions = m_versions;

            version = 1;

            if (0 < (versionLength = m_fileVersionPath.AssignChars(existsChars)))
            if (0 < (versionLength = m_fileVersionPath.AppendExtensionChars(versionExtension)))
            if ((versionChars = m_fileVersionPath.HasChars(versionLength)))
                version = (ULONG)(m_fileString.ReadFileUnsigned(versionChars, (LONG)(version)));

            for (entryType=EvFileSystemEntry::EV_TYPE_FILE; 
                 (versions > version) && (EvFileSystemEntry::EV_TYPE_NONE < entryType); 
                 version++)
            {
                if (0 < (versionLength = m_fileVersionPath.AssignChars(existsChars)))
                if (0 < (versionLength = m_fileVersionPath.AppendExtensionChars(versionExtension)))
                if (0 < (versionLength = m_fileVersionPath.AppendUnsignedChars(version)))
                if ((versionChars = m_fileVersionPath.Chars(versionLength)) && (0 < versionLength))
                if (EvFileSystemEntry::EV_TYPE_NONE 
                    < (entryType = m_entry.Exists(versionChars, versionLength)))
                    continue;
                else 
                {
                    if (versionDirectory)
                    if ((error = MakeDirectory(versionDirectory)))
                        break;

                    if (!(error = RenameFile(chars, versionChars)))
                    if (0 < (versionLength = m_fileVersionPath.AssignChars(existsChars)))
                    if (0 < (versionLength = m_fileVersionPath.AppendExtensionChars(versionExtension)))
                    if ((versionChars = m_fileVersionPath.HasChars(versionLength)))
                        m_fileString.WriteFileUnsigned(versionChars, version);
                }
                break;
            }
        }

        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: RenameFile
    //
    //   Author: $author$
    //     Date: 7/12/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError RenameFile
    (const char* oldPath,
     const char* newPath) 
    {
        EvError error = EV_ERROR_FAILED;
        int err;
        if (!(err = rename(oldPath, newPath)))
            error = EV_ERROR_NONE;
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: GetCurrentDirectory
    //
    //   Author: $author$
    //     Date: 8/16/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* 
    GetCurrentDirectory(LONG& length) 
    {
        const char* chars;

        length = -EV_ERROR_FAILED;
        m_currentDirectory[sizeof(m_currentDirectory)-1] = 0;

        if ((chars = getcwd(m_currentDirectory, sizeof(m_currentDirectory)-1)))
            length = (LONG)strlen(m_currentDirectory);
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: EntryExists
    //
    //   Author: $author$
    //     Date: 9/14/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int EntryExists
    (const char* chars, LONG length=-1) 
    {
        int entryType = m_entry.Exists(chars, length);
        return entryType;
    }
};
#endif // _CEVFILESYSTEM_HPP
