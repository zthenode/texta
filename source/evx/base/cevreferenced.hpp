///////////////////////////////////////////////////////////////////////
//   File: cevreferenced.hpp
//
// Author: $author$
//   Date: 4/8/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVREFERENCED_HPP
#define _CEVREFERENCED_HPP

#include "evreferenced.hpp"
#include "cevbase.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvReferenced
//
// Author: $author$
//   Date: 4/8/2007
///////////////////////////////////////////////////////////////////////
class CEvReferenced
: virtual public EvReferenced
{
public:
    typedef EvReferenced CImplements;
    typedef CEvReferenced CDerives;

    UINT m_referenced;
    bool m_isStatic;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvReferenced
    //
    //       Author: $author$
    //         Date: 4/8/2007
    ///////////////////////////////////////////////////////////////////////
    CEvReferenced
    (UINT referenced=0, bool isStatic=false) 
    : m_referenced(referenced),
      m_isStatic(isStatic)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvReferenced
    //
    //      Author: $author$
    //        Date: 4/8/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvReferenced()
    {
        EvError error;

        if (m_referenced)
            throw(error = EV_ERROR_REFERENCED);
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: IncrementReferenced
    //
    //   Author: $author$
    //     Date: 4/8/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError IncrementReferenced() 
    {
        EvError error = EV_ERROR_NONE;
        m_referenced++;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: DecrementReferenced
    //
    //   Author: $author$
    //     Date: 4/8/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError DecrementReferenced() 
    {
        EvError error = EV_ERROR_NONE;
        if (!(--m_referenced))
            error = DeleteReferenced();
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: DeleteReferenced
    //
    //   Author: $author$
    //     Date: 4/8/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError DeleteReferenced() 
    {
        EvError error = EV_ERROR_NONE;
        if (!m_isStatic)
            delete this;
        return error;
    }
};
#endif // _CEVREFERENCED_HPP
