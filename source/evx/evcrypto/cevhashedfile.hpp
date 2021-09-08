///////////////////////////////////////////////////////////////////////
//   File: cevhashedfile.hpp
//
// Author: $author$
//   Date: 11/5/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVHASHEDFILE_HPP
#define _CEVHASHEDFILE_HPP

#include <vector>
#include "cevcharfile.hpp"
#include "evhash.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvHashedFile
//
// Author: $author$
//   Date: 11/5/2007
///////////////////////////////////////////////////////////////////////
class CEvHashedFile
: public CEvCharFile
{
public:
    typedef CEvCharFile CExtends;
    typedef CEvHashedFile CDerives;

    EvHash& m_hash;
    ULONG m_hashedBytes;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvHashedFile
    //
    //       Author: $author$
    //         Date: 11/5/2007
    ///////////////////////////////////////////////////////////////////////
    CEvHashedFile(EvHash& hash) 
    : m_hash(hash),
      m_hashedBytes(0)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvHashedFile
    //
    //      Author: $author$
    //        Date: 11/5/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvHashedFile()
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Hash
    //
    //   Author: $author$
    //     Date: 11/5/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Hash
    (BYTE* bytes,
     ULONG size,
     const char* filename=0,
     const char* filemode=EVFILE_MODE_READ_BINARY) 
    {
        LONG length = -EV_ERROR_FAILED;
        LONG count;
        EvError error;

        if (filename)
        {
            if ((error = Open(filename, filemode)))
                return length = -error;
        }
        else if (0 > (count = m_hash.Initialize()))
                return length;

        else m_hashedBytes = 0;

        do count = Read((char*)bytes, size);
        while (0 < count);

        if (filename)
            length = Close(bytes, size);
        else if (0 <= (count = m_hash.Finalize(bytes, size)))
                length = count;

        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Open
    //
    //   Author: $author$
    //     Date: 11/7/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Open
    (const char* filename,
     const char* mode=EVFILE_MODE_READ,
     bool onlyIfClosed=false) 
    {
        EvError error = EV_ERROR_FAILED;
        LONG count;

        if (0 > (count = m_hash.Initialize()))
            return error;

        if (!(error = CExtends::Open
            (filename, mode, onlyIfClosed)))
            m_hashedBytes = 0;

        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Close
    //
    //   Author: $author$
    //     Date: 11/7/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Close
    (BYTE* bytes,
     ULONG size,
     bool onlyIfOpened=false) 
    {
        LONG length = -EV_ERROR_FAILED;
        EvError error;

        if (!(error = CExtends::Close(onlyIfOpened)))
            length = m_hash.Finalize(bytes, size);
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Read
    //
    //   Author: $author$
    //     Date: 11/7/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Read
    (char* chars, ULONG size) 
    {
        LONG length = -EV_ERROR_FAILED;
        LONG count, count2;

        if (0 < (count = CExtends::Read(chars, size)))
        if (count == (count2 = m_hash.Hash((BYTE*)chars, count)))
            m_hashedBytes += (length = count);
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Write
    //
    //   Author: $author$
    //     Date: 11/7/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Write
    (const char* chars, LONG length) 
    {
        LONG count = -EV_ERROR_FAILED;
        LONG count1, count2;

        if (0 < (count1 = m_hash.Hash((BYTE*)chars, length)))
        if (count1 == (count2 = CExtends::Write(chars, count1)))
            m_hashedBytes += (count = count1);
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetHashedBytes
    //
    //   Author: $author$
    //     Date: 11/6/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ULONG GetHashedBytes() const 
    {
        ULONG value = m_hashedBytes;
        return value;
    }
};

///////////////////////////////////////////////////////////////////////
//  Typedef: CEvHashedFiles
//
//   Author: $author$
//     Date: 11/5/2007
///////////////////////////////////////////////////////////////////////
typedef ::std::vector<CEvHashedFile*>
CEvHashedFiles;

///////////////////////////////////////////////////////////////////////
//  Typedef: CEvHashedFilesIterator
//
//   Author: $author$
//     Date: 11/5/2007
///////////////////////////////////////////////////////////////////////
typedef CEvHashedFiles::iterator
CEvHashedFilesIterator;

///////////////////////////////////////////////////////////////////////
//  Typedef: const_CEvHashedFilesIterator
//
//   Author: $author$
//     Date: 11/5/2007
///////////////////////////////////////////////////////////////////////
typedef CEvHashedFiles::const_iterator
const_CEvHashedFilesIterator;

#endif // _CEVHASHEDFILE_HPP
