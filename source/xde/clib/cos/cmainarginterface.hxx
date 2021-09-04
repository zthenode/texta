/**
 **********************************************************************
 * Copyright (c) 1988-2007 $organization$
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
 *   File: cmainarginterface.hxx
 *
 * Author: $author$
 *   Date: 2/17/2007
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CMAINARGINTERFACE_HXX
#define _CMAINARGINTERFACE_HXX

#include "cinterface.hxx"

/**
 **********************************************************************
 *  Class: cMainArgInterfaceT
 *
 * Author: $author$
 *   Date: 2/17/2007
 **********************************************************************
 */
template
<class TItem,
 class TChar=CHAR,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 class TImplements=cInterfaceBase>

class c_INTERFACE_CLASS cMainArgInterfaceT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef cMainArgInterfaceT cDerives;

    /**
     **********************************************************************
     * Function: MainArg
     *
     *   Author: $author$
     *     Date: 2/13/2007
     **********************************************************************
     */
    virtual int MainArg
    (int args, int argn, const TChar *arg, 
     int argc, const TChar** argv, const TChar** env) = 0;
    /**
     **********************************************************************
     * Function: SetShortName
     *
     *   Author: $author$
     *     Date: 2/17/2007
     **********************************************************************
     */
    virtual eError SetShortName
    (const TChar* chars,
     TLength length=VUndefinedLength) = 0;
    /**
     **********************************************************************
     * Function: GetShortName
     *
     *   Author: $author$
     *     Date: 2/17/2007
     **********************************************************************
     */
    virtual const TChar* GetShortName
    (TLength& length) const = 0;
    /**
     **********************************************************************
     * Function: SetName
     *
     *   Author: $author$
     *     Date: 2/17/2007
     **********************************************************************
     */
    virtual eError SetName
    (const TChar* chars,
     TLength length=VUndefinedLength) = 0;
    /**
     **********************************************************************
     * Function: GetName
     *
     *   Author: $author$
     *     Date: 2/17/2007
     **********************************************************************
     */
    virtual const TChar* GetName
    (TLength& length) const = 0;
    /**
     **********************************************************************
     * Function: CompareShortName
     *
     *   Author: $author$
     *     Date: 2/20/2003
     **********************************************************************
     */
    virtual int CompareShortName
    (const TChar* toName, TLength length=VUndefinedLength) const = 0;
    /**
     **********************************************************************
     * Function: CompareName
     *
     *   Author: $author$
     *     Date: 2/20/2003
     **********************************************************************
     */
    virtual int CompareName
    (const TChar* toName, TLength length=VUndefinedLength) const = 0;
    /**
     **********************************************************************
     * Function: SetDescription
     *
     *   Author: $author$
     *     Date: 2/17/2007
     **********************************************************************
     */
    virtual eError SetDescription
    (const TChar* chars,
     TLength length=VUndefinedLength) = 0;
    /**
     **********************************************************************
     * Function: GetDescription
     *
     *   Author: $author$
     *     Date: 2/17/2007
     **********************************************************************
     */
    virtual const TChar* GetDescription
    (TLength& length) const = 0;
    /**
     **********************************************************************
     * Function: SetParameters
     *
     *   Author: $author$
     *     Date: 2/20/2007
     **********************************************************************
     */
    virtual eError SetParameters
    (const TChar* chars,
     TLength length=VUndefinedLength) = 0;
    /**
     **********************************************************************
     * Function: GetParameters
     *
     *   Author: $author$
     *     Date: 2/20/2007
     **********************************************************************
     */
    virtual const TChar* GetParameters
    (TLength& length) const = 0;
    /**
     **********************************************************************
     * Function: GetListItem
     *
     *   Author: $author$
     *     Date: 2/20/2007
     **********************************************************************
     */
    virtual TItem& GetListItem() const = 0;
};

/**
 **********************************************************************
 *  Class: cMainArgImplementT
 *
 * Author: $author$
 *   Date: 2/17/2007
 **********************************************************************
 */
