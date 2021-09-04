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
//   File: cReference.hpp
//
// Author: $author$
//   Date: 6/20/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CREFERENCE_HPP) || defined(CREFERENCET_MEMBERS_ONLY)
#if !defined(_CREFERENCE_HPP) && !defined(CREFERENCET_MEMBERS_ONLY)
#define _CREFERENCE_HPP
#endif // !defined(_CREFERENCE_HPP) && !defined(CREFERENCET_MEMBERS_ONLY) 

#if !defined(CREFERENCET_MEMBERS_ONLY)
#include "cInstanceBase.hpp"
#include "cDebug.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

#undef CDB_CLASS
#define CDB_CLASS "cReferenceT"
///////////////////////////////////////////////////////////////////////
//  Class: cReferenceT
//
// Author: $author$
//   Date: 6/20/2011
///////////////////////////////////////////////////////////////////////
template
<class TInstance,
 class TReferenced,
 class TExtend=cInstanceBase>

class c_INSTANCE_CLASS cReferenceT
: public TExtend
{
public:
    typedef TExtend cExtends;
    typedef TInstance tInstance;
    typedef TReferenced tReferenced;

    TInstance* m_instance;
    TReferenced* m_referenced;

    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cReferenceT
    //
    //       Author: $author$
    //         Date: 6/20/2011
    ///////////////////////////////////////////////////////////////////////
    cReferenceT(TInstance* instance=0) 
    : m_instance(instance),
      m_referenced(0)
    {
        if (m_instance)
            m_referenced = TReferenced::NewInstance(1);
    }
    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cReferenceT
    //
    //       Author: $author$
    //         Date: 6/20/2011
    ///////////////////////////////////////////////////////////////////////
    cReferenceT(const cReferenceT& reference) 
    : m_instance(0),
      m_referenced(0)
    {
        if (reference.m_referenced != 0)
        {
            m_instance = reference.m_instance;
            m_referenced = reference.m_referenced;
            m_referenced->Increment();
        }
    }
    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cReferenceT
    //
    //       Author: $author$
    //         Date: 6/20/2011
    ///////////////////////////////////////////////////////////////////////
    template <class TDerivedInstance>
    cReferenceT(const cReferenceT<TDerivedInstance, TReferenced>& reference) 
    : m_instance(0),
      m_referenced(0)
    {
        TInstance* instance;

        if ((instance = (TInstance*)(reference.operator->())) != 0)
        {
            m_instance = instance;
            m_referenced = reference.m_referenced;
            m_referenced->Increment();
        }
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cReferenceT
    //
    //      Author: $author$
    //        Date: 6/20/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cReferenceT()
    {
        eError error;
        if ((error = Clear()))
        {
            c_DB_ERROR("() failed on Clear()");
            throw (error);
        }
    }
#else // !defined(CREFERENCET_MEMBERS_ONLY) 
#endif // !defined(CREFERENCET_MEMBERS_ONLY) 

#if !defined(CREFERENCET_MEMBERS_ONLY)
    ///////////////////////////////////////////////////////////////////////
    //  Function: Set
    //
    //    Author: $author$
    //      Date: 6/20/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Set
    (tInstance* instance)
#if defined(CREFERENCET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CREFERENCET_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_NONE;
#if !defined(CREFERENCET_MEMBER_FUNCS_IMPLEMENT)
        if (!(error = Clear()))
        if ((m_instance = instance))
        if (!(m_referenced = TReferenced::NewInstance(1)))
        {
            m_instance = 0;
            error = e_ERROR_NEW;
        }
#else // !defined(CREFERENCET_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CREFERENCET_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CREFERENCET_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: Clear
    //
    //    Author: $author$
    //      Date: 6/20/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Clear()
#if defined(CREFERENCET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CREFERENCET_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_NONE;
#if !defined(CREFERENCET_MEMBER_FUNCS_IMPLEMENT)
        eError error2;

        if (m_referenced)
        {
            if (m_instance)
            {
                if ((m_referenced->Decrement()) == 0)
                {
                    error = TReferenced::DeleteInstance(m_referenced);
                    if ((error2 = TInstance::DeleteInstance(m_instance)))
                    if (!error)
                        error = error2;
                }
                m_instance = 0;
            }
            m_referenced = 0;
        }
#else // !defined(CREFERENCET_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CREFERENCET_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CREFERENCET_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: Copy
    //
    //    Author: $author$
    //      Date: 6/20/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Copy
    (const cReferenceT& reference)
#if defined(CREFERENCET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CREFERENCET_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_NONE;
#if !defined(CREFERENCET_MEMBER_FUNCS_IMPLEMENT)
        cReferenceT& thisReference = *this;

        if (&reference != &thisReference)
        if (!(error = Clear()))
        {
            if (reference.m_referenced)
            {
                m_instance = reference.m_instance;
                m_referenced = reference.m_referenced;
                m_referenced->Increment();
            }
        }
#else // !defined(CREFERENCET_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CREFERENCET_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CREFERENCET_MEMBER_FUNCS_INTERFACE) 

#if !defined(CREFERENCET_MEMBER_FUNCS_IMPLEMENT)
    ///////////////////////////////////////////////////////////////////////
    //  Function: operator =
    //
    //    Author: $author$
    //      Date: 6/20/2011
    ///////////////////////////////////////////////////////////////////////
    virtual cReferenceT& operator = (const cReferenceT& reference)
#if defined(CREFERENCET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CREFERENCET_MEMBER_FUNCS_INTERFACE) 
    {
        cReferenceT& thisReference = *this;
        eError error;
        if ((error = Copy(reference)))
        {
            c_DB_ERROR("() failed on Copy()");
            throw(error);
        }
        return thisReference;
    }
#endif // defined(CREFERENCET_MEMBER_FUNCS_INTERFACE) 
#else // !defined(CREFERENCET_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CREFERENCET_MEMBER_FUNCS_IMPLEMENT) 

#if !defined(CREFERENCET_MEMBER_FUNCS_IMPLEMENT)
    ///////////////////////////////////////////////////////////////////////
    //  Function: operator ->
    //
    //    Author: $author$
    //      Date: 6/20/2011
    ///////////////////////////////////////////////////////////////////////
    virtual TInstance* operator ->() const
#if defined(CREFERENCET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CREFERENCET_MEMBER_FUNCS_INTERFACE) 
    {
        TInstance* instance = (TInstance*)(m_instance);
        return instance;
    }
#endif // defined(CREFERENCET_MEMBER_FUNCS_INTERFACE) 
#else // !defined(CREFERENCET_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CREFERENCET_MEMBER_FUNCS_IMPLEMENT) 
#if !defined(CREFERENCET_MEMBER_FUNCS_IMPLEMENT)
    ///////////////////////////////////////////////////////////////////////
    //  Function: operator *
    //
    //    Author: $author$
    //      Date: 6/20/2011
    ///////////////////////////////////////////////////////////////////////
    virtual TInstance& operator *() const
#if defined(CREFERENCET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CREFERENCET_MEMBER_FUNCS_INTERFACE) 
    {
        TInstance& instance = (TInstance&)(*m_instance);
        return instance;
    }
#endif // defined(CREFERENCET_MEMBER_FUNCS_INTERFACE) 
#else // !defined(CREFERENCET_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CREFERENCET_MEMBER_FUNCS_IMPLEMENT) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: operator !
    //
    //    Author: $author$
    //      Date: 6/20/2011
    ///////////////////////////////////////////////////////////////////////
    virtual bool operator !() const
#if defined(CREFERENCET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CREFERENCET_MEMBER_FUNCS_INTERFACE) 
    {
#if !defined(CREFERENCET_MEMBER_FUNCS_IMPLEMENT)
        bool isTrue = !(m_instance != 0);
#else // !defined(CREFERENCET_MEMBER_FUNCS_IMPLEMENT) 
        bool isTrue = false;
#endif // !defined(CREFERENCET_MEMBER_FUNCS_IMPLEMENT) 
        return isTrue;
    }
#endif // defined(CREFERENCET_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: operator bool
    //
    //    Author: $author$
    //      Date: 6/20/2011
    ///////////////////////////////////////////////////////////////////////
    virtual operator bool() const
#if defined(CREFERENCET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CREFERENCET_MEMBER_FUNCS_INTERFACE) 
    {
#if !defined(CREFERENCET_MEMBER_FUNCS_IMPLEMENT)
        bool isTrue = (m_instance != 0);
#else // !defined(CREFERENCET_MEMBER_FUNCS_IMPLEMENT) 
        bool isTrue = false;
#endif // !defined(CREFERENCET_MEMBER_FUNCS_IMPLEMENT) 
        return isTrue;
    }
#endif // defined(CREFERENCET_MEMBER_FUNCS_INTERFACE) 

};
#undef CDB_CLASS

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CREFERENCET_MEMBERS_ONLY) 
#endif // !defined(CREFERENCET_MEMBERS_ONLY) 

#endif // !defined(_CREFERENCE_HPP) || defined(CREFERENCET_MEMBERS_ONLY) 
