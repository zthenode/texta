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
 *   File: cfilepathinterface.hxx
 *
 * Author: $author$
 *   Date: 9/5/2008
 **********************************************************************
 */
#ifndef _CFILEPATHINTERFACE_HXX
#define _CFILEPATHINTERFACE_HXX

#include "cstring.hxx"

#undef CDB_CLASS
#define CDB_CLASS "cFilePathInterfaceT"
/**
 **********************************************************************
 *  Class: cFilePathInterfaceT
 *
 * Author: $author$
 *   Date: 9/5/2008
 **********************************************************************
 */
template
<class TChar=CHAR, 
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 TChar VNullChar=NULL_CHAR,
 class TStringInterface=cStringInterface,
 class TImplements=cStringInterface>
 
class c_INTERFACE_CLASS cFilePathInterfaceT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef cFilePathInterfaceT cDerives;
    /**
     **********************************************************************
     * Function: MakeFileName
     *
     *   Author: $author$
     *     Date: 9/8/2008
     **********************************************************************
     */
    virtual TLength MakeFileName
    (TStringInterface& path, const TChar* fileNameChars,
     TLength fileNameLength=VUndefinedLength) = 0;
    /**
     **********************************************************************
     * Function: SeparateParts
     *
     *   Author: $author$
     *     Date: 9/5/2008
     **********************************************************************
     */
    virtual eError SeparateParts() = 0;
    /**
     **********************************************************************
     * Function: CombineParts
     *
     *   Author: $author$
     *     Date: 9/5/2008
     **********************************************************************
     */
    virtual TLength CombineParts() = 0;
    /**
     **********************************************************************
     * Function: SetFileHost
     *
     *   Author: $author$
     *     Date: 9/5/2008
     **********************************************************************
     */
    virtual TLength SetFileHost
    (const TChar* chars,
     TLength length=VUndefinedLength) = 0;
    /**
     **********************************************************************
     * Function: GetFileHost
     *
     *   Author: $author$
     *     Date: 9/5/2008
     **********************************************************************
     */
    virtual const TChar* GetFileHost
    (TLength& length) const = 0;
    /**
     **********************************************************************
     * Function: SetFileVolume
     *
     *   Author: $author$
     *     Date: 9/5/2008
     **********************************************************************
     */
    virtual TLength SetFileVolume
    (const TChar* chars,
     TLength length=VUndefinedLength) = 0;
    /**
     **********************************************************************
     * Function: GetFileVolume
     *
     *   Author: $author$
     *     Date: 9/5/2008
     **********************************************************************
     */
    virtual const TChar* GetFileVolume
    (TLength& length) const = 0;
    /**
     **********************************************************************
     * Function: SetFileDirectory
     *
     *   Author: $author$
     *     Date: 9/5/2008
     **********************************************************************
     */
    virtual TLength SetFileDirectory
    (const TChar* chars,
     TLength length=VUndefinedLength) = 0;
    /**
     **********************************************************************
     * Function: GetFileDirectory
     *
     *   Author: $author$
     *     Date: 9/5/2008
     **********************************************************************
     */
    virtual const TChar* GetFileDirectory
    (TLength& length) const = 0;
    /**
     **********************************************************************
     * Function: SetFileName
     *
     *   Author: $author$
     *     Date: 9/5/2008
     **********************************************************************
     */
    virtual TLength SetFileName
    (const TChar* chars,
     TLength length=VUndefinedLength) = 0;
    /**
     **********************************************************************
     * Function: GetFileName
     *
     *   Author: $author$
     *     Date: 9/5/2008
     **********************************************************************
     */
    virtual const TChar* GetFileName
    (TLength& length) const = 0;
    /**
     **********************************************************************
     * Function: SetFileBase
     *
     *   Author: $author$
     *     Date: 9/5/2008
     **********************************************************************
     */
    virtual TLength SetFileBase
    (const TChar* chars,
     TLength length=VUndefinedLength) = 0;
    /**
     **********************************************************************
     * Function: GetFileBase
     *
     *   Author: $author$
     *     Date: 9/5/2008
     **********************************************************************
     */
    virtual const TChar* GetFileBase
    (TLength& length) const = 0;
    /**
     **********************************************************************
     * Function: SetFileExtension
     *
     *   Author: $author$
     *     Date: 9/5/2008
     **********************************************************************
     */
    virtual TLength SetFileExtension
    (const TChar* chars,
     TLength length=VUndefinedLength) = 0;
    /**
     **********************************************************************
     * Function: GetFileExtension
     *
     *   Author: $author$
     *     Date: 9/5/2008
     **********************************************************************
     */
    virtual const TChar* GetFileExtension
    (TLength& length) const = 0;
    /**
     **********************************************************************
     * Function: SetFilePath
     *
     *   Author: $author$
     *     Date: 9/5/2008
     **********************************************************************
     */
    virtual TLength SetFilePath
    (const TChar* chars,
     TLength length=VUndefinedLength) = 0;
    /**
     **********************************************************************
     * Function: GetFilePath
     *
     *   Author: $author$
     *     Date: 9/5/2008
     **********************************************************************
     */
    virtual const TChar* GetFilePath
    (TLength& length) const = 0;
    /**
     **********************************************************************
     * Function: SetIsRelativeDirectory
     *
     *   Author: $author$
     *     Date: 9/15/2008
     **********************************************************************
     */
    virtual int SetIsRelativeDirectory
    (bool is=true) = 0;
    /**
     **********************************************************************
     * Function: GetIsRelativeDirectory
     *
     *   Author: $author$
     *     Date: 9/15/2008
     **********************************************************************
     */
    virtual bool GetIsRelativeDirectory() const = 0;
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Typedef: cFilePathInterface
 *
 *  Author: $author$
 *    Date: 9/7/2008
 **********************************************************************
 */
