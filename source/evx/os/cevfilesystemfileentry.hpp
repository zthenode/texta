///////////////////////////////////////////////////////////////////////
//   File: cevfilesystemfileentry.hpp
//
// Author: $author$
//   Date: 7/6/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVFILESYSTEMFILEENTRY_HPP
#define _CEVFILESYSTEMFILEENTRY_HPP

#include "evfilesystemfileentry.hpp"
#include "cevfilesystementry.hpp"
#include "evbytereader.hpp"
#include "evbytewriter.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvFileSystemFileEntry
//
// Author: $author$
//   Date: 7/6/2007
///////////////////////////////////////////////////////////////////////
class CEvFileSystemFileEntry
: virtual public EvFileSystemFileEntry,
  public CEvFileSystemEntry
{
public:
    typedef EvFileSystemFileEntry CImplements;
    typedef CEvFileSystemEntry CExtends;
    typedef CEvFileSystemFileEntry CDerives;

    bool m_isOpen;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvFileSystemFileEntry
    //
    //       Author: $author$
    //         Date: 7/6/2007
    ///////////////////////////////////////////////////////////////////////
    CEvFileSystemFileEntry
    (const char* chars=0,
     LONG length=-1,
     EvMode mode=EV_MODE_READ) 
    : m_isOpen(false)
    {
        EvError error;
        if (chars)
        if ((error = Open(chars, length, mode)))
            throw(error);
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvFileSystemFileEntry
    //
    //      Author: $author$
    //        Date: 7/6/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvFileSystemFileEntry()
    {
        EvError error;
        if (m_isOpen)
        if ((error = Close()))
            throw(error);
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Open
    //
    //   Author: $author$
    //     Date: 7/6/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Open
    (const char* chars,
     LONG length=-1,
     EvMode mode=EV_MODE_READ) 
    {
        EvError error = EV_ERROR_FAILED;
#if defined(WIN32) 
// Windows
        DWORD dwDesiredAccess = (mode != EV_MODE_READ)?(GENERIC_WRITE):(GENERIC_READ);
        DWORD dwCreationDisposition = (mode != EV_MODE_READ)?(OPEN_ALWAYS):(OPEN_EXISTING);
        if ((m_findChars = GetFindName(chars, length)))
        if (!(error = m_win32File.Open
            (m_findChars, dwDesiredAccess, dwCreationDisposition)))
            m_isOpen = true;
#else // defined(WIN32) 
// Unix
#endif // defined(WIN32)
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Close
    //
    //   Author: $author$
    //     Date: 7/6/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Close() 
    {
        EvError error = CExtends::Close();
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Read
    //
    //   Author: $author$
    //     Date: 7/6/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Read
    (BYTE* bytes,
     ULONG size) 
    {
        LONG count = -EV_ERROR_FAILED;

        if (!m_isOpen)
            return -EV_ERROR_NOT_OPEN;

#if defined(WIN32) 
// Windows
        count = m_win32File.Read(bytes, size);
#else // defined(WIN32) 
// Unix
#endif // defined(WIN32)
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Write
    //
    //   Author: $author$
    //     Date: 7/6/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Write
    (const BYTE* bytes,
     LONG length=-1) 
    {
        LONG count = -EV_ERROR_FAILED;

        if (!m_isOpen)
            return -EV_ERROR_NOT_OPEN;

#if defined(WIN32) 
// Windows
        count = m_win32File.Write(bytes, length);
#else // defined(WIN32) 
// Unix
#endif // defined(WIN32)
        return count;
    }
};
#endif // _CEVFILESYSTEMFILEENTRY_HPP
