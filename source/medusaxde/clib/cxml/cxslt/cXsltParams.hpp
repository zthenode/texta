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
//   File: cXsltParams.hpp
//
// Author: $author$
//   Date: 7/25/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CXSLTPARAMS_HPP) || defined(CXSLTPARAMS_MEMBERS_ONLY)
#if !defined(_CXSLTPARAMS_HPP) && !defined(CXSLTPARAMS_MEMBERS_ONLY)
#define _CXSLTPARAMS_HPP
#endif // !defined(_CXSLTPARAMS_HPP) && !defined(CXSLTPARAMS_MEMBERS_ONLY) 

#if !defined(CXSLTPARAMS_MEMBERS_ONLY)
#include <vector>
#include "cXsltParamsInterface.hpp"
#include "cInstanceBase.hpp"
#include "cDebug.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cXsltParamsVector
//
//  Author: $author$
//    Date: 7/25/2011
///////////////////////////////////////////////////////////////////////
typedef std::vector<cXsltParamInterface*>
cXsltParamsVector;
///////////////////////////////////////////////////////////////////////
// Typedef: cXsltParamsVectorIterator
//
//  Author: $author$
//    Date: 7/25/2011
///////////////////////////////////////////////////////////////////////
typedef cXsltParamsVector::const_iterator
cXsltParamsVectorIterator;
///////////////////////////////////////////////////////////////////////
//  Class: cXsltParamsIterator
//
// Author: $author$
//   Date: 7/25/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cXsltParamsIterator
{
public:
    cXsltParamsVectorIterator i;
};