typedef cFilePathInterfaceT<>
cFilePathInterface;

#undef CDB_CLASS
#define CDB_CLASS "cFilePathImplementT"
/**
 **********************************************************************
 *  Class: cFilePathImplementT
 *
 * Author: $author$
 *   Date: 9/5/2008
 **********************************************************************
 */
template
<class TChar=CHAR, 
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 TChar VNullChar=NULL_CHAR,
 class TStringInterface=cStringInterface,
 class TStringImplements=cStringInterface,
 class TImplements=cFilePathInterface>
 
class cFilePathImplementT
: virtual public TStringImplements,
  virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef cFilePathImplementT cDerives;
    /**
     **********************************************************************
     * Function: MakeFileName
     *
     *   Author: $author$
     *     Date: 9/8/2008
     **********************************************************************
     */
    virtual TLength MakeFileName
    (TStringInterface& path, const TChar* fileNameChars,
     TLength fileNameLength=VUndefinedLength) 
    {
        TLength count = 0;
        return count;
    }
    /**
     **********************************************************************
     * Function: SeparateParts
     *
     *   Author: $author$
     *     Date: 9/5/2008
     **********************************************************************
     */
    virtual eError SeparateParts() 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        return error;
    }
    /**
     **********************************************************************
     * Function: CombineParts
     *
     *   Author: $author$
     *     Date: 9/5/2008
     **********************************************************************
     */
    virtual TLength CombineParts() 
    {
        TLength length = -e_ERROR_NOT_IMPLEMENTED;
        return length;
    }
    /**
     **********************************************************************
     * Function: SetFileHost
     *
     *   Author: $author$
     *     Date: 9/5/2008
     **********************************************************************
     */
    virtual TLength SetFileHost
    (const TChar* chars,
     TLength length=VUndefinedLength) 
    {
        TLength count = 0;
        return count;
    }
    /**
     **********************************************************************
     * Function: GetFileHost
     *
     *   Author: $author$
     *     Date: 9/5/2008
     **********************************************************************
     */
    virtual const TChar* GetFileHost
    (TLength& length) const 
    {
        const TChar* chars = 0;
        return chars;
    }
    /**
     **********************************************************************
     * Function: SetFileVolume
     *
     *   Author: $author$
     *     Date: 9/5/2008
     **********************************************************************
     */
    virtual TLength SetFileVolume
    (const TChar* chars,
     TLength length=VUndefinedLength) 
    {
        TLength count = 0;
        return count;
    }
    /**
     **********************************************************************
     * Function: GetFileVolume
     *
     *   Author: $author$
     *     Date: 9/5/2008
     **********************************************************************
     */
    virtual const TChar* GetFileVolume
    (TLength& length) const 
    {
        const TChar* chars = 0;
        return chars;
    }
    /**
     **********************************************************************
     * Function: SetFileDirectory
     *
     *   Author: $author$
     *     Date: 9/5/2008
     **********************************************************************
     */
    virtual TLength SetFileDirectory
    (const TChar* chars,
     TLength length=VUndefinedLength) 
    {
        TLength count = 0;
        return count;
    }
    /**
     **********************************************************************
     * Function: GetFileDirectory
     *
     *   Author: $author$
     *     Date: 9/5/2008
     **********************************************************************
     */
    virtual const TChar* GetFileDirectory
    (TLength& length) const 
    {
        const TChar* chars = 0;
        return chars;
    }
    /**
     **********************************************************************
     * Function: SetFileName
     *
     *   Author: $author$
     *     Date: 9/5/2008
     **********************************************************************
     */
    virtual TLength SetFileName
    (const TChar* chars,
     TLength length=VUndefinedLength) 
    {
        TLength count = 0;
        return count;
    }
    /**
     **********************************************************************
     * Function: GetFileName
     *
     *   Author: $author$
     *     Date: 9/5/2008
     **********************************************************************
     */
    virtual const TChar* GetFileName
    (TLength& length) const 
    {
        const TChar* chars = 0;
        return chars;
    }
    /**
     **********************************************************************
     * Function: SetFileBase
     *
     *   Author: $author$
     *     Date: 9/5/2008
     **********************************************************************
     */
    virtual TLength SetFileBase
    (const TChar* chars,
     TLength length=VUndefinedLength) 
    {
        TLength count = 0;
        return count;
    }
    /**
     **********************************************************************
     * Function: GetFileBase
     *
     *   Author: $author$
     *     Date: 9/5/2008
     **********************************************************************
     */
    virtual const TChar* GetFileBase
    (TLength& length) const 
    {
        const TChar* chars = 0;
        return chars;
    }
    /**
     **********************************************************************
     * Function: SetFileExtension
     *
     *   Author: $author$
     *     Date: 9/5/2008
     **********************************************************************
     */
    virtual TLength SetFileExtension
    (const TChar* chars,
     TLength length=VUndefinedLength) 
    {
        TLength count = 0;
        return count;
    }
    /**
     **********************************************************************
     * Function: GetFileExtension
     *
     *   Author: $author$
     *     Date: 9/5/2008
     **********************************************************************
     */
    virtual const TChar* GetFileExtension
    (TLength& length) const 
    {
        const TChar* chars = 0;
        return chars;
    }
    /**
     **********************************************************************
     * Function: SetFilePath
     *
     *   Author: $author$
     *     Date: 9/5/2008
     **********************************************************************
     */
    virtual TLength SetFilePath
    (const TChar* chars,
     TLength length=VUndefinedLength) 
    {
        TLength count = 0;
        return count;
    }
    /**
     **********************************************************************
     * Function: GetFilePath
     *
     *   Author: $author$
     *     Date: 9/5/2008
     **********************************************************************
     */
    virtual const TChar* GetFilePath
    (TLength& length) const 
    {
        const TChar* chars = 0;
        return chars;
    }
    /**
     **********************************************************************
     * Function: SetIsRelativeDirectory
     *
     *   Author: $author$
     *     Date: 9/15/2008
     **********************************************************************
     */
    virtual int SetIsRelativeDirectory
    (bool is=true) 
    {
        is = false;
        return is;
    }
    /**
     **********************************************************************
     * Function: GetIsRelativeDirectory
     *
     *   Author: $author$
     *     Date: 9/15/2008
     **********************************************************************
     */
    virtual bool GetIsRelativeDirectory() const 
    {
        bool is = false;
        return is;
    }
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Typedef: cFilePathImplement
 *
 *  Author: $author$
 *    Date: 9/7/2008
 **********************************************************************
 */
typedef cFilePathImplementT<>
cFilePathImplement;

#endif /* _CFILEPATHINTERFACE_HXX */
