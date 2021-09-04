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
 *   File: cxalanparameter.hxx
 *
 * Author: $author$
 *   Date: 3/13/2008
 **********************************************************************
 */
#ifndef _CXALANPARAMETER_HXX
#define _CXALANPARAMETER_HXX

#include "cinstance.hxx"
#include "creference.hxx"
#include "cstring.hxx"
#include "cvector.hxx"

/**
 **********************************************************************
 *  Class: cXalanParameter
 *
 * Author: $author$
 *   Date: 3/13/2008
 **********************************************************************
 */
class cXalanParameter
: public cInstance
{
public:
    typedef cInstance cExtends;
    typedef cXalanParameter cDerives;

    cCharString m_name;
    cCharString m_value;

    /**
     **********************************************************************
     * Constructor: cXalanParameter
     *
     *      Author: $author$
     *        Date: 3/13/2008
     **********************************************************************
     */
    cXalanParameter
    (const char* name=0, 
     const char* value=0,
     bool isStaticInstance=true) 
    : cExtends(isStaticInstance)
    {
        eError error;
        TLENGTH length;
        if (name)
        if (0 > (length = SetName(name)))
            throw(error = -length);
        if (value)
        if (0 > (length = SetValue(value)))
            throw(error = -length);
    }
    /**
     **********************************************************************
     * Function: SetName
     *
     *   Author: $author$
     *     Date: 3/13/2008
     **********************************************************************
     */
    virtual TLENGTH SetName
    (const char* chars,
     TLENGTH length=-1) 
    {
        TLENGTH count = m_name.Assign(chars, length);
        return count;
    }
    /**
     **********************************************************************
     * Function: GetName
     *
     *   Author: $author$
     *     Date: 3/13/2008
     **********************************************************************
     */
    virtual const char* GetName
    (TLENGTH& length) const 
    {
        const char* chars = m_name.Chars(length);
        return chars;
    }
    /**
     **********************************************************************
     * Function: SetValue
     *
     *   Author: $author$
     *     Date: 3/13/2008
     **********************************************************************
     */
    virtual TLENGTH SetValue
    (const char* chars,
     TLENGTH length=-1) 
    {
        TLENGTH count = m_value.Assign(chars, length);
        return count;
    }
    /**
     **********************************************************************
     * Function: GetValue
     *
     *   Author: $author$
     *     Date: 3/13/2008
     **********************************************************************
     */
    virtual const char* GetValue
    (TLENGTH& length) const 
    {
        const char* chars = m_value.Chars(length);
        return chars;
    }
    /**
     **********************************************************************
     * Function: DeleteThis
     *
     *   Author: $author$
     *     Date: 3/13/2008
     **********************************************************************
     */
    virtual eError DeleteThis()
    {
        eError error = e_ERROR_NONE;
        bool isStaticInstance;
        if ((isStaticInstance = GetIsStaticInstance()))
            return e_ERROR_STATIC_INSTANCE;
        delete this;
        return error;
    }
};

/**
 **********************************************************************
 *  Typedef: cXalanParameterReference
 *
 *  Author: $author$
 *    Date: 3/13/2008
 **********************************************************************
 */
typedef cReferenceT
<cXalanParameter,cReferenced>
cXalanParameterReference;

/**
 **********************************************************************
 *  Typedef: cXalanParameterReferenceVectorInterface
 *
 *  Author: $author$
 *    Date: 3/13/2008
 **********************************************************************
 */
typedef cVectorInterfaceT
<cXalanParameterReference,
 TSIZE,TLENGTH,UNDEFINED_LENGTH,cInterfaceBase>
cXalanParameterReferenceVectorInterface;

/**
 **********************************************************************
 * Typedef: cXalanParameterReferenceVectorExtends
 *
 *  Author: $author$
 *    Date: 3/13/2008
 **********************************************************************
 */
typedef std::vector<cXalanParameterReference>
cXalanParameterReferenceVectorExtends;

/**
 **********************************************************************
 *  Typedef: cXalanParameterReferenceVector
 *
 *  Author: $author$
 *    Date: 3/13/2008
 **********************************************************************
 */
typedef cVectorT
<cXalanParameterReference,
 TSIZE,TLENGTH,UNDEFINED_LENGTH,
 cXalanParameterReferenceVectorInterface, 
 cXalanParameterReferenceVectorExtends>
cXalanParameterReferenceVector;

/**
 **********************************************************************
 *  Typedef: cXalanParameters
 *
 *  Author: $author$
 *    Date: 3/13/2008
 **********************************************************************
 */
typedef cXalanParameterReferenceVector
cXalanParameters;

#endif /* _CXALANPARAMETER_HXX */
