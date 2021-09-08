///////////////////////////////////////////////////////////////////////
//   File: cevreference.hpp
//
// Author: $author$
//   Date: 4/8/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVREFERENCE_HPP
#define _CEVREFERENCE_HPP

#include "cevreferenced.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvReference
//
// Author: $author$
//   Date: 4/8/2007
///////////////////////////////////////////////////////////////////////
template
<class TReferenced=EvReferenced,
 class TBase=CEvBase>

class EV_EXPORT_CLASS CEvReference
: public TBase
{
public:
    typedef TBase CExtends;
    typedef CEvReference CDerives;

    TReferenced* m_referenced;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvReference
    //
    //       Author: $author$
    //         Date: 4/8/2007
    ///////////////////////////////////////////////////////////////////////
    CEvReference(TReferenced* referenced=0) 
    : m_referenced(referenced)
    {
        EvError error;
        if (m_referenced)
        if ((error = m_referenced->IncrementReferenced()))
            throw(error);
    }
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvReference
    //
    //       Author: $author$
    //         Date: 4/8/2007
    ///////////////////////////////////////////////////////////////////////
    CEvReference(const CEvReference& reference) 
    : m_referenced(reference.m_referenced)
    {
        EvError error;
        if (m_referenced)
        if ((error = m_referenced->IncrementReferenced()))
            throw(error);
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvReference
    //
    //      Author: $author$
    //        Date: 4/8/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvReference()
    {
        EvError error;
        if (m_referenced)
        if ((error = m_referenced->DecrementReferenced()))
            throw(error);
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Set
    //
    //   Author: $author$
    //     Date: 4/9/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Set(TReferenced& referenced) 
    {
        EvError error = EV_ERROR_NONE;

        if ((error = Clear()))
            return error;

        if ((error = (m_referenced = &referenced)->IncrementReferenced()))
            m_referenced = 0;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Clear
    //
    //   Author: $author$
    //     Date: 4/9/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Clear() 
    {
        EvError error = EV_ERROR_NONE;
        if (m_referenced)
        {
            if ((error = m_referenced->DecrementReferenced()))
                return error;
            m_referenced = 0;
        }
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Operator: ==
    //
    //   Author: $author$
    //     Date: 4/9/2007
    ///////////////////////////////////////////////////////////////////////
    virtual bool operator == (const void* to) const 
    {
        return to == ((const void*)(m_referenced));
    }
    ///////////////////////////////////////////////////////////////////////
    // Operator: !=
    //
    //   Author: $author$
    //     Date: 4/9/2007
    ///////////////////////////////////////////////////////////////////////
    virtual bool operator != (const void* to) const 
    {
        return to != ((const void*)(m_referenced));
    }
    ///////////////////////////////////////////////////////////////////////
    // Operator: bool
    //
    //   Author: $author$
    //     Date: 4/9/2007
    ///////////////////////////////////////////////////////////////////////
    virtual operator bool() const 
    {
        return (m_referenced != 0);
    }
};
#endif // _CEVREFERENCE_HPP
