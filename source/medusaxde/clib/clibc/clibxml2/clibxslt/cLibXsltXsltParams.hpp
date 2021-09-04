///////////////////////////////////////////////////////////////////////
// Copyright (c) 1988-2011 $organization$
//
// This software is provided by the author and contributors ``as is'' 
// and any express or implied warranties, including, but not limited to, 
// the implied warranties of merchantability and fitness for a particular 
// purpose are disclaimed. In no event shall the author or contributors 
// be liable for any direct, indirect, incidental, special, exemplary, 
// or consequential damages (including, but not limited to, procurement 
// of substitute goods or services; loss of use, data, or profits; or 
// business interruption) however caused and on any theory of liability, 
// whether in contract, strict liability, or tort (including negligence 
// or otherwise) arising in any way out of the use of this software, 
// even if advised of the possibility of such damage.
//
//   File: cLibXsltXsltParams.hpp
//
// Author: $author$
//   Date: 8/13/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CLIBXSLTXSLTPARAMS_HPP) || defined(CLIBXSLTXSLTPARAMS_MEMBERS_ONLY)
#if !defined(_CLIBXSLTXSLTPARAMS_HPP) && !defined(CLIBXSLTXSLTPARAMS_MEMBERS_ONLY)
#define _CLIBXSLTXSLTPARAMS_HPP
#endif // !defined(_CLIBXSLTXSLTPARAMS_HPP) && !defined(CLIBXSLTXSLTPARAMS_MEMBERS_ONLY) 

#if !defined(CLIBXSLTXSLTPARAMS_MEMBERS_ONLY)
#include "cInstanceBase.hpp"
#include "cArray.hpp"
#include "cDebug.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cLibXsltXsltParamsCharsInterface
//
//  Author: $author$
//    Date: 8/13/2011
///////////////////////////////////////////////////////////////////////
typedef cArrayInterfaceT<const char*>
cLibXsltXsltParamsCharsInterface;
///////////////////////////////////////////////////////////////////////
// Typedef: cLibXsltXsltParamsCharsImplement
//
//  Author: $author$
//    Date: 8/13/2011
///////////////////////////////////////////////////////////////////////
typedef cArrayImplementT
<cLibXsltXsltParamsCharsInterface, const char*>
cLibXsltXsltParamsCharsImplement;
///////////////////////////////////////////////////////////////////////
// Typedef: cLibXsltXsltParamsChars
//
//  Author: $author$
//    Date: 8/13/2011
///////////////////////////////////////////////////////////////////////
typedef cArrayT
<cLibXsltXsltParamsCharsImplement, 
 cLibXsltXsltParamsCharsInterface, const char*>
cLibXsltXsltParamsChars;

///////////////////////////////////////////////////////////////////////
// Typedef: cLibXsltXsltParamsStringsInterface
//
//  Author: $author$
//    Date: 8/13/2011
///////////////////////////////////////////////////////////////////////
typedef cArrayInterfaceT<cString*>
cLibXsltXsltParamsStringsInterface;
///////////////////////////////////////////////////////////////////////
// Typedef: cLibXsltXsltParamsStringsImplement
//
//  Author: $author$
//    Date: 8/13/2011
///////////////////////////////////////////////////////////////////////
typedef cArrayImplementT
<cLibXsltXsltParamsStringsInterface, cString*>
cLibXsltXsltParamsStringsImplement;
///////////////////////////////////////////////////////////////////////
// Typedef: cLibXsltXsltParamsStrings
//
//  Author: $author$
//    Date: 8/13/2011
///////////////////////////////////////////////////////////////////////
typedef cArrayT
<cLibXsltXsltParamsStringsImplement, 
 cLibXsltXsltParamsStringsInterface, cString*>
cLibXsltXsltParamsStrings;