///////////////////////////////////////////////////////////////////////
// Typedef: cXsltParamsExtend
//
//  Author: $author$
//    Date: 7/25/2011
///////////////////////////////////////////////////////////////////////
typedef cInstanceBase
cXsltParamsExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cXsltParams
//
// Author: $author$
//   Date: 7/25/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cXsltParams
: virtual public cXsltParamsImplement,
  public cXsltParamsExtend
{
public:
    typedef cXsltParamsImplement cImplements;
    typedef cXsltParamsExtend cExtends;

    cXsltParamsVector m_vector;
    cXsltParamsIterator m_iterator;

    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cXsltParams
    //
    //       Author: $author$
    //         Date: 7/25/2011
    ///////////////////////////////////////////////////////////////////////
    cXsltParams()
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cXsltParams
    //
    //      Author: $author$
    //        Date: 7/25/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cXsltParams()
    {
        eError error;
        if ((error = Clear()))
        {
            c_DB_ERROR("() failed on Clear()\n");
            throw(error);
        }
    }
#else // !defined(CXSLTPARAMS_MEMBERS_ONLY) 
#endif // !defined(CXSLTPARAMS_MEMBERS_ONLY) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: AddLiteral
    //
    //    Author: $author$
    //      Date: 7/25/2011
    ///////////////////////////////////////////////////////////////////////
    virtual cXsltParamInterface* AddLiteral
    (eError& error,
     const cString& name,
     const cString& expression,
     bool isLiteral=true)
#if defined(CXSLTPARAMS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CXSLTPARAMS_MEMBER_FUNCS_INTERFACE) 
    {
        cXsltParamInterface* param = 0;
#if !defined(CXSLTPARAMS_MEMBER_FUNCS_IMPLEMENT)
        param = Add(error, name, expression, isLiteral);
#else // !defined(CXSLTPARAMS_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CXSLTPARAMS_MEMBER_FUNCS_IMPLEMENT) 
        return param;
    }
#endif // defined(CXSLTPARAMS_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: Add
    //
    //    Author: $author$
    //      Date: 7/25/2011
    ///////////////////////////////////////////////////////////////////////
    virtual cXsltParamInterface* Add
    (eError& error,
     const cString& name,
     const cString& expression,
     bool isLiteral=false)
#if defined(CXSLTPARAMS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CXSLTPARAMS_MEMBER_FUNCS_INTERFACE) 
    {
        cXsltParamInterface* param = 0;
#if !defined(CXSLTPARAMS_MEMBER_FUNCS_IMPLEMENT)
        if ((param = cXsltParamInterface::NewInstance
            (error, name, expression, isLiteral)))
            m_vector.push_back(param);
#else // !defined(CXSLTPARAMS_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CXSLTPARAMS_MEMBER_FUNCS_IMPLEMENT) 
        return param;
    }
#endif // defined(CXSLTPARAMS_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: Clear
    //
    //    Author: $author$
    //      Date: 8/13/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Clear()
#if defined(CXSLTPARAMS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CXSLTPARAMS_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_NONE;
#if !defined(CXSLTPARAMS_MEMBER_FUNCS_IMPLEMENT)
        cXsltParamsVectorIterator begin = m_vector.begin();
        cXsltParamsVectorIterator end = m_vector.end();
        cXsltParamsVectorIterator i;
        cXsltParamInterface* param;
        eError error2;
        for (i = begin; i != end; i++)
        {
            if ((param  = *i))
            {
                if ((error2 = cXsltParamInterface::DeleteInstance(param)))
                if (!error)
                    error = error2;
            }
        }
        m_vector.clear();
#else // !defined(CXSLTPARAMS_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CXSLTPARAMS_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CXSLTPARAMS_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: GetFirst
    //
    //    Author: $author$
    //      Date: 7/25/2011
    ///////////////////////////////////////////////////////////////////////
    virtual cXsltParamInterface* GetFirst
    (cXsltParamsIterator& atParam) const
#if defined(CXSLTPARAMS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CXSLTPARAMS_MEMBER_FUNCS_INTERFACE) 
    {
        cXsltParamInterface* param = 0;
#if !defined(CXSLTPARAMS_MEMBER_FUNCS_IMPLEMENT)
        cXsltParamsVectorIterator begin = m_vector.begin();
        cXsltParamsVectorIterator end = m_vector.end();
        if (begin != end)
        {
            atParam.i = begin;
            param = *(atParam.i);
        }
#else // !defined(CXSLTPARAMS_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CXSLTPARAMS_MEMBER_FUNCS_IMPLEMENT) 
        return param;
    }
#endif // defined(CXSLTPARAMS_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetNext
    //
    //    Author: $author$
    //      Date: 7/25/2011
    ///////////////////////////////////////////////////////////////////////
    virtual cXsltParamInterface* GetNext
    (cXsltParamsIterator& atParam) const
#if defined(CXSLTPARAMS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CXSLTPARAMS_MEMBER_FUNCS_INTERFACE) 
    {
        cXsltParamInterface* param = 0;
#if !defined(CXSLTPARAMS_MEMBER_FUNCS_IMPLEMENT)
        cXsltParamsVectorIterator end = m_vector.end();
        if (atParam.i != end)
        if ((++atParam.i) != end)
            param = *(atParam.i);
#else // !defined(CXSLTPARAMS_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CXSLTPARAMS_MEMBER_FUNCS_IMPLEMENT) 
        return param;
    }
#endif // defined(CXSLTPARAMS_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: GetLast
    //
    //    Author: $author$
    //      Date: 7/25/2011
    ///////////////////////////////////////////////////////////////////////
    virtual cXsltParamInterface* GetLast
    (cXsltParamsIterator& atParam) const
#if defined(CXSLTPARAMS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CXSLTPARAMS_MEMBER_FUNCS_INTERFACE) 
    {
        cXsltParamInterface* param = 0;
#if !defined(CXSLTPARAMS_MEMBER_FUNCS_IMPLEMENT)
        cXsltParamsVectorIterator begin = m_vector.begin();
        cXsltParamsVectorIterator end = m_vector.end();
        if (begin != end)
        {
            atParam.i = --(end);
            param = *(atParam.i);
        }
#else // !defined(CXSLTPARAMS_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CXSLTPARAMS_MEMBER_FUNCS_IMPLEMENT) 
        return param;
    }
#endif // defined(CXSLTPARAMS_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetPrev
    //
    //    Author: $author$
    //      Date: 7/25/2011
    ///////////////////////////////////////////////////////////////////////
    virtual cXsltParamInterface* GetPrev
    (cXsltParamsIterator& atParam) const
#if defined(CXSLTPARAMS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CXSLTPARAMS_MEMBER_FUNCS_INTERFACE) 
    {
        cXsltParamInterface* param = 0;
#if !defined(CXSLTPARAMS_MEMBER_FUNCS_IMPLEMENT)
        cXsltParamsVectorIterator begin = m_vector.begin();
        if (atParam.i != begin)
        {
            --atParam.i;
            param = *(atParam.i);
        }
#else // !defined(CXSLTPARAMS_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CXSLTPARAMS_MEMBER_FUNCS_IMPLEMENT) 
        return param;
    }
#endif // defined(CXSLTPARAMS_MEMBER_FUNCS_INTERFACE) 

#if !defined(CXSLTPARAMS_MEMBER_FUNCS_IMPLEMENT)
    ///////////////////////////////////////////////////////////////////////
    //  Function: Iterator
    //
    //    Author: $author$
    //      Date: 7/25/2011
    ///////////////////////////////////////////////////////////////////////
    virtual cXsltParamsIterator& Iterator() const
#if defined(CXSLTPARAMS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CXSLTPARAMS_MEMBER_FUNCS_INTERFACE) 
    {
        return (cXsltParamsIterator&)(m_iterator);
    }
#endif // defined(CXSLTPARAMS_MEMBER_FUNCS_INTERFACE) 
#else // !defined(CXSLTPARAMS_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CXSLTPARAMS_MEMBER_FUNCS_IMPLEMENT) 

#if !defined(CXSLTPARAMS_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CXSLTPARAMS_MEMBERS_ONLY) 
#endif // !defined(CXSLTPARAMS_MEMBERS_ONLY) 

#endif // !defined(_CXSLTPARAMS_HPP) || defined(CXSLTPARAMS_MEMBERS_ONLY) 
