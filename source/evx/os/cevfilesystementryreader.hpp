///////////////////////////////////////////////////////////////////////
//   File: cevfilesystementryreader.hpp
//
// Author: $author$
//   Date: 6/24/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVFILESYSTEMENTRYREADER_HPP
#define _CEVFILESYSTEMENTRYREADER_HPP

#include <vector>

#include "evfilesystementryreader.hpp"
#include "cevfiledirectory.hpp"
#include "cevfilesystementry.hpp"
#include "cevfilepath.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvFileSystemEntryReader
//
// Author: $author$
//   Date: 6/24/2007
///////////////////////////////////////////////////////////////////////
class CEvFileSystemEntryReader
: virtual public EvFileSystemEntryReader,
  public CEvBase
{
public:
    typedef EvFileSystemEntryReader CImplements;
    typedef CEvBase CExtends;
    typedef CEvFileSystemEntryReader CDerives;

    typedef ::std::vector
    <CEvFileDirectory*> CEvFileDirectories;

    typedef CEvFileDirectories::iterator 
    CEvFileDirectoriesIterator;

    EvFileSystemEntryReaderEvents* m_events;
    bool m_isRecursive;
    bool m_isReflective;

    CEvFilePath m_path;
    CEvFilePath m_reflectedPath;
    CEvFilePath m_entryPath;
    CEvFilePath m_reflectedEntryPath;
    CEvFileSystemEntry m_entry;

    CEvFileDirectories m_dirs;
    CEvFileDirectory* m_dir;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvFileSystemEntryReader
    //
    //       Author: $author$
    //         Date: 6/24/2007
    ///////////////////////////////////////////////////////////////////////
    CEvFileSystemEntryReader
    (EvFileSystemEntryReaderEvents* events=0,
     const char* chars=0,
     const char* chars2=0,
     bool isRecursive=false,
     bool isReflective=false) 
    : m_events(events),
      m_isRecursive(isRecursive),
      m_isReflective(isReflective),
      m_dir(0)
    {
        EvError error;
        int type;

        if (chars)
        if (0 > (type = Read
            (chars, chars2, isRecursive, isReflective)))
            throw(error = -type);
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvFileSystemEntryReader
    //
    //      Author: $author$
    //        Date: 6/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvFileSystemEntryReader()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: ReadFirst
    //
    //   Author: $author$
    //     Date: 9/17/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int ReadFirst
    (EvFilePath& filePath,
     EvFileSystemEntryTimes& fileTimes,
     const char* chars,
     const char* chars2=0,
     bool isRecursive=false,
     bool isReflective=false) 
    {
        int pathEntryType = EvFileSystemEntry::EV_TYPE_NONE;
        int entryType = ReadFirst
        (filePath, fileTimes, pathEntryType,
         chars, chars2, isRecursive, isReflective);
        return entryType;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ReadFirst
    //
    //   Author: $author$
    //     Date: 9/17/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int ReadFirst
    (EvFilePath& filePath,
     EvFileSystemEntryTimes& fileTimes,
     int& pathEntryType,
     const char* chars,
     const char* chars2=0,
     bool isRecursive=false,
     bool isReflective=false) 
    {
        int entryType = EvFileSystemEntry::EV_TYPE_NONE;
        LONG length;

        if (chars2)
        {
            if (0 > (length = m_reflectedPath.Assign(chars2)))
                return -EV_ERROR_FAILED;
        }
        else if (0 > (length = m_reflectedPath.Clear()))
                return -EV_ERROR_FAILED;

        if ((chars2 = m_reflectedPath.HasChars(length)))
        {
            if (0 > (length = m_reflectedEntryPath.Assign(chars2, length)))
                return -EV_ERROR_FAILED;
        }
        else if (0 > (length = m_reflectedEntryPath.Clear()))
                return -EV_ERROR_FAILED;

        if (0 < (length = m_path.Assign(chars)))
        if ((chars = m_path.HasChars(length)))
        if (0 < (pathEntryType = m_entry.Exists(chars, length)))
        {
            m_isReflective = isReflective;
            m_isRecursive = isRecursive;

            switch(pathEntryType)
            {
            case (EvFileSystemEntry::EV_TYPE_FILE
                  | EvFileSystemEntry::EV_TYPE_SYMBOLIC_LINK):
                entryType = ReadFileEntrySymbolicLink
                (filePath, fileTimes, m_entry);
                break;

            case EvFileSystemEntry::EV_TYPE_FILE:
                entryType = ReadFileEntry
                (filePath, fileTimes, m_entry);
                break;

            case (EvFileSystemEntry::EV_TYPE_DIRECTORY
                  | EvFileSystemEntry::EV_TYPE_SYMBOLIC_LINK):

            case EvFileSystemEntry::EV_TYPE_DIRECTORY:
                entryType = ReadFirstDirectoryEntry
                (filePath, fileTimes, chars, length);
                break;
            }
        }
        return entryType;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ReadNext
    //
    //   Author: $author$
    //     Date: 9/17/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int ReadNext
    (EvFilePath& filePath,
     EvFileSystemEntryTimes& fileTimes) 
    {
        int entryType = EvFileSystemEntry::EV_TYPE_NONE;
        CEvFileDirectoriesIterator i;
        CEvFileDirectory* dir;
        EvFileDirectoryEntry* entry;
        EvError error2;
        const char* chars;
        LONG length;
        int type;

        if ((dir = m_dir))
        if ((chars = dir->GetPath(length)))
        do
        {
            while ((entry = dir->GetNextEntry(error2)))
            {
                if (EvFileSystemEntry::EV_TYPE_DIRECTORY
                    == (type = entry->GetType()))
                {
                    if (0 < (type = ReadFirstDirectoryEntry
                        (filePath, fileTimes, 
                         *entry, chars, length)))
                        return type;
                }
                else if ((EvFileSystemEntry::EV_TYPE_DIRECTORY
                          | EvFileSystemEntry::EV_TYPE_SYMBOLIC_LINK) == type)
                {
                    if (0 < (type = ReadFirstDirectoryEntry
                        (filePath, fileTimes,
                         *entry, chars, length)))
                        return type;
                }
                else if (EvFileSystemEntry::EV_TYPE_FILE == type)
                {
                    if (0 < (type = ReadFileEntry
                        (filePath, fileTimes, *entry)))
                        return type;
                    break;
                }
                else if ((EvFileSystemEntry::EV_TYPE_FILE
                          | EvFileSystemEntry::EV_TYPE_SYMBOLIC_LINK) == type)
                {
                    if (0 < (type = ReadFileEntrySymbolicLink
                        (filePath, fileTimes, *entry)))
                        return type;
                    break;
                }
            }

            if ((dir = CloseDirectory()))
            if (!(chars = dir->GetPath(length)))
                break;
        }
        while (dir);

        return entryType;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: ReadFirstDirectoryEntry
    //
    //   Author: $author$
    //     Date: 9/16/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int ReadFirstDirectoryEntry
    (EvFilePath& filePath,
     EvFileSystemEntryTimes& fileTimes,
     const char* chars, LONG length) 
    {
        int entryType = -EV_ERROR_FAILED;
        int type;
        EvError error2;
        CEvFileDirectory* dir;
        EvFileDirectoryEntry* entry;

        if ((dir = OpenDirectory(chars, length)))
        {
            if ((entry = dir->GetFirstEntry(error2)))
            do
            {
                if (EvFileSystemEntry::EV_TYPE_DIRECTORY
                    == (type = entry->GetType()))
                {
                    if (0 < (type = ReadFirstDirectoryEntry
                        (filePath, fileTimes, 
                         *entry, chars, length)))
                        return type;
                }
                else if ((EvFileSystemEntry::EV_TYPE_DIRECTORY
                          | EvFileSystemEntry::EV_TYPE_SYMBOLIC_LINK) == type)
                {
                    if (0 < (type = ReadFirstDirectoryEntry
                        (filePath, fileTimes,
                         *entry, chars, length)))
                        return type;
                }
                else if (EvFileSystemEntry::EV_TYPE_FILE == type)
                {
                    if (0 < (type = ReadFileEntry
                        (filePath, fileTimes, *entry)))
                        return type;
                    break;
                }
                else if ((EvFileSystemEntry::EV_TYPE_FILE
                          | EvFileSystemEntry::EV_TYPE_SYMBOLIC_LINK) == type)
                {
                    if (0 < (type = ReadFileEntrySymbolicLink
                        (filePath, fileTimes, *entry)))
                        return type;
                    break;
                }
            }
            while ((entry = dir->GetNextEntry(error2)));

            CloseDirectory();
        }
        return entryType;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ReadFirstDirectoryEntry
    //
    //   Author: $author$
    //     Date: 9/16/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int ReadFirstDirectoryEntry
    (EvFilePath& filePath,
     EvFileSystemEntryTimes& fileTimes,
     EvFileDirectoryEntry& entry,
     const char* chars, LONG length) 
    {
        int entryType = -EV_ERROR_FAILED;
        bool is;

        if (!(is = entry.GetIsCircular()))
        if ((is = GetIsRecursive()))
        if (0 < (length = m_entryPath.AssignChars(chars, length)))
        if ((chars = entry.GetName(length)) && (0 < length))
        if (0 < (length = m_entryPath.AppendFileName(chars, length)))
        if ((chars = entry.GetName(length)))
        if (0 < (length = m_reflectedEntryPath.AppendFileName(chars, length)))
        if ((chars = m_entryPath.HasChars(length)))
            entryType = ReadFirstDirectoryEntry
            (filePath, fileTimes, chars, length);

        return entryType;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: OpenDirectory
    //
    //   Author: $author$
    //     Date: 9/25/2007
    ///////////////////////////////////////////////////////////////////////
    virtual CEvFileDirectory* OpenDirectory
    (const char* chars, LONG length=-1) 
    {
        CEvFileDirectory* dir = 0;
        EvError error2;

        if ((dir = new CEvFileDirectory))
        {
            if (!(error2 = dir->OpenPath(chars, length)))
            {
                if ((chars = m_reflectedEntryPath.Chars(length)))
                if (0 <= (length = dir->SetReflectedPath(chars, length)))
                {
                    m_dirs.push_back(m_dir);
                    return m_dir = dir;
                }
                dir->Close();
            }
            delete dir;
            dir = 0;
        }
        return dir;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: CloseDirectory
    //
    //   Author: $author$
    //     Date: 9/25/2007
    ///////////////////////////////////////////////////////////////////////
    virtual CEvFileDirectory* CloseDirectory() 
    {
        CEvFileDirectory* dir = 0;
        CEvFileDirectoriesIterator i;
        const char* chars;
        LONG length;

        if ((chars = m_reflectedPath.HasChars(length)))
            m_reflectedEntryPath.AssignChars(chars, length);
        else m_reflectedEntryPath.Clear();

        if (m_dir)
        {
            m_dir->Close();
            delete m_dir;

            if ((i = m_dirs.end()) != m_dirs.begin())
            {
                if ((m_dir = (dir = *(--i))))
                if ((chars = dir->GetReflectedPath(length)))
                    m_reflectedEntryPath.Assign(chars, length);

                m_dirs.pop_back();
            }
            else m_dir = 0;
        }
        return dir;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: ReadFileEntrySymbolicLink
    //
    //   Author: $author$
    //     Date: 9/18/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int ReadFileEntrySymbolicLink
    (EvFilePath& filePath,
     EvFileSystemEntryTimes& fileTimes,
     const EvFileSystemEntry& fileEntry)
    {
        int entryType = -EV_ERROR_FAILED;
        EvError error2;
        const char* chars;
        LONG length;

        if ((chars = m_reflectedEntryPath.Chars(length)))
        if (0 <= (length = filePath.AssignChars(chars, length)))
        if ((chars = fileEntry.GetName(length)))
        if (0 < (length = filePath.AppendFileName(chars, length)))
        if ((chars = filePath.Chars(length)))
        if (!(error2 = fileEntry.CopyFileTimesTo(fileTimes)))
            entryType = (EvFileSystemEntry::EV_TYPE_FILE
                         | EvFileSystemEntry::EV_TYPE_SYMBOLIC_LINK);
        return entryType;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ReadFileEntry
    //
    //   Author: $author$
    //     Date: 9/18/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int ReadFileEntry
    (EvFilePath& filePath,
     EvFileSystemEntryTimes& fileTimes,
     const EvFileSystemEntry& fileEntry) 
    {
        int entryType = -EV_ERROR_FAILED;
        EvError error2;
        const char* chars;
        LONG length;

        if ((chars = m_reflectedEntryPath.Chars(length)))
        if (0 <= (length = filePath.AssignChars(chars, length)))
        if ((chars = fileEntry.GetName(length)))
        if (0 < (length = filePath.AppendFileName(chars, length)))
        if ((chars = filePath.Chars(length)))
        if (!(error2 = fileEntry.CopyFileTimesTo(fileTimes)))
            entryType = EvFileSystemEntry::EV_TYPE_FILE;
        return entryType;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ReadFileEntrySymbolicLink
    //
    //   Author: $author$
    //     Date: 9/18/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int ReadFileEntrySymbolicLink
    (EvFilePath& filePath,
     EvFileSystemEntryTimes& fileTimes,
     const EvFileDirectoryEntry& fileEntry) 
    {
        int entryType = -EV_ERROR_FAILED;
        EvError error2;
        const char* chars;
        LONG length;

        if ((chars = m_reflectedEntryPath.Chars(length)))
        if (0 <= (length = filePath.AssignChars(chars, length)))
        if ((chars = fileEntry.GetName(length)))
        if (0 < (length = filePath.AppendFileName(chars, length)))
        if (!(error2 = fileEntry.CopyFileTimesTo(fileTimes)))
            entryType = (EvFileSystemEntry::EV_TYPE_FILE
                         | EvFileSystemEntry::EV_TYPE_SYMBOLIC_LINK);
        return entryType;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ReadFileEntry
    //
    //   Author: $author$
    //     Date: 9/18/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int ReadFileEntry
    (EvFilePath& filePath,
     EvFileSystemEntryTimes& fileTimes,
     const EvFileDirectoryEntry& fileEntry)
    {
        int entryType = -EV_ERROR_FAILED;
        EvError error2;
        const char* chars;
        LONG length;

        if ((chars = m_reflectedEntryPath.Chars(length)))
        if (0 <= (length = filePath.AssignChars(chars, length)))
        if ((chars = fileEntry.GetName(length)))
        if (0 < (length = filePath.AppendFileName(chars, length)))
        if (!(error2 = fileEntry.CopyFileTimesTo(fileTimes)))
            entryType = EvFileSystemEntry::EV_TYPE_FILE;
        return entryType;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Read
    //
    //   Author: $author$
    //     Date: 6/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int Read
    (const char* chars,
     const char* chars2=0,
     bool isRecursive=false,
     bool isReflective=false) 
    {
        int entryType = -EV_ERROR_FAILED;
        bool oldIsRecursive = m_isRecursive;
        bool oldIsReflective = m_isReflective;
        EvError error;
        LONG length;

        if (chars2)
        {
            if (0 > (length = m_reflectedPath.Assign(chars2)))
                return -EV_ERROR_FAILED;
        }
        else if (0 > (length = m_reflectedPath.Clear()))
                return -EV_ERROR_FAILED;

        if (0 < (length = m_path.Assign(chars)))
        if ((chars = m_path.HasChars(length)))
        if (0 < (entryType = m_entry.Exists(chars, length)))
        {
            m_isReflective = isReflective;
            m_isRecursive = isRecursive;

            if ((error = OnFileSystemEntry
                (m_entry, m_path, m_reflectedPath, GetEvents())))
                entryType = -EV_ERROR_FAILED;

            m_isRecursive = oldIsRecursive;
            m_isReflective = oldIsReflective;
        }
        return entryType;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: OnFileSystemEntry
    //
    //   Author: $author$
    //     Date: 6/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnFileSystemEntry
    (const EvFileSystemEntry& entry, 
     const EvFilePath& path,
     const EvFilePath& reflectedPath,
     EvFileSystemEntryReaderEvents* deligate=0) 
    {
        EvError error = EV_ERROR_NONE;
        int type;

        if (deligate)
            error = deligate->OnFileSystemEntry
            (entry, path, reflectedPath, this);
        else
        {
            switch((type = entry.GetType()))
            {
            case EvFileSystemEntry::EV_TYPE_FILE:
                error = OnFileSystemFileEntry
                (entry, path, reflectedPath, GetEvents());
                break;

            case (EvFileSystemEntry::EV_TYPE_FILE
                  | EvFileSystemEntry::EV_TYPE_SYMBOLIC_LINK):
                error = OnFileSystemFileEntrySymbolicLink
                (entry, path, reflectedPath, GetEvents());
                break;

            case EvFileSystemEntry::EV_TYPE_DIRECTORY:
                error = OnFileSystemDirectoryEntry
                (entry, path, reflectedPath, GetEvents());
                break;

            case (EvFileSystemEntry::EV_TYPE_DIRECTORY
                  | EvFileSystemEntry::EV_TYPE_SYMBOLIC_LINK):
                error = OnFileSystemDirectoryEntrySymbolicLink
                (entry, path, reflectedPath, GetEvents());
                break;
            }
        }
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: OnFileSystemFileEntry
    //
    //   Author: $author$
    //     Date: 6/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnFileSystemFileEntry
    (const EvFileSystemEntry& entry, 
     const EvFilePath& path,
     const EvFilePath& reflectedPath,
     EvFileSystemEntryReaderEvents* deligate=0) 
    {
        EvError error = EV_ERROR_NONE;

        if (deligate)
            error = deligate->OnFileSystemFileEntry
            (entry, path, reflectedPath, this);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: OnFileSystemFileEntrySymbolicLink
    //
    //   Author: $author$
    //     Date: 6/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnFileSystemFileEntrySymbolicLink
    (const EvFileSystemEntry& entry,
     const EvFilePath& path,
     const EvFilePath& reflectedPath,
     EvFileSystemEntryReaderEvents* deligate=0)
    {
        EvError error = EV_ERROR_NONE;

        if (deligate)
            error = deligate->OnFileSystemFileEntrySymbolicLink
            (entry, path, reflectedPath, this);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: OnFileSystemDirectoryEntry
    //
    //   Author: $author$
    //     Date: 6/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnFileSystemDirectoryEntry
    (const EvFileSystemEntry& entry, 
     const EvFilePath& path,
     const EvFilePath& reflectedPath,
     EvFileSystemEntryReaderEvents* deligate=0) 
    {
        EvError error = EV_ERROR_NONE;

        if (deligate)
            error = deligate->OnFileSystemDirectoryEntry
            (entry, path, reflectedPath, this);
        else error = ReadFileDirectory(path, reflectedPath);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: OnFileSystemDirectoryEntrySymbolicLink
    //
    //   Author: $author$
    //     Date: 6/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnFileSystemDirectoryEntrySymbolicLink
    (const EvFileSystemEntry& entry,
     const EvFilePath& path,
     const EvFilePath& reflectedPath,
     EvFileSystemEntryReaderEvents* deligate=0)
    {
        EvError error = EV_ERROR_NONE;

        if (deligate)
            error = deligate->OnFileSystemDirectoryEntrySymbolicLink
            (entry, path, reflectedPath, this);
        else error = ReadFileDirectory(path, reflectedPath);
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: OnFileDirectoryEntry
    //
    //   Author: $author$
    //     Date: 6/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnFileDirectoryEntry
    (const EvFileDirectoryEntry& entry, 
     const EvFilePath& path,
     const EvFilePath& reflectedPath,
     EvFileSystemEntryReaderEvents* deligate=0) 
    {
        EvError error = EV_ERROR_NONE;
        const char* chars;
        LONG length;
        int type;

        if (deligate)
            error = deligate->OnFileDirectoryEntry
            (entry, path, reflectedPath, this);
        else
        {
            if ((chars = entry.GetName(length)) && (0 < length))
            if (0 < (type = entry.GetType()))
            switch(type)
            {
            case (EvFileDirectoryEntry::EV_TYPE_FILE
                  | EvFileDirectoryEntry::EV_TYPE_SYMBOLIC_LINK):
                error = OnFileDirectoryFileEntrySymbolicLink
                (entry, path, reflectedPath, GetEvents());
                break;

            case EvFileDirectoryEntry::EV_TYPE_FILE:
                error = OnFileDirectoryFileEntry
                (entry, path, reflectedPath, GetEvents());
                break;

            case (EvFileDirectoryEntry::EV_TYPE_DIRECTORY
                  | EvFileDirectoryEntry::EV_TYPE_SYMBOLIC_LINK):
                error = OnFileDirectoryDirectoryEntrySymbolicLink
                (entry, path, reflectedPath, GetEvents());
                break;

            case EvFileDirectoryEntry::EV_TYPE_DIRECTORY:
                error = OnFileDirectoryDirectoryEntry
                (entry, path, reflectedPath, GetEvents());
                break;
            }
        }
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: OnFileDirectoryFileEntrySymbolicLink
    //
    //   Author: $author$
    //     Date: 6/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnFileDirectoryFileEntrySymbolicLink
    (const EvFileDirectoryEntry& entry,
     const EvFilePath& path,
     const EvFilePath& reflectedPath,
     EvFileSystemEntryReaderEvents* deligate=0)
    {
        EvError error = EV_ERROR_NONE;

        if (deligate)
            error = deligate->OnFileDirectoryFileEntrySymbolicLink
            (entry, path, reflectedPath, this);
        else
        {
        }
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: OnFileDirectoryFileEntry
    //
    //   Author: $author$
    //     Date: 6/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnFileDirectoryFileEntry
    (const EvFileDirectoryEntry& entry, 
     const EvFilePath& path,
     const EvFilePath& reflectedPath,
     EvFileSystemEntryReaderEvents* deligate=0) 
    {
        EvError error = EV_ERROR_NONE;

        if (deligate)
            error = deligate->OnFileDirectoryFileEntry
            (entry, path, reflectedPath, this);
        else
        {
        }
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: OnFileDirectoryDirectoryEntry
    //
    //   Author: $author$
    //     Date: 6/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnFileDirectoryDirectoryEntry
    (const EvFileDirectoryEntry& entry, 
     const EvFilePath& path,
     const EvFilePath& reflectedPath,
     EvFileSystemEntryReaderEvents* deligate=0) 
    {
        EvError error = EV_ERROR_NONE;
        bool isRecursive = false;
        bool isCircular = false;

        if (deligate)
            error = deligate->OnFileDirectoryDirectoryEntry
            (entry, path, reflectedPath, this);
        else 
        {
            if ((isRecursive = GetIsRecursive()) 
                && !(isCircular = entry.GetIsCircular()))
                error = ReadFileDirectoryDirectoryEntry
                (entry, path, reflectedPath);
        }
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: OnFileDirectoryDirectoryEntrySymbolicLink
    //
    //   Author: $author$
    //     Date: 6/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnFileDirectoryDirectoryEntrySymbolicLink
    (const EvFileDirectoryEntry& entry,
     const EvFilePath& path,
     const EvFilePath& reflectedPath,
     EvFileSystemEntryReaderEvents* deligate=0)
    {
        EvError error = EV_ERROR_NONE;
        bool isRecursive = false;
        bool isCircular = false;

        if (deligate)
            error = deligate->OnFileDirectoryDirectoryEntrySymbolicLink
            (entry, path, reflectedPath, this);
        else
        {
            if ((isRecursive = GetIsRecursive())
                && !(isCircular = entry.GetIsCircular()))
                error = ReadFileDirectoryDirectoryEntry
                (entry, path, reflectedPath);
        }
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ReadFileDirectory
    //
    //   Author: $author$
    //     Date: 6/27/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ReadFileDirectory
    (const EvFilePath& path,
     const EvFilePath& reflectedPath) 
    {
        EvError error = EV_ERROR_NONE;
        EvError error2;
        const char* chars;
        LONG length;
        EvFileDirectoryEntry* dirEntry;
        CEvFileDirectory dir;

        if ((chars = path.Chars(length)) && (0 < length))
        if (!(error = dir.OpenPath(chars, length)))
        {
            if ((dirEntry = dir.GetFirstEntry(error)))
            do
            {
                if ((error = OnFileDirectoryEntry
                    (*dirEntry, path, reflectedPath, GetEvents())))
                    break;
            }
            while (!(error2 = dirEntry->GetNextEntry()));
            dir.Close();
        }
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ReadFileDirectoryDirectoryEntry
    //
    //   Author: $author$
    //     Date: 6/27/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ReadFileDirectoryDirectoryEntry
    (const EvFileDirectoryEntry& entry, 
     const EvFilePath& path,
     const EvFilePath& reflectedPath) 
    {
        EvError error = EV_ERROR_NONE;
        const char* chars;
        const char* entryChars;
        LONG length;
        LONG entryLength;
        CEvFilePath dirPath;

        if ((entryChars = entry.GetName(entryLength)) && (0 < entryLength))
        if ((chars = path.Chars(length)) && (0 < length))
        if (0 < (length = dirPath.AssignChars(chars, length)))
        if (0 < (length = dirPath.AppendDirectory(entryChars, entryLength)))
        if (GetIsReflective())
        {
            CEvFilePath dirEntryPath;

            if ((chars = reflectedPath.Chars(length)) && (0 <= length))
            if (0 <= (length = dirEntryPath.AssignChars(chars, length)))
            if (0 < (length = dirEntryPath.AppendDirectory(entryChars, entryLength)))
                error = ReadFileDirectory(dirPath, dirEntryPath);
        }
        else error = ReadFileDirectory(dirPath, reflectedPath);
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetIsReflective
    //
    //   Author: $author$
    //     Date: 6/27/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int SetIsReflective
    (bool is=true) 
    {
        m_isReflective = is;
        return m_isReflective;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetIsReflective
    //
    //   Author: $author$
    //     Date: 6/27/2007
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetIsReflective() const 
    {
        return m_isReflective;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetIsRecursive
    //
    //   Author: $author$
    //     Date: 6/27/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int SetIsRecursive
    (bool is=true) 
    {
        m_isRecursive = is;
        return m_isRecursive;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetIsRecursive
    //
    //   Author: $author$
    //     Date: 6/27/2007
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetIsRecursive() const 
    {
        return m_isRecursive;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetEvents
    //
    //   Author: $author$
    //     Date: 6/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvFileSystemEntryReaderEvents* SetEvents
    (EvFileSystemEntryReaderEvents* events) 
    {
        EvFileSystemEntryReaderEvents* oldEvents = m_events;
        m_events = events;
        return oldEvents;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetEvents
    //
    //   Author: $author$
    //     Date: 6/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvFileSystemEntryReaderEvents* GetEvents() const 
    {
        EvFileSystemEntryReaderEvents* events = m_events;
        return events;
    }
};
#endif // _CEVFILESYSTEMENTRYREADER_HPP
