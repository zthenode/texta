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
 *   File: cfileextensionpathfinderinterface.hxx
 *
 * Author: $author$
 *   Date: 10/3/2008
 **********************************************************************
 */
#ifndef _CFILEEXTENSIONPATHFINDERINTERFACE_HXX
#define _CFILEEXTENSIONPATHFINDERINTERFACE_HXX

#include "cfilepathfinderinterface.hxx"

#undef CDB_CLASS
#define CDB_CLASS "cFileExtensionPathFinderInterfaceT"
/**
 **********************************************************************
 *  Class: cFileExtensionPathFinderInterfaceT
 *
 * Author: $author$
 *   Date: 10/3/2008
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
 
class c_INTERFACE_CLASS cFileExtensionPathFinderInterfaceT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef cFileExtensionPathFinderInterfaceT cDerives;
    /**
     **********************************************************************
     * Function: FindFilePath
     *
     *   Author: $author$
     *     Date: 10/3/2008
     **********************************************************************
     */
    virtual TFilePathInterface* FindFilePath
    (TFileSystemEntryInterface*& fileSystemEntry,
     const TChar* fileName,
     TLength fileNameLength=VUndefinedLength,
     const TChar* filePaths=0,
     TLength filePathsLength=VUndefinedLength,
     const TChar* fileExtensions=0,
     TLength fileExtensionssLength=VUndefinedLength) = 0;
    /**
     **********************************************************************
     * Function: SetFileExtensions
     *
     *   Author: $author$
     *     Date: 10/3/2008
     **********************************************************************
     */
    virtual TLength SetFileExtensions
    (const TChar* chars,
     TLength length=VUndefinedLength) = 0;
    /**
     **********************************************************************
     * Function: GetFileExtensions
     *
     *   Author: $author$
     *     Date: 10/3/2008
     **********************************************************************
     */
    virtual const TChar* GetFileExtensions
    (TLength& length) const = 0;
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Typedef: cFileExtensionPathFinderInterface
 *
 *  Author: $author$
 *    Date: 10/3/2008
 **********************************************************************
 */
typedef cFileExtensionPathFinderInterfaceT<>
cFileExtensionPathFinderInterface;

#undef CDB_CLASS
#define CDB_CLASS "cFileExtensionPathFinderImplementT"
/**
 **********************************************************************
 *  Class: cFileExtensionPathFinderImplementT
 *
 * Author: $author$
 *   Date: 10/3/2008
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
 class TImplements=cFileExtensionPathFinderInterface>
 
class cFileExtensionPathFinderImplementT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef cFileExtensionPathFinderImplementT cDerives;
    /**
     **********************************************************************
     * Function: FindFilePath
     *
     *   Author: $author$
     *     Date: 10/3/2008
     **********************************************************************
     */
    virtual TFilePathInterface* FindFilePath
    (TFileSystemEntryInterface*& fileSystemEntry,
     const TChar* fileName,
     TLength fileNameLength=VUndefinedLength,
     const TChar* filePaths=0,
     TLength filePathsLength=VUndefinedLength,
     const TChar* fileExtensions=0,
     TLength fileExtensionssLength=VUndefinedLength) 
    {
        TFilePathInterface* filePath = 0;
        return filePath;
    }
    /**
     **********************************************************************
     * Function: SetFileExtensions
     *
     *   Author: $author$
     *     Date: 10/3/2008
     **********************************************************************
     */
    virtual TLength SetFileExtensions
    (const TChar* chars,
     TLength length=VUndefinedLength) 
    {
        TLength count = 0;
        return count;
    }
    /**
     **********************************************************************
     * Function: GetFileExtensions
     *
     *   Author: $author$
     *     Date: 10/3/2008
     **********************************************************************
     */
    virtual const TChar* GetFileExtensions
    (TLength& length) const 
    {
        const TChar* chars = 0;
        return chars;
    }
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Typedef: cFileExtensionPathFinderImplement
 *
 *  Author: $author$
 *    Date: 10/3/2008
 **********************************************************************
 */
typedef cFileExtensionPathFinderImplementT<>
cFileExtensionPathFinderImplement;
 
#endif /* _CFILEEXTENSIONPATHFINDERINTERFACE_HXX */
