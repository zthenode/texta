///////////////////////////////////////////////////////////////////////
//   File: cevwin32file.hpp
//
// Author: $author$
//   Date: 7/3/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVWIN32FILE_HPP
#define _CEVWIN32FILE_HPP

#include "cevhandleattached.hpp"

#if defined(WIN32) 
// Windows
///////////////////////////////////////////////////////////////////////
//  Class: CEvWin32File
//
// Author: $author$
//   Date: 7/3/2007
///////////////////////////////////////////////////////////////////////
class CEvWin32File
: virtual public EvHANDLEAttached,
  public CEvHANDLEAttached
{
public:
    typedef EvHANDLEAttached CImplements;
    typedef CEvHANDLEAttached CExtends;
    typedef CEvWin32File CDerives;

    bool m_isOpen;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvWin32File
    //
    //       Author: $author$
    //         Date: 7/3/2007
    ///////////////////////////////////////////////////////////////////////
    CEvWin32File
    (HANDLE attached=INVALID_HANDLE_VALUE, 
     bool isOpen=false) 
    : CExtends(attached),
      m_isOpen(isOpen)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvWin32File
    //
    //      Author: $author$
    //        Date: 7/3/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvWin32File()
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
    //     Date: 7/3/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Open
    (const TCHAR* chars, 
     DWORD mode=GENERIC_READ,
     DWORD create=OPEN_EXISTING,
     bool onlyIfClosed=false) 
    {
        EvError error = EV_ERROR_FAILED;
        DWORD dwDesiredAccess = mode;
        DWORD dwShareMode = 0;
        LPSECURITY_ATTRIBUTES lpSecurityAttributes = NULL;
        DWORD dwCreationDisposition = create;
        DWORD dwFlagsAndAttributes = 0;
        HANDLE hTemplateFile = NULL;

        if (INVALID_HANDLE_VALUE != m_attached)
        if (onlyIfClosed)
            return EV_ERROR_ALREADY_OPEN;
        else 
        {
            if (m_isOpen)
            if ((error = Close()))
                return error;
        }

        if ((m_isOpen = (INVALID_HANDLE_VALUE != 
            (m_attached = CreateFile
            (chars, 
             dwDesiredAccess,
             dwShareMode,
             lpSecurityAttributes,
             dwCreationDisposition,
             dwFlagsAndAttributes,
             hTemplateFile)))))
            error = EV_ERROR_NONE;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Close
    //
    //   Author: $author$
    //     Date: 7/3/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Close() 
    {
        EvError error = EV_ERROR_FAILED;

        if (INVALID_HANDLE_VALUE == m_attached)
            return EV_ERROR_NOT_ATTACHED;

        if (CloseHandle(m_attached))
            error = EV_ERROR_NONE;

        m_isOpen = false;
        m_attached = INVALID_HANDLE_VALUE;
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
        DWORD read;

        if (INVALID_HANDLE_VALUE == m_attached)
            return EV_ERROR_NOT_ATTACHED;

        if (ReadFile
            (m_attached, bytes, size, &read, NULL))
            count = (LONG)(read);
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Write
    //
    //   Author: $author$
    //     Date: 7/6/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Write
    (const BYTE* bytes, ULONG length) 
    {
        LONG count = -EV_ERROR_FAILED;
        DWORD written;

        if (INVALID_HANDLE_VALUE == m_attached)
            return EV_ERROR_NOT_ATTACHED;

        if (WriteFile
            (m_attached, bytes, length, &written, NULL))
            count = (LONG)(written);
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Truncate
    //
    //   Author: $author$
    //     Date: 1/19/2012
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Truncate() 
    {
        EvError error = EV_ERROR_FAILED;

        if (INVALID_HANDLE_VALUE == m_attached)
            return EV_ERROR_NOT_ATTACHED;

        if (INVALID_SET_FILE_POINTER != (SetFilePointer(m_attached, 0, 0, FILE_BEGIN)))
        if ((SetEndOfFile(m_attached)))
            error = EV_ERROR_NONE;

        return error;
    }
};
#else // defined(WIN32) 
// Otherwise
#endif // defined(WIN32)
#endif // _CEVWIN32FILE_HPP
