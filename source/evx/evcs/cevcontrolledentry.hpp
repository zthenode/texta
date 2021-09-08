///////////////////////////////////////////////////////////////////////
//   File: cevcontrolledentry.hpp
//
// Author: $author$
//   Date: 3/11/2008
///////////////////////////////////////////////////////////////////////
#ifndef _CEVCONTROLLEDENTRY_HPP
#define _CEVCONTROLLEDENTRY_HPP

#include "evcontrolledentry.hpp"
#include "cevbase.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvControlledEntry
//
// Author: $author$
//   Date: 3/11/2008
///////////////////////////////////////////////////////////////////////
class CEvControlledEntry
: virtual public EvControlledEntry,
  public CEvBase
{
public:
    typedef EvControlledEntry CEvImplements;
    typedef CEvBase CEvExtends;
    typedef CEvControlledEntry CEvDerives;

    EvControlledEntryType m_type;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvControlledEntry
    //
    //      Author: $author$
    //        Date: 3/11/2008
    ///////////////////////////////////////////////////////////////////////
    CEvControlledEntry
    (EvControlledEntryType type) 
    : m_type(type)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: SetType
    //
    //   Author: $author$
    //     Date: 3/11/2008
    ///////////////////////////////////////////////////////////////////////
    virtual EvControlledEntryType SetType
    (EvControlledEntryType type) 
    {
        m_type = type;
        return m_type;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetType
    //
    //   Author: $author$
    //     Date: 3/11/2008
    ///////////////////////////////////////////////////////////////////////
    virtual EvControlledEntryType GetType() const 
    {
        return m_type;
    }
};
#endif // _CEVCONTROLLEDENTRY_HPP 
