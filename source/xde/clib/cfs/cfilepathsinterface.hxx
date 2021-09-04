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
 *   File: cfilepathsinterface.hxx
 *
 * Author: $author$
 *   Date: 9/9/2008
 **********************************************************************
 */
#ifndef _CFILEPATHSINTERFACE_HXX
#define _CFILEPATHSINTERFACE_HXX

#include "cfilepathinterface.hxx"

#undef CDB_CLASS
#define CDB_CLASS "cFilePathsInterfaceT"
/**
 **********************************************************************
 *  Class: cFilePathsInterfaceT
 *
 * Author: $author$
 *   Date: 9/9/2008
 **********************************************************************
 */
template
<class TChar=CHAR, 
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 TChar VNullChar=NULL_CHAR,
 class TFilePathInterface=cFilePathInterface,
 class TImplements=cStringInterface>
 
class c_INTERFACE_CLASS cFilePathsInterfaceT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef cFilePathsInterfaceT cDerives;
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Typedef: cFilePathsInterface
 *
 *  Author: $author$
 *    Date: 9/9/2008
 **********************************************************************
 */
typedef cFilePathsInterfaceT<>
cFilePathsInterface;

#undef CDB_CLASS
#define CDB_CLASS "cFilePathsImplementT"
/**
 **********************************************************************
 *  Class: cFilePathsImplementT
 *
 * Author: $author$
 *   Date: 9/9/2008
 **********************************************************************
 */
template
<class TChar=CHAR, 
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 TChar VNullChar=NULL_CHAR,
 class TFilePathInterface=cFilePathInterface,
 class TImplements=cFilePathsInterface>
 
class cFilePathsImplementT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef cFilePathsImplementT cDerives;
    /**
     **********************************************************************
     * Function: GetFirstFilePath
     *
     *   Author: $author$
     *     Date: 9/9/2008
     **********************************************************************
     */
    virtual TFilePathInterface* GetFirstFilePath
    (eError& error) 
    {
        TFilePathInterface* filePath = 0;
        error = e_ERROR_NOT_IMPLEMENTED;
        return filePath;
    }
    /**
     **********************************************************************
     * Function: GetLastFilePath
     *
     *   Author: $author$
     *     Date: 9/9/2008
     **********************************************************************
     */
    virtual TFilePathInterface* GetLastFilePath
    (eError& error) 
    {
        TFilePathInterface* filePath = 0;
        error = e_ERROR_NOT_IMPLEMENTED;
        return filePath;
    }
    /**
     **********************************************************************
     * Function: GetNextFilePath
     *
     *   Author: $author$
     *     Date: 9/9/2008
     **********************************************************************
     */
    virtual TFilePathInterface* GetNextFilePath
    (eError& error) 
    {
        TFilePathInterface* filePath = 0;
        error = e_ERROR_NOT_IMPLEMENTED;
        return filePath;
    }
    /**
     **********************************************************************
     * Function: GetPrevFilePath
     *
     *   Author: $author$
     *     Date: 9/9/2008
     **********************************************************************
     */
    virtual TFilePathInterface* GetPrevFilePath
    (eError& error) 
    {
        TFilePathInterface* filePath = 0;
        error = e_ERROR_NOT_IMPLEMENTED;
        return filePath;
    }
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Typedef: cFilePathsImplement
 *
 *  Author: $author$
 *    Date: 9/9/2008
 **********************************************************************
 */
typedef cFilePathsImplementT<>
cFilePathsImplement;

#endif /* _CFILEPATHSINTERFACE_HXX */
