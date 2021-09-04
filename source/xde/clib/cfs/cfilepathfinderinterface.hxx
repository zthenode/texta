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
 *   File: cfilepathfinderinterface.hxx
 *
 * Author: $author$
 *   Date: 9/12/2008
 **********************************************************************
 */
#ifndef _CFILEPATHFINDERINTERFACE_HXX
#define _CFILEPATHFINDERINTERFACE_HXX

#include "cfilepathinterface.hxx"
#include "cfilesystementryinterface.hxx"

#undef CDB_CLASS
#define CDB_CLASS "cFilePathFinderInterfaceT"
/**
 **********************************************************************
 *  Class: cFilePathFinderInterfaceT
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
 class TFilePathInterface=cFilePathInterface,
 class TFileSystemEntryInterface=cFileSystemEntryInterface,
 class TImplements=cInterfaceBase>
 
class c_INTERFACE_CLASS cFilePathFinderInterfaceT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef cFilePathFinderInterfaceT cDerives;
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
     TLength filePathsLength=VUndefinedLength) = 0;
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
     TLength length=VUndefinedLength) = 0;
    /**
     **********************************************************************
     * Function: GetFilePaths
     *
     *   Author: $author$
     *     Date: 9/13/2008
     **********************************************************************
     */
    virtual const TChar* GetFilePaths
    (TLength& length) const = 0;
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Typedef: cFilePathFinderInterface
 *
 *  Author: $author$
 *    Date: 9/12/2008
 **********************************************************************
 */
typedef cFilePathFinderInterfaceT<>
cFilePathFinderInterface;

#undef CDB_CLASS
#define CDB_CLASS "cFilePathFinderImplementT"
/**
 **********************************************************************
 *  Class: cFilePathFinderImplementT
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
 class TFilePathInterface=cFilePathInterface,
 class TFileSystemEntryInterface=cFileSystemEntryInterface,
 class TImplements=cFilePathFinderInterface>
 
class cFilePathFinderImplementT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef cFilePathFinderImplementT cDerives;
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
        TLength count = 0;
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
        const TChar* chars = 0;
        length = 0;
        return chars;
    }
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Typedef: cFilePathFinderImplement
 *
 *  Author: $author$
 *    Date: 9/12/2008
 **********************************************************************
 */
typedef cFilePathFinderImplementT<>
cFilePathFinderImplement;

#endif /* _CFILEPATHFINDERINTERFACE_HXX */
