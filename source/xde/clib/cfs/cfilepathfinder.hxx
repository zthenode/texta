/**
 **********************************************************************
 * Copyright (c) 1988-2008 $organization$
 *
 * This software is provided by the author and contributors ``as is'' 
 * and any express or implied warranties, including, but not limited to, 
 * the implied warranties of merchantability and fitness for a particular 
 * purpose are disclaimed. In no event shall the author or contributors 
 * be liable for any direct, indirect, incidental, special, exemplary, 
 * or consequential damages (including, but not limited to, procurement 
 * of substitute goods or services; loss of use, data, or profits; or 
 * business interruption) however caused and on any theory of liability, 
 * whether in contract, strict liability, or tort (including negligence 
 * or otherwise) arising in any way out of the use of this software, 
 * even if advised of the possibility of such damage.
 *
 *   File: cfilepathfinder.hxx
 *
 * Author: $author$
 *   Date: 9/12/2008
 **********************************************************************
 */
#ifndef _CFILEPATHFINDER_HXX
#define _CFILEPATHFINDER_HXX

#include "cfilepathfinderinterface.hxx"
#include "cfilesystem.hxx"
#include "cfilepaths.hxx"
#include "cfilepath.hxx"

#undef CDB_CLASS
#define CDB_CLASS "cFilePathFinderT"
/**
 **********************************************************************
 *  Class: cFilePathFinderT
 *
 * Author: $author$
 *   Date: 9/12/2008
 **********************************************************************
 */
template
<class TChar=CHAR, 
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 TChar VNullChar=NULL_CHAR,
 class TFilePaths=cFilePaths,
 class TFilePath=cFilePath,
 class TFilePathInterface=cFilePathInterface,
 class TFileSystemInterface=cFileSystemInterface,
 class TFileSystemEntryInterface=cFileSystemEntryInterface,
 class TImplements=cFilePathFinderImplement,
 class TExtends=cBase>
 
class cFilePathFinderT
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements cImplements;
    typedef TExtends cExtends;
    typedef cFilePathFinderT cDerives;

    TFileSystemInterface& m_fileSystem;
    TFilePaths m_filePaths;
    TFilePath m_filePath;

    /**
     **********************************************************************
     * Constructor: cFilePathFinderT
     *
     *      Author: $author$
     *        Date: 9/12/2008
     **********************************************************************
     */
    cFilePathFinderT
    (TFileSystemInterface& fileSystem) 
    : m_fileSystem(fileSystem)
    {
    }
    /**
     **********************************************************************
     * Function: FindFilePath
     *
     *   Author: $author$
     *     Date: 9/12/2008
     **********************************************************************
     */
    virtual TFilePathInterface* FindFilePath
    (TFileSystemEntryInterface*& fileSystemEntry,
     const TChar* fileName,
     TLength fileNameLength=VUndefinedLength,
     const TChar* filePaths=0,
     TLength filePathsLength=VUndefinedLength) 
    {
        TFilePathInterface* filePath = 0;
        const TChar* chars;
        TLength length;
        eError error;

        fileSystemEntry = 0;

        if (filePaths)
        if (0 > (length = SetFilePaths(filePaths, filePathsLength)))
        {
            error = -length;
            return filePath;
        }

        for (filePath = m_filePaths.GetFirstFilePath(error); 
             filePath; filePath = m_filePaths.GetNextFilePath(error))
        {
            if (0 <= (length = filePath->MakeFileName
                (m_filePath, fileName, fileNameLength)))
            if ((chars = m_filePath.HasChars(length)))
            if ((fileSystemEntry = m_fileSystem.
                FindEntry(error, chars, length)))
            {
                filePath = &m_filePath;
                break;
            }
        }
        return filePath;
    }
    /**
     **********************************************************************
     * Function: SetFilePaths
     *
     *   Author: $author$
     *     Date: 9/13/2008
     **********************************************************************
     */
    virtual TLength SetFilePaths
    (const TChar* chars,
     TLength length=VUndefinedLength) 
    {
        TLength count = m_filePaths.Assign(chars, length);
        return count;
    }
    /**
     **********************************************************************
     * Function: GetFilePaths
     *
     *   Author: $author$
     *     Date: 9/13/2008
     **********************************************************************
     */
    virtual const TChar* GetFilePaths
    (TLength& length) const 
    {
        const TChar* chars = m_filePaths.HasChars(length);
        return chars;
    }
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Typedef: cFilePathFinder
 *
 *  Author: $author$
 *    Date: 9/12/2008
 **********************************************************************
 */
typedef cFilePathFinderT<>
cFilePathFinder;

#endif /* _CFILEPATHFINDER_HXX */
