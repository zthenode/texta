///////////////////////////////////////////////////////////////////////
//   File: cevcomparedfile.hpp
//
// Author: $author$
//   Date: 5/17/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCOMPAREDFILE_HPP
#define _CEVCOMPAREDFILE_HPP

#include <vector>
#include "cevcharfile.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvComparedFile
//
// Author: $author$
//   Date: 5/17/2007
///////////////////////////////////////////////////////////////////////
class CEvComparedFile
: public CEvCharFile
{
public:
    typedef CEvCharFile CExtends;
    typedef CEvComparedFile CDerives;

    CEvCharFile m_toFile;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvComparedFile
    //
    //       Author: $author$
    //         Date: 5/17/2007
    ///////////////////////////////////////////////////////////////////////
    CEvComparedFile() 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvComparedFile
    //
    //      Author: $author$
    //        Date: 5/17/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvComparedFile()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Compare
    //
    //   Author: $author$
    //     Date: 5/17/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int Compare
    (BYTE* bytes, ULONG size,
     const char* toFilename,
     const char* filename=0) 
    {
        int unequal = 0;
        EvError error;

        if ((error = m_toFile.Open
            (toFilename, EVFILE_MODE_READ_BINARY)))
            return unequal = -error+1;

        if (filename)
        if ((error = Open(filename, EVFILE_MODE_READ_BINARY)))
        {
            m_toFile.Close();
            return unequal = -error+1;
        }

        unequal = Compare(bytes, size, m_toFile);

        if (filename)
        if ((error = Close()))
        if ((unequal >= -1) && (unequal <= 1))
            unequal = error+1;

        if ((error = m_toFile.Close()))
        if ((unequal >= -1) && (unequal <= 1))
            unequal = error+1;

        return unequal;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Compare
    //
    //   Author: $author$
    //     Date: 5/17/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int Compare
    (BYTE* bytes, ULONG size, CEvCharFile& toFile) 
    {
        int unequal = 0;
        int equal = 0;
        LONG count;
        LONG count2;
        LONG length;

        if (2 > size)
            return EV_ERROR_FAILED+1;

        size >>= 1;

        do
        {
            if (0 > (count = Read((char*)bytes, size)))
                return -count+1;

            if (0 > (count2 = toFile.Read(((char*)(bytes))+size, size)))
                return -count+1;

            if (count2 < (length = count))
            {
                length = count2;
                equal = 1;
            }
            else if (count2 > count)
                    equal = -1;

            if ((unequal = memcmp(bytes, bytes+size, length)))
                return unequal;
        }
        while ((size <= (ULONG)(count)) 
               && (size <= (ULONG)(count2)));

        return equal;
    }
};

///////////////////////////////////////////////////////////////////////
//  Typedef: CEvComparedFiles
//
//   Author: $author$
//     Date: 5/17/2007
///////////////////////////////////////////////////////////////////////
typedef ::std::vector<CEvComparedFile*>
CEvComparedFiles;

///////////////////////////////////////////////////////////////////////
//  Typedef: CEvComparedFilesIterator
//
//   Author: $author$
//     Date: 5/17/2007
///////////////////////////////////////////////////////////////////////
typedef CEvComparedFiles::iterator
CEvComparedFilesIterator;

///////////////////////////////////////////////////////////////////////
//  Typedef: const_CEvComparedFilesIterator
//
//   Author: $author$
//     Date: 5/17/2007
///////////////////////////////////////////////////////////////////////
typedef CEvComparedFiles::const_iterator
const_CEvComparedFilesIterator;

#endif // _CEVCOMPAREDFILE_HPP
