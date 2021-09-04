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
 *   File: cfilepatheventinterface.hxx
 *
 * Author: $author$
 *   Date: 9/6/2008
 **********************************************************************
 */
#ifndef _CFILEPATHEVENTINTERFACE_HXX
#define _CFILEPATHEVENTINTERFACE_HXX

#include "cstringinterface.hxx"

#undef CDB_CLASS
#define CDB_CLASS "cFilePathEventInterfaceT"
/**
 **********************************************************************
 *  Class: cFilePathEventInterfaceT
 *
 * Author: $author$
 *   Date: 9/6/2008
 **********************************************************************
 */
template
<class TChar=CHAR, 
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 TChar VNullChar=NULL_CHAR,
 class TImplements=cInterfaceBase>
 
class c_INTERFACE_CLASS cFilePathEventInterfaceT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef cFilePathEventInterfaceT cDerives;
    /**
     **********************************************************************
     * Function: OnPathHost
     *
     *   Author: $author$
     *     Date: 9/6/2008
     **********************************************************************
     */
    virtual TLength OnPathHost
    (const TChar* chars,
     TLength length=VUndefinedLength) = 0;
    /**
     **********************************************************************
     * Function: OnPathVolume
     *
     *   Author: $author$
     *     Date: 9/6/2008
     **********************************************************************
     */
    virtual TLength OnPathVolume
    (const TChar* chars,
     TLength length=VUndefinedLength) = 0;
    /**
     **********************************************************************
     * Function: OnPathDirectory
     *
     *   Author: $author$
     *     Date: 9/6/2008
     **********************************************************************
     */
    virtual TLength OnPathDirectory
    (const TChar* chars,
     TLength length=VUndefinedLength) = 0;
    /**
     **********************************************************************
     * Function: OnPathParentDirectory
     *
     *   Author: $author$
     *     Date: 9/6/2008
     **********************************************************************
     */
    virtual TLength OnPathParentDirectory
    (const TChar* chars,
     TLength length=VUndefinedLength) = 0;
    /**
     **********************************************************************
     * Function: OnPathCurrentDirectory
     *
     *   Author: $author$
     *     Date: 9/6/2008
     **********************************************************************
     */
    virtual TLength OnPathCurrentDirectory
    (const TChar* chars,
     TLength length=VUndefinedLength) = 0;
    /**
     **********************************************************************
     * Function: OnPathRootDirectory
     *
     *   Author: $author$
     *     Date: 9/6/2008
     **********************************************************************
     */
    virtual TLength OnPathRootDirectory
    (const TChar* chars,
     TLength length=VUndefinedLength) = 0;
    /**
     **********************************************************************
     * Function: OnPathRootParentDirectory
     *
     *   Author: $author$
     *     Date: 9/6/2008
     **********************************************************************
     */
    virtual TLength OnPathRootParentDirectory
    (const TChar* chars,
     TLength length=VUndefinedLength) = 0;
    /**
     **********************************************************************
     * Function: OnPathRootCurrentDirectory
     *
     *   Author: $author$
     *     Date: 9/6/2008
     **********************************************************************
     */
    virtual TLength OnPathRootCurrentDirectory
    (const TChar* chars,
     TLength length=VUndefinedLength) = 0;
    /**
     **********************************************************************
     * Function: OnPathRootFileName
     *
     *   Author: $author$
     *     Date: 9/6/2008
     **********************************************************************
     */
    virtual TLength OnPathRootFileName
    (const TChar* chars,
     TLength length=VUndefinedLength) = 0;
    /**
     **********************************************************************
     * Function: OnPathRootFileBase
     *
     *   Author: $author$
     *     Date: 9/6/2008
     **********************************************************************
     */
    virtual TLength OnPathRootFileBase
    (const TChar* chars,
     TLength length=VUndefinedLength) = 0;
    /**
     **********************************************************************
     * Function: OnPathRootFileExtension
     *
     *   Author: $author$
     *     Date: 9/6/2008
     **********************************************************************
     */
    virtual TLength OnPathRootFileExtension
    (const TChar* chars,
     TLength length=VUndefinedLength) = 0;
    /**
     **********************************************************************
     * Function: OnPathFileName
     *
     *   Author: $author$
     *     Date: 9/6/2008
     **********************************************************************
     */
    virtual TLength OnPathFileName
    (const TChar* chars,
     TLength length=VUndefinedLength) = 0;
    /**
     **********************************************************************
     * Function: OnPathFileBase
     *
     *   Author: $author$
     *     Date: 9/6/2008
     **********************************************************************
     */
    virtual TLength OnPathFileBase
    (const TChar* chars,
     TLength length=VUndefinedLength) = 0;
    /**
     **********************************************************************
     * Function: OnPathFileExtension
     *
     *   Author: $author$
     *     Date: 9/6/2008
     **********************************************************************
     */
    virtual TLength OnPathFileExtension
    (const TChar* chars,
     TLength length=VUndefinedLength) = 0;
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Typedef: cFilePathEventInterface
 *
 *  Author: $author$
 *    Date: 9/6/2008
 **********************************************************************
 */
typedef cFilePathEventInterfaceT<>
cFilePathEventInterface;

#undef CDB_CLASS
#define CDB_CLASS "cFilePathEventImplementT"
/**
 **********************************************************************
 *  Class: cFilePathEventImplementT
 *
 * Author: $author$
 *   Date: 9/6/2008
 **********************************************************************
 */
template
<class TChar=CHAR, 
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 TChar VNullChar=NULL_CHAR,
 class TImplements=cFilePathEventInterface>
 
