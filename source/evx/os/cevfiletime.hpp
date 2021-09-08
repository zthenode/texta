///////////////////////////////////////////////////////////////////////
//   File: cevfiletime.hpp
//
// Author: $author$
//   Date: 6/13/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVFILETIME_HPP
#define _CEVFILETIME_HPP

#include "evfiletime.hpp"
#include "cevdatetimeinstance.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvFileTime
//
// Author: $author$
//   Date: 6/13/2007
///////////////////////////////////////////////////////////////////////
class CEvFileTime
: virtual public EvFileTime,
  public CEvDateTimeInstance
{
public:
    typedef EvFileTime CImplements;
    typedef CEvDateTimeInstance CExtends;
    typedef CEvFileTime CDerives;

    EvType m_type;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvFileTime
    //
    //       Author: $author$
    //         Date: 6/13/2007
    ///////////////////////////////////////////////////////////////////////
    CEvFileTime
    (bool isStaticInstance=false,
     EvType type=EV_TIME_NONE,
     UINT year=0,
     UINT month=0,
     UINT day=0,
     UINT hour=0,
     UINT minute=0,
     UINT second=0,
     UINT millisecond=0,
     bool isLocal=false,
     const EvTimezone* timezone=0,
     bool is12=false,
     bool isPM=false)
    : CExtends
      (year, month, day, 
       hour, minute, second, millisecond, 
       isLocal, timezone, is12, isPM),
      m_type(type)
    {
        CEvInstance::Construct(isStaticInstance);
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvFileTime
    //
    //      Author: $author$
    //        Date: 6/13/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvFileTime()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetType
    //
    //   Author: $author$
    //     Date: 6/13/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int SetType(EvType type) 
    {
        m_type = type;
        return m_type;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetType
    //
    //   Author: $author$
    //     Date: 6/13/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvType GetType() const 
    {
        return m_type;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: DeleteThis
    //
    //   Author: $author$
    //     Date: 5/16/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError DeleteThis()
    {
        if (m_isStaticInstance)
            return EV_ERROR_NOT_INSTANTIATED;
        delete this;
        return EV_ERROR_NONE;
    }
};
#endif // _CEVFILETIME_HPP