///////////////////////////////////////////////////////////////////////
// Typedef: cLibXsltXsltParamsExtend
//
//  Author: $author$
//    Date: 8/13/2011
///////////////////////////////////////////////////////////////////////
typedef cInstanceBase
cLibXsltXsltParamsExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cLibXsltXsltParams
//
// Author: $author$
//   Date: 8/13/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cLibXsltXsltParams
: //virtual public cLibXsltXsltParamsImplement,
  public cLibXsltXsltParamsExtend
{
public:
    //typedef cLibXsltXsltParamsImplement cImplements;
    typedef cLibXsltXsltParamsExtend cExtends;

    const char* const m_apos;
    const char* const m_nullChars;
    cString* const m_nullParam;
    cLibXsltXsltParamsChars m_paramsChars;
    cLibXsltXsltParamsStrings m_params;
    cLibXsltXsltParamsStrings m_paramNames;

    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cLibXsltXsltParams
    //
    //       Author: $author$
    //         Date: 8/13/2011
    ///////////////////////////////////////////////////////////////////////
    cLibXsltXsltParams()
    : m_apos("'"),
      m_nullChars(0),
      m_nullParam(0)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cLibXsltXsltParams
    //
    //      Author: $author$
    //        Date: 8/13/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cLibXsltXsltParams()
    {
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: AddName
    ///
    ///    Author: $author$
    ///      Date: 12/19/2012
    ///////////////////////////////////////////////////////////////////////
    virtual eError AddName(const cString& name)
    {
        eError error = e_ERROR_NONE;
        cString** params;
        cString* param;
        ssize_t length;
        int unequal;
        if ((params = m_paramNames.Elements(length))) {
            for (ssize_t i = 0; i < length; i++) {
                if ((param = params[i])) {
                    if (!(unequal = param->compare(name))) {
                        return error = e_ERROR_FAILED;
                    }
                }
            }
        }
        if ((param = new cString(name)))
            m_paramNames.Append(&param, 1);
        return error;
    }
#else // !defined(CLIBXSLTXSLTPARAMS_MEMBERS_ONLY) 
#endif // !defined(CLIBXSLTXSLTPARAMS_MEMBERS_ONLY) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: AddLiteral
    //
    //    Author: $author$
    //      Date: 8/13/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError AddLiteral
    (const cString& name,
     const cString& expression)
#if defined(CLIBXSLTXSLTPARAMS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CLIBXSLTXSLTPARAMS_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_NONE;
#if !defined(CLIBXSLTXSLTPARAMS_MEMBER_FUNCS_IMPLEMENT)
        cString *paramName, *paramExpression;
        const char *paramNameChars, *paramExpressionChars;
        eError error2;
        if (!(error2 = AddName(name)))
        if ((paramName = new cString(name)))
        {
            if ((paramNameChars = paramName->HasChars()))
            if ((paramExpression = new cString(m_apos)))
            {
                if (0 <= (paramExpression->Append(expression)))
                if (0 <= (paramExpression->Append(m_apos)))
                if ((paramExpressionChars = paramExpression->HasChars()))
                {
                    m_paramsChars.Append(&paramNameChars, 1);
                    m_paramsChars.Append(&paramExpressionChars, 1);
                    m_params.Append(&paramName, 1);
                    m_params.Append(&paramExpression, 1);
                    return error = e_ERROR_NONE;
                }
                delete paramExpression;
            }
            delete paramName;
        }
#else // !defined(CLIBXSLTXSLTPARAMS_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CLIBXSLTXSLTPARAMS_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CLIBXSLTXSLTPARAMS_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: Add
    //
    //    Author: $author$
    //      Date: 8/13/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Add
    (const cString& name,
     const cString& expression)
#if defined(CLIBXSLTXSLTPARAMS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CLIBXSLTXSLTPARAMS_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_NONE;
#if !defined(CLIBXSLTXSLTPARAMS_MEMBER_FUNCS_IMPLEMENT)
        cString *paramName, *paramExpression;
        const char *paramNameChars, *paramExpressionChars;
        eError error2;
        if (!(error2 = AddName(name)))
        if ((paramName = new cString(name)))
        {
            if ((paramNameChars = paramName->HasChars()))
            if ((paramExpression = new cString(expression)))
            {
                if ((paramExpressionChars = paramExpression->HasChars()))
                {
                    m_paramsChars.Append(&paramNameChars, 1);
                    m_paramsChars.Append(&paramExpressionChars, 1);
                    m_params.Append(&paramName, 1);
                    m_params.Append(&paramExpression, 1);
                    return error = e_ERROR_NONE;
                }
                delete paramExpression;
            }
            delete paramName;
        }
#else // !defined(CLIBXSLTXSLTPARAMS_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CLIBXSLTXSLTPARAMS_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CLIBXSLTXSLTPARAMS_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: AddEnd
    //
    //    Author: $author$
    //      Date: 8/13/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError AddEnd()
#if defined(CLIBXSLTXSLTPARAMS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CLIBXSLTXSLTPARAMS_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_NONE;
#if !defined(CLIBXSLTXSLTPARAMS_MEMBER_FUNCS_IMPLEMENT)
        const char** paramsChars;
        const char* paramChars;
        cString** params;
        cString* param;
        ssize_t length;

        if ((paramsChars = m_paramsChars.Elements(length)) && (0 <= length))
        if (1 > length)
            m_paramsChars.Append(&m_nullChars, 1);
        else
        if ((paramChars = paramsChars[length-1]))
            m_paramsChars.Append(&m_nullChars, 1);

        if ((params = m_params.Elements(length)) && (0 < length))
        if ((param = params[length-1]))
            m_params.Append(&m_nullParam, 1);
#else // !defined(CLIBXSLTXSLTPARAMS_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CLIBXSLTXSLTPARAMS_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CLIBXSLTXSLTPARAMS_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: Clear
    //
    //    Author: $author$
    //      Date: 8/13/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Clear()
#if defined(CLIBXSLTXSLTPARAMS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CLIBXSLTXSLTPARAMS_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_NONE;
#if !defined(CLIBXSLTXSLTPARAMS_MEMBER_FUNCS_IMPLEMENT)
        cString** params;
        cString* param;
        ssize_t length;
        m_paramsChars.Clear();
        if ((params = m_params.Elements(length)))
        {
            for (ssize_t i = 0; i < length; i++)
            {
                if ((param = params[i]))
                {
                    delete param;
                    params[i] = 0;
                }
            }
        }
        m_params.Clear();
        if ((params = m_paramNames.Elements(length)))
        {
            for (ssize_t i = 0; i < length; i++)
            {
                if ((param = params[i]))
                {
                    delete param;
                    params[i] = 0;
                }
            }
        }
        m_paramNames.Clear();
#else // !defined(CLIBXSLTXSLTPARAMS_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CLIBXSLTXSLTPARAMS_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CLIBXSLTXSLTPARAMS_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: ParamsChars
    //
    //    Author: $author$
    //      Date: 8/13/2011
    ///////////////////////////////////////////////////////////////////////
    virtual const char** ParamsChars() const
#if defined(CLIBXSLTXSLTPARAMS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CLIBXSLTXSLTPARAMS_MEMBER_FUNCS_INTERFACE) 
    {
        const char** paramsChars = 0;
#if !defined(CLIBXSLTXSLTPARAMS_MEMBER_FUNCS_IMPLEMENT)
        paramsChars = (m_paramsChars.Elements());
#else // !defined(CLIBXSLTXSLTPARAMS_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CLIBXSLTXSLTPARAMS_MEMBER_FUNCS_IMPLEMENT) 
        return paramsChars;
    }
#endif // defined(CLIBXSLTXSLTPARAMS_MEMBER_FUNCS_INTERFACE) 

#if !defined(CLIBXSLTXSLTPARAMS_MEMBERS_ONLY)
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CLIBXSLTXSLTPARAMS_MEMBERS_ONLY) 
#endif // !defined(CLIBXSLTXSLTPARAMS_MEMBERS_ONLY) 

#endif // !defined(_CLIBXSLTXSLTPARAMS_HPP) || defined(CLIBXSLTXSLTPARAMS_MEMBERS_ONLY) 
        

