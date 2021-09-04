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
 *   File: cfileextensionpathfinder.hxx
 *
 * Author: $author$
 *   Date: 10/3/2008
 **********************************************************************
 */
#ifndef _CFILEEXTENSIONPATHFINDER_HXX
#define _CFILEEXTENSIONPATHFINDER_HXX

#include "cfileextensionpathfinderinterface.hxx"
#include "cfilepathfinder.hxx"

#undef CDB_CLASS
#define CDB_CLASS "cFileExtensionPathFinderT"
/**
 **********************************************************************
 *  Class: cFileExtensionPathFinderT
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
 class TFilePaths=cFilePaths,
 class TFilePath=cFilePath,
 class TFilePathInterface=cFilePathInterface,
 class TFileSystemInterface=cFileSystemInterface,
 class TFileSystemEntryInterface=cFileSystemEntryInterface,
 class TImplements=cFileExtensionPathFinderImplement,
 class TExtends=cFilePathFinder>
 
class cFileExtensionPathFinderT
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements cImplements;
    typedef TExtends cExtends;
    typedef cFileExtensionPathFinderT cDerives;

    /**
     **********************************************************************
     * Constructor: cFileExtensionPathFinderT
     *
     *      Author: $author$
     *        Date: 10/3/2008
     **********************************************************************
     */
    cFileExtensionPathFinderT
    (TFileSystemInterface& fileSystem) 
    : cExtends(fileSystem)
    {
    }
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Typedef: cFileExtensionPathFinder
 *
 *  Author: $author$
 *    Date: 10/3/2008
 **********************************************************************
 */
typedef cFileExtensionPathFinderT<>
cFileExtensionPathFinder;

#endif /* _CFILEEXTENSIONPATHFINDER_HXX */
