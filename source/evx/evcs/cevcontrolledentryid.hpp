///////////////////////////////////////////////////////////////////////
//   File: cevcontrolledentryid.hpp
//
// Author: $author$
//   Date: 3/12/2008
///////////////////////////////////////////////////////////////////////
#ifndef _CEVCONTROLLEDENTRYID_HPP
#define _CEVCONTROLLEDENTRYID_HPP

#include "evcontrolledentryid.hpp"
#include "cevuuid.hpp"
#include "cevinstance.hpp"
#include "cevbase.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvControlledEntryID
//
// Author: $author$
//   Date: 3/12/2008
///////////////////////////////////////////////////////////////////////
class CEvControlledEntryID
: virtual public EvControlledEntryID,
  public CEvInstance
{
public:
    typedef EvControlledEntryID CEvImplements;
    typedef CEvBase CEvExtends;
    typedef CEvControlledEntryID CEvDerives;

    CEvUUID m_uuid;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvControlledEntryID
    //
    //      Author: $author$
    //        Date: 3/12/2008
    ///////////////////////////////////////////////////////////////////////
    CEvControlledEntryID() 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: CEvControlledEntryID
    //
    //     Author: $author$
    //       Date: 3/12/2008
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvControlledEntryID()
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: DeleteInstance
    //
    //   Author: $author$
    //     Date: 3/12/2008
    ///////////////////////////////////////////////////////////////////////
    virtual EvError DeleteInstance() 
    {
        EvError error = EV_ERROR_NONE;
        delete this;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Generate
    //
    //   Author: $author$
    //     Date: 3/12/2008
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Generate()
    {
        EvError error = m_uuid.Generate();
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Compare
    //
    //   Author: $author$
    //     Date: 3/12/2008
    ///////////////////////////////////////////////////////////////////////
    virtual int Compare
    (const EvControlledEntryID& to) const
    {
        const EvUUID& toUUID = (const EvUUID&)(to);
        int unequal = Compare(toUUID);
        return unequal;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Compare
    //
    //   Author: $author$
    //     Date: 3/12/2008
    ///////////////////////////////////////////////////////////////////////
    virtual int Compare(const EvUUID& to) const
    {
        int unequal = m_uuid.Compare(to);
        return unequal;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetUUID
    //
    //   Author: $author$
    //     Date: 3/12/2008
    ///////////////////////////////////////////////////////////////////////
    virtual const SEvUUID& GetUUID() const
    {
        return m_uuid.GetUUID();
    }
};
#endif // _CEVCONTROLLEDENTRYID_HPP 
