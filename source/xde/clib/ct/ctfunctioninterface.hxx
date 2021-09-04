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
 *   File: ctfunctioninterface.hxx
 *
 * Author: $author$
 *   Date: 3/31/2008
 **********************************************************************
 */
#ifndef _CTFUNCTIONINTERFACE_HXX
#define _CTFUNCTIONINTERFACE_HXX

#include "ctinterfacebase.hxx"
#include "cstream.hxx"

class cTFunctionParameter;
class cTFunctionArgument;
class cTFunctionArgumentList;
class cTFunctionItem;
class cTFunctionBranch;

/**
 **********************************************************************
 *  Class: cTFunctionInterface
 *
 * Author: $author$
 *   Date: 3/31/2008
 **********************************************************************
 */
class c_INTERFACE_CLASS cTFunctionInterface
: virtual public cInterfaceBase
{
public:
    typedef cInterfaceBase cImplements;
    typedef cTFunctionInterface cDerives;
    /**
     **********************************************************************
     * Function: Initialize
     *
     *   Author: $author$
     *     Date: 7/8/2003
     **********************************************************************
     */
    virtual eError Initialize(cTInterface &t)=0;
    /**
     **********************************************************************
     * Function: Finalize
     *
     *   Author: $author$
     *     Date: 7/8/2003
     **********************************************************************
     */
    virtual eError Finalize(cTInterface &t)=0;
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 7/8/2003
     **********************************************************************
     */
    virtual eError Expand
    (cCharStreamInterface &result, cTInterface &t,
     const cTFunctionArgumentList &arglist) const = 0;
    /**
     **********************************************************************
     * Function: CompareName
     *
     *   Author: $author$
     *     Date: 4/1/2008
     **********************************************************************
     */
    virtual int CompareName
    (const char* toChars, int length=-1) const=0;
    /**
     **********************************************************************
     * Function: GetName
     *
     *   Author: $author$
     *     Date: 7/8/2003
     **********************************************************************
     */
    virtual const char *GetName() const=0;
    /**
     **********************************************************************
     * Function: GetDescription
     *
     *   Author: $author$
     *     Date: 7/8/2003
     **********************************************************************
     */
    virtual const char *GetDescription
    (const cTFunctionParameter *&parameter, int &parameters) const=0;
    /**
     **********************************************************************
     * Function: GetItem
     *
     *   Author: $author$
     *     Date: 7/8/2003
     **********************************************************************
     */
    virtual cTFunctionItem &GetItem() const=0;
    /**
     **********************************************************************
     * Function: GetBranch
     *
     *   Author: $author$
     *     Date: 7/8/2003
     **********************************************************************
     */
    virtual cTFunctionBranch &GetBranch() const=0;
};
#endif /* _CTFUNCTIONINTERFACE_HXX */