class cFilePathEventImplementT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef cFilePathEventImplementT cDerives;
    /**
     **********************************************************************
     * Function: OnPathHost
     *
     *   Author: $author$
     *     Date: 9/6/2008
     **********************************************************************
     */
    virtual TLength OnPathHost
    (const TChar* chars,
     TLength length=VUndefinedLength) 
    {
        TLength count = -e_ERROR_NOT_IMPLEMENTED;
        return count;
    }
    /**
     **********************************************************************
     * Function: OnPathVolume
     *
     *   Author: $author$
     *     Date: 9/6/2008
     **********************************************************************
     */
    virtual TLength OnPathVolume
    (const TChar* chars,
     TLength length=VUndefinedLength) 
    {
        TLength count = -e_ERROR_NOT_IMPLEMENTED;
        return count;
    }
    /**
     **********************************************************************
     * Function: OnPathDirectory
     *
     *   Author: $author$
     *     Date: 9/6/2008
     **********************************************************************
     */
    virtual TLength OnPathDirectory
    (const TChar* chars,
     TLength length=VUndefinedLength) 
    {
        TLength count = -e_ERROR_NOT_IMPLEMENTED;
        return count;
    }
    /**
     **********************************************************************
     * Function: OnPathParentDirectory
     *
     *   Author: $author$
     *     Date: 9/6/2008
     **********************************************************************
     */
    virtual TLength OnPathParentDirectory
    (const TChar* chars,
     TLength length=VUndefinedLength) 
    {
        TLength count = -e_ERROR_NOT_IMPLEMENTED;
        return count;
    }
    /**
     **********************************************************************
     * Function: OnPathCurrentDirectory
     *
     *   Author: $author$
     *     Date: 9/6/2008
     **********************************************************************
     */
    virtual TLength OnPathCurrentDirectory
    (const TChar* chars,
     TLength length=VUndefinedLength) 
    {
        TLength count = -e_ERROR_NOT_IMPLEMENTED;
        return count;
    }
    /**
     **********************************************************************
     * Function: OnPathRootDirectory
     *
     *   Author: $author$
     *     Date: 9/6/2008
     **********************************************************************
     */
    virtual TLength OnPathRootDirectory
    (const TChar* chars,
     TLength length=VUndefinedLength) 
    {
        TLength count = -e_ERROR_NOT_IMPLEMENTED;
        return count;
    }
    /**
     **********************************************************************
     * Function: OnPathRootParentDirectory
     *
     *   Author: $author$
     *     Date: 9/6/2008
     **********************************************************************
     */
    virtual TLength OnPathRootParentDirectory
    (const TChar* chars,
     TLength length=VUndefinedLength) 
    {
        TLength count = -e_ERROR_NOT_IMPLEMENTED;
        return count;
    }
    /**
     **********************************************************************
     * Function: OnPathRootCurrentDirectory
     *
     *   Author: $author$
     *     Date: 9/6/2008
     **********************************************************************
     */
    virtual TLength OnPathRootCurrentDirectory
    (const TChar* chars,
     TLength length=VUndefinedLength) 
    {
        TLength count = -e_ERROR_NOT_IMPLEMENTED;
        return count;
    }
    /**
     **********************************************************************
     * Function: OnPathRootFileName
     *
     *   Author: $author$
     *     Date: 9/6/2008
     **********************************************************************
     */
    virtual TLength OnPathRootFileName
    (const TChar* chars,
     TLength length=VUndefinedLength) 
    {
        TLength count = -e_ERROR_NOT_IMPLEMENTED;
        return count;
    }
    /**
     **********************************************************************
     * Function: OnPathRootFileBase
     *
     *   Author: $author$
     *     Date: 9/6/2008
     **********************************************************************
     */
    virtual TLength OnPathRootFileBase
    (const TChar* chars,
     TLength length=VUndefinedLength) 
    {
        TLength count = -e_ERROR_NOT_IMPLEMENTED;
        return count;
    }
    /**
     **********************************************************************
     * Function: OnPathRootFileExtension
     *
     *   Author: $author$
     *     Date: 9/6/2008
     **********************************************************************
     */
    virtual TLength OnPathRootFileExtension
    (const TChar* chars,
     TLength length=VUndefinedLength) 
    {
        TLength count = -e_ERROR_NOT_IMPLEMENTED;
        return count;
    }
    /**
     **********************************************************************
     * Function: OnPathFileName
     *
     *   Author: $author$
     *     Date: 9/6/2008
     **********************************************************************
     */
    virtual TLength OnPathFileName
    (const TChar* chars,
     TLength length=VUndefinedLength) 
    {
        TLength count = -e_ERROR_NOT_IMPLEMENTED;
        return count;
    }
    /**
     **********************************************************************
     * Function: OnPathFileBase
     *
     *   Author: $author$
     *     Date: 9/6/2008
     **********************************************************************
     */
    virtual TLength OnPathFileBase
    (const TChar* chars,
     TLength length=VUndefinedLength) 
    {
        TLength count = -e_ERROR_NOT_IMPLEMENTED;
        return count;
    }
    /**
     **********************************************************************
     * Function: OnPathFileExtension
     *
     *   Author: $author$
     *     Date: 9/6/2008
     **********************************************************************
     */
    virtual TLength OnPathFileExtension
    (const TChar* chars,
     TLength length=VUndefinedLength) 
    {
        TLength count = -e_ERROR_NOT_IMPLEMENTED;
        return count;
    }
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Typedef: cFilePathEventImplement
 *
 *  Author: $author$
 *    Date: 9/7/2008
 **********************************************************************
 */
typedef cFilePathEventImplementT<>
cFilePathEventImplement;

#endif /* _CFILEPATHEVENTINTERFACE_HXX */