template
<class TItem,
 class TChar=CHAR,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 class TImplements=cMainArgInterfaceT
 <TItem, TChar, TLength, VUndefinedLength> >

class cMainArgImplementT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef cMainArgImplementT cDerives;

    /**
     **********************************************************************
     * Function: MainArg
     *
     *   Author: $author$
     *     Date: 2/13/2007
     **********************************************************************
     */
    virtual int MainArg
    (int args, int argn, const TChar *arg, 
     int argc, const TChar** argv, const TChar** env) 
    {
        return argn;
    }
    /**
     **********************************************************************
     * Function: SetName
     *
     *   Author: $author$
     *     Date: 2/17/2007
     **********************************************************************
     */
    virtual eError SetName
    (const TChar* chars,
     TLength length=VUndefinedLength) 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        return error;
    }
    /**
     **********************************************************************
     * Function: GetName
     *
     *   Author: $author$
     *     Date: 2/17/2007
     **********************************************************************
     */
    virtual const TChar* GetName
    (TLength& length) const 
    {
        const TChar* chars = 0;
        return chars;
    }
    /**
     **********************************************************************
     * Function: SetShortName
     *
     *   Author: $author$
     *     Date: 2/17/2007
     **********************************************************************
     */
    virtual eError SetShortName
    (const TChar* chars,
     TLength length=VUndefinedLength) 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        return error;
    }
    /**
     **********************************************************************
     * Function: GetShortName
     *
     *   Author: $author$
     *     Date: 2/17/2007
     **********************************************************************
     */
    virtual const TChar* GetShortName
    (TLength& length) const 
    {
        const TChar* chars = 0;
        return chars;
    }
    /**
     **********************************************************************
     * Function: CompareShortName
     *
     *   Author: $author$
     *     Date: 2/20/2003
     **********************************************************************
     */
    virtual int CompareShortName
    (const TChar* toName, TLength length=VUndefinedLength) const
    {
        return 1;
    }
    /**
     **********************************************************************
     * Function: CompareName
     *
     *   Author: $author$
     *     Date: 2/20/2003
     **********************************************************************
     */
    virtual int CompareName
    (const TChar* toName, TLength length=VUndefinedLength) const
    {
        return 1;
    }
    /**
     **********************************************************************
     * Function: SetDescription
     *
     *   Author: $author$
     *     Date: 2/17/2007
     **********************************************************************
     */
    virtual eError SetDescription
    (const TChar* chars,
     TLength length=VUndefinedLength) 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        return error;
    }
    /**
     **********************************************************************
     * Function: GetDescription
     *
     *   Author: $author$
     *     Date: 2/17/2007
     **********************************************************************
     */
    virtual const TChar* GetDescription
    (TLength& length) const 
    {
        const TChar* chars = 0;
        return chars;
    }
    /**
     **********************************************************************
     * Function: SetParameters
     *
     *   Author: $author$
     *     Date: 2/20/2007
     **********************************************************************
     */
    virtual eError SetParameters
    (const TChar* chars,
     TLength length=VUndefinedLength) 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        return error;
    }
    /**
     **********************************************************************
     * Function: GetParameters
     *
     *   Author: $author$
     *     Date: 2/20/2007
     **********************************************************************
     */
    virtual const TChar* GetParameters
    (TLength& length) const 
    {
        const TChar* chars = 0;
        return chars;
    }
};

class cMainArgItem;
class cMainArgList;
/**
 **********************************************************************
 * Typedef: cMainArgInterface
 *
 *  Author: $author$
 *    Date: 2/17/2007
 **********************************************************************
 */
typedef cMainArgInterfaceT
<cMainArgItem, char, LONG, -1, cInterfaceBase> 
cMainArgInterface;
/**
 **********************************************************************
 * Typedef: cMainArgImplement
 *
 *  Author: $author$
 *    Date: 2/17/2007
 **********************************************************************
 */
typedef cMainArgImplementT
<cMainArgItem, char, LONG, -1, cMainArgInterface>
cMainArgImplement;

#endif /* _CMAINARGINTERFACE_HXX */
