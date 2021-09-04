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
//   File: cXsltParam.hpp
//
// Author: $author$
//   Date: 7/25/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CXSLTPARAM_HPP) || defined(CXSLTPARAM_MEMBERS_ONLY)
#if !defined(_CXSLTPARAM_HPP) && !defined(CXSLTPARAM_MEMBERS_ONLY)
#define _CXSLTPARAM_HPP
#endif // !defined(_CXSLTPARAM_HPP) && !defined(CXSLTPARAM_MEMBERS_ONLY) 

#if !defined(CXSLTPARAM_MEMBERS_ONLY)
#include "cXsltParamInterface.hpp"
#include "cInstanceBase.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cXsltParamExtend
//
//  Author: $author$
//    Date: 7/25/2011
///////////////////////////////////////////////////////////////////////
typedef cInstanceBase
cXsltParamExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cXsltParam
//
// Author: $author$
//   Date: 7/25/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cXsltParam
: virtual public cXsltParamImplement,
  public cXsltParamExtend
{
public:
    typedef cXsltParamImplement cImplements;
    typedef cXsltParamExtend cExtends;

    cString m_name;
    cString m_expression;
    bool m_isLiteral;

    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cXsltParam
    //
    //       Author: $author$
    //         Date: 7/25/2011
    ///////////////////////////////////////////////////////////////////////
    cXsltParam
    (const cString& name,
     const cString& expression,
     bool isLiteral=false)
    : m_name(name),
      m_expression(expression),
      m_isLiteral(isLiteral)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cXsltParam
    //
    //       Author: $author$
    //         Date: 7/25/2011
    ///////////////////////////////////////////////////////////////////////
    cXsltParam
    (const char* name=0,
     const char* expression=0,
     bool isLiteral=false)
    : m_name(name),
      m_expression(expression),
      m_isLiteral(isLiteral)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cXsltParam
    //
    //      Author: $author$
    //        Date: 7/25/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cXsltParam()
    {
    }
#else // !defined(CXSLTPARAM_MEMBERS_ONLY) 
#endif // !defined(CXSLTPARAM_MEMBERS_ONLY) 

#if !defined(CXSLTPARAM_MEMBER_FUNCS_IMPLEMENT)
    ///////////////////////////////////////////////////////////////////////
    //  Function: SetName
    //
    //    Author: $author$
    //      Date: 7/25/2011
    ///////////////////////////////////////////////////////////////////////
    virtual cString& SetName
    (const cString& name)
#if defined(CXSLTPARAM_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CXSLTPARAM_MEMBER_FUNCS_INTERFACE) 
    {
        m_name = name;
        return m_name;
    }
#endif // defined(CXSLTPARAM_MEMBER_FUNCS_INTERFACE) 
#else // !defined(CXSLTPARAM_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CXSLTPARAM_MEMBER_FUNCS_IMPLEMENT) 
#if !defined(CXSLTPARAM_MEMBER_FUNCS_IMPLEMENT)
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetName
    //
    //    Author: $author$
    //      Date: 7/25/2011
    ///////////////////////////////////////////////////////////////////////
    virtual const cString& GetName() const
#if defined(CXSLTPARAM_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CXSLTPARAM_MEMBER_FUNCS_INTERFACE) 
    {
        return m_name;
    }
#endif // defined(CXSLTPARAM_MEMBER_FUNCS_INTERFACE) 
#else // !defined(CXSLTPARAM_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CXSLTPARAM_MEMBER_FUNCS_IMPLEMENT) 

#if !defined(CXSLTPARAM_MEMBER_FUNCS_IMPLEMENT)
    ///////////////////////////////////////////////////////////////////////
    //  Function: SetExpression
    //
    //    Author: $author$
    //      Date: 7/25/2011
    ///////////////////////////////////////////////////////////////////////
    virtual cString& SetExpression
    (cString& expression,
     bool isLiteral=false)
#if defined(CXSLTPARAM_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CXSLTPARAM_MEMBER_FUNCS_INTERFACE) 
    {
        m_expression = expression;
        m_isLiteral = isLiteral;
        return m_expression;
    }
#endif // defined(CXSLTPARAM_MEMBER_FUNCS_INTERFACE) 
#else // !defined(CXSLTPARAM_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CXSLTPARAM_MEMBER_FUNCS_IMPLEMENT) 
#if !defined(CXSLTPARAM_MEMBER_FUNCS_IMPLEMENT)
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetExpression
    //
    //    Author: $author$
    //      Date: 7/25/2011
    ///////////////////////////////////////////////////////////////////////
    virtual const cString& GetExpression(bool& isLiteral) const
#if defined(CXSLTPARAM_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CXSLTPARAM_MEMBER_FUNCS_INTERFACE) 
    {
        isLiteral = m_isLiteral;
        return m_expression;
    }
#endif // defined(CXSLTPARAM_MEMBER_FUNCS_INTERFACE) 
#else // !defined(CXSLTPARAM_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CXSLTPARAM_MEMBER_FUNCS_IMPLEMENT) 
#if !defined(CXSLTPARAM_MEMBER_FUNCS_IMPLEMENT)
    ///////////////////////////////////////////////////////////////////////
    //  Function: XsltParam
    //
    //    Author: $author$
    //      Date: 7/25/2011
    ///////////////////////////////////////////////////////////////////////
    virtual cXsltParam& XsltParam() const
#if defined(CXSLTPARAM_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CXSLTPARAM_MEMBER_FUNCS_INTERFACE) 
    {
        return (cXsltParam&)(*this);
    }
#endif // defined(CXSLTPARAM_MEMBER_FUNCS_INTERFACE) 
#else // !defined(CXSLTPARAM_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CXSLTPARAM_MEMBER_FUNCS_IMPLEMENT) 

#if defined(CXSLTPARAM_MEMBER_FUNCS_INTERFACE)
    ///////////////////////////////////////////////////////////////////////
    //  Function: NewInstance
    //
    //    Author: $author$
    //      Date: 7/25/2011
    ///////////////////////////////////////////////////////////////////////
    static cXsltParamInterface* NewInstance
    (eError& error,
     const cString& name,
     const cString& expression,
     bool isLiteral=false)
     ;
#else // defined(CXSLTPARAM_MEMBER_FUNCS_INTERFACE) 
#endif // defined(CXSLTPARAM_MEMBER_FUNCS_INTERFACE) 
#if defined(CXSLTPARAM_MEMBER_FUNCS_INTERFACE)
    ///////////////////////////////////////////////////////////////////////
    //  Function: DeleteInstance
    //
    //    Author: $author$
    //      Date: 7/25/2011
    ///////////////////////////////////////////////////////////////////////
    static eError DeleteInstance
    (cXsltParamInterface* instance)
     ;
#else // defined(CXSLTPARAM_MEMBER_FUNCS_INTERFACE) 
#endif // defined(CXSLTPARAM_MEMBER_FUNCS_INTERFACE) 

#if !defined(CXSLTPARAM_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CXSLTPARAM_MEMBERS_ONLY) 
#endif // !defined(CXSLTPARAM_MEMBERS_ONLY) 

#endif // !defined(_CXSLTPARAM_HPP) || defined(CXSLTPARAM_MEMBERS_ONLY) 
