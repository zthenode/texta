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
//   File: cReferenced.hpp
//
// Author: $author$
//   Date: 6/20/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CREFERENCED_HPP) || defined(CREFERENCEDT_MEMBERS_ONLY)
#if !defined(_CREFERENCED_HPP) && !defined(CREFERENCEDT_MEMBERS_ONLY)
#define _CREFERENCED_HPP
#endif // !defined(_CREFERENCED_HPP) && !defined(CREFERENCEDT_MEMBERS_ONLY) 

#if !defined(CREFERENCEDT_MEMBERS_ONLY)
#include "cInstanceBase.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

#undef CDB_CLASS
#define CDB_CLASS "cReferencedT"
///////////////////////////////////////////////////////////////////////
//  Class: cReferencedT
//
// Author: $author$
//   Date: 6/20/2011
///////////////////////////////////////////////////////////////////////
template
<class TExtend=cInstanceBase>

class c_INSTANCE_CLASS cReferencedT
: public TExtend
{
public:
    typedef TExtend cExtends;

    unsigned int m_referenced;

    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cReferencedT
    //
    //       Author: $author$
    //         Date: 6/20/2011
    ///////////////////////////////////////////////////////////////////////
    cReferencedT
    (unsigned int referenced=0)
    : m_referenced(referenced)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cReferencedT
    //
    //      Author: $author$
    //        Date: 6/20/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cReferencedT()
    {
    }
#else // !defined(CREFERENCEDT_MEMBERS_ONLY) 
#endif // !defined(CREFERENCEDT_MEMBERS_ONLY) 

#if !defined(CREFERENCEDT_MEMBERS_ONLY)

#if !defined(CREFERENCEDT_MEMBER_FUNCS_IMPLEMENT)
#if !defined(CREFERENCEDT_MEMBER_FUNCS_IMPLEMENT)
    ///////////////////////////////////////////////////////////////////////
    //  Function: Increment
    //
    //    Author: $author$
    //      Date: 6/20/2011
    ///////////////////////////////////////////////////////////////////////
    virtual cReferencedT Increment()
#if defined(CREFERENCEDT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CREFERENCEDT_MEMBER_FUNCS_INTERFACE) 
    {
        return cReferencedT(++m_referenced);
    }
#endif // defined(CREFERENCEDT_MEMBER_FUNCS_INTERFACE) 
#else // !defined(CREFERENCEDT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CREFERENCEDT_MEMBER_FUNCS_IMPLEMENT) 
#if !defined(CREFERENCEDT_MEMBER_FUNCS_IMPLEMENT)
    ///////////////////////////////////////////////////////////////////////
    //  Function: Decrement
    //
    //    Author: $author$
    //      Date: 6/20/2011
    ///////////////////////////////////////////////////////////////////////
    virtual cReferencedT Decrement()
#if defined(CREFERENCEDT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CREFERENCEDT_MEMBER_FUNCS_INTERFACE) 
    {
        return cReferencedT(--m_referenced);
    }
#endif // defined(CREFERENCEDT_MEMBER_FUNCS_INTERFACE) 
#else // !defined(CREFERENCEDT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CREFERENCEDT_MEMBER_FUNCS_IMPLEMENT) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: Referenced
    //
    //    Author: $author$
    //      Date: 6/20/2011
    ///////////////////////////////////////////////////////////////////////
    virtual unsigned int Referenced() const
#if defined(CREFERENCEDT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CREFERENCEDT_MEMBER_FUNCS_INTERFACE) 
    {
#if !defined(CREFERENCEDT_MEMBER_FUNCS_IMPLEMENT)
        unsigned int referenced = m_referenced;
#else // !defined(CREFERENCEDT_MEMBER_FUNCS_IMPLEMENT) 
        unsigned int referenced = 0;
#endif // !defined(CREFERENCEDT_MEMBER_FUNCS_IMPLEMENT) 
        return referenced;
    }
#endif // defined(CREFERENCEDT_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: operator ==
    //
    //    Author: $author$
    //      Date: 6/20/2011
    ///////////////////////////////////////////////////////////////////////
    virtual bool operator ==
    (unsigned int to) const
#if defined(CREFERENCEDT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CREFERENCEDT_MEMBER_FUNCS_INTERFACE) 
    {
#if !defined(CREFERENCEDT_MEMBER_FUNCS_IMPLEMENT)
        bool isTrue = (m_referenced == to);
#else // !defined(CREFERENCEDT_MEMBER_FUNCS_IMPLEMENT) 
        bool isTrue = false;
#endif // !defined(CREFERENCEDT_MEMBER_FUNCS_IMPLEMENT) 
        return isTrue;
    }
#endif // defined(CREFERENCEDT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: operator !=
    //
    //    Author: $author$
    //      Date: 6/20/2011
    ///////////////////////////////////////////////////////////////////////
    virtual bool operator !=
    (unsigned int to) const
#if defined(CREFERENCEDT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CREFERENCEDT_MEMBER_FUNCS_INTERFACE) 
    {
#if !defined(CREFERENCEDT_MEMBER_FUNCS_IMPLEMENT)
        bool isTrue = (m_referenced != to);
#else // !defined(CREFERENCEDT_MEMBER_FUNCS_IMPLEMENT) 
        bool isTrue = false;
#endif // !defined(CREFERENCEDT_MEMBER_FUNCS_IMPLEMENT) 
        return isTrue;
    }
#endif // defined(CREFERENCEDT_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: NewInstance
    //
    //    Author: $author$
    //      Date: 6/20/2011
    ///////////////////////////////////////////////////////////////////////
    static cReferencedT* NewInstance
    (unsigned int referenced=0)
#if defined(CREFERENCEDT_MEMBER_FUNCS_INTERFACE)
    ;
#else // defined(CREFERENCEDT_MEMBER_FUNCS_INTERFACE) 
    {
        cReferencedT* instance = new cReferencedT(referenced);
        return instance;
    }
#endif // defined(CREFERENCEDT_MEMBER_FUNCS_INTERFACE) 
#else // !defined(CREFERENCEDT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CREFERENCEDT_MEMBER_FUNCS_IMPLEMENT) 
#if !defined(CREFERENCEDT_MEMBER_FUNCS_IMPLEMENT)
    ///////////////////////////////////////////////////////////////////////
    //  Function: DeleteInstance
    //
    //    Author: $author$
    //      Date: 6/20/2011
    ///////////////////////////////////////////////////////////////////////
    static eError DeleteInstance
    (cReferencedT* instance)
#if defined(CREFERENCEDT_MEMBER_FUNCS_INTERFACE)
    ;
#else // defined(CREFERENCEDT_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_NONE;
        if ((instance))
            delete instance;
        return error;
    }
#endif // defined(CREFERENCEDT_MEMBER_FUNCS_INTERFACE) 
#else // !defined(CREFERENCEDT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CREFERENCEDT_MEMBER_FUNCS_IMPLEMENT)

};
#undef CDB_CLASS

///////////////////////////////////////////////////////////////////////
// Typedef: cReferenced
//
//  Author: $author$
//    Date: 6/20/2011
///////////////////////////////////////////////////////////////////////
typedef cReferencedT<cInstanceBase>
cReferenced;

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CREFERENCEDT_MEMBERS_ONLY) 
#endif // !defined(CREFERENCEDT_MEMBERS_ONLY) 

#endif // !defined(_CREFERENCED_HPP) || defined(CREFERENCEDT_MEMBERS_ONLY) 
