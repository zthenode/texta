///////////////////////////////////////////////////////////////////////
//   File: cevfilematchevents.hpp
//
// Author: $author$
//   Date: 6/28/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVFILEMATCHEVENTS_HPP
#define _CEVFILEMATCHEVENTS_HPP

#include "evfilematchevents.hpp"
#include "cevbase.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvFileMatchEvents
//
// Author: $author$
//   Date: 6/28/2007
///////////////////////////////////////////////////////////////////////
template
<class TExtends=CEvBase,
 class TImplements=EvFileMatchEventsImplement>

class CEvFileMatchEvents
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements CImplements;
    typedef TExtends CExtends;
    typedef CEvFileMatchEvents CDerives;

    EvFileMatchEvents* m_fileMatchEventsDelegate;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvFileMatchEvents
    //
    //      Author: $author$
    //        Date: 5/19/2008
    ///////////////////////////////////////////////////////////////////////
    CEvFileMatchEvents
    (EvFileMatchEvents* delegate=0) 
    : m_fileMatchEventsDelegate(delegate)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: SetFileMatchEventsDelegate
    //
    //   Author: $author$
    //     Date: 5/19/2008
    ///////////////////////////////////////////////////////////////////////
    virtual EvFileMatchEvents* SetFileMatchEventsDelegate
    (EvFileMatchEvents* delegate) const 
    {
        EvFileMatchEvents* oldDelegate = m_fileMatchEventsDelegate;
        return oldDelegate;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetFileMatchEventsDelegate
    //
    //   Author: $author$
    //     Date: 5/19/2008
    ///////////////////////////////////////////////////////////////////////
    virtual EvFileMatchEvents* GetFileMatchEventsDelegate() const 
    {
        return m_fileMatchEventsDelegate;
    }
};
#endif // _CEVFILEMATCHEVENTS_HPP
