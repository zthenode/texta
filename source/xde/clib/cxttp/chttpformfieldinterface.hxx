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
 *   File: chttpformfieldinterface.hxx
 *
 * Author: $author$
 *   Date: 3/17/2008
 **********************************************************************
 */
#ifndef _CHTTPFORMFIELDINTERFACE_HXX
#define _CHTTPFORMFIELDINTERFACE_HXX

#include "cinstanceinterface.hxx"

/**
 **********************************************************************
 *  Class: cHTTPFormFieldInterface
 *
 * Author: $author$
 *   Date: 3/17/2008
 **********************************************************************
 */
class c_INTERFACE_CLASS cHTTPFormFieldInterface
: virtual public cInstanceInterface
{
public:
    typedef char TChar;
    typedef TSIZE TSize;
    typedef TLENGTH TLength;

    typedef cInstanceInterface cImplements;
    typedef cHTTPFormFieldInterface cDerives;

    /**
     **********************************************************************
     * Function: SetName
     *
     *   Author: $author$
     *     Date: 3/17/2008
     **********************************************************************
     */
    virtual TLength SetName
    (const TChar* chars,
     TLength length=-1) = 0;
    /**
     **********************************************************************
     * Function: CompareName
     *
     *   Author: $author$
     *     Date: 3/17/2008
     **********************************************************************
     */
    virtual int CompareName
    (const TChar* toChars, 
     TLength length=-1) const = 0;
    /**
     **********************************************************************
     * Function: GetName
     *
     *   Author: $author$
     *     Date: 3/17/2008
     **********************************************************************
     */
    virtual const TChar* GetName
    (TLength& length) const = 0;
    /**
     **********************************************************************
     * Function: SetValue
     *
     *   Author: $author$
     *     Date: 3/17/2008
     **********************************************************************
     */
    virtual TLength SetValue
    (const TChar* chars,
     TLength length=-1) = 0;
    /**
     **********************************************************************
     * Function: CompareValue
     *
     *   Author: $author$
     *     Date: 12/29/2008
     **********************************************************************
     */
    virtual int CompareValue
    (const TChar* toChars, 
     TLength length=-1) const = 0;
    /**
     **********************************************************************
     * Function: GetValue
     *
     *   Author: $author$
     *     Date: 3/17/2008
     **********************************************************************
     */
    virtual const TChar* GetValue
    (TLength& length) const = 0;
    /**
     **********************************************************************
     * Function: SetIsFromQueryString
     *
     *   Author: $author$
     *     Date: 3/17/2008
     **********************************************************************
     */
    virtual bool SetIsFromQueryString(bool is=true) = 0;
    /**
     **********************************************************************
     * Function: GetIsFromQueryString
     *
     *   Author: $author$
     *     Date: 3/17/2008
     **********************************************************************
     */
    virtual bool GetIsFromQueryString() const = 0;

    /**
     **********************************************************************
     * Function: CreateInstance
     *
     *   Author: $author$
     *     Date: 3/17/2008
     **********************************************************************
     */
    static cHTTPFormFieldInterface* 
    CreateInstance(eError& error);
    /**
     **********************************************************************
     * Function: DestroyInstance
     *
     *   Author: $author$
     *     Date: 3/17/2008
     **********************************************************************
     */
    static eError DestroyInstance
    (cHTTPFormFieldInterface& instance);
};
#endif /* _CHTTPFORMFIELDINTERFACE_HXX */
