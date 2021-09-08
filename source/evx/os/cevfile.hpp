///////////////////////////////////////////////////////////////////////
//   File: cevfile.hpp
//
// Author: $author$
//   Date: 5/17/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVFILE_HPP
#define _CEVFILE_HPP

#include "evfile.hpp"
#include "evreader.hpp"
#include "evwriter.hpp"
#include "cevattached.hpp"
#include "cevbase.hpp"
#include "cevfilesystementry.hpp"

///////////////////////////////////////////////////////////////////////
// Typedef: EvFileAttached
//
//  Author: $author$
//    Date: 5/17/2007
///////////////////////////////////////////////////////////////////////
typedef EvAttached
<FILE*, EvBase> 
EvFileAttached;

///////////////////////////////////////////////////////////////////////
// Typedef: CEvFileAttached
//
//  Author: $author$
//    Date: 5/17/2007
///////////////////////////////////////////////////////////////////////
typedef CEvAttached
<FILE*, INVALID_FILE_T, INVALID_FILE,
 EvFileAttached, CEvBase> 
CEvFileAttached;

///////////////////////////////////////////////////////////////////////
//  Class: CEvFile
//
// Author: $author$
//   Date: 5/17/2007
///////////////////////////////////////////////////////////////////////
template
<class TChar=CHAR,
 class TSize=ULONG,
 class TLength=LONG,
 class TReader=EvReader<TChar, TSize, TLength>,
 class TWriter=EvWriter<TChar, TSize, TLength>,
 class TImplements=EvFileAttached,
 class TExtends=CEvFileAttached>

