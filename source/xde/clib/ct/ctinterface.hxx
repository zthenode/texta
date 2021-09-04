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
 *   File: ctinterface.hxx
 *
 * Author: $author$
 *   Date: 3/31/2008
 **********************************************************************
 */
#ifndef _CTINTERFACE_HXX
#define _CTINTERFACE_HXX

#include "ctfunctionlist.hxx"
#include "ctfunctioninterface.hxx"
#include "ctvariableinterface.hxx"
#include "ctparameterinterface.hxx"
#include "ctinterfacebase.hxx"
#include "cstream.hxx"

/**
 **********************************************************************
 *  Class: cTInterface
 *
 * Author: $author$
 *   Date: 3/31/2008
 **********************************************************************
 */
class c_INTERFACE_CLASS cTInterface
//: virtual public cInterfaceBase
: virtual public cTParameterInterface
{
public:
    //typedef cInterfaceBase cImplements;
    typedef cTParameterInterface cImplements;
    typedef cTInterface cDerives;

    /**
     **********************************************************************
     * Function: Initialize
     *
     *   Author: $author$
     *     Date: 4/1/2008
     **********************************************************************
     */
    virtual eError Initialize() = 0;
    /**
     **********************************************************************
     * Function: Finalize
     *
     *   Author: $author$
     *     Date: 4/1/2008
     **********************************************************************
     */
    virtual eError Finalize() = 0;

    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 7/7/2003
     **********************************************************************
     */
    virtual eError Expand
    (cCharStreamInterface &out, cCharStreamInterface &in) = 0;
    /**
     **********************************************************************
     * Function: ExpandFunction
     *
     *   Author: $author$
     *     Date: 7/15/2003
     **********************************************************************
     */
    virtual eError ExpandFunction
    (cCharStreamInterface &out, 
     const cTFunctionArgumentList &args, const char* name)=0;
    /**
     **********************************************************************
     * Function: GetFirstFunction
     *
     *   Author: $author$
     *     Date: 8/3/2005
     **********************************************************************
     */
    virtual cTFunctionInterface* GetFirstFunction() = 0;
    /**
     **********************************************************************
     * Function: GetNextFunction
     *
     *   Author: $author$
     *     Date: 8/3/2005
     **********************************************************************
     */
    virtual cTFunctionInterface* GetNextFunction() = 0;
    /**
     **********************************************************************
     * Function: FindFunction
     *
     *   Author: $author$
     *     Date: 8/3/2003
     **********************************************************************
     */
    virtual cTFunctionInterface*
    FindFunction(const char *name, int namelen=-1) const = 0;

    /**
     **********************************************************************
     * Function: ExpandVariable
     *
     *   Author: $author$
     *     Date: 7/15/2003
     **********************************************************************
     */
    virtual eError ExpandVariable
    (cCharStreamInterface &out, const char* name)=0;
    /**
     **********************************************************************
     * Function: SetVariable
     *
     *   Author: $author$
     *     Date: 7/15/2003
     **********************************************************************
     */
    virtual cTVariableInterface* SetVariable
    (const char *name,int namelen=-1,
     const char *value=0,int valuelen=-1)=0;
    /**
     **********************************************************************
     * Function: GetVariable
     *
     *   Author: $author$
     *     Date: 7/15/2003
     **********************************************************************
     */
    virtual cTVariableInterface* GetVariable
    (const char *name,int namelen=-1,
     const char *value=0,int valuelen=-1)=0;

    /**
     **********************************************************************
     * Function: SetValue
     *
     *   Author: $author$
     *     Date: 7/15/2003
     **********************************************************************
     */
    virtual const char *SetValue
    (const char *name,int namelen=-1,
     const char *value=0,int valuelen=-1) = 0;
    /**
     **********************************************************************
     * Function: GetValue
     *
     *   Author: $author$
     *     Date: 7/15/2003
     **********************************************************************
     */
    virtual const char *GetValue
    (const char *name,int namelen=-1) = 0;
};

/**
 **********************************************************************
 *  Class: cTImplement
 *
 * Author: $author$
 *   Date: 4/1/2008
 **********************************************************************
 */
class cTImplement
//: virtual public cTInterface
: virtual public cTParameterImplement,
  virtual public cTInterface
{
public:
    //typedef cTInterface cImplements;
    typedef cTParameterImplement cImplements;
    typedef cTImplement cDerives;

    static cTFunctionList m_function_list;

    /**
     **********************************************************************
     * Function: Initialize
     *
     *   Author: $author$
     *     Date: 7/15/2003
     **********************************************************************
     */
    virtual eError Initialize()
    {
        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: Finalize
     *
     *   Author: $author$
     *     Date: 7/15/2003
     **********************************************************************
     */
    virtual eError Finalize()
    {
        return e_ERROR_NONE;
    }

    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 7/7/2003
     **********************************************************************
     */
    virtual eError Expand
    (cCharStreamInterface &out, cCharStreamInterface &in)
    {
        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: ExpandFunction
     *
     *   Author: $author$
     *     Date: 7/15/2003
     **********************************************************************
     */
    virtual eError ExpandFunction
    (cCharStreamInterface &out, 
     const cTFunctionArgumentList &args, const char* name)
    {
        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: GetFirstFunction
     *
     *   Author: $author$
     *     Date: 8/3/2005
     **********************************************************************
     */
    virtual cTFunctionInterface* GetFirstFunction() 
    { return 0; }
    /**
     **********************************************************************
     * Function: GetNextFunction
     *
     *   Author: $author$
     *     Date: 8/3/2005
     **********************************************************************
     */
    virtual cTFunctionInterface* GetNextFunction() 
    { return 0; }

    /**
     **********************************************************************
     * Function: ExpandVariable
     *
     *   Author: $author$
     *     Date: 7/15/2003
     **********************************************************************
     */
    virtual eError ExpandVariable
    (cCharStreamInterface &out, const char* name)
    {
        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: SetVariable
     *
     *   Author: $author$
     *     Date: 7/15/2003
     **********************************************************************
     */
    virtual cTVariableInterface* SetVariable
    (const char *name,int namelen=-1,
     const char *value=0,int valuelen=-1)
    { return 0; }
    /**
     **********************************************************************
     * Function: GetVariable
     *
     *   Author: $author$
     *     Date: 7/15/2003
     **********************************************************************
     */
    virtual cTVariableInterface* GetVariable
    (const char *name,int namelen=-1,
     const char *value=0,int valuelen=-1)
    { return 0; }

    /**
     **********************************************************************
     * Function: SetValue
     *
     *   Author: $author$
     *     Date: 7/15/2003
     **********************************************************************
     */
    virtual const char *SetValue
    (const char *name,int namelen=-1,
     const char *value=0,int valuelen=-1)
    {
        cTVariableInterface *variable;

        if ((variable=SetVariable
            (name,namelen, value,valuelen)))
            return variable->GetValue();

        return 0;
    }
    /**
     **********************************************************************
     * Function: GetValue
     *
     *   Author: $author$
     *     Date: 7/15/2003
     **********************************************************************
     */
    virtual const char* GetValue
    (const char *name, int namelen=-1)
    {
        cTVariableInterface *variable;

        if ((variable=GetVariable(name, namelen)))
            return variable->GetValue();

        return 0;
    }
};
#endif /* _CTINTERFACE_HXX */
