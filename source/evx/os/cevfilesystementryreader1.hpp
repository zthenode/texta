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

    EvFileSystemEntryReaderEvents* m_events;
    bool m_isRecursive;
    bool m_isReflective;

    CEvFilePath m_path;
    CEvFilePath m_reflectedPath;
    CEvFilePath m_reflectedFilePath;
    CEvFileSystemEntry m_entry;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvFileSystemEntryReader
    //
    //       Author: $author$
    //         Date: 6/24/2007
    ///////////////////////////////////////////////////////////////////////
    CEvFileSystemEntryReader
    (const char* chars=0, LONG length=-1, 
     bool isRecursive=false,
     bool isReflective=false) 
    : m_events(0),
      m_isRecursive(isRecursive),
      m_isReflective(isReflective)
    {
        EvError error;
        int type;

        if (chars)
        if (0 > (type = Read(chars, length)))
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
    // Function: Read
    //
    //   Author: $author$
    //     Date: 6/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int Read
    (const char* chars,
     const char* chars2=0) 
    {
        bool isRecursive = GetIsRecursive();
        bool isReflective = GetIsReflective();
        int entryType = Read
        (chars, -1, chars2, -1, 
         isRecursive, isReflective);
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
     LONG length,
     const char* chars2=0,
     LONG length2=-1,
     bool isRecursive=false,
     bool isReflective=false) 
    {
        int entryType = EvFileSystemEntry::EV_TYPE_NONE;
        bool oldIsRecursive = m_isRecursive;
        bool oldIsReflective = m_isReflective;
        EvError error;

        m_isReflective = isReflective;
        m_isRecursive = isRecursive;

        if (0 < (length = m_path.Assign(chars, length)))
        if ((chars = m_path.Chars(length)) && (0 < length))
        if (0 < (entryType = m_entry.Exists(chars, length)))
        {
            if (!chars2)
            {
                const char* reflectedChars;
                LONG reflectedLength;

                chars2 = chars;
                length2 = length;

                if (EvFileSystemEntry::EV_TYPE_DIRECTORY != entryType)
                if (0 < (reflectedLength = m_reflectedFilePath.Assign(chars2, length2)))
                if ((reflectedChars = m_reflectedFilePath.
                    GetFileDirectory(reflectedLength)))
                {
                    chars2 = reflectedChars;
                    length2 = reflectedLength;
                }
            }

            if (0 <= (length2 = m_reflectedPath.Assign(chars2, length2)))
            if ((error = OnFileSystemEntry
                (m_entry, m_path, m_reflectedPath, GetEvents())))
                entryType = -EV_ERROR_FAILED;
        }

        m_isReflective = oldIsReflective;
        m_isRecursive = oldIsRecursive;
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

            case EvFileSystemEntry::EV_TYPE_DIRECTORY:
                error = OnFileSystemDirectoryEntry
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
            case EvFileDirectoryEntry::EV_TYPE_FILE:
                error = OnFileDirectoryFileEntry
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

        if (deligate)
            error = deligate->OnFileDirectoryDirectoryEntry
            (entry, path, reflectedPath, this);
        else 
        {
            if (GetIsRecursive()  && !entry.GetIsCircular())
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