class CEvFile
: virtual public TReader,
  virtual public TWriter,
  virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements CImplements;
    typedef TExtends CExtends;
    typedef CEvFile CDerives;

    bool m_isOpen;
    mutable CEvFileSystemEntry m_entry;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvFile
    //
    //       Author: $author$
    //         Date: 5/17/2007
    ///////////////////////////////////////////////////////////////////////
    CEvFile
    (const char* filename=0,
     const char* mode=EVFILE_MODE_READ) 
    : m_isOpen(false)
    {
        EvError error;
        if (filename)
        if ((error = Open(filename, mode)))
            throw(error);
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvFile
    //
    //      Author: $author$
    //        Date: 5/17/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvFile()
    {
        EvError error;
        if (m_isOpen)
        if ((error = Close()))
            throw(error);
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Exists
    //
    //   Author: $author$
    //     Date: 6/2/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int Exists
    (const char* chars, LONG length=-1) const
    {
        int type = m_entry.Exists(chars, length);
        return type;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Open
    //
    //   Author: $author$
    //     Date: 5/17/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Open
    (const char* filename,
     const char* mode=EVFILE_MODE_READ,
     bool onlyIfClosed=false) 
    {
        EvError error = EV_ERROR_NONE;
#if defined(WIN32_MSC_VER_8) 
// Visual C++ 8x
        errno_t err;
#endif // defined(WIN32_MSC_VER_8)

        if (INVALID_FILE != (*this).m_attached)
        if (m_isOpen)
        if (onlyIfClosed)
            return EV_ERROR_ALREADY_OPEN;
        else if ((error = Close()))
                return error;

#if defined(WIN32_MSC_VER_8) 
// Visual C++ 8x
        if (!(err = fopen_s(&(*this).m_attached, filename, mode)))
#else // defined(WIN32_MSC_VER_8) 
// Otherwise
        if (((*this).m_attached = fopen(filename, mode)))
#endif // defined(WIN32_MSC_VER_8)
            m_isOpen = true;
        else error = EV_ERROR_OPEN;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Close
    //
    //   Author: $author$
    //     Date: 5/17/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Close
    (bool onlyIfOpened=false) 
    {
        EvError error = EV_ERROR_NONE;
        int err;

        if (INVALID_FILE == (*this).m_attached)
        if (onlyIfOpened || m_isOpen)
            return EV_ERROR_NOT_ATTACHED;

        if (m_isOpen)
        {
            if ((err = fclose((*this).m_attached)))
                return EV_ERROR_CLOSE;
        }
        else if (onlyIfOpened)
                return EV_ERROR_NOT_OPEN;

        m_isOpen = false;
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Read
    //
    //   Author: $author$
    //     Date: 5/17/2007
    ///////////////////////////////////////////////////////////////////////
    virtual TLength Read
    (TChar* chars, TSize size) 
    {
        TLength length = -EV_ERROR_FAILED;

        if (INVALID_FILE == (*this).m_attached)
            return -EV_ERROR_NOT_ATTACHED;

        if (1 > size)
            return -EV_ERROR_INVALID_PARAMETER;

        length = (TLength)(fread
        (chars, 1, (size_t)(size), (*this).m_attached));
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Write
    //
    //   Author: $author$
    //     Date: 5/17/2007
    ///////////////////////////////////////////////////////////////////////
    virtual TLength Write
    (const TChar* chars, TLength length=-1) 
    {
        if (INVALID_FILE == (*this).m_attached)
            return -EV_ERROR_NOT_ATTACHED;

        if (0 > length)
        if (0 > (length = LengthOf(chars)))
            return length;

        length = (TLength)(fwrite
        (chars, 1, (size_t)(length), (*this).m_attached));
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: LengthOf
    //
    //   Author: $author$
    //     Date: 9/3/2007
    ///////////////////////////////////////////////////////////////////////
    virtual TLength LengthOf
    (const TChar* chars) const
    {
        TLength length = -EV_ERROR_INVALID_PARAMETER;
        TChar c;
        if (chars)
        for (length = 0; (c = *chars); chars++)
            length++;
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Flush
    //
    //   Author: $author$
    //     Date: 8/23/2007
    ///////////////////////////////////////////////////////////////////////
    virtual TLength Flush() 
    {
        TLength length = -EV_ERROR_FAILED;
        int err;

        if (INVALID_FILE == (*this).m_attached)
            return -EV_ERROR_NOT_ATTACHED;

        if (!(err = fflush((*this).m_attached)))
            length = 0;
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Truncate
    //
    //   Author: $author$
    //     Date: 8/23/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Truncate() 
    {
        EvError error = EV_ERROR_FAILED;
        int err;

        if (INVALID_FILE == (*this).m_attached)
            return EV_ERROR_NOT_ATTACHED;

#if defined(WIN32)
        if (!(err = _chsize(fileno((*this).m_attached), 0)))
            error = EV_ERROR_NONE;
#else // defined(WIN32)
        if (!(err = ftruncate(fileno((*this).m_attached), 0)))
            error = EV_ERROR_NONE;
#endif // defined(WIN32)

        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetBinaryMode
    //
    //   Author: $author$
    //     Date: 9/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError SetBinaryMode() 
    {
        EvError error = EV_ERROR_NONE;

        if (INVALID_FILE == (*this).m_attached)
            return EV_ERROR_NOT_ATTACHED;

#if defined(WIN32) 
// Windows
        int fileNo;
        int err;
        if (0 > (fileNo = _fileno((*this).m_attached)))
            return EV_ERROR_FAILED;
        if (0 > (err = _setmode(fileNo, _O_BINARY)))
            return EV_ERROR_FAILED;
#else // defined(WIN32) 
// Unix
#endif // defined(WIN32)
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: SetTextMode
    //
    //   Author: $author$
    //     Date: 9/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError SetTextMode() 
    {
        EvError error = EV_ERROR_NOT_ALLOWED;

        if (INVALID_FILE == (*this).m_attached)
            return EV_ERROR_NOT_ATTACHED;

#if defined(WIN32) 
// Windows
        int fileNo;
        int err;
        if (0 > (fileNo = _fileno((*this).m_attached)))
            return EV_ERROR_FAILED;
        if ((err = _setmode(fileNo, _O_TEXT)))
            return EV_ERROR_FAILED;
#else // defined(WIN32) 
// Unix
#endif // defined(WIN32)
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: GetIsBinaryMode
    //
    //   Author: $author$
    //     Date: 9/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int GetIsBinaryMode() const 
    {
        int isBinaryMode = 1;

        if (INVALID_FILE == (*this).m_attached)
            return -EV_ERROR_NOT_ATTACHED;

#if defined(WIN32) 
// Windows
        int fileMode;
        errno_t err;
        if ((err = _get_fmode(&fileMode)))
            return -EV_ERROR_FAILED;
        isBinaryMode = (_O_BINARY == fileMode);
#else // defined(WIN32) 
// Unix
#endif // defined(WIN32)
        return isBinaryMode;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetIsTextMode
    //
    //   Author: $author$
    //     Date: 9/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int GetIsTextMode() const 
    {
        int isTextMode = 0;

        if (INVALID_FILE == (*this).m_attached)
            return -EV_ERROR_NOT_ATTACHED;

#if defined(WIN32) 
// Windows
        int fileMode;
        errno_t err;
        if ((err = _get_fmode(&fileMode)))
            return -EV_ERROR_FAILED;
        isTextMode = (_O_TEXT == fileMode);
#else // defined(WIN32) 
// Unix
#endif // defined(WIN32)
        return isTextMode;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetIsOpen
    //
    //   Author: $author$
    //     Date: 5/17/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int SetIsOpen
    (bool is=true) 
    {
        m_isOpen = is;
        return m_isOpen;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetIsOpen
    //
    //   Author: $author$
    //     Date: 5/17/2007
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetIsOpen() const 
    {
        return m_isOpen;
    }
};
#endif // _CEVFILE_HPP
