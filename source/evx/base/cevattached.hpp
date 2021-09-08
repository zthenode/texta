///////////////////////////////////////////////////////////////////////
//   File: cevattached.hpp
//
// Author: $author$
//   Date: 4/11/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVATTACHED_HPP
#define _CEVATTACHED_HPP

#include "evattached.hpp"
#include "cevbase.hpp"
#include "evdebug.h"

///////////////////////////////////////////////////////////////////////
//  Class: CEvAttached
//
// Author: $author$
//   Date: 4/11/2007
///////////////////////////////////////////////////////////////////////
template
<class TAttached,
 class TNull,
 TNull VNull,
 class TImplements=EvAttached<TAttached>,
 class TExtends=CEvBase>

class CEvAttached
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements CImplements;
    typedef TExtends CExtends;
    typedef CEvAttached CDerives;

    TAttached m_attached;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvAttached
    //
    //       Author: $author$
    //         Date: 4/11/2007
    ///////////////////////////////////////////////////////////////////////
    CEvAttached(TAttached attached=((TAttached)(VNull))) 
    : m_attached(attached)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvAttached
    //
    //      Author: $author$
    //        Date: 4/11/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvAttached()
    {
        EvError error;
        TAttached attached;

        if (((TAttached)(VNull)) != m_attached)
        if ((error = Detach(attached)))
            throw(error);
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Attach
    //
    //   Author: $author$
    //     Date: 4/11/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Attach
    (TAttached attached) 
    {
        EvError error = EV_ERROR_NONE;

        if (((TAttached)(VNull)) != m_attached)
            return EV_ERROR_ALREADY_ATTACHED;

        m_attached = attached;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Detach
    //
    //   Author: $author$
    //     Date: 4/11/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Detach
    (TAttached& attached) 
    {
        EvError error = EV_ERROR_NONE;

        if (((TAttached)(VNull)) == m_attached)
            return EV_ERROR_NOT_ATTACHED;

        attached = m_attached;
        m_attached = ((TAttached)(VNull));
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Attached
    //
    //   Author: $author$
    //     Date: 5/2/2007
    ///////////////////////////////////////////////////////////////////////
    virtual TAttached Attached() const 
    {
        return m_attached;
    }
};
#endif // _CEVATTACHED_HPP
