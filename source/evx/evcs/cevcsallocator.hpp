///////////////////////////////////////////////////////////////////////
//   File: cevcsallocator.hpp
//
// Author: $author$
//   Date: 5/26/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCSALLOCATOR_HPP
#define _CEVCSALLOCATOR_HPP

#include "cevcsallocatorlist.hpp"
#include "evcsallocator.hpp"
#include "evcsacquired.hpp"
#include "cevcs.hpp"
#include "cevstring.hpp"
#include "cevmutex.hpp"
#include "evdebug.h"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcsAllocator
//
// Author: $author$
//   Date: 5/26/2007
///////////////////////////////////////////////////////////////////////
class CEvcsAllocator
: virtual public EvcsAllocator,
  public CEvBase
{
public:
    typedef EvcsAllocator CImplements;
    typedef CEvBase CExtends;
    typedef CEvcsAllocator CDerives;

    CEvcsAllocatorItem m_item;

    static EvcsAllocator* m_default;
    EvcsAllocator* m_oldDefault;

    bool m_isDefault;
    bool m_initialized;
    CEvString m_name;

    EvcsAcquired m_acquired;
    CEvMutex m_acquiredMutex;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcsAllocator
    //
    //       Author: $author$
    //         Date: 5/26/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcsAllocator
    (const char* name=0, LONG length=-1,
     bool isDefault=false) 
    : m_item(*this),
      m_oldDefault(m_default),
      m_isDefault(false),
      m_initialized(false)
    {
        Construct(name, length, isDefault);
    }
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcsAllocator
    //
    //       Author: $author$
    //         Date: 5/26/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcsAllocator(bool isDefault) 
    : m_item(*this),
      m_oldDefault(m_default),
      m_isDefault(false),
      m_initialized(false)
    {
        Construct(0, 0, isDefault);
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvcsAllocator
    //
    //      Author: $author$
    //        Date: 5/26/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvcsAllocator()
    {
        if (m_isDefault && (this == m_default))
            m_default = m_oldDefault;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Construct
    //
    //   Author: $author$
    //     Date: 5/26/2007
    ///////////////////////////////////////////////////////////////////////
    virtual void Construct
    (const char* name=0, LONG length=-1,
     bool isDefault=false) 
    {
        EvError error;

        if (name && (0 != length))
        if (0 > (length = SetName(name, length)))
            throw(error = -length);

        if (isDefault)
            m_default = this;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Initialize
    //
    //   Author: $author$
    //     Date: 5/27/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Initialize() 
    {
        EvError error = EV_ERROR_NONE;

        if (m_initialized)
            return EV_ERROR_NONE;

        if (!(error = m_acquiredMutex.Create()))
            m_initialized = true;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Finalize
    //
    //   Author: $author$
    //     Date: 5/27/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Finalize() 
    {
        EvError error = EV_ERROR_NONE;

        if (!m_initialized)
            return EV_ERROR_NONE;

        error = m_acquiredMutex.Destroy();
        m_initialized = false;
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: AcquireEvcs
    //
    //   Author: $author$
    //     Date: 5/26/2007
    ///////////////////////////////////////////////////////////////////////
    virtual Evcs* AcquireEvcs(EvError& error) 
    {
        LONG length = 0;
        const char* chars = GetName(length);
        CEvcs* evcs;
        
        if ((evcs = new CEvcs(this, chars)))
        {
            if ((error = m_acquiredMutex.Acquire()))
                DBE("() failed to aquire mutex\n");
            else
            {
                m_acquired.push_back(evcs);

                if ((error = m_acquiredMutex.Release()))
                    DBE("() failed to release mutex\n");
                return evcs;
            }

            delete evcs;
            evcs = 0;
        }
        else DBE("() failed on new CEvcs()\n");
        return evcs;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ReleaseEvcs
    //
    //   Author: $author$
    //     Date: 5/26/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ReleaseEvcs(Evcs& evcs) 
    {
        bool wasAcquired = false;
        EvError error = EV_ERROR_FAILED;
        EvError error2;
        EvcsAcquiredIterator i;
        Evcs* acquiredEvcs;

        if ((error = m_acquiredMutex.Acquire()))
        {
            DBE("() failed to acquire mutex\n");
            return error;
        }

        for (i = m_acquired.begin(); i != m_acquired.end(); i++)
        {
            if ((wasAcquired = (&evcs == (acquiredEvcs = *i))))
            {
                error = acquiredEvcs->DeleteInstance();
                m_acquired.erase(i);
                break;
            }
        }

        if (!wasAcquired)
            DBE("() evcs was not acquired\n");

        if ((error2 = m_acquiredMutex.Release()) && !error)
        {
            DBE("() failed to release mutex\n");
            error = error;
        }

        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetName
    //
    //   Author: $author$
    //     Date: 5/26/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG SetName
    (const char* chars, LONG length=-1) 
    {
        length = m_name.Assign(chars, length);
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetName
    //
    //   Author: $author$
    //     Date: 5/26/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetName
    (LONG& length) const 
    {
        const char* chars = m_name.Chars(length);
        return chars;
    }
};
#endif // _CEVCSALLOCATOR_HPP
