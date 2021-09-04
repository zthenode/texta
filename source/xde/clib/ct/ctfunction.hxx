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
 *   File: ctfunction.hxx
 *
 * Author: $author$
 *   Date: 4/1/2008
 **********************************************************************
 */
#ifndef _CTFUNCTION_HXX
#define _CTFUNCTION_HXX

#include "ctfunctioninterface.hxx"
#include "ctfunctionargument.hxx"
#include "ctfunctionparameter.hxx"
#include "ctfunctiontree.hxx"
#include "ctfunctionlist.hxx"
#include "ctinterface.hxx"
#include "ccomparer.hxx"
#include "cbase.hxx"

/**
 **********************************************************************
 *  Class: cTFunction
 *
 * Author: $author$
 *   Date: 4/1/2008
 **********************************************************************
 */
class cTFunction
: virtual public cTFunctionInterface,
  public cBase
{
public:
    typedef cTFunctionInterface cImplements;
    typedef cBase cExtends;
    typedef cTFunction cDerives;

    cTFunctionItem m_item;
    cTFunctionBranch m_branch;

    const char *m_name;
    const char *m_description;
    const cTFunctionParameter *m_parameter;
    int m_parameters;

    cCharComparer m_comparer;

    /**
     **********************************************************************
     * Constructor: cTFunction
     *
     *      Author: $author$
     *        Date: 8/2/2003
     **********************************************************************
     */
    cTFunction
    (const char *name, const char *description)
    : m_item(*this),
      m_branch(*this),
      m_name(name),
      m_description(description),
      m_parameter(0),
      m_parameters(0) 
    {
        cTImplement::m_function_list.AddItem(m_item);
    }
    /**
     **********************************************************************
     * Function: Initialize
     *
     *   Author: $author$
     *     Date: 8/2/2003
     **********************************************************************
     */
    virtual eError Initialize(cTInterface &t)
    {
        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: Finalize
     *
     *   Author: $author$
     *     Date: 8/2/2003
     **********************************************************************
     */
    virtual eError Finalize(cTInterface &t)
    {
        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 8/2/2003
     **********************************************************************
     */
    virtual eError Expand
    (cCharStreamInterface &result, cTInterface &t,
     const cTFunctionArgumentList &arglist) const
    {
        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: GetVariable
     *
     *   Author: $author$
     *     Date: 12/26/2008
     **********************************************************************
     */
    virtual cTVariableInterface* GetVariable
    (cTInterface &t, const cTFunctionArgument& name) const
    {
        cTVariableInterface *variable = 0;
        const char* nameChars;
        TLENGTH nameLength;
        if ((nameChars = name.GetBuffer(nameLength)))
        if (0 < nameLength)
            variable = t.GetVariable(nameChars, nameLength);
        return variable;
    }
    /**
     **********************************************************************
     * Function: CompareName
     *
     *   Author: $author$
     *     Date: 4/1/2008
     **********************************************************************
     */
    virtual int CompareName
    (const char* toChars, int length=-1) const
    {
        int unequal = m_comparer.Compare
        (m_name,-1, toChars, length);
        return unequal;
    }
    /**
     **********************************************************************
     * Function: GetName
     *
     *   Author: $author$
     *     Date: 8/2/2003
     **********************************************************************
     */
    virtual const char* GetName() const
    {
        return m_name;
    }
    /**
     **********************************************************************
     * Function: GetDescription
     *
     *   Author: $author$
     *     Date: 8/2/2003
     **********************************************************************
     */
    virtual const char* GetDescription
    (const cTFunctionParameter*& parameter, int &parameters) const
    {
        parameter = m_parameter;
        parameters = m_parameters;
        return m_description;
    }
    /**
     **********************************************************************
     * Function: GetItem
     *
     *   Author: $author$
     *     Date: 8/4/2003
     **********************************************************************
     */
    virtual cTFunctionItem& GetItem() const
    {
        return (cTFunctionItem&)(m_item);
    }
    /**
     **********************************************************************
     * Function: GetBranch
     *
     *   Author: $author$
     *     Date: 8/4/2003
     **********************************************************************
     */
    virtual cTFunctionBranch& GetBranch() const
    {
        return (cTFunctionBranch&)(m_branch);
    }
};

#endif /* _CTFUNCTION_HXX */
