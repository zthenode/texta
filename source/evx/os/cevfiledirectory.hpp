///////////////////////////////////////////////////////////////////////
//   File: cevfiledirectory.hpp
//
// Author: $author$
//   Date: 5/4/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVFILEDIRECTORY_HPP
#define _CEVFILEDIRECTORY_HPP

#include "cevfiledirectoryentry.hpp"

#define CEVFILEDIRECTORY_CURRENT_PATH_SIZE 1024

#if defined(WIN32) 
// Windows
#include "cevwstring.hpp"
#else // defined(WIN32) 
// Unix
#endif // defined(WIN32)

///////////////////////////////////////////////////////////////////////
//  Class: CEvFileDirectory
//
// Author: $author$
//   Date: 5/4/2007
///////////////////////////////////////////////////////////////////////
class CEvFileDirectory
: public CEvFileSystemDirectoryEntry
{
public:
    typedef CEvFileSystemDirectoryEntry CExtends;
    typedef CEvFileDirectory CDerives;

#if defined(WIN32) 
// Windows
    TCHAR m_wildcard[3];
    const TCHAR* m_patternChars;
    CEvTString m_pattern;
    const TCHAR* m_pathtChars;
    CEvTString m_patht;
#else // defined(WIN32) 
// Unix
#endif // defined(WIN32)

    const char* m_pathChars;
    CEvString m_path;
    CEvString m_reflectedPath;

    bool m_opened;

    CEvFileDirectoryEntry m_entry;

    char m_currentPath[CEVFILEDIRECTORY_CURRENT_PATH_SIZE];

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvFileDirectory
    //
    //       Author: $author$
    //         Date: 5/4/2007
    ///////////////////////////////////////////////////////////////////////
    CEvFileDirectory() 
    : m_opened(false)
    {
#if defined(WIN32) 
// Windows
        m_wildcard[0] = DIRECTORY_SEPARATOR_CHAR;
        m_wildcard[1] = DIRECTORY_WILDCARD_CHAR;
        m_wildcard[2] = 0;
#else // defined(WIN32) 
// Unix
#endif // defined(WIN32)
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvFileDirectory
    //
    //      Author: $author$
    //        Date: 5/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvFileDirectory()
    {
        EvError error;
        if (m_opened)
        if ((error = Close()))
            throw(error);
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: OpenPath
    //
    //   Author: $author$
    //     Date: 5/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OpenPath
    (const char* chars, LONG length=-1) 
    {
        EvError error = EV_ERROR_FAILED;
        if (0 < (length = SetPath(chars, length)))
            error = Open();
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Open
    //
    //   Author: $author$
    //     Date: 5/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Open() 
    {
        EvError error = EV_ERROR_FAILED;
        DIRECTORY handle;

#if defined(WIN32) 
// Windows
        LONG length;

		if (INVALID_HANDLE_VALUE == (handle = FindFirstFile
            (m_pathtChars, &m_win32FindData)))
            return error;

        if ((error = GetEntry(handle, m_win32FindData)))
            return error;

        FindClose(handle);
        Detach(handle);

        if (0 < (length = m_pattern.Assign(m_pathtChars)))
        if (0 < (length = m_pattern.Append(m_wildcard)))
        if ((m_patternChars = m_pattern.Chars(length))
            && (0 < length))
		if (INVALID_HANDLE_VALUE != (handle = FindFirstFile
            (m_patternChars, &m_win32FindData)))
        if ((error = Attach(handle)))
            FindClose(handle);
#else // defined(WIN32) 
// Unix
		if (INVALID_DIRECTORY != 
            (handle = opendir(m_pathChars)))
        if ((error = Attach(handle)))
            closedir(handle);
#endif // defined(WIN32)
        else m_opened = true;

        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Close
    //
    //   Author: $author$
    //     Date: 5/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Close(bool openedOnly=false) 
    {
        EvError error = EV_ERROR_FAILED;

        if (!m_opened)
        {
            if (openedOnly)
                return EV_ERROR_NOT_OPEN;

            m_opened = false;
            m_attached = INVALID_DIRECTORY;
            return EV_ERROR_NONE;
        }

        if (INVALID_DIRECTORY == m_attached)
            return EV_ERROR_NOT_ATTACHED;

#if defined(WIN32) 
// Windows
        if ((FindClose(m_attached)))
#else // defined(WIN32) 
// Unix
        int err;
        if (!(err = closedir(m_attached)))
#endif // defined(WIN32)
            error = EV_ERROR_NONE;

        m_opened = false;
        m_attached = INVALID_DIRECTORY;
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetCurrentPath
    //
    //   Author: $author$
    //     Date: 6/2/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG SetCurrentPath
    (const char* chars,
     LONG length=-1) 
    {
        length = -EV_ERROR_FAILED;
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetCurrentPath
    //
    //   Author: $author$
    //     Date: 6/2/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetCurrentPath
    (LONG& length) 
    {
        const char* chars;

        length = -EV_ERROR_FAILED;
        m_currentPath[sizeof(m_currentPath)-1] = 0;

        if ((chars = getcwd(m_currentPath, sizeof(m_currentPath)-1)))
            length = (LONG)strlen(m_currentPath);
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: GetFirstEntry
    //
    //   Author: $author$
    //     Date: 5/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvFileDirectoryEntry* 
    GetFirstEntry(EvError& error) 
    {
        EvFileDirectoryEntry* entry = 0;

        if (INVALID_DIRECTORY == m_attached)
        {
            error = EV_ERROR_NOT_ATTACHED;
            return entry;
        }

#if defined(WIN32) 
// Windows
        if (!(error = m_entry.GetEntry
            (m_attached, m_win32FindData)))
            entry = &m_entry;
#else // defined(WIN32) 
// Unix
        if ((m_dirent = readdir(m_attached))) {
        bool isSymbolicLink = false;
        if (DT_LNK == (m_dirent->d_type))
            isSymbolicLink = true;
        if (!(error = m_entry.GetEntry
            (m_attached, *m_dirent, m_pathChars)))
            entry = &m_entry;
        }
#endif // defined(WIN32)
        return entry;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetNextEntry
    //
    //   Author: $author$
    //     Date: 9/17/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvFileDirectoryEntry* 
    GetNextEntry(EvError& error) 
    {
        EvFileDirectoryEntry* entry = 0;
        EvError error2;

        if (INVALID_DIRECTORY == m_attached)
            error = EV_ERROR_NOT_ATTACHED;
        else if (!(error2 = m_entry.GetNextEntry()))
                entry = &m_entry;
        else error = EV_ERROR_FAILED;
        return entry;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetPath
    //
    //   Author: $author$
    //     Date: 5/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG SetPath
    (const char* chars, LONG length=-1) 
    {
        if (0 <= (length = m_path.Assign(chars, length)))
        if ((m_pathChars = m_path.Chars(length)))
#if defined(WIN32) 
// Windows
        if (0 <= (length = m_patht.Assignc(m_pathChars, length)))
        if ((m_pathtChars = m_patht.Chars(length)))
#else // defined(WIN32) 
// Unix
#endif // defined(WIN32)
            return length;

        return -EV_ERROR_FAILED;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetPath
    //
    //   Author: $author$
    //     Date: 5/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetPath
    (LONG& length) const 
    {
        const char* chars = m_path.Chars(length);
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetReflectedPath
    //
    //   Author: $author$
    //     Date: 9/25/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG SetReflectedPath
    (const char* chars, LONG length=-1) 
    {
        LONG count = m_reflectedPath.Assign(chars,length);
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetReflectedPath
    //
    //   Author: $author$
    //     Date: 9/25/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetReflectedPath
    (LONG& length) const 
    {
        return m_reflectedPath.Chars(length);
    }
};
#endif // _CEVFILEDIRECTORY_HPP
